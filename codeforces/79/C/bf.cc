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
const int INF=1e8;
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

string s,a[20];
const int mn=2e5;
int badstart[mn];
int badend[mn];
int lastend[mn];
bool contains(string s, string t) {
  int slen=s.length(),tlen=t.length();
  for (int i=0;i<=slen-tlen;i++) {
    //printf("i:%d slen:%d tlen:%d\n",i,s.length(),t.length());
    if (s.substr(i,t.length())==t) return true;
  }
  return false;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>s;
  int k; cin>>k;
  for (int i=0;i<k;i++) cin>>a[i];
  int n=s.length();
  pii final=MP(0,n-1);
  for (int x=0;x<n;x++) {
    for (int y=x;y<n;y++) {
      bool ok=1;
      for (int t=0;t<k;t++) {
        if (contains(s.substr(x,y-x+1),a[t])) {
          ok=0;
        }
      }
      if (ok) chkmax(final,MP(y-x+1,x));
    }
  }
  printf("%d %d\n",final.fst,final.snd);
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