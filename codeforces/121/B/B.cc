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
const int LIM=1000000;
string a;
int n,k;
bool g(int x) {
  return (0<=x&&x+1<n)&&a[x]=='4'&&a[x+1]=='7';
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n>>k>>a;
  assert(0==(LIM&1));
  if (k>=2*LIM) {
    k%=LIM;
    k+=LIM;
  }
  priority_queue<int,vi,greater<int> > pq;
  for (int x=0;x<n-1;x++) {
    if (g(x)) {
      pq.push(x);
    }
  }
  while(k>0&&!pq.empty()) {
    int x=pq.top(); pq.pop();
    if (g(x)) {
      a[x]=a[x+1]=((x&1)?'7':'4');
      if (g(x-1)) pq.push(x-1);
      if (g(x+1)) pq.push(x+1);
      --k;
    }
  }
  cout<<a<<endl;
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