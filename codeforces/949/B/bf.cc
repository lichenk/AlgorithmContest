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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
vector<ll> bf(ll n) {
  vector<ll> v(2*n);
  for (ll x=1;x<=n;x++) {
    v[2*x-1]=x;
  }
  while(1) {
    bool ok=1;
    for (ll x=1;x<=n;x++) {
      if (v[x]==0) {ok=0; break;}
    }
    if (ok) break;
    for (ll x=v.size()-1;x>=1;x--) {
      if (v[x]!=0) {
        for (ll y=x-1;y>=1;y--) {
          if (v[y]==0) {
            v[y]=v[x];
            v[x]=0;
            break;
          }
        }
        break;
      }
    }
  }
  //cout<<"n:"<<n<<endl;
  for (ll x=1;x<=n;x++) {
    //printf("%lld ",v[x]-1);
    ll idx=x-1,val=v[x]-1;
    //cout<<bitset<4>(idx)<<" "<<bitset<4>(val)<<endl;
    //cout<<val<<",";
  }
  //cout<<endl;
  v.resize(n+1);
  return v;
}
void go() {
  //for (ll n=1;n<=10;n*=2) {
  //  bf(n);
  //}
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n,q; cin>>n>>q;
  vector<ll> vans=bf(n);
  for (ll i=0;i<q;i++) {
    ll x; cin>>x;
    cout<<vans[x]<<endl;
  }
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