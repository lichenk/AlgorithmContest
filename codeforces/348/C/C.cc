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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
const int mn=1e5+4;
const int lim=sqrt(mn);
const int ms=lim;
//const int lim=6;
//const int ms=4;
ll a[mn];
int *vs[mn];
int vsz[mn];
vector<int>a2b[mn];
vector<int> a2s[mn];
int s2b[mn][ms];
ll vsum[mn];
ll vch[mn];
vector<int> h2b;
int b2h[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint(),q=rint();
  for (int x=1;x<=n;x++) a[x]=rint();
  int bsz=0;
  for (int s=1;s<=m;s++) {
    int sz=rint();
    vsz[s]=sz;
    vs[s]=new int[sz];
    if (sz>=lim) {
      h2b.PB(s);
      b2h[s]=bsz++;
      for (int i=0;i<sz;i++) {
        int x=rint();
        a2b[x].PB(s);
        vs[s][i]=x;
        vsum[s]+=a[x];
      }
    }
    else for (int i=0;i<sz;i++) {
      int x=rint();
      a2s[x].PB(s);
      vs[s][i]=x;
    }
  }
  for (int x=1;x<=n;x++) {
    int a2bsz=a2b[x].size();
    for (int i=0;i<a2bsz;i++) {
      int ib=a2b[x][i];
      for (int j=0;j<i;j++) {
        int jb=a2b[x][j];
        s2b[ib][b2h[jb]]++;
        s2b[jb][b2h[ib]]++;
      }
    }
    for (auto &s:a2s[x]) {
      for (int i=0;i<a2bsz;i++) {
        int ib=a2b[x][i];
        s2b[s][b2h[ib]]++;
      }
    }
  }
  for (int jj=0;jj<q;jj++) {
    char ch=rch();
    int s=rint();
    if (ch=='?') {
      ll ans;
      if (vsz[s]>=lim) {
        ans=vsum[s];
      }
      else {
        ans=0;
        int sz=vsz[s];
        for (int i=0;i<sz;i++) ans+=a[vs[s][i]];
      }
      //printf("ans:%lld\n",ans);
      for (int h=0;h<bsz;h++) {
        ans+=s2b[s][h]*vch[h];
        //printf("%d*%lld\n",s2b[s][h],vch[h]);
      }
      printf("%lld\n",ans);
    }
    else {
      int v=rint();
      if (vsz[s]>=lim) {
        vch[b2h[s]]+=v;
        vsum[s]+=v*(ll)vsz[s];
      }
      else {
        int sz=vsz[s];
        for (int i=0;i<sz;i++) {
          int id=vs[s][i];
          a[id]+=v;
          for (auto &b:a2b[id]) {
            vsum[b]+=v;
          }
        }
      }
    }
  }
}

