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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
pair<ll,ll> getfrac(ll dx, ll dy) {
	if (dx==0) return MP(0LL,dy/abs(dy));
	if (dy==0) return MP(dx/abs(dx),0LL);
	ll g=__gcd(abs(dx),abs(dy));
	return MP(dx/g,dy/g);
}
class BearBall {
	public:
	int countThrows(vector <int> vx, vector <int> vy) {
		ll n=vx.size();
		ll final=0;
		for (ll a=0;a<n;a++) {
			map<pair<ll,ll>, ll> h;
			for (ll b=0;b<n;b++) {
				if (a==b) continue;
				ll dx=vx[b]-vx[a];
				ll dy=vy[b]-vy[a];
				pair<ll,ll> frac=getfrac(dx,dy);
				h[frac]++;
			}
			ll ans=0;
			if (h.size()==1) {
				for (ll i=0;i<n;i++) {
					for (ll j=0;j<n;j++) {
						ans+=abs(i-j);
					}
				}
				return ans;
			}
			for (auto &w:h) {
				ans+=1+((w.second-1)*2);
			}
			final+=ans;
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
		cout << "Testing BearBall (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1466269203;
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
		BearBall _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,4,2};
				int y[] = {1,10,7};
				_expected = 6;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,0,0,1,1};
				int y[] = {0,1,2,0,1};
				_expected = 22;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {5,7,9,11};
				int y[] = {4,3,2,1};
				_expected = 20;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {10,10,50,50,90,90};
				int y[] = {5,17,5,17,5,17};
				_expected = 34;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {-100, -90, -80, -70, -85, -90, 0, 20};
				int y[] = {-5, -8, -13, -21, -13, -13, -13, -69};
				_expected = 68;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {0,0};
				int y[] = {0,1};
				_expected = 2;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {0,1,2};
				int y[] = {0,0,0};
				_expected = 1+2+1+1+1+2;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 7:
			{
				int x[] = {-1,0,1,0,0};
				int y[] = {0,0,0,-1,1};
				_expected = 4+5*4;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 8:
			{
				int x[]={13058, -12722, 4300, 16601, 10475};
				int y[]={13059, -12721, 4301, 16602, 10476};
				_expected = 40;
				_received = _obj.countThrows(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
