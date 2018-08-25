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


int rint()
{
  int x; scanf("%d",&x); return x;
}
string a[100];
bitset<100> b;
int n,m;
int lt(int r1, int r2) {
	for (int i=0;i<m;i++) {
		if (b[i]) continue;
		if (a[r1][i]<a[r2][i]) return -1;
		if (a[r1][i]>a[r2][i]) return i;
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	int klim=n*m;
	for (int k=0;k<=klim;k++) {
		for (int r=0;r<n-1;r++) {
			int c=lt(r,r+1);
			if (c!=-1) b[c]=1;
		}
	}
	printf("%d\n",(int)b.count());
}

