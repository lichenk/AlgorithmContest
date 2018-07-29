#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
ll t[26][1000][1000];
ll n,m;
void add(int k, int r, int c, int value) {
  for (int i = r; i < n; i |= i + 1)
  for (int j = c; j < m; j |= j + 1)
  t[k][i][j] += value;
}

int sum(int k, int r, int c) {
  int res = 0;
  for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
    for (int j = c; j >= 0; j = (j & (j + 1)) - 1)
      res += t[k][i][j];
  return res;
}

int sum2(int k, int r1, int c1, int r2, int c2) {
  return sum(k, r2, c2) - sum(k, r1 - 1, c2) - sum(k, r2, c1 - 1) + sum(k, r1 - 1, c1 - 1);
}
const ll mq=1e5+2;
char vs[1000][1004];
ll va[mq],vb[mq],vc[mq],vd[mq], ve[mq];
ll slow(ll s, ll t) {
	ll ans=0;
	for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) {
		ll a=vs[x][y]-'a',b=vs[x][y]-'a';
		if (va[s]<=x&&x<=vc[s]&&vb[s]<=y&&y<=vd[s]) a=ve[s];
		if (va[t]<=x&&x<=vc[t]&&vb[t]<=y&&y<=vd[t]) b=ve[t];
		ans+=abs(a-b);
	}
	return ans;
}
ll getdist(ll s, ll t) {
	ll A=sum2(ve[s],va[s],vb[s],vc[s],vd[s]);
	ll B=sum2(ve[t],va[t],vb[t],vc[t],vd[t]);
	ll xlo=max(va[s],va[t]),xhi=min(vc[s],vc[t]);
	ll ylo=max(vb[s],vb[t]),yhi=min(vd[s],vd[t]);
	ll ans;
	if (!((xlo<=xhi)&&(ylo<=yhi))) ans= A+B;
	else {
		ll interA=sum2(ve[s],xlo,ylo,xhi,yhi);
		ll interB=sum2(ve[t],xlo,ylo,xhi,yhi);
		ll szinter=(xhi-xlo+1)*(yhi-ylo+1);
		ans=A+B-interA-interB+szinter*abs(ve[s]-ve[t]);
	}
	//if (ans!=slow(s,t)) {
	//	printf("s:%d t:%d ans:%d slow:%d\n",s,t,ans,slow);
	//	assert(false);
	//}
	//printf("s:%d t:%d ans:%d\n",s,t,ans);
	return ans;
}
inline long long MK(ll x, ll y) {
	return (((long long)x)<<32)|y;
}
ll vdist[mq];
ll q;
ll bdist[mq];
long long distpair[mq];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d %d %d\n",&n,&m,&q);
	for (ll i=0;i<n;i++) scanf("%s\n",vs[i]);
	for (ll i=0;i<q;i++) {
		char e;
		scanf("%d %d %d %d %c",&va[i],&vb[i],&vc[i],&vd[i],&e);
		--va[i];--vb[i];--vc[i];--vd[i];
		ve[i]=e-'a';
	}
	if (q==0) {
		printf("0\n"); return 0;
	}
	memset(t,0,sizeof t);
	for (ll k=0;k<26;k++) {
		for (ll x=0;x<n;x++) for (ll y=0;y<m;y++) {
			add(k,x,y,abs(vs[x][y]-'a'-k));
		}
	}
	pll furthest=MP(-1,-1);
	for (ll x=0;x<q;x++) {
		ll dist=getdist(0,x);
		chkmax(furthest,MP(dist,x));
	}
	ll b=furthest.second;
	for (ll x=0;x<q;x++) {
		bdist[x]=getdist(b,x);
	}
	pll farc=MP(-1,-1);
	for (ll x=0;x<q;x++) {
		chkmax(farc, MP(bdist[x],x));
	}
	ll c=farc.second;
	for (ll x=0;x<q;x++) {
		ll cdist=getdist(c,x);
		distpair[x]=MK(min(bdist[x],cdist),x);
	}
	sort(distpair,distpair+q);
	ll final=INF;
	for (ll i=0;i<10;i++) {
		ll y=distpair[i]&0xffffffff;
		ll cand=0;
		for (ll x=0;x<q;x++) cand+=getdist(x,y);
		//printf("b:%d c:%d y:%d cand:%d\n",b,c,y,cand);
		chkmin(final,cand);
	}
	printf("%d\n",final);
}

