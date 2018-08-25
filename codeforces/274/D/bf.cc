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
const int mn=11;
int gid=mn;
vector<int> g[2*mn];
int indeg[2*mn];
int *a[mn];
void ae(int x, int y) {
  //printf("ae %d %d\n",x,y);
  indeg[y]++;
  g[x].PB(y);
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
  for (int x=0;x<n;x++) {
    a[x]=new int[m];
    for (int y=0;y<m;y++) a[x][y]=rint();
  }
  vector<int> p;
  for (int y=0;y<m;y++) p.PB(y);
  do {
    bool ok=1;
    for (int x=0;x<n;x++) {
      vector<int> v;
      for (int i=0;i<m;i++) {
        int y=p[i];
        int val=a[x][y];
        if (val!=-1) v.PB(val);
        //printf("x:%d i:%d y:%d val:%d\n",x,i,y,val);
      }
      for (int i=1;i<v.size();i++) {
        if (v[i-1]>v[i]) {ok=0; break;}
      }
      if (!ok) break;
    }
    if (ok) {
      for (auto &w:p) printf("%d ",w+1);
      printf("\n"); return 0;
    }
  } while(next_permutation(p.begin(),p.end()));
  printf("-1\n");
}
