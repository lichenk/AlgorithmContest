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
ll b[3];
ll f[2][mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int k=0;k<3;k++) cin>>b[k];
  for (int i=0;i<n;i++) cin>>a[i];
  int cur=0,nxt=1;
  for (int k=0;k<3;k++) {
    for (int x=0;x<n;x++) f[nxt][x]=LLONG_MIN;
    ll best=LLONG_MIN;
    ll bk=b[k];
    for (int x=0;x<n;x++) {
      chkmax(best,f[cur][x]);
      if (best>LLONG_MIN) {
        chkmax(f[nxt][x], best+a[x]*bk);
      }
    }
    swap(cur,nxt);
  }
  ll final=LLONG_MIN;
  for (int x=0;x<n;x++) {
    chkmax(final, f[cur][x]);
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