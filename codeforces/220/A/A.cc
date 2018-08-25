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
const int mn=1e5+4;
int a[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    a[i]=rint();
  }
  for (int z=0;z<2;z++) {
    vector<int> inbal;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        for (int k = max(0, i - 2); k <= min(n - 2, i + 2); k++) {
          inbal.PB(k);
        }
      }
    }
    if (inbal.size() > 60) {
      printf("NO\n");
      return 0;
    }
    int x = -1;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        x = i;
        break;
      }
    }
    if (x == -1) {
      printf("YES\n");
      return 0;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] <= a[x + 1]) {
        swap(a[x], a[i]);
        bool ok = 1;
        for (auto &y:inbal) {
          if (a[y] > a[y + 1]) {
            ok = 0;
            break;
          }
        }
        if (ok) {
          printf("YES\n");
          return 0;
        }
        swap(a[x], a[i]);

      }
    }
    reverse(a,a+n);
    for (int i=0;i<n;i++) a[i]=-a[i];
  }
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