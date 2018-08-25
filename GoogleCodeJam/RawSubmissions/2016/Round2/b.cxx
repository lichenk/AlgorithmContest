#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll MAXN=204;
ld a[MAXN];
ld f[MAXN][MAXN];
ld b[MAXN];
int main() {
	cout<<fixed;
	cout.precision(100);
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n,k; cin>>n>>k;
		for (ll i=0;i<n;i++) {
			cin>>b[i];
		}
		sort(b,b+n);
		ld final = 0;
		for (ll p=0;p<=k;p++) {
			ll idx=0;
			for (ll i=0;i<p;i++) {
				a[idx]=b[i];
				idx++;
			}
			for (ll i=0;i<(k-p);i++) {
				a[idx]=b[n-1-i];
				idx++;
			}
			assert(idx==k);
			for (ll x=0;x<MAXN;x++) {
				for (ll y=0;y<MAXN;y++) {
					f[x][y]=0;
				}
			}
			f[0][0]=1;
			for (ll x=0;x<k;x++) {
				for (ll y=0;y<=k;y++) {
					ld val=f[x][y];
					f[x+1][y+1]+=a[x]*val;
					f[x+1][y]+=(1-a[x])*val;
				}
			}
			ld ans=f[k][k/2];
			final=max(final,ans);
		}
		cout << "Case #" << casenum << ": " << final << endl;
	}
}
