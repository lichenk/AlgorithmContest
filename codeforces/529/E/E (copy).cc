#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;



int rint()
{
  int x; scanf("%d",&x); return x;
}


pair<ll, pair<ll,ll> > extgcd(ll a, ll b) {
	// Returns (gcd,(s,t))
	// gcd = a*s+b*t;
	ll s=0,old_s=1;
	ll t=1,old_t=0;
	ll r=b,old_r=a;
	while(r!=0) {
		ll q=old_r/r;
		ll tmp_r=r,tmp_s=s,tmp_t=t;
		r=old_r-q*r;
		s=old_s-q*s;
		t=old_t-q*t;
		old_r=tmp_r,old_s=tmp_s,old_t=tmp_t;
	}
	return MP(old_r,MP(old_s,old_t));
}

int mem[12600000*3];
int gid=0;
int *get(int need) {
	int *ans= &mem[gid];
	gid+=need;
	return ans;
}
const int maxn=5000;
int va[maxn];
ll *vs[maxn],*vt[maxn],*vgcd[maxn];
int main()
{
	int n=rint(); int k=rint();
	for (int i=0;i<n;i++) {
		va[i]=rint();
	}
	for (int i=0;i<n;i++) {
		vs[i]=get(i);
		vt[i]=get(i);
		vgcd[i]=get(i);
	}
	for (int x=0;x<n;x++) {
		for (int y=0;y<x;y++) {
			int a=va[x],b=va[y];
			pair<ll,pll> res = extgcd(a,b);
			ll gcd=res.fst;
			ll s=res.snd.fst,t=res.snd.snd;
			vs[x][y]=s;
			vt[x][y]=t;
			vgcd[x][y]=gcd;
		}
	}
	int q=rint();
	for (int i=0;i<q;i++) {
		int target=rint();
		int ans=INF;
		for (int x=0;x<n;x++) {
			int a=va[x];
			if (target%a==0) {
				chkmin(ans,(target/a));
			}
		}
		for (int x=0;x<n;x++) for (int y=0;y<x;y++) {
			int gcd=vgcd[x][y];
			if (target%gcd==0) {
				ll mult=target/gcd;
				{
					ll a=va[x],b=va[y];
					long long s=(long long)vs[x][y]*mult;
					long long t=(long long)vt[x][y]*mult;
					//assert(s*a+t*b==target);
					if (s<0) {
						swap(s,t); swap(a,b);
					}
					int sPerLCM=b/gcd;
					int tPerLCM=a/gcd;
					if (t<0) {
						long long giveLCM=((abs(t)+tPerLCM-1)/tPerLCM);
						t+=giveLCM*tPerLCM;
						s-=giveLCM*sPerLCM;
					}
					//assert(s*a+t*b==target);
					if (s>=0&&t>=0) {
						// Now s is maximal, t is minimal
						if (a<b) {
							// Want s minimal, t maximal
							int giveLCM=(s/sPerLCM);
							s-=giveLCM*sPerLCM;
							t+=giveLCM*tPerLCM;
						}
						else {
							int giveLCM=(t/tPerLCM);
							s+=giveLCM*sPerLCM;
							t-=giveLCM*tPerLCM;
						}
						//assert(s*a+t*b==target);
						//assert(s>=0&&t>=0);
						//if (a==1000&&b==100) printf("s:%d t:%d\n",s,t);
						int sum=s+t;
						if (s>=0&&t>=0&&sum<=k) chkmin(ans, sum);
					}
				}
			}
		}
		if (ans<=k) printf("%d\n",ans);
		else printf("-1\n");
	}
}

