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
typedef pll point;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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


// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(point p, point q, point r)
{
    if (q.fst <= max(p.fst, r.fst) && q.fst >= min(p.fst, r.fst) &&
        q.snd <= max(p.snd, r.snd) && q.snd >= min(p.snd, r.snd))
       return true;
 
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(point p, point q, point r)
{
    // See http://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.snd - p.snd) * (r.fst - q.fst) -
              (q.fst - p.fst) * (r.snd - q.snd);
 
    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(point p1, point q1, point p2, point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}

long long ccw(point a, point b, point c) {
  b.first -= a.first; b.second -= a.second;
  c.first -= a.first; c.second -= a.second;
  return b.first * (long long)c.second - c.first * (long long)b.second;
}


const int mn=404;
int dp[mn][mn];
point vp[mn];
bool ok[mn][mn];
int n;
int norm(int x) {
  return (x+n)%n;
}

int f(int l, int r) {
  int dpval=dp[l][r];
  if (dpval!=-1) return dpval;
  int len=r-l+1;
  ll ans=0;
  if (len==3) ans=1;
  else if (len<3) ans=0;
  else {
    for (int x=l;x<=r;x++) {
      int L=norm(x+1),R=norm(x-1);
      if (ok[L][R]) {
        if (L>R) R+=n;
        ans+=f(L,R);
      }
    }
  }
  return dp[l][r]=(int)(ans%MOD);
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=readInt();
  for (int i=0;i<n;i++) {
    int x=readInt(),y=readInt();
    vp[i]=MP(x,y);
  }
  if (ccw(vp[0],vp[1],vp[2])<0) reverse(vp,vp+n);
  for (int i=0;i<n;i++) vp[n+i]=vp[i];
  for (int i=0;i<n;i++) {
    if (ccw(vp[i],vp[i+1],vp[i+2])==0) {
      printf("0\n");
      return 0;
    }
  }
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
    if (x==y) continue;
    ok[x][y]=1;
    for (int z=0;z<n;z++) {
      if (doIntersect(vp[x],vp[y],vp[z],vp[z+1])) {
        ok[x][y]=0;
        break;
      }
    }
  }
  for (int x=0;x<2*n;x++) for (int y=0;y<2*n;y++) {
    ok[x][y]=ok[x%n][y%n];
  }
  memset(dp,-1,sizeof dp);
  ll final=f(0,n-1);
  printf("%lld\n",final);
}

