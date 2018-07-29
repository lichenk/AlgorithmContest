#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,unsafe-math-optimizations")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
#include <immintrin.h>
#include <emmintrin.h>
using namespace std;
typedef unsigned long long ll;
typedef long double ld;
typedef unsigned int uint;
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
const int mn=(2e5)+4;
vi g[mn];
int bins(vector<int> &v, int key) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
  
}

bool binf(vector<int> &v, int key) {
  int imin=bins(v,key);
  return (imin<v.size()) && (v[imin]==key);
}

ll C2(ll x) {
  ll a=x,b=x-1;
  if (a&1) b/=2;
  else a/=2;
  return a*b;
}
#define tm tmm
const int L=0,M=1,R=2;
ll tri[mn][3];
uint C[3];
uint vlo[mn],vhi[mn];
ll tl[mn],tm[mn],tr[mn];
ll ans[3];
//bool h[30][30];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<3;i++) C[i]=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    //h[x][y]=h[y][x]=true;
    g[x].PB(y);
    g[y].PB(x);
    vlo[max(x,y)]++;
    vhi[min(x,y)]++;
  }
  for (int x=0;x<n;x++) sort(g[x].begin(),g[x].end());
  for (int x=0;x<n;x++) {
    for (auto &y:g[x]) {
      if (y<x) {
      	//if (x==5&&lt) printf("y:%d lt:%d\n",y,lt);
        tl[x]+=bins(g[y],x);
        tm[x]+=g[y].size()-bins(g[y],x+1);
      }
      else {
        tr[x]+=g[y].size()-bins(g[y],x+1);
        tm[x]+=bins(g[y],x);
      }
    }
  }
	for (int xx=0;xx<n;xx++) {
    for (auto &yy:g[xx]) {
      if (xx>yy) continue;
      int x=xx,y=yy;
      if (g[x].size()>g[y].size()) swap(x,y);
      for (auto &z:g[x]) {
        if (binf(g[y],z)) {
          int s;
          if (z>x&&z>y) s=R;
          else if (z<x&&z<y) s=L;
          else s=M;
          ++tri[z][s];
        }
      }
    }
  }
  int el=0,er=m;
  for (int x=0;x<n;x++) {
    er-=vhi[x];
    ll em=m-el-er-g[x].size();
    //printf("x:%d em:%lld\n",x,em);
    // Code goes here
    ll al=x,ar=n-x-1;
    ll bl=vlo[x],br=vhi[x];
    ll gl=al-bl,gr=ar-br;
    { // x is leftmost
      ll one=br*gr+C2(br)+er;
      ll two=tr[x];
      ll three=tri[x][L];
      ll contrib=one-two+three;
      /*ll test=0;
      for (int i=x+1;i<n;i++) {
      	for (int j=i+1;j<n;j++) {
      		if (h[x][i]||h[x][j]||h[i][j]) ++test;
      	}
      }
      if (test!=contrib) {
      	printf("x:%d test:%lld contrib:%lld\n",x,test,contrib);
      	printf("one:%lld two:%lld three:%lld er:%d\n",one,two,three,er);
      	assert(test==contrib);
      }*/
      //printf("br:%d ar:%d er:%d\n",br,ar,er);
      
      ll all=C2(ar);
      //printf("leftmost x:%d contrib:%llu all:%llu ar:%llu\n",x,contrib,all,ar);
      //printf("leftmost x:%d add:%lld\n",x,all-contrib);
      ans[L]+=(all-contrib)*x;
    }
    { // x is on rightmost
      ll one=bl*gl+C2(bl)+el;
      ll two=tl[x];
      ll three=tri[x][R];
      ll contrib=one-two+three;
      ll all=C2(al);
      /*ll test=0;
      for (int i=0;i<x;i++) {
      	for (int j=i+1;j<x;j++) {
      		if (h[x][i]||h[x][j]||h[i][j]) ++test;
      	}
      }
      if (test!=contrib) {
      	printf("x:%d test:%lld contrib:%lld\n",x,test,contrib);
      	printf("one:%lld two:%lld three:%lld er:%d\n",one,two,three,er);
      	assert(test==contrib);
      }*/
      //printf("one:%lld two:%lld three:%lld all:%lld bl:%lld al:%lld el:%lld\n",one,two,three,all,bl,al,el);
      //printf("rightmost x:%d contrib:%llu all:%llu\n",x,contrib,all);
      //printf("rightmost x:%d add:%lld\n",x,all-contrib);
      ans[R]+=(all-contrib)*x;
    }
    { // mid x
      ll one=bl*gr+gl*br+bl*br+em;
      ll two=tm[x];
      ll three=tri[x][M];
      ll contrib=one-two+three;
      /*ll test=0;
      for (int i=0;i<x;i++) {
      	for (int j=x+1;j<n;j++) {
      		if (h[x][i]||h[x][j]||h[i][j]) ++test;
      	}
      }
      if (test!=contrib) {
      	printf("x:%d test:%lld contrib:%lld\n",x,test,contrib);
      	printf("one:%lld two:%lld three:%lld er:%d\n",one,two,three,er);
      	assert(test==contrib);
      }*/
      ll all=al*ar;
      //printf("middle x:%d contrib:%lld all:%lld\n",x,contrib,all);
      //printf("one:%lld two:%lld three:%lld all:%lld\n",one,two,three,all);
      //printf("mid x:%d add:%lld\n",x,all-contrib);
      ans[M]+=(all-contrib)*x;
    }
    // Ends here
    el+=vlo[x];
  }
  ll final=0;
  for (int i=0;i<3;i++) final+=ans[i]*C[i];
  printf("%llu\n",final);
}


inline int rint() {
  int x; scanf("%d",&x); return x;
}
