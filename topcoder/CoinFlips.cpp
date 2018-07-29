#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll MAXN = 308;
ld *f[MAXN][MAXN];
ld tpow[MAXN];
class CoinFlips {
	public:
	double getExpectation(vector <int> vals, int prob) {
		ll n = vals.size();
		ld t = ((ld)(1000000000-prob))/1000000000;
		tpow[0] = 1.0;
		for (ll i=1;i<=n+2;i++) {
			tpow[i] = tpow[i-1]*t;
		}
		for (ll r=0;r<=n;r++) {
			for (ll x=0;x<=n;x++) {
				f[r][x] = new ld[MAXN];
				for (ll y=0;y<=n;y++) {
					f[r][x][y] = 0;
				}
			}
		}
		for (ll r = 2; r < n; r++) {
			for (ll x=1; x<=r;x++) {
				for (ll y=x+1;y<=r;y++) {
					ld val = f[r][x][y];
					{
						// Middle
						ll d = y-x;
						ld mval = val;
						if (d==1) {
							mval = 1;
						}
						ld q = tpow[x] * (1-tpow[d]);
						f[r+1][x][y+1] += mval*q;
					}
					{
						// Left
						ld q = tpow[r+1] + (1-tpow[x]);

						f[r+1][x+1][y+1] += val*q;
					}
					{
						// Right
						ld q = tpow[y] - tpow[r+1];
						f[r+1][x][y] += val*q;
					}
				}
			}
		}
		ld ans = 0;
		for (ll x=1;x<=n;x++) {
			for (ll y=x+1;y<=n;y++) {
				ll val = vals[x-1] * vals[y-1];
				ans += (val * f[n][x][y]);
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
		cout << "Testing CoinFlips (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454781319;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CoinFlips _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int vals[] = {2,3,4};
				int prob = 500000000;
				_expected = 2.0;
				_received = _obj.getExpectation(vector <int>(vals, vals+sizeof(vals)/sizeof(int)), prob); break;
			}
			case 1:
			{
				int vals[] = {5,1,4,2,3};
				int prob = 100000000;
				_expected = 4.985392200480001;
				_received = _obj.getExpectation(vector <int>(vals, vals+sizeof(vals)/sizeof(int)), prob); break;
			}
			case 2:
			{
				int vals[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int prob = 0;
				_expected = 0.0;
				_received = _obj.getExpectation(vector <int>(vals, vals+sizeof(vals)/sizeof(int)), prob); break;
			}
			case 3:
			{
				int vals[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int prob = 1000000000;
				_expected = 0.0;
				_received = _obj.getExpectation(vector <int>(vals, vals+sizeof(vals)/sizeof(int)), prob); break;
			}
			case 4:
			{
				int vals[] = {1,2,3,4,5,6,7,8,9,10};
				int prob = 250000000;
				_expected = 130.25145424313288;
				_received = _obj.getExpectation(vector <int>(vals, vals+sizeof(vals)/sizeof(int)), prob); break;
			}
			case 5:
			{
				int vals[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,5,6,2,6,4,3,3,8,3,2,7,9,5};
				int prob = 123456789;
				_expected = 481.6707820920715;
				_received = _obj.getExpectation(vector <int>(vals, vals+sizeof(vals)/sizeof(int)), prob); break;
			}
			case 6:
			{
				int vals[] = {1,1,1,1};
				int prob = 500000000;
				_expected = 0.625;
				_received = _obj.getExpectation(vector <int>(vals, vals+sizeof(vals)/sizeof(int)), prob); break;
			}
			case 7:
			{
				int vals[] = {6, 131, 7, 207, 114, 203, 8, 4, 4, 88, 5, 47, 1, 4, 2, 5, 28, 441, 490, 13, 197, 35, 194, 412, 920, 1, 80, 567, 8, 4, 211, 297, 419, 212, 2, 206, 6, 7, 45, 24, 10, 174, 208, 57, 94, 1, 60, 751, 171, 118, 1, 126, 1, 149, 109, 13, 135, 485, 215, 1, 85, 1, 166, 21, 12, 64, 211, 24, 13, 4, 76, 3, 322, 69, 19, 1, 711, 41, 5, 107, 47, 1, 8, 2, 528, 4, 144, 88, 3, 49, 296, 1, 183, 230, 41, 77, 914, 1, 1, 53, 37, 5, 489, 338, 5, 495, 60, 2, 2, 24, 68, 3, 135, 426, 314, 7, 5, 445, 15, 216, 19, 259, 2, 40, 3, 1, 10, 4, 18, 118, 15, 119, 104, 4, 339, 2, 358, 3, 11, 3, 974, 270, 24, 1, 679, 25, 57, 4, 404, 3, 5, 47, 52, 512, 37, 7, 28, 15, 170, 329, 15, 35, 1, 4, 1, 438, 24, 897, 439, 8, 64, 149, 3, 296, 199, 399, 92, 2, 9, 5, 115, 1, 16, 58, 1, 4, 64, 19, 119, 1, 475, 3, 26, 1, 34, 34, 9, 3, 440, 185, 274, 1, 34, 220, 2, 2, 485, 5, 365, 152, 35, 21, 515, 4, 4, 79, 776, 584, 5, 212, 4, 25, 169, 10, 2, 55, 1, 24, 361, 11, 5, 183, 1, 1, 2, 11, 94, 2, 1, 51, 12, 132, 35, 2, 32, 16, 10, 4, 6, 993, 20, 22, 244, 20, 90, 18};
				int prob = 194635294;
				_expected = 3052332.6736270026;
				_received = _obj.getExpectation(vector <int>(vals, vals+sizeof(vals)/sizeof(int)), prob); break;
			}
			/*case 8:
			{
				int vals[] = ;
				int prob = ;
				_expected = ;
				_received = _obj.getExpectation(vector <int>(vals, vals+sizeof(vals)/sizeof(int)), prob); break;
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
