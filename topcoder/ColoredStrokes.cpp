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
class ColoredStrokes {
	public:
	int getLeast(vector <string> a) {
		ll n=a.size(),m=a[0].length();
		ll ans=0;
		for (ll r=0;r<n;r++) {
			bool in=false;
			for (ll c=0;c<m;c++) {
				char x=a[r][c];
				if (!in&&(x=='R'||x=='G')) {
					in=true;
					ans++;
				}
				else if (in&&!(x=='R'||x=='G')) {
					in=false;
				}
			}
		}
		for (ll c=0;c<m;c++) {
			bool in=false;
			for (ll r=0;r<n;r++) {
				char x=a[r][c];
				if (!in&&(x=='B'||x=='G')) {
					in=true;
					ans++;
				}
				else if (in&&!(x=='B'||x=='G')) {
					in=false;
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
		cout << "Testing ColoredStrokes (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484510634;
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
		ColoredStrokes _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string picture[] = {"...",
				                    "..."};
				_expected = 0;
				_received = _obj.getLeast(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			case 1:
			{
				string picture[] = {"..B.",
				                    "..B."};
				_expected = 1;
				_received = _obj.getLeast(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			case 2:
			{
				string picture[] = {".BB."};
				_expected = 2;
				_received = _obj.getLeast(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			case 3:
			{
				string picture[] = {"...B..",
				                    ".BRGRR",
				                    ".B.B.."};
				_expected = 3;
				_received = _obj.getLeast(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			case 4:
			{
				string picture[] = {"...B..",
				                    ".BRBRR",
				                    ".B.B.."};
				_expected = 4;
				_received = _obj.getLeast(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			case 5:
			{
				string picture[] = {"GR",
				                    "BG"};
				_expected = 4;
				_received = _obj.getLeast(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			/*case 6:
			{
				string picture[] = ;
				_expected = ;
				_received = _obj.getLeast(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string picture[] = ;
				_expected = ;
				_received = _obj.getLeast(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string picture[] = ;
				_expected = ;
				_received = _obj.getLeast(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
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
