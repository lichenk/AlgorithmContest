#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

template<int _SEGSZ> class SegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef ll S;
  S t[2 * SEGSZ];
  S identity = 0;
  S combine(const S& lefts, const S& rights) {
    return lefts+rights;
  }
  void init(int n) {segn=n;}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  S query(int l, int r) { // sum on interval [l, r]
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
};

template<int _SEGSZ> class PolySegTree {
public:
  SegTree<_SEGSZ*2> seg[3];
  int n;
  vi inp;
  void init(vi a) {
    n=a.size();
    inp=a; inp.resize(2*n); for (int i=0;i<n;i++) inp[i+n]=inp[i];
    for (int k=0;k<3;k++) {seg[k].init(2*n);}
    //for (int i=0;i<n;i++) printf("%d, ",a[i]); printf("\n");
    for (int i=0;i<2*n;i++) {
      int ai=(i>=n)?a[i-n]:a[i];
      seg[0].t[2*n+i]=ai;
      seg[1].t[2*n+i]=i*(ll)ai;
      seg[2].t[2*n+i]=(i*i)*(ll)ai;
      //printf("%d, ",ai);
    }
    //printf("\n");
    for (int k=0;k<3;k++) {seg[k].build();}
  }
  void sset(int pos, ll val) {
    inp[pos]=val;
    for (int k=0;k<3;k++) {
      seg[k].sset(pos,val);
      val*=pos;
    }
  }
  ll sum0(int l,int r) {
    if (r<l) r+=n;
    ll ans=seg[0].query(l,r);
    ll bf=0; for (int x=l;x<=r;x++) bf+=inp[x];
    assert(bf==ans);
    return ans;
  }
  ll sum1(int l,int r) {
    if (r<l) r+=n;
    ll ans=seg[1].query(l,r) - (l-1)*seg[0].query(l,r);
    ll bf=0; for (int x=l;x<=r;x++) bf+=(x-l+1)*inp[x];
    //printf("s0:%lld s1:%lld l:%d r:%d ans:%lld bf:%lld\n",seg[0].query(l,r),seg[1].query(l,r),l,r,ans,bf); fflush(stdout);
    assert(bf==ans);
    return ans;
  }
  ll sum2(int l,int r) {
    if (r<l) r+=n;
    ll ans=seg[2].query(l,r) - (l-1)*((l-1)*seg[0].query(l,r) + 2*sum1(l,r));
    ll bf=0; for (int x=l;x<=r;x++) bf+=(x-l+1LL)*(x-l+1LL)*((ll)inp[x]);
    //printf("l:%d r:%d ans:%lld bf:%lld s2:%lld\n",l,r,ans,bf,seg[2].query(l,r)); fflush(stdout);
    assert(bf==ans);
    return ans;
  }
};


long long ccw(pii a, pii b, pii c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	return b.first * (long long)c.second - c.first * (long long)b.second;
}
long long cross(pii b, pii c) {
  return b.first * (long long)c.second - c.first * (long long)b.second;
}
pii gcenter;
int vq[3][3]={
  {5,4,3},
  {6,-1,2},
  {7,0,1}
};
int quarter(pii a) {
  int x=(a.fst>0?1:0)+(a.fst>=0?1:0),y=(a.snd>0?1:0)+(a.snd>=0?1:0);
  return vq[x][y];
}

bool cmp(pii a, pii b) {
  a.fst-=gcenter.fst;
  b.fst-=gcenter.fst;
  a.snd-=gcenter.snd;
  b.snd-=gcenter.snd;
  int aq=quarter(a),bq=quarter(b);
  if (aq==bq) {
    return cross(a,b) > 0;
  }
	return aq<bq;
}


ll magic3(ll C, ll n) {
  // sum ((C+k) choose 3) from k=0 to k=n
  //1/24 (n + 1) (2 C + n - 2) (2 C^2 + 2 C (n - 2) + (n - 1) n)
  if (n<0) return 0;
  return ((n + 1)*(2*C + n - 2)*(2*C*C + 2*C*(n - 2) + (n - 1)*n))/24;
}

