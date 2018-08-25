#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
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
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}
const int mn=1e6+4;
char s[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,k; cin>>n>>k;
	if (n<k) {
		cout<<-1<<endl; return 0;
	}
	if (k==1) {
		if (n==1) {
			cout<<"a"<<endl;
		}
		else {
			cout<<-1<<endl;
		}
		return 0;
	}
	for (int i=0;i<n-(k-2);i++) {
		s[i]=(i&1)?'b':'a';
	}
	char c='c';
	for (int i=n-(k-2);i<n;i++) {
		s[i]=c;
		c++;
	}
	s[n]='\0';
	printf("%s\n",s);
}

