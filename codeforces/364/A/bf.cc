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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
const int mn=4004;
int q[60];
int b[mn];
inline int query(int l, int r) {
	//printf("l:%d r:%d ans:%d\n",l,r,b[r+1]-b[l]);
	return b[r+1]-b[l];
}
int n;
int bins(int start, int key) {
	int imin=start,imax=n;
	while(imin<imax) {
		int imid=(imin+imax)>>1;
		if (query(start,imid)<key) {
			imin=imid+1;
		}
		else imax=imid;
		//if (key==11&&start==0) printf("start:%d key:%d imin:%d imax:%d imid:%d\n",start,key,imin,imax,imid);
	}
	//if (key==11&&start==0) {printf("start:%d key:%d imin:%d\n",start,key,imin); exit(0);}
	return imin;
}
int getb(int start, int key) {
	int L=bins(start,key);
	if (query(start,L)!=key) return 0;
	int R=bins(start,key+1);
	//if (key==10) printf("L:%d R:%d start:%d key:%d\n",L,R,start,key);
	return R-L;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a; cin>>a;
	string s; cin>>s;
	n=s.length();
	for (int x=0;x<n;x++) b[x]=(s[x]-'0');
	ll final=0;
	for (int xl=0;xl<n;xl++) for (int xh=xl;xh<n;xh++)
		for (int yl=0;yl<n;yl++) for (int yh=yl;yh<n;yh++) {
			ll sum=0;
			for (int x=xl;x<=xh;x++)for (int y=yl;y<=yh;y++) {
				sum+=b[x]*b[y];
			}
			if (sum==a) final++;
		}
	printf("%lld\n",final);
}

