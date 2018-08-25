#include <bits/stdc++.h>
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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
int extgcd(int a, int b, int& x, int& y) { for (int u = y = 1, v = x = 0; a;) { int q = b / a; swap(x -= q *(ll) u, u); swap(y -= q *(ll) v, v); swap(b -= q *(ll) a, a); } return b; }
int mod_inv(int a, int m) { int x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
int z[1000];
int q[7];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int m=rint();
  for (int x=1;x<=m;x++) {
    int lucky=0;
    int y=x;
    while(y>0) {
      int d=y%10;
      if (d==1||d==2) lucky++;
      y/=10;
    }
    z[x]=lucky;
  }
  int ans=0;
  for (int a=1;a<=m;a++)
  for (int b=1;b<=m;b++)
  for (int c=1;c<=m;c++)
  for (int d=1;d<=m;d++)
  for (int e=1;e<=m;e++)
  for (int f=1;f<=m;f++)
  for (int g=1;g<=m;g++) {
    int i=0;
    q[i++]=(a);
    q[i++]=(b);
    q[i++]=(c);
    q[i++]=(d);
    q[i++]=(e);
    q[i++]=(f);
    q[i++]=(g);
    bool ok=1;
    for (int x=0;x<7;x++) for (int y=0;y<x;y++) if (q[x]==q[y]) ok=0;
    if (ok) {
      int all=z[a]+z[b]+z[c]+z[d]+z[e]+z[f];
      if (all<z[g]) ans++;
    }
  }
  printf("%d\n",ans);
}





int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}