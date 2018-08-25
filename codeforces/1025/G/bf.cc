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
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

typedef vector<ld> vd;
typedef vector<vd> vvd;
class MatrixInverse {
public:
  // square matrix
  // returns null if no inverse
  bool zero(ld x) {
    return fabs(x)<1e-9;
  }
  bool inv(vvd &M) { // Inverse is returned in M[0..n][n..2*n-1];
    int N = M.size();
    for (int i=0;i<N;i++) M[i].resize(2*N);
    for (int i = 0; i < N; i++) {
      M[i][i + N] = 1;
    }
    for (int r = 0; r < N; r++) {
      int k = r;
      while (zero(M[k][r])) {
        k++;
        if (k == N)
          return false; // no inverse
      }
      swap(M[r],M[k]);

      double lv = M[r][r];
      for (int j = 0; j < 2 * N; j++)
        M[r][j] /= lv;

      for (int i = 0; i < N; i++) {
        if (i != r) {
          lv = M[i][r];
          for (int j = 0; j < 2 * N; j++)
            M[i][j] -= lv * M[r][j];
        }
      }
    }
    return true;
  }
  vd solution(vvd &M, vd &inp) {//O(n^2)
    int n=M.size();
    vd sol(n);
    for (int r=0;r<n;r++) {
      for (int c=0;c<n;c++) {
        sol[r]+=M[r][c+n]*inp[c];
      }
    }
    return sol;
  }
};
vvd M;
int gn;
vi untrans2(int inp) {
  int n=gn;
  vi vans; vans.reserve(n);
  for (int x=0;x<n;x++) {
    vans.PB((inp%(n+1))-1);
    inp/=(n+1);
  }
  reverse(vans.begin(),vans.end());
  return vans;
}
vvi b;
int ffind(vi &inp) {
  int imin=0,imax=b.size();
  while(imin<imax) {
    int imid=(imin+imax)/2;
    if (b[imid]<inp) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
vi go(vi inp) {
  int n=gn;
  vi vans;
  for (int a=0;a<n;a++) {
    for (int b=0;b<n;b++) {
      if (a==b||inp[a]!=-1||inp[b]!=-1) continue;
      // A acquires B
      vi v=inp;
      v[b]=a;
      for (int x=0;x<n;x++) {
        if (v[x]==b) v[x]=-1;
      }
      vans.PB(ffind(v));
    }
  }
  return vans;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  /*int n=rint();
  vector<int> a(n);
  for (int i=0;i<n;i++) {
    int x=rint(); if (x!=-1) --x;
    a[i]=x;
  }*/
  int n; cin>>n;
  gn=n;
  {
    int zlim=1; for (int i=0;i<n;i++) zlim*=(n+1);
    for (int z=0;z<zlim;z++) {
    vi v=untrans2(z);
    bool ok=true;
    for (int x=0;x<n;x++) {
      if (v[x]!=-1&&v[v[x]]!=-1) ok=false;
    }
    if (ok) {
      b.PB(v);
    }
  }
  }
  int zlim=b.size();
  M.resize(zlim); for (int z=0;z<zlim;z++) M[z].resize(zlim);
  for (int z=0;z<zlim;z++) {
    vi ret=go(b[z]);
    M[z][z]+=1;
    ld C=-1.0L/ret.size();
    for (auto &dest:ret) {
      M[z][dest]+=C;
    }
  }
  MatrixInverse matinv;
  matinv.inv(M);
  vd vec(zlim); for (int i=0;i<zlim;i++) vec[i]=1;
  vd sol=matinv.solution(M,vec);
  printf("%f\n",(double)sol[0]);
  //exit(0);
  
  for (int z=0;z<zlim;z++) {
    {
      printf("res:%f ",(double)sol[z]);
      for (int x=0;x<n;x++) printf("%d ",b[z][x]);
      printf("\n");
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