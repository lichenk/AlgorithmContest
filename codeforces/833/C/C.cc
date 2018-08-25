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
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
const int mn=18+9;
int C[mn+1][mn+1];

struct S {
  int c[10];
  void clr() {memset(c,0,sizeof c);}
};
// Caculate value of Binomial Coefficient in bottom up manner
void initbinom(int n) {
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      // Base Cases
      if (j == 0 || j == i) C[i][j] = 1;
      // Calculate value using previosly stored values
      else C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
}
void idx2binom(int idx, int n, int k, S &ans) {
  memset(ans.c,0,sizeof ans.c);
  int prev=0;
  for (int x=n-1;x>=0;x--) {
    int zerocnt=C[x][k];
    if (idx>=zerocnt) {
      idx-=zerocnt;
      ans.c[k]=prev;
      prev=0;
      k--;
    }
    else prev++;
  }
}
struct ST {
  int c[10];
  int lo, hi,extra;
  void clr() {memset(c,0,sizeof c);}
};
ll pten[19];
int digl[19],digr[19];
vector<ST> vcand;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  /*for (int nd=1;nd<=9;nd++) {
    ll z=(1LL<<(nd*K));
    fgen(z,nd,1);
  }*/
  //printf("sz:%d\n",vgen.size());
  ll L=rlong()-1,R=rlong()+1;
  pten[0]=1;
  for (int i=1;i<19;i++) pten[i]=pten[i-1]*10;
  for (int x=18;x>=0;x--) {
    ll pt=pten[x];
    digl[x]=(L/pt)%10;
    digr[x]=(R/pt)%10;
  }
  ST pre; pre.clr();
  ST pl,pr;
  for (int x=18;x>=0;x--) {
    if (digl[x]!=digr[x]) {
      ST o=pre;
      o.lo=digl[x]+1;
      o.hi=digr[x]-1;
      o.extra=x;
      if (o.lo<=o.hi) vcand.PB(o);
      pl=pre;pr=pre;
      pl.hi=9;
      pr.lo=0;
      for (int y=x;y>=1;y--) {
        pl.c[digl[y]]++;
        pl.lo=digl[y-1]+1;
        pr.c[digr[y]]++;
        pr.hi=digr[y-1]-1;
        pl.extra=pr.extra=y-1;
        if (pl.lo<=pl.hi) vcand.PB(pl);
        if (pr.lo<=pr.hi) vcand.PB(pr);
      }
      break;
    }
    pre.c[digl[x]]++;
  }
  /*for (auto &cand:vcand) {
    for (int d=1;d<=9;d++) {
      if (cand.c[d])printf("(%d, %d) ",d,cand.c[d]);
    }
    printf("lo:%d hi:%d end cand\n",cand.lo,cand.hi);
  }*/
  initbinom(18+9);
  int final=0;
  S req;
  for (int ii=0;ii<C[18+9][9];ii++) {
    idx2binom(ii,18+9,9,req);
    //for (int d=1;d<=9;d++) {
    //  if (req.c[d])printf("(%d, %d) ",d,req.c[d]);
    //}
    //printf("\n");
    for (auto &cand:vcand) {
      int need=0;
      bool hasres=1;
      bool bad=false;
      for (int d=1;d<=9;d++) {
        int nd=req.c[d]-cand.c[d];
        if (nd<0) {
          bad=true; break;
        }
        if (nd>0) {
          if (hasres&&cand.lo<=d&&d<=cand.hi) {
            nd--; hasres=0;
          }
          need+=nd;
        }
      }
      if (cand.lo==0) hasres=0;
      if (bad||hasres) continue;
      if (need<=cand.extra) {
        //for (int d=1;d<=9;d++) {
        //  if (req.c[d])printf("(%d, %d) ",d,req.c[d]);
        //}
        //printf("\n");
    //for (int d=1;d<=9;d++) {
    //  if (cand.c[d])printf("(%d, %d) ",d,cand.c[d]);
    //}
    //printf("lo:%d hi:%d extra:%d end cand\n",cand.lo,cand.hi,cand.extra);
        final++;
        break;
      }
    }
  }
  printf("%d\n",final);
}
