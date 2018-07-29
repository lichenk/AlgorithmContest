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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

void solve(string s, string t){
	if ((s+s).find(t)!=-1) printf("Yes\n");
	else printf("No\n");
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	string S;
	string T;
	cin >> S;
	cin >> T;
	solve(S, T);
	return 0;
}

