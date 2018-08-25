#include <bits/stdc++.h>
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
const int MAXSZ=2e8;
char prealloc[MAXSZ];
int preidx=0;
void * galloc(size_t size) {
  //printf("size:%d\n",size);
  int oldidx=preidx;
  preidx+=size;
  return &prealloc[oldidx];
}

//#define MAXR 20000000004
//#define MAXC 20000000004
int MAXR=1,MAXC=1;
#include <assert.h>
#include <stddef.h>

inline int gcd2(int X, int Y) {
  return max(X,Y);
}

struct layer2_node {
  //layer2_node(int low, int high)
  //    : low(low), high(high), lft(NULL), rht(NULL), value(0LL) {
  //}
  int low;
  int high;
  layer2_node* lft;
  layer2_node* rht;
  int value;
};

layer2_node* l2n(int low, int high) {
  layer2_node* res=(layer2_node*)galloc(sizeof(layer2_node));
  res->low=low;
  res->high=high;
  res->lft=NULL;
  res->rht=NULL;
  res->value=0;
  printf("l2n:%lld\n",res);
  return res;
}

struct layer1_node {
  //layer1_node() : lft(NULL), rht(NULL), l2(0, MAXC) {
  //}

  layer1_node* lft;
  layer1_node* rht;
  layer2_node l2;
};

layer1_node* l1n() {
  layer1_node* res=(layer1_node*)galloc(sizeof(layer1_node));
  res->lft=NULL;
  res->rht=NULL;
  res->l2.low=0;
  res->l2.high=MAXC;
  printf("l1n:%lld\n",res);
  return res;
}



static layer1_node root;

static void update2(layer2_node* node, int Q, int K) {
  int low = node->low;
  int high = node->high;
  int mid = (low + high) / 2;
  if(low + 1 == high) {
    /* For leaf nodes we just update the value directly. */
    node->value = K;
    return;
  }

  layer2_node*& tgt = Q < mid ? node->lft : node->rht;
  if(tgt == NULL) {
    /* If there is no node on this side of the tree create a new leaf node
     * containing exactly our update point. */
    tgt = l2n(Q, Q + 1);
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
      mid = (low + high) / 2;
    } while((Q < mid) == (tgt->low < mid));

    layer2_node* nnode = l2n(low, high);
    (tgt->low < mid ? nnode->lft : nnode->rht) = tgt;
    tgt = nnode;

    update2(nnode, Q, K);
  }

  /* Internal nodes get updated as the gcd of its leaves. */
  node->value = gcd2(node->lft ? node->lft->value : 0,
                     node->rht ? node->rht->value : 0);
}

int query2(layer2_node* nd, int A, int B) {
  /* The same as the level 1 queries except the interval each node represents
   * may skip some levels of the tree so we store them in the node itself. */
  if(nd == NULL || B <= nd->low || nd->high <= A) {
    return 0;
  } else if(A <= nd->low && nd->high <= B) {
    return nd->value;
  }
  return gcd2(query2(nd->lft, A, B), query2(nd->rht, A, B));
}

static void update1(layer1_node* node, int low, int high,
                    int P, int Q, int K) {
  int mid = (low + high) / 2;

  if(low + 1 == high) {
    update2(&node->l2, Q, K);
  } else {
    layer1_node*& nnode = P < mid ? node->lft : node->rht;
    (P < mid ? high : low) = mid;
    if(nnode == NULL) {
      nnode = l1n();
    }
    update1(nnode, low, high, P, Q, K);

    /* Compute what value to update with. */
    K = gcd2(node->lft ? query2(&node->lft->l2, Q, Q + 1) : 0,
             node->rht ? query2(&node->rht->l2, Q, Q + 1) : 0);
    update2(&node->l2, Q, K);
  }
}

int query1(layer1_node* nd, int low, int high,
                 int A1, int A2) {
  /* Scan down the tree short-circuiting when we reach a node that contains
   * our entire query interval and combining the result of the level2 queries.
   */
  if(nd == NULL || high <= A1) {
    return 0;
  } else if(A1 <= low) {
    return query2(&nd->l2, A2, MAXC-1);
  }
  int mid = (low + high) / 2;
  return gcd2(query1(nd->lft, low, mid, A1, A2),
              query1(nd->rht, mid, high, A1, A2));
}

void init(int R, int C) {
}

void update(int P, int Q, int K) {
  update1(&root, 0, MAXR, P, Q, K);
}

int calculate(int P, int Q, int U, int V) {
  return query1(&root, 0, MAXR, P, Q);
}



const int mn=1e5+2;
bool cmp(const pll &a, const pll &b) {
  return a.fst+a.snd>b.fst+b.snd;
}

void makeunique(vector<ll> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
int bins(vector<ll> &vx, ll x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
pll vp[mn];
vector<ll> vx,vy;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  int a=rint(); rch(); int b=rint(); int c=rint(); rch(); int d=rint();
  ll det=1ll*a*d-1ll*b*c;
  vx.PB(0); vy.PB(0);
  vx.reserve(n); vy.reserve(n);
  for (int i=0;i<n;i++) {
    int x=rint(),y=rint();
    ll nx=1ll*-b*y+1ll*a*x;
    ll ny=1ll*d*y-1ll*c*x;
    if (det<0) {
      nx=-nx;ny=-ny;
    }
    vp[i]=MP(nx,ny);
    vx.PB(nx);
    vy.PB(ny);
  }
  sort(vp,vp+n,cmp);
  makeunique(vx); makeunique(vy);
  for (int i=0;i<n;i++) {
    ll x=vp[i].fst,y=vp[i].snd;
    vp[i].fst=bins(vx,x);
    vp[i].snd=bins(vy,y);
  }
  MAXR=vx.size();
  MAXC=vy.size();
  MAXR++;
  MAXC++;
  for (int i=0;i<n;i++) {
    int x=vp[i].fst,y=vp[i].snd;
    if (x<=0||y<=0) continue;
    int got1=calculate(x,y+1,MAXR-1,MAXC-1);
    int got2=calculate(x+1,y,MAXR-1,MAXC-1);
    int got=max(got1,got2)+1;
    update(x,y,got);
  }
  {
    int x=0,y=0;
    int got1=calculate(x,y+1,MAXR-1,MAXC-1);
    int got2=calculate(x+1,y,MAXR-1,MAXC-1);
    int got=max(got1,got2);
    printf("%d\n",got);
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