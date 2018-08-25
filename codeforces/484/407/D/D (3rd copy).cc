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
const int maxn=400;
const int maxv=400*400;
const int segn=512;
bitset<2*segn> t[maxv];
//bool t[maxv][2*segn];
void fins(int value, int p) { // set value at position p
  for (t[value][p += segn] = 1; p >>= 1; ) t[value][p] = 1;
}
/*void fzero(int value, int p) { // set value at position p
  for (t[value][p += segn] = 0; p >>= 1; ) t[value][p] = 0;
}*/
/*void fzero(int value, int idx) {
  t[value][idx]=0;
  if (idx<segn) {
    idx<<=1;
    if (t[value][idx]) fzero(value,idx);
    if (t[value][idx|1]) fzero(value,idx|1);
  }
}*/
int fquery(int value, int r) { // Finds maximal index idx<=r and t[value][idx]==true
  int idx=segn+r;
  if (t[value][idx]) return r;
  while(idx>1) {
    if (idx&1) {
      if (t[value][idx^1]) {
        idx^=1;
        while(idx<segn) {
          idx<<=1;
          if (t[value][idx|1]) idx|=1;
        }
        return idx-segn;
      }
    }
    idx>>=1;
  }
  return 0;
}
int fqueryins(int value, int r) { // Finds maximal index idx<=r and t[value][idx]==true
  int idx=segn+r;
  if (t[value][idx]) return r;
  t[value][idx]=1;
  while(idx>1) {
    if (idx&1) {
      if (t[value][idx^1]) {
        idx^=1;
        while(idx<segn) {
          idx<<=1;
          if (t[value][idx|1]) idx|=1;
        }
        return idx-segn;
      }
    }
    idx>>=1;
    t[value][idx]=1;
  }
  return 0;
}

/*void test() {
  for (int k=0;k<1000;k++) {
    t[0].reset();
    ll seed=time(0)+clock()+rand();
    srand(seed);
    set<int,greater<int> > s;
    s.insert(0);
    for (int i=0;i<300;i++) {
      int t=rand()%2;
      int x=rand()%400;
      if (t==0) {
        printf("Insert:%d\n",x);
        fins(0,x);
        s.insert(x);
      }
      else {
        int got=fquery(0,x);
        auto it=s.lower_bound(x);
        int correct=0;
        if (it!=s.end()) correct=*it;
        if(got!=correct) {
          printf("Query:%d. Got:%d Correct:%d. Seed:%lld\n",x,got,correct,seed);
          exit(0);
        }
      }
    }
  }
}*/

int vylo[maxn];
int a[maxn][maxn];
short vans[maxn][maxn][maxn];
int vid[maxv];
int main() 
{
  //test();
  //return 0;
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    a[x][y]=rint()-1;
  }
  for (int xlo=n-1;xlo>=0;xlo--) {
    for (int x=xlo+1;x<n;x++) for (int y=0;y<m;y++) {
      int value=a[x][y];
      if (vid[value]!=xlo+1) {
        vid[value]=xlo+1;
        t[value].reset();
      }
    }
    memset(vylo,0,sizeof vylo);
    for (int xhi=xlo;xhi<n;xhi++) {
      int ylo=0;
      for (int yhi=0;yhi<m;yhi++) {
        if (xlo!=xhi){
          int value=a[xlo][yhi];
          vans[xhi][xlo][yhi]=fquery(value,yhi);
        }
        {
          int value=a[xhi][yhi];
          ylo=max(ylo,max(vylo[yhi],fqueryins(value,yhi+1)));
          vylo[yhi]=ylo;
          vans[xlo][xhi][yhi]=ylo;
        }
      }
    }
  }
  int final=0;
  for (int xhi=0;xhi<n;xhi++) {
    memset(vylo,0,sizeof vylo);
    for (int xlo=xhi;xlo>=0;xlo--) {
      int ylo=0;
      for (int yhi=0;yhi<m;yhi++) {
        ylo=max(ylo,max(vylo[yhi],(int)vans[xhi][xlo][yhi]));
        vylo[yhi]=ylo;
        int rylo=max((int)vans[xlo][xhi][yhi],ylo);
        int cand=(xhi-xlo+1)*(yhi-rylo+1);
        chkmax(final,cand);
      }
    }
  }
  printf("%d\n",final);
}

