#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
int main() {
	cout.precision(300);
	ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n; cin>>n;
		map<ll,ll> h;
		for (ll x=0;x<2*n-1;x++) {
			for (ll y=0;y<n;y++) {
				ll k; cin>>k;
				h[k]++;
			}
		}
		vector<ll> ans;
		for (auto &w: h) {
			if ((w.second%2)==1) {
				ans.PB(w.first);
			}
		}
		cout << "Case #" << casenum << ":";
		for (auto &w: ans) {
			cout<<" "<<w;
		}
		cout<<endl;
	}
}
