int VMOD;
vector<int> VMODP;
void specialInit(int vmod) {
  VMOD=vmod;
  VMODP.clear();
  int slim=min(vmod-1,sqrt(vmod)+1);
  for (int x=2;x<=slim;x++) {
    if (vmod%x==0) {
      int ok=1;
      for (auto &w:VMODP) if (x%w) {ok=0; break;}
      if (ok) VMODP.PB(x);
    }
  }
}

struct SpecialInt {
  static const int VMODPSZ;
  unsigned x;
  int pe[9]; // Primorial(10)=6469693230> 2e9 limit
  SpecialInt(signed sig) {
    for (int i=0;i<VMODP.size();i++) {
      int p=VMODP[i]; int e=0;
      while(sig%p==0) {sig/=p; e++;}
      pe[i]=e;
    }
    x=sig;
  }
  int get() const {
    int ans=x;
    for (int i=0;i<VMODP.size();i++) {
      int p=VMODP[i]; int e=pe[i];
      for (int j=0;j<e;j++) ans=(ans*(ll)p)%VMOD;
    }
    return x;
  }
 
  SpecialInt &operator*=(SpecialInt that) {
    for (int i=0;i<VMODP.size();i++) pe[i]+=that.pe[i];
    x = ((unsigned long long)x * that.x) % VMOD;
    return *this;
  }
  SpecialInt &operator/=(SpecialInt that) { return *this *= that.inverse(); }

  SpecialInt &operator*=(int that) {this*=SpecialInt(that); return *this;}
  SpecialInt &operator/=(int that) {this/=SpecialInt(that); return *this;}

  SpecialInt operator*(SpecialInt that) const { return SpecialInt(*this) *= that; }
  SpecialInt operator/(SpecialInt that) const { return SpecialInt(*this) /= that; }

  SpecialInt operator*(int that) const { return SpecialInt(*this) *= that; }
  SpecialInt operator/(int that) const { return SpecialInt(*this) /= that; }


  SpecialInt inverse() const {
    for (int i=0;i<VMODP.size();i++) pe[i]=-pe[i];
    signed a = x, b = VMOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += Mod;
    SpecialInt res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(SpecialInt that) const { return x == that.x; }
  bool operator!=(SpecialInt that) const { return x != that.x; }
  SpecialInt operator-() const { SpecialInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
SpecialInt operator^(SpecialInt a, unsigned long long k) {
  SpecialInt<VMOD> r(1);
  while(k) {
    if(k & 1) r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}