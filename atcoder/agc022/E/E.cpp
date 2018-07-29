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
int extgcd(int a, int b, int& x, int& y) { for (int u = y = 1, v = x = 0; a;) { int q = b / a; swap(x -= q *(ll) u, u); swap(y -= q *(ll) v, v); swap(b -= q *(ll) a, a); } return b; }
int mod_inv(int a, int m) { int x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }

const int mn=3e5+4;
const int ml=4;
ll f[2][ml][1<<ml];
bool a[mn][2];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
void solve(string s){
	int n=s.length();
	int ques=0;
	for (int i=0;i<n;i++) {
		char c=s[i];
		if (c=='?') {a[i][0]=a[i][1]=true; ques++;}
		else a[i][c-'0']=true;
	}
	int cur=0,nxt=1;
	if (a[0][0]) f[cur][1][0]=1;
	if (a[0][1]) f[cur][1][1]=1;
	for (int i=1;i<n;i++) {
		memset(f[nxt],0,sizeof f[nxt]);
		for (int c=0;c<2;c++) {
			if (!a[i][c]) continue;
			for (int l=1;l<ml;l++) {
				int zlim=1<<l;
				for (int z=0;z<zlim;z++) {
					int now=f[cur][l][z];
					if (now==0) continue;
					now%=MOD;
					int az=(z<<1)|c;
					if (l+1<ml) f[nxt][l+1][az]+=now;
					for (int s=0;s+2<l+1;s++) {
						int inc=(__builtin_popcount((az>>s)&7)>=2)?1:0;
						int bz=0,idx=0;
						for (int y=0;y<s;y++) {
							if (az&(1<<y)) bz|=1<<idx;
							idx++;
						}
						bz|=inc<<idx; idx++;
						for (int y=s+3;y<l+1;y++) {
							if (az&(1<<y)) bz|=1<<idx;
							idx++;
						}
						assert(idx==l+1-2);
						//printf("l:%d s:%d az:%d bz:%d\n",l,s,az,bz);
						f[nxt][idx][bz]+=now;
					}
				}
			}
		}
		swap(cur,nxt);
	}
	//printf("%d %d\n",f[cur][1][0],f[cur][1][1]);
	int denom=(f[cur][1][0]+f[cur][1][1])%MOD;
	int numer=mod_pow(2,ques,MOD);
	int invdenom=mod_pow(denom,MOD-2,MOD);
	int ans=mul(f[cur][1][1],mul(numer,invdenom));
	printf("%lld\n",f[cur][1][1]%MOD);
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	string S;
	cin >> S;
	solve(S);
	return 0;
}

