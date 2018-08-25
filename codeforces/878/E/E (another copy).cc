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
const int mn=100000+1;
int a[mn];
int n;
int norm(ll x) {
	x%=MOD; if (x<0) x+=MOD; return x;
}

const int THRES=2*1000*1000*1000 + 1;
const int THRESLEN=31;
ll vsig[mn];
ll ptwo[THRESLEN];
int vl[mn];
vector<int> vpos;
void initsig(int initx) {
	ll sig=a[initx];
	for (int x=initx-1;x>=1;) {
		if (a[x]>0) {
			int len=x-vl[x]+1;
			ll ptwosig;
			bool ovf=false;
			if (sig>0) {
				ovf|=(len>=THRESLEN)||__builtin_smulll_overflow(ptwo[len], sig, &ptwosig);
				sig=ptwosig; ovf|=(sig>=THRES);
			}
			else {
				assert(sig==0);
			}
			sig+=vsig[x]; ovf|=(sig>=THRES);
  		if (ovf) {
  			vsig[initx]=THRES;
  			vl[initx]=1;
  			return;
  		}
			x=vl[x]-1;
		}
		else {
  		sig*=2;
  		sig+=a[x];
  		//printf("initx:%d x:%d sig:%lld\n",initx,x,sig);
  		if (sig>=THRES) {
  			vsig[initx]=THRES;
  			vl[initx]=1;
  			return;
  		}
  		if (sig<0) {
  			vsig[initx]=sig;
  			vl[initx]=x;
  			return;
  		}
  		x--;
  	}
	}
	vsig[initx]=sig;
	vl[initx]=1;
}
int vpresum[mn],vpre2[mn],vpreopt[mn],vopt[mn];
int vlastpos[mn];
int invp2mod[mn],p2mod[mn];
int vr[mn];
int querysum(int l, int r) {
	if (l>r) return 0;
	return vpresum[r]-vpresum[l-1];
}
int queryp2(int l, int r) {
	if (l>r) return 0;
	return ((vpre2[r]-vpre2[l-1])*(ll)invp2mod[l])%MOD;
}
int queryopt(int l, int r) {
	if (l>r) return 0;
	return vpreopt[r]-vpreopt[l-1];
}
int solve(int l, int r) {
	if (l>r) return 0;
	int lastpos=vlastpos[r];
	if (lastpos==-1) {
		return querysum(l,r);
	}
	else {
		int suf=querysum(max(l,lastpos+1),r);
		//int mid=queryp2(max(l,vl[lastpos]), lastpos);
		int mid=0;
		int pre=0;
		{
			int segr=vr[l];
			if (segr==0) {
				pre=queryopt(l,lastpos);
			}
			else {
				int segl=vl[segr];
				int pre0=norm(queryopt(l,segr)*(ll)invp2mod[l-segl]);
				int pre1=queryopt(segr+1,lastpos);
				printf("l:%d segr:%d pre0:%d.\n segr+1:%d lastpos:%d pre1:%d\n",
					l,segr,pre0,segr+1,lastpos,pre1);
				pre=pre0+pre1;
			}
		}
		printf("l:%d r:%d lastpos:%d vl[lastpos]:%d pre:%d mid:%d suf:%d\n",
			l,r,lastpos,vl[lastpos],pre,mid,suf);
		return ((ll)suf+(ll)pre+(ll)mid)%MOD;
	}
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  invp2mod[0]=1;
  const int inv2=(MOD+1)/2;
  for (int t=1;t<mn;t++) invp2mod[t]=(invp2mod[t-1]*(ll)inv2)%MOD;
  ptwo[0]=1;
  for (int t=1;t<THRESLEN;t++) {
  	ptwo[t]=(ptwo[t-1]*2);
  }
  n=rint(); int q=rint();
  for (int x=1;x<=n;x++) {
  	a[x]=rint();
  }
  int lastpos=-1;
  for (int x=1;x<=n;x++) {
  	if (a[x]>0) lastpos=x;
  	vlastpos[x]=lastpos;
  }
  for (int x=1;x<=n;x++) {
  	vpresum[x]=norm(vpresum[x-1]+(ll)a[x]);
  }
  {
  	int C=1;
  	p2mod[0]=1;
  	for (int x=1;x<=n;x++) {
  		C*=2; if (C>=MOD) C-=MOD;
  		p2mod[x]=C;
  		vpre2[x]=(vpre2[x-1]+C*(ll)a[x])%MOD;
  	}
  }
  for (int x=1;x<=n;x++) {
  	if (a[x]>0) initsig(x);
  }
  for (int x=1;x<=n;x++) vopt[x]=1;
  for (int r=1;r<=n;r++) {
  	if (a[r]>0) {
  		int l=vl[r];
  		printf("l%d r%d\n",l,r);
  		for (int x=l;x<=r;x++) {
  			vr[x]=x;
  			vopt[x]=p2mod[x-l];
  		}
  	}
  }
  for (int x=1;x<=n;x++) {
  	printf("x:%d vopt:%d\n",x,vopt[x]);
  	vpreopt[x]=norm(vpreopt[x-1]+vopt[x]*(ll)a[x]);
  }
  for (int qi=0;qi<q;qi++) {
  	int l=rint(),r=rint();
  	int got=solve(l+1,r);
  	int ans=norm(got*2LL+a[l]);
  	printf("%d\n",ans);
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