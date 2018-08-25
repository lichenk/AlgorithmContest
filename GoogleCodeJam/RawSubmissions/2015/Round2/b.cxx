#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
pair<ld,ld> *a;
#define EPS 0.000000000000001
ld gettemp(ll start, ll end) {
	ld numer = 0; ld denom = 0;
	for (ll i = start; i <= end; i++) {
		numer += (a[i].first * a[i].second);
		denom += a[i].second;
	}
	return numer/denom;
}

ld solve(ll start, ll end, ld ft) {
	ld numer = 0;
	for (ll i = start; i < end; i++) {
		numer += ((ft * a[i].second) - (a[i].second * a[i].first));
	}
	return numer/(a[end].first - ft);
}

ld sum(ll start, ll end) {
	ld ans = 0;
	for (ll i = start; i <= end; i++) {
		ans += a[i].second;
	}
	return ans;
}

int main() {
	cout.precision(300);
	//ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll n; cin >> n;
		ld fv, ft; cin >> fv; cin >> ft;
		a = new pair<ld,ld>[n];
		for (ll i = 0; i < n; i++) {
			// First is temperature, second is flow
			cin >> a[i].second; cin >> a[i].first;
		}
		ld temp = gettemp(0,n-1);
		ll start = 0; ll end = n-1;
		if (temp > ft + EPS) {
			sort(a,a+n);
			while (temp > ft + EPS) {
				end--;
				if (end < start) break;
				temp = gettemp(start,end);
			}
		}
		else if (temp < ft - EPS) {
			sort(a,a+n,greater<pair<ld,ld> >());
			while (temp < ft - EPS) {
				end--;
				if (end < start) break;
				temp = gettemp(start,end);
			}
		}
		else {
			ld allflow = sum(start,end);
			ld ans = fv / allflow;
			cout << "Case #" << casenum << ": " << ans << endl;
			continue;
		}
		if (end < start) {
			cout << "Case #" << casenum << ": " << "IMPOSSIBLE" << endl;
		}
		else {
			//cout << temp << " " << ft << " " << start << " " << end << endl;
			end++;
			ld allflow;
			if (start == end || end >= n) {
				if (abs(temp - ft) < EPS) {
					allflow = sum(start,end);
				}
				else {
					cout << "Case #" << casenum << ": " << "IMPOSSIBLE" << endl;
					continue;
				}
			}
			else {
				ld endflow = solve(start,end,ft);
				//cout << "ef:" << endflow << endl;
				allflow = sum(start,end-1) + endflow;
			}
			ld ans = fv / allflow;
			cout << "Case #" << casenum << ": " << ans << endl;
		}
	}
}
