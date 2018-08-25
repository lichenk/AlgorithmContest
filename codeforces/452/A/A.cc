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

vector<string> v={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; string s; cin>>n>>s;
  for (auto &w:v) {
    //printf("%d %d\n",w.length(),s.length());
    if (w.length()==s.length()) {
      bool ok=1;
      for (int i=0;i<s.length();i++) {
        if (s[i]=='.'||s[i]==w[i]) {}
        else {
          //printf("%c %c %s\n",s[i],w[i],w.c_str());
          ok=0;
        }
      }
      if (ok) {
        cout<<w<<endl;
        return 0;
      }
    }
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