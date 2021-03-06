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
const int UNDEF = -1;
const ll INF=1LL<<62;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=1e5+4;
vector<int> g[mn];
int vdest[mn],vc[mn];
ll vdist[mn];
vector<int> vreq;
typedef pair<ll,int> pli;
bool vneed[mn];
int n;
void dij() {
	int needleft=vreq.size();
	if (needleft==0) return;
	for (auto &x:vreq) {
		vneed[x]=true;
	}
	priority_queue<pli,vector<pli>,greater<pli> > pq;
	fill(vdist+2,vdist+n+1,INF);
	pq.push(MP(0LL,1));
	while(!pq.empty()) {
		auto got=pq.top(); pq.pop();
		ll dist=got.fst; int x=got.snd;
		if (dist>vdist[x]) continue;
		if (vneed[x]) {
			vneed[x]=false;
			needleft--;
			if (needleft==0) break;
		}
		for (auto &ei:g[x]) {
			int y=vdest[ei],cost=vc[ei];
			ll ndist=dist+cost;
			if (ndist<vdist[y]) {
				vdist[y]=ndist;
				pq.push(MP(ndist,y));
			}
		}
	}
	for (auto &x:vreq) {
		ll ans=vdist[x];
		if (ans>=INF) {
			printf("-1\n");
		}
		else printf("%lld\n",ans);
		vneed[x]=false;
	}
	vreq.clear();
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(); int m=rint(),qn=rint();
  for (int i=0;i<m;i++) {
  	int x=rint();vdest[i]=rint(),vc[i]=rint();
  	g[x].PB(i);
  }
  for (int qi=0;qi<qn;qi++) {
  	int t=rint();
  	if (t==1) {
  		int v=rint();
  		vreq.PB(v);
  	}
  	else {
  		dij();
  		int c=rint();
  		for (int i=0;i<c;i++) {
  			int ei=rint()-1;
  			vc[ei]++;
  		}
  	}
  }
  dij();
}





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