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
ll g[10][10];
ll pten[20];
class ReplacingDigit {
	public:
	int getMaximumStockWorth(vector <int> A, vector <int> _D) {
		ll D[100];
		D[0]=0;
		for (ll x=1;x<=9;x++) {
			D[x]=_D[x-1];
		}
		pten[0]=1;
		for (ll x=1;x<20;x++) {
			pten[x]=10*pten[x-1];
		}
		for (ll x=0;x<10;x++) {
			for (ll y=0;y<10;y++) {
				g[x][y]=0;
			}
		}
		ll ans=0;
		for (auto w:A) {
			ans+=w;
			ll x=w;
			vector<ll> v;
			while(w>0) {
				ll d=w%10;
				v.PB(d);
				w/=10;
			}
			ll len=v.size();
			for (ll i=0;i<len;i++) {
				g[i][v[i]]++;
			}
		}
		ll idx=9;
		for (ll p=9;p>=0;p--) {
			for (ll d=0;d<=9;d++) {
				while(g[p][d]>0) {
					while(idx>=0&&D[idx]==0) {
						idx--;
					}
					if (idx<=d) break;
					ans+=(pten[p]*(idx-d));
					D[idx]--;
					g[p][d]--;
				}
				if (idx<=d) break;
			}
			if (idx==-1) break;
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
		cout << "Testing ReplacingDigit (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1461734089;
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
		ReplacingDigit _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {100, 90};
				int D[] = {0, 0, 0, 0, 2, 1, 0, 0, 0};
				_expected = 745;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {9};
				int D[] = {1, 1, 1, 1, 1, 1, 1, 1, 0};
				_expected = 9;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {123456};
				int D[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
				_expected = 988777;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {10, 970019, 1976, 10936, 68750, 756309, 37600, 559601, 6750, 76091, 640, 312, 312, 90, 8870};
				int D[] = {11, 2, 8, 10, 7, 6, 3, 1, 3};
				_expected = 3297500;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int D[] = {111, 111, 111, 111, 111, 111, 111, 111, 111};
				_expected = 198;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			/*case 5:
			{
				int A[] = ;
				int D[] = ;
				_expected = ;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				int D[] = ;
				_expected = ;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				int D[] = ;
				_expected = ;
				_received = _obj.getMaximumStockWorth(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
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
