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
const int INF=INT_MAX;
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
const int mn=2e5+2;
vector<int> g[mn];
int vt[2*mn],vc[2*mn];
int vsumall[mn];
int vsumin[mn];
bool seen[mn];
int vans[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int id=0;id<2*m;) {
    int a=rint(),b=rint(),c=rint();
    g[a].PB(id); vt[id]=b; vc[id]=c;
    ++id;
    g[b].PB(id); vt[id]=a; vc[id]=c;
    ++id;
    vsumall[a]+=c;
    vsumall[b]+=c;
  }
  queue<int> q;
  q.push(1);
  seen[1]=true;
  while(!q.empty()) {
    int x=q.front();q.pop();
    //printf("x:%d\n",x);
    for (auto &id:g[x]) {
      int y=vt[id],c=vc[id];
      if (!seen[y]) {
        vans[id>>1]=id&1;
        vsumin[y]+=c;
        //printf("y:%d c:%d vsumin:%d vsumall:%d\n",y,c,vsumin[y],vsumall[y]);
        if (vsumin[y]*2==vsumall[y]&&y!=n) {
          seen[y]=true;
          q.push(y);
        }
      }
      else {
        vans[id>>1]=(id&1)^1;
      }
    }
  }
  for (int id=0;id<m;id++) printf("%d\n",vans[id]);
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