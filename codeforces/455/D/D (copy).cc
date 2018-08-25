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


int rint()
{
  int x; scanf("%d",&x); return x;
}

const int mn=100000;
const int mg=317+1;
int _block[mn][mg];
int _block_id=0;
int *alloc() {
  return _block[_block_id++];
}
vector<pair<int,int*> > vblock[mg];
int g_leftshift[mg];
int g_last_upd_timestamp[mg];
int n;
int a[mn];
int sqrt_lidx[mg],sqrt_ridx[mg];
int sqrt_g[mn],sqrt_s[mn];
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
int *get_alloced_block_for_g(int timestamp, int g) {
  int sz=vblock[g].size();
  int imin=0,imax=sz;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vblock[g][imid].fst<=timestamp) imin=imid+1;
    else imax=imid;
  }
  //printf("get alloced timestamp:%d g:%d imin-1:%d foundts:%d resp:%x\n",timestamp,g,imin-1,vblock[g][imin-1].fst,vblock[g][imin-1].snd);
  return vblock[g][imin-1].snd;
}

int gete(int idx) {
  int g=sqrt_g[idx];
  int timestamp=g_last_upd_timestamp[g];
  int leftshift=g_leftshift[g];
  if (leftshift==0) {
    //printf("idx:%d g:%d s:%d e:%d block:%x front:%d\n",idx,g,sqrt_s[idx],vblock[g].back().snd[sqrt_s[idx]],vblock[g].back().snd,vblock[g].back().fst);
    return vblock[g].back().snd[sqrt_s[idx]];
  }
  int src_idx=idx-leftshift;
  int src_g=sqrt_g[src_idx];
  int src_s=sqrt_s[src_idx];
  //printf("idx:%d src_idx:%d src_g:%d src_s:%d timestamp:%d\n",idx,src_idx,src_g,src_s,timestamp);
  int *block=get_alloced_block_for_g(timestamp, src_g);
  return block[src_s];
}
void commit_new_revision_for_g(int g) {
  int leftshift=g_leftshift[g];
  int prevg=-1;
  int *fresh_block=alloc();
  int *block;
  int timestamp=g_last_upd_timestamp[g];
  //printf("Commit g:%d with last ts:%d nts:%d\n",g,timestamp,gtimestamp+1);
  int l=sqrt_lidx[g],r=sqrt_ridx[g];
  for (int idx=l;idx<=r;idx++) {
    int src_idx=idx-leftshift;
    int src_g=sqrt_g[src_idx],src_s=sqrt_s[src_idx];
    if (src_g!=prevg) {
      prevg=src_g;
      block=get_alloced_block_for_g(timestamp, src_g);
    }
    //printf("Commit g:%d idx:%d src_g:%d src_s:%d e:%d\n",g,idx,src_g,src_s,block[src_s]);
    //printf("idx:%d got:%d\n",idx,block[src_s]);
    fresh_block[idx-l]=block[src_s];
  }
  ++gtimestamp;
  g_last_upd_timestamp[g]=gtimestamp;
  g_leftshift[g]=0;
  vblock[g].PB(MP(gtimestamp, fresh_block));
  //printf("Commit end\n");
}
void sqrt_modify(int l, int r) {
  //printf("Modify:%d-%d\n",l,r);
  int lg=sqrt_g[l],rg=sqrt_g[r];
  int ls=sqrt_s[l],rs=sqrt_s[r];
  int re=gete(r);
  if (lg==rg) {
    commit_new_revision_for_g(lg);
    int *block=vblock[lg].back().snd;
    for (int s=rs;s>=ls+1;s--) {
      block[s]=block[s-1];
    }
    block[ls]=re;
  }
  else{
    rmh(rg,re);
    addh(lg,re);
    for (int g=lg;g<rg;g++) {
      int idx=sqrt_ridx[g];
      int e=gete(idx);
      //printf("Modify g:%d e:%d\n",g,e);
      rmh(g,e);
      addh(g+1,e);
    }
    commit_new_revision_for_g(lg);
    commit_new_revision_for_g(rg);
    {
      int *block=vblock[rg].back().snd;
      //printf("Rotr:%x rg:%d\n",block,rg);
      for (int s=rs; s>=1;s--) {
        block[s]=block[s-1];
      }
      block[0]=gete(sqrt_lidx[rg]-1);
    }
    {
      int *block=vblock[lg].back().snd;
      //printf("Rotl:%x lg:%d\n",block,lg);
      for (int idx=sqrt_s[sqrt_ridx[lg]]; idx>=ls+1;idx--) {
        block[idx]=block[idx-1];
      }
      block[ls]=re;
      //printf("ls:%d re:%d\n",ls,re);
    }
    for (int g=lg+1;g<rg;g++) {
      g_leftshift[g]++;
    }
  }
}
void sqrt_build() {
  gtimestamp=0;
  int slim=round(sqrt(n));
  int glim=(n+slim-1)/slim;
  int rem=n-(glim-1)*slim;
  int idx=0;
  for (int g=0;g<glim;g++) {
    sqrt_lidx[g]=idx;
    int lim=(g==glim-1)?rem:slim;
    int *block = alloc();
    for (int s=0;s<lim;s++) {
      int val=a[idx];
      sqrt_g[idx]=g;
      sqrt_s[idx]=s;
      h[g][val]++;
      block[s]=val;
      printf("g:%d s:%d idx:%d a:%d\n",g,s,idx,a[idx]);
      idx++;
    }
    //printf("g:%d timestamp:%d block:%x b0:%d\n",g,timestamp,block,block[0]);
    vblock[g].PB(MP(gtimestamp, block));
    sqrt_ridx[g]=idx-1;
  }
}
int naive_query(int l, int r, int val) {
  int ans=0;
  for (int idx=l;idx<=r;idx++) {
    //printf("idx:%d e:%d val:%d\n",idx,gete(idx),val);
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
      ans+=queryh(g,val);
      //printf("Got g:%d ans:%d\n",g,queryh(g,val));
    }
    return ans;
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