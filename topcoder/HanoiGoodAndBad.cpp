#include <bits/stdc++.h>
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
ll a,b;
ll gdave,gearl;
ll gans=INF;
inline bool same() {
	if (a==b) {
		//printf("SAME");
		chkmin(gans,gearl);
	}
	return a==b;
}
inline ll getbit(ll s, ll k) {
	--k;
	return(s>>(2*k))&3;
}
inline void setbit(ll &s,ll k, ll x) {
	ll os=s;
	--k;
	s&=~(3LL<<(2*k));
	s|=x<<(2*k);
	//printf("k:%lld x:%lld os:%lld -> s:%lld. Ampersand:%lld Tilde:%lld\n",k,x,os,s,3<<(2*k),~(3<<(2*k)));
}
void solve_dave(ll s, ll t, ll e, ll n) {
	if (n>0) {
		if (gdave==0) return;
		solve_dave(s,e,t,n-1);
		if (gdave==0) return;
		//printf("n:%lld. %lld==%lld->%lld\n",n,getbit(a,n),s,t);
		assert(getbit(a,n)==s);
		setbit(a,n,t);
		assert(getbit(a,n)==t);
		gdave--;
		if (gdave==0) return;
		solve_dave(e,t,s,n-1);
		if (gdave==0) return;
	}
}
ll p3[30];
void solve_earl(ll s, ll t, ll e, ll n) {
	if (same()) return;
	if (n>0) {
		ll slot=getbit(a,n);
		if (slot==s) {
			solve_earl(s,t,e,n-1);
			if (same()) return;
		}
		else if (slot==e) {
			for (ll x=1;x<=n-1;x++) {
				setbit(b,x,t);
			}
			gearl+=(p3[n-1]-1)+1;
			assert(getbit(b,n)==s);
			setbit(b,n,e);
			if (same()) return;
			solve_earl(t,s,e,n-1);
			if (same()) return;
		}
		else {
			assert(slot==t);
			gearl+=(p3[n-1]-1)+1+(p3[n-1]-1)+1;
			assert(getbit(b,n)==s);
			setbit(b,n,t);
			if (same()) return;
			solve_earl(s,t,e,n-1);
			if (same()) return;
		}
	}
}
ll bf(ll n, ll dave) {
	a=0;b=0;
	gdave=dave;
	solve_dave(0,1,2,n);
	assert(gdave==0);
	gearl=0;
	solve_earl(0,1,2,n);
	assert(same());
	//printf("%lld %lld\n",gearl,gans);
	assert(gearl==gans);
	return gearl;
}
class HanoiGoodAndBad {
	public:
	int moves(int n, int dave) {
		{
			ll x=1;
			for (ll i=0;i<30;i++) {
				p3[i]=x;
				x*=3;
			}
		}
		return bf(n,dave);
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
		cout << "Testing HanoiGoodAndBad (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488653911;
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
		HanoiGoodAndBad _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int Dave = 1;
				_expected = 2;
				_received = _obj.moves(N, Dave); break;
			}
			case 1:
			{
				int N = 4;
				int Dave = 15;
				_expected = 80;
				_received = _obj.moves(N, Dave); break;
			}
			case 2:
			{
				int N = 9;
				int Dave = 265;
				_expected = 16418;
				_received = _obj.moves(N, Dave); break;
			}
			case 3:
			{
				int N = 1;
				int Dave = 0;
				_expected = 0;
				_received = _obj.moves(N, Dave); break;
			}
			case 4:
			{
				int N = 1;
				int Dave = 1;
				_expected = 2;
				_received = _obj.moves(N, Dave); break;
			}
			case 5:
			{
				int N = 2;
				int Dave = 0;
				_expected = 0;
				_received = _obj.moves(N, Dave); break;
			}
			case 6:
			{
				int N = 2;
				int Dave = 1;
				_expected = 1;
				_received = _obj.moves(N, Dave); break;
			}
			case 7:
			{
				int N = 2;
				int Dave = 2;
				_expected = 7;
				_received = _obj.moves(N, Dave); break;
			}
			case 8:
			{
				int N = 2;
				int Dave = 3;
				_expected = 8;
				_received = _obj.moves(N, Dave); break;
			}
			case 9:
			{
				int N = 19;
				int Dave = 471981;
				_expected = 1142891524;
				_received = _obj.moves(N, Dave); break;
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
