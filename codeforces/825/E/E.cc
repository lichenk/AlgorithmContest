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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
const int mn=1e5+4;
vector<int> rg[mn];
int degout[mn];
int vans[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    rg[y].PB(x);
    degout[x]++;
  }
  priority_queue<int> pq;
  for (int x=1;x<=n;x++) {
  	if (degout[x]==0) {
  		pq.push(x);
  	}
  }
  int gid=n;
  while(!pq.empty()) {
  	int x=pq.top(); pq.pop();
  	vans[x]=gid--;
  	for (auto &y:rg[x]) {
  		if ((--degout[y])==0) {
  			pq.push(y);
  		}
  	}
  }
  for (int x=1;x<=n;x++) printf("%d ",vans[x]); printf("\n");
}

