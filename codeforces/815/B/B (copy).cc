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
void solve(int n) {
  vector<vector<int> > f[2];
  for (int i=0;i<n;i++) {
    vector<int> v; v.resize(n);
    v[i]++;
    f[0].PB(v);
  }
  int sign=1;
  int cur=0,nxt=1;
  while(f[cur].size()>1) {
    f[nxt].clear();
    int k=f[cur].size();
    for (int i=0;i<k-1;i++) {
      vector<int> v=f[cur][i];
      for (int j=0;j<n;j++) {
        v[j]+=f[cur][i+1][j]*sign;
      }
      sign=-sign;
      f[nxt].PB(v);
    }
    swap(cur,nxt);
  }
  for (auto &w:f[cur][0]) printf("%d ",w);
  printf(" n:%d\n",n);
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int n=1;n<=30;n++) solve(n);
}

