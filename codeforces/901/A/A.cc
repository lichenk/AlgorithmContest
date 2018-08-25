#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=3e5;
int a[mn];
int g[mn];
void fail(int t) {
	printf("perfect\n"); exit(0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int hlim=rint();
  int sh=-1;
  for (int h=0;h<=hlim;h++) a[h]=rint();
  for (int h=0;h<hlim;h++){
  	if (a[h]!=1&&a[h+1]!=1) sh=h;
  }
  if (sh==-1) {
  	fail(1);
  }
  {
  	printf("ambiguous\n");
  	for (int b=0;b<2;b++) {
  		vector<int> p; p.PB(0);
  		int id=1;
  		for (int h=0;h<=hlim;h++) {
  			vector<int> newp;
  			for (int t=0;t<a[h];t++) {
  				newp.PB(id);
  				int ans=p[0];
  				if (b==1&&h==sh+1&&t==1) {
  					ans=p[1];
  				} 
  				printf("%d ",ans);
  				id++;
  			}
  			//printf("h:%d a:%d\n",h,a[h]); fflush(stdout);
  			assert(newp.size()>0);
  			p=newp;
  		}
  		printf("\n");
  	}
  }

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