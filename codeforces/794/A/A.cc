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


int rint()
{
  int x; scanf("%d",&x); return x;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a=rint(),b=rint(),c=rint();
  int n=rint();
  ll ans=0;
  for (int i=0;i<n;i++) {
    int x=rint();
    if (b<x&&x<c) ans++;
  }
  printf("%lld\n",ans);
}

