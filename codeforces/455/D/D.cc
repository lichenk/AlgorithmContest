#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
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

int readInt()
{
    readAhead(128);

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


template <typename T, typename U>
pair<T,U> operator+ (const pair<T,U> & a, pair<T,U> & b) {
  return make_pair (a.first+b.first, a.second+b.second);
}

template <typename T, typename U>
pair<T,U> operator- (const pair<T,U> & a, pair<T,U> & b) {
  return make_pair (a.first-b.first, a.second-b.second);
}

template <typename T, typename U>
pair<T,U> operator* (const int & a, pair<T,U> & b) {
  return make_pair (a*b.first, a*b.second);
}
int randarray[2*100000];
int randcnt=-1;
unsigned int gseed;
int gid=0;
template <typename T> 
class treapset {
private:

  int next_priority() {
    return randarray[gid++];
  }

  void regenerate_priorities () {
    assert(0);
  }

  struct item;
  typedef struct item * pitem;

  bool _is_sorted = true, stop;
  pitem root = NULL, _begin = NULL;
  T erased;

  struct item {
    int prior;
    int cnt, rev;
    T key;
    pitem l, r;
  };

struct item _prealloc[2*100000];
int _allocid=0;
pitem alloc() {
  return &(_prealloc[_allocid++]);
}

  int cnt (pitem it) {
    return it ? it->cnt : 0;
  }

  void upd_cnt (pitem it) {
    if (it)
      it->cnt = cnt(it->l) + cnt(it->r) + 1;
  }

  void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r) 
      t = l ? l : r;
    else if (l->prior > r->prior)
      merge (l->r, l->r, r),  t = l;
    else
      merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
  }

  void split (pitem t, pitem & l, pitem & r, int index) { // split at position
    if (!t)
      return void( l = r = 0 );
    if (index <= cnt(t->l))
      split (t->l, l, t->l, index),  r = t;
    else
      split (t->r, t->r, r, index - 1 - cnt(t->l)),  l = t;
    upd_cnt (t);
  }

  void splitK (pitem t, pitem & l, pitem & r, T & key, bool & eq) { // split by key
    if (!t)
      return void( l = r = 0 );
    if (key == t->key) {
      eq =true;
      return;
    }
    if (key < t->key) {
      splitK (t->l, l, t->l, key, eq);
      if (!eq) r = t;
    }
    else {
      splitK (t->r, t->r, r, key, eq);
      if (!eq) l = t;
    }
    if(!eq) upd_cnt (t);
  }

  void insert (pitem & t, pitem it, int index) { // insert at position
    if (!t) 
      t = it;
    else if (it->prior > t->prior)
      split (t, it->l, it->r, index),  t = it;
    else if (index <= cnt(t->l))
      insert (t->l, it, index);
    else
      insert (t->r, it, index - cnt(t->l) - 1 );
    if (stop) return;
    upd_cnt (t);
  }

  void insertK (pitem & t, pitem it, bool & eq) { // insert by key
    if (!t)
      t = it;
    else if (it->key == t->key) {
      eq =true; 
      return;
    }
    else if (it->prior > t->prior) {
      splitK (t, it->l, it->r, it->key, eq);
      if (!eq) t = it;
    }
    else if (it->key < t->key)
      insertK (t->l, it, eq);
    else
      insertK (t->r, it, eq);
    if (stop) return;
    if (!eq) upd_cnt (t);
  }

  void erase (pitem & t, int index) {
    if (cnt(t->l) == index) 
      {erased=t->key; merge (t, t->l, t->r);}
    else if (index < cnt(t->l))
      erase (t->l, index);
    else
      erase (t->r, index - cnt(t->l) - 1 );
    upd_cnt (t);
  }

  void eraseK (pitem & t, T key, bool & found) {
    if (key == t->key) {
      merge (t, t->l, t->r);
      found = true;
    }
    else if (key < t->key)
      eraseK (t->l, key, found);
    else
      eraseK (t->r, key, found);
    upd_cnt (t);
  }

  T get (pitem t, int index) {
    if (index < cnt(t->l))
      return get (t->l, index);
    else if (index > cnt(t->l))
      return get (t->r, index - cnt(t->l) - 1);
    return t->key;
  }

  int find (pitem t, T key) {
    if (!t || key == t->key)
      return cnt (t->l);
    if (key < t->key)
      return get (t->l, key);
    else 
      return get (t->r, key) + 1 + cnt (t->l);
  }

