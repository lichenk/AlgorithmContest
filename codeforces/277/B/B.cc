#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
const int LIM=10000*10000;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
	if (m==3) {
		if (n==3) {
			printf("0 0\n0 1\n1 0\n");
		}
		else if (n==4) {
			printf("0 0\n3 0\n0 3\n1 1\n");
		}
		if (n>=5) {
			printf("-1\n");
		}
	}
	else {
		{
			int y=0;
			for (int x=0;x<m;x++) {
				printf("%d %d\n",-LIM+x,y);
				y+=(x+1);
			}
		}
		{
			int y=0;
			for (int x=0;x<n-m;x++) {
				printf("%d %d\n",LIM-x,y);
				y+=(x+1);
			}
		}
	}
}
