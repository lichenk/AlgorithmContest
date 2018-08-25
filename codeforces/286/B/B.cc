#include <bits/stdc++.h>
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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

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
const int mn=1e6+4;
int p[mn];
int q[mn];
void go(int n) {
  for (int x=1;x<=n;x++) p[x]=x;
  for (int k=2;k<=n;k++) {
    for (int r=0;;r++) {
      int L=r*k+1;
      int R=min(n,r*k+k);
      //printf("L:%d R:%d\n",L,R);
      
      if (L>n) break;
      q[R]=p[L];
      for (int x=L;x<=R-1;x++) {
        q[x]=p[x+1];
      }
    }
    swap(q,p);
  }
  for (int x=1;x<=n;x++) q[p[x]]=x;
  for (int x=1;x<=n;x++) printf("%d ",q[x]-1);
  printf("\n");
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int n=rint();
  for (int n=1;n<=20;n++) go(n);
}

