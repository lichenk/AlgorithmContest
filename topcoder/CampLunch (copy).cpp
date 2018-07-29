#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL

class CampLunch {
	public:
	int count(int N, int M, vector <string> a) {
ll lim = 1<<M;
f[0][0][0] = 0;
for (ll x = 0; x < N; x++) {
	for (ll y = 0; y < M; y++) {
		for (ll z = 0; z < lim; z++) {
			char p = a[x][y];
			ll np = a[x].find(string(1,p));
			ll pmask = 1ULL<<np;
			ll cmask = 1ULL<<y;
			ll c = f[x][y][z];
			if (z & cmask) {
				// This is like putting 1
				ll nz = z & ~pmask;
				f[nx][ny][nz] += c;
			}
			else {
				{
					ll ny = y+1;
					ll nx = x;
					if (ny == M) {
						ny = 0; nx = x+1;
					}
					// Put 1
					ll nz = z & (~pmask);
					f[nx][ny][nz] += c;
					f[nx][ny][nz] %= MOD;
					// Put 2 vertical block
					ll nz = z | pmask;
					f[nx][ny][nz] += c;
					f[nx][ny][nz] %= MOD;
				}
				// Put 2 horizontal block
				ll nmask = 1ULL<<(y+1);
				if (y <= M-2 && !(z & nmask)) {
					ll nx = x;
					ll ny = y+2;
					if (ny == M) {
						ny = 0; nx = x+1;
					}
					char p2 = a[x][y+1];
					ll np2 = a[x].find(string(1,p2));
					ll pmask2 = 1ULL<<np2;
					ll nz = z & (~pmask) & (~pmask2);
					f[nx][ny][nz] += c;
					f[nx][ny][nz] %= MOD;
				}
			}
		}
	}
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
