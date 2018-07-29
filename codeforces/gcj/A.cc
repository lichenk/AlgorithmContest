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

bool isok(ll d, string s) {
  ll now=1;
  for (auto &x:s) {
    if (x=='S') {d-=now;}
    else if (x=='C') now*=2;
    else assert(0);
    if (d<0) return false;
  }
  return (d>=0);
}

void solve(int casenum) {
  ll d; string s; cin>>d>>s;
  ll n=s.length();
  ll ans=0;
  while(1) {
    if (isok(d,s)) {
      printf("Case #%d: %lld\n",casenum,ans);
      return;
    }
    bool found=0;
    for (ll i=n-2;i>=0;i--) {
      if (s[i]=='C'&&s[i+1]=='S') {
        swap(s[i],s[i+1]);
        found=1;
        ans++;
        break;
      }
    }
    if (!found) {
      printf("Case #%d: IMPOSSIBLE\n",casenum);
      return;
    }
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll T; cin>>T;
  for (ll i=1;i<=T;i++) {
    solve(i);
  }
}
