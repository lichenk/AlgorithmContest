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
const int mn=2e5+4;
pair<int,int> a[mn];
int oa[mn];
int newm[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=n-1;i>=0;i--) {
    int x=rint();
    oa[i]=x;
    a[i]=MP(x+(n-1-i),i);
  }
  sort(a,a+n,greater<pair<int,int> >());
  for (int i=0;i<n;i++) {
    int idx=a[i].snd;
    int money=oa[idx]+(i-idx);
    newm[i]=money;
  }
  for (int i=1;i<n;i++) {
    if (newm[i-1]<newm[i]) {
      printf(":(\n"); return 0;
    }
  }
  for (int i=n-1;i>=0;i--) {
    printf("%d ",newm[i]);
  }
  printf("\n");
}

