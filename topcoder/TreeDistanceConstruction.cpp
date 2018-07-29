#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=55;
vector<ll> g[mn];
vector<int> fail={};
void add_edge(ll x,ll y) {g[x].PB(y);g[y].PB(x);}
bool seen[mn];
ll dfs(ll x, ll p) {
	if (seen[x]) return INF;
	seen[x]=true;
	ll ans=0;
	for (auto &y:g[x]) {
		if (y==p) continue;
		chkmax(ans,dfs(y,x)+1);
	}
	return ans;
}
bool check(vector<int> d) {
	ll n=d.size();
	for (ll x=0;x<n;x++) {
		memset(seen,0,sizeof seen);
		if (dfs(x,-1)!=d[x]) {
			//printf("x:%lld dfs:%lld d:%lld\n",x,dfs(x,-1),d[x]);
			return false;
		}
	}
	return true;
}
class TreeDistanceConstruction {
	public:
	vector <int> construct(vector <int> d) {
		ll go[mn];
		memset(go,-1,sizeof go);
		vector<ll> h[mn];
		ll n=d.size();
		ll hi=-INF;
		for (ll i=0;i<n;i++) {
			h[d[i]].PB(i);
			chkmax(hi,(ll)d[i]);
		}
		ll arms=h[hi].size();
		ll rad=(hi+1)/2;
		if (hi%2==1) {
			if (!(h[rad].size()>=2&&arms>=2)) return fail;
			add_edge(h[rad][0],h[rad][1]);
			{
				ll last=h[rad][0];
				for (ll x=rad+1;x<=hi;x++) {
					if (h[x].size()==0) return fail;
					ll v=h[x].back();
					add_edge(last,v);
					h[x].pop_back();
					last=v;
					go[x+1]=v;
				}
			}
			{
				ll last=h[rad][1];
				for (ll x=rad+1;x<=hi;x++) {
					if (h[x].size()==0) return fail;
					ll v=h[x].back();
					add_edge(last,v);
					h[x].pop_back();
					last=v;
					go[x+1]=v;
				}
			}
			go[rad+1]=h[rad][0];
			for (ll x=rad+1;x<=hi;x++) {
				for (auto &v:h[x]) {
					if (go[x]==-1) {
						//printf("x:%lld\n",x);
						return fail;
					}
					add_edge(go[x],v);
				}
			}
		}
		else {
			if (!(h[rad].size()>=1)) return fail;

			{
				ll last=h[rad][0];
				for (ll x=rad+1;x<=hi;x++) {
					if (h[x].size()==0) return fail;
					ll v=h[x].back();
					add_edge(last,v);
					h[x].pop_back();
					last=v;
					go[x+1]=v;
				}
			}
			{
				ll last=h[rad][0];
				for (ll x=rad+1;x<=hi;x++) {
					if (h[x].size()==0) return fail;
					ll v=h[x].back();
					add_edge(last,v);
					h[x].pop_back();
					last=v;
					go[x+1]=v;
				}
			}
			go[rad+1]=h[rad][0];
			for (ll x=rad+1;x<=hi;x++) {
				for (auto &v:h[x]) {
					if (go[x]==-1) {
						return fail;
					}
					add_edge(go[x],v);
				}
			}
		}
		for (ll x=0;x<n;x++) {
			for (auto &y:g[x]) {
				//if (y>x) printf("%lld %lld\n",x,y);
			}
		}
		if (!check(d)) return fail;
		else {
			vector<int> a;
			for (ll x=0;x<n;x++) {
				for (auto &y:g[x]) {
					if (y>x) a.PB(x),a.PB(y);
				}
			}
			return a;
		}
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
		cout << "Testing TreeDistanceConstruction (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483062114;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TreeDistanceConstruction _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d[] = {3,2,2,3};
				int __expected[] = {1, 2, 1, 0, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int d[] = {1,2,2,2};
				int __expected[] = {0, 1, 0, 2, 0, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int d[] = {1,1,1,1};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int d[] = {1,1,1};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int d[] = {1,1};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 5:
			{
				int d[] = {2,1,2,2,2,2,2};
				int __expected[] = {-1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 6:
			{
				int d[] = {9, 10, 10, 12, 10, 12, 14, 9, 13, 11, 9, 8, 12, 12, 11, 11, 10, 10, 11, 13, 10, 15, 13, 11, 11, 8, 13, 15, 14, 13, 13, 9, 10, 12, 9, 10, 13, 13, 10, 12, 11, 12, 14, 15, 12, 11};
				int __expected[] = {-1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 7:
			{
				int d[] = {2, 3, 3, 4, 4, 4, 4, 4, 4};
				int __expected[] = {0, 1, 0, 2, 1, 3, 2, 4, 2, 5, 2, 6, 2, 7, 2, 8};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
