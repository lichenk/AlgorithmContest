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
int a[102];
char vact[22];
int i2t[22];
int i2k[22];
vector<int> t2i[3];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d",&n);
  for (int i=0;i<n;i++) scanf("%d",&a[i]);
  sort(a,a+n,greater<int>());
  int k; scanf("%d\n",&k);
  for (int i=0;i<k;i++) {
    scanf("%c %d\n",&vact[i],&i2t[i]);
    i2k[i]=t2i[i2t[i]].size();
    t2i[i2t[i]].PB(i);
  }
  int sz[3]; for (int t=1;t<=2;t++) sz[t]=t2i[t].size();
  int z[3];
  int final=-1e9;
  for (z[1]=0;z[1]<(1<<sz[1]);z[1]++) {
    int best=1e9;
    for (z[2]=0;z[2]<(1<<sz[2]);z[2]++) {
      int score=0;
      int hero=0;
      for (int i=0;i<k;i++) {
        if (vact[i]=='p') {
          if (i2t[i]==1) score+=a[hero++];
          else score-=a[hero++];
        }
        else {
          int bit=(z[i2t[i]]>>i2k[i])&1;
          if (bit) hero++;
        }
      }
      chkmin(best,score);
    }
    chkmax(final,best);
  }
  printf("%d\n",final);
}