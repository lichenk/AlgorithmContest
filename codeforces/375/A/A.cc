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
bool c[20];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a; cin>>a;
	vector<int> v={1,6,8,9};
	for (auto &w:v) c[w]=1;
	int asz=a.length();
	int zeros=0;
	vector<int> final;
	int rem=0;
	for (int i=0;i<asz;i++) {
		int d=a[i]-'0';
		if (d==0) zeros++;
		else if (c[d]) {
			c[d]=0;
		}
		else {
			final.PB(d);
			rem*=10;
			rem+=d;
			rem%=7;
		}
	}
	set<int> s;
	do {
		int ans=rem;
		for (auto &w:v) {
			ans*=10;
			ans+=w;
			ans%=7;
		}
		if (ans==0) {
			int now=0;
			for (auto &w:final) {
				now*=10; now+=w; now%=7;
				printf("%d",w);
			}
			for (auto &w:v) {
				now*=10; now+=w; now%=7;
				printf("%d",w);
			}
			for (int i=0;i<zeros;i++) {
				now*=10; now+=0; now%=7;
				printf("0");
			}
			assert(now==0);
			printf("\n"); return 0;
		}
	} while(next_permutation(v.begin(),v.end()));
}
