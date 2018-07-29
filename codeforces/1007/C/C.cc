#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

int ask(ll x, ll y) {
  printf("%lld %lld\n",x,y); fflush(stdout);
  int ret; scanf("%d",&ret);
  if (ret==0) exit(0);
  return ret;
}
ll ga,gb;
map<pll,int> gh;
int ask(ll x, ll y) {
	auto it=gh.find(MP(x,y));
	if (it!=gh.end()) return it->snd;
	ll a=ga,b=gb;
	if (x==a&&y==b) exit(0);
	vector<int> v;
	if (x<a) v.PB(1);
	if (y<b) v.PB(2);
	if (x>a||y>b) v.PB(3);
	srand(clock());
	int ans=v[rand()%v.size()];
	gh[MP(x,y)]=ans;
	return ans;
}

void solve(ll n) {
	ll vgot[2]; vgot[0]=vgot[1]=-1;
  for (int s=0;s<2;s++) {
  	ll imin[2]; ll imax=n+1;
  	for (int t=0;t<2;t++) {imin[t]=1;}
  	while(imin[0]<imax||imin[1]<imax) {
  		for (int t=0;t<2;t++) {
  			if (imin[t]<imax) {
  				ll imid=(imin[t]+imax)/2;
  				int r=ask(imid,imid);
  				if (s==0) {
  					if (r==1) imin[0]=imid+1;
  					else if (r==2) imin[1]=imid+1;
  					else imax=imid;
  				}
  			}
  		}
  	}
    for (int t=0;t<2;t++) {
    	if (imin[t]==imax) vgot[t]=imax;
    }
  }
  for (int t=0;t<2;t++) {
  	ll got=vgot[t]; if (got==-1) continue;
	  for (ll g=max(1ll,got-1);g<=min(n,got+1);g++) {
	    if (t==0) {
	      ll imin=1,imax=n+1;
	      while(imin<imax) {
	        ll imid=(imin+imax)/2;
	        int r=ask(imid,g);
	        if (r==1) imin=imid+1;
	        else imax=imid;
	      }
	    }
	    if (t==1) {
	      ll imin=1,imax=n+1;
	      while(imin<imax) {
	        ll imid=(imin+imax)/2;
	        int r=ask(g,imid);
	        if (r==2) imin=imid+1;
	        else imax=imid;
	      }
	    }
	  }
	}
	assert(0);

}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n; scanf("%lld",&n);
  scanf("%lld%lld",&ga,&gb);
  solve(n);
}




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