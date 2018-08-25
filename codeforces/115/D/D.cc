#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000003;
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
const int mn=2000;
char a[mn];
bool isdig(char c) {
  return ('0'<=c&&c<='9');
}
int f[mn][mn];
vector<int> v,p;
int v2p[mn];
const int ADD=0,MUL=1,NUM=2;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%s\n",a); int alen=strlen(a);
   v.reserve(alen);
  for (int i=0;i<alen;i++) {
    char c=a[i];
    if (c=='+'||c=='-') v.PB(ADD);
    else if (c=='/'||c=='*') v.PB(MUL);
    else if (isdig(c)) {
      if (i==0||!isdig(a[i-1])) v.PB(NUM);
    }
  }
  memset(v2p,-1,sizeof v2p);
  int n=v.size();
  for (int x=0;x<n;x++) {
    //printf("x:%d v:%d\n",x,v[x]);
    if (v[x]==NUM) f[x][x]=1;
    else {
      v2p[x]=p.size();
      p.PB(x);
    }
  }
  for (int x=n-2;x>=0;x--) {
    if(v2p[x]==-1) v2p[x]=v2p[x+1];
  }
  int psz=p.size();
  {
    int d=1;
    for (int l=0;l+d<n;l++) {
      int r=l+d;
      //printf("l:%d r:%d\n",l,r);
      int ans=0;
      if (v[l]==ADD) ans=f[l+1][r];
      f[l][r]=ans;
      //printf("l:%d r:%d ans:%d\n",l,r,ans);
    }
  }
  for (int d=2;d<n;d++) {
    for (int l=0;l+d<n;l++) {
      int r=l+d;
      //printf("l:%d r:%d\n",l,r);
      ll ans=0;
      if (v[l]==ADD) ans=f[l+1][r];
      int sl=v2p[l+1];
      if (sl!=-1) {
        int sr=v2p[r];
        if (sr==-1) sr=psz;
        for (int s=sl;s<sr;s++) {
          int x=p[s];
          ans+=(f[l][x-1]*(ll)f[x+1][r]);
        }
      }
      f[l][r]=ans%MOD;
      //printf("l:%d r:%d ans:%d\n",l,r,ans);
    }
  }
  printf("%d\n",f[0][n-1]);
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