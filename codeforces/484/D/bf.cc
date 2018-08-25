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
const ll INF=1e9+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=1e6+4;
int a[mn];
ll f[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  memset(f,0,sizeof f);
  for (int i=0;i<n;i++) {
    int lo=a[i],hi=a[i];
    for (int j=i;j<n;j++) {
      chkmin(lo,a[j]);
      chkmax(hi,a[j]);
      chkmax(f[j+1],f[i]+abs((ll)hi-(ll)lo));
    }
  }
  printf("%lld\n",f[n]);
}

