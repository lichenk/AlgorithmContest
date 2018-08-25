#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll INF=1ULL<<60ULL;
const ll UNDEF=-1;
const ll MAXX=50;
const ll MAXK=50;
string dp[MAXX][MAXK];
bool dpv[MAXX][MAXK];
string solve(ll x, ll k) {
	if (dpv[x][k]) return dp[x][k];
	if (k==0) {
		string ans;
		if (x==0) ans="R";
		else if (x==1) ans="P";
		else if (x==2) ans="S";
		else assert(false);
		dp[x][k]=ans; dpv[x][k]=true;
		return ans;
	}
	else {
		string b[2];
		ll idx=0;
		for (ll y=0;y<3;y++) {
			if (x==y) continue;
			b[idx]=solve(y,k-1);
			idx++;
		}
		string ans=min(b[0]+b[1],b[1]+b[0]);
		dp[x][k]=ans; dpv[x][k]=true;
		return ans;
	}
}
int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	for (ll x=0;x<MAXX;x++) {
		for (ll k=0;k<MAXK;k++) {
			dpv[x][k]=false;
		}
	}
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n; cin>>n;
		ll a[3];
		for (ll i=0;i<3;i++) cin>>a[i];
		string ans="IMPOSSIBLE";
		for (ll e=0;e<3;e++) {
			string cand=solve(e,n);
			ll c[3];
			for (ll x=0;x<3;x++) c[x]=0;
			for (ll i=0;i<(1LL<<n);i++) {
				if (cand[i]=='R') c[0]++;
				else if (cand[i]=='P') c[1]++;
				else if (cand[i]=='S') c[2]++;
			}
			assert(cand.length()==1LL<<n);
			bool ok=true;
			for (ll x=0;x<3;x++) {
				if (a[x]!=c[x]) ok=false;
			}
			if (ok) {
				if (ans=="IMPOSSIBLE") ans=cand;
				else {
					ans=min(ans,cand);
				}
			}
		}
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}
