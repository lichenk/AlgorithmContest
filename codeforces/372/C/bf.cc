#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
const int mn=150000;
/*const int q=18;
inline ll MK(ll val, int x) {
  return (val<<q)|x;
}
inline ll VAL(ll x) {
  return x>>q;
}
inline int XX(ll x) {
  return x&((1<<q)-1);
}*/
int f[2][mn];
int cnt[(300*mn)+4];
priority_queue<int> pq;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint(),dpt=rint();
  int prevt;
  int cur=0,nxt=1;
  ll final=0;
  for (int i=0;i<m;i++) {
    int a=rint()-1,bb=rint(),t=rint();
    final+=bb;
    if (i==0) {
      for (int x=0;x<n;x++) {
        f[nxt][x]=-abs(a-x);
      }
    }
    else {
      
      int dist=(int)min((ll)n-1LL,(ll)dpt*(ll)(t-prevt));
      //printf("prevt:%d t:%d\n",prevt,t);
      {
        for (int k=0;k<=dist;k++) {
          int got=f[cur][k];
          pq.push(got);
          //printf("ins:%lld\n",f[cur][k]);
        }
        int x=0;
        int val=-abs(a-x);
        //printf("dist:%d\n",dist); fflush(stdout);
        f[nxt][0]=val+pq.top();
      }
      for (int x=1;x<n;x++) {
        int lx=x-dist-1;
        if (lx>=0) {
          //assert(f[cur][lx]<=0);
          cnt[-f[cur][lx]]++;
          while(!pq.empty()) {
            auto got=pq.top();
            //assert(got<=0);
            if (cnt[-got]>0) {
              cnt[-got]--;
              pq.pop();
            }
            else break;
          }
        }
        int rx=x+dist;
        if (rx<n) {
          //printf("insB:%lld\n",f[cur][rx]);
          int got=f[cur][rx];
          pq.push(got);
        }
        int val=-abs(a-x);
        f[nxt][x]=val+pq.top();
      }
      while(!pq.empty()) {
        auto got=pq.top();
        if (cnt[-got]>0) cnt[-got]--;
        pq.pop();
      }
    }
    //for (int x=0;x<n;x++) printf("i:%d x:%d f:%lld\n",i,x,f[nxt][x]);
    prevt=t;
    swap(cur,nxt);
  }
  int ans=-(1<<30);
  for (int x=0;x<n;x++) chkmax(ans,f[cur][x]);
  printf("%lld\n",final+ans);
}