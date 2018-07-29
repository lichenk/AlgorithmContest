#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=2004;
ld f[MAXN][MAXN];
ll n;
pair<ll,ll> oz[MAXN];
class DoraemonPuzzleGame {
	public:
	double solve(vector <int> _zero, vector <int> _one, int m) {
		ll n=_zero.size();
		for (ll i=0;i<n;i++) {
			// Sort by _one
			oz[i] = MP(_one[i],_zero[i]);
		}
		sort(oz,oz+n, greater<pair<ll,ll> >());
		m-=n;
		ld ans = 0.0;
		for (ll i=0;i<MAXN;i++) {
			for (ll j=0;j<MAXN;j++) {
				f[i][j] = 0;
			}
		}
		f[n][m] = 1.0;
		for (ll x=n;x>=1;x--) {
			ld on = 0.001*(ld)oz[x-1].first; ld ze = 0.001*(ld)oz[x-1].second;
			ld probzero = ze/(ze+on);
			ld probone = on/(ze+on);
			ld tilclear = 1.0/(ze+on);
			ld tilone = 1.0/on;
			//printf("%f %f. %f %f %f %f\n",on,ze,probzero,probone,tilclear,tilone);
			/*for (ll k=0;k<=x;k++) {
				printf("%f ",f[x][k]);
			}
			printf("\n");*/
			for (ll k=0;k<x;k++) {
				// We must enforce k <= x
				ld currp = f[x][k];
				ll kminus1 = k>0?k-1:k;
				f[x-1][kminus1] += probone *currp;
				f[x-1][k] += probzero * currp;
				ans += currp*tilclear;
			}
			{
				ll k=x;
				ld currp = f[x][k];
				f[x-1][k-1] += currp;
				ans += currp*tilone;
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
		cout << "Testing DoraemonPuzzleGame (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457116242;
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
		DoraemonPuzzleGame _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int X[] = {800};
				int Y[] = {200};
				int m = 2;
				_expected = 5.0;
				_received = _obj.solve(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), m); break;
			}
			case 1:
			{
				int X[] = {1,999,999};
				int Y[] = {999,1,1};
				int m = 3;
				_expected = 3.0;
				_received = _obj.solve(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), m); break;
			}
			case 2:
			{
				int X[] = {500,500};
				int Y[] = {500,500};
				int m = 3;
				_expected = 2.5;
				_received = _obj.solve(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), m); break;
			}
			case 3:
			{
				int X[] = {250,250,250,250};
				int Y[] = {250,250,250,250};
				int m = 5;
				_expected = 8.25;
				_received = _obj.solve(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), m); break;
			}
			case 4:
			{
				int X[] = {250,500,250};
				int Y[] = {500,250,500};
				int m = 5;
				_expected = 4.962962962962963;
				_received = _obj.solve(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), m); break;
			}
			case 5:
			{
				int X[] = {600,900,800,500,900,200,400,100,800,300,900,300,800,700,800,600,800,900,400,100,100,700,600,100,500,
				          800,700,600,900,600,300,100,300,100,700,500,900,200,800,400,300,700,300,400,700,300,400,800,300,200};
				int Y[] = {400,100,200,500,100,800,600,900,200,700,100,700,200,300,200,400,200,100,600,900,900,300,400,900,500,
				          200,300,400,100,400,700,900,700,900,300,500,100,800,200,600,700,300,700,600,300,700,600,200,700,800};
				int m = 95;
				_expected = 119.33578280666175;
				_received = _obj.solve(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), m); break;
			}
			/*case 6:
			{
				int X[] = ;
				int Y[] = ;
				int m = ;
				_expected = ;
				_received = _obj.solve(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), m); break;
			}*/
			/*case 7:
			{
				int X[] = ;
				int Y[] = ;
				int m = ;
				_expected = ;
				_received = _obj.solve(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), m); break;
			}*/
			/*case 8:
			{
				int X[] = ;
				int Y[] = ;
				int m = ;
				_expected = ;
				_received = _obj.solve(vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int)), m); break;
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
