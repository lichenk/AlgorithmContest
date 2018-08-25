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
//template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const string IMPOSSIBLE="?";
inline void chkmin(string &aa, const string &bb) {
  if (aa==IMPOSSIBLE) aa=bb;
  if (bb==IMPOSSIBLE) return;
  if (aa.length()==bb.length()) {
    if (aa>bb) aa=bb;
  }
  else if (aa.length() > bb.length()) {
    aa=bb;
  }
}
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int E=0;
const int T=1;
const int F=2;
const int mk=3;
const int mz=1<<8;
const int MARK=1;
const int DONE=2;
string dp[mk][mz];
int vstate[mk][mz];
typedef unsigned short ushort;
typedef unsigned short uchar;
vector<ushort> orsplit[mz];
vector<ushort> andsplit[mz];
string f(uchar mode, uchar sig) {
  int &state=vstate[mode][sig];
  if (state==DONE) return dp[mode][sig];
  if (state==MARK) return "?";
  state=MARK;
  if (mode==E) {
    string ans=f(T,sig);
    for (auto &lr:orsplit[sig]) {
      uchar l=lr>>8; uchar r=lr&(mz-1);
      string L=f(E,l); if (L=="?") continue;
      string R=f(T,r); if (R=="?") continue;
      string LR=L+"|"+R;
      chkmin(ans,LR);
    }
    state=DONE;
    return dp[mode][sig]=ans;
  }
  else if (mode==T) {
    string ans=f(F,sig);
    for (auto &lr:andsplit[sig]) {
      uchar l=lr>>8; uchar r=lr&(mz-1);
      string L=f(T,l); if (L=="?") continue;
      string R=f(F,r); if (R=="?") continue;
      string LR=L+"&"+R;
      chkmin(ans,LR);
    }
    state=DONE;
    return dp[mode][sig]=ans;
  }
  else {
    string ans="?";
    string A=f(E,sig);
    if (A!="?") {
    string ans="("+f(E,sig)+")";
    chkmin(ans, "!("+f(E,(~sig)&(mz-1))+")");
    state=DONE;
    return dp[mode][sig]=ans;
  }
}
void init(uchar c, string s) {
  for (int mode=0;mode<3;mode++) {
    dp[mode][c]="!"+s; 
    vstate[mode][c]=DONE;
    dp[mode][(~c)&(mz-1)]=s;
    vstate[mode][(~c)&(mz-1)]=DONE;
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  {
    init(0b01010101,"z");
    init(0b00110011,"y");
    init(0b00001111,"x");
  }
  for (ushort l=0;l<mz;l++) {
    for (ushort r=0;r<mz;r++) {
      ushort comb=(l<<8)|r;
      orsplit[l|r].PB(comb);
      andsplit[l&r].PB(comb);
    }
  }
  int n; cin>>n;
  for (int j=0;j<n;j++) {
    string s; cin>>s;
    int x=0;
    for (int i=0;i<8;i++) {
      if (s[i]=='1') x|=1<<i;
    }
    string ans=f(E,x);
    printf("%s\n",ans.c_str());
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