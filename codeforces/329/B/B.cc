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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
const int mn=1004;
char a[mn][mn];
int dist[mn][mn];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int xlim,ylim;
bool valid(int x, int y) {
  return (0<=x&&x<xlim&&0<=y&&y<ylim)&&(a[x][y]!='T');
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d %d\n",&xlim,&ylim);
  for (int x=0;x<xlim;x++) scanf("%s\n",a[x]);
  int ex=-1,ey=-1;
  for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) if (a[x][y]=='E') {ex=x;ey=y; break;}
  for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) dist[x][y]=1<<30;
  queue<pii> q;
  dist[ex][ey]=0;

  q.push(MP(ex,ey));
  while(!q.empty()) {
    auto got=q.front(); q.pop();
    int cand=dist[got.fst][got.snd]+1;
    for (int d=0;d<4;d++) {
      int x=got.fst+dx[d],y=got.snd+dy[d];
      if (!valid(x,y)) continue;
      if (dist[x][y]>cand) {
        dist[x][y]=cand;
        q.push(MP(x,y));
      }
    }
  }
  int sd=0;
  for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) if (a[x][y]=='S') sd=dist[x][y];
  int ans=0;
  for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) {
    if (dist[x][y]<=sd&&'0'<=a[x][y]&&a[x][y]<='9') {
      ans+=a[x][y]-'0';
    }
  }
  printf("%d\n",ans);
}
