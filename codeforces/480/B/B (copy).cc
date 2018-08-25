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
bitset<2> d;
int n; ll l; ll x[2];
set<ll> s;
set<ll> solve(int t) {
  set<ll> ans;
  for (auto &w:s) {
    if (w>=x[t])   {ans.insert(w-x[t]); return ans;}
    if (l-w>=x[t]) {ans.insert(w+x[t]); return ans;}
  }
  ans.insert(0); ans.insert(x[t]); return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();l=rint(),x[0]=rint(),x[1]=rint();
	for (int i=0;i<n;i++) {
    int a=rint();
    s.insert(a);
  }
  d.reset();
  for (auto &w:s) {
    for (int t=0;t<2;t++) {
      if (s.find(w-x[t])!=s.end()||s.find(w+x[t])!=s.end()) d[t]=1;
    }
  }
  if (d.count()==2) {
    printf("0\n");
    return 0;
  }
  if (d.count()==1) {
    int tneed=-1;
    for (int t=0;t<2;t++) if (!d[t]) tneed=t;
    auto got=solve(tneed);
    printf("%lld\n",(ll)got.size());
    for (auto &w:got) printf("%lld ",w);
    printf("\n");
    return 0;
  }
  for (auto &w:s) {
    if (w+x[1]<=l) {
      if (s.find(w+x[1]-x[0])!=s.end()||s.find(w+x[1]+x[0])!=s.end()) {
        printf("1\n%lld\n",w+x[1]);
        return 0;
      }
    }
    if (w-x[1]>=0) {
      if (s.find(w-x[1]+x[0])!=s.end()||s.find(w-x[1]-x[0])!=s.end()) {
        printf("1\n%lld\n",w-x[1]);
        return 0;
      }
    }
  }
  set<ll> res;
  for (int t=0;t<2;t++) if (!d[t]) {
    auto got=solve(t);
    for (auto &w:got) res.insert(w);
  }
  printf("%lld\n",(ll)res.size());
  for (auto &w:res) {
    printf("%lld ",w);
  }
  printf("\n");
}

