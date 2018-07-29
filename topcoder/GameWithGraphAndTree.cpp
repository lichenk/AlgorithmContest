#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const int mn=14;
template <typename LST> struct LimitedVec  {
  LST a[1<<mn];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
};
LimitedVec<int> pop2z[mn+1];
int z2pop[1<<mn];
vector<int> zpop2subset[1<<mn][mn+1];
vector<int> g[mn];
bool bg[mn][mn];
vector<int> t[mn];
int tsz[mn];
int f[mn][1<<mn][mn];
int dp[1<<mn];
int n;
void dfs(int tx, int tp) {
	for (auto &ty:t[tx]) {
		if (ty==tp) continue;
		dfs(ty,tx);
	}
	for (int gx=0;gx<n;gx++) {
		memset(dp,0,sizeof dp);
		int csz=1;
		dp[1<<gx]=1;
		bool islast=false;
		for (auto &ty:t[tx]) {
			if (ty==tp) continue;
			int ysz=tsz[ty];
			csz+=ysz;
			//printf("tx:%d ty:%d ysz:%d csz:%d\n",tx,ty,ysz,csz);
			islast=(csz==tsz[tx]);
			for (auto &wholemask: pop2z[csz])
			{
				int ans=0;
				for (auto subtreemask: zpop2subset[wholemask][ysz]) {
					//printf("wholemask:%d subtreemask:%d ysz:%d\n",wholemask,subtreemask,ysz);
					int prev=dp[wholemask^subtreemask];
					if (prev==0) continue;
					int subtcopy=subtreemask;
					while(subtcopy) {
						int gy=31-__builtin_clz(subtcopy);
						//printf("subtcopy:%d gy:%d\n",subtcopy,gy);
						if (bg[gx][gy]) {
							int trans=f[ty][subtreemask][gy];
							if (trans!=0) ans=(ans+trans*(ll)prev)%MOD;
						}
						subtcopy^=(1<<gy);
					}
				}
				//printf("tx:%d gx:%d ty:%d wholemask:%d ans:%d\n",tx,gx,ty,wholemask,ans);
				if (islast) f[tx][wholemask][gx]=ans;
				else dp[wholemask]=ans;
			}
		}
		if (!islast) {
			//printf("tx:%d msk:%d gx:%d ONE\n",tx,1<<gx,gx);
			f[tx][1<<gx][gx]=1;
		}
	}
}
int getsz(int tx, int tp) {
	int sz=1;
	for (auto &ty:t[tx]) {
		if (ty==tp) continue;
		sz+=getsz(ty,tx);
	}
	return tsz[tx]=sz;
}
class GameWithGraphAndTree {
	public:
	int calc(vector <string> graph, vector <string> tree) {
		n=graph.size();
		for (int x=0;x<n;x++) for (int y=0;y<x;y++) {
			if (graph[x][y]=='Y') {g[x].PB(y); g[y].PB(x); bg[x][y]=bg[y][x]=true;}
			if (tree[x][y]=='Y') {t[x].PB(y); t[y].PB(x);}
		}
		getsz(0,-1);
		for (int z=0;z<(1<<n);z++) {
			int pop=__builtin_popcount(z);
			pop2z[pop].PB(z); z2pop[z]=pop;
		}
		for (int bitmask=0;bitmask<(1<<n);bitmask++) {
			for (int sub = 0; sub = sub - bitmask & bitmask ; ) {
			  zpop2subset[bitmask][z2pop[sub]].PB(sub);
			}
		}
		dfs(0,-1);
		ll ans=0;
		for (int gx=0;gx<n;gx++) ans+=f[0][(1<<n)-1][gx];
		return ans%MOD;
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
		cout << "Testing GameWithGraphAndTree (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1501516796;
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
		GameWithGraphAndTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string graph[] = {"NYN",
				                  "YNY",
				                  "NYN"};
				string tree[] = {"NYY",
				                 "YNN",
				                 "YNN"};
				_expected = 2;
				_received = _obj.calc(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
			}
			case 1:
			{
				string graph[] = {"NYNNN",
				                  "YNYYY",
				                  "NYNYY",
				                  "NYYNY",
				                  "NYYYN"};
				string tree[] = {"NYNNN", 
				                 "YNYNN",
				                 "NYNYN",
				                 "NNYNY",
				                 "NNNYN"};
				_expected = 12;
				_received = _obj.calc(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
			}
			case 2:
			{
				string graph[] = {"NYNNNY",
				                  "YNYNNN",
				                  "NYNYNN",
				                  "NNYNYN", 
				                  "NNNYNY",
				                  "YNNNYN"};
				string tree[] = {"NYNNYN",
				                 "YNNYNY",
				                 "NNNNYN",
				                 "NYNNNN",
				                 "YNYNNN",
				                 "NYNNNN"};
				_expected = 0;
				_received = _obj.calc(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
			}
			case 3:
			{
				string graph[] = {"NYNNYN",
				                  "YNNYNY",
				                  "NNNNYN",
				                  "NYNNNN",
				                  "YNYNNN",
				                  "NYNNNN"};
				string tree[] = {"NNNYYN", 
				                 "NNYNNN",
				                 "NYNNYY", 
				                 "YNNNNN",
				                 "YNYNNN",
				                 "NNYNNN"};
				_expected = 2;
				_received = _obj.calc(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
			}
			case 4:
			{
				string graph[] = {"NYNNNYNNY",
				                  "YNNNNNNYN",
				                  "NNNNYYNYY",
				                  "NNNNNYNNY",
				                  "NNYNNNYNY",
				                  "YNYYNNNYN",
				                  "NNNNYNNYN",
				                  "NYYNNYYNN",
				                  "YNYYYNNNN"};
				string tree[] = {"NNYNNNYYN",
				                 "NNNNYNNNN",
				                 "YNNNNNNNN",
				                 "NNNNNNYNN",
				                 "NYNNNNNYY",
				                 "NNNNNNNNY",
				                 "YNNYNNNNN",
				                 "YNNNYNNNN",
				                 "NNNNYYNNN"};
				_expected = 90;
				_received = _obj.calc(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
			}
			case 5:
			{
				string graph[] = {"N"};
				string tree[] = {"N"};
				_expected = 1;
				_received = _obj.calc(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
			}
			case 6:
			{
				string graph[] = {
				"NY",
				"YN"
			  };
				string tree[] = {
				"NY",
				"YN"
			  };
				_expected = 2;
				_received = _obj.calc(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
			}
			case 7:
			{
				string graph[] = {"NYN",
				                  "YNY",
				                  "NYN"};
				string tree[] = {"NYN",
				                  "YNY",
				                  "NYN"};
				_expected = 2;
				_received = _obj.calc(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
			}
			case 8:
			{
				string graph[] = {"NYYYYYYYYYYYYY", "YNYYYYYYYYYYYY", "YYNYYYYYYYYYYY", "YYYNYYYYYYYYYY", "YYYYNYYYYYYYYY", "YYYYYNYYYYYYYY", "YYYYYYNYYYYYYY", "YYYYYYYNYYYYYY", "YYYYYYYYNYYYYY", "YYYYYYYYYNYYYY", "YYYYYYYYYYNYYY", "YYYYYYYYYYYNYY", "YYYYYYYYYYYYNY", "YYYYYYYYYYYYYN"};
				string tree[] = {"NYYYYYYYYYYYYY", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN", "YNNNNNNNNNNNNN"};
				_expected = 178290591;
				_received = _obj.calc(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <string>(tree, tree+sizeof(tree)/sizeof(string))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
