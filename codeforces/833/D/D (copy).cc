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



const int mn=1e5+8;
vector<int> g[mn];
int vdest[2*mn],vval[2*mn],vc[2*mn];
bool iscentroid[mn];
int getCentroid(int u,int p,int n) {
    int cnt = 1;
    bool goodCenter = true;
    for (auto wi : g[u]) {
      int w=vdest[wi];
      int v=w;
      if (v == p||iscentroid[v]) continue;
      int res = getCentroid(v, u, n);
      if (res >= 0)
        return res;
      int size = -res;
      goodCenter &= size <= n / 2;
      cnt += size;
    }
    goodCenter &= n - cnt <= n / 2;
    return goodCenter ? u : -cnt;
  }
int getSubtreeSize(int x,int p) {
  int selfSubtreeSize=1;
  for (auto &wi:g[x]) {
    int w=vdest[wi];
    int y=w;
    if (y==p||iscentroid[y]) continue;
    int childSubtreeSize=getSubtreeSize(y,x);
    selfSubtreeSize+=childSubtreeSize;
  }
  return selfSubtreeSize;
}

/* Custom functions go here */
inline ll MK(int x, int y) {
  return ((ll)x<<32)|y;
}
inline int mul(int x, int y) {
  return (x*(ll)y)%MOD;
}
const int mod=MOD;
int mod_pow(int a, int n) {int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
vector<pair<pii,int> > h;
void dfs(int x, int p, int prod, int e0, int e1) {
  h.PB(MP(MP(e0,e1),prod));
  for (auto &yi:g[x]) {
    int y=vdest[yi];
    if (y==p||iscentroid[y]) continue;
    int c=vc[yi],val=vval[yi];
    int ne0=e0,ne1=e1;
    if (c==0) ne0++; else ne1++;
    int nprod=mul(prod,val);
    dfs(y,x,nprod,ne0,ne1);
  }
}
const int MAXN=4*mn;
struct FenwickAdd{
public:
int t[MAXN]; // MAXN = maxindex + 1
int fn,fn2;
int fseen[MAXN];
int use[MAXN];
int usesz=0;
int gts=0;
void init(int n) {
  fn=n;
  fn2=2*n;
  gts++;
  usesz=0;
}
inline int trans(int i) {
  return fn-i;
}
// T[i] += value
void add(int k, int value) {
  int i=trans(k);
  use[usesz++]=i;
  for (; i < fn2; i |= i + 1)
    t[i] += value;
}
// sum[0..i]
int sum(int k) {
  int i=trans(k);
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res += t[i];
  return res;
}
void sset(int i) {
  int orig = sum(i)-sum(i-1);
  add(i,-orig);
}
void deinit() {
  for (int j=0;j<usesz;j++) {
    int i=use[j];
    if (fseen[i]!=gts) {
      fseen[i]=gts;
      sset(trans(i));
    }
  }
}
};
FenwickAdd f[2];
struct FenwickMul{
public:
int t[MAXN]; // MAXN = maxindex + 1
int fn,fn2;
int fseen[MAXN];
int use[MAXN];
int usesz=0;
int gts=0;
void init(int n) {
  fn=n;
  fn2=2*n;
  gts++;
  usesz=0;
}
inline int trans(int i) {
  return fn-i;
}
// T[i] += value
void add(int k, int value) {
  int i=trans(k);
  use[usesz++]=i;
  for (; i < fn2; i |= i + 1)
    t[i] = mul(t[i],value);
}
// sum[0..i]
int sum(int k) {
  int i=trans(k);
  int res = 1;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res = mul(res,t[i]);
  return res;
}
void sset(int i) {
  int orig = mul(mod_pow(sum(i),MOD-2),sum(i-1));
  add(i,orig);
}
void deinit() {
  for (int j=0;j<usesz;j++) {
    int i=use[j];
    if (fseen[i]!=gts) {
      fseen[i]=gts;
      sset(trans(i));
    }
  }
}
};
FenwickMul m[2];
int final=1;
/* Custom functions end here */

void fullCentroidDecomposition(int initv,int p,int n) {
  int centroid=getCentroid(initv,p,n);
  vector<pii> subtreeRootsWithSizes;
  int allsize=0;
  for (auto &wi:g[centroid]) {
    int w=vdest[wi];
    int y=w;
    if (y!=p&&(!iscentroid[y])) {
      int sz=getSubtreeSize(y,centroid);
      allsize+=sz;
      subtreeRootsWithSizes.PB(MP(y,sz));
    }
  }
  /* Custom code starts here. Should take linear time. Do not consider nodes with iscentroid=true, or nodes beyond them.*/
  for (int q=0;q<2;q++) {
    f[q].init(2*(allsize+1));
    //f[q].add(0,1);
    m[q].init(2*(allsize+1));
  }
  int x=centroid;
  for (auto &yi:g[centroid]) {
    {
      int y=vdest[yi];
      if (iscentroid[y]) continue;
      int c=vc[yi],yval=vval[yi];
      int e0=0,e1=0;
      int ne0=e0,ne1=e1;
      if (c==0) ne0++; else ne1++;
      int nprod=yval;
      h.clear();
      dfs(y,x,nprod,ne0,ne1);
    }
    for (auto &w:h) {
      int e0=w.fst.fst,e1=w.fst.snd,val=w.snd;
      if (e0<=4||e1<=4) {
        for (int oe0=0;oe0<=4;oe0++) {
          for (int oe1=0;oe1<=4;oe1++) {
            int s0=e0+oe0,s1=e1+oe1;
            if (s0)
          }
        }
      }
      else {
        for (int q=0;q<2;q++) {
          int delta=w.fst,val=w.snd;
          int gotcnt=f[q].sum(-delta);
          int gotprod=m[q].sum(-delta);
          int powup=mod_pow(val,gotcnt);
          int prod=mul(powup, gotprod);
          printf("x:%d y:%d q:%d delta:%d val:%d gotcnt:%d gotprod:%d powup:%d prod:%d\n",x,y,q,delta,val,gotcnt,gotprod,powup,prod);
          final=mul(final, prod);
        }
      }
    }
    for (int q=0;q<2;q++) {
      for (auto &w:h[q]) {
        int delta=w.fst,val=w.snd;
        int gotcnt=f[q].sum(-delta);
        int gotprod=m[q].sum(-delta);
        int powup=mod_pow(val,gotcnt);
        int prod=mul(powup, gotprod);
        printf("x:%d y:%d q:%d delta:%d val:%d gotcnt:%d gotprod:%d powup:%d prod:%d\n",x,y,q,delta,val,gotcnt,gotprod,powup,prod);
        final=mul(final, prod);
      }
      for (auto &w:h[q]) {
        int delta=w.fst,val=w.snd;
        f[q].add(delta,1);
        m[q].add(delta,val);
      }
    }
  }
  for (int q=0;q<2;q++) {f[q].deinit(); m[q].deinit();}
  /* Custom code ends here. Continue decomposing subtree.*/
  iscentroid[centroid]=true;
  for (auto &got:subtreeRootsWithSizes) {
    fullCentroidDecomposition(got.first,centroid,got.second);
  }
}
int eid=0;
void ae(int x, int y, int val, int c) {
  g[x].PB(eid);
  vdest[eid]=y;
  vval[eid]=val;
  vc[eid]=c;
  eid++;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n-1;i++) {
    int u=rint(),v=rint(),val=rint(),c=rint();
    ae(u,v,val,c);
    ae(v,u,val,c);
  }
  for (int q=0;q<2;q++) {
    for (int i=0;i<MAXN;i++) m[q].t[i]=1;
  }
  fullCentroidDecomposition(1,-1,n);
  printf("%d\n",final%MOD);
}