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
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int rint()
{
  int x; scanf("%d",&x); return x;
}
string s[55];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m; cin>>n>>m;
  for (int x=0;x<n;x++) cin>>s[x];
  map<char,int> b;
  b['f']=1;
  b['a']=1;
  b['c']=1;
  b['e']=1;
  int ans=0;
  for (int x=0;x<n-1;x++) for (int y=0;y<m-1;y++) {
    map<char,int> h;
    h[s[x][y]]++;
    h[s[x][y+1]]++;
    h[s[x+1][y]]++;
    h[s[x+1][y+1]]++;
    if(h==b) ans++;
  }
  cout<<ans<<endl;
}

