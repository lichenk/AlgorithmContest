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

int rint()
{
  int x; scanf("%d",&x); return x;
}

typedef vector<int> vi;
typedef vector<vi> vvi;
vvi matrixUnit(ll n) {
    vvi res(n, vi(n));
    for (ll i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}

vvi matrixMul(const vvi &a, const vvi &b) {
    ll n = a.size();
    ll m = a[0].size();
    ll k = b[0].size();
    vvi res(n, vi(k));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < k; j++)
            for (ll p = 0; p < m; p++)
                res[i][j] = (res[i][j] + (long long) a[i][p] * b[p][j]) % MOD;
    return res;
}

void matrixMult(vvi &res, const vvi &a, const vvi &b) {
    ll n = a.size();
    ll m = a[0].size();
    ll k = b[0].size();
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < k; j++)
        {
          ll ans=0;
            for (ll p = 0; p < m; p++)
                ans = (ans + (long long) a[i][p] * b[p][j]) % MOD;
          res[i][j]=ans;
        }
}

bool bf(vvi inp) {
  vvi a=inp;
  int n=a.size();
  for (int k=0;k<100;k++) {
    bool ok=1;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
      if (a[i][j]==0) {ok=0;break;}
    }
    if (ok) return 1;
    a=matrixMul(a,inp);
  }
  return 0;
}
const int mn=2000;
bool g[mn][mn];
int gn;
bool smart(int n) {
  gn=n;
  if (n==1&&a[0][0]!=0) return 1;
  for (int x=0;x<n;x++) {
    int ans=0;
    for (int y=0;y<n;y++) {
      if (a[x][y]) ans++;
    }
    if (ans<2) return 0;
  }
  for (int x=0;x<n;x++) {
    int ans=0;
    for (int y=0;y<n;y++) {
      if (a[y][x]) ans++;
    }
    if (ans<2) return 0;
  }
  return 1;
}
void test() {
  srand(time(0)+clock()+rand());
  for (int k=0;k<1000;k++) {
    int n=(rand()%5)+1;
    vvi a; a.resize(n);
    for (int x=0;x<n;x++) {
      a[x].resize(n);
      for (int y=0;y<n;y++) g[x][y]=a[x][y]=rand()&1;
    }
    bool b=bf(a),s=smart(n);
    if (b!=s) {
      for (int x=0;x<n;x++) {
        for (int y=0;y<n;y++) printf("%d",a[x][y]);
        printf("\n");
      }
      printf("b:%d s:%d\n",b,s);
    }
  }
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	test(); return 0;
  int n=rint();
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) g[x][y]=rint();
  bool final=solve(n);
  if (final) printf("YES\n");
  else printf("NO\n");
}

