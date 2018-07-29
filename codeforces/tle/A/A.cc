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
const int mn=1002;
pii pp[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  set<pii> s;
  pp[1]=MP(0,0);
  s.insert(pp[1]);
  for (int i=2;i<=n;i++) {
  	int p=rint(),dx=rint(),dy=rint();
  	pp[i]=MP(pp[p].fst+dx,pp[p].snd+dy);
  	//printf("%d %d\n",pp[i].fst,pp[i].snd);
  	s.insert(pp[i]);
  }
  printf("%d\n",(int)(s.size()));
}

int rint()
{
	int x; scanf("%d",&x); return x;
}
