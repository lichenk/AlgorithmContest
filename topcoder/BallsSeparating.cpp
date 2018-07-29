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
class BallsSeparating {
	public:
	int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
		ll n=red.size();
		if(n<3) return -1;
		ll final=INF;
		for (ll r=0;r<n;r++)
			for (ll g=0;g<n;g++)
				for (ll b=0;b<n;b++) {
					if (r==g||r==b||g==b) continue;
					ll ans=0;
					for (ll x=0;x<n;x++) {
						ll sum=red[x]+green[x]+blue[x];
						if (x==r) sum-=red[x];
						else if (x==g) sum-=green[x];
						else if (x==b) sum-=blue[x];
						else {
							vector<ll> t; t.PB(red[x]);t.PB(green[x]);t.PB(blue[x]);
							sort(t.begin(),t.end());
							sum-=t[2];
						}
						ans+=sum;
					}
					final=min(final,ans);
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
		cout << "Testing BallsSeparating (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459136132;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BallsSeparating _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int red[] = {1, 1, 1};
				int green[] = {1, 1, 1};
				int blue[] = {1, 1, 1};
				_expected = 6;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 1:
			{
				int red[] = {5};
				int green[] = {6};
				int blue[] = {8};
				_expected = -1;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 2:
			{
				int red[] = {4, 6, 5, 7};
				int green[] = {7, 4, 6, 3};
				int blue[] = {6, 5, 3, 8};
				_expected = 37;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 3:
			{
				int red[] = {7, 12, 9, 9, 7};
				int green[] = {7, 10, 8, 8, 9};
				int blue[] = {8, 9, 5, 6, 13};
				_expected = 77;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 4:
			{
				int red[] = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799};
				int green[] = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141};
				int blue[] = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103};
				_expected = 7230607;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			/*case 5:
			{
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int red[] = ;
				int green[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.minOperations(vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(green, green+sizeof(green)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
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
