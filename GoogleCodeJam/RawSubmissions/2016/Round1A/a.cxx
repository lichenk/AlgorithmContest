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
		string s; cin>>s;
		ll n=s.length();
		string ans="";
		for (ll x=0;x<n;x++) {
			char c=s[x];
			if (ans+c>=c+ans) {
				ans=ans+c;
			}
			else {
				ans=c+ans;
			}
		}
		cout << "Case #" << casenum << ": " << ans << endl;
	}
}
