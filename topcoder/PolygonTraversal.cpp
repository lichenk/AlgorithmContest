#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
ll f[18][262144];
class PolygonTraversal {
	public:
	long long count(int N, vector <int> points) {
		ll m = points.size();
		for (ll i = 0; i < m; i++) {
			points[i] = points[i] - 1;
		}
		ll mask = 0;
		for (ll i = 0; i < m; i++) {
			mask |= (1LL << points[i]);
		}
		f[points[m-1]][mask] = 1;
		ll lim = (1LL<<N) - 1;
		for (ll z = 0; z < lim; z++) {
			ll b = z;
			for (ll x = 0; x < N; x++) {
				if ((b & (1LL<<x)) == 0) continue;
				ll first = -1; ll last = -1;
				for (ll y = (x+1)%N; y != x;) {
					if (b & (1LL<<y)) {first = y; break;}
					y = (y+1)%N;
				}
				for (ll y = x-1; y != x;) {
					while (y < 0) y += N;
					if (b & (1LL<<y)) {last = y; break;}
					y = (y-1)%N;
					while (y < 0) y += N;
				}
				if (first == -1 || last == -1 || first == last) continue;
				ll ways = f[x][b];
				//if (x == points[m-1] && b == mask) {
				//printf("%lld %lld %lld %lld %lld\n",x,b,ways,first,last);
				//}
				for (ll y = (first+1)%N; y != last;) {
					//if (x == points[m-1] && b == mask) {
					//	printf("Trying y:%lld b:%lld %lld %lld %lld %d\n",y,b,(1LL<<y),b&2,b & (1LL<<y),(b & (1LL<<y) == 0));
					//}
					if ((b & (1LL<<y)) == 0) {
						f[y][b|(1LL<<y)] += ways;
					}
					y = (y+1)%N;
				}
			}
		}
		ll ans = 0;
		{
			ll b = lim;
			ll t = points[0];
			for (ll x = 0; x < N; x++) {
				if ((b & (1LL<<x)) == 0) continue;
				ll first = -1; ll last = -1;
				for (ll y = (x+1)%N; y != x;) {
					if (b & (1LL<<y)) {first = y; break;}
					y = (y+1)%N;
				}
				for (ll y = x-1; y != x;) {
					while (y < 0) y += N;
					if (b & (1LL<<y)) {last = y; break;}
					y = (y-1)%N;
					while (y < 0) y += N;
				}
				if (first == -1 || last == -1 || first == last) continue;
				ll ways = f[x][b];
				//printf("%lld %lld %lld\n",x,b,ways);
				for (ll y = (first+1)%N; y != last;) {
					if (y == t) {
						//printf("Final: %lld %lld %lld\n",x,b,ways);
						ans += ways;
					}
					y = (y+1)%N;
				}
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
		cout << "Testing PolygonTraversal (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449733527;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PolygonTraversal _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int points[] = {1, 3, 5};
				_expected = 1LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 6;
				int points[] = {1, 4, 2};
				_expected = 1LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 7;
				int points[] = {2, 4, 7};
				_expected = 2LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 7;
				int points[] = {1, 2, 3, 4, 6, 5};
				_expected = 0LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 18;
				int points[] = {1, 7, 18};
				_expected = 4374612736LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int points[] = ;
				_expected = LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int points[] = ;
				_expected = LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int points[] = ;
				_expected = LL;
				_received = _obj.count(N, vector <int>(points, points+sizeof(points)/sizeof(int))); break;
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
