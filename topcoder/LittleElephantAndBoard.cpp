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
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }

template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
ll mod_pow2(ll a, ll n, ll mod) {
	if (n<0) return mod_inv(mod_pow(a,-n,mod),mod);
	else return mod_pow(a,n,mod);
}

const ll EMP=0,PONLY=1,HASGB=2;
inline ll norm(ll x) {
	x%=MOD; if(x<0) x+=MOD; return x;
}
const ll mn=2e6+2;
ll ptwo[mn];
ll fact[mn],invfact[mn];
void initfact() {
	ll n=mn;
	ll res=1;
	fact[0] = res;
	for (ll x = 1; x < n; x++) {
		res=(res*x)%MOD;
		fact[x]=res;
	}
	res=mod_inv(res,MOD);
	for (ll x=n-1;x>=0;x--) {
		invfact[x]=res;
		//assert((fact[x]*invfact[x])%MOD==1);
		res=(res*x)%MOD;
	}
	ptwo[0]=1;
	for (ll x=1;x<n;x++) {
		ptwo[x]=(ptwo[x-1]*2)%MOD;
	}
}
ll binom(ll n,ll k) {
	if (n<k) return 0;
	if (n<0||k<0) return 0;
	
	ll ans = (invfact[k]*invfact[n-k])%MOD;
	
	return (fact[n]*ans)%MOD;
}

ll starbar(ll stars, ll parts) {
	if (parts==0) {
		return (stars==0)?1:0;
	}
	return binom(stars+parts-1,parts-1);
}
ll brute(ll r, ll g, ll b) {
	ll n=r+g+b;
	ll zlim=1; for (ll i=0;i<n;i++) zlim*=3;
	ll ans=0;
	for (ll zz=0;zz<zlim;zz++) {
		ll z=zz;
		ll prev=-1;
		ll cr=0,cg=0,cb=0;
		bool ok=true;
		//vector<ll> v;
		for (ll i=0;i<n;i++) {
			ll t=z%3; z/=3;
			if (t==prev) {
				ok=false; break;
			}
			if (t==0) cr++;
			if (t==1) cg++;
			if (t==2) cb++;
			//v.PB(t);
			prev=t;
		}
		if (ok&&cr==r&&cg==g&&cb==b) {
			//for (auto &w:v)printf("%lld ",w); printf("\n");
			ans++;
		}
	}
	return (2*ans)%MOD;
}
inline ll mul(ll x, ll y) {
	return (x*y)%MOD;
}
int solve(int _M, int _R, int _G, int _B) {
		assert(2*_M==_R+_G+_B);
		ll M=_M;
		ll R=M-_R,G=M-_G,B=M-_B;
		//printf("R:%d G:%d B:%d\n",R,G,B);
		if (R==0) {
			if (G==B) return 2*2;
			if (abs(G-B)==1) return 1*2;
			return 0;
		}
		ll midslots=R-1;
		ll final=0;
		for (ll _p=0;_p<=min(G,B);_p++) {
			for (ll ls=0;ls<3;ls++) for (ll rs=0;rs<3;rs++) {
				ll p=_p;
				ll loneg=G-p;
				ll loneb=B-p;
				ll lone=loneg+loneb;
				ll ans=1;
				// Order GB
				ll c1=binom(lone,loneg);
				if (ls==PONLY) {p--; ans*=2;}
				if (rs==PONLY) {p--; ans*=2;}
				if (ls==HASGB) lone--;
				if (rs==HASGB) lone--;
				if (p<0||lone<0) continue;
				//printf("_p:%lld ls:%lld rs:%lld lone:%lld p:%lld ans:%lld\n",_p,ls,rs,lone,p,ans);
				// Put lone GB into midslots.
				ll c2=binom(midslots,lone);
				// Put 1P into empty midslots. Mul by 2 each time.
				ll emptymidslots=midslots-lone;
				if (emptymidslots<0) continue;
				p-=emptymidslots;
				if (p<0) continue;
				ans*=ptwo[emptymidslots]; ans=norm(ans);
				// Distribute remaining Ps into midslots + side slots if they accept stuff
				ll accepters = midslots;
				if (ls!=EMP) accepters++;
				if (rs!=EMP) accepters++;
				ll c3=starbar(p, accepters);

				ans=mul(ans,mul(c1,mul(c2,c3)));
				final+=ans;
				//printf("_p:%lld ls:%lld rs:%lld ans:%lld c1:%lld c2:%lld c3:%lld p:%lld midslots:%lld\n",_p,ls,rs,ans,c1,c2,c3,p,midslots);
				final=norm(final);
			}
		}
		final*=2;
		final=norm(final);
		//ll bf=brute(R,G,B);
		//if (final!=bf) {
		//	printf("Got:%lld Expected:%lld\n",final,bf);
		//	assert(0);
		//}
		return final;
}
class LittleElephantAndBoard {
	public:
	int getNumber(int _M, int _R, int _G, int _B) {
		initfact();
		//for (ll k=0;k<1000;k++) {
		//	_M=rand()%8+1;
		//	_R=rand()%8+1;
		//	_G=rand()%8+1;
		//	_B=2*_M-_R-_G;
		//	if (_R>=0&&_G>=0&&_B>=0) solve(_M, _R, _G, _B);
		//}
		return solve(_M, _R, _G, _B);
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
		cout << "Testing LittleElephantAndBoard (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486842926;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LittleElephantAndBoard _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int M = 2;
				int R = 2;
				int G = 1;
				int B = 1;
				_expected = 4;
				_received = _obj.getNumber(M, R, G, B); break;
			}
			case 1:
			{
				int M = 2;
				int R = 2;
				int G = 2;
				int B = 0;
				_expected = 0;
				_received = _obj.getNumber(M, R, G, B); break;
			}
			case 2:
			{
				int M = 10;
				int R = 7;
				int G = 7;
				int B = 6;
				_expected = 496;
				_received = _obj.getNumber(M, R, G, B); break;
			}
			case 3:
			{
				int M = 474;
				int R = 250;
				int G = 300;
				int B = 398;
				_expected = 969878317;
				_received = _obj.getNumber(M, R, G, B); break;
			}
			case 4:
			{
				int M = 2;
				int R = 1;
				int G = 1;
				int B = 2;
				_expected = 4;
				_received = _obj.getNumber(M, R, G, B); break;
			}
			case 5:
			{
				int M = 3;
				int R = 2;
				int G = 2;
				int B = 2;
				_expected = 12;
				_received = _obj.getNumber(M, R, G, B); break;
			}
			/*case 6:
			{
				int M = 3;
				int R = 1;
				int G = 4;
				int B = ;
				_expected = ;
				_received = _obj.getNumber(M, R, G, B); break;
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
