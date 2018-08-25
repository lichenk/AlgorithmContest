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
const int mn=5002;
ld f[mn];
ld a[mn];
ld c[mn];
ld vprob[mn];
int vt[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),T=rint();
  for (int i=0;i<n;i++) {
    int per=rint();
    vprob[i]=(ld)per/100.0L;
    vt[i]=rint();
  }
  f[0]=1;
  ld final=0;
  for (int s=0;s<n;s++) {
    ld p=vprob[s];
    ld np=1-p;
    ld npc=1;
    int chorus=vt[s];
    for (int i=0;i<chorus-1;i++) {
      npc*=np;
    }
    for (int t=0;t<=T;t++) {
      ld x=f[t];
      a[t+1]+=x*p;
      if (t+chorus<=T) {
        a[t+chorus]-=x*npc*p;
        c[t+chorus]+=x*npc;
      }
    }
    ld sum=0;
    for (int t=0;t<=T;t++) {
      sum+=a[t];
      f[t]=sum+c[t];
      //printf("t:%d f:%f\n",t,(double)f[t]);
      final+=f[t];
      sum*=np;
      a[t]=0; c[t]=0;
    }
  }
  printf("%.9f\n",(double)final);
}

