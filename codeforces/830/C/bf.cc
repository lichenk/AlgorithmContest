#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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

ll rint()
{
    readAhead(16);

    ll x = 0;
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
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
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

ll n; ll k;
ll a[104];
ll f[104];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld%lld",&n,&k);
	for (ll i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	ll suma=0;
	for (ll i=0;i<n;i++) suma+=a[i];
	ll gota=(k+suma)/n;
	ll final=-1;
	if (gota>=a[n-1]) final=gota;
	ll slim=ceil(sqrt(a[n-1]))+1;
	while(slim*slim<=a[n-1]) slim++;
	ll s=slim;
	while(s<=a[n-1]) {
		ll minleeway=1LL<<61;
		ll sum=0;
		ll contrib=0;
		for (ll i=0;i<n;i++) {
			f[i]=(a[i]+s-1)/s;
			contrib+=f[i];
			ll rem=f[i]*s-a[i];
			sum+=rem;
			ll leeway=(s-rem)/f[i];
			//printf("a[i]:%d leeway:%lld f[i]:%d\n",a[i],leeway,f[i]);
			chkmin(minleeway,leeway);
		}
		chkmax(minleeway,0ll);
		ll gomax=(k-sum)/contrib;
		if (gomax>=0) {
			ll cango=min(gomax,minleeway);
			if (sum+(cango*contrib)<=k) chkmax(final,(ll)(s+cango));
		}
		//printf("s:%lld minleeway:%lld cango:%lld gomax:%lld\n",s,minleeway,cango,gomax); fflush(stdout);
		// Transition state
		s+=minleeway+1;
	}
	for (ll d=slim;d>=1;d--) {
		if (final>=d) {
			printf("%lld\n",final);
			return 0;
		}
		ll sum=0;
		for (ll i=0;i<n;i++) {
			ll rem=a[i]%d;
			if (rem>0) sum+=d-rem;
		}
		if (sum<=k) {
			printf("%lld\n",d);
			return 0;
		}
	}
}
