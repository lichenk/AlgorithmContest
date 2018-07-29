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
const int ms=735425;
vector<int> vp={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
vector<int> vq={53,59,61,67,71,73,79,83,89,97};
const int LIM=1000*1000*1000;
int f[ms];
const int mk=100;
char g[ms][mk-2];
const int LOGDIV=4;
const int DIV=1<<4;
short h[(LIM/DIV)+2];
void gen() {
	f[0]=1;
	int sz=1;
	int nsz=sz;
	for (auto &p:vp) {
		for (int i=0;i<sz;i++) {
			int x=f[i];
			while(1) {
				if (__builtin_smul_overflow (x, p, &x)) break;
				if (x>LIM) break;
				f[nsz]=x;
				++nsz;
			}
		}
		sz=nsz;
	}
	sort(f,f+ms);
	for (int i=0;i<ms;i++) {
		int x=f[i];
		h[(x>>LOGDIV)+1]=i+1;
	}
	memset(g,127,sizeof g);
	g[0][0]=0;
	for (int xi=0;xi<ms;xi++) {
		int x=f[xi];
		char have=127;
		for (int y=x+x,k=0;y<=LIM&&k<mk;y+=x,k++) {
			chkmin(have,g[xi][k]);
			if (have==127) continue;
			int ydiv=y>>LOGDIV;
			int imin=h[ydiv],imax=h[ydiv+1];
			while(imin<imax) {
				int imid=(imin+imax)>>1;
				if (f[imid]<y) imin=imid+1;
				else imax=imid;
			}
			chkmin(g[imin][k],(char)(have+(char)1));
		}
	}
}
const int mt=1169;
ll vlarge[mt];
void gen2() {
	vlarge[0]=1;
	int sz=1;
	int nsz=sz;
	for (auto &p:vq) {
		for (int i=0;i<sz;i++) {
			int x=vlarge[i];
			int cnt=vlargecnt[i];
			while(1) {
				if (__builtin_smul_overflow (x, p, &x)) break;
				if (x>LIM) break;
				++cnt;
				vlarge[nsz]=((ll)x)<<32|cnt;
				++nsz;
			}
		}
		sz=nsz;
	}
	sort(vlarge,vlarge+mt);
	/*for (int i=0;i<mt;i++) {
		int x=vlarge[i];
		int cnt=vlargecnt[i];
		for (int k=cnt;k<mk;k++) {
			vl[k][vlidx[k]++]=x;
		}
	}
	for (int k=0;k<mk;k++) {
		sort(vl[k],vl[k]+vlidx[k]);
	}*/
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int l,r,p; scanf("%d%d%d\n",&l,&r,&p);
  gen();
  gen2();
  for (int xi=0;xi<ms;xi++) {
  	for (int yi=0;yi<mt;yi++) {

  	}
  }
}