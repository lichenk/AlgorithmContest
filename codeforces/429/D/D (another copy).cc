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
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=100000;
int a[mn];
int main()
{
	int n=rint();
  int final=1LL<<30;
  for (int i=0;i<n;i++) a[i]=rint();
  for (int j=1;j<n;j++) {
    int aj1=a[j];
    int best=aj1*aj1+1;
    int b2=0;
    int suma=a[j];
    int absaj1=abs(aj1);
    for (int i=j-1;i>=0;i--) {
      int d=j-i;
      b2+=(d<<1)-1;
      if (b2>=best) break;
      //printf("j:%d i:%d b2:%d suma:%d\n",j,i,b2,suma);
      if (abs(suma)<=absaj1) {
        int res=b2+suma*suma;
        if (res<best) best=res;
      }
      suma+=a[i];
    }
    chkmin(final,best);
  }
  printf("%d\n",final);
}

