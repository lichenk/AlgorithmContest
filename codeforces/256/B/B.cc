#include <bits/stdc++.h>
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

const ll lim=1e9+2;
ll arith(ll start, ll delta, ll terms) {

}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n,x,y,c; cin>>n>>x>>y>>c;
  n--;
  vector<ll> v;
  h[(x-1)]++;h[(y-1)]++;
  h[(n-x)]++;h[(n-y)]++;
  ll inc=4;
  for (auto &w:h) {
    ll need=(c+inc-1)/inc;
    if (need<=w.fst) {
      printf("%lld\n",need);
      return 0;
    }
    need-=inc*(w.fst-prev);
    inc-=w.snd;
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