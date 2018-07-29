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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=1004;
double f[MAXN][MAXN];
class Queueing {
	public:
	double probFirst(int alim, int blim, int _p, int _q) {
		double p=1.0/_p, q=1.0/_q;
		double den=1-(1-p)*(1-q);
		double hh=p*q/den;
		double ht=p*(1-q)/den;
		double th=q*(1-p)/den;
		for (ll a=0;a<MAXN;a++) for (ll b=0;b<MAXN;b++) f[a][b]=0;
		f[0][0] = 1;
		for (ll s=0;s<=alim+blim-1;s++) {
			for (ll a=0;a<alim;a++) {
				ll b=s-a;
				if (!(0<=b&&b<blim)) continue;
				double v=f[a][b];
				f[a+1][b+1]+=v*hh;
				f[a+1][b]+=v*ht;
				f[a][b+1]+=v*th;
				f[a][b]=0;
			}
		}
		{
			double num=0;
			for (ll b=0;b<blim;b++) {
				num+=f[alim][b];
			}
			return num;
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
		cout << "Testing Queueing (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460148243;
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
		Queueing _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int len1 = 1;
				int len2 = 2;
				int p1 = 2;
				int p2 = 1;
				_expected = 0.5;
				_received = _obj.probFirst(len1, len2, p1, p2); break;
			}
			case 1:
			{
				int len1 = 1;
				int len2 = 3;
				int p1 = 3;
				int p2 = 7;
				_expected = 0.9835390946502058;
				_received = _obj.probFirst(len1, len2, p1, p2); break;
			}
			case 2:
			{
				int len1 = 3;
				int len2 = 1;
				int p1 = 7;
				int p2 = 3;
				_expected = 0.010973936899862834;
				_received = _obj.probFirst(len1, len2, p1, p2); break;
			}
			case 3:
			{
				int len1 = 12;
				int len2 = 34;
				int p1 = 56;
				int p2 = 78;
				_expected = 0.999996203228025;
				_received = _obj.probFirst(len1, len2, p1, p2); break;
			}
			case 4:
			{
				int len1 = 3;
				int len2 = 6;
				int p1 = 8;
				int p2 = 4;
				_expected = 0.5229465300297028;
				_received = _obj.probFirst(len1, len2, p1, p2); break;
			}
			/*case 5:
			{
				int len1 = ;
				int len2 = ;
				int p1 = ;
				int p2 = ;
				_expected = ;
				_received = _obj.probFirst(len1, len2, p1, p2); break;
			}*/
			/*case 6:
			{
				int len1 = ;
				int len2 = ;
				int p1 = ;
				int p2 = ;
				_expected = ;
				_received = _obj.probFirst(len1, len2, p1, p2); break;
			}*/
			/*case 7:
			{
				int len1 = ;
				int len2 = ;
				int p1 = ;
				int p2 = ;
				_expected = ;
				_received = _obj.probFirst(len1, len2, p1, p2); break;
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
