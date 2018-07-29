#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll MAXN = 308;
const ll UNDEF = -999;
vector<ll> g[MAXN];
vector<ll> h[MAXN];
ll hm[MAXN];
ll gm[MAXN];
inline vector<ll> load(vector<string> L) {
	string s = "";
	for (ll i=0; i<L.size();++i) s+=L[i];
	stringstream in(s);
	ll x;
	vector<ll> ret;
	while (in>>x) {
		ret.push_back(x);
	}
	return ret;
}

ll dfsg(ll x, ll t, ll p, ll c) {
	if (x==t) return 0;
	if (c==0) {
		for (auto &w: g[x]) {
			if (w==p) continue;
			ll cand = dfsg(w,t,x,c);
			if (cand != UNDEF) {
				return cand+1;
			}
		}
	}
	else {
		for (auto &w: h[x]) {
			if (w==p) continue;
			ll cand = dfsg(w,t,x,c);
			if (cand != UNDEF) {
				return cand+1;
			}
		}
	}
	return UNDEF;
}

class TreeUnion {
	public:
	double expectedCycles(vector <string> tree1, vector <string> tree2, int K) {
		vector<ll> gg = load(tree1);
		vector<ll> hh = load(tree2);
		ll n=gg.size()+1;
		for (ll x=1;x<n;x++) {
			ll y=gg[x-1];
			g[x].PB(y);
			g[y].PB(x);
		}
		assert(n==hh.size()+1);
		for (ll x=1;x<n;x++) {
			ll y=hh[x-1];
			h[x].PB(y);
			h[y].PB(x);
		}
		for (ll x=0;x<n;x++) {
			for (ll y=x+1;y<n;y++) {
				ll len=dfsg(x,y,-1,0)+1;
				//printf("G:%lld %lld: %lld\n",x,y,len);
				gm[len]++;
			}
		}
		for (ll x=0;x<n;x++) {
			for (ll y=x+1;y<n;y++) {
				ll len=dfsg(x,y,-1,1)+1;
				//printf("H:%lld %lld: %lld\n",x,y,len);
				if (len>K) continue;
				hm[len]++;
			}
		}
		ld norm = n*(n-1);
		ld ans = 0.0;
		for (ll a=0;a<=K;a++) {
			ll b=K-a;
			//printf("%lld %lld. %lld %lld.\n",a,b,gm[a],hm[b]);
			ld cand = ((ld)gm[a]*(ld)hm[b])/norm;
			ans += cand;
		}
		ans *= 2;
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
		cout << "Testing TreeUnion (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456194177;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeUnion _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string tree1[] = {"0"};
				string tree2[] = {"0"};
				int K = 4;
				_expected = 1.0;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}
			case 1:
			{
				string tree1[] = {"0 1"};
				string tree2[] = {"0 1"};
				int K = 4;
				_expected = 1.3333333333333333;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}
			case 2:
			{
				string tree1[] = {"0 1"};
				string tree2[] = {"0 1"};
				int K = 6;
				_expected = 0.3333333333333333;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}
			case 3:
			{
				string tree1[] = {"0 ", "1 1 1"};
				string tree2[] = {"0 1 0 ", "1"};
				int K = 5;
				_expected = 4.0;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}
			case 4:
			{
				string tree1[] = {"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"};
				string tree2[] = {"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"};
				int K = 7;
				_expected = 13.314285714285713;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}
			/*case 5:
			{
				string tree1[] = ;
				string tree2[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}*/
			/*case 6:
			{
				string tree1[] = ;
				string tree2[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
			}*/
			/*case 7:
			{
				string tree1[] = ;
				string tree2[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedCycles(vector <string>(tree1, tree1+sizeof(tree1)/sizeof(string)), vector <string>(tree2, tree2+sizeof(tree2)/sizeof(string)), K); break;
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
