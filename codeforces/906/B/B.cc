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
const int maxn=100000;
clock_t start;
int a[maxn],b[maxn];
bitset<maxn> divm;
int n,m,nm;
inline bool checkneigh(int x, int y) {
  if (x>y) swap(x,y);
  int diff=y-x;
  //if (((diff==m)||diff==1 && divm[y])) printf("x:%d y:%d\n",x,y);
  return ((diff==m)||diff==1 && divm[y]);
}

inline void check() {
  for (int x=0;x<nm-m;x++) {
    if (checkneigh(a[x],a[x+m])) return;
  }
  for (int x=1;x<nm;x++) {
    if (divm[x] && checkneigh(a[x],a[x-1])) return;
  }
  printf("YES");
  for (int x=0;x<nm;x++) {
    if (!divm[x]) printf("\n");
    printf("%d ",a[x]+1);
  }
  exit(0);
}


void pr() {
  for (int x=0;x<nm;x++) {
    if (!divm[x]) printf("\n");
    printf("%d ",a[x]);
  }
}

void brute() {
  for (int x=0;x<nm;x++) a[x]=x;
  while(1) {
    clock_t now=clock();
    if (now - start > 1.72 * CLOCKS_PER_SEC) break;
    srand(now);
    random_shuffle(a,a+nm);
    check();
  }
}
void smart1(int mode) {
  if (mode&2) swap(n,m);
  int pos=0;
  for (int x=0;x<n;x++) {
    int base=x*m;
    for (int y=base;y<base+m;y+=2) {
      a[pos++]=y;
    }
    for (int y=base+1;y<base+m;y+=2) {
      a[pos++]=y;
    }
    if (x&1) {
      reverse(a+base,a+base+m);
      if(mode&1)for (int y=base+1;y<base+m;y+=2) {
        swap(a[y-1],a[y]);
      }
    }
  }
  {
    memcpy(b,a,sizeof(a));
    int id=0;
    for (int x=0;x<n;x+=2) {
      for (int y=0;y<m;y++) {
        a[id++]=b[x*m+y];
      }
    }
    for (int x=1;x<n;x+=2) {
      for (int y=0;y<m;y++) {
        a[id++]=b[x*m+y];
      }
    }
  }
  for (int x=1;x<n;x+=2) {
    int base=x*m;
    for (int y=base+1;y<base+m;y+=2) {
      swap(a[y],a[y-m]);
    }
  }
  if (mode&2) {
    memcpy(b,a,sizeof(a));
    for (int x=0;x<n;x++) {
      for (int y=0;y<m;y++) {
        int val=b[x*m+y];
        int r=val/m,c=val%m;
        a[y*n+x]=c*n+r;
      }
    }
    swap(n,m);
  }
  check();
  //pr();
}
int main() 
{
  start=clock();
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%d%d",&n,&m);
  //printf("isneigh:%d\n",checkneigh(2,3));
  nm=n*m;
  divm.set();
  for (int x=0;x<nm;x+=m) divm[x]=false;
  for (int mode=0;mode<4;mode++) smart1(mode);
  brute();
  assert(0);
  printf("NO\n");
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