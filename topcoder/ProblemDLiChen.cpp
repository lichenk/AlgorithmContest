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


const int maxn=999999+1;
const int maxp=6;
const int maxd=10;
const int mod=1000000007;
const int maxptwo=5000000+2;
int ptwo[maxptwo];
int f[maxn];
int mod10[maxn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int z=0;z<10;z++) mod10[z]=z;
	for (int z=10;z<maxn;z++) mod10[z]=mod10[z-10];
	int p2=1;
	for (int i=0;i<maxptwo;i++) {
		ptwo[i]=p2;
		p2=p2*2;
		if (p2>=mod) p2-=mod;
	}
	int n=readInt();
	for (int i=0;i<n;i++) {
		int x=readInt();
		f[x]++;
	}
	{
		int pten=1;
		for (int p=0;p<maxp;p++) {
			for (int z=maxn-1;z>=0;z--) {
				int d=mod10[z/pten];
				if (d!=9) {
					f[z]+=f[z+pten];
				}
			}
			pten*=10;
		}
	}
	for (int z=0;z<maxn;z++) {
		int x=f[z];
		if (x==0) f[z]=0;
		else f[z]=((ll)x*(ll)ptwo[x-1])%mod;
	}
	{
		int pten=1;
		for (int p=0;p<maxp;p++) {
			for (int z=0;z<maxn;z++) {
				int d=mod10[(z/pten)];
				if (d!=9) {
					f[z]-=f[z+pten];
					if (f[z]<0) f[z]+=mod;
				}
			}
			pten*=10;
		}
	}
	ll ans=0;
	for (int z=0;z<maxn;z++) {
		ans^=((ll)z*(ll)(f[z]));
	}
	printf("%lld\n",ans);
}

