#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
ll f[17][16][1LL<<16];
class CampLunch {
	public:
	int count(int N, int M, vector <string> a) {
ll lim = 1<<M;
for (ll x = 0; x <= N; x++) {
	for (ll y = 0; y < M; y++) {
		for (ll z = 0; z < lim; z++) {
			f[x][y][z] = 0;
		}
	}
}
f[0][0][0] = 1;
for (ll x = 0; x < N; x++) {
	for (ll y = 0; y < M; y++) {
		for (ll z = 0; z < lim; z++) {
			ll current = a[x][y] - 'A';
			ll cmask = 1ULL << current;
			ll add = f[x][y][z];
			ll ny = (y+1)%M; ll nx = x;
			if (ny == 0) {nx++;}
			if (z&cmask) {
				// Step right
				ll nz = z & ~cmask;
				f[nx][ny][nz] = (f[nx][ny][nz] + add)%MOD;
			}
			else {
				{// Add 1
				ll nz = z & ~cmask;
				f[nx][ny][nz] = (f[nx][ny][nz] + add)%MOD;
				}
				{// Add 2 down
				ll nz = z | cmask;
				f[nx][ny][nz] = (f[nx][ny][nz] + add)%MOD;
				}
				// Add 2 horizontal
				if (y+1 < M) {
					ll right = a[x][y+1] - 'A';
					ll rmask = 1ULL << right;
					if (z & rmask) continue;
					ny = (y+2)%M; nx = x;
					if (ny == 0) {nx++;}
					ll nz = z & ~cmask & ~rmask;
					f[nx][ny][nz] = (f[nx][ny][nz] + add)%MOD;
				}
			}
		}
	}
}
return f[N][0][0];
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
		cout << "Testing CampLunch (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450940321;
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
		CampLunch _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int M = 2;
				string a[] = {"AB","AB"};
				_expected = 7;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 2;
				int M = 3;
				string a[] = {"ABC","ABC"};
				_expected = 22;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 2;
				int M = 3;
				string a[] = {"ABC","BAC"};
				_expected = 21;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 1;
				int M = 1;
				string a[] = {"A"};
				_expected = 1;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 4:
			{
				int N = 1;
				int M = 10;
				string a[] = {"ABDEFHIGJC"};
				_expected = 89;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 5:
			{
				int N = 16;
				int M = 16;
				string a[] = {"ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP"};
				_expected = 950052677;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			/*case 6:
			{
				int N = ;
				int M = ;
				string a[] = ;
				_expected = ;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				string a[] = ;
				_expected = ;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int M = ;
				string a[] = ;
				_expected = ;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
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
