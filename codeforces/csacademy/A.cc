#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int readInt()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXFACT=4e5+4;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
ll MOD;
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
void init() {
  ll got=1;
  for (ll x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (ll x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
ll binom(ll n,ll k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

ll starbar(ll stars, ll parts) {
  if (parts==0) {
    return (stars==0)?1:0;
  }
  if (parts<=0||stars<0) return 0;
  return binom(stars+parts-1,parts-1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,X; scanf("%lld%lld%lld",&n,&X,&MOD);
	--X;
	init();
	if (n==1) {
		printf("%lld\n",(X+1)%MOD);
		return 0;
	}
	ll final=0;
	for (ll first=1;first<=n;first++) for (ll last=1;last<=n;last++) {
		if (first==last) continue;
		for (ll wastefirst=0;wastefirst<=first;wastefirst++) {
			for (ll wastelast=0;wastelast<=last;wastelast++) {
				ll allsum=(n*(n+1))/2 - first - last + wastefirst + wastelast + n - 1;
				if (wastefirst!=1&&wastelast!=1) allsum--;
				ll t=min(wastefirst,wastelast); allsum+=t;
				ll spots=X-allsum;
				if (spots<0) continue;
				ll buckets=n-1;
				if (wastefirst==first) buckets++;
				if (wastelast==last) buckets++;
				ll got=starbar(spots,buckets);
				//printf("first:%lld last:%lld wf:%lld wl:%lld got:%lld\n",first,last,wastefirst,wastelast,got);
				final+=got;
			}
		}
	}
	final=mul(final,fact[n-2]);
	printf("%lld\n",final);
}
