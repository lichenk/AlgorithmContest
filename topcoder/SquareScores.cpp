#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class SquareScores {
	public:
	double calcexpectation(vector <int> p, string s) {
		ld q[26];
		for (ll i = 0; i < 26; i++) q[i] = 0;
		for (ll i = 0; i < p.size(); i++) q[i] = ((ld)p[i])/100.0;
		ll n = s.length();
		ld ans = 0;
		for (ll x = 0; x < n; x++) {
			if (s[x] != '?') {
				ld cand = 1.0;
				char orig = s[x];
				for (ll y = x; y < n; y++) {
					if (s[y] == orig) {
					}
					else if (s[y] == '?') {
						cand *= q[orig-'a'];
					}
					else {
						break;
					}
					ans += cand;
				}
			}
			else {
				for (ll c = 0; c < 26; c++) {
					ld cand = q[c];
					char orig = 'a'+c;
					ans += cand;
					for (ll y = x+1; y < n; y++) {
						if (s[y] == orig) {
						}
						else if (s[y] == '?') {
							cand *= q[orig-'a'];
						}
						else {
							break;
						}
						ans += cand;
					}
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
		cout << "Testing SquareScores (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1452394704;
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
		SquareScores _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {1, 99};
				string s = "aaaba";
				_expected = 8.0;
				_received = _obj.calcexpectation(vector <int>(p, p+sizeof(p)/sizeof(int)), s); break;
			}
			case 1:
			{
				int p[] = {10, 20, 70};
				string s = "aa?bbbb";
				_expected = 15.0;
				_received = _obj.calcexpectation(vector <int>(p, p+sizeof(p)/sizeof(int)), s); break;
			}
			case 2:
			{
				int p[] = {10, 20, 30, 40};
				string s = "a??c?dc?b";
				_expected = 11.117;
				_received = _obj.calcexpectation(vector <int>(p, p+sizeof(p)/sizeof(int)), s); break;
			}
			case 3:
			{
				int p[] = {25, 25, 21, 2, 2, 25};
				string s = "a??b???????ff??e";
				_expected = 21.68512690712425;
				_received = _obj.calcexpectation(vector <int>(p, p+sizeof(p)/sizeof(int)), s); break;
			}
			case 4:
			{
				int p[] = {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4};
				string s = "??????????????????????????????";
				_expected = 31.16931963781721;
				_received = _obj.calcexpectation(vector <int>(p, p+sizeof(p)/sizeof(int)), s); break;
			}
			case 5:
			{
				int p[] = {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3};
				string s = "makigotapresentfromniko";
				_expected = 23.0;
				_received = _obj.calcexpectation(vector <int>(p, p+sizeof(p)/sizeof(int)), s); break;
			}
			/*case 6:
			{
				int p[] = ;
				string s = ;
				_expected = ;
				_received = _obj.calcexpectation(vector <int>(p, p+sizeof(p)/sizeof(int)), s); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				string s = ;
				_expected = ;
				_received = _obj.calcexpectation(vector <int>(p, p+sizeof(p)/sizeof(int)), s); break;
			}*/
			/*case 8:
			{
				int p[] = ;
				string s = ;
				_expected = ;
				_received = _obj.calcexpectation(vector <int>(p, p+sizeof(p)/sizeof(int)), s); break;
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
