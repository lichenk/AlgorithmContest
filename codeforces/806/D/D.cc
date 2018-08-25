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
const ll INF=2e15;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mn=2004;
int a[mn][mn];
int leastEdge[mn];
int n;
ll dist[mn];
priority_queue<pair<ll,int>,vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  int s=2e9;
  for (int i=0;i<n;i++) {
    for (int j=1;j<n-i;j++) {
      int x=rint();
      a[i][i+j]=x;
      a[i+j][i]=x;
      chkmin(s,x);
    }
  }
  for (int x=0;x<n;x++) {
    int le=2e9;
    for (int y=0;y<n;y++) {
      if (x!=y) chkmin(le,a[x][y]);
    }
    leastEdge[x]=le;
  }
  for (int x=0;x<n;x++) dist[x]=INF;
  ll newdist=(ll)s*(ll)(n-1);
  for (int x=0;x<n;x++) {
    for (int y=0;y<x;y++) {
      if (a[x][y]==s) {
        if (newdist<dist[x]) {
          dist[x]=newdist;
          pq.push(MP(newdist,x));
        }
        if (newdist<dist[y]) {
          dist[y]=newdist;
          pq.push(MP(newdist,y));
        }
      }
    }
  }
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    ll odist=got.fst;
    int x=got.snd;
    if (odist>dist[x]) continue;
    for (int y=0;y<n;y++) {
      if (x==y) continue;
      ll newdist1=odist+a[x][y]-s;
      ll newdist2=odist+2*(leastEdge[y]-s);
      ll newdist=min(newdist1,newdist2);
      if (newdist<dist[y]) {
        dist[y]=newdist;
        pq.push(MP(newdist,y));
      }
    }
  }
  for (int x=0;x<n;x++) printf("%lld\n",dist[x]);
}
