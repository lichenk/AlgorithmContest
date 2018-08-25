#include "bits/stdc++.h"
#include <assert.h>
using namespace __gnu_pbds;
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

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

const int MAXN = 2e5+2;

const int mx=MAXN;
typedef set UFTYPE;
class UnionFind {
public:
    int ufParent[mx];
    UFTYPE ufData[mx];
    int vl[mx],vr[mx];
    int lastlcp[mx];
    void init(int n) {
      for (int x=0;x<n;x++) {
        ufParent[x]=x;
        vl[x]=x;
        vr[x]=x;
      }
    }
    int ffind(int x) {
      if (ufParent[x] != x) {
        ufParent[x] = ffind(ufParent[x]);
      }
      return ufParent[x];
    }
    int funion(int _x, int _y) {
      int xr = ffind(_x);
      int yr = ffind(_y);
      if (xr==yr) return;
      if (ufData[xr].size() > ufData[yr].size()) swap(xr,yr);
      if (rank[xr]==rank[yr]) rank[yr]++;
      ufParent[xr] = yr;
      chkmin(vl[yr], vl[xr]);
      chkmax(vr[yr], vr[xr]);
      for (auto &w:ufData[xr]) ufData[yr].insert(w);
      return yr;
    }
};



int S[MAXN];
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN], revsa[MAXN];

bool sufCmp(int i, int j)
{
  if (pos[i] != pos[j])
    return pos[i] < pos[j];
  i += gap;
  j += gap;
  return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA(int stringlen)
{
  N = stringlen;
  REP(i, N) sa[i] = i, pos[i] = S[i];
  for (gap = 1;; gap *= 2)
  {
    sort(sa, sa + N, sufCmp);
    REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
    REP(i, N) pos[sa[i]] = tmp[i];
    if (tmp[N - 1] == N - 1) break;
  }
}

void buildLCP()
{
  for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
    {
      for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
        ++k;
      lcp[pos[i]] = k;
      if (k)--k;
    }
}
void buildREVSA() {
  for (int i=0;i<N;i++) revsa[sa[i]]=i;
}

vector<int> vlen2lcp[MAXN];
const int mc=1e5+2;
UnionFind uf;
char tmp[mc];
const int SPLITTER=1000000;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tn,k; scanf("%d %d\n",&tn,&k);
  int sidx=0;
  for (int ti=0;ti<tn;ti++) {
    ti2sidx[ti]=sidx;
    scanf("%s\n",tmp);
    int tlen=strlen(tmp);
    ti2tlen[ti]=tlen;
    for (int i=0;i<tlen;i++) {
      S[sidx++]=tmp[i];
    }
    S[sidx++]=SPLITTER+ti;
  }
  int slen=sidx;
  buildSA(slen);
  buildREVSA();
  buildLCP();
  for (int i=0;i<slen;i++) {
    vlen2lcp[lcp[i]].PB(i);
  }
  uf.init(slen);
  for (int ti=0;ti<tn;ti++) {
    int xs=ti2sidx[ti];
    int xe=xs+ti2tlen[ti];
    for (int x=xs;x<xe;x++) {
      int saidx = revsa[x];
      uf.ufData[saidx].insert(ti);
    }
  }
  for (int len=MAXN-1;len>=1;len--) {
    for (auto &saidx:vlen2lcp[len]) {
      int xr=ffind(saidx);
      int yr=ffind(saidx+1);
      if (uf.ufData[xr].size()<k && uf.ufData[yr].size()<k) {
        uf.lastlcp[xr]=len;
        uf.lastlcp[yr]=len;
        uf.funion(xr,yr);
      }
    }
  }
  for (int ti=0;ti<tn;ti++) {
    int xs=ti2sidx[ti];
    int xe=xs+ti2tlen[ti];
    ll final=0;
    for (int pos=xs;pos<xe;pos++) {
      int xx=revsa[pos];

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