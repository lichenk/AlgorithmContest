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

int rint()
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

int n; ll k;
int a[104];
int f[104];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%lld",&n,&k);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	ll suma=0;
	for (int i=0;i<n;i++) suma+=a[i];
	ll gota=(k+suma)/n;
	ll final=-1;
	if (gota>=a[n-1]) final=gota;
	int slim=ceil(sqrt(a[n-1]))+1;
	while(slim*slim<=a[n-1]) slim++;
	int s=slim;
	while(s<=a[n-1]) {
		int minleeway=2147483647;
		ll sum=0;
		int contrib=0;
		for (int i=0;i<n;i++) {
			f[i]=(a[i]+s-1)/s;
			contrib+=f[i];
			int rem=f[i]*s-a[i];
			sum+=rem;
			int leeway=(s-rem)/f[i];
			//printf("a[i]:%d leeway:%lld f[i]:%d\n",a[i],leeway,f[i]);
			chkmin(minleeway,leeway);
		}
		chkmax(minleeway,0);
		int gomax=(k-sum)/contrib;
		if (gomax>=0) {
			int cango=min(gomax,minleeway);
			if (sum+(cango*(ll)contrib)<=k) chkmax(final,(ll)(s+cango));
		}
		//printf("s:%lld minleeway:%lld cango:%lld gomax:%lld\n",s,minleeway,cango,gomax); fflush(stdout);
		// Transition state
		s+=minleeway+1;
	}
	for (int d=slim;d>=1;d--) {
		if (final>=d) {
			printf("%lld\n",final);
			return 0;
		}
		ll sum=0;
		for (int i=0;i<n;i++) {
			int rem=a[i]%d;
			if (rem>0) sum+=d-rem;
		}
		if (sum<=k) {
			printf("%d\n",d);
			return 0;
		}
	}
}
