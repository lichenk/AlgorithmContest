#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
#define PERIOD '.'
#define UP '^'
#define RIGHT '>'
#define DOWN 'v'
#define LEFT '<'
map<ll,char> *row, *col;

bool findalt(ll x, ll y) {
	map<ll,char>::iterator rit = row[y].find(x);
	if (rit->first != row[y].begin()->first || rit->first != row[y].rbegin()->first) {
		return true;
	}
	map<ll,char>::iterator cit = col[x].find(y);
	if (cit->first != col[x].begin()->first || cit->first != col[x].rbegin()->first) {
		return true;
	}
	return false;
}

int main() {
	cout.precision(300);
	//ios::sync_with_stdio(false);
	ll cases;
	cin >> cases;
	for (ll casenum = 1; casenum <= cases; casenum++) {
		ll r,c; cin >> r; cin >> c;
		row = new map<ll,char>[r];
		col = new map<ll,char>[c];
		for (ll y = 0; y < r; y++) {
			for (ll x = 0; x < c; x++) {
				char arrow; cin >> arrow;
				if (arrow != PERIOD) {
					row[y][x] = arrow;
					col[x][y] = arrow;
				}
			}
		}
		ll ans = 0;
		bool ok = true;
		for (ll y = 0; y < r; y++) {
			if (row[y].size() > 0) {
				{
					map<ll,char>::iterator it = row[y].begin();
					if (it->second == LEFT) {
						ans++;
						ok = ok && findalt(it->first, y);
					}
				}
				map<ll,char>::reverse_iterator rit = row[y].rbegin();
				if (rit->second == RIGHT) {
					ans++;
					ok = ok && findalt(rit->first, y);
				}
			}
		}
		for (ll x = 0; x < c; x++) {
			if (col[x].size() > 0) {
				{
					map<ll,char>::iterator it = col[x].begin();
					if (it->second == UP) {
						ans++;
						ok = ok && findalt(x,it->first);
					}
				}
				map<ll,char>::reverse_iterator rit = col[x].rbegin();
				if (rit->second == DOWN) {
					ans++;
					ok = ok && findalt(x,rit->first);
				}
			}
		}
		if (ok) {
			cout << "Case #" << casenum << ": " << ans << endl;
		}
		else {
			cout << "Case #" << casenum << ": " << "IMPOSSIBLE" << endl;
		}
	}
}
