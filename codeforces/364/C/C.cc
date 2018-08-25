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

const int MAXN=5004;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int sp[MAXP+1];
vector<ll> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = ceil(sqrt(MAXP))+1;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      if (i*(ll)i<=MAXP) {
        for (int j = i*i; j <= MAXP; j+=i) {
          sieve_array[j] = false;
        }
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
    }
  }
}

int k;
int xlim;
bool f[(2*5000*5000)+1];
void go(int plim) {
  f[1]=1;
  for (int x=2;x<=xlim;x++) f[x]=0;
  for (int pi=0;pi<plim;pi++) {
    int p=gpv[pi];
    int elim=0;
    int now=1;
    while(now<k) {
      now*=pi; elim++;
    }
    for (int e=0;e<elim;e++) {
      int lim=xlim/p;
      for (int x=1;x<=lim;x++) {
        f[x*p]|=f[x];
      }
    }
  }
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  scanf("%d",&k);
  xlim=2*k*k;
	for (int plim=1;;plim++) go(plim);
}

