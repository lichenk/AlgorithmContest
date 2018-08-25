#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}

inline bool isPowerOfTwo(ll x)
{
  return (!(x & (x - 1)));
  //return ((x != 0) && !(x & (x - 1)));
}

char s[51][51];
ld f[1<<20];
vector<ll> g[1<<20];
ll cache[51][51];
int popcache[51][51];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int snum; scanf("%d",&snum);
  for (int i=0;i<snum;i++) {
    scanf("%s\n",s[i]);
  }
  if (snum==1) {
    printf("0\n"); return 0;
  }
  int len=strlen(s[0]);
  for (int p=0;p<len;p++) {
    for (int si=0;si<snum;si++) {
      ll msk=0;
      for (int ti=0;ti<snum;ti++) {
        if (s[si][p]==s[ti][p]) msk|=1LL<<ti;
      }
      cache[p][si]=msk;
    }
  }
  ld final=0;
  f[0]=1;
  g[0].PB((1LL<<snum) - 1);
  int zlim=1<<len;
  for (int z=0;z<zlim;z++) { // 2**20
    int ones=0;
    int others=0;
    if (z!=0) {
      int p=__builtin_ffs(z)-1;
      int oz=z^(1<<p);
      for (auto &_w:g[oz]) {
        ll w=_w;
        int cnt=0;
        while(w!=0) {
          int ffs=__builtin_ffsll(w)-1;
          ll part=cache[p][ffs]&w;
          int pop=__builtin_popcountll(part);
          if (pop==1) {ones++;}
          else {others+=pop;}
          g[z].PB(part);
          w^=part;
        }
      }
    }
    else {
      others=snum;
    }
    if (ones+others==0) continue;
    ld fz=f[z];
    final+=(fz*ones*__builtin_popcount(z))/(ones+others);
    int rempos=len-__builtin_popcount(z);
    ld fadder=(fz*others)/(rempos*(ones+others));
    for (int p=0;p<len;p++) {
      int pmsk=1<<p;
      if (0==(pmsk&z)) f[pmsk|z]+=fadder;
    }
  }
  printf("%.10f\n",final);
}

