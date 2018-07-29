#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<30ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=77777+8;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
vector<ll> pv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
		sp[i]=INF;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
				chkmin(sp[j],i);
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if(sieve_array[i]) {
			chkmin(sp[i],i);
		}
	}
}
ll h[MAXN];
class TheSquareRootDilemma {
	public:
	int countPairs(int n, int m) {
		sieve();
		sp[1]=1;
		if (n>m) swap(n,m);
		for (ll x=1;x<=n;x++) {
			ll d=1;
			ll y=x;
			ll prevp=1,cnt=0,p=0;
			while(p!=1) {
				p=sp[y];
				if (prevp!=p) {
					
					if ((cnt%2)==1) d*=prevp;
					prevp=p;
					cnt=0;
				}
				cnt++;
				y/=p;
				//if (x==281) printf("%lld\n",p);
				//assert(y!=0);
			}

			h[d]++;
		}
		ll ans=0;
		for (ll x=1;x<=m;x++) {
			ll d=1;
			ll y=x;
			ll prevp=1,cnt=0,p=0;
			while(p!=1) {
				p=sp[y];
				if (prevp!=p) {
					
					if ((cnt%2)==1) d*=prevp;
					prevp=p;
					cnt=0;
				}
				cnt++;
				y/=p;
			}
			//printf("%lld, %lld: %lld\n",x,d,h[d]);
			ans+=h[d];
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
		cout << "Testing TheSquareRootDilemma (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460305330;
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
		TheSquareRootDilemma _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int M = 2;
				_expected = 2;
				_received = _obj.countPairs(N, M); break;
			}
			case 1:
			{
				int N = 10;
				int M = 1;
				_expected = 3;
				_received = _obj.countPairs(N, M); break;
			}
			case 2:
			{
				int N = 3;
				int M = 8;
				_expected = 5;
				_received = _obj.countPairs(N, M); break;
			}
			case 3:
			{
				int N = 100;
				int M = 100;
				_expected = 310;
				_received = _obj.countPairs(N, M); break;
			}
			case 4:
			{
				int N = 77777;
				int M = 77777;
				_expected = 543345;
				_received = _obj.countPairs(N, M); break;
			}
			/*case 5:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.countPairs(N, M); break;
			}*/
			/*case 6:
			{
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.countPairs(N, M); break;
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
