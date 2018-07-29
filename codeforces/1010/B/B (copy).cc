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
/*int ask(int y) {
  printf("%d\n",y); fflush(stdout);
  int ret; scanf("%d",&ret);
  if (ret==0||ret==-2) {exit(0);}
  return ret;
}*/
int gx; bitset<31> fake;
int ask(int y) {
  if (fake)
}

const int mn=1e5+4;
bitset<mn> res;


void go(int hi, int n) {
  for (int i=0;i<n;i++) {
    int got=ask(1);
    if (got==1) res[i]=true;
    else res[i]=false;
  }
  ll imin=2,imax=hi+1;
  int idx=0;
  while(imin<imax) {
    ll imid=(imin+imax)/2;
    int got=ask(imid);
    if (res[idx]==false) got=-got;
    if (got==1) imin=imid+1; // y<x
    else imax=imid;
  }
  ask(imin);
}

void test() {
  int hi=rand()%(int)(1e9)+1;
  int n=rand()%30+1;
  go();
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int hi,n; scanf("%d%d",&hi,&n);
  go(hi,n);
}
