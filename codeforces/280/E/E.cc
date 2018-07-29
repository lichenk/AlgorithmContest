#include <bits/stdc++.h>
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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=6000;
int vx[mn];
int *rl2id[mn];
ll *prefixsum;
int gn,q,a,b;
int gk;

inline int getid(int l, int r) {
	return rl2id[r][l];
}

bool cmp1(const int &x, const int &y) {
	int xl=x>>16,xr=x&0xffff;
	int yl=x>>16,yr=x&0xffff;
	ld xsum=prefixsum[xr]-prefixsum[xl-1];
	ld ysum=prefixsum[yr]-prefixsum[yl-1];
	int xd=xr-xl+1;
	int yd=yr-yl+1;
	return xsum*yd < ysum*xd;
}
int cmp2r;
bool cmp2(const pair<short,float> &x, const pair<short,float> &y) {
	return getid(x.fst,cmp2r)<getid(y.fst,cmp2r);
}

vector<pair<short,float> > f[mn];

template <typename LST> struct LimitedVec  {
  LST a[mn];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
};
LimitedVec<pair<short,double> > tmp;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  gn=rint(),q=rint(),a=rint(),b=rint();
  int n=gn;
  for (int i=0;i<n;i++) {
  	vx[i]=rint();
  }
  prefixsum = new ll[n+1];
  {
  	ll sub=0;
  	for (int i=0;i<n;i++) {
  		prefixsum[i+1]=vx[i]-sub;
  		sub+=a;
  	}
  }
  gk=(n*(n+1))/2;
  int *pfi=new int[gk];
	int pfisz=0;
  for (int l=0;l<n;l++) for (int r=l;r<n;r++) pfi[pfisz++]=(l<<16)|r;
  sort(pfi,pfi+gk,cmp1);
	delete prefixsum;
  for (int r=0;r<n;r++) rl2id[r]=new int[r+1];
	for (int i=0;i<gk;i++) {
		int got=pfi[i];
		int l=got>>16,r=got&0xffff;
		rl2id[r][l]=i;
	}
  delete pfi;
  for (int l=0;l<gn;l++) {
  	if (l>0) {
  		if (f[l-1].size()==0) continue;
  		cmp2r=l-1;
  		sort(f[l-1].begin(),f[l-1].end(),cmp2);
  		pair<short,float> best;
  		for (int i=0;i<(int)f[l-1].size();i++) {
  			if (i==0||f[l-1][i].snd<best.snd) {
  				best=f[l-1][i];
  				tmp.PB(f[l-1][i]);
  			}
  		}
  		f[l-1].resize(tmp.sz);
  		for (int i=0;i<tmp.sz;i++) {
  			f[l-1][i]=tmp.a[i];
  		}
  	}
		int nn=0;
		ld mean=0; ld M2=0;
		for (int i=l;i<gn;i++) {
			nn+=1;
			ld x=vx[i]-i*(ll)a;
			ld delta=x-mean;
			mean+=delta/nn;
			ld delta2=x-mean;
			M2+=delta*delta2;
			int r=i;
			if (l==0) {
				printf("l:%d r:%d M2:%.9f\n",l,r,(double)M2);
				f[r].PB(MP(l, M2));
			}
			else {
				int rlid=getid(l,r);
				int imin=0,imax=f[l-1].size();
				while(imin<imax) {
					int imid=(imin+imax)>>1;
					int prevl=f[l-1][imid].fst;
					int previd=getid(prevl,l-1);
					if (previd<rlid) imin=imid+1;
					else imax=imid;
				}
				if (imin<f[l-1].size()) {
					ld ans=f[l-1][imin].snd + M2;
					printf("l:%d r:%d ans:%.9f\n",l,r,(double)ans);
					f[r].PB(MP(l,ans));
				}
			}
		}
  }
  vector<pair<short,short> > series;
  {
  	int r=n-1;
  	pair<short,float> best=f[r][0];
  	for (auto &w:f[r]) if (w.snd<best.snd) best=w;
  	int l=best.fst;
  	series.PB(MP(l,r));
  	//printf("l:%d r:%d\n",l,r); fflush(stdout);
  	while(l!=0) {
			int rlid=getid(l,r);
			int imin=0,imax=f[l-1].size();
			while(imin<imax) {
				int imid=(imin+imax)>>1;
				int prevl=f[l-1][imid].fst;
				int previd=getid(prevl,l-1);
				if (previd<rlid) imin=imid+1;
				else imax=imid;
			}
			int prevl=f[l-1][imin].fst;
			int prevr=l-1;
			l=prevl,r=prevr;
			series.PB(MP(l,r));
			//printf("l:%d r:%d\n",l,r); fflush(stdout);
			if (l==0) break;
  	}
  }
  cout<<fixed<<setprecision(20);
  ld final=0;
  for (int i=series.size()-1;i>=0;i--) {
  	int l=series[i].fst,r=series[i].snd;
  	printf("l:%d r:%d\n",l,r);
  	ll sum=0;
  	for (int x=l;x<=r;x++) sum+=vx[x]-x*(ll)a;
  	ld mean=sum/(ld)(r-l+1);
  	for (int x=l;x<=r;x++) {
  		ld ans=(mean+x*(ll)a);
  		ld diff=ans-vx[x];
  		final+=diff*diff;
  		cout<<ans<<" ";
  	}
  }
  cout<<"\n"<<final<<"\n";
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