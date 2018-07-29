#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define ilim 138
#define jlim 404
#define INF 9999999999LL
#define PINF MP(INF,INF)
//#define INF 999LL
pair<ll,ll> f[21][ilim][jlim];
inline bool fail(ll k, ll a, ll b, ll c) {
	//printf("IN: %lld: %lld %lld %lld. ",k,a,b,c);
	ll cm = max(0LL, c-k);
	b += cm;
	ll bm = max(0LL, b-k);
	a += bm;
	//printf("OUT: %lld %lld %lld.\n",a,b,c-cm);
	return (a > k);
}
class Mutalisk {
	public:
	int minimalAttacks(vector <int> x) {
		ll n = x.size();
		ll total = 0;
		for (ll t = 0; t < n; t++) {
			total += x[t];
		}
		for (ll t = 0; t <= n; t++) {
			for (ll i = 0; i < ilim; i++) {
				for (ll j = 0; j < jlim; j++) {	
						f[t][i][j] = PINF;
				}
			}		
		}
		f[0][0][0] = MP(0LL,0LL);
		ll s = 0;
		for (ll t = 1; t <= n; t++) {
			//ll ninelim = ilim - 1;
			ll ninelim = 1 + (x[t-1]/9);
			s += x[t-1];
			//ll ilim2 = ilim; ll jlim2 = jlim;
			ll ilim2 = 2 + s/9; ll jlim2 = 2 + s/3;
			for (ll nine = 0; nine <= ninelim; nine++) {
				//ll threelim = jlim-1;
				ll threelim = 1 + ((x[t-1] - 9*nine)/3);
				for (ll three = 0; three <= threelim; three++) {
					ll one = max(x[t-1] - 3*three - 9*nine,0LL);
					ll sum = nine+three+one;
					for (ll i = nine; i < ilim2; i++) {
						for (ll j = three; j < jlim2; j++) {
								pair<ll,ll> prev = f[t-1][i-nine][j-three];
								if (prev == PINF) continue;
								f[t][i][j] = min(f[t][i][j],
									MP(prev.first + one, max(prev.second, sum))
									);
						}
					}
				}
			}
		}
		//for (ll t = 1; t <= n; t++) {
		//	for (ll i = 0; i <= 7; i++) {
		//		printf("t: %lld, i: %02lld. ",t,i);
		//		for (ll j = 0; j <= 7; j++) {
		//			printf("%03lld ", f[t][i][j]);
		//		}
		//		printf("\n");
		//	}
		//	printf("\n");
		//}
		ll best = INF;
		for (ll i = 0; i < ilim; i++) {
			for (ll j = 0; j < jlim; j++) {
					ll one = f[n][i][j].first;
					if (one >= INF) continue;
					ll imin = max(i, f[n][i][j].second);
					ll imax = 1201;
					while (imin < imax) {
						ll imid = (imin+imax)/2;
						if (fail(imid, i,j,one)) {
							imin = imid+1;
						}
						else {
							imax = imid;
						}
					}
					//assert(imin == imax);
					//if (imin == 5) {
					//	printf("DBG: %lld %lld %lld\n", i,j,one);
					//}
					best = min(best, imin);
			}
		}
		return best;
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
		cout << "Testing Mutalisk (650.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449368071;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 650.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Mutalisk _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {12,10,4};
				_expected = 2;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {54,18,6};
				_expected = 6;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1,1,1,1,1,1,1,1,1,1};
				_expected = 4;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {55,60,53};
				_expected = 13;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {60};
				_expected = 7;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60};
				_expected = 93;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				_expected = ;
				_received = _obj.minimalAttacks(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
