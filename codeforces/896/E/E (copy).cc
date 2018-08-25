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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=100000;
int n;
int t[2 * mn];

int a[mn];
const int mg=317+1;
int sqrt_lidx[mg],sqrt_ridx[mg];
int sqrt_g[mn],sqrt_s[mn];
int h[mg][mn+1];
treapset<int> ts;
int gete(int p) {
  return a[ts[p]];
}
void sqrt_build() {
  int slim=round(sqrt(n));
  int glim=(n+slim-1)/slim;
  int rem=n-(glim-1)*slim;
  int idx=0;
  for (int g=0;g<glim;g++) {
    sqrt_lidx[g]=idx;
    int lim=(g==glim-1)?rem:slim;
    for (int s=0;s<lim;s++) {
      sqrt_g[idx]=g;
      sqrt_s[idx]=s;
      h[g][a[idx]]++;
      idx++;
    }
    sqrt_ridx[g]=idx-1;
  }
}
void sqrt_modify(int l, int r, int val) {
  int lg=sqrt_g[l],rg=sqrt_g[r];
  int re=gete(r);
  if (lg<rg) {
    h[rg][re]--;
    h[lg][re]++;
    for (int g=lg;g<rg;g++) {
      int idx=sqrt_ridx[g];
      int e=gete(idx);
      //printf("Modify g:%d e:%d\n",g,e);
      h[g][e]--;
      h[g+1][e]++;
    }
  }
}
int naive_query(int l, int r, int val) {
  int ans=0;
  for (int idx=l;idx<=r;idx++) {
    if (gete(idx)==val) ans++;
  }
  return ans;
}
int sqrt_query(int l, int r, int val) {
  int lg=sqrt_g[l],rg=sqrt_g[r];
  if (lg==rg) {
    return naive_query(l,r,val);
  }
  else {
    int ans=naive_query(l,sqrt_ridx[lg],val)+naive_query(sqrt_lidx[rg],r,val);
    //printf("naive:%d->%d:%d %d->%d:%d\n",l,sqrt_ridx[lg],naive_query(l,sqrt_ridx[lg],val),
    //  sqrt_lidx[rg],r,naive_query(sqrt_lidx[rg],r,val)
    //  );
    for (int g=lg+1;g<rg;g++) {
      ans+=h[g][val];
      //printf("Got g:%d ans:%d\n",g,queryh(g,val));
    }
    return ans;
  }
}



int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sqrt_build();
  n=rint(); int qlim=rint();
  for (int q=0;q<qlim;q++) {
    int t=rint(),l=rint()-1,r=rint()-1,x=rint();
    if (t==1) {
      modify(l,r,x);
    }
  }
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