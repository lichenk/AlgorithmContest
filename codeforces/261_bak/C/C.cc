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
int a[200][200];
int bf(int m) {
  for (int j=1;j<=m;j++) a[1][j]=0;
  a[1][m+1]=1;
  for (int i=2;i<=m+1;i++) {
    for (ll j=1;j<=m+1;j++) {
      if (j==1) {
        a[i][j]=a[i-1][j+1];
      } else {
        if (j==m+1) {
          a[i][j]=a[i-1][j-1];
        } else {
          a[i][j]=a[i-1][j-1]^a[i-1][j+1];
        }
      }
    }
  }
  int sum=0;
  for (int x=1;x<=m+1;x++) sum+=a[m+1][x];
  return sum;
}

int smart(int n) {
  return 1<<(__builtin_popcount(n+1)-1);
}
int ilog2(ll x) {
  return 63-__builtin_clzll(x);
}
const int maxbinom=60;
ll _dpbinom[maxbinom+1][maxbinom+1];
void initbinom() {
  const int n=maxbinom;
  // Caculate value of Binomial Coefficient in bottom up manner
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j == 0 || j == i) {_dpbinom[i][j] = 1;}
      else {_dpbinom[i][j] = _dpbinom[i-1][j-1] + _dpbinom[i-1][j];}
    }
  }
}
ll solve(ll lim, int want) {
  if (want==0) return 0;
  ll ans=0;
  if (__builtin_popcountll(lim)==want)ans++;
  for (int k=0;;k++) {
    ll head=lim>>k;
    if (head==0) break;
    if (head&1) {
      int have=__builtin_popcountll(head)-1;
      int need=want-have;
      if (need>=0) {
        ans+=_dpbinom[k][need];
      }
    }
  }
  return ans;
}
ll stu(int lim, int want) {
  int ans=0;
  for (int x=1;x<=lim;x++) {
    if (__builtin_popcount(x)==want) ans++;
  }
  return ans;
}
/*void test() {
  for (int lim=0;lim<=60;lim++) {
    for (int want=0;want<=40;want++) {
      printf("SOLVE\n");
      int so=solve(lim,want),st=stu(lim,want);
      if (so!=st) {
        printf("lim:%d want:%d so:%d st:%d\n",lim,want,so,st);
        exit(0);
      }
    }
  }
  printf("passed\n");
  exit(0);
}*/
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  initbinom();
  //test();
  ll n,t; cin>>n>>t;
  
  int logt=ilog2(t);
  if (t!=1LL<<logt) {
    printf("0\n"); return 0;
  }
  int ones=logt+1;
  ll ans=solve(n+1,ones)-solve(1,ones);
  printf("%lld\n",ans);

  //ll n=199;
  //ll ans=0;
  //for (int m=1;m<=n;m++) {
  //  int bfv=bf(m);
  //  int sv=smart(m);
  //  assert(bfv==sv);
  //}
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