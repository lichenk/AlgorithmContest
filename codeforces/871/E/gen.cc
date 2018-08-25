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
const int INF=1<<29;
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
void fail() {
  assert(0);
  printf("-1\n"); exit(0);
}
const int mk=200,mn=30000;
vector<int> gans[mn];
int vbfsdist[mn];
void bfs(int n, int init) {
  for (int x=0;x<n;x++) vbfsdist[x]=INF;
  vbfsdist[init]=0;
  queue<int> q;
  q.push(init);
  while(!q.empty()) {
    int x=q.front(); q.pop();
    int cand=vbfsdist[x]+1;
    for (auto &y:gans[x]) {
      if (cand<vbfsdist[y]) {
        vbfsdist[y]=cand;
        q.push(y);
      }
    }
  }
}

void ae(int x, int y) {
  gans[x].PB(y); gans[y].PB(x);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  printf("");
  srand(clock()^rand());
  int n=(rand()%20)+2;
  printf("%d ",n);
  srand(clock()^rand());
  int k=rand()%(n-1)+1;
  printf("%d\n",k);
  srand(clock()^rand());
  vector<int> p; for (int x=0;x<n;x++) p.PB(x);
  srand(clock()^rand());
  random_shuffle(p.begin(),p.end());
  for (int x=1;x<n;x++) {
    ae(p[x],p[rand()%x]);
  }
  for (int x=0;x<k;x++) {
    bfs(n,x);
    for (int y=0;y<n;y++) printf("%d ",vbfsdist[y]);
    printf("\n");
  }
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