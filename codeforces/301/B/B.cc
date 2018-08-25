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
const int mn=100;
int a[mn],px[mn],py[mn];
int n,d;
bool isedge[mn][mn];
int vcost[mn][mn];
int vdist[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),d=rint();
  for (int i=1;i<n-1;i++) {
    a[i]=rint();
  }	
  for (int i=0;i<n;i++) px[i]=rint(),py[i]=rint();
  for (int s=0;s<n;s++) for (int t=0;t<n;t++) {
  	if (s!=t) {
  		int c=d*(abs(px[s]-px[t])+abs(py[s]-py[t])) - a[s];
  		vcost[s][t]=c;
  		isedge[s][t]=true;
  	}
  }
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	for (int x=0;x<n;x++) vdist[x]=1<<29;
	vdist[0]=0; pq.push(MP(0,0));
	while(!pq.empty()) {
		auto got=pq.top(); pq.pop();
		int dist=got.fst,x=got.snd;
		if (dist>vdist[x]) continue;
		for (int y=0;y<n;y++) {
			if (!isedge[x][y]) continue;
			int cost=vcost[x][y];
			int ndist=dist+cost;
			if (ndist<vdist[y]) {
				vdist[y]=ndist;
				pq.push(MP(ndist,y));
			}
		}
	}
  printf("%d\n",vdist[n-1]);
}
