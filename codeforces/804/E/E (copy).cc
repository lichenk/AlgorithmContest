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


int rint()
{
  int x; scanf("%d",&x); return x;
}
int perm[100];
bool solve(int n) {
  vector<pair<int,int> > v;
  for (int x=0;x<n;x++) for (int y=x+1;y<n;y++) {
    v.PB(MP(x,y));
  }
  srand(clock());
  for (int k=0;k<58000000;k++) {
    random_shuffle(v.begin(),v.end());
    for (int k=0;k<n;k++) perm[k]=k;
    for (auto &w:v) {
      swap(perm[w.fst],perm[w.snd]);
    }
    bool ok=1;
    for (int k=0;k<n;k++) if (perm[k]!=k) {ok=0;break;}
    if (ok) {
      //for (auto &w:v) {
      //  swap(perm[w.fst],perm[w.snd]);
      //  for (int k=0;k<n;k++) printf("%d ",perm[k]);
      //  printf(" (%d %d)\n",w.fst,w.snd);
      //}
      //printf("\n\n");
      return true;
    }
  } //while(next_permutation(v.begin(),v.end()));
  return false;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int n=6;n<=20;n++) {
    bool can=solve(n);
    printf("n:%d can:%d\n",n,can);
  }
}

