#include <iostream>
#include <fstream>

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
const ll mn=1e5+4,mc=26;
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
inline ll add(ll x,ll y) {return (x+y)%MOD;}
ll f[mn]; // f(x,k) := Number of subseq of length k ending at x
ll lastsum[mc]; // g(c,k) := Last sum for char c, subseq length k
ll currentsum; // sum(k) := Sum for subseq k.
int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  ll T; cin>>T;
for (ll ii=0;ii<T;ii++) {
  string s; cin>>s;
  ll n=s.length();
  memset(lastsum,0,sizeof lastsum);
  memset(f,0,sizeof f);
  currentsum=0;
  f[0]=1; currentsum+=f[0];
  for (ll x=1;x<=n;x++) { // Pos in string
      f[x]=f[x-1];
      ll c=s[x-1]-'A';
      {
          ll toadd=(currentsum-lastsum[c]+MOD)%MOD;
          f[x]+=toadd; f[x]%=MOD;
          lastsum[c]=currentsum;
          currentsum+=toadd; currentsum%=MOD;
      }
  }
  ll final=f[n]%MOD;
  printf("%lld\n",final);
}
}
