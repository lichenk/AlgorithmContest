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
const int UNDEF = -1;
const int INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}

int h[MAXN],d[MAXN];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<n;i++) d[i]=rint();
  for (int i=0;i<n;i++) h[i]=rint();
  segn=2*n;
  for (int i=0;i<n;i++) {
    t[segn+i].bestInternal=0;
    t[segn+i].bestFromLeft=2*h[i];
    t[segn+i].bestFromRight=2*h[i]+d[i];
    t[segn+i].distOnRight=d[i];
    t[segn+n+i]=t[segn+i];
  }
  build(segn);
  for (int i=0;i<m;i++) {
    int a=rint()-1,b=rint()-1;
    int l,r;
    if (a<=b) {
      l=b+1,r=n+a-1;
    }
    else {
      l=b+1,r=a-1;
    }
    //printf("a:%d b:%d l:%d r:%d\n",a,b,l,r);
    auto q=query(l,r);
    printf("%lld\n",q.bestInternal);
  }
}