#include "bits/stdc++.h"
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
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=1e5+2;
char inv[256];
int lo[mn];
int hi[mn];
int pre[mn];
int query(int l, int r) {
  return pre[r+1]-pre[l];
}
bool cor(string &a) {
  stack<char> S;
  for (int i=0;i<a.length();i++) {
    char c=a[i];
    if (c=='('||c=='[') {
      S.push(c);
    }
    else {
      if ((!S.empty())&&S.top()==inv[c]) {
        S.pop();
      }
      else {
        S.push(c);
      }
    }
  }
  return S.empty();
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  inv[']']='[';
  inv[')']='(';
  string a; cin>>a;
  int n=a.length();
  pair<int,pii> best=MP(0,MP(-0,-1));
  for (int l=0;l<n;l++) {
    for (int r=l;r<n;r++) {
      string t=a.substr(l,r-l+1);
      if (cor(t)) {
        int c=0;
        for (auto &w:t) {
          if (w=='[') c++;
        }
        chkmax(best,MP(c,MP(-l,r)));
      }
    }
  }
  printf("%d\n",best.fst);
  for (int x=-best.snd.fst;x<=best.snd.snd;x++) printf("%c",a[x]);
  printf("\n");
}





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