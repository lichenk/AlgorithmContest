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
const int FST=1;
const int SND=2;
const int DRAW=3;
bool intersect(int a,int b,int c, int d) {
  chkmax(d,c);
  assert(a<=b&&c<=d);
  return !((a>d)||(c>b));
}

pii f(int x1, int x2, int a, int b, bool need) {
  assert(a<=b);
  assert(x1!=x2);
  if (x1+a<=x2&&x1+b>=x2) {
    return MP(FST,x2);
  }
  if (a<0&&b>0) {
    return MP(DRAW,0);
  }
  else if ((b<=0 && x2>x1)||(a>=0&&x2<x1)) {
    return MP(DRAW,0);
  }
  else {
    int c=min(abs(a),abs(b));
    int d=max(abs(a),abs(b));
    int rem=abs(x2-x1)%(c+d);
    assert(rem>=0);
    int lorem=max(0,abs(x2-x1)-d)%(c+d);
    int hirem=max(0,abs(x2-x1)-c)%(c+d);
    if (lorem<=hirem) {
      if (intersect(lorem,hirem,max(1,c),d)) return MP(SND,0);
    }
    if (lorem>hirem) {
      if (intersect(lorem,c+d-1,max(1,c),d)) return MP(SND,0);
      if (intersect(0,hirem,max(1,c),d)) return MP(SND,0);
    }
    if (intersect(rem,rem,max(1,c),d)) {
      if (!need) return MP(FST,0);
      if (f(x2,x1+a,-b,-a,false).fst==SND) return MP(FST,x1+a); 
      if (f(x2,x1+b,-b,-a,false).fst==SND) return MP(FST,x1+b);
      for (int t=a+1;t<=b-1;t++) {
        if (f(x2,x1+t,-b,-a,false).fst==SND) return MP(FST,x1+t);
      }
      assert(0);
    }
    return MP(DRAW,0);
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int x1,x2,a,b; cin>>x1>>x2>>a>>b;
  pii ans=f(x1,x2,a,b,true);
  if (ans.fst==FST) printf("FIRST\n%d\n",ans.snd);
  else if (ans.fst==SND) printf("SECOND\n");
  else printf("DRAW\n");
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