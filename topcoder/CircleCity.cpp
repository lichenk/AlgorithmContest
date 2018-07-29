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
const ll mn=8004;
ll pre[mn];
ll n;
ll query(ll l, ll r) {
	if (l<=r) {
		return pre[r]-pre[l];
	}
	else {
		return pre[n]-(pre[l]-pre[r]);
	}
}
inline ll queryf(ll l, ll r) {
	return pre[r]-pre[l];
}
ll bins(ll start, ll end, ll key) {
	ll imin=start,imax=end;
	while(imin<imax) {
		ll imid=(imin+imax)>>1;
		if (queryf(start,imid)<=key) {
			imin=imid+1;
		}
		else imax=imid;
	}
	return imin;
}
class CircleCity {
	public:
	int findMin(vector <int> dist, int k) {
		n=dist.size();
		for (ll i=0;i<n;i++) {
			pre[i+1+n]=pre[i+1]=dist[i]*2;
		}
		for (ll i=1;i<=2*n;i++) {
			pre[i]+=pre[i-1];
		}
		ll final=0;
		for (ll x=0;x<n;x++) for (ll y=0;y<x;y++) {
			ll got=min(query(x,y),query(y,x));
			chkmax(final,got);
		}
		ll imin=0,imax=final;
		while(imin<imax) {
			ll imid=(imin+imax)>>1;
			//imid=0;
			bool ok=0;
			for (ll init=0;init<n;init++) {
				ll x=init;
				ll end=init+n;
				ll have=k;
				while(x<end) {
					ll y=bins(x,end,imid);
					x=y;
					have--;
					if (have==0) break;
				}
				if (have>=0 && x>=end) {
					ok=1; break;
				}
			}
			//exit(0);
			if (!ok) imin=imid+1;
			else imax=imid;
		}
		chkmin(final,imin);
		return final/2;
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
		cout << "Testing CircleCity (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1499908423;
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
		CircleCity _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dist[] = {3,5,4};
				int k = 2;
				_expected = 3;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 1:
			{
				int dist[] = {3,5,4};
				int k = 3;
				_expected = 0;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 2:
			{
				int dist[] = {1,2,3,4,5,6,5,4,3,2,1};
				int k = 5;
				_expected = 5;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 3:
			{
				int dist[] = {1, 100, 1,1,1, 100, 1, 100, 1,1,1, 100, 1};
				int k = 4;
				_expected = 3;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 4:
			{
				int dist[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7};
				int k = 6;
				_expected = 8;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 5:
			{
				int dist[] = {
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000,
				             1000000,1000000,1000000,1000000,1000000,1000000
				             };
				int k = 7;
				_expected = 9000000;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 6:
			{
				int dist[] = {1,1};
				int k = 1;
				_expected = 1;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 7:
			{
				int dist[] = {1,1};
				int k = 2;
				_expected = 0;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 8:
			{
				int dist[] = {1,1,1,1};
				int k = 1;
				_expected = 2;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 9:
			{
				int dist[] = {1,1,1,1};
				int k = 2;
				_expected = 1;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 10:
			{
				int dist[] = {1,1,1,1};
				int k = 3;
				_expected = 1;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
			}
			case 11:
			{
				int dist[] = {1,1,1,1};
				int k = 4;
				_expected = 0;
				_received = _obj.findMin(vector <int>(dist, dist+sizeof(dist)/sizeof(int)), k); break;
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
