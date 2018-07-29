#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=777777777;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
int good[4][4];
int a[20];
int b[20];
int n,m;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),m=rint();
  for (int x=1;x<=3;x++) {
  	for (int y=1;y<=3;y++) {
  		good[x][y]=rint();
  	}
  }
	int last=0;
	for (int i=0;i<m;i++) {
    ll ans=0;
		int pos=rint()-1,val=rint();
    a[pos]=val;
    int zlim=1;
    vector<int> v;
    for (int i=0;i<n;i++) if (a[i]==0) {v.PB(i); zlim*=3;}
    for (int zz=0;zz<zlim;zz++) {
      for (int i=0;i<n;i++) b[i]=a[i];
      int z=zz;
      for (auto &w:v) {
        b[w]=1+(z%3);
        z/=3;
      }
      int ok=1;
      //for (int i=0;i<n;i++) printf("%d ",b[i]);
      //printf("\n");
      for (int i=0;i<n-1;i++) {
        if (!good[b[i]][b[i+1]]) {
          //printf("i:%d b[i]:%d %d\n",i,b[i],b[i+1]);
          ok=0;break;
        }
      }
      /*if (ok) {
        for (int i=0;i<n;i++) printf("%d ",b[i]);
        printf("\n");
      }*/
      ans+=ok;
    }
    printf("%lld\n",ans%777777777);
	}

}




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