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
const ll mn=3001;
bool seen[mn];
bool fst[mn];
ll invfst[mn];
ll n;
ll st[mn];
ll cnt[8];
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) {assert(n>=0); ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
ll final=0;
void addfinal() {
	ll ans=1;
	for (ll s=0;s<8;s++) {
		ll to=mod_pow(__builtin_popcountll(s),cnt[s],MOD);
		ans=(to*ans)%MOD;
	}
	final+=ans;
	final%=MOD;
}
ll cnt[mn][mn];
vector<ll> vs;
class MappingABC {
	public:
	int countStrings(vector <int> t) {
		set<ll> ss;
		for (auto &w:t) ss.insert(w);
		for (auto &w:ss) vs.PB(w);
		n=t.size();
		memset(seen,0,sizeof seen);
		for (ll i=0;i<n;i++) {
			if (!seen[t[i]]) {fst[i]=true;seen[t[i]]=true;}
		}
		ll ans=0;
		for (ll k=0;k<2;k++) {
			final=0;
			for (ll a=0;a<n;a++) {
				if (!fst[a]) continue;
				memset(cnt,0,sizeof cnt);
				for (auto &s:vs) st[s]=(k==0)?0b110:0b111;
				for (ll x=0;x<n;x++) {
					if (x<a) st[t[x]]=0b011;
				}
				st[t[a]]=0b100;
				for (auto &s:vs) {
					cnt[st[s]]++;
				}
				for (ll b=a+1;b<n;b++) {
					if (!fst[b]) continue;
					ll os=st[t[b]];
					cnt[os]--;
					{ll ns=os&0b010;
					st[t[b]]=ns;
					cnt[ns]++;
					if(k) {
					printf("a:%lld b:%lld\n",a,b);
					for (ll x=0;x<n;x++) printf("x:%lld cnt:%lld\n",x,st[t[x]]);}
					addfinal();
					printf("final:%lld\n",final);
					cnt[ns]--;}
					ll ns=os&0b101;
					if (last[t[b]]<=b) ns|=0b001;
					st[t[b]]=ns;
					cnt[ns]++;
				}
			}
			printf("k:%lld final:%lld\n",k,final);
			if (k==0) {
				ans+=(MOD-final);
			}
			else {
				ans+=final;
			}
		}
		return ans%MOD;
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
		cout << "Testing MappingABC (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485016624;
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
		MappingABC _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int t[] = {9,9,2,9,4};
				_expected = 2;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 1:
			{
				int t[] = {1,2,3};
				_expected = 1;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 2:
			{
				int t[] = {1,2,2,1,2,1,2};
				_expected = 0;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 3:
			{
				int t[] = {7,3000,1,3000,1,3000,1,10,7};
				_expected = 20;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 4:
			{
				int t[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,
				          26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
				_expected = 166952139;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			/*case 5:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int t[] = ;
				_expected = ;
				_received = _obj.countStrings(vector <int>(t, t+sizeof(t)/sizeof(int))); break;
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
