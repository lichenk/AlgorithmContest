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
const int mn=32,mk=10;
bitset<mn> win;
int s[mn][mk];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();k=rint();
  for (int x=0;x<n;x++) {
    for (int y=0;y<k;y++) {
      s[x][y]=rint();
    }
  }
  for (int y=0;y<k;y++) b[y]=s[0][y];
  printf("1\n");
  for (int x=1;x<n;x++) {
    bool canwin=0;
    bool winall=1;
    for (int y=0;y<k;y++) {
      if (s[x][y]>b[y]) {
        canwin=1;
      }
      else winall=0;
    }
    printf("%d\n",ans);
  }
}





int rint()
{
  int x; scanf("%d",&x); return x;
}
