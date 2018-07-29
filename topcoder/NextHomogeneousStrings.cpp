#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

int isPowerOfTwo (unsigned int x)
{
  return ((x != 0) && !(x & (x - 1)));
}

const int D=8;
vector<int> S;
int final=0;
void genr(int k, int now, int gend) {
	if (k==0) {
		int b=0;
		for (auto &w:S) b|=1<<w;
		if (isPowerOfTwo(b+1)) final++;
		return;
	}
	else {
		now*=gend;
		for (int x=0;x<gend;x++) {
			S.PB(x);
			genr(k-1,now+x,gend);
			S.pop_back();
		}
	}
}
void gen(int n, int clim) {
	assert(clim<=7);
	int gend=min(n,clim);
	genr(n, 0, gend);
}

class NextHomogeneousStrings {
	public:
	string getNext(int clim, int d, string seed, long long k) {
		for (int n=1;n<=8;n++) gen(n,min(n,7));
		printf("%d\n",final);
		return "";
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
		cout << "Testing NextHomogeneousStrings (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1523832887;
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
		NextHomogeneousStrings _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d = 1;
				int n = 2;
				string seed = "aaa";
				long long k = 3LL;
				_expected = "ddd";
				_received = _obj.getNext(d, n, seed, k); break;
			}
			case 1:
			{
				int d = 2;
				int n = 3;
				string seed = "abc";
				long long k = 0LL;
				_expected = "aca";
				_received = _obj.getNext(d, n, seed, k); break;
			}
			case 2:
			{
				int d = 2;
				int n = 4;
				string seed = "ttrrzz";
				long long k = 6LL;
				_expected = "ttsssc";
				_received = _obj.getNext(d, n, seed, k); break;
			}
			case 3:
			{
				int d = 6;
				int n = 8;
				string seed = "txyaaxaassaaaarghjsdohasdghususdidisisdodo";
				long long k = 10000000000000000LL;
				_expected = "txyaaxaassaaaarghjsgaaaaaaaaadntffiniqrddy";
				_received = _obj.getNext(d, n, seed, k); break;
			}
			case 4:
			{
				int d = 2;
				int n = 5;
				string seed = "zzzzzaa";
				long long k = 100LL;
				_expected = "";
				_received = _obj.getNext(d, n, seed, k); break;
			}
			/*case 5:
			{
				int d = ;
				int n = ;
				string seed = ;
				long long k = LL;
				_expected = ;
				_received = _obj.getNext(d, n, seed, k); break;
			}*/
			/*case 6:
			{
				int d = ;
				int n = ;
				string seed = ;
				long long k = LL;
				_expected = ;
				_received = _obj.getNext(d, n, seed, k); break;
			}*/
			/*case 7:
			{
				int d = ;
				int n = ;
				string seed = ;
				long long k = LL;
				_expected = ;
				_received = _obj.getNext(d, n, seed, k); break;
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
