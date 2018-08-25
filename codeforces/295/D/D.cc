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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
const int mn=2004;
int f[2][2][mn][mn];
int tmp[mn][mn];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int rlim,n; scanf("%d%d",&rlim,&n);
  int cur=0,nxt=1;
  ll final=0;
  for (int r=0;r<rlim;r++) {
    for (int x=1;x<=n;x++) for (int y=x+1;y<=n;y++) f[cur][0][x][y]++;
    for (int s=0;s<2;s++) for (int x=1;x<=n;x++) {
      f[cur][s][x][x]=0;
      for (int y=x+1;y<=n;y++) {
        final+=f[cur][s][x][y];
      }
    }
    final%=MOD;
    memcpy(f[nxt],f[cur],sizeof f[cur]);
    {
      int s=0;
      for (int x=1;x<=n;x++) {
        for (int y=x+1;y<=n;y++) {
          f[nxt][s][x][y]+=f[nxt][s][x][y-1];
          if (f[nxt][s][x][y]>=MOD) f[nxt][s][x][y]-=MOD;
        }
      }
      for (int y=1;y<=n;y++) {
        for (int x=y-1;x>=1;x--) {
          f[nxt][s][x][y]+=f[nxt][s][x+1][y];
          if (f[nxt][s][x][y]>=MOD) f[nxt][s][x][y]-=MOD;
        }
      }
    }
    {
      int s=1;
      for (int x=1;x<=n;x++) {
        for (int y=n-1;y>=x;y--) {
          f[nxt][s][x][y]+=f[nxt][s][x][y+1];
          if (f[nxt][s][x][y]>=MOD) f[nxt][s][x][y]-=MOD;
        }
      }
      for (int y=1;y<=n;y++) {
        for (int x=2;x<=y;x++) {
          f[nxt][s][x][y]+=f[nxt][s][x-1][y];
          if (f[nxt][s][x][y]>=MOD) f[nxt][s][x][y]-=MOD;
        }
      }
    }
    memcpy(tmp,f[cur][0],sizeof f[cur][0]);
    for (int x=1;x<=n;x++) {
      for (int y=n-1;y>=x;y--) {
        tmp[x][y]+=tmp[x][y+1];
        if (tmp[x][y]>=MOD) tmp[x][y]-=MOD;
      }
    }
    for (int y=1;y<=n;y++) {
      for (int x=2;x<=y;x++) {
        tmp[x][y]+=tmp[x-1][y];
        if (tmp[x][y]>=MOD) tmp[x][y]-=MOD;
      }
    }
    for (int x=1;x<=n;x++) for (int y=x;y<=n;y++) {
      f[nxt][1][x][y]+=tmp[x][y]-f[cur][0][x][y];
      if (f[nxt][1][x][y]>=MOD) f[nxt][1][x][y]-=MOD;
      if (f[nxt][1][x][y]<0) f[nxt][1][x][y]+=MOD;
    }
    swap(cur,nxt);
  }
  if (final<0) final+=MOD;
  printf("%lld\n",final);
}

