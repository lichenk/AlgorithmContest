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
vector<int> a;
ll p;
ll n;
const ll MAXN=1008;
ll f[MAXN];
ll solve(ll d) {
	for (ll x=0;x<=n;x++) f[x]=0;
	for (ll x=2;x<=n;x++) {
		chkmax(f[x],f[x-1]);
		if (a[x-1]-a[x-2]<=d) {
			chkmax(f[x],f[x-2]+1);
		}
		//printf("x:%lld f:%lld\n",x,f[x]);
	}
	return f[n]>=p;
}
class EllysSocks {
	public:
	int getDifference(vector <int> S, int P) {
		sort(S.begin(),S.end());
		n=S.size();
		a=S;
		p=P;
		ll imin=0,imax=1+(ll)1e10;
		while(imin<imax) {
			ll imid=imin+(imax-imin)/2;
			if (!solve(imid)) {
				imin=imid+1;
			}
			else {
				imax=imid;
			}
		}
		return imin;
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
		cout << "Testing EllysSocks (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459008428;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		EllysSocks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int S[] = {42, 37, 84, 36, 41, 42};
				int P = 2;
				_expected = 1;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 1:
			{
				int S[] = {42, 37, 84, 36, 41, 42};
				int P = 3;
				_expected = 42;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 2:
			{
				int S[] = {5, 2, 8, 8, 6, 7, 3, 7, 4, 2, 4, 5, 3, 6};
				int P = 7;
				_expected = 0;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 3:
			{
				int S[] = {17, 3, 13, 3, 2, 17, 11, 5, 5, 7, 11, 7, 13, 19};
				int P = 7;
				_expected = 4;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 4:
			{
				int S[] = {795755685, 581869303, 404620563, 708632712, 545404205, 133711906, 372047868, 949333986, 579004999, 323567404,
				           418932836, 944672732, 196140741, 809094427, 946129058, 30574577, 182506778, 15198493, 150802600, 138749191,
				           676943010, 177512688, 126303054, 81133258, 183966551, 471852627, 84672537, 867128744, 857788837, 275731772,
				           609397213, 20544910, 811450930, 483031419, 361913171, 547204602, 892462744, 522136404, 173978710, 131752569,
				           478582453, 867889991, 153380496, 551745921, 647984700, 910208077, 283496852, 368550363, 379821990, 712568903,
				           40498239, 113911604, 103237637, 39073007, 684602223, 812852787, 479711181, 746745228, 735241235, 296707007,
				           262522458, 870676136, 136721027, 359573809, 189375153, 547914047, 198304613, 640439653, 417177802, 25475624,
				           758242872, 764919655, 310701088, 537655880, 361931892, 14685971, 213794688, 107063881, 147944789, 444803289,
				           884392679, 540721924, 638781100, 902841101, 7097711, 219972874, 879609715, 156513984, 802611721, 755486970,
				           103522060, 967048445, 913778155, 94092596, 519074050, 884870761, 248268555, 339840186, 53612697, 826647953};
				int P = 42;
				_expected = 12866316;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 5:
			{
				int S[] = {1,1000000000};
				int P = 1;
				_expected = 999999999;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 6:
			{
				int S[] = {1,1,1,1,1};
				int P = 2;
				_expected = 0;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 7:
			{
				int S[] = {1,1,1,1,1,3};
				int P = 3;
				_expected = 2;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
			case 8:
			{
				int S[] = {1,11,2,12};
				int P = 3;
				_expected = 2;
				_received = _obj.getDifference(vector <int>(S, S+sizeof(S)/sizeof(int)), P); break;
			}
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
