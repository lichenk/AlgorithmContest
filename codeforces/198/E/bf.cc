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





const int MAXSZ=(512-64)*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  //preidx+=(((int)size) + 7) & ~0x07;
  preidx+=size;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}
//#define MAXR 20000000004
//#define MAXC 20000000004
const int mc=250001;
const int MAXR=mc,MAXC=mc;
#include <assert.h>
#include <stddef.h>
typedef int STV;
inline STV gcd2(STV X, STV Y) {
  return max(X,Y);
}
struct layer2_node {
    layer2_node(int low, int high)
            : low(low), high(high), lft(NULL), rht(NULL), value(0LL) {
    }

    int low;
    int high;
    layer2_node* lft;
    layer2_node* rht;
    STV value;
};

struct layer1_node {
    layer1_node() : lft(NULL), rht(NULL), l2(0, MAXC) {
    }

    layer1_node* lft;
    layer1_node* rht;
    layer2_node l2;
};

static void update2(layer2_node* node, int Q, STV K) {
  int low = node->low;
  int high = node->high;
  int mid = (low + high) >> 1;
  if(low + 1 == high) {
    /* For leaf nodes we just update the value directly. */
    node->value = K;
    return;
  }

  layer2_node*& tgt = Q < mid ? node->lft : node->rht;
  if(tgt == NULL) {
    /* If there is no node on this side of the tree create a new leaf node
     * containing exactly our update point. */
    tgt = new layer2_node(Q, Q + 1);
    tgt->value = K;
  } else if(tgt->low <= Q && Q < tgt->high) {
    /* If the existing node contains our query point continue inserting there.
     */
    update2(tgt, Q, K);
  } else {
    /* Otherwise traverse down the virtual tree until the side of our query node
     * and the side of the existing node differ.  Create this node and continue
     * updating along it. */
    do {
      (Q < mid ? high : low) = mid;
      mid = (low + high) >> 1;
    } while((Q < mid) == (tgt->low < mid));

    layer2_node* nnode = new layer2_node(low, high);
    (tgt->low < mid ? nnode->lft : nnode->rht) = tgt;
    tgt = nnode;

    update2(nnode, Q, K);
  }

  /* Internal nodes get updated as the gcd of its leaves. */
  int got=node->lft ? node->lft->value : 0;
  if (got) node->value=got;
  else {node->value = node->rht ? node->rht->value : 0;}
}

STV query2(layer2_node* nd, int A, int B) {
  /* The same as the level 1 queries except the interval each node represents
   * may skip some levels of the tree so we store them in the node itself. */
  if(nd == NULL || B <= nd->low || nd->high <= A) {
    return 0;
  } else if(A <= nd->low && nd->high <= B) {
    return nd->value;
  }
  STV got1=query2(nd->lft, A, B);
  if (got1) return got1;
  return query2(nd->rht, A, B);
}

static void update1(layer1_node* node, int low, int high,
                    int P, int Q, STV K) {
  int mid = (low + high) >> 1;

  if(low + 1 == high) {
    update2(&node->l2, Q, K);
  } else {
    layer1_node*& nnode = P < mid ? node->lft : node->rht;
    (P < mid ? high : low) = mid;
    if(nnode == NULL) {
      nnode = new layer1_node();
    }
    update1(nnode, low, high, P, Q, K);

    /* Compute what value to update with. */
    STV got1=node->lft ? query2(&node->lft->l2, Q, Q + 1) : 0;
    if (got1) K=got1;
    else K = node->rht ? query2(&node->rht->l2, Q, Q + 1) : 0;
    update2(&node->l2, Q, K);
  }
}

STV query1(layer1_node* nd, int low, int high,
           int B1, int B2) {
  /* Scan down the tree short-circuiting when we reach a node that contains
   * our entire query interval and combining the result of the level2 queries.
   */
  if(nd == NULL || B1 <= low) {
    return 0;
  } else if(high <= B1) {
    return query2(&nd->l2, 0, B2);
  }
  int mid = (low + high) >> 1;
  int got1=query1(nd->lft, low, mid, B1, B2);
  if (got1) return got1;
  return query1(nd->rht, mid, high, B1, B2);
}

void init(int R, int C) {
}
layer1_node root;
void update(layer1_node &root, int P, int Q, STV K) {
  //printf("P:%d Q:%d K:%d\n",P,Q,K);
  update1(&root, 0, MAXR, Q, P, K);
}

