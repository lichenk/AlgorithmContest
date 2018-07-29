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
ll twodicehelper(ll a, ll b, ll k) {
	if (0<=k&&k<=a+b) {
		if (a>b) swap(a,b);
		ll ans=min(a+1,min(k,a+b-k)+1);
		return ans;
	}
	else return 0;
}
ll twodice(ll a, ll b, ll c, ll d, ll k) {
	// Number of ways [a,b]+[c,d]=k
	return twodicehelper(b-a,d-c,k-a-c);
}
const ll mn=(1e5+4);
ld logtable[2*mn+4];
class AlternatingLane {
	public:
	double expectedBeauty(vector <int> low, vector <int> high) {
		for (ll i=0;i<2*mn+4;i++) logtable[i]=log((ld)i);
		ll n=low.size();
		ld final=0;
		for (ll i=0;i<n-1;i++) {
			ll l0=mn-high[i],h0=mn-low[i];
			ll l1=low[i+1],h1=high[i+1];
			//ld normer=1.0L/((high[i+1]-low[i+1]+1)*(high[i]-low[i]+1));
			ld lognorm=-log((ld)(high[i+1]-low[i+1]+1))-log((ld)(high[i]-low[i]+1));
			ld ans=0;
			for (ll x=0;x<2*mn;x++) {
				ll got=twodice(l0,h0,l1,h1,x);
				if (got>0) {
					//printf("l0:%lld h0:%lld l1:%lld h1:%lld k:%lld got:%lld\n",l0,h0,l1,h1,x,got);
					//ld fuck=(ld)abs(x-mn);
					//ans+=normer*fuck*(ld)got;
					ans+=exp(lognorm+logtable[got]+logtable[abs(x-mn)]);
				}
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
		cout << "Testing AlternatingLane (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484528249;
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
		AlternatingLane _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int low[] = {1};
				int high[] = {100};
				_expected = 0.0;
				_received = _obj.expectedBeauty(vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 1:
			{
				int low[] = {1, 1, 1};
				int high[] = {2, 2, 2};
				_expected = 1.0;
				_received = _obj.expectedBeauty(vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 2:
			{
				int low[] = {1, 3, 5, 7, 9};
				int high[] = {2, 4, 6, 8, 10};
				_expected = 8.0;
				_received = _obj.expectedBeauty(vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 3:
			{
				int low[] = {4, 3, 3, 7};
				int high[] = {10, 7, 7, 7};
				_expected = 6.171428571428572;
				_received = _obj.expectedBeauty(vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 4:
			{
				int low[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int high[] = {100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000, 100000};
				_expected = 1633333.3331700016;
				_received = _obj.expectedBeauty(vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 5:
			{
				int low[] = {1,1,1,1};
				int high[] = {3,3,3,3};
				_expected = 2.6666666667;
				_received = _obj.expectedBeauty(vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 6:
			{
				int low[] = {1,1,1,1,1};
				int high[] = {5,5,5,5,5};
				_expected = 6.4;
				_received = _obj.expectedBeauty(vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 7:
			{
				int low[] = {1,1};
				int high[] = {100000,100000};
				_expected = 33333.3333300000;
				_received = _obj.expectedBeauty(vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
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
