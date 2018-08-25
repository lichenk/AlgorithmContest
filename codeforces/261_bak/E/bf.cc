#include <bits/stdc++.h>
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
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int l=rint(),r=rint(),p=rint();
  int zlim=1<<p;
  unordered_set<int> s;
  for (int zz=0;zz<zlim;zz++) {
    ll a=1,b=0;
    int z=zz;
   // vector<int> vb;
    for (int i=0;i<p;i++) {
      if (z&1) {
        b++;
      }
      else {
        a*=b;
        //vb.PB(b);
      }
      z=z>>1;
      //if (a==58500) for (auto &w:vb) printf("%d\n",w);
      if (l<=a&&a<=r) s.insert(a);
    }
  }
  int ans=s.size();
  printf("%d\n",ans);
  //for (auto &w:s) printf("%d\n",w);
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