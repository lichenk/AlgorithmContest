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


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; cin>>s;
  sort(s.begin(),s.end());
  string t=s;
  int n=s.size();
  pair<int,pair<string,string> > final=MP(0,MP(s,s));
  do {
  do {
    int got=0;
    for (int i=0;i<n;i++) {
      got*=10;
      got+=(int)(s[i]-'0')+(int)(t[i]-'0');
    }
    int ans=0;
    int ten=1;
    for (int k=1;k<=n+1;k++) {
      ten*=10;
      if (got%ten==0) ans=k;
      else break;
    }
    chkmax(final,MP(ans,MP(s,t)));
  } while(next_permutation(t.begin(),t.end()));
  } while(next_permutation(s.begin(),s.end()));
  cout<<final.fst<<endl;
  //cout<<final.snd.fst<<endl<<final.snd.snd<<endl;
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