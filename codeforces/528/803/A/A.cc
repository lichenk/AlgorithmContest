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
bool a[102][102];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),k=rint();
	for (int x=0;x<n;x++) for (int y=x;y<n;y++) {
		if (x==y) {
			if (k>=1) {
				k--;
				a[x][y]=1;
			}
		}
		else {
			if (k>=2) {
				k-=2;
				a[x][y]=1;
				a[y][x]=1;
			}
		}
	}
	if (k==0) {
		for (int x=0;x<n;x++) {
			for (int y=0;y<n;y++) printf("%d ",(int)a[x][y]);
			printf("\n");
		}
	}
	else printf("-1\n");
}

