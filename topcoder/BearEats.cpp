#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 200000
#define UNDEF -1LL
pair<ll,ll> c[MAXN];
ll o[MAXN];
class BearEats {
	public:
	long long getDifference(int Ni, int Ri, int Ci, int Di, int A_MAXi, int B_MAXi) {
ll R = Ri;
ll C = Ci;
ll D = Di;
ll A_MAX = A_MAXi;
ll B_MAX = B_MAXi;
    	for (ll i = 0; i < Ni; i++) {
    		R = (C * R + D) % MOD;
    		c[i+1].second = R % A_MAX;
    		R = (C * R + D) % MOD;
    		c[i+1].first = R % B_MAX;
    	}

    	ll n = Ni+1;
    	c[0] = MP(0LL,0LL);
    	sort(c+1,c+n, greater<pair<ll,ll> >());
    	priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
    	ll avail = UNDEF;
    	ll ans = 0;
    	for (ll x = 0; x < n; x++) {
    		ans -= c[x].first;
    	}
    	for (ll x = 0; x < n; x++) {
    		ll a = c[x].second;
    		ll b = c[x].first;
    		ll vx = a+b;
    		if (avail != UNDEF) {
    			o[x] = avail;
    			avail = UNDEF;
    			ans += vx;
                pq.push(MP(vx,x));
    		}
    		else {
    			if (!pq.empty()) {
    				pair<ll,ll> py = pq.top();
    				ll vy = py.first; ll y = py.second;
    				if (vx > vy) {
    					assert(o[y] != UNDEF);
    					o[x] = o[y];
    					o[y] = UNDEF;
    					avail = y;
    					pq.pop();
    					pq.push(MP(vx, x));
    					ans += (vx-vy);
    				}
    				else {
    					avail = x;
    					o[x] = UNDEF;
    				}
    			}
    			else {
    				avail = x;
    				o[x] = UNDEF;
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
		cout << "Testing BearEats (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453178604;
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
		BearEats _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int R = 4;
				int C = 4;
				int D = 1;
				int A_MAX = 11;
				int B_MAX = 15;
				_expected = -3LL;
				_received = _obj.getDifference(N, R, C, D, A_MAX, B_MAX); break;
			}
			case 1:
			{
				int N = 5;
				int R = 2;
				int C = 3;
				int D = 0;
				int A_MAX = 14;
				int B_MAX = 40;
				_expected = 4LL;
				_received = _obj.getDifference(N, R, C, D, A_MAX, B_MAX); break;
			}
			case 2:
			{
				int N = 4;
				int R = 938593858;
				int C = 538591850;
				int D = 384025833;
				int A_MAX = 885912358;
				int B_MAX = 3405;
				_expected = 1452754016LL;
				_received = _obj.getDifference(N, R, C, D, A_MAX, B_MAX); break;
			}
			case 3:
			{
				int N = 200000;
				int R = 999998741;
				int C = 999997411;
				int D = 64592149;
				int A_MAX = 57;
				int B_MAX = 75;
				_expected = 462494LL;
				_received = _obj.getDifference(N, R, C, D, A_MAX, B_MAX); break;
			}
			/*case 4:
			{
				int N = ;
				int R = ;
				int C = ;
				int D = ;
				int A_MAX = ;
				int B_MAX = ;
				_expected = LL;
				_received = _obj.getDifference(N, R, C, D, A_MAX, B_MAX); break;
			}*/
			/*case 5:
			{
				int N = ;
				int R = ;
				int C = ;
				int D = ;
				int A_MAX = ;
				int B_MAX = ;
				_expected = LL;
				_received = _obj.getDifference(N, R, C, D, A_MAX, B_MAX); break;
			}*/
			/*case 6:
			{
				int N = ;
				int R = ;
				int C = ;
				int D = ;
				int A_MAX = ;
				int B_MAX = ;
				_expected = LL;
				_received = _obj.getDifference(N, R, C, D, A_MAX, B_MAX); break;
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
