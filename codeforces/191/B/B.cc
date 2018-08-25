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
ll pqs=0;
priority_queue<int,vector<int>, greater<int> > pq;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),k=rint();
  ll b=rlong();
  for (int x=1;x<=n;x++) a[x]=rint();
  int final=n;
  for (int x=n-1;x>=1;x--) {
    ll need=pqs+a[x];
    if (need>b) chkmin(final,x);
    pq.push(a[x]); pqs+=a[x];
    if (pq.size()>k-1) {
      pqs-=pq.top();
      pq.pop();
    }
  }
  printf("%d\n",final);
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
