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
const int mn=1e5+4;
set<vi> final;
void play(vector<int> v) {
  int rm=1;
  while(v.size()>2) {
    bool found=0;
    for (auto it=v.begin();it!=v.end();++it) {
      if (*it ==rm) {
        found=1;v.erase(it); break;
      }
    }
    if (!found) v.erase(v.begin());
    rm^=1;
  }
  final.insert(v);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; cin>>s;
  int n=s.length();
  for (int z=0;z<(1<<n);z++) {
    vector<int> v;
    for (int i=0;i<n;i++) {
      if (s[i]=='?') v.PB((z>>i)&1);
      else v.PB(s[i]-'0');
    }
    play(v);
  }
  for (auto &w:final) {
    for (auto &c:w) printf("%d",c);
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