#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const int MOD = 1000000007LL;
const int INF = 1LL<<30LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const int mn=1002;
vector<int> g[mn];
int vd[mn];
void dfsd(int x, int p, int d) {
	//printf("x:%d d:%d\n",x,d);
	vd[x]=d;
	for (auto &y:g[x]) {
		if (y==p) continue;
		dfsd(y,x,d+1);
	}
}
bool seen[mn];
int glo,ghi;
string glabels;
void dfs(int x, int p) {
	if (seen[x]) return;
	seen[x]=1;
	int d=vd[x];
	chkmin(glo,d);
	chkmax(ghi,d);
	seen[x]=1;
	for (auto &y:g[x]) {
		if (y==p) continue;
		if (glabels[x]==glabels[y]) dfs(y,x);
	}
}
vector<int> h[mn];
int f[2][mn];
class DengklekGaneshAndTree {
	public:
	int getCount(string labels, vector <int> parents) {
		glabels=labels;
		int n=labels.size();
		for (int x=1;x<n;x++) {
			int y=parents[x-1]; g[x].PB(y);g[y].PB(x);
		}
		dfsd(0,-1,0);
		int ahi=0;
		for (int x=0;x<n;x++) {
			glo=INF,ghi=-INF;
			if (seen[x]) continue;
			dfs(x,-1);
			//printf("x:%d glo:%d ghi:%d\n",x,glo,ghi);
			h[glo].PB(ghi);
			chkmax(ahi,ghi);
		}
		ahi++;
		int cur=0,nxt=1;
		f[cur][0]=1;
		for (int x=0;x<=ahi;x++) {
			for (auto &w:h[x]) {
				//printf("x:%d w:%d\n",x,w);
				memcpy(f[nxt],f[cur],sizeof f[nxt]);
				for (int y=x;y<=ahi;y++) {
					if (f[cur][y]) {
						//printf("y:%d f:%d\n",y,f[cur][y]);
						int ny=max(y,w+1);
						f[nxt][ny]+=f[cur][y];
						if (f[nxt][ny]>=MOD) f[nxt][ny]-=MOD;
					}
				}
				swap(cur,nxt);
			}
		}
		return f[cur][ahi];
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
		cout << "Testing DengklekGaneshAndTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1499533735;
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
		DengklekGaneshAndTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string labels = "seems";
				int parents[] = {0, 1, 0, 3};
				_expected = 5;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}
			case 1:
			{
				string labels = "like";
				int parents[] = {0, 0, 0};
				_expected = 7;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}
			case 2:
			{
				string labels = "a";
				int parents[] = {};
				_expected = 1;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}
			case 3:
			{
				string labels = "coincidence";
				int parents[] = {0, 1, 2, 0, 2, 1, 4, 7, 7, 6};
				_expected = 218;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}
			case 4:
			{
				string labels = "topcoderopenroundtwobgoodluckhavefun";
				int parents[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
				_expected = 147418098;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}
			/*case 5:
			{
				string labels = ;
				int parents[] = ;
				_expected = ;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string labels = ;
				int parents[] = ;
				_expected = ;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string labels = ;
				int parents[] = ;
				_expected = ;
				_received = _obj.getCount(labels, vector <int>(parents, parents+sizeof(parents)/sizeof(int))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
