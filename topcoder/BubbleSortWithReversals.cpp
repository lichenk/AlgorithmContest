#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<16ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN = 52;
ll f[MAXN][MAXN];
class BubbleSortWithReversals {
	public:
	int getMinSwaps(vector <int> a, ll k) {
		ll n=a.size();
		for (ll x=0;x<=n+1;x++) {
			for (ll t=0;t<=k+1;t++) {
				f[x][t]=INF;
			}
		}
		f[0][0]=0;
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<=x;y++) {
				ll cross=0;
				for (ll p=0;p<y;p++) {
					for (ll q=y;q<=x;q++) {
						if (a[p]>a[q])cross++;
					}
				}
				ll self=0,antiself=0;
				for (ll p=y;p<=x;p++) {
					for (ll q=p+1;q<=x;q++) {
						if (a[p]>a[q])self++;
						if (a[p]<a[q])antiself++;
					}
				}
				ll len=x-y+1;
				for (ll t=0;t<=k;t++) {
					chkmin(f[x+1][t],f[y][t]+cross+self);
					ll newt=(y==x)?t:t+1;
					chkmin(f[x+1][newt],f[y][t]+cross+antiself);
				}
			}
		}
		ll final=INF;
		for (ll t=0;t<=k;t++) {
			chkmin(final,f[n][t]);
		}
		return final;
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
		cout << "Testing BubbleSortWithReversals (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457230286;
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
		BubbleSortWithReversals _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {6,8,8,7,7};
				int K = 1;
				_expected = 0;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 1:
			{
				int A[] = {7,2,2,13,5,5,2};
				int K = 2;
				_expected = 3;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 2:
			{
				int A[] = {12,5,1,10,12,6,6,10,6,8};
				int K = 2;
				_expected = 12;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 3:
			{
				int A[] = {2,3,1};
				int K = 2;
				_expected = 1;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 4:
			{
				int A[] = {482,619,619,601,660,660,691,691,77,77,96,77};
				int K = 9;
				_expected = 22;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 5:
			{
				int A[] = {2,1};
				int K = 0;
				_expected = 1;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 6:
			{
				int A[] = {3,2,1};
				int K = 1;
				_expected = 0;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 7:
			{
				int A[] = {3,2,1};
				int K = 0;
				_expected = 3;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 8:
			{
				int A[] = {1,2};
				int K = 0;
				_expected = 0;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 9:
			{
				int A[] = {2,1};
				int K = 1;
				_expected = 0;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
			}
			case 10:
			{
				int A[] = {1,3,2,2};
				int K = 1;
				_expected = 0;
				_received = _obj.getMinSwaps(vector <int>(A, A+sizeof(A)/sizeof(int)), K); break;
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
