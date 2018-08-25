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
const ll maxn=200;
string a[maxn];
bool isemp[maxn];
void solve(ll testnum) {
	ll rlim,clim; cin>>rlim>>clim;
	for (ll r=0;r<rlim;r++) {
		cin>>a[r];
	}
	memset(isemp,0,sizeof isemp);
	ll notemp=-1;
	for (ll r=0;r<rlim;r++) {
		char firstchar='.';
		for (ll c=0;c<clim;c++) {
			if (a[r][c]!='?') {
				firstchar=a[r][c]; break;
			}
		}
		if (firstchar=='.') {
			isemp[r]=true;
		}
		else {
			for (ll c=0;c<clim;c++) {
				if (a[r][c]=='?') {
					a[r][c]=firstchar;
				}
				else firstchar = a[r][c];
			}
			notemp=r;
		}
	}
	assert(notemp!=-1);
	for (ll r=notemp-1;r>=0;r--) {
		if (isemp[r]) a[r]=a[r+1];
	}
	for (ll r=notemp+1;r<rlim;r++) {
		if (isemp[r]) a[r]=a[r-1];
	}
	cout<<"Case #"<<testnum<<":"<<endl;
	for (ll r=0;r<rlim;r++) cout<<a[r]<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; cin>>numtests;
	for (ll testnum=1;testnum<=numtests;testnum++) {
		solve(testnum);
	}
}

