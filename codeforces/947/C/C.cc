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

typedef struct _trie {
  int val;
  struct _trie *ch[2];
} trie;

trie *newnode() {
  trie *r = new trie;
  r->val=0;
  r->ch[0]=NULL;
  r->ch[1]=NULL;
  return r;
}

void ins(trie *r, int x, int k) {
  r->val++;
  if (k==-1) return;
  int b=(x>>k)&1;
  if (r->ch[b]==NULL) {
    r->ch[b]=newnode();
  }
  ins(r->ch[b],x,k-1);
}

int query(trie *r, int x, int k, int got) {
  r->val--;
  if (k==-1) return got;
  int b=(x>>k)&1;
  if (r->ch[b]!=NULL&&(r->ch[b]->val>0)) {
    return query(r->ch[b],x,k-1,got);
  }
  else {
    return query(r->ch[b^1],x,k-1,got|(1<<k));
  }
}
const int mn=300000+4;
int a[mn],p[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  for (int i=0;i<n;i++) p[i]=rint();
  trie *r=newnode();
  for (int i=0;i<n;i++) ins(r,p[i],29);
  for (int i=0;i<n;i++) {
    int ans=query(r,a[i],29,0);
    printf("%d ",ans);
  }
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