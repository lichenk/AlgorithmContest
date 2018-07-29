#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "bits/stdc++.h"
#include <assert.h>
using namespace __gnu_pbds;
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


const int MAXSZ=220*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  //preidx+=(((int)size) + 3) & ~0x03;
  preidx+=(((int)size) + 7) & ~0x07;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}


typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int mn=100001;
const int R=pow(mn/log(mn),1.0/3.0)/4;
//const int R=1;

typedef struct _tri
{
  struct _tri *children[26];
  ordered_set *s;
} tri;

/*tri *getNode()
{
  tri *root = new tri;
  memset(root->children,0,sizeof (root->children));
  return root;
}*/

ordered_set *qi2set[mn];

// Trie add string
void addstr(tri *root, const char *str, int len, int qi) {
  for (int depth = 0; depth < len; depth++)
  {
    int index = str[depth]-'a';
    if (!root->children[index]) {
      root->children[index] = new tri;
    }
    root = root->children[index];
  }
  if (root->s==NULL) root->s=new ordered_set;
  qi2set[qi]=root->s;
}


void ins(tri *root, const char *str, int len, int lidx) {
  for (int depth = 0; depth < len; depth++)
  {
    int index = str[depth]-'a';
    root = root->children[index];
    if (root==NULL) return;
    if (root->s) root->s->insert(lidx);
  }
}


void rm(tri *root, const char *str, int len, int lidx) {
  for (int depth = 0; depth < len; depth++)
  {
    int index = str[depth]-'a';
    root=root->children[index];
    if (root==NULL) return;
    if (root->s) root->s->erase(lidx);
  }
}

void modify(tri *root, const char *str, int len, int lidx, int cdepth, char newc) {
  for (int depth = 0; depth < cdepth; depth++)
  {
    int index = str[depth]-'a';
    root = root->children[index];
    if (root==NULL) return;
  }
  rm(root, str+cdepth, len-cdepth, lidx);
  int index = newc-'a';
  root = root->children[index];
  if (root==NULL) return;
  if (root->s) root->s->insert(lidx);
  assert(len-cdepth-1>=0);
  ins(root, str+cdepth+1, len-cdepth-1, lidx);
}

int query(ordered_set *s, int qlen, int l, int r) {
  int ansl=s->order_of_key(l);
  int ansr=s->order_of_key(r-qlen+2);
  return ansr-ansl;
}

/* KMP from UBC2012 bookcode */
// t is the string to search in, p is the substring to search for
int fail[mn];
void kmp_init(const char *p, const int plen) {
  for (int i=0, j=-1, m=plen; ; ++i, ++j) {
    fail[i] = j; if (i == m) return;
    while (j>=0 && p[i]!=p[j]) j = fail[j];
} } // fail[i] = len of longest proper suffix that's also a prefix in s[0...i-1]
int kmp_match(const char *t, const int tlen, const char *p, const int plen) {
  int n=tlen,m=plen;
  kmp_init(p,m);
  int matches=0;
  for (int i=0, j=0; ; ++i, ++j) {
    if (j == m) matches++, j = fail[j];
    if (i == n) return matches;
    while (j>=0 && t[i]!=p[j]) j = fail[j]; }
  return matches;
}
/* End KMP from UBC2012 bookcode */

char str[mn];
char modstr[mn];
char qs[mn];
tri _root;
tri *root=&_root;

char vt[mn];
char *vqstr[mn];
int vl[mn],vr[mn];
int vqlen[mn];
int vans[mn];

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%s\n",str); int slen=strlen(str);
  int qlim; scanf("%d\n",&qlim);
  int queries=0;
  bool hasq=0;
  int qlo=0;
  for (int qi=0;qi<qlim;qi++) {
    char t; scanf("%c ",&t); vt[qi]=t;
    if (t=='1') {
      int p; char c; scanf("%d %c\n",&p,&c); --p;
      vl[qi]=p; vr[qi]=c;
      if (!hasq) {
        str[p]=c;
        ++qlo;
      }
    }
    else {
      queries++;
      hasq=1;
      int l,r; scanf("%d %d %s\n",&l,&r,qs); --l; --r;
      vl[qi]=l; vr[qi]=r;
      int qlen=strlen(qs);
      vqlen[qi]=qlen;
      vqstr[qi]=new char[qlen];
      memcpy(vqstr[qi],qs,qlen);
    }
  }
  if ((queries<=2e4)) {
    for (int qi=qlo;qi<qlim;qi++) {
      char t=vt[qi];
      if (t=='1') {
        int p=vl[qi]; char c=vr[qi];
        str[p]=c;
      }
      else {
        int l=vl[qi],r=vr[qi],qlen=vqlen[qi];
        int ans=kmp_match(str+l,r-l+1,vqstr[qi],qlen);
        printf("%d\n",ans);
      }
    }
    return 0;
  }
  memcpy(modstr,str,slen);
  for (int qi=qlo;qi<qlim;qi++) {
    char t=vt[qi];
    if (t=='1') {
      int p=vl[qi]; char c=vr[qi];
      modstr[p]=c;
    }
    else {
      int l=vl[qi]; int r=vr[qi];
      int qlen=vqlen[qi];
      if (qlen<=R) {
        addstr(root,vqstr[qi],qlen,qi);
      }
      else {
        vans[qi]=kmp_match(modstr+l,r-l+1,vqstr[qi],qlen);
      }
    }
  }
  for (int l=0;l<slen;l++) {
    int len=min(R,slen-l);
    ins(root,str+l,len,l);
  }
  for (int qi=qlo;qi<qlim;qi++) {
    char t=vt[qi];
    if (t=='1') {
      int p=vl[qi]; char c=vr[qi];
      if (str[p]!=c) {
        for (int l=max(0,p-R+1);l<=p;l++) {
          int len=min(R,slen-l);
          int cdepth=p-l;
          modify(root,str+l,len,l,cdepth,c);
        }
        str[p]=c;
      }
    }
    else {
      int l=vl[qi],r=vr[qi],qlen=vqlen[qi];
      int ans;
      if (qlen<=R) {
        ans=query(qi2set[qi],qlen,l,r);
      }
      else {
        ans=vans[qi];
      }
      printf("%d\n",ans);
    }
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