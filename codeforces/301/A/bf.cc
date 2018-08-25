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
int a[102];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int k=rint();
	int n=2*k-1;
	for (int i=0;i<n;i++) a[i]=rint();
	sort(a,a+n);
  int best=-1e9;
  for (int j=0;j<200000;j++) {
    if ((j&0xf)==0) srand(time(0)+clock());
    random_shuffle(a,a+n);
    for (int i=0;i<k;i++) {
      a[i]=-a[i];
    }
    int sum=0; for (int i=0;i<n;i++) sum+=a[i];
    chkmax(best,sum);
  }
	printf("%d\n",best);
}

