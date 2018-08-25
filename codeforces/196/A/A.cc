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
const int mn=1e5+4;
char h[mn];
char vans[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s;
  cin>>s;
  int n=s.length();
  char c='a'-1;
  for (int i=n-1;i>=0;i--) {
    chkmax(c,s[i]);
    h[i]=c;
  }
  int k=0;
  for (int i=0;i<n;i++) {
    if (s[i]==h[i]) {
      vans[k++]=s[i];
    }
  }
  vans[k++]='\0';
  printf("%s\n",vans);
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