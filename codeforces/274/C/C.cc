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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
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

int rint()
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
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
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

typedef std::complex<ld> point;

point bary(point A, point B, point C, ld a, ld b, ld c) {
    return (A*a + B*b + C*c) / (a + b + c);
}

point circumcenter(point A, point B, point C) {
    // intersection of perpendicular bisectors
    ld a = norm(B - C), b = norm(C - A), c = norm(A - B);
    return bary(A, B, C, a*(b+c-a), b*(c+a-b), c*(a+b-c));
}
ld cross(point a, point b) {
  return (conj(a) * b).imag();
}
ld cross3(point a, point b, point c) {
  return cross(a-b,b-c);
}
ld dist(point a, point b) {
  return abs(a - b);
}
const ld EPS=1e-9;
bool inside(point a, point b, point c, point g) {
  if (cross3(g,a,b)<EPS&&cross3(g,b,c)<EPS&&cross3(g,c,a)<EPS) return true;
  if (cross3(g,b,a)<EPS&&cross3(g,c,b)<EPS&&cross3(g,a,c)<EPS) return true;
  return false;
}
void printpt(point a) {
  printf("(%f, %f), ",(double)a.real(),(double)a.imag());
}
const int mn=102;
point p[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
  for (int i=0;i<n;i++) {
    ld x,y; cin>>x>>y;
    p[i]=point(x,y);
    //printpt(p[i]); printf("\n");
  }
  ld final=-2;
  for (int a=0;a<n;a++) {
    for (int b=0;b<a;b++) {
      for (int c=0;c<b;c++) {
        point A=p[a],B=p[b],C=p[c];
        ld cr=cross3(A,B,C);
        if (-EPS<cr&&cr<EPS) continue;
        point center=circumcenter(A,B,C);
        //printpt(A);printpt(B);printpt(C);printpt(center); printf("\n");
        if (inside(A,B,C,center)) {
        ld best=1e9;
        for (int x=0;x<n;x++) {
          ld got=dist(p[x],center);
          chkmin(best,got);
        }
        chkmax(final,best);}
        /*if (inside(A,B,C,center)) {
          ld d=dist(A,center);
          chkmax(final,d);
        }*/
      }
    }
  }
  if (final<-1) {
    printf("-1\n");
    return 0;
  }
  printf("%.9f\n",(double)final);
}

