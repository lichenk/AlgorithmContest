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
ll n,t,k,d;
ll f(ll x) {
  return (x/t)*k;
}
ll g(ll x) {
  return ((x/t)+max(0ll,x-d)/t) *k;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>t>>k>>d;
  ll A,B;
  {
    ll imin=0,imax=1e9;
    while(imin<imax) {
      ll imid=(imin+imax)/2;
      if (f(imid)<n) imin=imid+1;
      else imax=imid;
    }
    A=imin;
  }
  {
    ll imin=0,imax=1e9;
    while(imin<imax) {
      ll imid=(imin+imax)/2;
      if (g(imid)<n) imin=imid+1;
      else imax=imid;
    }
    B=imin;
  }
  //assert(A>=B);
  if (A!=B) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

}

