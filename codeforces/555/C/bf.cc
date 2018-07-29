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
const int mn=100+4;
int a[mn][mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,q; scanf("%d %d\n",&n,&q);	
	for (ll ii=0;ii<q;ii++) {
		int x,y; char c; scanf("%d %d %c\n",&x,&y,&c);
		int ans=0;
		if (c=='U') {
			for (;y>=1;y--) {
				//printf("x:%d y:%d\n",x,y);
				if (a[x][y]) break;
				else {a[x][y]=1; ans++;}
			}
		}
		else {
			for (;x>=1;x--) {
				if (a[x][y]) break;
				else {a[x][y]=1; ans++;}
			}
		}
		printf("%d\n",ans);
	}
}

