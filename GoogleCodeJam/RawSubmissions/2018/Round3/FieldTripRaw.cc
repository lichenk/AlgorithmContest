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
const ll INF=1LL<<60;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
void solve(int casenum) {
	int n; cin>>n;
	vector<pll> a(n+5);
	for (int i=1;i<=n;i++) cin>>a[i].fst>>a[i].snd;
	ll lox=a[1].fst,hix=a[1].fst;
	ll loy=a[1].snd,hiy=a[1].snd;
	for (int i=2;i<=n;i++) {
		chkmin(lox,a[i].fst);
		chkmax(hix,a[i].fst);
		chkmin(loy,a[i].snd);
		chkmax(hiy,a[i].snd);
	}
	ll dx=(hix-lox+1)/2;
	ll dy=(hiy-loy+1)/2;
	ll ans=max(dx,dy);
	printf("Case #%d: %lld\n",casenum,ans);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin>>T;
  for (int i=1;i<=T;i++) {
    solve(i);
  }
}
