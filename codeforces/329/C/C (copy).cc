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
bool a[mz][mz];
int bf_n;
int bf(int start, int now, int state) {
  int n=bf_n;
  for (int x=0;x<n;x++) {
    if ((1<<x)&state) continue;
    
  }
}

const int mn=1e5+4;
vector<int> g[mn];
vector<pii> vans;
bool seen[mn];
vector<int> have;
void dfs(int x) {
  if (seen[x]) return;
  seen[x]=true;
  have.PB(x);
  for (auto &y:g[x]) {
    dfs(y);
  }
}
vector<vector<int> > comp[5][2];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int nn=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  for (int x=1;x<=nn;x++) {
    if (!seen[x]) {
      dfs(x);
      int k=have.size();
      if (k>=5) {
        if (k&1) {
          for (int t=0,i=0;i<k;i++,t=(t+2)%k) {
            vans.PB(have[t],have[(t+2)%k]);
          }
        }
        else {
          int t=0;
          for (int i=0;i<k;i++) {
            int nt;
            if (t==0) nt=k/2;
            else if (t<n/2) nt=k-t;
            else nt=(k-t)+1;
            vans.PB(have[t],have[nt]);
            t=nt;
          }
        }
      }
      else {
        int iscyc=1;
        for (auto &y:have) if (g[y].size()==1) iscyc=0;
        comp[k][iscyc].PB(have);
      }
      have.clear();
    }
  }
  for (int )
}
