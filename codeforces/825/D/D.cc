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
const int mc=26,mn=1e6+4;
char s[mn],t[mn];
int sc[mc+1],tc[mc+1],wc[mc+1];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%s\n%s\n",s,t);
	int sl=strlen(s),tl=strlen(t);
	int q=0;
	for (int i=0;i<sl;i++) {
		if (s[i]!='?') sc[s[i]-'a']++;
		else q++;
	}
	for (int i=0;i<tl;i++) {
		tc[t[i]-'a']++;
	}
	int imin=0,imax=mn;
	while(imin<imax) {
		int imid=(imin+imax)>>1;
		ll need=0;
		for (int c=0;c<26;c++) {
			ll want=(tc[c]*(ll)imid)-sc[c];
			if (want>=0) need+=want;
		}
		if (need<=q) imin=imid+1;
		else imax=imid;
	}
	imin--;
	//printf("imin:%d\n",imin);
	for (int c=0;c<26;c++) {
		wc[c]=tc[c]*imin-sc[c];
	}
	int cidx=0;
	for (int i=0;i<sl;i++) {
		if (s[i]=='?') {
			while(cidx<mc&&wc[cidx]<=0) cidx++;
			if (cidx<mc) {
				s[i]='a'+cidx;
				wc[cidx]--;
			}
			else {
				s[i]='a';
			}
		}
	}
	printf("%s\n",s);
}

