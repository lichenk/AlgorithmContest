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
const ll INF=1e18;
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
const int mn=5e7;
int f[mn];
int g[mn];
//vector<int> vp={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
unordered_set<int> final;
void go(int lo, int lim, int steps, int maxk) {
	f[0]=1;
	g[0]=0;
	int sz=1;
	int k=sz;
	for (int p=2;p<=maxk;p++) {
		for (int i=0;i<sz;i++) {
			int x=f[i];
			int gi=g[i];
			while(1) {
				if (__builtin_smul_overflow (x, p, &x)) break;
				if (x>lim) break;
				++gi;
				if (gi>steps) break;
				if (x>=lo) final.insert(x);
				f[k]=x;
				g[k]=gi;
				++k;
			}
		}
		sz=k;
	}
	//printf("sz:%d\n",sz);
	//return sz;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int l=rint(),r=rint(),p=rint();
  for (int maxk=2;maxk<p;maxk++) {
  	go(l,r,p-maxk,maxk);
  }
  int ans=final.size();
  if (l==1) ans++;
  printf("%d\n",ans);
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