#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<61ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll n=17;
ll dn[n];
ll f[2][2][n][n][n];
class FavouriteDigits {
	public:
	long long findNext(long long LOWER, int digit1, int count1, int digit2, int count2) {
		LOWER--;
		for (ll i=n-2;i>=0;i--) {
			dn[i]=LOWER%10;
			LOWER/=10;
		}
		for (ll s=0;s<2;s++) for (ll t=0;t<2;t++) for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) for (ll z=0;z<n;z++) f[s][t][x][y][z]=INF;
		f[0][0][0][0][0]=0;
		for (ll x=0;x<n-1;x++) {
			for (ll s=0;s<2;s++) for (ll t=0;t<2;t++) {
				for (ll y=0;y<n;y++) for (ll z=0;z<n;z++) {
					ll val=f[s][t][x][y][z];
					if (val>=INF) continue;
					for (ll d=0;d<10;d++) {
						if (t==0&&d<dn[x]) continue;
						ll ns=(d!=0)?1:s;
						ll nt=(d>dn[x])?1:t;
						ll nx=x+1;
						ll ny=(d==digit1&&(d>0||s==1))?y+1:y;
						ll nz=(d==digit2&&(d>0||s==1))?z+1:z;
						ll nv=val*10+d;
						chkmin(f[ns][nt][nx][ny][nz],val*10+d);
					}
				}
			}
		}
		ll ans=INF;
		for (ll y=count1;y<n;y++) for (ll z=count2;z<n;z++) {
			chkmin(ans,f[1][1][n-1][y][z]);
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
		cout << "Testing FavouriteDigits (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470717787;
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
		FavouriteDigits _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long N = 47LL;
				int digit1 = 1;
				int count1 = 0;
				int digit2 = 2;
				int count2 = 0;
				_expected = 47LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			case 1:
			{
				long long N = 47LL;
				int digit1 = 5;
				int count1 = 0;
				int digit2 = 9;
				int count2 = 1;
				_expected = 49LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			case 2:
			{
				long long N = 47LL;
				int digit1 = 5;
				int count1 = 0;
				int digit2 = 3;
				int count2 = 1;
				_expected = 53LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			case 3:
			{
				long long N = 47LL;
				int digit1 = 2;
				int count1 = 1;
				int digit2 = 0;
				int count2 = 2;
				_expected = 200LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			case 4:
			{
				long long N = 123456789012345LL;
				int digit1 = 1;
				int count1 = 2;
				int digit2 = 2;
				int count2 = 4;
				_expected = 123456789012422LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			case 5:
			{
				long long N = 92LL;
				int digit1 = 1;
				int count1 = 1;
				int digit2 = 0;
				int count2 = 0;
				_expected = 100LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}
			/*case 6:
			{
				long long N = LL;
				int digit1 = ;
				int count1 = ;
				int digit2 = ;
				int count2 = ;
				_expected = LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}*/
			/*case 7:
			{
				long long N = LL;
				int digit1 = ;
				int count1 = ;
				int digit2 = ;
				int count2 = ;
				_expected = LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
			}*/
			/*case 8:
			{
				long long N = LL;
				int digit1 = ;
				int count1 = ;
				int digit2 = ;
				int count2 = ;
				_expected = LL;
				_received = _obj.findNext(N, digit1, count1, digit2, count2); break;
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
