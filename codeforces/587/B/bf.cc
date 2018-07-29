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
const ll mn=1e6+2;
ll b[mn],a[mn];
ll f[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n,l,klim; scanf("%lld%lld%lld",&n,&l,&klim);
  ll left=l%n;
  for (ll i=0;i<n;i++) {
    ll x; scanf("%lld",&x);
    a[i]=x;
  }
  for (ll x=0;x<l;x++) {
    b[x]=a[(x)%n];
  }
  ll final=0;
  for (ll s=0;s<l;s+=n) {
    memset(f,0,sizeof f);
    for (ll x=s;x<min(l,s+n);x++) {
      f[x]=1;
      final++;
    }
    ll k=1;
    for (ll x=s;x<l;x+=n) {
      k++;
      if (k>klim) break;
      for (ll y=x;y<x+n;y++) {
        for (ll z=x+n;z<min(l,x+2*n);z++) {
          if (b[z]>=b[y]) {
            f[z]+=f[y];
            //printf("s:%lld z:%lld y:%lld f:%lld\n",s,z,y,f[y]);
            f[z]%=MOD;
          }
        }
      }
      for (ll z=x+n;z<min(l,x+2*n);z++) {
        //printf("s:%lld k:%lld z:%lld f:%lld\n",s,k,z,f[z]);
        final+=f[z];
        final%=MOD;
      }
    }
  }
  final%=MOD;
  printf("%lld\n",final);
}

