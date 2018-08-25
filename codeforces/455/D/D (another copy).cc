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
#define DBG
#ifdef DBG
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif


int rint()
{
  int x; scanf("%d",&x); return x;
}

const int mn=100000;
const int mg=317+1;
int vblock[mg][mg];
vector<int> inflow[mg];
int g_leftshift[mg];
int n;
int vlidx[mg],vridx[mg],vslim[mg];
int vg[mn],vs[mn];
map<int,int> h[mg];
int gtimestamp=0;
inline void addh(int g, int val) {
  h[g][val]++;
}
inline void rmh(int g, int val) {
  auto it=h[g].find(val);
  if (it->snd==1) h[g].erase(it);
  else it->snd -=1;
}
inline int queryh(int g, int val) {
  auto it=h[g].find(val);
  if (it==h[g].end()) return 0;
  return it->snd;
}
int gete(int g, int s) {
  int news=s-g_leftshift[g];
  if (news<0) return inflow[g][-news-1];
  else return vblock[g][news];
}
int gete(int idx) {
  return gete(vg[idx],vs[idx]);
}
void commit(int g) {
  int slim=vslim[g];
  for (int s=slim;s>=0;s--) {
    vblock[g][s]=gete(g,s);
    dbg("Commit g:%d s:%d e:%d\n",g,s,gete(g,s));
  }
  g_leftshift[g]=0;
  inflow[g].clear();
  if (g>0) inflow[g].PB(gete(g-1,vslim[g-1]));
}
void sqrt_modify(int l, int r) {
  int lg=vg[l],rg=vg[r];
  int ls=vs[l],rs=vs[r];
  int re=gete(r);
  if (lg==rg) {
    int *block=vblock[lg];
    for (int s=rs;s>=ls+1;s--) {
      block[s]=block[s-1];
    }
    block[ls]=re;
  }
  else{
    rmh(rg,re);
    addh(lg,re);
    for (int g=lg;g<rg;g++) {
      int e=gete(g,vslim[g]);
      dbg("Modify g:%d e:%d\n",g,e);
      rmh(g,e);
      addh(g+1,e);
      inflow[g+1].PB(e);
    }
    commit(rg);
    for (int s=rs;s>=1;s--) {
      vblock[rg][s]=vblock[rg][s-1];
    }
    vblock[rg][0]=inflow[rg][0];
    commit(lg);
    for (int s=vslim[l];s>=ls+1;s--) {
      vblock[lg][s]=vblock[lg][s-1];
    }
    vblock[lg][ls]=re;
    for (int g=lg+1;g<rg;g++) g_leftshift[g]++;
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
  int lg=vg[l],rg=vg[r];
  if (lg==rg) {
    return naive_query(l,r,val);
  }
  else {
    int ans=naive_query(l,vridx[lg],val)+naive_query(vlidx[rg],r,val);
    for (int g=lg+1;g<rg;g++) {
      ans+=queryh(g,val);
    }
    return ans;
  }
}

int a[mn];
void sqrt_build() {
  gtimestamp=0;
  int slim=round(sqrt(n));
  int glim=(n+slim-1)/slim;
  int rem=n-(glim-1)*slim;
  int idx=0;
  for (int g=0;g<glim;g++) {
    if (g>0) inflow[g].PB(a[idx-1]);
    vlidx[g]=idx;
    int lim=(g==glim-1)?rem:slim;
    for (int s=0;s<lim;s++) {
      int val=a[idx];
      vg[idx]=g;
      vs[idx]=s;
      dbg("idx:%d g:%d s:%d\n",idx,g,s);
      h[g][val]++;
      vblock[g][s]=val;
      idx++;
    }
    vridx[g]=idx-1;
    vslim[g]=lim-1;
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int i=0;i<n;i++) {
    a[i]=rint();
  }
  sqrt_build();
  int q=rint();
  int lastans=0;
  for (int i=0;i<q;i++) {
    int t=rint(),lp=rint(),rp=rint();
    int l=lp+lastans-1; if (l>=n) l-=n;
    int r=rp+lastans-1; if (r>=n) r-=n;
    if (l>r) swap(l,r); 
    if (t==1) {
      sqrt_modify(l,r);
    }
    else {
      int kp=rint();
      int k=kp+lastans-1; if (k>=n) k-=n;
      k++;
      //printf("l:%d r:%d k:%d\n",l,r,k);
      //lastans=sqrt_query(l,r,k);
      lastans=naive_query(l,r,k); //printf("\nNAIVE\n");
      printf("%d\n",lastans);
    }
    for (int idx=0;idx<n;idx++) {
      printf("%d ",gete(idx));
    }
    printf("\n");
  }
}