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

int a[20];
int b[20];
int inpa[20];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<n;i++) {
    inpa[i]=rint();
  }
  for (int i=0;i<m;i++) {
    b[i]=1<<rint();
  }
  int final=0;
  for (int k=0;k<300000;k++) {
    srand(clock());
    memcpy(a,inpa,sizeof inpa);
    random_shuffle(b,b+m);
    bool ok=1;
    for (int i=0;i<m;i++) {
      int j=rand()%n;
      a[j]-=b[i];
      if (a[j]<0) {
        ok=0;
        chkmax(final,i);
        break;
      }
    }
    if (ok) chkmax(final,m);
  }
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