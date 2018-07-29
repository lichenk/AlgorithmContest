#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
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
ll gid=0;
ll getid() {
	return ++gid;
}
const ll mn=2e5+4;
ll a[mn];
vll d2v[mn];
ll firstlone[mn];
ll numlone[mn];
ll sub(ll x) {
	if (numlone[x]<=firstlone[x]) return -1;
	if (firstlone[x]) {
		return numlone[x]-2;
	}
	else return numlone[x]-1;
}
ll firstcnt[mn];
vll g[mn];
bool seen[mn];
void dfs(ll x) {
	seen[x]=1;
	for (auto &y:g[x]) dfs(y);
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,t,k; scanf("%d%d%d",&n,&t,&k);
	for (ll i=1;i<=t;i++) {scanf("%d",&a[i]);}
	d2v[0].PB(getid());
	for (ll d=1;d<=t;d++) {
		for (ll i=0;i<a[d];i++) d2v[d].PB(getid());
	}
	ll have=0;
	for (ll d=1;d<t;d++) {
		if (a[d+1]<=a[d]) firstlone[d]=1;
		numlone[d]=min(a[d],a[d+1]) + firstlone[d]-1;
		have+=numlone[d];
	}
	for (ll d=1;d<t;d++) {
		ll later=sub(d);
		if (firstlone[d]&&later>=k) {
			firstcnt[d]++;
			have=later;
		}
	}
	for (ll d=1;d<t;d++) {
		while(1) {
			ll later=sub(d);
			if (later>=k) {
				firstcnt[d]++;
				have=later;
			}
			else break;
		}
	}
	if (have!=k) {
		printf("-1\n"); return 0;
	}
	for (ll d=0;d<t;d++) {
		vll now=d2v[d];
		vll next=d2v[d+1];
		auto it=next.begin();
		for (ll i=0;i<firstcnt[d];i++) {
			g[now[0]].PB(*it);
			++it;
		}
		ll idx=1;
		for (;idx<now.size()&&it!=next.end();++it,++idx) {
			g[now[idx]].PB(*it);
		}
		for (;it!=next.end();++it) g[now[0]].PB(*it);
	}
	dfs(1);
	for (ll x=1;x<=n;x++) {
		if (!seen[x]) {
			printf("-1\n"); return 0;
		}
	}
	printf("%d\n",n);
	for (ll x=1;x<=n;x++) {
		for (auto &y:g[x]) {
			printf("%d %d\n",x,y);
		}
	}
}

