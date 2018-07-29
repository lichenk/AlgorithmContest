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
ll mod_pow(ll a, ll n) {const ll mod=MOD; ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
inline ll add(ll x,ll y) {return (x+y)%MOD;}
const ll mn=52;
ll f[2][mn][mn][mn];
typedef vector<ll> vll;
const ll MAXF=1000;
ll fact[MAXF],invfact[MAXF];
ll binom(ll n, ll k) {
	ll denom = (invfact[n-k]*invfact[k])%MOD;
	return (fact[n]*denom)%MOD;
}
void initfact() {
	fact[0] = 1;
	for (ll i = 1; i < MAXF; i++) {
		fact[i] = (fact[i-1] * i)%MOD;
	}
	for (ll i = 0; i < MAXF; i++) {
		invfact[i] = mod_pow(fact[i],MOD-2);
	}
}
vll pmul(vll &a, vll &b) {
	ll as=a.size(),bs=b.size();
	vll c; c.resize(as+bs-1);
	for (ll ai=0;ai<as;ai++) for (ll bi=0;bi<bs;bi++) {
		c[ai+bi]=add(c[ai+bi], mul(a[ai],b[bi]));
	}
	return c;
}
vector<ll> base,lower;
void init(vector<ll> blank, ll r) {
	// Base
	{
		vector<ll> v={1};
		ll bsz=blank.size();
		for (ll x=0;x<bsz;x++) {
			if (x==r) continue;
			ll len=blank[x];
			vector<ll> a(len+1);
			for (ll i=0;i<=len;i++) {
				a[i]=binom(len,i);
			}
			v=pmul(v,a);
		}
		base=v;
	}
	// Lower
	{
		vector<ll> v={1};
		ll bsz=blank.size();
		for (ll x=0;x<bsz;x++) {
			if (x==r) continue;
			ll len=blank[x];
			vector<ll> a(len);
			for (ll i=0;i<len;i++) {
				a[i]=binom(len,i);
			}
			v=pmul(v,a);
		}
		lower=v;
	}
}
ll getprob(ll t, ll rn) {
	if (t<rn) return 0;
	ll k=t-rn;
	if (k>=lower.size()||k>=base.size()) return 0;
	return mul(lower[t-rn],mod_pow(base[t-rn],MOD-2));
}
vector<ll> cardsmod;
ll cardslen[55];
inline void clearf(ll t, ll rn, ll numcards) {
	for (ll b=0;b<=rn;b++) for (ll a=0;a<=rn;a++) for (ll c=0;c<=numcards;c++) {
		f[t][b][a][c]=0;
	}
}
ll final=0;
void solvef(vector<string> cards, ll rn, ll bsum, ll p, ll gxidx) {
	//printf("rn:%lld p:%lld\n",rn,p);
	ll clim=cards.size();
	clearf(0,rn,clim);
	f[0][0][0][clim]=1;
	for (ll t=0;t<=cards.size();t++) {
		ll cur=t&1;ll nxt=cur^1;
		clearf(nxt,rn,clim);
		ll splitdenom=mod_pow(bsum-t,MOD-2); // Number of blanks to choose from
		ll blim=min(p,t);
		ll alim=min(rn-p-1,t);
		//printf("blim:%lld alim:%lld dlim:%lld\n",blim,alim,dlim);
		for (ll b=0;b<=blim;b++) for (ll a=0;a<=alim;a++) for (ll cx=0;cx<=clim;cx++){
			ll nc=(cx==clim)?0:1;
			if (a+b+nc>rn) continue;
			ll v=f[cur][b][a][cx];
			if (v==0) continue;
			v%=MOD;
			ll bl=p-b,al=rn-p-1-a,cl=1-nc,rl=bsum-t-bl-al-cl;
			//printf("t:%lld b:%lld a:%lld cx:%lld d:%lld v:%lld. bl:%lld al:%lld rl:%lld\n",t,b,a,cx,d,v,bl,al,rl);
			if (rl<0) continue;
			if (a+b+nc==rn) {
				// Add contribution
				ll base=v;
				base=mul(cardsmod[cx],base);
				ll mulprob=getprob(t,rn);
				ll contrib=mul(base, mulprob);
				//ll contrib=base;
				final=add(final,contrib);
				//printf("t:%lld b:%lld a:%lld cx:%lld d:%lld Adding contrib: %lld. t:%lld rn:%lld mulprob:%lld\n",t,b,a,cx,d,contrib,t,rn,mulprob);
				continue;
			}
			if (bl) {
				// Goes before
				ll split=mul(bl,splitdenom);
				f[nxt][b+1][a][cx]+=mul(v,split);
				f[nxt][b+1][a][cx]%=MOD;
			}
			if (al) {
				// Goes after
				ll split=mul(al,splitdenom);
				split=mul(split,mod_pow(10ll,cardslen[t]));
				f[nxt][b][a+1][cx]+=mul(v,split);
				f[nxt][b][a+1][cx]%=MOD;
			}
			//printf("Consider card %lld to inc. cl:%lld\n",t,cl);
			if (cl) {
				// Goes center
				assert(cx==clim);
				ll split=mul(cl,splitdenom);
				f[nxt][b][a][t]+=mul(v,split);
				//printf("Using card %lld to inc\n",t);
				f[nxt][b][a][t]%=MOD;
			}
			if (rl) {
				// Goes rest
				ll split=mul(rl,splitdenom);
				f[nxt][b][a][cx]+=mul(v,split);
				f[nxt][b][a][cx]%=MOD;
			}
		}
	}
}
class AnyNumber {
	public:
	int findExpectation(vector <string> cards, vector <int> _blank) {
		initfact();
		vector<ll> blank; for (auto &w:_blank) blank.PB(w);
		for (ll i=0;i<55;i++) cardslen[i]=0;
		for (ll i=0;i<cards.size();i++) {
			cardslen[i]=cards[i].length();
		}
		for (auto &s:cards) {
			ll v=0;
			for (auto &c:s) {
				v=mul(v,10ll);
				ll d=c-'0';
				v=add(v,d);
			}
			cardsmod.PB(v);
		}
		ll bsz=blank.size();
		ll tlim=cards.size();
		ll bsum=0; for (auto &w:blank) bsum+=w;
		for (ll x=0;x<bsz;x++) {
			init(blank,x);
			for (ll p=0;p<blank[x];p++) {
				solvef(cards, blank[x], bsum, p, blank.size()-1);
			}
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
		cout << "Testing AnyNumber (1000.0 points)" << endl << endl;
		for (int i = 0; i < 30; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1476592155;
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
		AnyNumber _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cards[] = {"1000000007"};
				int blank[] = {1};
				_expected = 0;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 1:
			{
				string cards[] = {"123", "45", "6", "7"};
				int blank[] = {3};
				_expected = 401988;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 2:
			{
				string cards[] = {"46", "135", "00000", "3024920394"};
				int blank[] = {1,2};
				_expected = 166676675;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 3:
			{
				string cards[] = {"0001","1"};
				int blank[] = {2};
				_expected = 5006;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 4:
			{
				string cards[] = {
				                 "23049823728915788877792227159747104412489500114823",
				                 "0","0","0","0","0","0","0","0","0","0","0","0","0","0"
				                 };
				int blank[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				_expected = 700700700;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 5:
			{
				string cards[] = {
				                 "00818779221632",
				                 "278572651816185",
				                 "6333769219121862",
				                 "26393834152447144",
				                 "538326000966547591",
				                 "9821611315224768137",
				                 "93972464995137565728",
				                 "3898045535918771635",
				                 "590165533540363294",
				                 "44937786507616011",
				                 "4104385393322343",
				                 "073516634500928",
				                 "60161293266216",
				                 "1113290873818",
				                 "324806712350"
				                 };
				int blank[] = {2,7,3,4,1};
				_expected = 708644595;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 6:
			{
				string cards[] = {"123"};
				int blank[] = {1};
				_expected = 123;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 7:
			{
				string cards[] = {"2","4"};
				int blank[] = {2};
				_expected = 33;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 8:
			{
				string cards[] = {"2","4"};
				int blank[] = {1,1};
				_expected = 2;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 9:
			{
				string cards[] = {"2","4","6","8"};
				int blank[] = {2,2};
				_expected = 44;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 10:
			{
				string cards[] = {"2","4","6","8"};
				int blank[] = {2,2,2};
				_expected = 600000057;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 11:
			{
				string cards[] = {"2","4","6","8"};
				int blank[] = {1,1,1};
				_expected = 2;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 12:
			{
				string cards[] = {"2","4","6","8"};
				int blank[] = {1,1,2};
				_expected = 833333347;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 13:
			{
				string cards[] = {"2","4","6"};
				int blank[] = {1,1,2};
				_expected = 833333347;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 14:
			{
				string cards[] = {"1","1","1"};
				int blank[] = {1,1,2};
				_expected = 666666674;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 15:
			{
				string cards[] = {"0","2","6","2","5","9","9","3","5","4","4","0","6","1","3"};
				int blank[] = {2,7,3,4,1};
				_expected = 258341033;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 16:
			{
				string cards[] = {"1","1","1","1"};
				int blank[] = {1,2,3};
				_expected = 166666688;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 17:
			{
				string cards[] = {"1","1","1","1","1"};
				int blank[] = {2,2,3};
				_expected = 857142897;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 18:
			{
				string cards[] = {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"};
				int blank[] = {2,7,3,4,1};
				_expected = 653272690;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 19:
			{
				string cards[] = {"1","1","1","1","1","1","1"};
				int blank[] = {2,3,4};
				_expected = 460317732;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 20:
			{
				string cards[] = {"1","1","1","1","1","1"};
				int blank[] = {2,3,3};
				_expected = 66;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
			}
			case 21:
			{
				string cards[] = {"1","1","1","1","1","1"};
				int blank[] = {1,3,3};
				_expected = 285714328;
				_received = _obj.findExpectation(vector <string>(cards, cards+sizeof(cards)/sizeof(string)), vector <int>(blank, blank+sizeof(blank)/sizeof(int))); break;
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
