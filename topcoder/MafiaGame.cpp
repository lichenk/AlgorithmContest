#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=55;
vector<ll> v;
ll n;
vector<ll> a;
ll origfreevotes;
ll gethighest(ll freevotes, ll x) {
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	for (ll i=x;i<n;i++) {
		pq.push(MP(v[i],-i));
	}
	a=v;
	while(freevotes>0) {
		auto got=pq.top(); pq.pop();
		ll votes=got.fst,y=-got.snd;
		if (votes!=a[y]) continue;
		freevotes--;
		a[y]++;
		pq.push(MP(a[y],-y));
	}
	return a[n-1];
}
ld f(ll x) {
	if (x==n-1) return 1;
	ll freevotes=origfreevotes;
	for (ll i=0;i<x;i++) freevotes+=v[i];
	ll hi=gethighest(freevotes,x);
	priority_queue<pll,vector<pll>,greater<pll> > pq;
	for (ll i=x;i<n;i++) {
		pq.push(MP(v[i],-i));
	}
	a=v;
	ld prob=1;
	while(freevotes>0) {
		auto got=pq.top(); pq.pop();
		ll votes=got.fst,y=-got.snd;
		if (votes!=a[y]) continue;
		freevotes--;
		if (a[y]+1==hi) {
			ll cnt=0;
			for (auto &w:a) if (w==a[y]) cnt++;
			prob*=(1-1.0L/cnt);
		}
		a[y]++;
		pq.push(MP(a[y],-y));
	}
	ld passthis=1-prob;
	if (hi==v[n-1]) passthis=1;
	ll nextgo=-1;
	for (ll y=n-1;y>=x;y--) {
		if (a[y]==a[n-1]) nextgo=y;
		else break;
	}
	//for (ll i=x;i<n;i++) printf("%lld ",a[i]);
	//printf("\nx:%lld nextgo:%lld pass:%f prob:%f\n",x,nextgo,passthis,prob);
	if (nextgo==x) return 0;
	return passthis*f(nextgo);
}
class MafiaGame {
	public:
	double probabilityToLose(int N, vector <int> decisions) {
		n=N;
		origfreevotes=n-decisions.size();
		map<ll,ll> h;
		for (auto &w:decisions) {h[w]++;}
		for (auto &w:h) v.PB(w.snd);
		while(v.size()<n) v.PB(0);
		sort(v.begin(),v.end());
		ld ans=f(0);
		return ans;
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing MafiaGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484436416;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MafiaGame _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int decisions[] = {1, 1, 1};
				_expected = 1.0;
				_received = _obj.probabilityToLose(N, vector <int>(decisions, decisions+sizeof(decisions)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 5;
				int decisions[] = {1, 2, 3};
				_expected = 0.0;
				_received = _obj.probabilityToLose(N, vector <int>(decisions, decisions+sizeof(decisions)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 20;
				int decisions[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 18, 19, 0};
				_expected = 0.0;
				_received = _obj.probabilityToLose(N, vector <int>(decisions, decisions+sizeof(decisions)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 23;
				int decisions[] = {17, 10, 3, 14, 22, 5, 11, 10, 22, 3, 14, 5, 11, 17};
				_expected = 0.14285714285714285;
				_received = _obj.probabilityToLose(N, vector <int>(decisions, decisions+sizeof(decisions)/sizeof(int))); break;
			}
			/*case 4:
			{
				int N = ;
				int decisions[] = ;
				_expected = ;
				_received = _obj.probabilityToLose(N, vector <int>(decisions, decisions+sizeof(decisions)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int N = ;
				int decisions[] = ;
				_expected = ;
				_received = _obj.probabilityToLose(N, vector <int>(decisions, decisions+sizeof(decisions)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int decisions[] = ;
				_expected = ;
				_received = _obj.probabilityToLose(N, vector <int>(decisions, decisions+sizeof(decisions)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
