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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXFACT=54;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
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
const int mn=51;
int vbinom[51][51];

int f[2][51][51];
int dx[2]={1,0};
int dy[2]={0,1};
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  for (int x=0;x<mn;x++) for (int y=0;y<=x;y++) vbinom[x][y]=binom(x,y);
	int n=readInt(),k=readInt()/50;
  int xlim=0;
  for (int i=0;i<n;i++) {
    if (readInt()==50) xlim++;
  }
  int ylim=n-xlim;
  if ((ylim>0&&k<2)||(xlim>0&&k<1)) {
    printf("-1\n0\n"); return 0;
  }
  int cur=0,nxt=1;
  f[cur][xlim][ylim]=1;
  for (int d=0;;d++) {
    memset(f[nxt],0,sizeof f[nxt]);
    bool change=0;
    for (int x=0;x<=xlim;x++) {
      for (int y=0;y<=ylim;y++) {
        int val=f[cur][x][y];        
        if (val!=0) {
          printf("x:%d y:%d val:%d\n",x,y,val);
          if (d==0) {
            for (int nx=0;nx<=x;nx++) {
              for (int ny=0;ny<=y;ny++) {
                if (nx==x&&ny==y) continue;
                if ((x-nx)+2*(y-ny)>k) break;
                ll got=f[nxt][nx][ny]+vbinom[x][nx]*(((ll)vbinom[y][ny]*(ll)val)%MOD);
                f[nxt][nx][ny]=got%MOD;
                change=1;
              }
            }
          }
          for (int b=0;b<2;b++) {
            int hx=x+dx[b],hy=y+dy[b];
            for (int nx=0;nx<=hx;nx++) {
              for (int ny=0;ny<=hy;ny++) {
                if (nx==hx&&ny==hy) continue;
                if ((hx-nx)+2*(hy-ny)>k) break;
                int mt=(dx[b])?(xlim-x):(ylim-y);
                if (mt==0) continue;
                ll got=f[nxt][nx][ny]+mt*vbinom[hx][nx]*(((ll)vbinom[hy][ny]*(ll)val)%MOD);
                f[nxt][nx][ny]=got%MOD;
                change=1;
              }
            }
          }
        }
      }
    }
    if (!change) {
      printf("-1\n0\n"); return 0;
    }
    int ans=f[nxt][0][0];
    if (ans) {
      printf("%d\n%d\n",d+1,ans); return 0;
    }
    swap(cur,nxt);
  }
}

