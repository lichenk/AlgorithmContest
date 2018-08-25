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

// printf("Case #%d: %lld\n",casenum,ans);
bool solve(int casenum) {
	int xlim,ylim,xc,yc; cin>>xlim>>ylim>>xc>>yc;
	vector<string> a; a.resize(xlim);
	for (int x=0;x<xlim;x++) cin>>a[x];
	int sum=0;
	for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) {
		if (a[x][y]=='@') sum++;
	}
	if (sum==0) return true;
	int pcs=(xc+1)*(yc+1);
	if ((sum%pcs) != 0) return false;
	vector<int> vx; vx.PB(0);
	{
		int targ=sum/(xc+1);
		int now=0;
		for (int x=0;x<xlim;x++) {
			for (int y=0;y<ylim;y++) {
				if (a[x][y]=='@') now++;
			}
			if (now>targ) return false;
			if (now==targ) {
				vx.PB(x+1);
				now=0;
			}
		}
	}
	vector<int> vy; vy.PB(0);
	{
		int targ=sum/(yc+1);
		int now=0;
		for (int y=0;y<ylim;y++) {
			for (int x=0;x<xlim;x++) {
				if (a[x][y]=='@') now++;
			}
			if (now>targ) return false;
			if (now==targ) {
				vy.PB(y+1);
				now=0;
			}
		}
	}
	int need=sum/pcs;
	for (int xi=0;xi<vx.size()-1;xi++) {
		int xl=vx[xi],xr=vx[xi+1];
		for (int yi=0;yi<vy.size()-1;yi++) {
			int yl=vy[yi],yr=vy[yi+1];
			int ans=0;
			for (int x=xl;x<xr;x++) for (int y=yl;y<yr;y++) {
				if (a[x][y]=='@') ans++;
			}
			if (ans!=need) return false;
		}
	}
	return true;
	
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin>>T;
  for (int i=1;i<=T;i++) {
    bool ans=solve(i);
    if (ans) printf("Case #%d: POSSIBLE\n",i);
    else printf("Case #%d: IMPOSSIBLE\n",i);
  }
}
