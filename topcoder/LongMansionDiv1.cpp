#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const int mn=1004;
ll vdist[mn];
ll vedist[mn];

class LongMansionDiv1 {
	public:
	long long minimalTime(vector <int> t, int sX, int sY, int eX, int eY) {
		int n=t.size();
		{
			ll sum=0;
			for (int r=sX;r<n;r++) {
				sum+=t[r];
				vdist[r]=sum;
			}
		}
		{
			ll sum=0;
			for (int r=sX;r>=0;r--) {
				sum+=t[r];
				vdist[r]=sum;
			}
		}
		{
			ll sum=0;
			for (int r=eX;r<n;r++) {
				sum+=t[r];
				vedist[r]=sum;
			}
		}
		{
			ll sum=0;
			for (int r=eX;r>=0;r--) {
				sum+=t[r];
				vedist[r]=sum;
			}
		}
		int dy=abs((ll)eY-(ll)sY)-1;
		ll final=0;
		for (int r=0;r<n;r++) {
			ll initd=vdist[r];
			ll endd=vedist[r];
			ll inter=(ll)dy*t[r];
			ll cand=initd+endd+inter;
			if (r==0) final=cand;
			else chkmin(final,cand);
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
		cout << "Testing LongMansionDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1502758803;
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
		LongMansionDiv1 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int t[] = {5, 3, 10};
				int sX = 2;
				int sY = 0;
				int eX = 2;
				int eY = 2;
				_expected = 29LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
			}
			case 1:
			{
				int t[] = {5, 3, 10};
				int sX = 0;
				int sY = 2;
				int eX = 0;
				int eY = 0;
				_expected = 15LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
			}
			case 2:
			{
				int t[] = {137, 200, 184, 243, 252, 113, 162};
				int sX = 0;
				int sY = 2;
				int eX = 4;
				int eY = 2;
				_expected = 1016LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
			}
			case 3:
			{
				int t[] = {995, 996, 1000, 997, 999, 1000, 997, 996, 1000, 996, 1000, 997, 999, 996, 1000, 998, 999, 995, 995, 998, 995, 998, 995, 997, 998, 996, 998, 996, 997, 1000, 998, 997, 995, 1000, 996, 997, 1000, 997, 997, 999, 998, 995, 999, 999, 1000, 1000, 998, 997, 995, 999};
				int sX = 18;
				int sY = 433156521;
				int eX = 28;
				int eY = 138238863;
				_expected = 293443080673LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
			}
			case 4:
			{
				int t[] = {1};
				int sX = 0;
				int sY = 0;
				int eX = 0;
				int eY = 0;
				_expected = 1LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
			}
			case 5:
			{
				int t[] = {1};
				int sX = 0;
				int sY = 0;
				int eX = 0;
				int eY = 100;
				_expected = 101LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
			}
			case 6:
			{
				int t[] = {1,2};
				int sX = 0;
				int sY = 0;
				int eX = 0;
				int eY = 0;
				_expected = 1LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
			}
			case 7:
			{
				int t[] = {1,2};
				int sX = 0;
				int sY = 0;
				int eX = 1;
				int eY = 0;
				_expected = 3LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
			}
			case 8:
			{
				int t[] = {2,1};
				int sX = 0;
				int sY = 0;
				int eX = 0;
				int eY = 0;
				_expected = 2LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
			}
			case 9:
			{
				int t[] = {2,1};
				int sX = 0;
				int sY = 0;
				int eX = 0;
				int eY = 1;
				_expected = 4LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
			}
			case 10:
			{
				int t[] = {20,1};
				int sX = 0;
				int sY = 0;
				int eX = 0;
				int eY = 2;
				_expected = 43LL;
				_received = _obj.minimalTime(vector <int>(t, t+sizeof(t)/sizeof(int)), sX, sY, eX, eY); break;
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
