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
const int mn=21;
string a[mn];
int xlim,ylim;
bitset<mn> b[mn];
bitset<mn> seen[mn];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool valid(int x, int y) {
	return (0<=x&&x<xlim) && (0<=y&&y<ylim);
}
int dfs(int x, int y) {
	if (seen[x][y]||b[x][y]==false) return 0;
	int ans=1;
	seen[x][y]=true;
	for (int k=0;k<4;k++) {
		int nx=x+dx[k],ny=y+dy[k];
		if (valid(nx,ny)) {
			ans+=dfs(nx,ny);
		}
	}
	return ans;
}
void solve(int casenum) {
	cin>>xlim>>ylim;
	for (int x=0;x<xlim;x++) cin>>a[x];
	set<string> pat;
	for (int x=-1;x<=xlim;x++) for (int y=-1;y<=ylim;y++) {
		string s; s.resize(4); for (int i=0;i<4;i++) s[i]='.';
		for (int k=0;k<4;k++) {
			int nx=x+(k&1);
			int ny=y+(k>>1);
			if (valid(nx,ny)) s[k]=a[nx][ny];
		}
		pat.insert(s);
	}
	int ans=0;
	for (auto &p:pat) {
		for (int sx=-1;sx<=xlim;sx++) for (int sy=-1;sy<=ylim;sy++) {
			for (int x=0;x<xlim;x++) {b[x].reset(); seen[x].reset();}
			for (int x=0;x<xlim;x++) {
				for (int y=0;y<ylim;y++) {
					char c=a[x][y];
					int sig=((y>sy)?2:0)|((x>sx)?1:0);
					b[x][y]=(c==p[sig]);
				}
			}
			for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) {
				if (b[x][y]&&(!seen[x][y])) {
					int cand=dfs(x,y);
					chkmax(ans,cand);
				}
			}
		}
	}
	printf("Case #%d: %d\n",casenum,ans);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin>>T;
  for (int i=1;i<=T;i++) {
    solve(i);
  }
}
