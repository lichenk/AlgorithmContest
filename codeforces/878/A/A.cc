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
const int orig=0,norig=1,f0=2,f1=3;
int b[10];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d\n",&n);
  for (int i=0;i<n;i++) {
    char op; int x;
    scanf("%c %d\n",&op,&x);
    for (int k=0;k<10;k++) {
      int msk=1<<k;
      if (op=='|') {
        if (msk&x) {
          b[k]=f1;
        }
      }
      else if (op=='&') {
        if (0==(msk&x)) {
          //printf("& k:%d\n",k);
          b[k]=f0;
        }
      }
      else {
        assert(op=='^');
        if (msk&x) {
          if (b[k]==f0) b[k]=f1;
          else if (b[k]==f1) b[k]=f0;
          else if (b[k]==orig) b[k]=norig;
          else if (b[k]==norig) b[k]=orig;
          else assert(0);
        }
      }
    }
  }
  printf("3\n");
  {
    int x=0;
    for (int k=0;k<10;k++) {
      if (b[k]==norig) x|=(1<<k);
    }
    printf("^ %d\n",x);
  }
  {
    int x=0;
    for (int k=0;k<10;k++) {
      if (b[k]==f1) x|=(1<<k);
    }
    printf("| %d\n",x);
  }
  {
    int x=0;
    for (int k=0;k<10;k++) {
      if (b[k]==f0) x|=(1<<k);
    }
    x=(1024-1)&(~x);
    printf("& %d\n",x);
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