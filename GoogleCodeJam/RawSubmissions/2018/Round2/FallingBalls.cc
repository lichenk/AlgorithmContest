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
const int mn=200+4;
int a[mn],b2d[mn];
char s[mn][mn];
void solve(int casenum) {
	int n; cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	int sum=0; for (int i=0;i<n;i++) sum+=a[i];
	if (sum!=n||a[0]==0||a[n-1]==0) {
		printf("Case #%d: IMPOSSIBLE\n",casenum); return;
	}
	int rows=0;
	{
		int b=0;
		for (int pos=0;pos<n;pos++) {
			for (int t=0;t<a[pos];t++) {
				b2d[b]=pos;
				++b;
			}
		}
	}
	for (int x=0;x<mn;x++) {
		for (int y=0;y<n;y++) {
			s[x][y]='.';
		}
		s[x][n]='\0';
	}
	for (int b=0;b<n;b++) {
		int pos=b2d[b];
		int rlim=abs(pos-b);chkmax(rows,rlim);
		if (pos>b) {
			for (int r=0;r<rlim;r++) {
				s[r][b+r]='\\';
			}
		}
		else if (pos<b) {
			for (int r=0;r<rlim;r++) {
				s[r][b-r]='/';
			}
		}
	}
	rows++;
	printf("Case #%d: %d\n",casenum,rows);
	for (int r=0;r<rows;r++) printf("%s\n",s[r]);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin>>T;
  for (int i=1;i<=T;i++) {
    solve(i);
  }
}
