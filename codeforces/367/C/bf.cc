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
bool a[10][10];
int solve(int n) {
  int want=(n*(n-1))/2;
  int final=1000000;
  for (int k=0;k<2000000;k++) {
    if (0==(k&0xfff)) srand(time(0)+clock()+rand());
    memset(a,0,sizeof a);
    int got=0;
    int prev=rand()%n;
    for (int i=2;;i++) {
      int now=rand()%n;
      while(now==prev) now=rand()%n;
      {
        int x=prev,y=now; if (x>y) swap(x,y);
        if (!a[x][y]) {
          //printf("got %d %d\n",x,y);
          a[x][y]=1; got++;
          if (got==want) {
            chkmin(final,i);
            break;
          }
        }
      }
      prev=now;
    }
  }
  return final;
}
int main() 
{
  for (int n=2;n<=20;n++) {
    int ans=solve(n);
    printf("%d, ",ans);
    fflush(stdout);
  }
}