public:

  int size () {return cnt(root);}
  bool insert (T x) {
    if (!_is_sorted) return false;
    bool eq = false;
    pitem it = alloc();
    {
      it->key = x;
      it->cnt = 1;
      it->rev = 0;
      it->l = it->r = NULL; 
      it->prior = next_priority();
    }
    stop = false;
    insertK (root, it, eq);
    while (stop) {
      stop = false;
      eq = false;
      insertK (root, it, eq);
    }
    return !eq;
  }

  void insert_pos (int pos, T x) {
    if (pos > size()) return;
    pitem it = alloc();
    {
      it->key = x;
      it->cnt = 1;
      it->rev = 0;
      it->l = it->r = NULL; 
      it->prior = next_priority();
    }
    stop = false;
    insert (root, it, pos);
    while (stop) {
      stop = false;
      insert (root, it, pos);
    }
    if (pos > 0 && _is_sorted) {
      if (get (root, pos-1) >= get (root, pos)) _is_sorted = false;
    }
    if (pos < size()-1 && _is_sorted) {
      if (get (root, pos) >= get (root, pos+1)) _is_sorted = false;
    }
  }

  bool erase (T x) {
    if (!_is_sorted) return false;
    bool found = false;
    eraseK (root, x, found);
    return found;
  }

  T erase_pos (int pos) {
    erase (root, pos);
    return erased;
  }

  T operator[] (int index) {
    return get (root, index);
  }
};


const int mn=100000;
int n;
int t[2 * mn];

int a[mn];
const int mg=317+1;
int sqrt_lidx[mg],sqrt_ridx[mg];
int sqrt_g[mn],sqrt_s[mn];
int h[mg][mn+1];
treapset<int> ts;
int gete(int p) {
  return a[ts[p]];
}
void sqrt_build() {
  int slim=round(sqrt(n));
  int glim=(n+slim-1)/slim;
  int rem=n-(glim-1)*slim;
  int idx=0;
  for (int g=0;g<glim;g++) {
    sqrt_lidx[g]=idx;
    int lim=(g==glim-1)?rem:slim;
    for (int s=0;s<lim;s++) {
      sqrt_g[idx]=g;
      sqrt_s[idx]=s;
      h[g][a[idx]]++;
      //printf("g:%d s:%d idx:%d a:%d\n",g,s,idx,a[idx]);
      idx++;
    }
    sqrt_ridx[g]=idx-1;
  }
}
void sqrt_modify(int l, int r) {
  int lg=sqrt_g[l],rg=sqrt_g[r];
  int re=gete(r);
  if (lg<rg) {
    h[rg][re]--;
    h[lg][re]++;
    for (int g=lg;g<rg;g++) {
      int idx=sqrt_ridx[g];
      int e=gete(idx);
      //printf("Modify g:%d e:%d\n",g,e);
      h[g][e]--;
      h[g+1][e]++;
    }
  }
}
int naive_query(int l, int r, int val) {
  int ans=0;
  for (int idx=l;idx<=r;idx++) {
    if (gete(idx)==val) ans++;
  }
  return ans;
}
int sqrt_query(int l, int r, int val) {
  int lg=sqrt_g[l],rg=sqrt_g[r];
  if (lg==rg) {
    return naive_query(l,r,val);
  }
  else {
    int ans=naive_query(l,sqrt_ridx[lg],val)+naive_query(sqrt_lidx[rg],r,val);
    //printf("naive:%d->%d:%d %d->%d:%d\n",l,sqrt_ridx[lg],naive_query(l,sqrt_ridx[lg],val),
    //  sqrt_lidx[rg],r,naive_query(sqrt_lidx[rg],r,val)
    //  );
    for (int g=lg+1;g<rg;g++) {
      ans+=h[g][val];
      //printf("Got g:%d ans:%d\n",g,queryh(g,val));
    }
    return ans;
  }
}


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=readInt();
  for (int i=0;i<2*n;i++) randarray[i]=i;
  random_shuffle(randarray,randarray+2*n);
  for (int i=0;i<n;i++) {
    a[i]=readInt();
  }
  //time_t start=clock();
  for (int i=0;i<n;i++) ts.insert(i);
  //time_t end=clock();
  //fprintf(stderr,"%.9f\n",(double)(end-start)/(double)CLOCKS_PER_SEC);
  sqrt_build();
  int q=readInt();
  int lastans=0;
  for (int i=0;i<q;i++) {
    int t=readInt(),lp=readInt(),rp=readInt();
    int l=lp+lastans-1; if (l>=n) l-=n;
    int r=rp+lastans-1; if (r>=n) r-=n;
    if (l>r) swap(l,r); 
    if (t==1) {
      sqrt_modify(l,r);
      int re=ts.erase_pos(r);
      ts.insert_pos(l,re);
    }
    else {
      int kp=readInt();
      int k=kp+lastans-1; if (k>=n) k-=n;
      k++;
      //printf("l:%d r:%d k:%d\n",l,r,k);
      lastans=sqrt_query(l,r,k);
      //lastans=naive_query(l,r,k); //printf("\nNAIVE\n");
      printf("%d\n",lastans);
    }
  }
}