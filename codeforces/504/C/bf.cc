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
const int mn=16;
int a[mn];
int b[mn];
typedef vector<int> vi;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=1;i<=n;i++) b[i]=rint();
  ll final=0;
  for (int l=1;l<=n;l++) for (int r=l;r<=n;r++) {
    memcpy(a,b,sizeof b);
    sort(a+l,a+r+1);
    bool yes=0;
    do {
      bool ok=1;
      for (int i=1;i<=n;i++) {
        if (a[i]!=a[n+1-i]) ok=false;
      }
      if (ok) yes=1;
    } while(next_permutation(a+l,a+r+1));
    if (yes) final++;
  }
  printf("%lld\n",final);
}
