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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
const int MAXFACT=700*3+4;
int fact[MAXFACT+1],invfact[MAXFACT+1];
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
    invfact[x]=got;
  }
}
int binom(int n,int k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

int starbar(int stars, int parts) {
  if (parts==0) {
    return (stars==0)?1:0;
  }
  if (parts<=0||stars<0) return 0;
  return binom(stars+parts-1,parts-1);
}

int f[11],pre[11],suf[11];

int go(int n) {
  dbg("n:%d ",n);
  {
    int sum=0;
    for (int d=0;d<=9;d++) {
      for (int i=0;i<f[d];i++) dbg("%d",d);
      sum+=f[d];
      pre[d]=sum;
    }
  }
  dbg("\n");
  {
    int sum=0;
    for (int d=9;d>=0;d--) {
      sum+=f[d];
      suf[d]=sum;
    }
  }
  int final=0;
  for (int d=1;d<=9;d++) {
    int contrib=d;
    for (int pos=0;pos<n;pos++) {
      int fd=f[d];
      if (fd==0) {
        for (int dupb4=0;dupb4<=fd;dupb4++) {
          int takenb4=dupb4+pre[d-1];
          int takenaft=fd-dupb4+suf[d+1];
          int b4=n-1-pos-takenb4;
          int aft=pos-takenaft;
          //dbg("n:%d d:%d pos:%d dupb4:%d b4:%d aft:%d\n",n,d,pos,dupb4,b4,aft);
          if (b4>=0&&aft>=0) {
            int times=mul(starbar(b4, d), starbar(aft,10-d));
            ll thing=times*(ll)contrib;
            dbg("takenb4:%d takenaft:%d\n",takenb4,takenaft);
            dbg("n:%d d:%d pos:%d dupb4:%d b4:%d aft:%d thing:%lld\n",n,d,pos,dupb4,b4,aft,thing);
            final=(final+thing)%MOD;
          }
        }
      }
      if (fd>0) {
        fd--;
        for (int dupb4=0;dupb4<=fd;dupb4++) {
          int takenb4=dupb4+pre[d-1];
          int takenaft=fd-dupb4+suf[d+1];
          int b4=n-1-pos-takenb4;
          int aft=pos-takenaft;
          //dbg("n:%d d:%d pos:%d dupb4:%d b4:%d aft:%d B\n",n,d,pos,dupb4,b4,aft);
          if (b4>=0&&aft>=0) {
            int times=mul(starbar(b4, d), starbar(aft,10-d));
            ll thing=times*(ll)contrib;
            dbg("n:%d d:%d pos:%d dupb4:%d thing2:%lld\n",n,d,pos,dupb4,thing);
            final=(final+thing)%MOD;
          }
        }
        fd++;
      }
      contrib=mul(contrib,10);
    }
  }
  dbg("final:%d\n",final);
  return final;
}

int solve(string a) {
  memset(f,0,sizeof f);
  ll final=0;
  int alim=a.length();
  for (int x=0;x<alim;x++) {
    if (a[x]=='0') continue;
    memset(f,0,sizeof f);
    for (int y=0;y<x;y++) f[a[y]-'0']++;
    int n=alim;
    int dlim=a[x]-'0'-1;
    //dbg("x:%d dlim:%d\n",x,dlim);
    for (int d=dlim;d>=0;d--) {
      f[d]++;
      final+=go(n);
      f[d]--;
    }
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
  for (int x=20;x<=20;x++) {
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
  test(); return 0;
  string a;
  cin>>a;
  int ans=solve(a);
  printf("%d\n",ans);
}
