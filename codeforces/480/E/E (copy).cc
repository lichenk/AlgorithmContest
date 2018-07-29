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
void f(int r, int c) {
  f(r+1,c);
  f(r,c+1);
  f(r,c);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
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
    {
      int c=qc;
      for (int r=qr;r<=rlim;r++) {
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
          dec(osq);
          inc(sq[r][c]);
        }
      }
    }
    {
      int r=qr;
      for (int c=qc;c<=clim;c++) {
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
          dec(osq);
          inc(sq[r][c]);
        }
      }
    }
    {
      for (int r=qr,c=qc;r<=rlim&&c<=clim;r++,c++) {
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
          dec(osq);
          inc(sq[r][c]);
        }
      }
    }
    int ans=h.begin()->fst;
    printf("%d\n",ans);
  }
}

