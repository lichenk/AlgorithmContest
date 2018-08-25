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
const int mn=100005;
int n;
int a[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int i=1;i<=n;i++) a[i]=rint();
  int q=rint();
  int lastans=0;
  for (int i=0;i<q;i++) {
    int t=rint(),lp=rint(),rp=rint();
    int l=((lp+lastans-1)%n)+1;
    int r=((rp+lastans-1)%n)+1;
    if (l>r) swap(l,r); 
    if (t==1) {
      int ar=a[r];
      for (int x=r;x>=l+1;x--) {
        a[x]=a[x-1];
      }
      a[l]=ar;
      //for (int x=1;x<=n;x++) printf("%d ",a[x]);
      //printf("endq\n");
    }
    else {
      int kp=rint();
      int k=((kp+lastans-1)%n)+1;
      //printf("l:%d r:%d k:%d\n",l,r,k);
      int ans=0;
      for (int x=l;x<=r;x++) if(a[x]==k) ans++;
      lastans=ans;
      printf("%d\n",ans);
    }
    //for (int x=1;x<=n;x++) printf("%d ",a[x]);
    //printf("\n");
  }
}

