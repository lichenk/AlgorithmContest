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
int n;
const int mn=104;
int a[mn];
bool f(int k) {
	vector<int> p[mn];
	int pile=0;
	for (int i=0;i<n;i++) {
		int x=a[i];
		p[pile].PB(x);
		pile++;
		if (pile>=k) pile=0;
	}
	for (int t=0;t<k;t++) {
		int sz=p[t].size();
		for (int i=0;i<sz;i++) {
			if (p[t][i]<sz-i-1) return false;
		}
	}
	return true;
}
int main()
{
	//a
	ios_base::sync_with_stdio(false); cin.tie(0);
	 scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n,greater<int>());
	for (int k=1;k<=n;k++) {
		if (f(k)) {
			printf("%d\n",k);
			return 0;
		}
	}	
}

