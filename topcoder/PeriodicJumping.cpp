#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
ll a[300],b[300];
class PeriodicJumping {
	public:
	int minimalTime(int need, vector <int> jumpLengths) {
		need=abs(need);
		ll clen=jumpLengths.size();
		ll csum=0;
		for (ll i=0;i<clen;i++) {
			csum+=jumpLengths[i];
		}
		a[0]=0;
		for (ll i=0;i<2*clen;i++) {
			a[i+1]=a[i]+jumpLengths[i%clen];
		}
		for (ll i=0;i<2*clen;i++) {
			b[i]=jumpLengths[i%clen];
		}
		for (ll imid=0;imid<2*clen;imid++) {
			bool ok = false;
			ll reach=a[imid];
			if (reach >= need) {
				ll hi=0;
				for (ll i=0;i<imid;i++) {
					hi=max(hi,b[i]);
				}
				ll other=reach-hi;
				ll lo=hi-other;
				//printf("imid:%lld lo:%lld reach:%lld\n",imid,lo,reach);
				if (lo<=need&&need<=reach) ok=true;
			}
			if(ok) return imid;
		}
		{
			ll imin=2*clen; ll imax=(ll)1e10 + 1;
			while (imin<imax) {
				ll imid=imin+(imax-imin)/2;
				ll cycles = imid/clen;
				ll left = imid%clen;
				ll reach = cycles*csum+a[left];
				if (reach<0) reach = need+1;
				if (reach<need) {
					imin=imid+1;
				}
				else {
					imax=imid;
				}
			}
			return imin;
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
		cout << "Testing PeriodicJumping (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455178406;
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
		PeriodicJumping _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 15;
				int jumpLengths[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = 5;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 1:
			{
				int x = 5;
				int jumpLengths[] = {5};
				_expected = 1;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 2:
			{
				int x = 1;
				int jumpLengths[] = {10};
				_expected = 2;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 3:
			{
				int x = -10;
				int jumpLengths[] = {2,3,4,500,6,7,8};
				_expected = 11;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 4:
			{
				int x = -1000000000;
				int jumpLengths[] = {1};
				_expected = 1000000000;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			case 5:
			{
				int x = 0;
				int jumpLengths[] = {19911120};
				_expected = 0;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x = ;
				int jumpLengths[] = ;
				_expected = ;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x = ;
				int jumpLengths[] = ;
				_expected = ;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x = ;
				int jumpLengths[] = ;
				_expected = ;
				_received = _obj.minimalTime(x, vector <int>(jumpLengths, jumpLengths+sizeof(jumpLengths)/sizeof(int))); break;
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
