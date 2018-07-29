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
const int mk=18;
const int mn=1<<mk;
typedef pair<int,int> pii;
pii f[mn][2];
pii b[4];
int main(){
	ios::sync_with_stdio(false);
	int klim; scanf("%d",&klim);
	int zlim=1<<klim;
	for (int i=0;i<zlim;i++) {
		int x; scanf("%d",&x);
		f[i][0]=MP(x,i);
		f[i][1]=MP(-1,-1);
	}
  for (int k=0;k<klim;k++) {
    for (int z=0;z<(1<<klim);z++) {
      if (z&(1<<k)) {
      	for (int t=0;t<2;t++) b[t]=f[z][t];
      	for (int t=0;t<2;t++) b[t+2]=f[z^(1<<k)][t];
      	sort(b,b+4);
      	int has=0;
      	for (int i=3;i>=0;i--) {
      		if (i==3||b[i]!=b[i+1]) {
      			f[z][has++]=b[i];
      			if (has==2) break;
      		}
      	}
      }
    }
  }
  int ans=0;
  for (int z=1;z<zlim;z++) {
  	int cand=f[z][0].fst+f[z][1].fst;
  	chkmax(ans,cand);
  	printf("%d\n",ans);
  }
}
