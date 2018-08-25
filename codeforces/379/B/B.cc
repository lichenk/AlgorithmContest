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
const int mn=400;
int a[mn];
char vans[1000004];
int k=0;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  int lft=0;
  for (int x=1;x<=n;x++) {a[x]=rint(); lft+=a[x];}
  while(lft>0) {
    for (int x=1;x<=n;x++) {
      if (a[x]) {
        a[x]--; lft--;
        vans[k++]='P';
      }
      if (x!=n) vans[k++]='R';
    }
    vans[k++]='L';
    for (int x=n-1;x>1;x--) {
      if (a[x]) {
        a[x]--; lft--;
        vans[k++]='P';
      }
      vans[k++]='L';
    }
  }
  vans[k]='\0';
  printf("%s\n",vans);
}

