#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const int INF = 1LL<<30LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const int mn=51;
bitset<mn> g[mn];
int n;
int dist[mn];
void bfs(int initx) {
	for (int x=0;x<n;x++) dist[x]=INF;
	queue<int> q;
	dist[initx]=0;
	q.push(initx);
	while(!q.empty()) {
		auto x=q.front(); q.pop();
		for (int y=0;y<n;y++) {
			if (g[x][y]) {
				int newcand=dist[x]+1;
				assert(newcand<INF/2);
				if (newcand<dist[y]) {
					dist[y]=newcand;
					q.push(y);
				}
			}
		}
	}
}
ll f[mn][mn];
void floyd(int initx) {
	for (int x=0;x<n;x++) for (int y=0;y<n;y++) f[x][y]=INF;
	for (int x=0;x<n;x++) f[x][x]=0;
	for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
		if(g[x][y]) f[x][y]=1;
	}
	for (int k=0;k<n;k++) for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		if (f[i][j]>f[i][k]+f[k][j]) {
			f[i][j]=f[i][k]+f[k][j];
		}
	}
}

	vector <string> solve(vector <int> dist0, vector <int> dist1) {
		n=dist0.size();
		for (int x=0;x<n;x++) g[x].set();
		for (int x=0;x<n;x++) g[x][x]=false;
		for (int x=0;x<n;x++) {
			for (int y=0;y<n;y++) {
				if (abs(dist0[x]-dist0[y])>1) g[x][y]=false;
				if (abs(dist1[x]-dist1[y])>1) g[x][y]=false;
			}
		}
		for (int x=0;x<n;x++) {
			bfs(x);
			floyd(x);
			for (int y=0;y<n;y++) {
				//printf("x:%d y:%d dist:%d f:%d\n",x,y,dist[y],f[x][y]);
				assert(dist[y]==f[x][y]);
				assert(f[x][y]==f[y][x]);
			}
		}
		bfs(0);
		vector<string> fail;
		for (int x=0;x<n;x++) {
			if (dist0[x]!=dist[x]) return fail;
		}
		bfs(1);
		for (int x=0;x<n;x++) {
			if (dist1[x]!=dist[x]) return fail;
		}
		vector<string> ans; ans.resize(n);
		for (int x=0;x<n;x++) {
			ans[x].resize(n);
			for (int y=0;y<n;y++) {
				ans[x][y]=g[x][y]?'Y':'N';
			}
		}
		return ans;
	}

void test() {
	srand(clock());
	int n=rand()%50+2;
	chkmin(n,5);
	for (int x=0;x<n;x++) g[x].reset();
	for (int x=0;x<n;x++) {
		for (int y=0;y<x;y++) {
			g[x][y]=rand()&1;
			g[y][x]=g[x][y];
		}
	}
	for (int x=0;x<n;x++) for (int y=0;y<n;y++) if (f[x][y]>=INF/2) return;
	vector<int> d0,d1;
	bfs(0);
	for (int i=0;i<n;i++) d0.PB(dist[i]);
	bfs(1);
	for (int i=0;i<n;i++) d1.PB(dist[i]);
	for (auto &w:d0) if (w>=INF/2) return;
	auto ans=solve(d0,d1);
	if (ans.size()==0) {
		for (int x=0;x<n;x++) printf("%d ",d0[x]);printf("\n");
		for (int x=0;x<n;x++) printf("%d ",d1[x]);printf("\n");
		//for (int x=0;x<n;x++) for (int y=0;y<n;y++) printf("%lld ",f[x][y]);
		//printf("\n");
		//	for (int x=0;x<n;x++) {
		//for (int y=0;y<x;y++) {if (h[x][y]) printf("x:%d y:%d\n",x,y);}}
		//printf("n:%d\n",n);
	}
	assert(ans.size()>0);
	printf("Tested\n");
}
class DistanceZeroAndOne {
	public:
	vector <string> construct(vector <int> dist0, vector <int> dist1) {
		for (int k=0;k<100;k++) test();
		auto ans=solve(dist0,dist1);
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
		cout << "Testing DistanceZeroAndOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495297299;
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
		DistanceZeroAndOne _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dist0[] = {0,2,1};
				int dist1[] = {2,0,1};
				string __expected[] = {"NNY", "NNY", "YYN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 1:
			{
				int dist0[] = {0,2,1};
				int dist1[] = {1,0,2};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 2:
			{
				int dist0[] = {3,1,1,1};
				int dist1[] = {1,0,1,1};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 3:
			{
				int dist0[] = {0,1,1,1};
				int dist1[] = {1,0,1,1};
				string __expected[] = {"NYYY", "YNYY", "YYNN", "YYNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 4:
			{
				int dist0[] = {0,3,1,2,2,3,4,4};
				int dist1[] = {3,0,2,1,2,3,4,4};
				string __expected[] = {"NNYNNNNN", "NNNYNNNN", "YNNYYNNN", "NYYNYNNN", "NNYYNYNN", "NNNNYNYY", "NNNNNYNN", "NNNNNYNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 5:
			{
				int dist0[] = {0,1};
				int dist1[] = {1,0};
				string __expected[] = {"NY", "YN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 6:
			{
				int dist0[] = {0,1,1};
				int dist1[] = {1,0,1};
				string __expected[] = {"Meow"};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 7:
			{
				int dist0[] = {0,9,4,6};
				int dist1[] = {9,0,4,6};
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 8:
			{
				int dist0[] = {1,5,6,1,3,5,7,1,2};
				int dist1[] = {1,5,6,1,3,5,7,1,2};
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
