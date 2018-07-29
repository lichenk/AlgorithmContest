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
ll av[22];
class StrIIRec {
	public:
	string recovstr(int n, int minInv, string minStr) {
		bool exc=false;
		string ans;
		ll inv=0;
		for (ll x=0;x<n;x++) av[x]=1;
		for (ll x=0;x<n;x++) {
			for (ll c=0;c<n;c++) {
				if (av[c]==0) continue;
				if ((!exc)&&c<(minStr[x]-'a')) continue;
				ll got=0;
				for (ll d=0;d<n;d++) {
					if (av[d]&&d<c) got++;
				}
				ll left=n-1-x;
				got+=left*(left-1)/2;
				got+=inv;
				//printf("x:%lld c:%lld inv:%lld got:%lld\n",x,c,inv,got);
				if (got>=minInv) {
					char ch='a'+c;
					ans+=ch;
					if (c>(minStr[x]-'a')) exc=true;
					av[c]=0;
					inv=got-left*(left-1)/2;
					break;
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
		cout << "Testing StrIIRec (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470761276;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		StrIIRec _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int minInv = 1;
				string minStr = "ab";
				_expected = "ba";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 1:
			{
				int n = 9;
				int minInv = 1;
				string minStr = "efcdgab";
				_expected = "efcdgabhi";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 2:
			{
				int n = 11;
				int minInv = 55;
				string minStr = "debgikjfc";
				_expected = "kjihgfedcba";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 3:
			{
				int n = 15;
				int minInv = 0;
				string minStr = "e";
				_expected = "eabcdfghijklmno";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			case 4:
			{
				int n = 9;
				int minInv = 20;
				string minStr = "fcdebiha";
				_expected = "fcdehigba";
				_received = _obj.recovstr(n, minInv, minStr); break;
			}
			/*case 5:
			{
				int n = ;
				int minInv = ;
				string minStr = ;
				_expected = ;
				_received = _obj.recovstr(n, minInv, minStr); break;
			}*/
			/*case 6:
			{
				int n = ;
				int minInv = ;
				string minStr = ;
				_expected = ;
				_received = _obj.recovstr(n, minInv, minStr); break;
			}*/
			/*case 7:
			{
				int n = ;
				int minInv = ;
				string minStr = ;
				_expected = ;
				_received = _obj.recovstr(n, minInv, minStr); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
