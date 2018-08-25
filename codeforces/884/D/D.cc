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

const int mn=2e5+4;
int inp[mn];
int n;
ll go(bool flag) {
  priority_queue<ll,vector<ll>,greater<ll> > pq;
  for (int i=0;i<n;i++) {
    pq.push(inp[i]);
  }
  ll ans=0;
  while(pq.size()>1) {
    ll sum=0;
    int klim=flag?2:3;
    flag=false;
    for (int k=0;k<klim;k++) {
      if (pq.empty()) break;
      sum+=pq.top();
      //printf("Got:%lld\n",pq.top());
      pq.pop();
    }
    //printf("Sum:%lld\n",sum);
    ans+=sum;
    pq.push(sum);
  }
  return ans;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);

  n=rint(); for (int i=0;i<n;i++) inp[i]=rint();
  ll ans=min(go(1),go(0));
  printf("%lld\n",ans);
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