#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define EPS 0.0000000001
vector<int> tg;
vector<int> xg;
ll Cg;
ll n;

bool f(ld r) {
	ld v = 0;
	for (ll i = 0; i < n; i++) {
		ld d = xg[i]-r;
		v += d * tg[i];
		v = max(v,(ld)0);
		if (v > Cg) {
			return false;
		}
	}
	return true;
}


ld binsearch(ld imin, ld imax)
{
    while (imin + EPS < imax)
    {
        ld imid = (imin+imax)/2;
        // reduce the search
        //cout << imid << ":" << f(imid) << endl;
        if (f(imid) == false)
            imin = imid + EPS;
        else
            imax = imid - EPS;
    }
    return imin;
}


class WaterTank {
	public:
	double minOutputRate(vector <int> t, vector <int> x, int C) {
		tg = t;
		n = tg.size();
		xg = x;
		Cg = C;
		int imax = 0;
		for (ll i = 0; i < n; i++) {
			imax = max(imax, x[i]);
		}
		ld ans = binsearch(0, imax+1);
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
		cout << "Testing WaterTank (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450454402;
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
		WaterTank _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int t[] = {3,3};
				int x[] = {1,2};
				int C = 3;
				_expected = 0.9999999999999999;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}
			case 1:
			{
				int t[] = {1,2,3,4,5};
				int x[] = {5,4,3,2,1};
				int C = 10;
				_expected = 1.9999999999999996;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}
			case 2:
			{
				int t[] = {5949,3198,376,3592,4019,3481,5609,3840,6092,4059};
				int x[] = {29,38,96,84,10,2,39,27,76,94};
				int C = 1000000000;
				_expected = 0.0;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}
			case 3:
			{
				int t[] = {9,3,4,8,1,2,5,7,6};
				int x[] = {123,456,789,1011,1213,1415,1617,1819,2021};
				int C = 11;
				_expected = 2019.1666666666665;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}
			case 4:
			{
				int t[] = {100};
				int x[] = {1000};
				int C = 12345;
				_expected = 876.55;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}
			/*case 5:
			{
				int t[] = ;
				int x[] = ;
				int C = ;
				_expected = ;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}*/
			/*case 6:
			{
				int t[] = ;
				int x[] = ;
				int C = ;
				_expected = ;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
			}*/
			/*case 7:
			{
				int t[] = ;
				int x[] = ;
				int C = ;
				_expected = ;
				_received = _obj.minOutputRate(vector <int>(t, t+sizeof(t)/sizeof(int)), vector <int>(x, x+sizeof(x)/sizeof(int)), C); break;
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
