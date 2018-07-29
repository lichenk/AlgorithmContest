/*
To optimize:
 Use floats. Scan through inp[][], get the 10 highest numbers, zero them out and manually compute them after the main loop.
 */
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
const int sz=mxn;
point w[mxn+1];
const ld PI=3.14159265358979323846264338327950288;
void init(int n)
{
	w[0]=point(1,0);
	complex<long double> e(0,2*PI/sz);
	complex<long double> unit=exp(e);
	lpoint tw(unit.real(),unit.imag());
	lpoint cur(1,0);
	for(int i=1;i<=sz;i++) {
		cur=cur*tw;
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
			for(int j=i,outer=0;j<i+l;j++,outer+=g)
			{
				point t=a[j+l]*w[outer];
				auto aij=a[j];
				a[j+l]=aij-t;
				a[j]=aij+t;
			}
		}
		g>>=1;
	}
	//if(rev)for(int i=0;i<sz;i++)a[i]=a[i]/sz; // Output should divide by sz*sz
}
void FFTrev(point a[])
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
			for(int j=i,outer=sz;j<i+l;j++,outer-=g)
			{
				point t=a[j+l]*w[outer];
				auto aij=a[j];
				a[j+l]=aij-t;
				a[j]=aij+t;
			}
		}
		g>>=1;
	}
	//if(rev)for(int i=0;i<sz;i++)a[i]=a[i]/sz; // Output should divide by sz*sz
}

/*inline void transpose(point (&dest)[mxn][mxn], point (&src)[mxn][mxn]) {
	const int blocksize=512;
	const int logn=12;
	int n=sz;
	for (int i = 0; i < n; i += blocksize) {
		for (int j = 0; j < n; j += blocksize) {
			for (int k = i; k < i + blocksize; ++k) {
				for (int l = j; l < j + blocksize; ++l) {
					dst[k + l<<12] = src[l + k<<12];
				}
			}
		}
	}
}*/
point A[mxn][mxn];

void FFT2() {
	for (int i = 0; i < sz; i++)FFT(A[i]);
	const int n=mxn;
	size_t block=0,size=8;
	for(block=0;block+size-1<n;block+=size){
		for(size_t i=block;i<block+size;++i){
			for(size_t j=i+1;j<block+size;++j){
				std::swap(A[i][j],A[j][i]);}}
		for(size_t i=block+size;i<n;++i){
			for(size_t j=block;j<block+size;++j){
				std::swap(A[i][j],A[j][i]);}}}
	for(size_t i=block;i<n;++i){
		for(size_t j=i+1;j<n;++j){
			std::swap(A[i][j],A[j][i]);}}
	for (int i = 0; i < sz; i++)FFT(A[i]);
	//for(int i=0;i<sz;i++)for(int j=i;j<sz;j++)swap(a[i][j],a[j][i]); // No need to swap, we're going to swap again in inverse FFT.
};

void FFT2rev() {
	for (int i = 0; i < sz; i++)FFTrev(A[i]);
	const int n=mxn;
	size_t block=0,size=8;
	for(block=0;block+size-1<n;block+=size){
		for(size_t i=block;i<block+size;++i){
			for(size_t j=i+1;j<block+size;++j){
				std::swap(A[i][j],A[j][i]);}}
		for(size_t i=block+size;i<n;++i){
			for(size_t j=block;j<block+size;++j){
				std::swap(A[i][j],A[j][i]);}}}
	for(size_t i=block;i<n;++i){
		for(size_t j=i+1;j<n;++j){
			std::swap(A[i][j],A[j][i]);}}
	for (int i = 0; i < sz; i++)FFTrev(A[i]);
}



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
const int sz2=sz*sz;
const int minp=200000;
int ax[minp],ay[minp];
typedef pair<int,int> pii;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
	for(int i = 0 ; i < n ; i++){
		int x=rint(),y=rint();
		ax[i]=x,ay[i]=y;
		inp[x][y]++;
	}
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	for (int x=1;x<mn;x++) for (int y=1;y<mn;y++) {
			int cnt=inp[x][y];
			if (cnt) {
				A[x][y].x=inp[x][y];
				pq.push(MP(inp[x][y], (x<<16)|y));
				if (pq.size()>4) pq.pop();
			}
		}
	vector<pii> v; while(!pq.empty()) {
		v.PB(pq.top()); pq.pop();
	}
	factinit();
	int final=0;
	for (auto &w:v) {
		int c=w.fst;
		int c2=((c*(ll)(c-1)))%MOD;
		int bx=w.snd>>16,by=w.snd&0xffff;
		int sx=bx<<1,sy=by<<1;
		//printf("c:%d bx:%d by:%d c2:%d\n",c,bx,by,c2);
		int muler=binom(sx+sy,sx);
		final=(final+muler*(ll)c2)%MOD;
		A[bx][by].x=0;
		inp[bx][by]=0;
	}
	set<int> ss; for (auto &w:v) ss.insert(w.snd);
	for (int i=0;i<n;i++) {
		int x=ax[i],y=ay[i];
		int sig=(x<<16)|y;
		for (auto &w:v) {
			int wsnd=w.snd;
			if (sig!=wsnd) {
				int c=w.fst;
				if (ss.find(sig)==ss.end()) c<<=1;
				int bx=wsnd>>16,by=wsnd&0xffff;
				int sx=x+bx,sy=y+by;
				//printf("x:%d bx:%d y:%d by:%d c:%d\n",x,bx,y,by,c);
				int muler=binom(sx+sy,sx);
				final=(final+muler*(ll)c)%MOD;
			}
		}
	}
	init(mxn);
	FFT2();
	for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)A[i][j]=A[i][j]*A[i][j];
	FFT2rev();
	for (int x=2;x<=4000;x++) {
		for (int y=2;y<=4000;y++) {
			ll lgot=round(A[x][y].x);
			int got=0;
			if (lgot!=0) {
				lgot=(lgot+(sz2>>1))>>24;
				if (lgot>=MOD) got=lgot%MOD;
				else got=lgot;
			}
			if (0==((x|y)&1)) {
				int dup=inp[x>>1][y>>1];
				if (dup!=0) got+=MOD-dup;
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