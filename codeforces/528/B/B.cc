#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}
map<ll,ll> h;
map<ll,ll> dp;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=0;i<n;i++) {
    int x=rint(),w=rint();
    int l=x-w,r=x+w;
    auto it=h.find(l);
    if (it==h.end()) {
      h[l]=r;
    }
    else {
      chkmin(it->snd,r);
    }
    dp[l]=0;dp[r]=0;
  }
  int best=0;
  for (auto &w:dp) {
    int l=w.fst;
    chkmax(w.snd,best);
    chkmax(best,w.snd);
    auto it=h.find(l);
    if (it!=h.end()) {
      int r=it->snd;
      int ans=w.snd+1;
      chkmax(dp[r],ans);
    }
  }
  printf("%d\n",best);
}

