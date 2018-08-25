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

char rch()
{
  char x; scanf("%c",&x); return x;
}

typedef struct S {
  map<int,int,greater<int> > ml,mm,mr;
  int len;
} S;
S identity;
typedef pair<int,int> pii;
void combine(S &dest,S &x, S &y) {
  if (x.len==0) {dest=y; return;}
  if (y.len==0) {dest=x; return;}
  dest.len=x.len+y.len;
  if (x.mm.size()>y.mm.size()) {
    dest.mm=x.mm;
    for (auto &w:y.mm) {
      chkmax(dest.mm[w.fst],w.snd);
    }
  }
  else {
    dest.mm=y.mm;
    for (auto &w:x.mm) {
      chkmax(dest.mm[w.fst],w.snd);
    }
  }
  //printf("xlen:%d ylen:%d\n",x.len,y.len);
  for (auto &xw:x.mr) {
    for (auto &yw:y.ml) {
      //printf("xw:%d %d. yw:%d %d\n",xw.fst,xw.snd,yw.fst,yw.snd);
      int key=xw.fst+yw.fst;
      int ht=min(xw.snd,yw.snd);
      //printf("C %d %d\n",key,ht);
      chkmax(dest.mm[key],ht);
    }
  }
  {
    int best=-1;
    for (auto it=dest.mm.begin();it!=dest.mm.end();) {
      if (best>=it->snd) {
        it=dest.mm.erase(it);
      }
      else {
        best=it->snd;
        ++it;
      }
    }
  }
  dest.ml=x.ml;
  {
    int xh=x.ml[x.len];
    int lastht=-1;
    for (auto w:y.ml) {
      int nowht=min(xh,w.snd);
      if (nowht>lastht) {
        int key=x.len+w.fst;
        //printf("A %d %d\n",key,nowht);
        dest.ml[key]=nowht;
        chkmax(dest.mm[key],nowht);
        lastht=nowht;
      }
    }
  }
  dest.mr=y.mr;
  {
    int yh=y.mr[y.len];
    int lastht=-1;
    for (auto w:x.mr) {
      int nowht=min(yh,w.snd);
      if (nowht>lastht) {
        int key=y.len+w.fst;
        dest.mr[key]=nowht;
        //printf("B %d %d\n",key,nowht);
        chkmax(dest.mm[key],nowht);
        lastht=nowht;
      }
    }
  }
}
S combine(S &x, S &y) {
  S dest;
  if (x.len==0) {dest=y; return dest;}
  if (y.len==0) {dest=x; return dest;}
  dest.len=x.len+y.len;
  if (x.mm.size()>y.mm.size()) {
    dest.mm=x.mm;
    for (auto &w:y.mm) {
      chkmax(dest.mm[w.fst],w.snd);
    }
  }
  else {
    dest.mm=y.mm;
    for (auto &w:x.mm) {
      chkmax(dest.mm[w.fst],w.snd);
    }
  }
  //printf("xlen:%d ylen:%d\n",x.len,y.len);
  for (auto &xw:x.mr) {
    for (auto &yw:y.ml) {
      //printf("xw:%d %d. yw:%d %d\n",xw.fst,xw.snd,yw.fst,yw.snd);
      int key=xw.fst+yw.fst;
      int ht=min(xw.snd,yw.snd);
      //printf("C %d %d\n",key,ht);
      chkmax(dest.mm[key],ht);
    }
  }
  {
    int best=-1;
    for (auto it=dest.mm.begin();it!=dest.mm.end();) {
      if (best>=it->snd) {
        it=dest.mm.erase(it);
      }
      else {
        best=it->snd;
        ++it;
      }
    }
  }
  dest.ml=x.ml;
  {
    int xh=x.ml[x.len];
    int lastht=-1;
    for (auto w:y.ml) {
      int nowht=min(xh,w.snd);
      if (nowht>lastht) {
        int key=x.len+w.fst;
        //printf("A %d %d\n",key,nowht);
        dest.ml[key]=nowht;
        chkmax(dest.mm[key],nowht);
        lastht=nowht;
      }
    }
  }
  dest.mr=y.mr;
  {
    int yh=y.mr[y.len];
    int lastht=-1;
    for (auto w:x.mr) {
      int nowht=min(yh,w.snd);
      if (nowht>lastht) {
        int key=y.len+w.fst;
        dest.mr[key]=nowht;
        //printf("B %d %d\n",key,nowht);
        chkmax(dest.mm[key],nowht);
        lastht=nowht;
      }
    }
  }
  return dest;
}

const ll MAXN=100000;
S t[2*MAXN];
int segn;
void build(int n) {  // build the tree
  identity.len=0;
  segn=n;
  for (int i = n - 1; i > 0; --i) {
    combine(t[i], t[i<<1], t[i<<1|1]);
  }
}
//void modify(int p, const S& value) {
//  int n=segn;
//    for (t[p += n] = value; p >>= 1; ) combine(t[p], t[p<<1], t[p<<1|1]);
//}
int query(int l, int r, int w) {
  int n=segn;
  r++;
  S resl=identity, resr=identity;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) {resl = combine(resl, t[l++]);}
      if (r&1) {resr = combine(t[--r], resr);}
  }
  S got=combine(resl, resr);
  auto it=got.mm.upper_bound(w);
  if (it!=got.mm.begin()) {
    --it;
    return it->snd;
  }
  return 0;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    int h=rint();
    t[n+i].ml[1]=h;
    t[n+i].mr[1]=h;
    t[n+i].mm[1]=h;
    t[n+i].len=1;
  }
  build(n);
  int m=rint();
  for (int i=0;i<m;i++) {
    int l=rint()-1,r=rint()-1,w=rint();
    int ans=query(l,r,w);
    printf("%d\n",ans);
  }
}
