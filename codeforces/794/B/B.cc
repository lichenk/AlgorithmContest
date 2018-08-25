#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef __float128 ld;
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


int rint()
{
  int x; scanf("%d",&x); return x;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),h=rint();
  ld want=(ld)h/(ld)(n*2);
  ld prev=0;
  for (int i=0;i<n-1;i++) {
    ld imin=prev,imax=h;
    for (int k=0;k<65;k++) {
      ld imid=(imin+imax)/2;
      ld got=(imid-prev)*(imid+prev)/(2*h);
      if (got<want) imin=imid;
      else imax=imid;
    }
    printf("%.10f ",(double)imin);
    prev=imin;
  }
  printf("\n");
}

