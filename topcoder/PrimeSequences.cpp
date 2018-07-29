#include "bits/stdc++.h"
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

const int mn=1e7+4;
const int MAXP=mn;
bitset<MAXP+1> sieve_array;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
      }
    }
  }
}

int f[mn];

class PrimeSequences {
	public:
	int getLargestGenerator(int N, int D) {
		sieve();
		for (int x=2;x<=N;x++) {
			if (sieve_array[x]) {
				chkmax(f[x],1);
				{
					int y=2*x+1;
					if (y<=N&&sieve_array[y]) {
						f[y]=f[x]+1;
					}
				}
			}
		}
		for (int x=N;x>=2;x--) {
			if (f[x]>=D) return x;
		}
		return -1;
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
		cout << "Testing PrimeSequences (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1520826524;
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
		PrimeSequences _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 10;
				int D = 2;
				_expected = 7;
				_received = _obj.getLargestGenerator(N, D); break;
			}
			case 1:
			{
				int N = 42;
				int D = 3;
				_expected = 23;
				_received = _obj.getLargestGenerator(N, D); break;
			}
			case 2:
			{
				int N = 666;
				int D = 7;
				_expected = -1;
				_received = _obj.getLargestGenerator(N, D); break;
			}
			case 3:
			{
				int N = 1337;
				int D = 5;
				_expected = 47;
				_received = _obj.getLargestGenerator(N, D); break;
			}
			case 4:
			{
				int N = 100000;
				int D = 5;
				_expected = 2879;
				_received = _obj.getLargestGenerator(N, D); break;
			}
			case 5:
			{
				int N = 40000;
				int D = 1;
				_expected = 39989;
				_received = _obj.getLargestGenerator(N, D); break;
			}
			case 6:
			{
				int N = 10000000;
				int D = 6;
				_expected = 4068479;
				_received = _obj.getLargestGenerator(N, D); break;
			}
			/*case 7:
			{
				int N = ;
				int D = ;
				_expected = ;
				_received = _obj.getLargestGenerator(N, D); break;
			}*/
			/*case 8:
			{
				int N = ;
				int D = ;
				_expected = ;
				_received = _obj.getLargestGenerator(N, D); break;
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
