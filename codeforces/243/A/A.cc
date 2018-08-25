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
const int INF=1e9;
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

const int mk=21;
const int mn=1e5+2;
int f[mk][mn],a[mn];
int makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  return (std::distance(vx.begin(),it));
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=1;i<=n;i++) a[i]=rint();
  for (int k=0;k<mk;k++) {
    int msk=1<<k;
    int z=INF;
    for (int x=n;x>=1;x--) {
      f[k][x]=z;
      if (a[x]&msk) {
        z=x;
      }
    }
  }
  vector<int> vals;
  vals.reserve(n*mk);
  for (int l=1;l<=n;l++) {
    int r=l;
    int now=a[l];
    vals.PB(now);
    //printf("l:%d now:%d\n",l,now);
    while(1) {
      int nxt=INF;
      for (int k=0;k<mk;k++) {
        int msk=1<<k;
        if (0==(msk&now)) {
          chkmin(nxt,f[k][r]);
        }
      }
      if (nxt==INF) break;
      r=nxt;
      now|=a[r];
      vals.PB(now);
      //printf("r:%d now:%d\n",r,now);
    }
  }
  int final=makeunique(vals);
  printf("%d\n",final);
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