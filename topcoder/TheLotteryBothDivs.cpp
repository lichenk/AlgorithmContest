#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class TheLotteryBothDivs {
	public:
	double find(vector <string> _ss) {
		set<string> xx;
		for (auto &w:_ss) xx.insert(w);
		vector<string> s;
		for (auto &w:xx) s.PB(w);
		for (auto &w:s) reverse(w.begin(),w.end());
		ll n=s.size();
		ll ans=0;
		for (ll x=0;x<n;x++) {
			bool good=true;
			for (ll y=0;y<n;y++) {
				if (x==y) continue;
				if (s[y].length()<=s[x].length()) {
					bool ispre=true;
					for (ll i=0;i<s[y].length();i++) {
						if (s[x][i]!=s[y][i]) ispre=false;
					}
					if (ispre) good=false;
				}
			}
			if (good) {
				ll t=1;
				for (ll i=0;i<9-s[x].length();i++) t*=10;
				ans+=t;
			}
		}
		//printf("ans:%lld\n",ans);
		return (ld)ans/1e9;
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
		cout << "Testing TheLotteryBothDivs (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484379725;
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
		TheLotteryBothDivs _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string goodSuffixes[] = {"4"};
				_expected = 0.1;
				_received = _obj.find(vector <string>(goodSuffixes, goodSuffixes+sizeof(goodSuffixes)/sizeof(string))); break;
			}
			case 1:
			{
				string goodSuffixes[] = {"4", "7"};
				_expected = 0.2;
				_received = _obj.find(vector <string>(goodSuffixes, goodSuffixes+sizeof(goodSuffixes)/sizeof(string))); break;
			}
			case 2:
			{
				string goodSuffixes[] = {"47", "47"};
				_expected = 0.01;
				_received = _obj.find(vector <string>(goodSuffixes, goodSuffixes+sizeof(goodSuffixes)/sizeof(string))); break;
			}
			case 3:
			{
				string goodSuffixes[] = {"47", "58", "4747", "502"};
				_expected = 0.021;
				_received = _obj.find(vector <string>(goodSuffixes, goodSuffixes+sizeof(goodSuffixes)/sizeof(string))); break;
			}
			case 4:
			{
				string goodSuffixes[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"};
				_expected = 0.201100101;
				_received = _obj.find(vector <string>(goodSuffixes, goodSuffixes+sizeof(goodSuffixes)/sizeof(string))); break;
			}
			/*case 5:
			{
				string goodSuffixes[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(goodSuffixes, goodSuffixes+sizeof(goodSuffixes)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string goodSuffixes[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(goodSuffixes, goodSuffixes+sizeof(goodSuffixes)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string goodSuffixes[] = ;
				_expected = ;
				_received = _obj.find(vector <string>(goodSuffixes, goodSuffixes+sizeof(goodSuffixes)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
