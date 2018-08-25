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
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=2e5+4;
int a[mn];
int b[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  for (int x=0;x<n;x++) b[x]=INF;
  int last=INF;
  for (int x=0;x<n;x++) {
    if (a[x]==0) last=x;
    chkmin(b[x],abs(x-last));
  }
  {
int last=INF;
  for (int x=n-1;x>=0;x--) {
    if (a[x]==0) last=x;
    chkmin(b[x],abs(x-last));
  }
  for (int x=0;x<n;x++) printf("%d ",b[x]);
  printf("\n");
  }
}

