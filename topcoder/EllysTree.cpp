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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=108;
vector<ll> dg[MAXN];
ll par[MAXN];
bool gused[MAXN];
ll gn;
ll orig=-1;
ll ret=-1;
vector<ll> lf[MAXN];
void dfs(ll x) {
	for (auto &y:dg[x]) {
		dfs(y);
		lf[x].PB(y);
		for (auto &w: lf[y]) {
			lf[x].PB(w);
		}
	}
}

ll findleaf(ll x) {
	ll cnt=0;
	for (auto &w: dg[x]) {
		cnt+=findleaf(w);
	}
	if (x!=orig&&cnt==0&&!gused[x]) ret=x;
	cnt+=(gused[x])?0:1;
	return cnt;
}

bool solve(ll x) {
	gused[x]=true;
	bool ok=true;
	for (ll i=0;i<gn;i++) {
		if (!gused[i]) ok=false;
	}
	if(ok) return ok;
	ret=-1;
	orig=x;
	findleaf(x);
	ll leaf=ret;
	if (leaf==x) leaf=-1;
	if (leaf==-1) {
		while(par[x]!=-1) {
			x=par[x];
			if (!gused[x]) {
				return solve(x);
			}
		}
	}
	else {
		gused[leaf]=true;
		return solve(leaf);
	}
	return false;
}
class EllysTree {
	public:
	vector <int> getMoves(vector <int> parent) {
		ll n=parent.size();
		for (ll i=0;i<MAXN;i++) par[i]=-1;
		for (ll i=0;i<n;i++) {
			ll c = i+1; ll p=parent[i];
			dg[p].PB(c);
			par[c]=p;
		}
		n++;
		gn=n;
		dfs(0);
		for (ll t=0;t<n;t++) {
			ll x=t;
			while(par[x]!=-1) {
				x=par[x];
				lf[t].PB(x);
			}
		}
		for (ll t=0;t<n;t++) sort(lf[t].begin(),lf[t].end());
		ll x=0;
		bool used[MAXN];
		for (ll i=0;i<n;i++) used[i]=false;
		vector<int> ans;
		for (ll t=0;t<n-1;t++) {
			used[x]=true;
			for (auto &y: lf[x]) {
				if (used[y]) continue;
				for (ll i=0;i<n;i++) gused[i]=used[i];
				bool ok=solve(y);
				if (ok) {
					ans.PB(y);
					x=y;
					break;
				}
			}
		}
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
		cout << "Testing EllysTree (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459009866;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EllysTree _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {9, 13, 7, 9, 8, 14, 14, 0, 6, 9, 2, 2, 5, 5, 7};
				int __expected[] = {1, 5, 2, 11, 13, 12, 8, 3, 7, 15, 14, 4, 6, 9, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {3, 4, 5, 0, 2};
				int __expected[] = {1, 2, 3, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {0, 0};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {0, 6, 6, 2, 6, 1, 3, 5};
				int __expected[] = {2, 4, 1, 3, 7, 6, 5, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 4:
			{
				int parent[] = {0};
				int __expected[] = {1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			/*case 5:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}*/
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
