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
const int mn=3e6;
int f[mn];
int g[mn];
vector<int> vp={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int go(int lim) {
	f[0]=1;
	int sz=1;
	int k=sz;
	for (auto &p:vp) {
		for (int i=0;i<sz;i++) {
			int x=f[i];
			while(1) {
				if (__builtin_smul_overflow (x, p, &x)) break;
				if (x>lim) break;
				f[k]=x;
				g[k]=p;
				++k;
			}
		}
		sz=k;
	}
	//printf("sz:%d\n",sz);
	return sz;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int l=rint(),r=rint(),p=rint();
  int sz=go(r);
  int ans=0;
  vector<int> fin;
  for (int i=0;i<sz;i++) {
  	int fi=f[i];
  	int gi=g[i];
  	if (fi==58500) printf("CONS gi:%d\n",gi);
  	if (l<=fi&&fi<=r) {
  		for (int maxk=gi;maxk<p;maxk++) {
  			int x=f[i];
  			int lft=p-(maxk);
  			if (fi==58500)printf("maxk:%d\n",maxk);
  			for (int k=maxk;k>=2;k--) {
  				while((x%k)==0) {
  					if (fi==58500)printf("k:%d,",k);
  					x/=k;
  					lft--;
  				}
  				if (lft<=0||x==1) break;
  			}
  			if (fi==58500)printf("lft:%d x:%d\n",lft,x);
  			if (x==1&&lft>=0) {
  				if (fi==58500) printf("PUSH\n");
  				fin.PB(f[i]);
  				ans++;
  				break;
  			}
  		}
  	}
  }
  //printf("%d\n",ans);
  sort(fin.begin(),fin.end());
  //for (auto &w:fin) printf("%d\n",w);
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