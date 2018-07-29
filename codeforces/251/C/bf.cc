#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define vendl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;

int rint();char rch();long long rlong();
const int mn=5e7+2;
//const int mn=10;
int klim;
void go(int *start, int a) {
  for (int i=0;i<mn;i++) start[i]=1e9;
  start[0]=0;
  for (ll x=a+1;x<a+mn;x++) {
    int ans=start[x-a-1];
    for (int k=2;k<=klim;k++) {
      int r=x%k;
      if (x-a-r>=0) {
        chkmin(ans,start[x-a-r]);
        //printf("x-r:%lld %lld\n",x-r,start[x-a-r]);
      }
    }
    ans++;
    //printf("x:%lld ans:%d\n",x,ans);
    start[x-a]=ans;
  }
}
int start[mn];
const int FIX=1e5;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //ll z=2;
  //for (ll x=3;x<=15;x++) {
  //  z=(z*x)/__gcd(z,x);
  //}
  //printf("%lld\n",z);
  //return 0;
  ll a,b;
  cin>>b>>a>>klim;
  go(start,a);
  ll final=start[b-a];
  printf("%lld\n",final);
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