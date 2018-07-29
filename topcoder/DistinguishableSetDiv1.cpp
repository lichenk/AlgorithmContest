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
int f[1<<21];
class DistinguishableSetDiv1 {
	public:
	int count(vector <string> answer) {
		ll gn=answer.size();
		ll gm=answer[0].length();
		ll zlim=1LL<<gm;
		for (ll z=0;z<zlim;z++) f[z]=0;
		for (ll x=0;x<gn;x++) {
			for (ll y=0;y<x;y++) {
				ll got=0;
				for (ll k=0;k<gm;k++) {
					if (answer[x][k]!=answer[y][k]) got|=1LL<<k;
				}
				f[got]=1;
			}
		}
		for (ll x=0;x<gm;x++) {
			ll msk=1LL<<x;
			for (ll z=0;z<zlim;z++) {
				if (f[z]&&!(z&msk)) {
					f[z^msk]=1;
				}
			}
		}
		ll ans=0;
		for (ll z=0;z<zlim;z++) ans+=f[z];
		return zlim-ans;
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
		cout << "Testing DistinguishableSetDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470893841;
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
		DistinguishableSetDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string answer[] = {"AA","AB","CC"};
				_expected = 2;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 1:
			{
				string answer[] = {"XYZ","XYZ","XYZ"};
				_expected = 0;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 2:
			{
				string answer[] = {"AAAA","BACA","CDCE"};
				_expected = 11;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			case 3:
			{
				string answer[] = {"XYZ","XAB","YAC"};
				_expected = 5;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}
			/*case 4:
			{
				string answer[] = {};
				_expected = ;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string answer[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string answer[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string answer[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(answer, answer+sizeof(answer)/sizeof(string))); break;
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
