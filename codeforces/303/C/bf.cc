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
const int INF=1<<30;
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

const int MAXN=1e6+4;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int sp[MAXP+1];
vector<int> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    sp[i]=INF;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = sqrt(MAXP)+1;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        chkmin(sp[j],i);
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      chkmin(sp[i],i);
    }
  }
}

vector<int> getfac(int x) {
  if (x==1) return vector<int>({1});
  int p=sp[x];
  vector<int> got=getfac(x/p);
  int gsz=got.size();
  for (int i=0;i<gsz;i++) {
    got.PB(got[i]*p);
  }
  return got;
}
const int mn=5004;
int a[mn];
int n,k;
vector<int> v={0};
const int mx=1e6+4;
int cnt[mx];
void f(int m) {
  //printf("candm:%d\n",m);
  memset(cnt,0,sizeof cnt);
  for (int i=0;i<n;i++) {
    int x=a[i]%m;
    cnt[x]++;
  }
  int have=0;
  for (int x=0;x<m;x++) {
    have+=max(0,cnt[x]-1);
  }
  if (have>k) return;
  printf("%d\n",m);
  exit(0);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
  n=rint(),k=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  for (int x=1;x<=mx+2;x++) {
    f(x);
  }
}
