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
multiset<int, greater<int> > s[3];
int delay[3];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int numlaundry; cin>>numlaundry;
  for (int a=0;a<3;a++) {
    int ni; cin>>ni;
    for (int i=0;i<ni;i++) s[a].insert(0);
  }
  for (int a=0;a<3;a++) cin>>delay[a];
  int final=0;
  for (int laundry=0;laundry<numlaundry;laundry++) {
    int mt[3];
    for (int a=0;a<3;a++) mt[a]=*(s[a].rbegin());
    int st=max(mt[0],max(mt[1]-delay[0],mt[2]-delay[0]-delay[1]));
    int t=st;
    for (int a=0;a<3;a++) {
      auto it=s[a].lower_bound(t);
      //assert(it!=s[a].end());
      //int got=*it;
      s[a].erase(it);
      t+=delay[a];
      s[a].insert(t);
    }
    chkmax(final,t);
  }
  printf("%d\n",final);
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