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
char a[504][504];
char b[2][504][504];
int main() {
	ios_base::sync_with_stdio(false);
	ll rlim,clim; cin>>rlim>>clim;
	for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) {
		cin>>a[r][c];
	}
	for (ll t=0;t<2;t++) for (ll r=0;r<rlim;r++) for (ll c=0;c<clim;c++) {
		b[t][r][c]=a[r][c];
	}
	for (ll k=0;;k++) {
		ll ox=k,oy=k;
		ll ex=rlim-k-1,ey=clim-k-1;
		if (ox>=ex||oy>=ey) break;
		//printf("ox:%lld ex:%lld oy:%lld ey:%lld\n",ox,ex,oy,ey);
		ll c=k&1;
		ll d=c^1;
		for (ll x=ox+1;x<=ex;x++) {
			b[c][x][oy]='#';
		}
		for (ll y=oy;y<=ey;y++) {
			b[c][ex][y]='#';
		}
		for (ll y=oy;y<=ey;y++) {
			b[d][ox][y]='#';
		}
		for (ll x=ox;x<ex;x++) {
			b[d][x][ey]='#';
		}
	}
	for (ll t=0;t<2;t++) {
		for (ll r=0;r<rlim;r++) {
			for (ll c=0;c<clim;c++) {
				cout<<b[t][r][c];
			}
			cout<<endl;
		}
		cout<<endl;
	}
}