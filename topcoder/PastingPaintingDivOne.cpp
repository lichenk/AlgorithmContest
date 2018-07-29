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
const int MAXN=5000+50;
char b[MAXN+4][MAXN+4];
char a[50][50];
class PastingPaintingDivOne {
	public:
	vector<long long> countColors(vector <string> clipboard, int T) {
		int n=clipboard.size();
		int m=clipboard[0].length();
		for (int x=0;x<n;x++) {
			for (int y=0;y<m;y++) {
				a[x][y]=clipboard[x][y];
			}
		}
		ll go=min(T,MAXN-50);
		for (ll k=0;k<go-1;k++) {
			for (ll x=0;x<n;x++) {
				for (ll y=0;y<m;y++) {
					if (a[x][y]=='.') continue;
					b[k+x][k+y]=a[x][y];
				}
			}
		}
		
			ll rz=0,gz=0,blz=0;
			for (int x=0;x<MAXN;x++) for (int y=0;y<MAXN;y++) {
				if (b[x][y]=='R')rz++;
				else if (b[x][y]=='G')gz++;
				else if (b[x][y]=='B')blz++;
			}
		
		{
			ll k=go-1;
			for (ll x=0;x<n;x++) {
				for (ll y=0;y<m;y++) {
					if (a[x][y]=='.') continue;
					b[k+x][k+y]=a[x][y];
				}
			}
		}
		{
			ll r=0,g=0,bl=0;
			for (int x=0;x<MAXN;x++) for (int y=0;y<MAXN;y++) {
				if (b[x][y]=='R')r++;
				else if (b[x][y]=='G')g++;
				else if (b[x][y]=='B')bl++;
			}
			//printf("%d %d %d. %d %d %d. %d %d",r,g,bl,rz,gz,blz,T,go);
			r=(r-rz)*(T-go+1)+rz;
			g=(g-gz)*(T-go+1)+gz;
			bl=(bl-blz)*(T-go+1)+blz;
					vector<ll> ans;
		ans.PB(r);ans.PB(g);ans.PB(bl);
		return ans;
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
		cout << "Testing PastingPaintingDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1464099076;
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
		PastingPaintingDivOne _obj;
		vector<long long> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string clipboard[] = {
				                     "..G",
				                     "R..",
				                     "BG."
				                     };
				int T = 3;
				long long __expected[] = {3, 4, 3 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			case 1:
			{
				string clipboard[] = {
				                     "R...",
				                     "....",
				                     "....",
				                     "...R"
				                     };
				int T = 2;
				long long __expected[] = {4, 0, 0 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			case 2:
			{
				string clipboard[] = {"RGB"};
				int T = 100000;
				long long __expected[] = {100000, 100000, 100000 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			case 3:
			{
				string clipboard[] = {"."};
				int T = 1000000000;
				long long __expected[] = {0, 0, 0 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			case 4:
			{
				string clipboard[] = {
				                     "RB.",
				                     ".G."
				                     };
				int T = 100;
				long long __expected[] = {100, 1, 100 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			case 5:
			{
				string clipboard[] = {
				                     "..........G..........",
				                     ".........G.G.........",
				                     "........G...G........",
				                     ".......G.....G.......",
				                     "......G..B.B..G......",
				                     ".....G...B.B...G.....",
				                     "....G...........G....",
				                     "...G...R.....R...G...",
				                     "..G.....RRRRRR....G..",
				                     ".G..........RR.....G.",
				                     "GGGGGGGGGGGGGGGGGGGGG"
				                     };
				int T = 1000000000;
				long long __expected[] = {2000000018, 17000000048, 2000000005 };
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}
			/*case 6:
			{
				string clipboard[] = ;
				int T = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}*/
			/*case 7:
			{
				string clipboard[] = ;
				int T = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
			}*/
			/*case 8:
			{
				string clipboard[] = ;
				int T = ;
				long long __expected[] = ;
				_expected = vector<long long>(__expected, __expected+sizeof(__expected)/sizeof(long long));
				_received = _obj.countColors(vector <string>(clipboard, clipboard+sizeof(clipboard)/sizeof(string)), T); break;
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
