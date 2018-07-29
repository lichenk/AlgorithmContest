#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<62LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

const int MAXLOG = 60;
const int64_t BAD=INF;
struct basis
{
    int64_t base[MAXLOG];

    void clear()
    {
		for(int i = MAXLOG - 1; i >= 0; i--)
			base[i] = 0;
    }

    void add(int64_t val)
    {
    	for(int i = MAXLOG - 1; i >= 0; i--) {
				if((val >> i) & 1)
				{
					if(!base[i]) { base[i] = val; return; }
					else val ^= base[i];
				}
			}
		}

    inline int size()
    {
    	int sz = 0;
    	for(int i = 0; i < MAXLOG; i++){
				sz += (bool)(base[i]);
			}
			return sz;
    }

    int64_t min_xor_with_prefix(int64_t seed, int64_t prefix, int64_t prefixmask)
    {
    	int64_t res = seed;
    	int64_t track=seed^prefix;
			for(int i = MAXLOG - 1; i >= 0; i--) {
				if (prefixmask&(1LL<<i)) {
					if(((track >> i) & 1) && base[i]) {
						track ^= base[i];
						res^=base[i];
					}
				}
			}
			if ((res&prefixmask)!=(prefix&prefixmask)) return BAD; // Impossible
			for(int i = MAXLOG-1; i >= 0; i--) {
				if (0==(prefixmask&(1LL<<i))) {
					if(((res >> i) & 1) && base[i]) {res ^= base[i];}
				}
			}
			return res;
		}

    int64_t max_xor(int64_t seed)
    {
			int64_t res = seed;
			for(int i = MAXLOG - 1; i >= 0; i--)
				if(!((res >> i) & 1) && base[i])
					res ^= base[i];
			return res;
		}

    bool can_create(int64_t val)
    {
			for(int i = MAXLOG - 1; i >= 0; i--)
				if(((val >> i) & 1) && base[i])
					val ^= base[i];
			return (val == 0);
    }
};
struct basis bb;
const int mn=101;
int64_t getminge(int64_t ge, int64_t seed) {
	if (ge==0) {
		return bb.min_xor_with_prefix(seed, 0, 0);
	}
	int64_t gt=ge-1;
	int64_t mask=(1LL<<MAXLOG) - 1;
	for (int i=0;i<MAXLOG;i++) {
		if (0==((1LL<<i)&gt)) {
			int64_t prefix=gt|(1LL<<i);
			int64_t ans=bb.min_xor_with_prefix(seed,prefix,mask);
			//if (seed==2) printf("i:%d gt:%lld seed:%lld prefix:%lld mask:%lld\n",i,gt,seed,prefix,mask);
			if (ans!=BAD) return ans;
		}
		mask^=1LL<<i;
	}
	return BAD;
}
ll f[2][mn];
class XorAndLIS {
	public:
	int maximalLength(vector<long long> v) {
		int n=v.size();
		int cur=0;
		fill(f[cur],f[cur]+mn,BAD);
		f[cur][0]=0;
		for (int x=0;x<n;x++) {
			int nxt=cur^1;
			memcpy(f[nxt],f[cur],sizeof(f[cur]));
			for (int k=0;k<=x;k++) {
				ll got=f[cur][k];
				if (got==BAD) continue;
				ll ans=getminge(got,v[x]);
				//printf("x:%d k:%d got:%lld ans:%lld\n",x,k,got,ans);
				if (ans==BAD) continue;
				chkmin(f[nxt][k+1],ans+1);
			}
			bb.add(v[x]);
			cur^=1;
		}
		//for (int k=0;k<=n;k++) {printf("x:%d k:%d got:%lld\n",n,k,f[cur][k]);}
		for (int k=n;k>=1;k--) {
			if (f[cur][k]!=BAD) return k;
		}
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
		cout << "Testing XorAndLIS (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1518723866;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		XorAndLIS _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long x[] = {4,2,1};
				_expected = 3;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
			}
			case 1:
			{
				long long x[] = {0,0,0,0,0,0,0,0,0,0};
				_expected = 1;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
			}
			case 2:
			{
				long long x[] = {1,2,3,4,5,6,7,8,9,10};
				_expected = 10;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
			}
			case 3:
			{
				long long x[] = {7,3,1};
				_expected = 2;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
			}
			case 4:
			{
				long long x[] = {1008,42,7,5,2,9,75,0,0,12,3,6,81,4,3};
				_expected = 12;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
			}
			case 5:
			{
				long long x[] = {1000000000000000000};
				_expected = 1;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
			}
			case 6:
			{
				long long x[] = {10000000000,10000000001};
				_expected = 2;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
			}
			case 7:
			{
				long long x[] = {10000000001,10000000000};
				_expected = 1;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
			}
			case 8:
			{
				long long x[] = {2,1,1};
				_expected = 2;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
			}
			case 9:
			{
				long long x[] = {35,35,35,35};
				_expected = 2;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
			}
			case 10:
			{
				long long x[] = {1,1};
				_expected = 1;
				_received = _obj.maximalLength(vector<long long>(x, x+sizeof(x)/sizeof(long long))); break;
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
