#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
bool isv[256];
bool rh(string a, string b, int k) {
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  for (int i=0;i<min(a.size(),b.size());i++) {
    if (a[i]!=b[i]) return false;
    if (isv[a[i]]) --k;
    if (k==0) return true;
  }
  return false;
}
set<string> tmp={ "aabb", "abab", "abba", "aaaa"};
set<string> vans=tmp;
void solve(int k) {
  string a[4];
  for (int t=0;t<4;t++) cin>>a[t];
  for (auto &p:tmp) {
    bool ok=true;
    for (int x=0;x<4;x++) {
      for (int y=0;y<4;y++) {
        if (p[x]==p[y]&&!rh(a[x],a[y],k)) {ok=false; break;}
      }
    }
    if (!ok) vans.erase(p);
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (auto &w:vector<char>({'a','e','i','o','u'})) {
    isv[w]=true;
  }
  int n,k; cin>>n>>k;
  for (int q=0;q<n;q++) {
    solve(k);
  }
  if (vans.size()) {
    cout<<*(vans.begin())<<endl;
  }
  else cout<<"NO"<<endl;
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