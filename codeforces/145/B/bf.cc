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

void fail(int t) {
  printf("-1\n"); exit(0);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int ga=rint(),gb=rint(),gab=rint(),gba=rint();
  for (int n=1;n<=12;n++) {
    for (int z=0;z<(1<<n);z++) {
      int a=0,b=0,ab=0,ba=0;
      for (int i=0;i<n;i++) {
        if ((z>>i)&1)b++; else a++;
      }
      for (int i=0;i<n-1;i++) {
        if (1==((z>>i)&3)) ab++;
        if (2==((z>>i)&3)) ba++;
      }
      if (a==ga&&b==gb&&ab==gab&&gba==ba) {
        for (int i=n-1;i>=0;i--) {
          if (z&(1<<i)) printf("7");
          else printf("4");
        }
        printf("\n");
        return 0;
      }
    }
  }
  printf("-1\n");
}





int rint()
{
int x; cin>>x; return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}