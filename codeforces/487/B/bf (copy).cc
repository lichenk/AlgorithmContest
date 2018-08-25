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
const ll INF=1e9+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}

int segn;
void build(int *t) {  // build the tree
  int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(int *t, int p, int value) {  // set value at position p
  int n=segn;
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int *t, int l, int r) {  // sum on interval [l, r]
  r++;
  int n=segn;
  int res = INF;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) chkmin(res, t[l++]);
    if (r&1) chkmin(res, t[--r]);
  }
  return res;
}


class RmqSparseTable {

  int* logTable;
  int** rmq;
  int* a;
  int n;
  public:
  RmqSparseTable(int *_a, int _n) {
    a=_a;
    n=_n;

    logTable = new int[n + 1];
    fill(logTable,logTable+n+1,0);
    for (int i = 2; i <= n; i++)
      logTable[i] = logTable[i >> 1] + 1;

    rmq = new int*[logTable[n] + 1];
    for (int i=0;i<logTable[n] + 1;i++) {
      rmq[i]=new int[n];
    }
    for (int i = 0; i < n; ++i)
      rmq[0][i] = i;

    for (int k = 1; (1 << k) < n; ++k) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        int x = rmq[k - 1][i];
        int y = rmq[k - 1][i + (1 << k - 1)];
        rmq[k][i] = a[x] <= a[y] ? x : y;
      }
    }
  }

  int minPos(int i, int j) {
    int k = logTable[j - i];
    int x = rmq[k][i];
    int y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? x : y;
  }
  int minVal(int i, int j) {
    if (i>j) return INF;
    int k = logTable[j - i];
    int x = rmq[k][i];
    int y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? a[x] : a[y];
  }
};


int getmaxtake(int x, int s, int l, RmqSparseTable &tmin, RmqSparseTable &tmax) {
  int imin=l,imax=x+1+1;
  bool ok=0;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    int lo=tmin.minVal(x-imid+1,x);
    int hi=-tmax.minVal(x-imid+1,x);
    if (hi-lo<=s) {imin=imid+1; ok=1;}
    else imax=imid;
  }
  if (!ok) return -1;
  return imin-1;
}
const int mn=1e5+4;
int va[mn],vna[mn],tf[2*mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),s=rint(),l=rint();
  for (int i=0;i<n;i++) va[i]=rint();
  for (int i=0;i<n;i++) vna[i]=-va[i];
  RmqSparseTable tmin=RmqSparseTable(va,n);
  RmqSparseTable tmax=RmqSparseTable(vna,n);
  segn=n+1;
  for (int i=1;i<n;i++) tf[segn+i]=INF;
  build(tf);
  for (int x=l+1;x<=n;x++) {
    int gmt=getmaxtake(x-1,s,l,tmin,tmax);
    if (gmt==-1) continue;
    int L=x-gmt,R=x-l;
    assert(L<=R);
    int q=query(tf,L,R)+1;
    if (x==n) {
      if (q>=INF) printf("-1\n");
      else printf("%d\n",q);
      return 0;
    }
    modify(tf,x,q);
  }
  printf("-1\n");
}