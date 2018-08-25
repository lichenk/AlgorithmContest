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

bool f(ll p,ll q,ll b) {
	if (p==0) return true;
	q=q/__gcd(p,q);
	while(1) {
		while (q%b==0) q/=b;
		if (q==1) return true;
		ll g=__gcd(q,b);
		if (g==1) return false;
		b=g; q/=g;
	}
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rlong();
  for (ll i=0;i<n;i++) {
  	ll p=rlong(),q=rlong(),b=rlong();
  	bool ans=f(p,q,b);
  	if (ans) printf("Finite\n");
  	else printf("Infinite\n");
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