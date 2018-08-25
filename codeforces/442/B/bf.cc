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
const int mn=100;
ld a[mn];
ld b[mn];
ld p[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=0;i<n;i++) {
    cin>>p[i];
  }
  sort(p,p+n);
  for (int i=0;i<n;i++) {
    ld x=p[i];
    a[i]=x/(1-x);
    b[i]=(1-x);
  }
  int zlim=1<<n;
  pair<ld,int> best=MP(-1.0L,-1);
  for (int z=0;z<zlim;z++) {
    ld sum=0,prod=1;
    for (int i=0;i<n;i++) {
      if ((1<<i)&z) {
        sum+=a[i];
        prod*=b[i];
      }
      ld ans=sum*prod;
      chkmax(best,MP(ans,z));
    }
  }
  //int gz=best.snd;
  //for (int i=0;i<n;i++) {
  //  if ((1<<i)&gz) printf("%d ",i);
  //}
  printf("%.12f\n",(double)best.fst);
}

