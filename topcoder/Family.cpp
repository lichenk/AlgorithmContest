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
const ll MAXN=200;
ll f[MAXN];
vector<ll> g[MAXN];
bool dfs(ll x, ll p) {
	f[x] = (p==-1)?0:f[p]^1;
	//printf("%lld: %lld. (p:%lld)\n",x,f[x],p);
	for (auto &w: g[x]) {
		//printf("Consider:%lld\n",w);
		if (w!=p) {
			if (f[x]==f[w]) {
				//printf("A:%lld %lld\n",f[x],f[w]);
				return false;
			}
			if (f[w]==-1) {
				//printf("B\n");
				bool ok=dfs(w,x);
				if (!ok) return false;
			}
		}
	}
	return true;
}

class Family {
	public:
	string isFamily(vector <int> parent1, vector <int> parent2) {
		ll n=parent1.size();
		for (ll i=0;i<n;i++) f[i]=-1;
		for (ll i=n-1;i>=0;i--) {
			ll p1=parent1[i],p2=parent2[i];
			if (p1!=-1) {
				g[p1].PB(p2);
				g[p2].PB(p1);
			}
		}
		for (ll i=0;i<n;i++) {
			if (f[i]==-1) {
				bool ok=dfs(i,-1);
				if (!ok) return "Impossible";
			}
		}
		return "Possible";
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
		cout << "Testing Family (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457771163;
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
		Family _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent1[] = {-1,-1,0};
				int parent2[] = {-1,-1,1};
				_expected = "Possible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 1:
			{
				int parent1[] = {-1,-1,-1,-1,-1};
				int parent2[] = {-1,-1,-1,-1,-1};
				_expected = "Possible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 2:
			{
				int parent1[] = {-1,-1,0,0,1};
				int parent2[] = {-1,-1,1,2,2};
				_expected = "Impossible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 3:
			{
				int parent1[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6};
				int parent2[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1};
				_expected = "Possible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			case 4:
			{
				int parent1[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11};
				int parent2[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13};
				_expected = "Impossible";
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int parent1[] = ;
				int parent2[] = ;
				_expected = ;
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent1[] = ;
				int parent2[] = ;
				_expected = ;
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int parent1[] = ;
				int parent2[] = ;
				_expected = ;
				_received = _obj.isFamily(vector <int>(parent1, parent1+sizeof(parent1)/sizeof(int)), vector <int>(parent2, parent2+sizeof(parent2)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
