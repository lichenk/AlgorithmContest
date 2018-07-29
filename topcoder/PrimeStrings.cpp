#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=84;
ll gx,gy;
ll dp[MAXN][2][MAXN][2][MAXN][2];
ll solve(ll p, ll xs, ll q, ll ys, ll k, ll hitone) {
	ll dped=dp[p+42][xs][q+42][ys][k+42][hitone];
	if (dped!=UNDEF) {
		return dped;
	}
	if (hitone&&p>q+k) ys=0;
	if (xs==0&&ys==0) {
		ll fin=0;
		if (p+1>=k+q+1) fin = 1LL<<(p+1);
		return fin;
	}
	if (p==-1) {
		return 0;
	}
	ll xb=(gx>>p)&1, yb=(gy>>q)&1;
	ll nxlim=xs?xb:1;
	ll ans=0;
	for (ll nx=0;nx<=nxlim;nx++) {
		ll nxs=(xs&&(nx==xb));
		ll nys=(ys&&(nx==yb));
		if (q<0) {
			yb=0; nys=0;
		}
		bool skip=(nx==0&&k>0)||(nx==1&&k>p);
		ll nhitone=hitone||(nx==1);
		if (skip) {
			ll nk=(nhitone)?k-1:k;
			ll val=solve(p-1,nxs,q,ys,nk,nhitone);
			ans+=val;
		}
		else {
			if (ys) {
				if(nx>=yb) {
					ll val=solve(p-1,nxs,q-1,nys,k,nhitone);
					ans+=val;
				}
			}
			else {
				ll val=solve(p-1,nxs,q-1,nys,k,nhitone);
				ans+=val;
			}
		}
	}
	//printdbg("%lld %lld %lld %lld %lld: %lld\n",p,xs,q,ys,k,ans);
	dp[p+42][xs][q+42][ys][k+42][hitone]=ans;
	return ans;
}

class PrimeStrings {
	public:
long long getCount(long long x, long long y, int k) {
	for (ll p=0;p<MAXN;p++)
		for (ll xs=0;xs<2;xs++)
			for (ll q=0;q<MAXN;q++)
				for (ll ys=0;ys<2;ys++)
					for (ll kk=0;kk<MAXN;kk++)
						for (ll hitone=0;hitone<2;hitone++)
							dp[p][xs][q][ys][kk][hitone]=UNDEF;
	gx=x+1,gy=y;
	ll flsx=63-__builtin_clzll(gx);
	ll flsy=63-__builtin_clzll(gy);
	ll ans=solve(flsx,1,flsy,1,k,0);
	ll final=x-ans;
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
		cout << "Testing PrimeStrings (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1462161593;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PrimeStrings _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long x = 2LL;
				long long y = 1LL;
				int k = 1;
				_expected = 2LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 1:
			{
				long long x = 6LL;
				long long y = 2LL;
				int k = 1;
				_expected = 4LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 2:
			{
				long long x = 6LL;
				long long y = 1LL;
				int k = 3;
				_expected = 6LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 3:
			{
				long long x = 31LL;
				long long y = 6LL;
				int k = 2;
				_expected = 20LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 4:
			{
				long long x = 413LL;
				long long y = 34LL;
				int k = 2;
				_expected = 130LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 5:
			{
				long long x = 1000000000LL;
				long long y = 1000000000LL;
				int k = 5;
				_expected = 1000000000LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 6:
			{
				long long x = 549755813602LL;
				long long y = 8369864093LL;
				int k = 5;
				_expected = 178429547459LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 7:
			{
				long long x = 68719476128LL;
				long long y = 4023LL;
				int k = 22;
				_expected = 8591149647LL;
				_received = _obj.getCount(x, y, k); break;
			}
			/*case 8:
			{
				long long x = LL;
				long long y = LL;
				int k = ;
				_expected = LL;
				_received = _obj.getCount(x, y, k); break;
			}*/
			/*case 9:
			{
				long long x = LL;
				long long y = LL;
				int k = ;
				_expected = LL;
				_received = _obj.getCount(x, y, k); break;
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
