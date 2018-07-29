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
class TheTournamentDivOne {
	public:
	int find(vector <int> points, int w, int d) {
		ll n=points.size();
		ll final=INF;
		{
			multiset<ll,greater<ll> > gpq;
			ll add=0;
			for (ll i=0;i<n;i++) {
				while ((points[i]%d) != 0 && points[i]>=0) {
					points[i]-=w;
					add++;
				}
				if (points[i]<0) {
					return -1;
				}
			}
			for (ll i=0;i<n;i++) {
				if (points[i]>0) gpq.insert(points[i]);
			}
			while(1) {
				if (gpq.empty()) {
					final=min(final,add);
					break;
				}
				ll top = *(gpq.begin());
				ll sum=0;
				for (auto &x: gpq) {
					sum+=x;
				}
				if (top <= sum-top && (sum%(2*d))==0) {
					final=min(final,add+(sum/(2*d)));
				}
				gpq.erase(gpq.begin());
				top-=w; add++;
				while((top%d)!=0) {
					top-=w;
					add++;
				}
				if (top<0) break;
				if (top>0) gpq.insert(top);
			}
		}
		if (final>=INF) return -1;
		else return final;
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
		cout << "Testing TheTournamentDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458705979;
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
		TheTournamentDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int points[] = {10, 1, 1};
				int w = 2;
				int d = 1;
				_expected = 6;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int)), w, d); break;
			}
			case 1:
			{
				int points[] = {1, 1, 1};
				int w = 2;
				int d = 1;
				_expected = -1;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int)), w, d); break;
			}
			case 2:
			{
				int points[] = {1, 4, 0, 2};
				int w = 3;
				int d = 1;
				_expected = 3;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int)), w, d); break;
			}
			case 3:
			{
				int points[] = {8, 3, 8, 5, 9, 2, 7, 11};
				int w = 3;
				int d = 2;
				_expected = 15;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int)), w, d); break;
			}
			case 4:
			{
				int points[] = {0,0};
				int w = 2;
				int d = 1;
				_expected = 0;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int)), w, d); break;
			}
			case 5:
			{
				int points[] = {2082, 2485, 3876, 2182, 5409, 9149, 7797, 1506, 6627, 3401, 4346, 4092, 4233, 504, 4962, 6430, 282, 1633, 1115, 9527, 772, 5444, 6275, 472, 4724, 2499, 3745, 5345, 5632, 3512, 8259, 9331, 7448, 3749, 2992, 8519, 4232, 7352, 8072, 2613, 5477, 1233, 6328, 7510, 6390, 1701, 5649, 7432};
				int w = 21;
				int d = 2;
				_expected = 10862;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int)), w, d); break;
			}
			case 6:
			{
				int points[] = {9414, 2858, 7625, 4627, 9866, 8885, 2034, 2164, 7906, 3978, 7147, 1260, 3291, 4567, 5070, 8425, 9514, 5127, 2587, 7107, 4214, 5021, 6547, 2680, 7832, 3715, 5192, 6815, 4510, 8352, 6455, 2341, 1228, 6588, 7326, 9993, 3471, 1475, 7136, 1566, 8579, 1168, 5652, 9025, 5599, 5883, 6424};
				int w = 51;
				int d = 16;
				_expected = 5274;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int)), w, d); break;
			}
			case 7:
			{
				int points[] = {5462, 7011, 5716, 7766};
				int w = 11;
				int d = 1;
				_expected = 2371;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int)), w, d); break;
			}
			case 8:
			{
				int points[] = {19, 22, 28};
				int w = 3;
				int d = 1;
				_expected = 25;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int)), w, d); break;
			}
			case 9:
			{
				int points[] = {1491, 6953};
				int w = 15;
				int d = 3;
				_expected = -1;
				_received = _obj.find(vector <int>(points, points+sizeof(points)/sizeof(int)), w, d); break;
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
