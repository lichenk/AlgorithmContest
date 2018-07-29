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
const ll INF=1e18+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1004;
ll B[mn];
ll c[10];
vll va;
string A;
void dfs(ll pos, ll have) {
	//printf("pos:%d have:%lld\n",pos,have);
	if (pos==A.length()) {
		string res=to_string(have);
		if (res.length()==A.length()) {
			va.PB(have);
		}
	}
	for (ll d=0;d<10;d++) {
		ll shit=(ll)(A[pos]-'0');
		//printf("%lld != %lld: %d\n",shit,d,shit!=d);
		if (A[pos]!='?'&&shit!=d) continue;
		dfs(pos+1,have*10+d);
	}
}
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin>>A;
	ll n; cin>>n;
	for (ll i=0;i<n;i++) cin>>B[i];
	for (ll i=0;i<10;i++) cin>>c[i];
	dfs(0,0);
	ll final=-INF;
	for (auto &a:va) {
		ll ans=0;
		for (ll i=0;i<n;i++) {
			ll res=B[i]+a;
			string s=to_string(res);
			for (ll h=0;h<s.length();h++) {
				char ch=s[h];
				ans+=c[ch-'0'];
			}
		}
		chkmax(final,ans);
	}
	printf("%lld\n",final);
}
