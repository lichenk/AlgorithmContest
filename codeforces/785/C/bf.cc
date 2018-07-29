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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int INF=1000*1000*1000+7;
const ll LINF=INF*(ll)INF;
ll n,m;
bool ok(ll k) {
	return ((2*(n-m)<=k*(k+1)));
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	if (m>=n) {
		cout<<n<<endl;
		return 0;
	}
	ll ans=m;
	ll l=1,r=LINF;
	while(l+1<r) {
		ll k=(l+r)/2;
		ll v1=(ll)k*(k+1)/2;
		if (v1>=n-m)r=k;
		else l=k;
	}
	ans+=r;
	cout<<ans<<endl;
}
