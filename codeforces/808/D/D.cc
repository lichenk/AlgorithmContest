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


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=1e5+4;
ll a[mn];
ll pre[mn];
ll diff[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  ll sum=0;
  for (int i=0;i<=n;i++) {
    pre[i]=sum;
    sum+=a[i];
  }
  for (int i=0;i<=n;i++) {
    diff[i]=pre[i]-(sum-pre[i]);
  }
  map<ll,int> spre,ssuf;
  for (int i=0;i<n;i++) {
    ssuf[a[i]]++;
  }
  for (int i=0;i<=n;i++) {
    ll dif=diff[i];
    //printf("i:%d diff[i]:%lld\n",i,dif);
    if (dif%2==0) {
      dif/=2;
      if (dif==0) {
        printf("YES\n"); return 0;
      }
      else if (dif>0) {
        auto it=spre.find(dif);
        if (it!=spre.end()) {
          printf("YES\n"); return 0;
        }
      }
      else {
        auto it=ssuf.find(-dif);
        if (it!=ssuf.end()) {
          printf("YES\n"); return 0;
        }
      }
    }
    if (i==n) break;
    ll x=a[i];
    //printf("Mani:%lld\n",x);
    spre[x]++;
    auto it=ssuf.find(x);
    if (it->snd==1) ssuf.erase(it);
    else it->snd -= 1;
  }
  printf("NO\n");
}

