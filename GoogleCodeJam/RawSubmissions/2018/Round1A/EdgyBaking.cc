#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
const ld NEGINF=-1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif

// printf("Case #%d: %lld\n",casenum,ans);
ld f[(250*100)+10];
void solve(int casenum) {
	int n,p; cin>>n>>p;
	vector<int> vh(n),vw(n);
	for (int i=0;i<n;i++) {
		cin>>vh[i]>>vw[i];
	}
	ll base=0;
	for (int i=0;i<n;i++) {
		base+=vh[i]; base+=vw[i];
	}
	base*=2;
	int sumlo=0;
	for (int i=0;i<n;i++) {
		int h=vh[i],w=vw[i];
		sumlo+=min(h,w);
	}
	f[0]=0;
	for (int x=1;x<=sumlo;x++) f[x]=NEGINF;
	for (int i=0;i<n;i++) {
		//int cur=i&1; int nxt=cur^1;
		int h=vh[i],w=vw[i];
		int lo=min(h,w);
		ld hi=sqrt((ld)(h*(ll)h+w*(ll)w));
		for (int x=sumlo;x>=lo;x--) {
			ld cand=f[x-lo];
			if (cand>-1) {
				chkmax(f[x],cand+hi);
			}
		}
	}
	ld best=0;
	int xhi=min((p-base)/2,(ll)sumlo);
	for (int x=0;x<=xhi;x++) {
		chkmax(best,f[x]);
	}
	ld final=min(best*2+base,(ld)p);
	//printf("base:%lld\n",base);
	printf("Case #%d: %.9f\n",casenum,(double)final);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin>>T;
  for (int i=1;i<=T;i++) {
    solve(i);
  }
}