STV calculate(layer1_node &root, int U, int V) {
  int ans=query1(&root, 0, MAXR, V + 1, U + 1);
  //printf("xl:%d yl:%d xh:%d yh:%d ans:%d\n",P,Q,U,V,ans);
  return ans;
}














const int MAXX=1e9+4;
int fsq(ll targ) {
  ll xc=sqrt(targ);
  if (xc>=MAXX) return MAXX;
  int xcc=xc;
  for (int x=max(0,xcc-1);;x++) {
    if (x*(ll)x >= targ) return x;
  }
}
const int mn=250000+2;
int hwp[mn],hwr[mn];
vector<int> vh[mn];

void makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
int bins(vector<int> &vx, int x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

int vp[mn]; int vr[mn];
int vwp[mn]; int vwr[mn];
vector<int> bp,br;
bool vbad[mn];
vector<pair<pii, int> > vv;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int sx=rint(),sy=rint(); vp[0]=rint(),vr[0]=rint(); int n=rint();
  queue<int> q;
  for (int i=1;i<=n;i++) {
    int x=rint(),y=rint();
    int dx=(x-sx),dy=y-sy;
    ll dist2=dx*(ll)dx + dy*(ll)dy;
    vwr[i]=fsq(dist2);
    vwp[i]=rint();
    vp[i]=rint(),vr[i]=rint();
    if (vwr[i]>=MAXX) {
      vbad[i]=true;
    }
  }
  bp.reserve(n+1);
  for (int i=0;i<=n;i++) {
    bp.PB(vp[i]);// bp.PB(vwp[i]);
  }
  makeunique(bp);
  for (int i=0;i<=n;i++) {
    vp[i]=bins(bp,vp[i]);
    vwp[i]=bins(bp,vwp[i]);
  }
  for (int i=0;i<=n;i++) {
    br.PB(vr[i]);// br.PB(vwr[i]);
  }
  br.reserve(n+1);
  makeunique(br);
  for (int i=0;i<=n;i++) {
    vr[i]=bins(br,vr[i]);
    vwr[i]=bins(br,vwr[i]);
  }
  for (int i=1;i<=n;i++) {
    //printf("i:%d vwp:%d vwr:%d vp:%d vr:%d\n",i,bp[vwp[i]],br[vwr[i]],bp[vp[i]],br[vr[i]]);
    if (vbad[i]) continue;
    vv.PB(MP(MP(vwp[i],vwr[i]),i));
  }
  sort(vv.begin(),vv.end());
  int vs=vv.size();
  int hid=0;
  pii prev;
  int ans=0;
  for (int i=0;i<vs;i++) {
    auto &w=vv[i];
    pii sig=w.fst;
    int p = w.fst.fst, r = w.fst.snd;
    if (i==0||sig!=prev) {
      hid++;
      hwr[hid] = r;
      hwp[hid] = p;
      if (!(p<=vp[0]&&r<=vr[0])) {
        update(root, p, r, hid);
      }
      prev=sig;
    }
    if (!(p<=vp[0]&&r<=vr[0])) {
      vh[hid].PB(w.snd);
    }
    else {
      q.push(w.snd);
      ans++;
    }
  }

  while(!q.empty()) {
    int qid=q.front(); q.pop();
    int hp=vp[qid],hr=vr[qid];
    while(1) {
      int hid = calculate(root, hp, hr);
      if (hid==0) break;
      update(root,hwp[hid],hwr[hid],0);
      ans+=vh[hid].size();
      for (auto id:vh[hid]) {
        //printf("id:%d\n",id);
        q.push(id);
      }
    }
  }
  printf("%d\n",ans);

}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
  size_t remaining = stdinDataEnd - stdinPos;
  if (remaining < amount) {
    memmove(stdinBuffer, stdinPos, remaining);
    size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
    stdinPos = stdinBuffer;
    stdinDataEnd = stdinBuffer + remaining + sz;
    if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
      *stdinDataEnd = 0;
  }
}

int rint()
{
  readAhead(16);

  int x = 0;
  bool neg = false;
  while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }

  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }

  return neg ? -x : x;
}
char rch()
{
  readAhead(16);
  while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
  char ans=*stdinPos;
  ++stdinPos;
  return ans;
}
long long rlong()
{
  readAhead(32);

  long long x = 0;
  bool neg = false;
  while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }

  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }

  return neg ? -x : x;
}