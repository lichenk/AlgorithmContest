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
const int mn=100005;
int n;
int a[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=readInt();
  for (int i=1;i<=n;i++) a[i]=readInt();
  int q=readInt();
  int lastans=0;
  for (int i=0;i<q;i++) {
    int t=readInt(),lp=readInt(),rp=readInt();
    int l=((lp+lastans-1)%n)+1;
    int r=((rp+lastans-1)%n)+1;
    if (l>r) swap(l,r); 
    if (t==1) {
      int ar=a[r];
      for (int x=r;x>=l+1;x--) {
        a[x]=a[x-1];
      }
      a[l]=ar;
      //for (int x=1;x<=n;x++) printf("%d ",a[x]);
      //printf("endq\n");
    }
    else {
      int kp=readInt();
      int k=((kp+lastans-1)%n)+1;
      //printf("l:%d r:%d k:%d\n",l,r,k);
      int ans=0;
      for (int x=l;x<=r;x++) if(a[x]==k) ans++;
      lastans=ans;
      printf("%d\n",ans);
    }
    //for (int x=1;x<=n;x++) printf("%d ",a[x]);
    //printf("\n");
  }
}

