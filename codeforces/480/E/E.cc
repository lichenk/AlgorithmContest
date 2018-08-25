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
int rlim,clim,qlim;
const int mn=2004;
char str[mn];
bitset<mn> a[mn];
int lft[mn][mn];
int up[mn][mn];
int sq[mn][mn];
map<int,int,greater<int> > h;
void dec(int sqr) {
  auto it=h.find(sqr);
  if(it->snd==1) h.erase(it);
  else (it->snd)--;
}
void inc(int sqr) {
  h[sqr]++;
}
int dr[]={1,0,1};
int dc[]={0,1,1};
int gid=1;
int sid[mn][mn];
typedef pair<int,int> pii;
void f(int qr, int qc) {
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  pq.push(MP(qr+qc,qr));
  while(!pq.empty()) {
    auto tp=pq.top(); pq.pop();
    int r=tp.snd; int c=tp.fst-r;
    int osq=sq[r][c];
    if (a[r][c]) {
      lft[r][c]=lft[r][c-1]+1;
      up[r][c]=up[r-1][c]+1;
      sq[r][c]=min(sq[r-1][c-1]+1,min(lft[r][c],up[r][c]));
    }
    else {
      lft[r][c]=0; up[r][c]=0; sq[r][c]=0;
    }
    if (osq!=sq[r][c]) {
      //if (r<50)printf("gid:%d r:%d c:%d osq:%d sq:%d\n",gid,r,c,osq,sq[r][c]);
      dec(osq);
      inc(sq[r][c]);
      for (int k=0;k<3;k++) {
        int nr=r+dr[k],nc=c+dc[k];
        if (sid[nr][nc]!=gid) {
          sid[nr][nc]=gid;
          pq.push(MP(nr+nc,nr));
        }
      }
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  time_t st=clock();
  scanf("%d %d %d\n",&rlim,&clim,&qlim);
  for (int x=1;x<=rlim;x++) {
    scanf("%s\n",str);
    for (int y=1;y<=clim;y++) {
      a[x][y]=(str[y-1]=='.')?1:0;
    }
  }
  for (int r=1;r<=rlim;r++) for (int c=1;c<=clim;c++) {
    if (a[r][c]) {
      lft[r][c]=lft[r][c-1]+1;
      up[r][c]=up[r-1][c]+1;
      sq[r][c]=min(sq[r-1][c-1]+1,min(lft[r][c],up[r][c]));
    }
    else {
      lft[r][c]=0; up[r][c]=0; sq[r][c]=0;
    }
    inc(sq[r][c]);
  }
  for (int q=0;q<qlim;q++) {
    int qr,qc; scanf("%d %d",&qr,&qc);
    a[qr][qc]=0;
    f(qr,qc);
    int ans=h.begin()->fst;
    printf("%d\n",ans);
    ++gid;
  }
}
