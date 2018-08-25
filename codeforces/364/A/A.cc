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
const int mn=4004;
vector<int> q;
int b[mn];
inline int query(int l, int r) {
	//printf("l:%d r:%d ans:%d\n",l,r,b[r+1]-b[l]);
	return b[r+1]-b[l];
}
int n;
int bins(int start, int key) {
	int imin=start,imax=n;
	while(imin<imax) {
		int imid=(imin+imax)>>1;
		if (query(start,imid)<key) {
			imin=imid+1;
		}
		else imax=imid;
		//if (key==11&&start==0) printf("start:%d key:%d imin:%d imax:%d imid:%d\n",start,key,imin,imax,imid);
	}
	//if (key==11&&start==0) {printf("start:%d key:%d imin:%d\n",start,key,imin); exit(0);}
	return imin;
}
int getb(int start, int key) {
	int L=bins(start,key);
	if (query(start,L)!=key) return 0;
	int R=bins(start,key+1);
	//if (key==10) printf("L:%d R:%d start:%d key:%d\n",L,R,start,key);
	return R-L;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a; cin>>a;
	string s; cin>>s;
	int slim=min(a,(int)(ceil(sqrt(a))+2));
	set<int> fac;
	for (int x=1;x<=slim;x++) {
		if (a%x==0) {
			fac.insert(x);
			fac.insert(a/x);
		}
	}
	n=s.length();
	for (int x=0;x<n;x++) b[x+1]=(s[x]-'0')+b[x];
	if (a==0) {
		ll zero=0;
		for (int xl=0;xl<n;xl++) {
			zero+=getb(xl,0);
		}
		ll all=(n*(n+1))/2;
		ll ans=2*zero*all-zero*zero;
		printf("%lld\n",ans);
		return 0;
	}
	vector<int> rfa;
	vector<pii> fa;
	map<int,int> h;
	int idx=0;
	for (auto &w:fac) {
		rfa.PB(w);
		h[w]=idx++;
	}
	idx=0;
	for (auto &w:fac) {
		fa.PB(MP(idx,h[a/w]));
		idx++;
	}
	//for (int x=0;x<=n;x++) printf("x:%d b:%d\n",x,b[x]);
	int fsz=fac.size();
	q.resize(fsz);
	for (int xl=0;xl<n;xl++) {
		for (int i=0;i<fsz;i++) {
			int d=rfa[i];
			q[i]+=getb(xl,d);
		}
	}
	ll final=0;
	for (auto dp:fa) {
		int c=dp.fst,d=dp.snd;
		final+=q[c]*(ll)q[d];
	}
	printf("%lld\n",final);
}

