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
const int mn=1002;
const int ms=10001;
int f[2][2*ms];
int a[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d",&n);
  for (int i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  int cur=0,nxt=1;
  int final=0;
  for (int p=0;p<n;p++) {

    //for (int s=0;s<2*ms;s++) {
    //int now=f[cur][s];
    //if (now!=0) {
    //  printf("p:%d s:%d now:%d\n",p,s,now);
    //}}

    memset(f[nxt],0,sizeof f[nxt]);
    int v=a[p];
    final+=f[cur][ms];
    if (final>=MOD) final-=MOD;
    f[cur][ms]++;
    for (int s=0;s<2*ms;s++) {
      int now=f[cur][s];
      if (now!=0) {
        {int got=f[nxt][s+v]+now;
        if (got>=MOD) got-=MOD;
        f[nxt][s+v]=got;}
        {int got=f[nxt][s-v]+now;
        if (got>=MOD) got-=MOD;
        f[nxt][s-v]=got;}
      }
    }
    swap(cur,nxt);
  }
  //for (int s=0;s<2*ms;s++) {
  //  int now=f[cur][s];
  //  if (now!=0) {
  //    printf("p:%d s:%d now:%d\n",n,s,now);
  //  }}
  final+=f[cur][ms];
  if (final>=MOD) final-=MOD;
  printf("%d\n",final);
}