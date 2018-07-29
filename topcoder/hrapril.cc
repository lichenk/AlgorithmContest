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
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vii;
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

int readInt()
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


const double pi=acos(-1);
const int mn=2e5+8;
const int mxn=4e5+16;
struct point
{
  double x,y;
  point(double _x=0,double _y=0){x=_x;y=_y;}
  point operator+(const point &t)const{return point(x+t.x,y+t.y);}
  point operator-(const point &t)const{return point(x-t.x,y-t.y);}
  point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
  point operator*(const double &t)const{return point(x*t,y*t);}
};
point makeunit(double x){return point(cos(x),sin(x));}
int sz;
point w[(2*mxn)+1];
int initFFT(int n)
{
  if(sz==n)return n;
  sz=1;
  while(sz<n)sz<<=1;
  w[0]=point(1,0);
  point tw=makeunit(2*pi/sz);
  for(int i=1;i<=sz;i++)w[i]=w[i-1]*tw;
  return sz;
}
void FFT(point a[],bool rev)
{
  for(int i=0,j=0;i<sz;i++)
  {
    if(i>j)swap(a[i],a[j]);
    for(int l=sz>>1;(j^=l)<l;l>>=1);
  }
  for(int l=1;l<sz;l<<=1)
  {
    int l2=l<<1;
    for(int i=0;i<sz;i+=l2)
    {
      for(int j=0;j<l;j++)
      {
        point t=a[i+j+l]*w[rev?sz-sz/l2*j:sz/l2*j];
        a[i+j+l]=a[i+j]-t;
        a[i+j]=a[i+j]+t;
      }
    }
  }
  if(rev)for(int i=0;i<sz;i++)a[i]=a[i]*(1.0/sz);
}

vector<int> g[mn];
bool iscentroid[mn];
int getCentroid(int u,int p,int n) {
    int cnt = 1;
    bool goodCenter = true;
    for (auto w : g[u]) {
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
pair<int,int> getSubtreeSizeAndDepth(int x,int p) {
  int selfSubtreeSize=1;
  int depth=0;
  for (auto &w:g[x]) {
    int y=w;
    if (y==p||iscentroid[y]) continue;
    pair<int,int> childSubtreeSizeAndDepth=getSubtreeSizeAndDepth(y,x);
    selfSubtreeSize+=childSubtreeSizeAndDepth.fst;
    chkmax(depth, childSubtreeSizeAndDepth.snd);
  }
  return MP(selfSubtreeSize, depth+1);
}

int gcnt[mn];
void buildCnt(int x, int p, int depth) {
  gcnt[depth]++;
  for (auto &w:g[x]) {
    int y=w;
    if (y==p||iscentroid[y]) continue;
    buildCnt(y,x,depth+1);
  }
}
ll vfinal[mn];
ll sumE[mn];
void updFinal(int x, int p, int depth) {
  vfinal[x]+=sumE[depth];
  for (auto &w:g[x]) {
    int y=w;
    if (y==p||iscentroid[y]) continue;
    updFinal(y,x,depth+1);
  }
}
point C[mxn];
point W[mxn];
int weight[2*mn];
void fullCentroidDecomposition(int initv,int p,int n) {
  int centroid=getCentroid(initv,p,n);
  //printf("centroid:%d\n",centroid);
  vector<pair<int,pii> > subtreeRootsWithSizes;
  int depth=0;
  for (auto &w:g[centroid]) {
    int y=w;
    if (y!=p&&(!iscentroid[y])) {
      pii szAndDepth=getSubtreeSizeAndDepth(y,centroid);
      int childDepth=szAndDepth.snd;
      chkmax(depth,childDepth);
      subtreeRootsWithSizes.PB(MP(y,szAndDepth));
    }
  }
  /* Custom code starts here */
  int base=2*(depth+1);
  int poly_size=initFFT(base*2);
  for (int i=0;i<poly_size;i++) W[i]=0;
  for (int d=0;d<base;d++) W[base-1-d]=weight[d];
  //for (int d=0;d<base;d++) printf("(%d, %f)",d,W[d].x); printf(" W\n");
  FFT(W,false);
  vector<vector<int> > allE;
  memset(sumE,0,sizeof(ll)*base);
  for (int d=0;d<base;d++) {
    sumE[d]+=weight[d];
  }
  for (auto &got:subtreeRootsWithSizes) {
    int y=got.fst;
    memset(gcnt,0,sizeof(int)*base);
    buildCnt(y,centroid,1);
    for (int i=0;i<poly_size;i++) C[i]=0;
    for (int d=0;d<base;d++) C[d]=gcnt[d];
    //for (int d=0;d<base;d++) printf("(%d, %f)",d,C[d].x); printf(" C y:%d\n",got.fst);
    FFT(C,false);
    for (int i=0;i<poly_size;i++) C[i]=C[i]*W[i];
    FFT(C,true);
    //for (int d=0;d<base;d++) printf("(%d, %f)",d,C[d].x); printf(" W*C y:%d\n",got.fst);
    vector<int> E(base);
    for (int d=0;d<base;d++) {
      E[d]=round(C[base-1-d].x);
      //printf("(%d: %d) ",d,E[d]);
      sumE[d]+=E[d];
    }
    //printf(" E\n");
    allE.PB(E);
  }
  vfinal[centroid]+=sumE[0];
  auto Eit=allE.begin();
  for (auto &got:subtreeRootsWithSizes) {
    int y=got.fst;
    for (int d=0;d<base;d++) {
      sumE[d]-=(*Eit)[d];
    }
    updFinal(y,centroid,1);
    for (int d=0;d<base;d++) {
      sumE[d]+=(*Eit)[d];
    }
    ++Eit;
  }
  /* Custom code ends here. Continue decomposing subtree.*/
  iscentroid[centroid]=true;
  for (auto &got:subtreeRootsWithSizes) {
    fullCentroidDecomposition(got.first,centroid,got.snd.fst);
  }
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt();
  for (int i=0;i<n;i++) weight[i]=readInt();
  for (int i=1;i<n;i++) {
    int x=readInt(),y=readInt();
    g[x].PB(y); g[y].PB(x);
  }
	fullCentroidDecomposition(1,-1,n);
  for (int x=1;x<=n;x++) printf("%lld ",vfinal[x]);
  printf("\n");
}

