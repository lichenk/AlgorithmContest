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
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  int sum=0;
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
    int z=rint();
    if (x==y) {
      sum^=z;
    }
  }
  int q=rint();
  for (int j=0;j<q;j++) {
    int t=rint();
    if (t==3) {
      printf("%d",sum);
    }
    else {
      int i=rint();
      sum^=1;
    }
  }
}

