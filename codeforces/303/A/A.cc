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
const int mn=1e5+2;
int a[mn],b[mn];
void bf(int n) {
  for (int x=0;x<n;x++) a[x]=b[x]=x;
  do {
    do {
      set<int> s;
      for (int x=0;x<n;x++) {
        s.insert((a[x]+b[x])%n);
      }
      if (s.size()==n) {
        printf("n:%d\n",n);
        for (int x=0;x<n;x++) printf("%d ",a[x]); printf("\n");
        for (int x=0;x<n;x++) printf("%d ",a[x]); printf("\n");
        return;
      }
    } while(next_permutation(b,b+n));
  } while(next_permutation(a,a+n));
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  //for (int n=1;;n++) bf(n);
	int n=rint();
  if (n%2==0) {
    printf("-1\n");
    return 0;
  }
  for (int x=0;x<n;x++) printf("%d ",x); printf("\n");
  for (int x=0;x<n;x++) printf("%d ",x); printf("\n");
  for (int x=0;x<n;x++) printf("%d ",(2*x)%n); printf("\n");
}

