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
const int MAXSZ=2.2e8;
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  preidx+=(((int)size) + 7) & ~0x07;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}
//#define MAXR 20000000004
//#define MAXC 20000000004
const int mn=1e5+4;
//const int mn=12;
const int MAXR=mn,MAXC=mn;
#include <assert.h>
#include <stddef.h>

inline ll gcd2(ll X, ll Y) {
  return X+Y;
}

struct layer2_node {
  layer2_node(int low, int high)
      : low(low), high(high), lft(NULL), rht(NULL), value(0LL) {
  }

  int low;
  int high;
  layer2_node* lft;
  layer2_node* rht;
  ll value;
};

struct layer1_node {
  layer1_node() : lft(NULL), rht(NULL), l2(0, MAXC) {
  }

  layer1_node* lft;
  layer1_node* rht;
  layer2_node l2;
};

static void update2(layer2_node* node, int Q, ll K) {
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
      mid = (low + high) / 2;
    } while((Q < mid) == (tgt->low < mid));

    layer2_node* nnode = new layer2_node(low, high);
    (tgt->low < mid ? nnode->lft : nnode->rht) = tgt;
    tgt = nnode;

    update2(nnode, Q, K);
  }

  /* Internal nodes get updated as the gcd of its leaves. */
  node->value = gcd2(node->lft ? node->lft->value : 0,
                     node->rht ? node->rht->value : 0);
}

ll query2(layer2_node* nd, int A, int B) {
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
                    int P, int Q, ll K) {
  int mid = (low + high) / 2;

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
    K = gcd2(node->lft ? query2(&node->lft->l2, Q, Q + 1) : 0,
             node->rht ? query2(&node->rht->l2, Q, Q + 1) : 0);
    update2(&node->l2, Q, K);
  }
}

ll query1(layer1_node* nd, int low, int high,
                 int A1, int B1, int A2, int B2) {
  /* Scan down the tree short-circuiting when we reach a node that contains
   * our entire query interval and combining the result of the level2 queries.
   */
  if(nd == NULL || B1 <= low || high <= A1) {
    return 0;
  } else if(A1 <= low && high <= B1) {
    return query2(&nd->l2, A2, B2);
  }
  int mid = (low + high) / 2;
  return gcd2(query1(nd->lft, low, mid, A1, B1, A2, B2),
              query1(nd->rht, mid, high, A1, B1, A2, B2));
}

void init(int R, int C) {
}
layer1_node root1,root2;
void update(layer1_node &root, int P, int Q, ll K) {
  //if (&root==&root2) printf("P:%d Q:%d K:%lld\n",P,Q,K);
  update1(&root, 0, MAXR, P, Q, K);
}

ll calculate(layer1_node &root, int P, int Q, int U, int V) {
  return query1(&root, 0, MAXR, P, U + 1, Q, V + 1);
}
/*ll bf[12][12];
void test() {
  for (int k=0;k<2;k++) {
  layer1_node root;
  memset(bf,0,sizeof bf);
  int n=10;
  for (int k=0;k<100000;k++) {
    int x=rand()%n,y=rand()%n;
    ll val=rand()+1e10;
    update(root,x,y,val);
    bf[x][y]=val;
    int xl=rand()%n,xh=rand()%n; if (xl>xh) swap(xl,xh);
    int yl=rand()%n,yh=rand()%n; if (yl>yh) swap(yl,yh);
    ll bfans=0;
    for (int x=xl;x<=xh;x++) for (int y=yl;y<=yh;y++) bfans+=bf[x][y];
    ll smans=calculate(root,xl,yl,xh,yh);
    printf("x:%d y:%d xl:%d xh:%d yl:%d rh:%d bfans:%lld smans:%lld\n",x,y,xl,xh,yl,yh,bfans,smans);
    assert(bfans==smans);
  }
  }
}*/

int a[mn];
set<int> shape2pos[mn];
int vl[mn],vr[mn];
int tmp[mn];
const int vinf=mn-1;
void rm(int pos, int oldshape) {
  //printf("rm\n");
  int l=vl[pos],r=vr[pos];
  update(root1,pos,r,0);
  update(root2,pos,l,0);
  if (r<vinf) {
    vl[r]=l;
    update(root2,r,pos,0);
    update(root2,r,l,r);
  }
  if (l>0) {
    vr[l]=r;
    update(root1,l,pos,0);
    update(root1,l,r,l);
  }
  shape2pos[oldshape].erase(pos);
}

void ins(int pos, int newshape) {
  //printf("ins\n");
  std::pair<std::set<int>::iterator,bool> ret=shape2pos[newshape].insert(pos);
  auto it=ret.fst;
  int l=0,r=vinf;
  if (it!=shape2pos[newshape].begin()) {
    --it; l=*it; r=vr[l];
  }
  else {
    ++it;
    if (it!=shape2pos[newshape].end()) {
      r=*it;
    }
  }
  vl[pos]=l; vr[pos]=r;
  if (l>0) {
    update(root1,l,vr[l],0);
    update(root1,l,pos,l);
    vr[l]=pos;
  }
  if (r<vinf) {
    update(root2,r,vl[r],0);
    update(root2,r,pos,r);
    vl[r]=pos;
  }
  update(root1,pos,r,pos);
  update(root2,pos,l,pos);
}


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //test(); return 0;
  int n=rint(),m=rint();
  for (int x=1;x<=n;x++) a[x]=rint();
  for (int x=1;x<=n;x++) {
    shape2pos[a[x]].insert(x);
  }
  for (int x=n;x>=1;x--) {
    int val=a[x];
    int h=vinf;
    if (tmp[val]!=0) {
      h=tmp[val];
      vl[h]=x;
    }
    vr[x]=h;
    tmp[val]=x;
  }
  for (int x=1;x<=n;x++) {
    update(root1,x,vr[x],x);
    update(root2,x,vl[x],x);
  }
  for (int qi=0;qi<m;qi++) {
    int t=rint();
    if (t==1) {
      int pos=rint(),newshape=rint();
      //printf("pos:%d newshape:%d\n",pos,newshape);
      int oldshape=a[pos];
      if (oldshape!=newshape) {
        a[pos]=newshape;
        rm(pos, oldshape);
        ins(pos,newshape);
      }
    }
    else {
      int l=rint(),r=rint();
      ll ans1=calculate(root1,l,r+1,r,vinf);
      ll ans2=calculate(root2,l,0,r,l-1);
      //printf("l:%d r:%d ans:%lld-%lld\n",l,r,ans1,ans2);
      printf("%lld\n",ans1-ans2);
    }
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