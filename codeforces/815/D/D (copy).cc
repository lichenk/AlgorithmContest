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
const int UNDEF = -1;
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
const int mn=500000+4;

class RemovalClass {
  int cnt[mn];
  int idx=mn-1;
public:
  void add(int x) {
    cnt[x]++;
  }
  void rm(int x) {
    cnt[x]--;
  }
  int get() {
    while(cnt[idx]==0) idx--;
    return idx;
  }
};

RemovalClass pqb,pqc;
int alim,blim,clim;
int n;
ll live=0;
void ins(map<int,int,greater<int> > &b2c, const int b, const int c, const int bfloor, const int cfloor, const bool modlive) {
  auto jt=b2c.upper_bound(b);
  if (jt!=b2c.begin()) {
    --jt;
    if (jt->fst>=b&&jt->snd >= c) return;
  }
  auto it=b2c.find(b);
  int nc=c,oc=0;
  if (it!=b2c.end()) {
    if (it->snd >= c) return;
    oc=it->snd;
    it->snd=c;
  }
  else it=b2c.insert(MP(b,c)).fst;
  printf("Now: %d->%d. %d %d\n",it->fst,it->snd, b,c);
  for (auto &w:b2c) printf("%d->%d\n",w.fst,w.snd);
  fflush(stdout);
  ++it;
  int lastb=b;
  while (it!=b2c.end()) {
    printf("Iterate: %d %d\n",it->fst,it->snd);
    fflush(stdout);
    if (modlive) {
      printf("oc:%d nc:%d itfst:%d lastb:%d\n",oc,nc,it->fst,lastb);
      ll add=(max(nc,cfloor)-max(oc,cfloor))*(ll)(max(it->fst,bfloor)-max(lastb,bfloor));
      printf("(%d-%d)*(%d-%d)=%lld\n",
        max(nc,cfloor),max(oc,cfloor),max(it->fst,bfloor),max(lastb,bfloor),add);
      live+=add;
    }
    if (it->snd<=c) {
      oc=it->snd;
      it=b2c.erase(it);
    }
    else break;
  }
}
void addb(map<int,int,greater<int> > &b2c, const int b, const int cfloor, const int clim) {
  auto jt=b2c.upper_bound(b);
  if (jt!=b2c.begin()) {
    --jt;
    if (jt->fst>=b) {
      printf("addb b:%d clim:%d - jtsnd:%d\n",b,clim,jt->snd);
      live+=max(0,clim-jt->snd+1);
      return;
    }
  }
  live+=clim-cfloor+1;
  printf("addb b:%d clim:%d - cfloor:%d\n",b,clim,cfloor);
}
int bfloor,cfloor;
vector<int> a2i[mn];
map<int,int,greater<int> > b2c,c2b;
int vb[mn],vc[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=rint(),alim=rint(),blim=rint(),clim=rint();
  pqb.add(1); pqc.add(1);
  for (int i=0;i<n;i++) {
    int a=rint()+1,b=rint()+1,c=rint()+1;
    vb[i]=b,vc[i]=c;
    a2i[a].PB(i);
    pqb.add(b); pqc.add(c);
  }
  bfloor=pqb.get(),cfloor=pqc.get();
  b2c[0]=cfloor; b2c[bfloor]=0;
  c2b[0]=bfloor; c2b[cfloor]=0;
  live=(blim-bfloor+1)*(ll)(clim-cfloor+1);
  ll ans=0;
  for (int i=0;i<n;i++) {
      int b=vb[i],c=vc[i];
      printf("b2c\n");
      ins(b2c,b,c,bfloor,cfloor,true);
      printf("c2b\n");
      ins(c2b,c,b,cfloor,bfloor,false);    
  }
  for (int a=1;a<=alim;a++) {
    for (auto &i:a2i[a]) {
      int b=vb[i],c=vc[i];
      pqb.rm(b);pqc.rm(c);
    }
    int newbfloor=pqb.get();
    printf("ADDB\n");
    printf("bfloor:%d nbf:%d\n",bfloor,newbfloor);
    for (int b=bfloor-1;b>=newbfloor;b--) {
      addb(b2c,b,cfloor,clim);
    }
    bfloor=newbfloor;
    printf("ADDC\n");
    int newcfloor=pqc.get();
    for (int c=cfloor-1;c>=newcfloor;c--) {
      addb(c2b,c,bfloor,blim);
    }
    cfloor=newcfloor;
    printf("a:%d live:%lld\n",a,live);
    ans+=live;
  }
  printf("%lld\n",ans);
}

