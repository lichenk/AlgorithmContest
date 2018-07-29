#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
complex<ll> t[301];
class ForkliftTruckOperator {
	public:
	int getNumber(string pallets) {
		ll n = pallets.length();
		for (ll i = 0; i < n; i++) {
			if (pallets[i] == 'A') {
				t[i].real() = 1; t[i].imag() = 0;
			}
			else if (pallets[i] == 'B') {
				t[i].real() = 0; t[i].imag() = 1;
			}
			else {assert(false);}
		}
		while(n >= 2) {
			bool halvegood = false;
			if (n%2 == 0) {
				bool halvegood1 = true;
				for (ll i = 0; i < n/2; i++) {
					if (t[i] != t[0]) halvegood1 = false;
				}
				bool halvegood2 = true;
				for (ll i = n/2; i < n; i++) {
					if (t[i] != t[n/2]) halvegood2 = false;
				}
				halvegood = halvegood1 || halvegood2;
			}
			if (halvegood) {
				shift(n/2, n-1, 0, n/2-1);
			}
			else {
				complex<ll> x = t[0];
				complex<ll> y;
				bool found = false;
				for (ll i = 0; i < n; i++) {
					if (t[i] != x) {y = t[i]; found = true; break;}
				}
				assert(found);
				for (ll i = 0; i < n; i++) {
					if (t[i] != x && t[i] != y) {return -1;}
				}
				vector<pair<ll,ll> > segx, segy;
				ll left = 0;
				complex<ll> prev = t[0];
				for (ll i = 0; i <= n; i++) {
					if (i == n || t[i] != prev) {
						ll right = i-1;
						pair<ll,ll> seg = MP(left, right);
						if (prev == x) segx.PB(seg);
						else if (prev == y) segy.PB(seg);
						else assert(false);
						left = i;
						prev = t[i];
					}
				}
				// WLOG segx has smaller size
				if (segy.size() < segx.size()) swap(segx, segy);
				if (segx.size() == 0) {
					// Copy y onto itself
					shift(n/2, 2*(n/2), 0, n/2-1);
				}
				else if (segx.size() == 1 && segy.size() == 1) {
					ll lenx = segx[0].second - segx[0].first + 1;
					ll leny = segy[0].second - segy[0].first + 1;
					if (leny > lenx) swap(segx, segy);
					shift(segx[0].first, segx[0].second, segy[0].first, segy[0].second);
				}
				else {
					
				}
			}

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
		cout << "Testing ForkliftTruckOperator (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451195126;
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
		ForkliftTruckOperator _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string pallets = "RRBRBR";
				_expected = 4;
				_received = _obj.getNumber(pallets); break;
			}
			case 1:
			{
				string pallets = "RB";
				_expected = 1;
				_received = _obj.getNumber(pallets); break;
			}
			case 2:
			{
				string pallets = "RRRRRR";
				_expected = 3;
				_received = _obj.getNumber(pallets); break;
			}
			case 3:
			{
				string pallets = "RRRRBBBBBBBBB";
				_expected = 5;
				_received = _obj.getNumber(pallets); break;
			}
			case 4:
			{
				string pallets = "RBRBRBRBRBRBRB";
				_expected = -1;
				_received = _obj.getNumber(pallets); break;
			}
			case 5:
			{
				string pallets = "B";
				_expected = 0;
				_received = _obj.getNumber(pallets); break;
			}
			case 6:
			{
				string pallets = "BBBBBBBBBBBBBBBBRRRRRRRRBRBBRRRR";
				_expected = 5;
				_received = _obj.getNumber(pallets); break;
			}
			/*case 7:
			{
				string pallets = ;
				_expected = ;
				_received = _obj.getNumber(pallets); break;
			}*/
			/*case 8:
			{
				string pallets = ;
				_expected = ;
				_received = _obj.getNumber(pallets); break;
			}*/
			/*case 9:
			{
				string pallets = ;
				_expected = ;
				_received = _obj.getNumber(pallets); break;
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
