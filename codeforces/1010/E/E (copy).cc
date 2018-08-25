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

/*
const int MAXSZ=(241)*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  preidx+=(((int)size) + 3) & ~0x03;
  //preidx+=size;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}
*/


const int SZ = 100000+1;
struct Node1 {
  vector<int> v;
  bool sorted=false;
  void upd(int x) {
    v.PB(x);
  }
  bool query(int x1, int x2) {
    if (!sorted) {
      sort(v.begin(),v.end()); sorted=true;
    }
    int imin=0,imax=v.size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (v[imid]<x1) imin=imid+1;
      else imax=imid;
    }
    return imax<v.size() && v[imin]<=x2;
  }
};



struct Node2 {
    Node1 seg;
    Node2* c[2];
    void upd(int x, int y, int L = 0, int R = SZ-1) { // add v
        seg.upd(y);
        if (L == x && R == x) {
            return;
        }
        int M = (L+R)/2;
        if (x <= M) {
            if (!c[0]) c[0] = new Node2();
            c[0]->upd(x,y,L,M);
        } else {
            if (!c[1]) c[1] = new Node2();
            c[1]->upd(x,y,M+1,R);
        }
    }
    
    bool query(int x1, int x2, int y1, int y2, int L = 0, int R = SZ-1) { // query sum of rectangle
        if (x1 <= L && R <= x2) return seg.query(y1,y2);
        if (x2 < L || R < x1) return false;
        int M = (L+R)/2;
        if (c[0]) if(c[0]->query(x1,x2,y1,y2,L,M)) return true;
        if (c[1]) if(c[1]->query(x1,x2,y1,y2,M+1,R)) return true;
        return false;
    }
};

struct Node3 {
    Node2 seg;
    Node3* c[2];
    void upd(int x, int y, int z, int L = 0, int R = SZ-1) { // add v
        seg.upd(y,z);
        if (L == x && R == x) {
            return;
        }
        int M = (L+R)/2;
        if (x <= M) {
            if (!c[0]) c[0] = new Node3();
            c[0]->upd(x,y,z,L,M);
        } else {
            if (!c[1]) c[1] = new Node3();
            c[1]->upd(x,y,z,M+1,R);
        }
    }
    
    bool query(int x1, int x2, int y1, int y2, int z1, int z2, int L = 0, int R = SZ-1) { // query sum of rectangle
        if (x1 <= L && R <= x2) return seg.query(y1,y2,z1,z2);
        if (x2 < L || R < x1) return false;
        int M = (L+R)/2;
        if (c[0]) if(c[0]->query(x1,x2,y1,y2,z1,z2,L,M)) return true;
        if (c[1]) if(c[1]->query(x1,x2,y1,y2,z1,z2,M+1,R)) return true;
        return false;
    }
};

/*
const int mn=50;
bitset<mn+4> a[mn+4];
void test() {
  for (int x=0;x<mn+4;x++) a[x].reset();
  Node2 *root = new Node2;
  srand(clock());
  for (int k=0;k<1000;k++) {
    int x=rand()%mn,y=rand()%mn;
    root->upd(x,y); a[x][y]=true;
    int x1=rand()%mn,x2=rand()%mn; if (x1>x2) swap(x1,x2);
    int y1=rand()%mn,y2=rand()%mn; if (y1>y2) swap(y1,y2);
    bool got=root->query(x1,x2,y1,y2);
    bool bf=0;
    for (int x=x1;x<=x2;x++) for (int y=y1;y<=y2;y++) {
      if (a[x][y]) {bf=1; break;}
    }
    if (bf!=got) {
      printf("WRONG\n");
      exit(0);
    }
  }
}
*/
int lim[3];
int vh[3],vl[3];
Node3 root;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //for (int i=0;i<500;i++) test();
  for (int d=0;d<3;d++) lim[d]=rint();
  int n=rint(),m=rint(),k=rint();
  for (int d=0;d<3;d++) {vl[d]=INT_MAX; vh[d]=INT_MIN;}
  for (int i=0;i<n;i++) {
    for (int d=0;d<3;d++) {
      int got=rint();
      chkmin(vl[d],got);
      chkmax(vh[d],got);
    }
  }
  for (int i=0;i<m;i++) {
    int p[3];
    for (int d=0;d<3;d++) p[d]=rint();
    root.upd(p[0],p[1],p[2]);
  }
  if (root.query(
    vl[0],vh[0],
    vl[1],vh[1],
    vl[2],vh[2]
    )) {
    printf("INCORRECT\n"); exit(0);
  }
  printf("CORRECT\n");
  for (int i=0;i<k;i++) {
    int p[3];
    for (int d=0;d<3;d++) p[d]=rint();
    bool closed=false;
    for (int d=0;d<3;d++) {
      if (!(vl[d]<=p[d]&&p[d]<=vh[d])) closed=true;
    }
    bool open=true;
    if (root.query(
      min(vl[0],p[0]),max(vh[0],p[0]),
      min(vl[1],p[1]),max(vh[1],p[1]),
      min(vl[2],p[2]),max(vh[2],p[2])
      )) {
      open=false;
    }
    if (closed&&open) printf("UNKNOWN\n");
    else if (closed) printf("CLOSED\n");
    else if (open) printf("OPEN\n");
    else assert(0);
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