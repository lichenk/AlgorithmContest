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
int segn;
void modify(int *t, int l, int r, int value) {
  int n=segn;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] |= value;
    if (r&1) t[--r] |= value;
  }
}
void push(int *t) {
  int n=segn;
  for (int i = 1; i < n; ++i) {
    t[i<<1] |= t[i];
    t[i<<1|1] |= t[i];
    t[i] = 0;
  }
}


void build(int *t) {  // build the tree
  int n=segn;
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] & t[i<<1|1];
}
int query(int *t, int l, int r) {  // sum on interval [l, r)
  int n=segn;
  r++;
  int res = (1<<30)-1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res &= t[l++];
    if (r&1) res &= t[--r];
  }
  return res;
}
const int mn=1e5+2;
int vt[2*mn],vl[mn],vr[mn],vq[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
  //for (int i=1;i<=n;i++) {a[i]=rint();}
  segn=n+1;
  for (int i=0;i<m;i++) {
    vl[i]=rint(),vr[i]=rint(),vq[i]=rint();
    modify(vt,vl[i],vr[i],vq[i]);
  }
  push(vt);
  //for (int i=1;i<=n;i++) printf("%d ",vt[segn+i]);
  //printf("\n");
  build(vt);
  for (int i=0;i<m;i++) {
    int got=query(vt,vl[i],vr[i]);
    //printf("got:%d\n",got);
    if (vq[i]!=got) {
      printf("NO\n"); return 0;
    }
  }
  printf("YES\n");
  for (int i=1;i<=n;i++) printf("%d ",vt[i+segn]);
  printf("\n");
}

