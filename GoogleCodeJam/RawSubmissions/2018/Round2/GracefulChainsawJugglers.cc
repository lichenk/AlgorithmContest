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
const int INF=1<<29;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
const int mn=501;
int f[mn+2][mn+2];
void solve(int casenum) {
	int x,y; cin>>x>>y;
	printf("Case #%d: %d\n",casenum,f[x][y]);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int x=0;x<=mn;x++) {
  	fill(f[x],f[x]+mn+1,-INF);
  }
  f[0][0]=0;
  for (int s=1;s<=mn;s++) {
  	for (int dx=0;dx<=s;dx++) {
  		int dy=s-dx;
  		for (int x=mn;x>=dx;x--) for (int y=mn;y>=dy;y--) {
  			int now=f[x-dx][y-dy];
  			chkmax(f[x][y],now+1);
  		}
  	}
  }
  int T; cin>>T;
  for (int i=1;i<=T;i++) {
    solve(i);
  }
}
