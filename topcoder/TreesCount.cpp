#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const int mn=52;
int vdist[mn];
ll vcnt[mn];
vector<pii> g[mn];
bool seen[mn];
class TreesCount {
	public:
	int count(vector <string> graph) {
		int n=graph.size();
		for (int x=0;x<n;x++) for (int y=0;y<n;y++) if (graph[x][y]!='0') {
			int c=graph[x][y]-'0';
			g[x].PB(MP(y,c)); g[y].PB(MP(x,c));
		}
		priority_queue<pii,vector<pii>,greater<pii> > pq;
		for (int x=0;x<n;x++) vdist[x]=1<<29;
		vdist[0]=0; pq.push(MP(0,0));
		while(!pq.empty()) {
			auto got=pq.top(); pq.pop();
			int dist=got.fst,x=got.snd;
			if (dist>vdist[x]) continue;
			for (auto &gg:g[x]) {
				int y=gg.fst,cost=gg.snd;
				int ndist=dist+cost;
				if (ndist<vdist[y]) {
					vdist[y]=ndist;
					pq.push(MP(ndist,y));
				}
			}
		}
		for (int x=0;x<n;x++) {
			for (int y=0;y<n;y++) {
				if (vdist[x]<vdist[y]&&vdist[y]-vdist[x]==(int)(graph[x][y]-'0')) vcnt[y]++;
			}
		}
		ll ans=1;
		for (int y=1;y<n;y++) {
			ans=(ans*vcnt[y])%MOD;
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
		cout << "Testing TreesCount (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1501515722;
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
		TreesCount _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string graph[] = {"01",
				                  "10"};
				_expected = 1;
				_received = _obj.count(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 1:
			{
				string graph[] = {"011",
				                  "101",
				                  "110"};
				_expected = 1;
				_received = _obj.count(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 2:
			{
				string graph[] = {"021",
				                  "201",
				                  "110"};
				_expected = 2;
				_received = _obj.count(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 3:
			{
				string graph[] = {"0123",
				                  "1012",
				                  "2101",
				                  "3210"};
				_expected = 6;
				_received = _obj.count(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 4:
			{
				string graph[] = {"073542",
				                  "705141",
				                  "350721",
				                  "517031",
				                  "442304",
				                  "211140"};
				_expected = 2;
				_received = _obj.count(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 5:
			{
				string graph[] = {"0"};
				_expected = 1;
				_received = _obj.count(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			/*case 6:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
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
