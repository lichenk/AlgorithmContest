#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
set<pll> s;
vector<pll> v;
ll vans[20];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll h,w,n; cin>>h>>w>>n;
	for (ll i=0;i<n;i++) {
		ll a,b; cin>>a>>b;
		s.insert(MP(a,b));
		v.PB(MP(a,b));
	}
	for (ll i=0;i<20;i++) vans[i]=0;
	for (auto &ww:v) {
		ll origa=ww.first,origb=ww.second;
		for (ll a=origa-1;a<=origa+1;a++)for (ll b=origb-1;b<=origb+1;b++){
			if (!(2<=a&&a<=h-1)) continue;
			if (!(2<=b&&b<=w-1)) continue;
			ll cnt=0;
			for (ll x=a-1;x<=a+1;x++) for (ll y=b-1;y<=b+1;y++) {
				pll sig=MP(x,y);
				if (s.find(sig)!=s.end()) cnt++;
			}
			//cout<<a<<","<<b<<":"<<cnt<<endl;
			vans[cnt]++;
		}
	}
	ll have=0;
	for (ll j=1;j<=9;j++) {vans[j]/=j; have+=vans[j];}
	vans[0]=((h-2)*(w-2))-have;
	for (ll j=0;j<=9;j++) cout<<vans[j]<<endl;

}