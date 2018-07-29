#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = 1<<30;
const ll INIT = 1+(1<<30);
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=2000+1;
string s[MAXN];
pair<string,ll> v[MAXN];
ll val[MAXN];
const ll MAXK=10000+1;
ll f[MAXN][MAXK];
bool cmp(const pair<string,ll> &a, const pair<string,ll> &b) {
	return (a.first+b.first)<(b.first+a.first);
}
int main() {
	ios_base::sync_with_stdio(false);
	ll n,k; cin>>n>>k;
	for (ll i=0;i<n;i++) cin>>s[i];
	reverse(s,s+n);
	for (ll i=0;i<n;i++) v[i]=MP(s[i],i);
	sort(v,v+n,cmp);
	for (ll i=0;i<n;i++) {
		val[v[i].second]=i;
	}
	for (ll x=0;x<=k;x++) f[0][x]=UNDEF;
	f[0][0]=INIT;
	for (ll t=0;t<n;t++) {
		ll len=s[t].length();
		for (ll x=0;x<=k;x++) f[t+1][x]=f[t][x];
		for (ll x=0;x<=k-len;x++) {
			if (f[t][x]!=UNDEF) chkmin(f[t+1][x+len], val[t]);
		}
	}
	vector<ll> ans;
	{
		ll t=n; ll p=k;
		while(p>0) {
			ll value=f[t][p];
			ll sidx=v[value].second;
			ans.PB(sidx);
			ll len=s[sidx].length();
			t=sidx; p-=len;
		}
		assert(p==0);
	}
	//reverse(ans.begin(),ans.end());
	for (auto &w: ans) {
		cout<<s[w];
	}
	cout<<endl;
}