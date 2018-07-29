#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 5
#define MAXK 5004
#define MAXQ 59049
ll f[MAXK][9];
ll g[2][MAXQ];
ll h[32];
class Nine {
	public:
	int count(int N, vector <int> d) {
		ll k = d.size();
		for (ll x = 0; x <= k; x++) {
			for (ll d = 0; d < 10; d++) {
				f[x][d] = 0;
			}
		}
		f[0][0] = 1;
		for (ll x = 0; x < k; x++) {
			for (ll b = 0; b < 9; b++) {
				ll c = f[x][b];
				for (ll e = 0; e < 10; e++) {
					f[x+1][(b+e)%9] += c;
					f[x+1][(b+e)%9] %= MOD;
				}	
			}
		}
		/*for (ll x = 0; x <= k; x++) {
			for (ll b = 0; b < 9; b++) {
				printf("x:%lld b:%lld f:%lld\n",x,b,f[x][b]);
			}
		}*/
		for (ll z = 0; z < 32; z++) h[z] = 0;
		for (auto& z: d) {
			h[z]++;
		}
		ll qmax = 1;
		for (ll i = 0; i < N; i++) {
			qmax *= 9;
		}
		{
			ll c = 1;
			for (ll qq = 0; qq < qmax; qq++) {
				g[c][qq] = 0;
			}
			g[c][0] = 1;
		}

		ll a[5];
		ll lastc = -1;
		ll zlim = 1ULL<<N;
		for (ll z = 0; z < zlim; z++) {
			ll p = (z+1)%2;
			ll c = z%2;
			lastc = c;
			for (ll qq = 0; qq < qmax; qq++) {
				g[c][qq] = 0;
			}
			for (ll qq = 0; qq < qmax; qq++) {
				for (ll b = 0; b < 9; b++) {
					ll tmpq = qq;
					for (ll i = 0; i < N; i++) {
						a[i] = tmpq%9;
						tmpq /= 9;
					}
					for (ll i = 0; i < N; i++) {
						if ((1ULL<<i)&z) {
							a[i] = (a[i] + b)%9;
						}
					}
					//printf("\n");
					ll t = 0;
					for (ll i = N-1; i >= 0; i--) {
						t *= 9;
						t += a[i];
					}
					//assert(t<qmax);
					ll add = (g[p][qq] * f[h[z]][b])%MOD;
					//printf("z:%lld b:%lld q:%lld t:%lld g:%lld f:%lld \n",z,b,qq,t,g[p][qq], f[h[z]][b]);
					g[c][t] = (g[c][t] + add)%MOD;
				}
			}
		}
		return g[lastc][0];

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
		cout << "Testing Nine (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451760620;
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
		Nine _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int d[] = {1,2};
				_expected = 4;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 2;
				int d[] = {1,2,3};
				_expected = 16;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 1;
				int d[] = {0,0,1};
				_expected = 200;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 5;
				int d[] = {1,3,5,8,24,22,25,21,30,2,4,0,6,7,9,11,14,13,12,15,18,17,16,19,26,29,31,28,27,10,20,23};
				_expected = 450877328;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 5;
				int d[] = {31,31,31,31,31};
				_expected = 11112;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 1;
				int d[] = {1};
				_expected = 2;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int d[] = ;
				_expected = ;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int d[] = ;
				_expected = ;
				_received = _obj.count(N, vector <int>(d, d+sizeof(d)/sizeof(int))); break;
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
