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
typedef unsigned long long ull;
const int mn=250001;
int n;
char a[mn];
// http://www.wolframalpha.com/input/?i=NextPrime%5B4294967296,-2%5D
const unsigned int P[]={4294967291U,4294967279U};
const unsigned int B[]={500009,500029};
const int PN=2;
const int MAXPOW=2*mn;
unsigned int basepow[PN][MAXPOW];
void init() {
	for (int t=0;t<PN;t++) {
		unsigned int b=B[t],p=P[t];
		unsigned int now=1;
		for (int i=0;i<MAXPOW;i++) {
			basepow[t][i]=now;
			now=(now*(unsigned long long)b)%p;
		}
	}
}

map<ull,vector<int> > h;

int vpos[mn];


int bins(vector<int> &v, int key) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin; 
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d\n%s\n",&n,a);
	{
		int pos=mn;
		for (int i=0;i<n;i++) {
			if (a[i]=='<') --pos;
			else if (a[i]=='>') ++pos;
			vpos[i]=pos;
		}
	}

	{
		unsigned int vsig[2]; vsig[0]=vsig[1]=0;
		h[0].PB(-1);
		for (int i=0;i<n;i++) {
			int pos=vpos[i];
			if (a[i]=='+') {
				for (int t=0;t<PN;t++) vsig[t]+=basepow[t][pos];
			}
			else if (a[i]=='-') {
				for (int t=0;t<PN;t++) vsig[t]-=basepow[t][pos];
			}
			ull sig=((ull)vsig[0]<<32)|vsig[1];
			h[sig].PB(i);
		}
	}

	for (auto &w:h) {
		sort(w.snd.begin(),w.snd.end());
	}

	ll ans=0;
	ans+=bins(h[0],n-2);
	{
		unsigned int vsig[2]; vsig[0]=vsig[1]=0;
		for (int i=n-1;i>=0;i--) {
			int pos=vpos[i];
			if (a[i]=='+') {
				for (int t=0;t<PN;t++) vsig[t]+=basepow[t][pos];
			}
			else if (a[i]=='-') {
				for (int t=0;t<PN;t++) vsig[t]-=basepow[t][pos];
			}
			ull sig=((ull)vsig[0]<<32)|vsig[1];
			int got=bins(h[sig],i-2);
			ans+=got;
		}
	}
	printf("%lld\n",ans);

}

