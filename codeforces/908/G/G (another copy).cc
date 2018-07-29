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
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
const int MAXFACT=700+4;
int fact[MAXFACT+1],invfact[10][MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
void init() {
  int got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (int x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[1][x]=got;
  }
  for (int d=2;d<=9;d++) {
    for (int x=0;x<=MAXFACT;x++) {
      invfact[d][x]=(invfact[d-1][x]+invfact[1][x]);
      if (invfact[d][x]>=MOD) invfact[d][x]-=MOD;
    }
  }
}
const int mn=702;
int pten[mn];
int gten[mn];
int pg[mn][mn];
int f[2][2][mn];
int g[2][2][mn];
int cnt[10];
int go(int fr, int dlim) {
  //dbg("fr:%d dlim:%d ",fr,dlim);
  //for (int d=0;d<=9;d++) for (int i=0;i<cnt[d];i++) dbg("%d",d); dbg("\n");
  for (int t=0;t<2;t++) memset(f[0][t],0,sizeof(int)*(fr+1));
  for (int t=0;t<2;t++) memset(g[0][t],0,sizeof(int)*(fr+1));
  f[0][0][0]=0;
  g[0][0][0]=fact[fr];
  int cur=0,nxt=1;
  int pres=0;
  for (int d=9;d>=0;d--) {
    for (int t=0;t<2;t++) memset(f[nxt][t],0,sizeof(int)*(fr+1));
    for (int t=0;t<2;t++) memset(g[nxt][t],0,sizeof(int)*(fr+1));
    for (int t=0;t<2;t++) {
      int pred=cnt[d];
      for (int x=0;x<=fr;x++) {
        for (int add=0;add<=fr-x;add++) {
          f[nxt][t][x+add]=(
            f[nxt][t][x+add]+
            f[cur][t][x]*(ll)invfact[1][add]+
            (d?(g[cur][t][x]*(ll)mul(invfact[d][add],pg[x+pres+t][add+pred])):0)
            )%MOD;
          g[nxt][t][x+add]=(
            g[nxt][t][x+add]+
            g[cur][t][x]*(ll)invfact[1][add]
            )%MOD;
        }
      }
    }
    if (d<=dlim) {
      int pred=cnt[d]+1;
      for (int x=0;x<=fr;x++) {
        for (int add=0;add<=fr-x;add++) {
          f[nxt][1][x+add]=(
            f[nxt][1][x+add]+
            f[cur][0][x]*(ll)invfact[1][add]+
            (d?g[cur][0][x]*(ll)mul(invfact[d][add],pg[x+pres][add+pred]):0)
            )%MOD;
          g[nxt][1][x+add]=(
            g[nxt][1][x+add]+
            g[cur][0][x]*(ll)invfact[1][add]
            )%MOD;
        }
      }
    }
    pres+=cnt[d];
    swap(cur,nxt);
  }
  int ans=f[cur][1][fr];
  return ans;
}

int solve(string a) {
  memset(cnt,0,sizeof cnt);
  ll final=0;
  int alim=a.length();
  for (int x=0;x<alim;x++) {
    if (a[x]=='0') continue;
    int n=alim-x-1;
    int dlim=a[x]-'0'-1;
    final+=go(n,dlim);
    cnt[a[x]-'0']++;
  }
  sort(a.begin(),a.end());
  int cum=0;
  for (auto &w:a) {
    cum=mul(cum,10);
    cum+=(w-'0');
  }
  final+=cum;
  return (int)(final%MOD);
}

int bf(string &inp) {
  int n=0;
  for (auto &w:inp) {
    n*=10;
    n+=(w-'0');
  }
  ll final=0;
  for (int x=1;x<=n;x++) {
    string a=to_string(x);
    sort(a.begin(),a.end());
    int cum=0;
    for (auto &w:a) {
      cum=mul(cum,10);
      cum+=(w-'0');
    }
    final+=cum;
  }
  return (int)(final%MOD);
}

void test() {
  for (int x=1;x<=2222;x++) {
    string a=to_string(x);
    int ss=solve(a);
    int bff=bf(a);
    if (ss!=bff) {
      printf("x:%d ss:%d bff:%d\n",x,ss,bff);
    }
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  {
    int x=1;
    for (int i=0;i<mn;i++) {
      pten[i]=x;
      x=mul(x,10);
    }
    gten[0]=0;
    for (int i=1;i<mn;i++) {
      gten[i]=gten[i-1]+pten[i-1];
      if (gten[i]>=MOD) gten[i]-=MOD;
    }
    for (int p=0;p<mn;p++) for (int y=0;y<mn;y++) {
      pg[p][y]=mul(pten[p],gten[y]);
    }
  }
  //test(); return 0;
  string a;
  cin>>a;
  int ans=solve(a);
  printf("%d\n",ans);
}