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
const int INF=1<<30;
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
const int mn=20;
int p[mn];
int ffind(int x) {
  if (p[x] != x) {
    p[x] = ffind(p[x]);
  }
  return p[x];
}
void funion(int x, int y) {
  if (rand()&1) swap(x,y); 
  int xr = ffind(x);
  int yr = ffind(y);
  p[xr] = yr;
}
int va[mn],vb[mn],vc[mn],vfinal[mn];
vector<int> gc[mn];
int n,m;
bool findmst(int wantei) {
  srand(time(0)+clock()+rand());
  for (int x=0;x<n;x++) p[x]=x;
  for (int c=0;c<=11;c++) {
    //printf("c:%d gcsz:%d\n",c,gc[c].size());
    if (gc[c].size()==0) continue;
    random_shuffle(gc[c].begin(),gc[c].end());
    for (auto &ei:gc[c]) {
      int x = va[ei];
      int y = vb[ei];
      //printf("x:%d y:%d ei:%d c:%d\n",x,y,ei,c);
      if (ffind(x) != ffind(y)) {
        if (ei==wantei) return true;
        funion(x,y);
      }
    }
  }
  return false;
}
bool tryc(int wantei, int wantc) {
  for (int c=0;c<=11;c++) gc[c].clear();
  for (int ei=0;ei<m;ei++) {
    int x = va[ei];
    int y = vb[ei];
    int c = vc[ei];
    if (ei==wantei) c=wantc;
    gc[c].PB(ei);
  }
  for (int k=0;k<100000;k++) {
    //printf("k:%d\n",k);
    if (!findmst(wantei)) return false;
  }
  return true;
}
int get(int wantei) {
  for (int wantc=11;wantc>=0;wantc--) {
    if (tryc(wantei,wantc)) return wantc;
  }
  //assert(tryc(wantei,0));
  //printf("wantei:%d",wantei);
  assert(0);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint(),c=rint();
    c/=100000000;
    --x;--y;
    va[i]=x,vb[i]=y,vc[i]=c;
  }
  for (int ei=0;ei<m;ei++) {
    int got=get(ei); if (got>=11) got=-1; else {got*=100000000; got+=100000000-1;}
    printf("%d ",got);
  }
  printf("\n");
}