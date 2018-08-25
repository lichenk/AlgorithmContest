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
const int mn=5e5+4;
int va[mn];
int vr[mn];
int vl[mn];
bitset<mn> used;
typedef pair<pair<int,int>,int> T;
priority_queue<T> pq; // Max heap
void ins(int i) {
  if (used[i]) return;
  int a=va[vl[i]],mid=va[i],b=va[vr[i]];
  T t=MP(MP(min(a,b),mid),i);  
  pq.push(t);
}
const int mv=1e6+2;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=1;i<=n;i++) {
    int x=rint();
    va[i]=x;
  }
  for (int i=1;i<=n;i++) {
    vr[i]=i+1;vl[i]=i-1;
  }
  for (int i=2;i<=n-1;i++) {
    ins(i);
  }
  ll ans=0;
  int left=n-2;
  while(!pq.empty()) {
    T t=pq.top(); pq.pop();
    int i=t.snd;
    int minab=t.fst.fst;
    int l=vl[i],r=vr[i];
    if ((!used[i])&&(!used[l])&&(!used[r])&&minab==min(va[vl[i]],va[vr[i]])) {
      dbg("i:%d l:%d r:%d minab:%d\n",i,l,r,minab);
      vr[l]=r;
      vl[r]=l;
      used[i]=true;
      ans+=minab;
      ins(l); ins(r);
      left--;
      if (left==0) break;
    }
  }
  printf("%lld\n",ans);
}
