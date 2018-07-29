#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int mn=204;
int dp[mn][mn][mn];

int f(int a, int b, int c) {
	if (a==b&&b==c) return 0;
	if (a<mn&&b<mn&&c<mn) {
		int dpval=dp[a][b][c];
		if (dpval!=-1) return dpval;
		int ans=min({
			f(a+2,b,c),
			f(a,b+2,c),
			f(a,b,c+2),
			f(a+1,b+1,c),
			f(a+1,b,c+1),
			f(a,b+1,c+1)
			})+1;
		return dp[a][b][c]=ans;
	}
	else return INF;
}

void solve(long long A, long long B, long long C){
	memset(dp,-1,sizeof dp);
	int ans=f(A,B,C);
	printf("%d\n",ans);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long A;
	long long C;
	long long B;
	scanf("%lld",&A);
	scanf("%lld",&B);
	scanf("%lld",&C);
	solve(A, B, C);
	return 0;
}

