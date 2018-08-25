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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
queue<int> vlive[2];
const int mn=2e6+4;
vector<int> rg[mn];
int outdeg[mn];
int vmore[mn];
bool seen[mn];
bool tseen[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    //printf("%d->%d\n",y,x);
    rg[y].PB(x);
    outdeg[x]++;
  }
  int s=rint(),t=rint();
  int cur=0,nxt=1;
  vlive[cur].push(t);
  for (int cost=0;;cost++) {
    if (vlive[cur].size()==0) {
      printf("-1\n"); return 0;
    }
    queue<int> &q=vlive[cur];
    int morecnt=0;
    while(!q.empty()) {
      int x=q.front();
      if (x==s) {
        printf("%d\n",cost); return 0;
      }
      q.pop();
      if (seen[x]) continue;
      //printf("cost:%d x:%d\n",cost,x);
      seen[x]=true;
      vmore[morecnt++]=x;
      for (auto &y:rg[x]) {
        --outdeg[y];
        //printf("y:%d deg:%d\n",y,outdeg[y]);
        if (outdeg[y]==0) {
          q.push(y);
        }
      }
    }
    queue<int> &nq=vlive[nxt];
    nq=queue<int>();
    for (int i=0;i<morecnt;i++) {
      int x=vmore[i];
      for (auto &y:rg[x]) {
        if (!seen[y]&&!tseen[y]) {
          //printf("cost:%d y:%d\n",cost,y);
          tseen[y]=true;
          nq.push(y);
        }
      }
    }
    swap(cur,nxt);
  }
}

