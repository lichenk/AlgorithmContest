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
const int mn=1e5+4;
const int mb=24;
int g[mn][mb];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<=n;i++) for (int b=0;b<mb;b++) g[i][b]=INF;
  for (int i=0;i<m;i++) {
  	int a=rint(),b=rint(),c=rint();
  	chkmin(g[a][b],c);
  }
  int now=1;
  for (int a=1;a<n;a++) {
  	int h=now%24;
  	int nxt=INF;
  	for (int b=0;b<mb;b++) {
  		if (b>=h) {
  			chkmin(nxt,now+(b-h)+g[a][b]);
  		}
  		else {
  			chkmin(nxt,now+(b+24-h)+g[a][b]);
  		}
  	}
  	now=nxt+1;
  }
  int d=now/24,h=now%24;
  printf("Day %d Hour %d\n",d,h);
}

int rint()
{
	int x; scanf("%d",&x); return x;
}
