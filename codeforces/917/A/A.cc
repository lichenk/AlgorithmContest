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

string a;
int n;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>a;
  n=a.length();
  int ans=0;
  for (int s=0;s<n;s++) {
    int base=0,q=0,cnt=0;
    bool ok=1;
    for (int t=s;t<n;t++) {
      char c=a[t];
      if (c=='(') {
        base++;
      }
      else if (c==')') {
        base--;
        if (base<0) {
          if (q>0) {
            base+=2; q--;
          }
          else {ok=0;}
        }
      }
      else {
        if(base>0) {
          base--;
          q++;
        }
        else {
          base++;
        }
      }
      cnt++;
      if (ok&&(0==(cnt%2))) {
        if (base==0) {
          //printf("s:%d t:%d\n",s,t);
          ans++;
        }
      }
    }
  }
  printf("%d\n",ans);
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