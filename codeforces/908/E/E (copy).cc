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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }

bitset<(1<<5)> b;
int bf1(int m,vector<int> v, bool pr) {
  int M=(1<<m)-1;
  int zlim=(1<<(1<<m));
  int ans=0;
  for (int z=0;z<zlim;z++) {
    b.reset();
    for (int i=0;i<=M;i++) {
      if (z&(1<<i)) b[i]=true;
    }
    bool ok=1;
    for (auto &w:v) {
      if (!b[w]) {ok=0; goto qq;}
    }
    for (int x=0;x<=M;x++) {
      if (b[x] != b[x^M]) {ok=0; goto qq;}
    }
    for (int x=0;x<=M;x++) {
      if (b[x]) for (int y=0;y<x;y++) {
        if (b[y]) {
          if (!b[x&y]) {ok=0; goto qq;}
        }
      }
    }
    qq:
    if (ok) {
      if (pr) {
        for (int i=0;i<=M;i++) {
          if (b[i]) printf("%d, ",i);
        }
        printf("\n");
      }
      ans++;
    }
  }
  return ans;
}

int bf2(int m,vector<int> v, bool pr) {
  int M=(1<<m)-1;
  int zlim=(1<<(1<<(m-1)));
  int ans=0;
  for (int z=0;z<zlim;z++) {
    b.reset();
    for (int i=0;i<(1<<(m-1));i++) {
      if (z&(1<<i)) {
        b[i]=true;
        b[M^i]=true;
      }
    }
    bool ok=1;
    for (auto &w:v) {
      if (!b[w]) {ok=0; goto qq;}
    }
    for (int x=0;x<=M;x++) {
      if (b[x] != b[x^M]) {ok=0; goto qq;}
    }
    for (int x=0;x<=M;x++) {
      if (b[x]) for (int y=0;y<x;y++) {
        if (b[y]) {
          if (!b[x&y]) {ok=0; goto qq;}
        }
      }
    }
    qq:
    if (ok) {
      if (pr) {
        for (int i=0;i<=M;i++) {
          if (b[i]) printf("%d, ",i);
        }
        printf("\n");
      }
      ans++;
    }
  }
  return ans;
}


void testone() {
  int seed=clock();
  //seed=240684;
  srand(seed);
  int m=rand()%4+1;
  int n=rand()%5+1;
  vector<int> v;
  for (int i=0;i<n;i++) v.PB(rand()%(1<<m));
  int ans1=bf1(m,v,0);
  int ans2=bf2(m,v,0);
  if (ans1!=ans2) {
    printf("ans1:%d ans2:%d seed:%d m:%d n:%d v: ",ans1,ans2,seed,m,n);
    for (auto &w:v) printf("%d ",w);
    printf("\n");
  }
  /*if (ans==5) {
    printf("seed:%d m:%d n:%d v: ",seed,m,n);
    for (auto &w:v) printf("%d ",w);
    printf("\n");
    bf1(m,v,1);
  }*/
  printf("ans2:%d\n",ans2);
}

void test() {
  for (int k=0;k<100;k++) testone();
}

const int mn=52;
string a[mn];
//int n,m;

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  test(); return 0;
  int m,n; cin>>m>>n;
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  vector<int> v;
  for (int i=0;i<n;i++) {
    int got=0;
    for (int x=0;x<m;x++) {
      if (a[i][x]=='1') got|=1<<x;
    }
    v.PB(got);
  }
  int res=bf1(m,v,0);
  printf("%d\n",res);
  /*
  set<ll> s;
  for (int x=0;x<m;x++) {
    ll sig=0;
    for (int i=0;i<n;i++) {
      if (a[i][x]=='1') {
        sig|=1LL<<i;
      }
    }
    s.insert(sig);
  }
  int ans=mod_pow(2,m-s.size(),MOD);
  printf("%d\n",ans);*/
}
