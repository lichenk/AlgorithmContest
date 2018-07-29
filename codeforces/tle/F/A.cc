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

const int mn=2008;
int a[mn];
vector<char> vans;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=1;i<=n;i++) a[i]=rint();
  int x=-1;
  while(1) {
    pii hi=MP(-1,-1);
    for (int x=0;x<=n;x++) {
      chkmax(hi,MP(a[x],-x));
    }
    assert(hi.fst>=0);
    if (hi.fst<=0) break;
    int l=-hi.snd;
    int r=l;
    for (int x=l;x<=n+1;x++) {
      if (a[x]!=hi.fst) {r=x-1; break;}
    }
    //printf("l:%d r:%d\n",l,r);
    while(x<r-1) {
      printf("A");
      printf("R");
      x++;
    }
    printf("A");
    while(x>l-2) {
      printf("L");
      x--;
    }
    printf("A");
    for (int x=l;x<=r;x++) a[x]--;
  }
  printf("\n");
}

int rint()
{
  int x; scanf("%d",&x); return x;
}