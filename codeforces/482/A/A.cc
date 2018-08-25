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

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,k; scanf("%d%d",&n,&k);
	int prefix=n-k-1;
	vector<int> v;
	for (int x=1;x<=prefix;x++) {
		v.PB(x);
	}
	int l=prefix+1,r=n;
	for (int q=0;q<n-prefix;q++) {
		if (0==(q&1)) {
			v.PB(l++);
		}
		else {
			v.PB(r--);
		}
	}
	for (auto &w:v) printf("%d ",w);
	printf("\n");
}