const int mn=2002;
pii vinp[mn];
pii vp[mn];
PolySegTree<mn> sg,sg2;
vi oppc, oppc2, oppi, semi;
vi _oppc,_oppc2;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int gn=rint();
  for (int i=0;i<gn;i++) {
    int x=rint(); int y=rint();
    vinp[i]=MP(x,y);
  }
  {
    int n=gn-1;oppc.resize(n);  oppi.resize(n); semi.resize(n); oppc2.resize(n);
  }
  ll final=0;
  for (int a=0;a<gn;a++) {
  	gcenter=vinp[a];
    int j=0;
    for (int i=0;i<gn;i++) if (i!=a) vp[j++]=vinp[i];
    int n=gn-1;
  	sort(vp,vp+n,cmp);
    //for (int lo=0;lo<n;lo++) printf("a:%d. %d %d\n",a,vp[lo].fst,vp[lo].snd);
    {
      int lo=0;
      while(ccw(gcenter,vp[lo],vp[n-1])<0) {
        //printf("lo: %d %d\n",vp[lo].fst,vp[lo].snd);
        ++lo;
      }
      //printf("initlo: %d %d\n",vp[lo].fst,vp[lo].snd);
      for (int hi=0;hi<n;hi++) {
        int got=0;
        while(ccw(gcenter,vp[lo],vp[hi])<0) {
          //printf("hi:%d %d. lo: %d %d\n",vp[hi].fst,vp[hi].snd,vp[lo].fst,vp[lo].snd);
          ++lo; ++got; if (lo==n) lo=0;
        }
        // lo is the first point that has ccw <=0
        oppc[hi]=got;
        oppc2[hi]=got*(ll)got;
        oppi[hi]=lo;
        semi[hi]=hi-lo; if (semi[hi]<0) semi[hi]+=n;
        //printf("hi:%d %d lo:%d %d got:%d oppc:%d\n",vp[hi].fst,vp[hi].snd,vp[lo].fst,vp[lo].snd,got,oppc[hi]);
      }
    }
    {
      sg.init(oppc); sg2.init(oppc2);
      _oppc=oppc;_oppc2=oppc2;
      for (auto &w:oppc) printf("%d ",w); printf(" end oppc\n");
      //for (auto &w:oppc2) printf("%d ",w); printf(" end oppc2\n");
      for (int l=0;l<n;l++) {
        int lp=oppi[l];
        {
          int opplp=oppi[lp];
          ll lpc=max(0,(opplp<l?(opplp+n):opplp)-l-1);
          printf("center:%d %d l:%d %d lp:%d %d opplp:%d %d lpc:%lld\n",
            gcenter.fst,gcenter.snd,
            vp[l].fst,vp[l].snd,
            vp[lp].fst,vp[lp].snd,
            vp[opplp].fst,vp[opplp].snd,lpc
          );
          sg.sset(lp,lpc);
          sg2.sset(lp,lpc*lpc);
        }
        int r=l-1; if (r<0) r+=n;
        ll total=magic3(n-semi[l]-1, semi[l]-2);
        printf("total:%lld %d %d\n",
          total,n-semi[l]-1, semi[l]-2);
        //printf("center:%d %d.l:%d %d. semi[l]:%d\n",gcenter.fst,gcenter.snd,vp[l].fst,vp[l].snd,semi[l]);
        int C=n-semi[l];
        ll sub1=(sg.sum1(lp,r)-sg.sum0(lp,r))*semi[l];
        sub1-=(sg.sum2(lp,r) - sg.sum1(lp,r));
        ll sub2=semi[l]*(C*sg.sum0(lp,r) - sg2.sum0(lp,r));
        sub2-=(C*sg.sum1(lp,r) - sg2.sum1(lp,r));
        ll sub3=semi[l]*((sg2.sum0(lp,r) - sg.sum0(lp,r)));
        sub3-=((sg2.sum1(lp,r) - sg.sum1(lp,r)));
        assert(sub3%2==0);
        sub3/=2;
        ll sub=sub1+sub2+sub3;
        ll got=total-sub;
        printf("lp:%d r:%d C:%d semi[l]:%d sub1: %lld sub2: %lld sub3: %lld sub: %lld total:%lld\n",
          lp,r,C,semi[l],sub1,sub2,sub3,sub,total);
        printf("Semi: %d\n",n-1-semi[l]);
        printf("lp:%d r:%d sum2:%lld sum1:%lld\n",lp,r,sg.sum2(lp,r),sg.sum1(lp,r));
        printf("center:%d %d. l:%d %d got:%lld\n",gcenter.fst,gcenter.snd,vp[l].fst,vp[l].snd,got);
        //printf("center:%d %d l:%d %d total:%lld sub:%lld semi[l]:%d semi[lp]:%d\n",
        //  gcenter.fst,gcenter.snd,vp[l].fst,vp[l].snd,total,sub,semi[l],semi[lp]);
        fflush(stdout);
        assert(got>=0);
        final+=got;
        {
          int lp=oppi[l];
          sg.sset(lp,_oppc[lp]);
          sg2.sset(lp,_oppc2[lp]);
        }
      }
    }
    //exit(0);
  }
  assert(final%18==0);
  printf("%lld\n",final/18);

}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}