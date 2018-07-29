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
const int mn=1e5+2;
set<int> t[2*mn];
int segn;
void combine(set<int> &dest, set<int> &src) {
	for (auto &w:src) dest.insert(w);
}

void modify(int l, int r, int value) {
	int n=segn;
	r++;
	if (l>r) return;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++].insert(value);
    if (r&1) t[--r].insert(value);
  }
}

void push() {
	int n=segn;
  for (int i = 1; i < n; ++i) {
  	combine(t[i<<1], t[i]);
  	combine(t[i<<1|1], t[i]);
  }
}

int query(int p) {
	int n=segn;
	return t[n+p].size();
/*  set<int> res;
  for (p += n; p > 0; p >>= 1) combine(res, t[p]);
  return res.size();*/
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt();
	segn=m+1;
	for (int i=0;i<n;i++) {
		int l=readInt(),r=readInt(),a=readInt();
		modify(l,r,a);
		modify(0,l-1,0);
		modify(r+1,m,0);
	}
	push();
	int final=0;
	for (int p=1;p<=n;p++) {
		chkmax(final,query(p));
	}
	printf("%d\n",final);
}

