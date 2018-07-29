#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef float ld;
typedef double lld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const int mxn=4096;
struct point
{
		ld x,y;
		point(ld _x=0,ld _y=0){x=_x;y=_y;}
		point operator+(const point &t)const{return point(x+t.x,y+t.y);}
		point operator-(const point &t)const{return point(x-t.x,y-t.y);}
		point operator*(const point &t)const{return point(x*t.x-y*t.y,x*t.y+y*t.x);}
		point operator*(const ld &t)const{return point(x*t,y*t);}
		point operator*(const int &t)const{return point(x*t,y*t);}
		point operator/(const int &t)const{return point(x/t,y/t);}
};
struct lpoint
{
		lld x,y;
		lpoint(lld _x=0,lld _y=0){x=_x;y=_y;}
		lpoint operator+(const lpoint &t)const{return lpoint(x+t.x,y+t.y);}
		lpoint operator-(const lpoint &t)const{return lpoint(x-t.x,y-t.y);}
		lpoint operator*(const lpoint &t)const{return lpoint(x*t.x-y*t.y,x*t.y+y*t.x);}
		lpoint operator*(const lld &t)const{return lpoint(x*t,y*t);}
		lpoint operator*(const int &t)const{return lpoint(x*t,y*t);}
		lpoint operator/(const int &t)const{return lpoint(x/t,y/t);}
};
//point makeunit(ld x){return point(cos(x),sin(x));}
int sz;
point w[mxn+1];
lpoint lw[mxn+1];
const ld PI=3.14159265358979323846264338327950288;
void init(int n)
{
	if(sz==n)return;
	sz=1;
	while(sz<n)sz<<=1;
	w[0]=point(1,0);
	complex<long double> e(0,2*PI/sz);
	complex<long double> unit=exp(e);
	lpoint tw(unit.real(),unit.imag());
	lpoint cur(1,0);
	for(int i=1;i<=sz;i++) {
		cur=cur*tw;
		lw[i]=cur;
		w[i]=point(cur.x,cur.y);
	}
}
void FFT(point a[])
{
	for(int i=0,j=0;i<sz;i++)
	{
		if(i>j)swap(a[i],a[j]);
		for(int l=sz>>1;(j^=l)<l;l>>=1);
	}
	int g=sz>>1;
	for(int l=1;l<sz;l<<=1)
	{
		int l2=l<<1;
		for(int i=0;i<sz;i+=l2)
		{
			int outer=0;
			for(int j=0;j<l;j++)
			{
				point t=a[i+j+l]*w[outer];
				auto aij=a[i+j];
				a[i+j+l]=aij-t;
				a[i+j]=aij+t;
				outer+=g;
			}
		}
		g>>=1;
	}
	//if(rev)for(int i=0;i<sz;i++)a[i]=a[i]/sz; // Output should divide by sz*sz
}
void FFTrev(lpoint a[])
{
	for(int i=0,j=0;i<sz;i++)
	{
		if(i>j)swap(a[i],a[j]);
		for(int l=sz>>1;(j^=l)<l;l>>=1);
	}
	int g=sz>>1;
	for(int l=1;l<sz;l<<=1)
	{
		int l2=l<<1;
		for(int i=0;i<sz;i+=l2)
		{
			int outer=sz;
			for(int j=0;j<l;j++)
			{
				lpoint t=a[i+j+l]*lw[outer];
				auto aij=a[i+j];
				a[i+j+l]=aij-t;
				a[i+j]=aij+t;
				outer-=g;
			}
		}
		g>>=1;
	}
	//if(rev)for(int i=0;i<sz;i++)a[i]=a[i]/sz; // Output should divide by sz*sz
}

point A[mxn][mxn];
lpoint B[mxn][mxn];
void FFT2rev() {
		for (int i = 0; i < sz; i++)FFTrev(B[i]);
		for (int i = 0; i < sz; i++)for (int j = i; j < sz; j++)swap(B[i][j], B[j][i]);
		for (int i = 0; i < sz; i++)FFTrev(B[i]);
}
void FFT2() {
		for (int i = 0; i < sz; i++)FFT(A[i]);
		for (int i = 0; i < sz; i++)for (int j = i; j < sz; j++)swap(A[i][j], A[j][i]);
		for (int i = 0; i < sz; i++)FFT(A[i]);
	//for(int i=0;i<sz;i++)for(int j=i;j<sz;j++)swap(a[i][j],a[j][i]); // No need to swap, we're going to swap again in inverse FFT.
};


int mod_pow(int a, int n) {
	int ret = 1; int p = a % MOD; while (n) { if (n & 1) ret = (ret *(ll) p) % MOD; p = (p *(ll) p) % MOD; n >>= 1; } return ret;
}
const int MAXFACT=8001;
int fact[MAXFACT+1],invfact[MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
void factinit() {
	int got=1;
	for (int x=0;x<=MAXFACT;x++) {
		fact[x]=got;
		got=mul(got,x+1);
	}
	got=mod_pow(got,MOD-2);
	for (int x=MAXFACT;x>=0;x--) {
		got=mul(got,x+1);
		invfact[x]=got;
	}
}
int binom(int n,int k) {
	return mul(fact[n],mul(invfact[k],invfact[n-k]));
}
const int mn=2001;
int inp[mn][mn];
int rint();
int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
	for(int i = 0 ; i < n ; i++){
		inp[rint()][rint()]++;
	}
	memset(A,0,sizeof A);
	for (int x=0;x<mn;x++) for (int y=0;y<mn;y++) A[x][y].x=inp[x][y];
	init(mxn);
	FFT2();
	for(int i=0;i<sz;i++)for(int j=0;j<sz;j++) {
			point ga=A[i][j];
			lpoint got(ga.x,ga.y);
			B[i][j]=got*got;
			//A[i][j]=A[i][j]*A[i][j];
		}
	FFT2rev();
	factinit();
	int final=0;
	int sz2=sz*sz;
	for (int x=2;x<=4000;x++) {
		for (int y=2;y<=4000;y++) {
			ll lgot=round(B[x][y].x/sz2);
			int got=(lgot)?lgot%MOD:0;
			if (got < 0) got += MOD;
			if (0==((x&1)|(y&1))) {
				int dup=inp[x>>1][y>>1];
				got-=dup;
				if (got < 0) got += MOD;
			}
			if (got!=0) {
				int multiplier = binom(x + y, x);
				final = (final + got * (ll) multiplier) % MOD;
			}
		}
	}
	final=mul(final, 500000004);
	printf("%d\n",final);
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