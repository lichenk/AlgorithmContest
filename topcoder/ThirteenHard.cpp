#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<int,int> pii;
const int mn=25;
vector<pii> g[mn];
const int mk=13;
const int mz=1<<12;
int vdist[mn][mk-1][mz];
typedef pair<int,int> pp;
inline int MK(int x, int k, int z) {
	return (x<<24)|(k<<16)|z;
}
inline int getx(int t) {return t>>24;}
inline int getk(int t) {return (t>>16)&15;}
inline int getz(int t) {return t&(mz-1);}
void dij(int n) {
	priority_queue<pp,vector<pp>,greater<pp> > pq;
	for (int x=0;x<n;x++) for (int k=0;k<mk-1;k++) for (int z=0;z<mz;z++) vdist[x][k][z]=1<<29;
	pq.push(MP(0,MK(0,0,0)));
	while(!pq.empty()) {
		auto got=pq.top(); pq.pop();
		int dist=got.fst; int x=getx(got.snd),k=getk(got.snd),z=getz(got.snd);
		if (dist!=0&&dist>vdist[x][k-1][z]) continue;
		for (auto &gg:g[x]) {
			int y=gg.fst,cost=gg.snd;
			int ndist=dist+cost;
			int rem=ndist%13;
			if (rem!=0) {
				int remsk=1<<(rem-1);
				if ((remsk&z)==0) {
					int nz=remsk|z;
					int nk=rem;
					if (ndist<vdist[y][nk-1][nz]) {
						vdist[y][nk-1][nz]=ndist;
						pq.push(MP(ndist,MK(y,nk,nz)));
					}
				}
			}
		}
	}
}



class ThirteenHard {
	public:
	int calcTime(vector <string> city) {
		int n=city.size();
		for (int x=0;x<n;x++) {
			for (int y=0;y<n;y++) {
				char c=city[x][y];
				if (c!='#') {
					int t;
					if ('A'<=c&&c<='Z') t=c-'A'+1;
					else t=c-'a'+27;
					g[x].PB(MP(y,t));
				}
			}
		}
		dij(n);
		int ans=1<<29;
		for (int k=0;k<mk-1;k++)
		for (int z=0;z<mz;z++) {
			chkmin(ans,vdist[n-1][k][z]);
		}
		if (ans==(1<<29)) ans=-1;
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
		cout << "Testing ThirteenHard (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1520827027;
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
		ThirteenHard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string city[] = { "#AB##",
				                  "###A#",
				                  "###C#",
				                  "####K",
				                  "#####" };
				_expected = 16;
				_received = _obj.calcTime(vector <string>(city, city+sizeof(city)/sizeof(string))); break;
			}
			case 1:
			{
				string city[] = { "#Z",
				                  "Z#" };
				_expected = -1;
				_received = _obj.calcTime(vector <string>(city, city+sizeof(city)/sizeof(string))); break;
			}
			case 2:
			{
				string city[] = { "Good#####",
				                  "#Luck####",
				                  "##and####",
				                  "##Have###",
				                  "####Fun##",
				                  "#####in##",
				                  "#####the#",
				                  "CHALLENGE",
				                  "##PHASE##" };
				_expected = 137;
				_received = _obj.calcTime(vector <string>(city, city+sizeof(city)/sizeof(string))); break;
			}
			case 3:
			{
				string city[] = { "###No#####",
				                  "####Zaphod",
				                  "#####Just#",
				                  "######very",
				                  "####very##",
				                  "improbable",
				                  "##########",
				                  "##########",
				                  "##########",
				                  "##########" };
				_expected = 103;
				_received = _obj.calcTime(vector <string>(city, city+sizeof(city)/sizeof(string))); break;
			}
			case 4:
			{
				string city[] = { "#B#C##T#M",
				                  "##K######",
				                  "########A",
				                  "####R####",
				                  "#####U###",
				                  "########C",
				                  "#######H#",
				                  "########S",
				                  "#########" };
				_expected = 47;
				_received = _obj.calcTime(vector <string>(city, city+sizeof(city)/sizeof(string))); break;
			}
			case 5:
			{
				string city[] = {"#Z","##"};
				_expected = -1;
				_received = _obj.calcTime(vector <string>(city, city+sizeof(city)/sizeof(string))); break;
			}
			case 6:
			{
				string city[] = {"#A","#Z"};
				_expected = 1;
				_received = _obj.calcTime(vector <string>(city, city+sizeof(city)/sizeof(string))); break;
			}
			case 7:
			{
				vector<string> vs;
				for (int x=0;x<25;x++) {
					string s; s.resize(25);
					for (int y=0;y<25;y++) {
						if (x==y) s[y]='#';
						else s[y]='z';
					}
					vs.PB(s);
				}
				_expected = -1;
				_received = _obj.calcTime(vs); break;
			}
			case 8:
			{
				string city[] = {"##PH###", "##ZEI##", "##CMaX#", "BJ#U###", "###U#GY", "QVAL###", "SW#F##a"};
				_expected = 67;
				_received = _obj.calcTime(vector <string>(city, city+sizeof(city)/sizeof(string))); break;
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
