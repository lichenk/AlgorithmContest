#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=52;
const ll my=1e5+4;
ld f[2][my];
ll glen;
ld gwalk;
ld gwalkinv;
vector<ld> gwidth,gspeed;
ll n;
ll lwidth2;
ld lspeed;
inline ld compute(ll x, ll y, ll z) {
  return sqrt(lwidth2+(z-y)*(z-y))/lspeed+f[x&1][z];
}
vector<pair<ll,ll> > v;
const ld INF=1e18;
class EllysRivers {
	public:
	double getMin(int length, int _walk, vector <int> _width, vector <int> _speed) {
		glen=length;
		gwalk=_walk;
		gwalkinv=1.0L/_walk;
		n=_width.size();
		for (ll x=0;x<n;x++) {
			ll width=_width[x],speed=_speed[x];
			v.PB(MP(width,speed));
		}
		for (ll x=0;x<n;x++) {
			gwidth.PB(v[x].first);
			gspeed.PB(v[x].second);
		}
		for (ll y=0;y<=length;y++) f[0][y]=y/gwalk;
		f[0][length+1]=INF;
		for (ll x=0;x<n;x++) {
			ll cur=x&1; ll nxt=cur^1;
			f[nxt][length+1]=INF;
			lwidth2=gwidth[x]*gwidth[x];
			lspeed=gspeed[x];
			for (ll y=0;y<=length;y++) {
				ll imin=0,imax=y+1;
				ld best=(y>0)?f[nxt][y-1]+gwalkinv:INF;
				ll iterations=18;
				while(imin<imax&&--iterations) {
					ll imid=(imin+imax)/2;
					ld fi0=compute(x,y,imid);
					ld fi1=compute(x,y,imid+1);
					//printf("x:%d y:%d imid:%d. fi0:%f fi1:%f\n",x,y,imid,fi0,fi1);
					if (fi0>fi1) {
						best=min(best,fi1);
						imin=imid+1;
					}
					else {
						best=min(best,fi0);
						imax=imid;
					}
				}
				f[nxt][y]=best;
			}
		}
		return f[n&1][length];
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
		cout << "Testing EllysRivers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471225891;
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
		EllysRivers _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length = 10;
				int walk = 3;
				int width[] = {5, 2, 3};
				int speed[] = {5, 2, 7};
				_expected = 3.231651964071508;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 1:
			{
				int length = 10000;
				int walk = 211;
				int width[] = {911};
				int speed[] = {207};
				_expected = 48.24623664712219;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 2:
			{
				int length = 1337;
				int walk = 2;
				int width[] = {100, 200, 300, 400};
				int speed[] = {11, 12, 13, 14};
				_expected = 128.57830549575695;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 3:
			{
				int length = 77;
				int walk = 119;
				int width[] = {11, 12, 13, 14};
				int speed[] = {100, 200, 300, 400};
				_expected = 0.3842077071089629;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 4:
			{
				int length = 7134;
				int walk = 1525;
				int width[] = {11567, 19763, 11026, 10444, 24588, 22263, 17709, 11181, 15292, 28895, 15039, 18744, 19985, 13795, 26697, 18812, 25655, 13620, 28926, 12393};
				int speed[] = {1620, 1477, 2837, 2590, 1692, 2270, 1655, 1078, 2683, 1475, 1383, 1153, 1862, 1770, 1671, 2318, 2197, 1768, 1979, 1057};
				_expected = 214.6509731258811;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 5:
			{
				int length = 42;
				int walk = 337;
				int width[] = {1, 1, 1};
				int speed[] = {1, 1, 1};
				_expected = 3.1246290801186944;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 6:
			{
				int length = 100000;
				int walk = 1;
				int width[] = {1000000, 1000000, 1000000};
				int speed[] = {1, 1, 1000000};
				_expected = 2000001.004987562;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 7:
			{
				int length = 1;
				int walk = 1;
				int width[] = {1, 1, 1};
				int speed[] = {1, 1000000, 1};
				_expected = 2.0000014142135623;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 8:
			{
				int length = 100000;
				int walk = 1000000;
				int width[] = {1000, 6000, 11000, 16000, 21000, 26000, 31000, 36000, 41000, 46000, 51000, 56000, 61000, 66000, 71000, 76000, 81000, 86000, 91000, 96000, 101000, 106000, 111000, 116000, 121000, 126000, 131000, 136000, 141000, 146000, 151000, 156000, 161000, 166000, 171000, 176000, 181000, 186000, 191000, 196000, 201000, 206000, 211000, 216000, 221000, 226000, 231000, 236000, 241000, 246000};
				int speed[] = {10, 1010, 2010, 3010, 4010, 5010, 6010, 7010, 8010, 9010, 10010, 11010, 12010, 13010, 14010, 15010, 16010, 17010, 18010, 19010, 20010, 21010, 22010, 23010, 24010, 25010, 26010, 27010, 28010, 29010, 30010, 31010, 32010, 33010, 34010, 35010, 36010, 37010, 38010, 39010, 40010, 41010, 42010, 43010, 44010, 45010, 46010, 47010, 48010, 49010};
				_expected = 349.2645017757457;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}
			case 9:
			{
				int length = 93664;
				int walk = 945766;
				int width[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int speed[] = {1495, 999977, 999987, 999131, 2, 578, 974063, 999992, 61, 462198, 2093, 987141, 999989, 994346, 942737, 2735, 11618, 999831, 999957, 995595, 999992, 999976, 8505, 2, 169, 999904, 993266, 1, 998098, 999992, 6221, 999799, 999987, 109523, 727765, 151, 1, 994031, 73570, 105921, 275968, 15, 999962, 999080};
				_expected = 3.1929115458550874;
				_received = _obj.getMin(length, walk, vector <int>(width, width+sizeof(width)/sizeof(int)), vector <int>(speed, speed+sizeof(speed)/sizeof(int))); break;
			}

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
