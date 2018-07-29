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
vector<string> g;
int n;
const int mn=42;
bitset<mn> availe[mn];
bitset<mn> seenv;
void dfs(int x) {
	if (seenv[x]) return;
	seenv[x]=1;
	for (int y=0;y<n;y++) {
		if (g[x][y]!='.'&&availe[x][y]) dfs(y);
	}
}
int h[128];
bool check(int cur) {
	if (availe[cur].count()==0) {
		if (cur!=0) return false;
		else {
			for (int x=1;x<n;x++) {
				if (availe[x].count()!=0) return false;
			}
			return true;
		}
	}
	// Check degree
	for (int x=0;x<n;x++) {
		int needm=0;
		if (x==cur) needm++;
		if (x==0) needm++;
		if (needm==2) needm=0;
		if (availe[x].count()%2!=needm) {
			//printf("A\n");
			return false;
		}
	}
	// Check nondominating
	for (int x=0;x<n;x++) {
		for (int c='a';c<='z';c++) h[c]=0;
		for (int c='A';c<='Z';c++) h[c]=0;
		for (int y=0;y<n;y++) {
			if (availe[x][y]) {
				h[g[x][y]]++;
			}
		}
		int most=0;
		for (int c='a';c<='z';c++) chkmax(most,h[c]);
		for (int c='A';c<='Z';c++) chkmax(most,h[c]);
		int d=availe[x].count();
		int lim;
		if (cur!=0) {
			if (x==cur) lim=(d+2)/2;
			else if (x==0) lim=(d+2)/2;
			else lim=d/2;
		}
		else {
			if (x==0) lim=(d+2)/2;
			else lim=d/2;
		}
		if (most>lim) {
			//printf("B\n");
			return false;
		}
	}
	// Check connected
	int needv=0;
	for (int x=0;x<n;x++) {
		if (availe[x].count()>0) needv++;
	}
	seenv.reset();
	for (int x=0;x<n;x++) {
		if (availe[x].count()>0) {dfs(x); break;}
	}
	if (seenv.count()!=needv) {
		//printf("C\n");
		return false;
	}
	return true;
}
vector<int> vans;
void go(int x, char c) {
	for (int y=0;y<n;y++) {
		if (availe[x][y]&&g[x][y]!=c) {
			availe[x][y]=0; availe[y][x]=0;
			bool got=check(y);
			if (got) {
				//printf("x:%d c:%c y:%d g[x][y]:%c\n",x,c,y,g[x][y]);
				vans.PB(y);
				go(y,g[x][y]);
				return;
			}
			availe[x][y]=1; availe[y][x]=1;
		}
	}
	return;
}
vector <int> solve(vector <string> roads, vector <int> queries) {
	vans.clear();
	g=roads;
	n=roads.size();
	for (int x=0;x<n;x++) availe[x].reset();
	for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
		if (g[x][y]!='.') availe[x][y]=1;
	}
	if (!check(0)) return {};
	vans.PB(0);
	go(0,'?');
	for (int x=0;x<n;x++) {
		if (availe[x].count()!=0) return {-1};
	}
	vector<int> vfinal;
	for (auto &w:queries) vfinal.PB(vans[w]);
	return vfinal;
}
void bf() {
	vector <int> queries={0};
	for (int k=0;k<100000;k++) {
		vector <string> roads;
		srand(clock());
		int n=rand()%5+2;
		roads.resize(n);
		for (int x=0;x<n;x++) roads[x].resize(n);
		for (int x=0;x<n;x++) roads[x][x]='.';
		for (int x=0;x<n;x++) for (int y=0;y<x;y++) {
			char c='a'+rand()%3;
			if (rand()&1) c='.';
			roads[x][y]=c;
			roads[y][x]=c;
		}
		vector<int> res=solve(roads,queries);
		if (res==vector<int>({-1})) {
			for (auto &w:roads) {
				cout<<w<<endl;
			}
			exit(0);
		}
	}
}
class LexSmallestTour {
	public:
	vector <int> determineTour(vector <string> roads, vector <int> queries) {
		//bf();
		return solve(roads,queries);
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
		cout << "Testing LexSmallestTour (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495555329;
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
		LexSmallestTour _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string roads[] = {".AB"
				                 ,"A.C"
				                 ,"BC."};
				int queries[] = {0, 1, 2, 3};
				int __expected[] = {0, 1, 2, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineTour(vector <string>(roads, roads+sizeof(roads)/sizeof(string)), vector <int>(queries, queries+sizeof(queries)/sizeof(int))); break;
			}
			case 1:
			{
				string roads[] = {".A..C"
				                 ,"A.ABB"
				                 ,".A.C."
				                 ,".BC.."
				                 ,"CB..."};
				int queries[] = {0, 1, 2, 3, 4, 5, 6};
				int __expected[] = {0, 1, 3, 2, 1, 4, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineTour(vector <string>(roads, roads+sizeof(roads)/sizeof(string)), vector <int>(queries, queries+sizeof(queries)/sizeof(int))); break;
			}
			case 2:
			{
				string roads[] = {".aa"
				                 ,"a.A"
				                 ,"aA."};
				int queries[] = {3, 2, 1};
				int __expected[] = {0, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineTour(vector <string>(roads, roads+sizeof(roads)/sizeof(string)), vector <int>(queries, queries+sizeof(queries)/sizeof(int))); break;
			}
			case 3:
			{
				string roads[] = {"..A.A"
				                 ,"...A."
				                 ,"A...A"
				                 ,".A..."
				                 ,"A.A.."};
				int queries[] = {1, 2};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineTour(vector <string>(roads, roads+sizeof(roads)/sizeof(string)), vector <int>(queries, queries+sizeof(queries)/sizeof(int))); break;
			}
			case 4:
			{
				string roads[] = {
					".ZZ",
					"Z.z",
					"Zz."
				};
				int queries[] = {0,1,2};
				int __expected[] = {0,1,2};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineTour(vector <string>(roads, roads+sizeof(roads)/sizeof(string)), vector <int>(queries, queries+sizeof(queries)/sizeof(int))); break;
			}
			case 5:
			{
				string roads[] = {
					".a",
					"a."
				};
				int queries[] = {0,1};
				int __expected[] = {};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineTour(vector <string>(roads, roads+sizeof(roads)/sizeof(string)), vector <int>(queries, queries+sizeof(queries)/sizeof(int))); break;
			}
			case 6:
			{
				string roads[] = {
					".ZZ",
					"Z.Z",
					"ZZ."
				};
				int queries[] = {0,1,2};
				int __expected[] = {};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineTour(vector <string>(roads, roads+sizeof(roads)/sizeof(string)), vector <int>(queries, queries+sizeof(queries)/sizeof(int))); break;
			}
			case 7:
			{
				string roads[] = {".zmyYMV", "z.etalY", "me.CLUI", "ytC.MsL", "YaLM.wo", "MlUsw.i", "VYILoi."};
				int queries[] = {0, 1, 21, 20, 17, 11, 10, 13, 2, 9, 19, 8, 12, 15, 3, 5, 16, 6, 7, 4, 14, 18};
				int __expected[] = {0, 1, 0, 6, 6, 2, 6, 4, 2, 1, 5, 5, 3, 5, 0, 1, 3, 4, 0, 3, 2, 4};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineTour(vector <string>(roads, roads+sizeof(roads)/sizeof(string)), vector <int>(queries, queries+sizeof(queries)/sizeof(int))); break;
			}
			case 8:
			{
				string roads[] = {
					".ca",
					"c.b",
					"ab.",
				};
				int queries[] = {0,1,2};
				int __expected[] = {0,1,2};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.determineTour(vector <string>(roads, roads+sizeof(roads)/sizeof(string)), vector <int>(queries, queries+sizeof(queries)/sizeof(int))); break;
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
