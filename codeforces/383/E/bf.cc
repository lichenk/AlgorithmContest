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
const int mk=5;
const int mz=1<<mk;
int vmsk[10001];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
  for (int i=0;i<n;i++) {
    string s; cin>>s;
    int msk=0;
    for (int j=0;j<3;j++) {
      int c=s[j]-'a';
      msk|=1<<c;
    }
    vmsk[i]=msk;
  }
  ll final=0;
  for (int z=0;z<mz;z++) {
    int ans=0;
    for (int i=0;i<n;i++) {
      if (vmsk[i]&z) ans++;
    }
    ll got=ans;
    got=got*got;
    //printf("z:%d got:%lld\n",z,got);
    final^=got;
  }
  printf("%lld\n",final);
}

