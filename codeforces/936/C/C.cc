#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

map<char,int> hs,ht;
string s,t;
vi vans;
int n;
void flip(int x) {
  if (x==n) return;
  assert(0<=x);
  assert(x<n);
  vans.PB(x);
  string A=s.substr(0,x);
  string B=s.substr(x,n-x);
  reverse(B.begin(),B.end());
  string olds=s;
  s=B+A;
  //printf("x:%d\no:%s\ns:%s\n",x,olds.c_str(),s.c_str());
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n;
  cin>>s>>t;
  //for (auto &w:s) hs[w]++;
  //for (auto &w:t) ht[w]++;
  //if (hs!=ht) {printf("-1\n"); return 0;}
  vi p;
  for (int x=0;x<n;x++) {
    reverse(p.begin(),p.end());
    p.PB(x);
  }
  vi q=p;
  for (int x=0;x<n;x++) {
    q[p[x]]=x;
  }
  for (int i=0;i<n;i++) {
    int targ=-1;
    for (int x=i;x<n;x++) {
      if (s[x]==t[q[i]]) {
        targ=x;
      }
    }
    //printf("Want:%c targ:%d\n",t[q[i]],targ);
    if (targ==-1) {
      printf("-1\n"); exit(0);
    }
    flip(targ);
    int A=targ-i; int lft=n-A;
    flip(lft);
    flip(0);
  }
  if (s!=t) {
    printf("-1\n"); return 0;
  }
printf("%d\n",(int)vans.size());
for (auto &w:vans) printf("%d ",n-w);
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