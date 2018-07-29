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
typedef vector<int> vi;
bool solve(int xlim, int ylim, vector<string> s){
	for (auto &x:s) for (auto &y:x) y-='a';
	int sz=(xlim+1)/2;
	for (int z=0;z<(1<<xlim);z++) {
		if (__builtin_popcount(z)!=sz) continue;
		vector<int> vx,ox;
		for (int x=0;x<xlim;x++) {
			if (z&(1<<x)) vx.PB(x);
			else ox.PB(x);
		}
		do {
			map<ll,int> h;
			map<ll,int> g;
			for (int y=0;y<ylim;y++) {
				ll got=0;
				for (int i=0;i<sz;i++) {
					got*=26;
					got+=s[vx[i]][y];
				}
				for (int i=0;i<ox.size();i++) {
					got*=26;
					got+=s[ox[i]][y];
				}
				ll rev=0;
				for (int i=ox.size()-1;i>=0;i--) {
					rev*=26;
					rev+=s[ox[i]][y];
				}
				for (int i=sz-1;i>=0;i--) {
					rev*=26;
					rev+=s[vx[i]][y];
				}
				if (got!=rev) {
					++h[got];
					--h[rev];
				}
				else {
					++g[got];
				}
			}
			int odd=0;
			for (auto &w:h) {
				if (w.snd) odd=1e9;
			}
			for (auto &w:g) {
				odd+=(w.snd&1);
			}
			if (odd<=1)return true;
		} while(next_permutation(vx.begin(),vx.end()));
	}
	return false;
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long H;
	long long W;
	cin>>H;
	vector<string> S(H-1+1);
	cin>>W;
	for(int i = 0 ; i <= H-1 ; i++){
		cin >> S[i];
	}
	bool ans=solve(H, W, S);
	if (ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}

