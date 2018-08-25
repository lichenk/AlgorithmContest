#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;



int rint()
{
  int x; scanf("%d",&x); return x;
}

const int maxn=5000;
int va[maxn];
const int maxc=2e8+2;
unsigned char vc[maxc];
int main()
{
	memset(vc,-1,sizeof vc);
	int n=rint(); int k=rint();
	for (int i=0;i<n;i++) {
		int a=rint();
		va[i]=a;
		int cum=0;
		for (int t=0;t<=k;t++) {
			chkmin(vc[cum],(unsigned char)t);
			cum+=a;
		}
	}
	int q=rint();
	for (int i=0;i<q;i++) {
		int ans=k+1;
		int target=rint();
		for (int x=0;x<n;x++) {
			int a=va[x];
			int now=target;
			for (int t=0;t<=k;t++) {
				chkmin(ans, t+vc[now]);
				now-=a;
				if (now<0) break;
			}
		}
		if (ans<=k) printf("%d\n",ans);
		else printf("-1\n");
	}
}

