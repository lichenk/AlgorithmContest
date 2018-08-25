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

int solve(vi v) {
  int n=v.size();
  int as=0,ae=n-1;
  int len=0;
  {
    int c=v[ae];
    while(ae>=as&&v[ae]==c) {
      c^=1;len++;ae--;
    }
  }
  int bs=v[ae+1],be=v[n-1];
  int sgn=1;
  while(1) {
    int olen=len;
    int c=be^1;
    //printf("sgn:%d as:%d ae:%d bs:%d be:%d\n",sgn,as,ae,bs,be);
    if (sgn==1) {
      while(as<=ae&&v[as]==c) {
        //printf("as:%d c:%d\n",as,c);
        as++; len++; c^=1;
      }
    }
    else {
      while(as>=ae&&v[as]==c) {
        //printf("as:%d c:%d\n",as,c);
        as--; len++; c^=1;
      }
    }
    swap(bs,be);
    bs=c^1;
    if (len==olen) return len;
    swap(as,ae);
    sgn=-sgn;
  }
  return -1;
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; cin>>s; int n=s.length();
  vi a(n);
  for (int i=0;i<n;i++) a[i]=(s[i]=='b')?1:0;
  int final=0;
  int now=1;
  for (int i=1;i<n;i++) {
    if (a[i]!=a[i-1]) {
      ++now;
    }
    else now=1;
    chkmax(final,now);
  }
  for (int k=0;k<2;k++) {
    //printf("K:%d   \n",k);
    chkmax(final,solve(a));
    reverse(a.begin(),a.end());
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