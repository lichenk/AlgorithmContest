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
const int mn=1e5+4;

int va[mn],vl[mn],vr[mn];
ll vd[mn];
int vtmp[mn];
ll vt[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint(),k=rint();
	for (int i=1;i<=n;i++) va[i]=rint();
	for (int i=1;i<=m;i++) {
		vl[i]=rint();vr[i]=rint();vd[i]=rint();
	}
	for (int i=1;i<=k;i++) {
		int x=rint(),y=rint();
		vtmp[x]++; vtmp[y+1]--;
	}
	for (int i=1;i<=m;i++) {
		vtmp[i]+=vtmp[i-1];
		vd[i]*=vtmp[i];
	}
	for (int i=1;i<=m;i++) {
		vt[vl[i]]+=vd[i];
		vt[vr[i]+1]-=vd[i];
	}
	for (int i=1;i<=n;i++) {
		vt[i]+=vt[i-1];
		ll ans=vt[i]+va[i];
		printf("%lld ",ans);
	}
	printf("\n");
}

