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
//const int mv=64;
const int mv=300;
const int mc=((mv*(mv-1))/2)+1;
const int ma=31;
bitset<mc> f[2][ma];
void reset() {
	for (int v=0;v<2;v++) for (int ai=0;ai<ma;ai++) f[v][ai].reset();
}
int solve(vector<int> &a) {
	sort(a.begin(),a.end());
	int alim=a.size();
	if (alim==1) {
		if (a[0]==0) return 1;
		else return 0;
	}
	f[1][0][a[0]]=true;
	//printf("%d\n",(int)f[1][0][a[0]]);
	for (int v=2;v<mv;v++) {
		for (int ai=0;ai<alim;ai++) {
			f[(v&1)][ai].reset();
		}
		for (int sai=0;sai<alim;sai++) {
			/*bool got=0;
			for (int x=0;x<mc;x++) {
				if ((f[(v&1)^1][sai])[x]) {printf("%d ",x); got=1;}
			}
			if (got)printf(" end sai:%d v:%d dbg:%d\n",sai,v,a[0]);*/
			for (int dai=sai;dai<=min(alim-1,sai+1);dai++) {
				int shift=a[dai];
				f[(v&1)][dai]|=(f[(v&1)^1][sai]<<shift);
			}
		}
		/*for (int sai=0;sai<alim;sai++) {
			bool got=0;
			for (int x=0;x<mc;x++) {
				if (f[(v&1)][sai][x]) {printf("%d ",x); got=1;}
			}
			if (got)printf(" end sai:%d v:%d dest\n",sai,v);
		}*/
		int klim=(v*(v-1))/2;
		if (f[(v&1)][alim-1][klim]) return v;
		bitset<mc> filt; filt.set(); filt>>=klim; filt<<=klim;
		for (int ai=0;ai<alim;ai++) {
			f[(v&1)][ai]&=filt;
		}
	}
	return 0;
}
int maxx=0;
void test() {
	reset();
	vector<int>va;
	int p=(rand()%100);
	for (int x=0;x<=30;x++) {
		if (rand()%100 <= p) va.PB(x);
	}
	if (va.size()==0) va.PB(rand()%31);
	int res=solve(va);
	printf("%d,",res); fflush(stdout);
	chkmax(maxx,res);
	assert(res<64);
}
void go() {
	for (int k=0;k<10000;k++) {
		srand(clock());
		test();
	}
}
int main() 
{
	go();
	printf("Passed maxx:%d\n",maxx);
  /*ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); vector<int> va; va.reserve(n);
  for (int i=0;i<n;i++) {
  	int x=rint(); va.PB(x);
  }
  assert(solve(va));*/
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