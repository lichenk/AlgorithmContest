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

pair<ll,ll> vp[100005];
bool cmp(const pair<ll,ll> &x,const pair<ll,ll> &y) {
  ll a=x.fst,c=y.fst;
  ll b=x.snd,d=y.snd;
  ll l=a*d,r=b*c;
  //if (l==r) {
  //  return x.snd<y.snd;
  //}
  return l>r;
}
const int MAXGO=600;
vector<ll> vx[4];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<n;i++) {
    vp[i].snd=rint();
    vp[i].fst=rint();
  }
  sort(vp,vp+n,cmp);
  ll lim=max(0,m-MAXGO);
  ll curw=0;
  ll curp=0;
  ll idx=0;
  for (;idx<n;idx++) {
    if (curw+vp[idx].snd>lim) break;
    curp+=vp[idx].fst;
    curw+=vp[idx].snd;
  }
  int vlim[4];
  vlim[1]=MAXGO;
  vlim[2]=MAXGO/2;
  vlim[3]=MAXGO/3;
  for (;idx<n;idx++) {
    int wt=vp[idx].snd;
    //printf("Ins:wt%d %d\n",wt,0);
    if (vx[wt].size()<vlim[wt]) vx[wt].PB(vp[idx].fst);
  }
  for (int wt=1;wt<=3;wt++) {
    sort(vx[wt].begin(),vx[wt].end(),greater<ll>());
    vx[wt].insert(vx[wt].begin(), 0);
    //for (auto &w:vx[wt]) printf("%d ",w);
    //printf(" end %d\n",wt);
    for (int i=1;i<vx[wt].size();i++) {
      vx[wt][i]+=vx[wt][i-1];
    }
  }
  ll remw=m-curw;
  //printf("remw:%d\n",remw);
  ll best=0;
  for (int a=0;a<vx[3].size();a++) {
    if (a*3LL>remw) break;
    //printf("a:%d vx[3].size():%d\n",a,(int)vx[3].size());
    for (int b=0;b<vx[2].size();b++) {
      if (a*3LL+b*2LL>remw) break;
      for (int c=0;c<vx[1].size();c++) {
        if (a*3LL+b*2LL+c>remw) break;
        ll sum=vx[3][a]+vx[2][b]+vx[1][c];
        //printf("a*3+b*2+c:%d sum:%lld\n",a*3+b*2+c,sum);
        chkmax(best,sum);
      }
    }
  }
  ll final=best+curp;
  printf("%lld\n",final);
}

