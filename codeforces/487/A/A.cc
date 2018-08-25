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
int ohp[2],oatk[2],odef[2];
int hp[2],atk[2],def[2];
int hc,ac,dc;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i=0;i<2;i++) cin>>ohp[i]>>oatk[i]>>odef[i];
  cin>>hc>>ac>>dc;
  ll ans=INF;
  for (int a=0;a<=204;a++) for (int d=0;d<=204;d++) {
    for (int i=0;i<2;i++) hp[i]=ohp[i],atk[i]=oatk[i],def[i]=odef[i];
    atk[0]+=a; def[0]+=d;
    if (atk[0]<=def[1]) continue;
    while(hp[1]>0) {
      for (int p=0;p<2;p++) hp[p^1]-=max(0,atk[p]-def[p^1]);
    }
    int need=max(0,1-hp[0]);
    ll cost=(ll)a*(ll)ac+(ll)d*(ll)dc+(ll)need*(ll)hc;
    chkmin(ans,cost);
  }
  printf("%lld\n",ans);
}

