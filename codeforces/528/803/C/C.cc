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
ld quad(ll a, ll b, ll c) {
  ll discr=b*b-4*a*c;
  ld sqrtdiscr=0;
  if (discr>0) sqrtdiscr=sqrt((ld)discr);
  ld x=((ld)(-b)+(ld)sqrtdiscr)/(2*(ld)a);
  return x;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n=rint(),k=rint();
  set<ll,greater<ll> > divisors;
  ll lim=sqrt(n)+2;
  for (ll d=1;d<=lim;d++) {
    if (n%d==0) {
      divisors.insert(d);
      divisors.insert(n/d);
    }
  }
  for (auto &d:divisors) {
    for (ll i=1;i<=k;i++) {
      vans.PB(i);
      n-=i;
    }
    vans[vans.size()-1]+=n;
    if (n<0) {
      printf("-1\n"); return 0;
    }    
  }
  if (k<=sqrt(2*n)+100) {
    set<ll> divisors;

    vector<ll> vans;
    for (ll i=1;i<=k;i++) {
      vans.PB(i);
      n-=i;
    }
    vans[vans.size()-1]+=n;
    if (n<0) {
      printf("-1\n"); return 0;
    }
    for (auto &w:vans) printf("%lld ",w);
  }
  else {
    printf("-1\n");
  }
}

