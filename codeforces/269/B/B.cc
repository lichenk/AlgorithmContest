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
const int INF=1e9;
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

const int mn=5e3+8;
int vt[mn];
//int suf[mn][mn];
int f[mn][mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m; cin>>n>>m;
  for (int i=1;i<=n;i++) {
    double xi;
    cin>>vt[i]>>xi;
  }
  /*for (int i=1;i<=n;i++) {
    suf[vt[i]][i]++;
  }
  for (int t=1;t<=m;t++) {
    for (int x=n-1;x>=0;x--) suf[t][x]+=suf[t][x+1];
  }*/
  for (int pos=1;pos<=n;pos++) {
    int best=f[pos-1][0];
    for (int t=0;t<=m;t++) {
      chkmin(best, f[pos-1][t]);
      int cand=best+((vt[pos]!=t)?1:0);
      f[pos][t]=cand;
      //printf("pos:%d t:%d cand:%d\n",pos,t,cand);
    }
  }
  int final=f[n][0];
  for (int t=0;t<=m;t++) {
    chkmin(final,f[n][t]);
  }
  printf("%d\n",final);
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