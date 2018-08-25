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
bool isvow[256];
vector<char> vow={'a', 'e', 'i', 'o','u'};
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (auto &w:vow) isvow[w]=true;
  string a;
  cin>>a;
  int n=a.length();
  int ls=-1;
  for (int x=0;x<n;x++) {
    if (ls<=x-3) {
      bool ok=1;
      set<char> s;
      for (int y=x-2;y<=x;y++) {
        char c=a[y];
        if (isvow[c]) ok=0;
        s.insert(c);
      }
      if (ok&&s.size()>=2) {
        ls=x-1;
        printf(" ");
      }
    }
    printf("%c",a[x]);
  }
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