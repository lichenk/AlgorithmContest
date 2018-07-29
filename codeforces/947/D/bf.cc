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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();


string gtarg;
string g2ns[3]={"BC","AC","AB"};
bool bf(string src, int depth) {
  if (src==gtarg) {return true;}
  if (depth<0) return false;
  int n=src.length();
  for (int pos=0;pos+2<n;pos++) {
    if (src.substr(pos,3)=="AAA") {
      string res=src.substr(0,pos)+src.substr(pos+3,n-pos-3);
      if(bf(res,depth-1)) {
        //printf("res:%s\n",res.c_str());
        return true;
      }
    }
  }
  for (int pos=0;pos+1<n;pos++) {
    if (src[pos]=='A'&&src[pos+1]!='A') {
      string res=src.substr(0,pos)+src.substr(pos+1,n-pos-1);
      if(bf(res,depth-1)) {
        //printf("res:%s\n",res.c_str());
        return true;
      }
    }
  }
  for (int pos=0;pos<n;pos++) {
    char got=src[pos];
    string ns=g2ns[got-'A'];
    string res=src.substr(0,pos)+ns+src.substr(pos+1,n-pos-1);
    if (bf(res,depth-1)) {
      //printf("res:%s\n",res.c_str());
      return true;
    }
  }
  return false;
}

bool go(string src, string targ) {
  //printf("%s %s\n",src.c_str(),targ.c_str());
  gtarg=targ;
  return bf(src,8);
}

string s[2];
vi vbc[2],va[2];
int solve() {
  int l[2],r[2];
  for (int k=0;k<2;k++) {cin>>l[k]>>r[k]; l[k]--; r[k]--;}
  int k=0;
  string src=s[k].substr(l[k],r[k]-l[k]+1);
  k=1;
  string targ=s[k].substr(l[k],r[k]-l[k]+1);
  return go(src,targ);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int k=0;k<2;k++) {
    cin>>s[k];
  }
  int q; cin>>q;
  for (int i=0;i<q;i++) {
    int ans=solve();
    printf("%d",ans);
  }
  printf("\n");
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