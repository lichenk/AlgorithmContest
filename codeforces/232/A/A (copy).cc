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

bool a[100][100];
void go(int oldk) {
  int k=oldk;
  vector<int> vans;
  int left=100;
  for (int x=100;x>=5;x--) {
    if (x>left) continue;
    int x3=(x*(x-1)*(x-2))/6;
    while(x3<=k) {
      k-=x3;
      printf("x:%d k:%d\n",x,k);
      for (auto &y:vans) {
        int y2=(y*(y-1))/2;
        int need=k/y2;
        int take=min(x,need);
        k-=take*y2;
        printf("x:%d y:%d k:%d\n",x,y,k);
      }
      vans.PB(x);
      left-=x;
    }
  }
  left-=k+2;
  assert(left>=0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //int k=rint();
  for (int k=100*1000;k>=1;k--) {
    go(k);
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