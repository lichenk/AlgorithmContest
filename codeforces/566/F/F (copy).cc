#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
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

const ll mn=1e6+2;
ll a[mn];
vector<ll> divTable[mn];
ll cntX[mn];
ll cntDiv[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (ll x=1;x<mn;x++) {
		for (ll y=x;y<mn;y+=x) {
			divTable[y].PB(x);
		}
	}
	ll n=readInt();
	for (ll i=0;i<n;i++) {
		ll x=readInt();
		cntX[x]++;
	}
	for (ll x=1;x<mn;x++) {
		ll cntx=cntX[x];
		if (cntx) {
			for (auto &div:divTable[x]) {
				cntDiv[div]++;
			}
		}
	}
	ll ans=0;
	for (ll x=1;x<mn;x++) {
		if (cntX[x]) chkmax(ans,cntDiv[x]);
	}
	printf("%d\n",ans);
}

