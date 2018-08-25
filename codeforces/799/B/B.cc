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


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=2e5+4;
int p[mn],a[mn],b[mn];
set<int> h[4][4];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=0;i<n;i++) p[i]=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  for (int i=0;i<n;i++) b[i]=rint();
  for (int i=0;i<n;i++) {
    h[a[i]][b[i]].insert(p[i]);
  }
  int m=rint();
  for (int i=0;i<m;i++) {
    int c=rint();
    pair<int,pair<int,int> > ans=MP(2e9+4,MP(-1,-1));
    for (int k=1;k<=3;k++) {
      if (h[c][k].size()>0) {
        int cand=*(h[c][k].begin());
        chkmin(ans,MP(cand,MP(c,k)));
      }
      if (h[k][c].size()>0) {
        int cand=*(h[k][c].begin());
        chkmin(ans,MP(cand,MP(k,c)));
      }
    }
    if (ans.fst<2e9) {
      printf("%d ",ans.fst);
      h[ans.snd.fst][ans.snd.snd].erase(h[ans.snd.fst][ans.snd.snd].begin());
    }
    else {
      printf("-1 ");
    }
  }
  printf("\n");
}

