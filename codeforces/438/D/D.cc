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

  typedef struct STTV {
    int hi,hi2;ll sum;
  } STV;
class SegmentTreeBeats {
public:
  static const int MAXSEG=100000;
  typedef int STD;
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Max operations. Operations like Add/Sum, Set/Max can also be implemented.
  inline STD getNeutralDelta() {
    return 0;
  }
  inline STV modifyOperation(const STV &x, const STD &y, int len) {
  	// We are assured that y!=neutralDelta
  	assert(y!=getNeutralDelta());
  	assert(hi==hi2);
  	assert(hi>=y);
  	int newhi=hi%y;
  	ll newsum=sum-(len*(ll)(hi-newhi));
    return {newhi,newhi,newsum};
  }

  // query (or combine) operation
  STV queryOperation(STV x, STV y) {
    int tmp[4];
    sort(tmp,tmp+4);int hi=tmp[3];
    int hi2=hi;
    for (int i=2;i>=0;i--) {
      int tmpi=tmp[i];
      if (tmpi<hi) {
        hi2=tmpi; break;
      }
    }
    return {hi,hi2,x.sum+y.sum};
  }

  int joinDeltas(const STD &delta1, const STD &delta2) {
    if (delta1 == getNeutralDelta()) return delta2;
    if (delta2 == getNeutralDelta()) return delta1;
    return delta1||delta2;
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    // Here you must write a fast equivalent of following slow code:
    // int result = delta;
    // for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
    // return result;
    return delta;
  }

  bool break_condition(int queryleft, int queryright, STD delta, int root, int nodeleft, int noderight) {
    return (nodeleft>queryright||noderight<queryleft||vvalue[root].hi<delta);
  }

  bool tag_condition(int queryleft, int queryright, STD delta, int root, int nodeleft, int noderight) {
    return (nodeleft==noderight);
  }

  // generic code
  int n;
  STV vvalue[4*MAXSEG];
  STD vdelta[4*MAXSEG]; // vdelta[i] affects vvalue[i], vdelta[2*i+1] and vdelta[2*i+2]

  STV joinValueWithDelta(STV value, STD delta, int len) {
    if (delta == getNeutralDelta()) return value;
    return modifyOperation(value, delta, len);
  }

  void pushDelta(int root, int left, int right) {
    vvalue[root] = joinValueWithDelta(vvalue[root], deltaEffectOnSegment(vdelta[root], right - left + 1), right - left + 1);
    vdelta[2 * root + 1] = joinDeltas(vdelta[2 * root + 1], vdelta[root]);
    vdelta[2 * root + 2] = joinDeltas(vdelta[2 * root + 2], vdelta[root]);
    vdelta[root] = getNeutralDelta();
  }

  void build(int _n, const vector<STV> &vinit) {
    n = _n;
    _build(0, 0, n - 1, vinit);
  }

  void _build(int root, int left, int right, const vector<STV> &vinit) {
    if (left == right) {
      vvalue[root] = vinit[left];
      vdelta[root] = getNeutralDelta();
      return;
    } else {
      int mid = (left + right) >> 1;
      _build(2 * root + 1, left, mid, vinit);
      _build(2 * root + 2, mid + 1, right, vinit);
      vvalue[root] = queryOperation(vvalue[2 * root + 1], vvalue[2 * root + 2]);
      vdelta[root] = getNeutralDelta();
    }
  }

  STV query(int from, int to) {
    return _query(from, to, 0, 0, n - 1);
  }

  STV _query(int from, int to, int root, int left, int right) {
    if (from == left && to == right) {
      return joinValueWithDelta(vvalue[root], deltaEffectOnSegment(vdelta[root], right - left + 1), , right - left + 1);
    }
    pushDelta(root, left, right);
    int mid = (left + right) >> 1;
    if (from <= mid && to > mid)
      return queryOperation(
          _query(from, min(to, mid), root * 2 + 1, left, mid),
          _query(max(from, mid + 1), to, root * 2 + 2, mid + 1, right));
    else if (from <= mid)
      return _query(from, min(to, mid), root * 2 + 1, left, mid);
    else if (to > mid)
      return _query(max(from, mid + 1), to, root * 2 + 2, mid + 1, right);
    else
      assert(0);
  }

  void modify(int from, int to, int delta) {
    _modify(from, to, delta, 0, 0, n - 1);
  }

  void _modify(int queryleft, int queryright, STD delta, int root, int nodeleft, int noderight) {
    if (break_condition(queryleft, queryright, delta, root, nodeleft, noderight)) {
      return;
    }
    if (nodeleft==noderight) {
      vvalue[root] = joinValueWithDelta(vvalue[root], delta, 1);
      return;
    }
    if (tag_condition(queryleft, queryright, delta, root, nodeleft, noderight)) {
      vdelta[root] = joinDeltas(vdelta[root], delta);
      return;
    }
    pushDelta(root, nodeleft, noderight);
    int mid = (nodeleft + noderight) >> 1;
    _modify(queryleft, min(queryright, mid), delta, 2 * root + 1, nodeleft, mid);
    _modify(max(queryleft, mid + 1), queryright, delta, 2 * root + 2, mid + 1, noderight);
    vvalue[root] = queryOperation(
        joinValueWithDelta(vvalue[2 * root + 1], deltaEffectOnSegment(vdelta[2 * root + 1], mid - nodeleft + 1), mid - nodeleft + 1),
        joinValueWithDelta(vvalue[2 * root + 2], deltaEffectOnSegment(vdelta[2 * root + 2], noderight - mid), noderight - mid)
    );
  }
};

SegmentTreeBeats st;

int main()
{
  //ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  vector<STV> vinit(n);
  for (int i=0;i<n;i++) {
    int x=rint();
    vinit[i]={x,x,x};
  }
  st.build(n,vinit);
  for (int i=0;i<m;i++) {
    char tp=rch();
    if (tp=='1') {
    	int l=rint()-1,r=rint()-1;
      ll res=st.query(l,r).val;
      printf("%lld\n",res);
    }
    else if (tp=='2'){
    	int l=rint()-1,r=rint()-1,x=rint();
    	st.modify(l,r,x);
    }
    else {
    	int k=rint(),x=rint();

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