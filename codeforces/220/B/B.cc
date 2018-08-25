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
vector<int> v;
int bins(int key) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid]<key) imin=imid+1;
    else imax=imid;
  }
  if (imin<v.size()&&v[imin]==key) return imin;
  return -1;
}
const int mn=1e5+4;
vector<int> q[mn];
int bins2(int kk,int key) {
  vector<int> &b=q[kk];
  int imin=0,imax=b.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (b[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
int getans(int kk, int l, int r) {
  return bins2(kk,r)-bins2(kk,l);
}
int a[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  map<int,int> h;
  for (int i=0;i<n;i++) {
    h[a[i]]++;
  }
  for (auto &w:h) {
    if (w.snd>=w.fst) v.PB(w.fst);
  }
  for (int i=0;i<n;i++) {
    int key=bins(a[i]);
    if (key!=-1) q[key].PB(i);
  }
  int vsz=v.size();
  for (int i=0;i<m;i++) {
    int l=rint()-1,r=rint();
    int final=0;
    for (int kk=0;kk<vsz;kk++) {
      int x=v[kk];
      int cnt=getans(kk,l,r);
      if (cnt==x) {
        final++;
      }
    }
    printf("%d\n",final);
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