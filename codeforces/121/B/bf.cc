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

void f(string &a) {
  int n=a.length();
  int y=-1;
  for (int x=0;x<n-1;x++) {
    if (a[x]=='4'&&a[x+1]=='7') {y=x; break;}
  }
  if (y!=-1) a[y]=a[y+1]=(y&1)?'7':'4';
}
map<string,int> h;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; int n,k; cin>>n>>k>>s;
  h[s]=0;
  for (int x=1;x<=k;x++) {
    f(s);
    auto it=h.find(s);
    if (it!=h.end()) {
      int y=it->snd;
      int r=(k-y)%(x-y);
      for (int i=0;i<r;i++) f(s);
      cout<<s<<endl; exit(0);
    }
    else {
      h[s]=x;
    }
  }
  cout<<s<<endl; exit(0);
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