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


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int x=rint(),y=rint();
  while(1) {
  	{
  		bool ok=0;
  		for (int a=2;a>=0;a--) {
  			int b=22-a*10;
  			if (x>=a&&y>=b) {
  				x-=a; y-=b; ok=1; break;
  			}
  		}
  	if (!ok) {
  		printf("Hanako\n"); return 0;
  	}
  	}
  	{
  		bool ok=0;
  		for (int a=0;a<=2;a++) {
  			int b=22-a*10;
  			if (x>=a&&y>=b) {
  				x-=a; y-=b; ok=1; break;
  			}
  		}
  	if (!ok) {
  		printf("Ciel\n"); return 0;
  	}
  	}
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