#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll INF = 1ULL<<60ULL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<pair<ll,ll>,ll> ppll;
#define fst first
#define snd second
const ll UNDEF=-1;
const ll mn=3e4+4;
const ll mc=3;
struct SS {
    ll a[mc][mc];
};
typedef struct SS S;

void ps(S s) {
	for (int x=0;x<mc;x++) for (int y=0;y<mc;y++) printf("%lld ",s.a[x][y]);
}

S identity;
S combine(S &a, S &b) {
	//ps(a); printf(" isa\n");
	//ps(b); printf(" isb\n");
    S c;
    for (int x=0;x<mc;x++) {
        for (int y=0;y<mc;y++) {
            ll ans = 0;
            for (int z = 0; z < mc; z++) {
                ll aa=a.a[x][z];
                ll bb=b.a[z][y];
                if (aa<=-INF||bb<=-INF) continue;
                //printf("x:%d y:%d z:%d aa:%lld bb:%lld\n",x,y,z,aa,bb);
                chkmax(ans,aa+bb);
            }
            c.a[x][y]=ans;
        }
    }
    return c;
}
const ll MAXN=mn;
S t[2*MAXN];
int segn;
void build() {  // build the tree
	int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}
void modify(int p, const S& value) {
	int n=segn;
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

S query(int l, int r) {
	int n=segn;
  r++;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}
pair<int,int> wv[mn],hv[mn];
int ow2w[mn];
int oh2h[mn];
int owtooh[mn];
int getpair(int w) {
	if (w<0) return -123;
	int ow=wv[w].snd;
	int oh=owtooh[ow];
	int h=oh2h[oh];
	return h;
}
S make(int x) {
	S res;
	int x1=x-1;
	int x1pair=getpair(x1);
	int xpair=getpair(x);
	res.a[0][0]=(x1pair==x1)?(-INF):wv[x-1].fst*hv[x-1].fst;
	res.a[0][1]=(x1pair==x||xpair==x1)?(-INF):wv[x-1].fst*hv[x].fst+wv[x].fst*hv[x-1].fst;
	res.a[1][0]=0;
	res.a[1][1]=(xpair==x)?(-INF):wv[x].fst*hv[x].fst;
	//ps(res); printf(" for x:%d\n",x);
	return res;
}

int main() {
	identity.a[0][0]=0;
	identity.a[0][1]=0;
	identity.a[1][0]=0;
	identity.a[1][1]=0;
	int n,q; scanf("%d%d",&n,&q);
	segn=n;
	for (int w=0;w<n;w++) {
		int got;scanf("%d",&got);
		wv[w]=MP(got,w);
	}
	sort(wv,wv+n);
	for (int h=0;h<n;h++) {
		int got;scanf("%d",&got);
		hv[h]=MP(got,h);
	}
	sort(hv,hv+n);
	for (int x=0;x<n;x++) {
		ow2w[wv[x].snd]=x;
		oh2h[hv[x].snd]=x;
	}
	for (int x=0;x<n;x++) {
		owtooh[x]=x;
	}
	for (int x=0;x<n;x++) {
		t[x+segn]=make(x);
	}
	//ps(combine(t[0+segn],t[1+segn])); printf(" meow01\n");
	//return 0;
	build();
	for (int qi=0;qi<q;qi++) {
		int a,b; scanf("%d%d",&a,&b);
		--a;--b;
		swap(owtooh[a],owtooh[b]);
		int na=ow2w[a],nb=ow2w[b];
		modify(na,make(na));
		modify(nb,make(nb));
		S res=query(0,n-1);
		//ps(res); printf(" qi:%d\n",qi);
		ll ans=res.a[0][1];
		printf("%lld\n",ans);
	}
}
