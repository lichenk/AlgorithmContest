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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=25+1;
int a[mn];
int b[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(1);
  int n,m; cin>>n>>m;
  int alen=0;
  for (int i=0;i<m;i++) for (int j=0;j<n;j++) a[alen++]=j;
  int denom=0;
  ld numer=0;
  for (int k=0;k<2000000;k++) {
    srand(clock());
    random_shuffle(a,a+alen);
    for (int x=0;x<n;x++) b[x]=0;
    for (int x=0;x<n;x++) {
      b[a[x]]++;
    }
    for (int x=0;x<n;x++) {
      numer+=(b[x]*b[x])/(ld)(n*n);
    }
    denom++;
  }
  ld final=(numer)/(ld)denom;
  cout<<final<<endl;
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