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
const int mn=1e5+4;
int a[mn];
bool seen[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),k=rint();
  for (int i=0;i<n;i++) {
    a[i]=rint();
  }
  sort(a,a+n);
  map<int,int> h;
  for (int i=0;i<n;i++) {
    h[a[i]]=i;
  }
  int ans=0;
  for (int i=n-1;i>=0;i--) {
    if (seen[i]) continue;
    ans++;
    int x=a[i];
    if (x%k==0) {
      int y=x/k;
      auto it=h.find(y);
      if (it!=h.end()) {
        seen[it->snd]=true;
      }
    }
  }
  printf("%d\n",ans);
}

