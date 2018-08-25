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

int vk[2];
vi a[2];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); for (int t=0;t<2;t++) vk[t]=rint();
  int k=vk[0]+vk[1];
  for (int t=0;t<2;t++) {
    for (int i=0;i<n;i++) a[t].PB(rint());
  }
  priority_queue<int> pq; // maxheap
  for (int i=0;i<n;i++) {
    int x=abs(a[0][i]-a[1][i]);
    if (x>0) pq.push(x);
  }
  while (k>0&&(!pq.empty())) {
    int x=pq.top(); pq.pop();
    if (x>0) {
      --x; --k;
      if (x>0) pq.push(x);
    }
  }
  ll final=(k&1);
  while (!pq.empty()) {
    int d=pq.top(); pq.pop();
    if (d>0) final+=((ll)d)*(ll)d;
  }
  printf("%lld\n",final);
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