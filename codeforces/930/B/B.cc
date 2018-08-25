#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

vector<int> f2k[26];
int g[26];
const int mc=26;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s;
  cin>>s;
  int n=s.length();
  for (int k=0;k<n;k++) {
    int first=s[k]-'a';
    f2k[first].PB(k);
  }
  ld ans=0;
  for (int first=0;first<mc;first++) {
    ld best=0;
    for (int p=1;p<n;p++) {
      memset(g,0,sizeof g);
      for (auto &k:f2k[first]) {
        int t=k+p; if (t>=n) t-=n;
        int c=s[t]-'a';
        g[c]++;
      }
      ld got=0;
      for (int c=0;c<mc;c++) {
        if (g[c]==1) {
          got+=1.0/f2k[first].size();
        }
      }
      chkmax(best,got);
    }
    ans+=best*f2k[first].size()/((ld)n);
  }
  printf("%.9f\n",(double)ans);
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