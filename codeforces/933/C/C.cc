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
int rint();
int vx[3],vy[3], vr[3]; ll vs[3];
const int C=150000;
const ll C2=C*(ll)C;
const int LOX=(-20*C)-1,HIX=(20*C)+1;
int n;
int go(int x, int y) {
  int sig=0;
  for (int i=0;i<n;i++) {
    int dx=x-vx[i];
    int dy=y-vy[i];
    ll r2=dx*(ll)dx+dy*(ll)dy;
    ll ar2=vs[i];
    if (r2<ar2) sig|=1<<i;
  }
  //if (x==-4*C) printf("x:%f y:%f sig:%d\n",x/(double)C,y/(double)C,sig);
  return 1<<sig;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int i=0;i<n;i++) {
    vx[i]=rint()*C;
    vy[i]=rint()*C;
    vr[i]=rint()*C;
    vs[i]=vr[i]*(ll)vr[i];
  }
  int res=0;
  int prev=1;
  for (int x=LOX;x<=HIX;x++) {
    int now=1;
    for (int i=0;i<n;i++) {
      int dx=x-vx[i];
      ll rhs2=vs[i]-dx*(ll)dx;
      if (rhs2<0) continue;
      ld rhs=sqrt((ld)rhs2);
      {
        ld rd=-rhs+vy[i];
        int got=round(rd);
        for (int y=got-1;y<=got+1;y++) {
          now|=go(x,y);
        }
      }
      {
        int rd=round(rhs+vy[i]);
        int got=rd;
        for (int y=got-1;y<=got+1;y++) {
          now|=go(x,y);
        }
      }
    }
    int toadd=__builtin_popcount(now^prev);
    /*if (toadd) {
      printf("x:%d prev:%d now:%d\n",x,prev,now);
    }*/
    res+=toadd;
    prev=now;
  }
  int final=res/2+1;
  printf("%d\n",final);
}

inline int rint()
{
  int x; scanf("%d",&x); return x;
}