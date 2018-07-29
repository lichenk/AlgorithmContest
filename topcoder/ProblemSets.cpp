#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
class ProblemSets {
	public:
	long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
		ll imin = 0;
		ll imax = 2000000000000000002LL;
		while (imin < imax) {
			ll imid = imin + (imax - imin)/2;
			ll e = E; ll em = EM; ll m = M; ll mh = MH; ll h = H;
			ll neede = max(0LL, imid - e);
			em -= neede; e += neede;
			ll needh = max(0LL, imid - h);
			mh -= needh; h += needh;
			ll needm = max(0LL, imid - m);
			bool ok = false;
			if (em >= 0 && mh >= 0 && em + mh >= needm) {
				ok = true;
			}
			if (ok) {
				imin = imid+1;
			}
			else {
				imax = imid;
			}
		}
		assert(imin == imax);
		return imin-1;
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
		cout << "Testing ProblemSets (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451022666;
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
		ProblemSets _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long E = 2LL;
				long long EM = 2LL;
				long long M = 1LL;
				long long MH = 2LL;
				long long H = 2LL;
				_expected = 3LL;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}
			case 1:
			{
				long long E = 100LL;
				long long EM = 100LL;
				long long M = 100LL;
				long long MH = 0LL;
				long long H = 0LL;
				_expected = 0LL;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}
			case 2:
			{
				long long E = 657LL;
				long long EM = 657LL;
				long long M = 657LL;
				long long MH = 657LL;
				long long H = 657LL;
				_expected = 1095LL;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}
			case 3:
			{
				long long E = 1LL;
				long long EM = 2LL;
				long long M = 3LL;
				long long MH = 4LL;
				long long H = 5LL;
				_expected = 3LL;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}
			case 4:
			{
				long long E = 1000000000000000000LL;
				long long EM = 1000000000000000000LL;
				long long M = 1000000000000000000LL;
				long long MH = 1000000000000000000LL;
				long long H = 1000000000000000000LL;
				_expected = 1666666666666666666LL;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}
			/*case 5:
			{
				long long E = LL;
				long long EM = LL;
				long long M = LL;
				long long MH = LL;
				long long H = LL;
				_expected = LL;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}*/
			/*case 6:
			{
				long long E = LL;
				long long EM = LL;
				long long M = LL;
				long long MH = LL;
				long long H = LL;
				_expected = LL;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
			}*/
			/*case 7:
			{
				long long E = LL;
				long long EM = LL;
				long long M = LL;
				long long MH = LL;
				long long H = LL;
				_expected = LL;
				_received = _obj.maxSets(E, EM, M, MH, H); break;
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
