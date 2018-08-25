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
const ll maxn=55;
ll r[maxn];
ll q[maxn][maxn];
ll cachehi[maxn][maxn];

ll n,p;
ll gethiservings(ll need, ll have) {
	ll num=10*have;
	ll denom=9*need;
	return num/denom;
}

ll getloservings(ll need, ll have) {
	ll num=10*have;
	ll denom=11*need;
	return (num+denom-1)/denom;
}

void solve(ll testnum) {
	cin>>n>>p;
	for (ll i=0;i<n;i++) cin>>r[i];
	for (ll i=0;i<n;i++) {
		for (ll j=0;j<p;j++) {
			cin>>q[i][j];
		}
	}
	set<ll> s;
	map<ll, set<ll> > vlo[maxn];
	map<ll, set<ll> > vhi[maxn];
	for (ll i=0;i<n;i++) sort(q[i],q[i]+p);
	for (ll x=0;x<n;x++) {
		for (ll y=0;y<p;y++) {
			ll lo=getloservings(r[x], q[x][y]);
			ll hi=gethiservings(r[x], q[x][y])+1;
			//printf("lo:%d hi:%d\n",lo,hi);
			if (lo>=hi) continue;
			cachehi[x][y]=hi;
			s.insert(lo);
			s.insert(hi);
			vlo[x][lo].insert(y);
			vhi[x][hi].insert(y);
		}
	}
	set<pll> active[maxn];
	ll finalans=0;
	for (auto &tim:s) {
		ll take=INF;
		for (ll x=0;x<n;x++) {
			{
				auto it=vhi[x].find(tim);
				if (it!=vhi[x].end()) {
					for (auto &y:it->snd) {
						ll hi=cachehi[x][y];
						active[x].erase(MP(hi,y));
					}
				}				
			}
			{
				auto it=vlo[x].find(tim);
				if (it!=vlo[x].end()) {
					for (auto &y:it->snd) {
						ll hi=cachehi[x][y];
						active[x].insert(MP(hi,y));
					}
				}
			}
			chkmin(take, (ll)active[x].size());
		}
		for (ll x=0;x<n;x++) {
			for (ll i=0;i<take;i++) {
				auto it=active[x].begin();
				ll y=it->snd;
				ll hi=it->fst;
				active[x].erase(it);
				vhi[x][hi].erase(y);
			}
		}
		finalans+=take;
	}
	cout<<"Case #"<<testnum<<": "<<finalans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; cin>>numtests;
	for (ll testnum=1;testnum<=numtests;testnum++) {
		solve(testnum);
	}
}

