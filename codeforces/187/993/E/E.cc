#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
#define M_PIl 3.141592653589793238462643383279502884L

typedef long long lint;


  typedef complex<long double> base;
  void fft(vector<base> &v, bool inv){
    vector<base> w(v.size());
    for(int i=2; i<=v.size(); i<<=1){
      int bsz = v.size() / i;
      base ang(cos(2 *  M_PIl / i), sin(2 *  M_PIl / i));
      if(inv) ang = base(1, 0) / ang;
      for(int j=0; j<bsz; j++){
        for(int k=0; k<i; k++){
          w[k] = v[bsz * k + j];
        }
        base pw(1, 0);
        for(int k=0; k<i/2; k++){
          base a = w[2*k], b = w[2*k+1] * pw;
          v[bsz * k + j] = a + b;
          v[bsz * k + j + v.size()/2] = a - b;
          pw *= ang;
        }
      }
    }
    if(inv){
      for(int i=0; i<v.size(); i++){
        v[i] /= v.size();
      }
    }
  }
  vector<lint> multiply(vector<lint> &v, vector<lint> &w){
    vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
    int n = 1;
    while(n < max(v.size(), w.size())) n <<= 1;
    n <<= 1;
    fv.resize(n);
    fw.resize(n);
    fft(fv, 0);
    fft(fw, 0);
    for(int i=0; i<n; i++) fv[i] *= fw[i];
    fft(fv, 1);
    vector<lint> ret(n);
    for(int i=0; i<n; i++) ret[i] = round(fv[i].real());
    return ret;
  }
  vector<lint> power(vector<lint> &v){
    vector<base> fv(v.begin(), v.end());
    int n = 1;
    while(n < v.size()) n <<= 1;
    n <<= 1;
    fv.resize(n);
    fft(fv, 0);
    for(int i=0; i<n; i++) fv[i] *= fv[i];
    fft(fv, 1);
    vector<lint> ret(n);
    for(int i=0; i<n; i++) ret[i] = round(fv[i].real());
    return ret;
  }






const int mn=2e5+2;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll inpsz=rint(), t=rint();
  vector<ll> f;
  {
    int sum=0;
    for (int i=0;i<inpsz;i++) {
      int x=rint();
      if (x<t) {
        f.PB(sum+1);
        sum=0;
      }
      else ++sum;
    }
    f.PB(sum+1);
  }
  ll fsz=f.size();
  vector<ll> g=f;
  reverse(g.begin(),g.end());
  vector<ll> res=multiply(f,g);
  ll zero=0;
  for (auto &w:f) zero+=(w*(w-1))/2;
  printf("%lld ",zero);
  for (int x=1;x<=inpsz;x++) {
    ll e=fsz-1+x;
    if (e<res.size()) printf("%lld ",res[e]);
    else printf("0 ");
  }
  printf("\n");
}





int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}