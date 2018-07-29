
template<typename T, int _MAXSEG> class MaxSegTreeRemap {
public:
  static const int MAXSEG = _MAXSEG;  // limit for array size
  int segn=_MAXSEG;  // array size
  typedef p4 S;
  S vseg[2 * MAXSEG];
  S identity = {INF,-INF,INF,-INF};
  S combine(const S& a, const S& b) {
    return p4(
      min(a.xlo,b.xlo),
      max(a.xhi,b.xhi),
      min(a.ylo,b.ylo),
      max(a.yhi,b.yhi)
    );
  }
  RemapUnique<T> remap;
  void init(vector<pair<T,S> > inp) {
    vector<T> vt; for (auto &w: inp) vt.PB(w.fst);
    remap.init(vt);
    segn=remap.size()+4;
    fill(vseg+segn,vseg+segn+segn, identity);
    for (auto &w:inp) {
      int idx=segn+remap.GTE(w.fst);
      vseg[idx]=combine(vseg[idx],w.snd);
      //printf("idx:%d inpi:%d, %d\n",idx-segn,inp[i].fst,inp[i].snd);
    }
    build();
    //printf("eee\n");
  }
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) vseg[i] = combine(vseg[i<<1], vseg[i<<1|1]);
  }

  void sset(int _p, const S& value) { // set value at position p
    int p=remap.GTE(_p);
    int n=segn;
    for (vseg[p += n] = value; p >>= 1; ) vseg[p] = combine(vseg[p<<1], vseg[p<<1|1]);
  }

  S query(int _l, int _r) { // sum on interval [l, r]
    int l=remap.GTE(_l),r=remap.GTE(_r+1)-1+1;
    //printf("%d %d. %d %d\n",_l,_r,l,r);
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, vseg[l++]);
      if (r&1) resr = combine(vseg[--r], resr);
    }
    return combine(resl, resr);
  }
};
