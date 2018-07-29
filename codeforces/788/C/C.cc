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
ll n;
const int mn=1e3+2;
bool a[mn];
const int mx=1e4;
ll h[(mx*2)+2];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k;
	scanf("%lld%d",&n,&k);
	for (int i=0;i<k;i++) {
		int x; scanf("%d",&x);
		a[x]=true;
	}
	vll v;
	for (ll x=0;x<=1000;x++) {
		if (!a[x]) continue;
		if (x==n) {
			printf("0\n");
			return 0;
		}
		ll y=x-n;
		
	}
}

