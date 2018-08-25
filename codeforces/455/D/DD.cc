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


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=100000;
int n;
int t[2 * mn];

void seg_init() {
  for (int i=0;i<n;i++) t[i+n]=i;
}

void seg_add(int l, int r, int value) {
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

int seg_query(int p) {
  int res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

int a[mn];
const int mg=317+2;
int sqrt_lidx[mg],sqrt_ridx[mg];
int sqrt_g[mn],sqrt_s[mn];
map<int,int> h[mg];
inline void addh(int g, int val) {
  h[g][val]++;
}
inline void rmh(int g, int val) {
  auto it=h[g].find(val);
  if (it->snd==1) h[g].erase(it);
  else it->snd -=1;
}
inline int queryh(int g, int val) {
  auto it=h[g].find(val);
  if (it==h[g].end()) return 0;
  return it->snd;
}

int gete(int p) {
  return a[seg_query(p)];
}
void sqrt_build() {
  int slim=round(sqrt(n));
  int glim=(n+slim-1)/slim;
  int rem=n-(glim-1)*slim;
  int idx=0;
  for (int g=0;g<glim;g++) {
    sqrt_lidx[g]=idx;
    int lim=(g==glim-1)?rem:slim;
    for (int s=0;s<lim;s++) {
      sqrt_g[idx]=g;
      sqrt_s[idx]=s;
      h[g][a[idx]]++;
      idx++;
    }
    sqrt_ridx[g]=idx-1;
  }
}
void sqrt_modify(int l, int r) {
  int lg=sqrt_g[l],rg=sqrt_g[r];
  int re=gete(r);
  if (lg<rg) {
    rmh(rg,re);
    addh(lg,re);
    for (int g=lg;g<rg;g++) {
      int idx=sqrt_ridx[g];
      int e=gete(idx);
      rmh(g,e);
      addh(g+1,e);
    }
  }
}
int naive_query(int l, int r, int val) {
  int ans=0;
  for (int idx=l;idx<=r;idx++) {
    if (gete(idx)==val) ans++;
  }
  return ans;
}
int sqrt_query(int l, int r, int val) {
  int lg=sqrt_g[l],rg=sqrt_g[r];
  if (lg==rg) {
    return naive_query(l,r,val);
  }
  else {
    int ans=naive_query(l,sqrt_ridx[lg],val)+naive_query(sqrt_lidx[rg],r,val);
    for (int g=lg+1;g<rg;g++) {
      ans+=queryh(g,val);
    }
    return ans;
  }
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  seg_init();
	for (int i=0;i<n;i++) a[i]=rint();
  sqrt_build();
  int q=rint();
  int lastans=0;
  for (int i=0;i<q;i++) {
    int t=rint(),lp=rint(),rp=rint();
    int l=lp+lastans-1; if (l>n) l-=n;
    int r=rp+lastans-1; if (r>n) r-=n;
    if (l>r) swap(l,r); 
    if (t==1) {
      seg_add(l+1,r,-1);
      seg_add(l,l,r-l);
      sqrt_modify(l,r);
    }
    else {
      int kp=rint();
      int k=kp+lastans-1; if (k>n) k-=n;
      k++;
      lastans=sqrt_query(l,r,k);
      printf("%d\n",lastans);
    }
  }
}

