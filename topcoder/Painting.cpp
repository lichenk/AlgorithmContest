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
class Painting {
	public:
	int largestBrush(vector <string> a) {
		for (ll d=50;d>=1;d--) {
			vector<string> b=a;
			for (auto &x:b) for (auto &y:x) y='W';
			ll n=a.size(),m=a[0].length();
			for (ll x=0;x<=n-d;x++) {
				for (ll y=0;y<=m-d;y++) {
					bool ok=true;
					for (ll i=x;i<x+d;i++) for (ll j=y;j<y+d;j++) {
						if (a[i][j]=='W') {
							ok=false; break;
						}
					}
					//printf("x:%lld y:%lld d:%lld ok:%d\n",x,y,d,ok);
					if (ok) for (ll i=x;i<x+d;i++) for (ll j=y;j<y+d;j++) b[i][j]='B';
				}
			}
			//cout<<d<<endl;
			//for (auto &x:b) cout<<x<<endl;
			if (a==b) return d;
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
		cout << "Testing Painting (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484527748;
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
		Painting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string picture[] = {"BBBB",
				                    "BBBB",
				                    "BBBB",
				                    "BBBB"};
				_expected = 4;
				_received = _obj.largestBrush(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			case 1:
			{
				string picture[] = {"BBBB",
				                    "BWWB",
				                    "BWWB",
				                    "BBBB"};
				_expected = 1;
				_received = _obj.largestBrush(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			case 2:
			{
				string picture[] = {"WBBBBB",
				                    "BBBBBB",
				                    "BBBBBB",
				                    "BBBBBB"};
				_expected = 3;
				_received = _obj.largestBrush(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			case 3:
			{
				string picture[] = {"BBBB",
				                    "BBBB",
				                    "WBBB",
				                    "BBBB",
				                    "BBBB",
				                    "BBBB"};
				_expected = 2;
				_received = _obj.largestBrush(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			case 4:
			{
				string picture[] = {"WBBBBBWWWWWWWWW",
				                    "WBBBBBBWWWWWWWW",
				                    "WBBBBBBBBBBBWWW",
				                    "WBBBBBBBBBBBWWW",
				                    "BBBBBBBBBBBBBBB",
				                    "BBBBBBBBBBBBBBB",
				                    "BBBBBBBBBBBBBBB",
				                    "BBBBBBBBWWBBBBB",
				                    "BBBBBBBBWBBBBBB",
				                    "WBBBBBBBWBBBBBW",
				                    "BBBBBBBWWBBBBBW",
				                    "BBBBBBBWWBBBBBW",
				                    "BBBBBBWWWBBBBBW",
				                    "BBBBBWWWWWWWWWW",
				                    "BBBBBWWWWWWWWWW"};
				_expected = 5;
				_received = _obj.largestBrush(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}
			/*case 5:
			{
				string picture[] = ;
				_expected = ;
				_received = _obj.largestBrush(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string picture[] = ;
				_expected = ;
				_received = _obj.largestBrush(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string picture[] = ;
				_expected = ;
				_received = _obj.largestBrush(vector <string>(picture, picture+sizeof(picture)/sizeof(string))); break;
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
