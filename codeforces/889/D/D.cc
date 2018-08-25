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
const int mn=2000;
pii vp[mn];

inline pii operator+ (const pii &p, const pii &q) {
	return MP(p.fst+q.fst,p.snd+q.snd);
}
inline pii operator- (const pii &p, const pii &q) {
	return MP(p.fst-q.fst,p.snd-q.snd);
}

inline pii lineFor2Pt(pii p1, pii p2) {
	int x1=p1.fst,y1=p1.snd;
	int x2=p2.fst,y2=p2.snd;
	int xres=y1-y2,yres=x2-x1;
	if (yres<0||(yres==0&&xres<0)) {xres=-xres; yres=-yres;}
	return MP(xres,yres);
}
inline pii lineFor4Pt(pii p1, pii p2, pii p3, pii p4) {
	return lineFor2Pt(p2-p1,p4-p3);
}

inline int quad(pii p) {
	int x=p.fst,y=p.snd;
	if (y==0) return 0;
	else if (x>0) {
		assert(y>0);
		return 1;
	}
	else if (x==0) return 2;
	else {
		assert(y>0&&x<0);
		return 3;
	}
}
inline bool cmpLine(pii l1, pii l2) {

	int q1=quad(l1);
	int q2=quad(l2);
	if (q1==q2) {
		if (0==(q1&1)) return false; // Equal
    int x1=abs(l1.fst),y1=abs(l1.snd);
    int x2=abs(l2.fst),y2=abs(l2.snd);
		if (q1==1) return y1*(ll)x2 < x1*(ll)y2;
    else {
      assert(q1==3);
      return y1*(ll)x2 > x1*(ll)y2;
    }
	}
	return q1<q2;
}

inline bool cmpAB(pii p1, pii p2) {
	int a1=p1.fst,b1=p1.snd;
	int a2=p2.fst,b2=p2.snd;
	return cmpLine(lineFor2Pt(vp[a1],vp[b1]),lineFor2Pt(vp[a2],vp[b2]));
}
inline bool cmpX(int a, int b) {
	if (vp[a].fst==vp[b].fst) return vp[a].snd < vp[b].snd;
	return vp[a].fst<vp[b].fst;
}
inline ll dot(pii p1, pii p2) {
	int x1=p1.fst,y1=p1.snd;
	int x2=p2.fst,y2=p2.snd;
	return x1*(ll)x2 + y1*(ll)y2;
}
pii sortedAB[(mn*(mn-1))/2];
int pos2id[mn],id2pos[mn];
bitset<mn> pendingSwap[mn];
const int MAXA=((mn-1)/2);
vector<int> vactiveCls[2];
int bactiveCls[2][MAXA];
int ts=1;
int cur=0,nxt=1;
int gn;
int ncls;
int nactive;
int getClass(int x) {
	int inpx=x;
	if (gn%2==0 && x==ncls) return -1;
	if (x>=ncls) {
		x++;
		x=gn-1-x;
	}
	assert(x<ncls);
	return x;
}

int gcd(int a, int b) {
  a=abs(a); b=abs(b);
	if(a==0||b==0) return a+b;
	return __gcd(a,b);
}
void fail(int t) {
	dbg("t:%d\n",t);
	printf("-1\n"); exit(0);
}
vector<pii> vcandLine;
inline void check(pii line) {
  int g=gcd(line.fst,line.snd);
  line.fst/=g; line.snd/=g;
	//printf("check line: %d %d\n",line.fst,line.snd);
  assert(vactiveCls[nxt].size()==0);
  for (auto cls: vactiveCls[cur]) {
  	//printf("cls:%d\n",cls);
    if (bactiveCls[nxt][cls]==ts+1) continue;
  	pii d1=vp[pos2id[cls+1]]-vp[pos2id[cls]];
  	pii d2=vp[pos2id[gn-1-cls]]-vp[pos2id[gn-2-cls]];
  	if (d1!=d2) {
  		vactiveCls[nxt].PB(cls);
  		bactiveCls[nxt][cls]=ts+1;
  	}
  }
  nactive=vactiveCls[nxt].size();
  if (nactive==0) fail(3);
  vactiveCls[cur].clear();
  swap(cur,nxt);
  vcandLine.PB(line);
}
inline void rmAdj(int st, int en) {
	int take=0;
	int lastcls=-1;
	for (int x=st;x<=en;x++) {
		int cls=getClass(x);
		if (cls==-1) continue;
		if (bactiveCls[cur][cls]==ts) {
      //printf("RM:%d nactive:%d take:%d\n",cls,nactive,take);
			take++; lastcls=cls;
		}
	}
	if (nactive-take<=0) {
		// Do reset
		int cls=lastcls;
		if (cls==-1) fail(2);
		pii line=lineFor4Pt(vp[pos2id[cls]],vp[pos2id[cls+1]],vp[pos2id[gn-2-cls]],vp[pos2id[gn-1-cls]]);
		check(line);
		ts++;
	}
	for (int x=st;x<=en;x++) {
		int cls=getClass(x);
		if (cls==-1) continue;
		if (bactiveCls[cur][cls]==ts) {
			nactive--;
			bactiveCls[cur][cls]=0;
		}
	}
}
inline void addAdj(int st, int en, bool init=false) {
	for (int x=st;x<=en;x++) {
		int cls=getClass(x);
		if (cls==-1) continue;
    //printf("ADD:%d\n",cls);
  	pii d1=vp[pos2id[cls+1]]-vp[pos2id[cls]];
  	pii d2=vp[pos2id[gn-1-cls]]-vp[pos2id[gn-2-cls]];
  	if (d1!=d2) {
  		vactiveCls[cur].PB(cls);
  		if (init) bactiveCls[cur][cls]=ts;
  	}
	}
}
bool lessthan(int a, int b, pii line) {
  ll adot=dot(vp[a],line);
  ll bdot=dot(vp[b],line);
  if (adot==bdot) {
    pii orth=MP(-line.snd,line.fst);
    ll aDotOrth=dot(vp[a],orth);
    ll bDotOrth=dot(vp[b],orth);
    return aDotOrth<bDotOrth;
  }
  return adot<bdot;
}
void goswap(int a, int b, pii line) {
	int n=gn;
	int posa=id2pos[a],posb=id2pos[b];
	assert(abs(posa-posb)==1);
	if (posa>posb) {
		swap(a,b); swap(posa,posb);
	}
	assert(posa<posb);
	// After swap, b should be on the left of a.
  if (lessthan(b,a,line)) {
  	//printf("Swapping: %d %d -> %d %d\n",a,b,b,a);
  	//for (int i=0;i<n;i++) {
  	//	printf("%d ",pos2id[i]);
  	//}
  	//printf(" pre-swap\n");
  	int st=max(posa-1,0);
  	int en=min(posa+1,gn-2);
  	rmAdj(st,en);
  	swap(pos2id[posa],pos2id[posb]);
  	swap(id2pos[a],id2pos[b]);
  	addAdj(st,en);
  	//for (int i=0;i<n;i++) {
  	//	printf("%d ",pos2id[i]);
  	//}
  	//printf(" post-swap\n");
  	pendingSwap[a][b]=false;
  	pendingSwap[b][a]=false;
  	for (int pos=st;pos<=en;pos++) {
  		int na=pos2id[pos],nb=pos2id[pos+1];
  		if (pendingSwap[na][nb]) {
  			goswap(na,nb,line);
  		}
  	}
  }
}



void goswap2(int a, int b, pii line) {
	int n=gn;
	int posa=id2pos[a],posb=id2pos[b];
	assert(abs(posa-posb)==1);
	if (posa>posb) {
		swap(a,b); swap(posa,posb);
	}
	assert(posa<posb);
	// After swap, b should be on the left of a.
  if (lessthan(b,a,line)) {
  	//printf("Swapping: %d %d -> %d %d\n",a,b,b,a);
  	//for (int i=0;i<n;i++) {
  	//	printf("%d ",pos2id[i]);
  	//}
  	//printf(" pre-swap\n");
  	int st=max(posa-1,0);
  	int en=min(posa+1,gn-2);
  	swap(pos2id[posa],pos2id[posb]);
  	swap(id2pos[a],id2pos[b]);
  	//for (int i=0;i<n;i++) {
  	//	printf("%d ",pos2id[i]);
  	//}
  	//printf(" post-swap\n");
  	pendingSwap[a][b]=false;
  	pendingSwap[b][a]=false;
  	for (int pos=st;pos<=en;pos++) {
  		int na=pos2id[pos],nb=pos2id[pos+1];
  		if (pendingSwap[na][nb]) {
  			goswap2(na,nb,line);
  		}
  	}
  }
}




pii gcandLine;
bool cmpCandLine(const int &p, const int &q) {
	return dot(vp[p], gcandLine) < dot(vp[q], gcandLine);
}
int sortedP[mn];

bool lessthan2(int a, int b, pii line) {
  ll adot=dot(vp[a],line);
  ll bdot=dot(vp[b],line);
  if (adot==bdot) {
  	return true;
  }
  return adot<bdot;
}

void checkmain(pii line) {
	return;
  for (int i=1;i<gn;i++) {
    int p=pos2id[i-1],q=pos2id[i];
    if(!lessthan2(p,q,line)) {
      printf("i:%d p:%d q:%d\n",i,pos2id[i-1],pos2id[i]);
      exit(-1);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); gn=n;
  for (int i=0;i<n;i++) pos2id[i]=i;
  for (int i=0;i<n;i++) {
  	int x=rint(); int y=rint();
    //assert(0==x%250000);assert(0==y%250000);
    //x/=250000; y/=250000;
    //printf("x:%d y:%d\n",x,y);
  	vp[i]=MP(x,y);
  }
  //printf("\n");
  if (n<=2) {
  	fail(1);
  }
  int szAB=0;
  for (int a=0;a<n;a++) {
  	for (int b=a+1;b<n;b++) {
  		sortedAB[szAB++]=MP(a,b);
  	}
  }
  sort(pos2id,pos2id+n,cmpX);
  for (int pos=0;pos<n;pos++) {
  	id2pos[pos2id[pos]]=pos;
  }
  checkmain(MP(1,0));
  ncls=(n-1)/2;
  sort(sortedAB,sortedAB+szAB,cmpAB);
  addAdj(0,ncls-1,true);
  nactive=vactiveCls[cur].size();
  for (int iab=0;iab<szAB;iab++) {
  	int a=sortedAB[iab].fst,b=sortedAB[iab].snd; assert(a<b);
  	int posa=id2pos[a],posb=id2pos[b];
  	if (abs(posa-posb)==1) {
      pii abLine = lineFor2Pt(vp[a],vp[b]);
  		goswap(a,b,abLine);
      
      //for (int i=0;i<n;i++) {
      //  printf("%d ",pos2id[i]);
      //}
      //printf(" main a:%d b:%d line:%d %d\n",a,b,abLine.fst,abLine.snd);
      //checkmain(abLine);
  	}
  	else {
  		pendingSwap[a][b]=true;
  		pendingSwap[b][a]=true;
  	}
  }
  {
  	
  	for (int cls=0;cls<ncls;cls++) {
  		pii line=lineFor4Pt(vp[pos2id[cls]],vp[pos2id[cls+1]],vp[pos2id[gn-2-cls]],vp[pos2id[gn-1-(cls)]]);
  		if (bactiveCls[cur][cls]==ts) {
  			//printf("terminal: %d %d\n",line.fst,line.snd);
        int g=gcd(line.fst,line.snd);
        line.fst/=g; line.snd/=g;
  			vcandLine.PB(line); break;
  		}
  	}
  }
  int final=0;
  sort(vcandLine.begin(),vcandLine.end());
  auto it=unique(vcandLine.begin(),vcandLine.end());
  vcandLine.resize(distance(vcandLine.begin(), it));
  sort(vcandLine.begin(),vcandLine.end(),cmpLine);
  sort(pos2id,pos2id+n,cmpX);
  for (int pos=0;pos<n;pos++) {
  	id2pos[pos2id[pos]]=pos;
  }
  for (int a=0;a<n;a++) pendingSwap[a].reset();
  int iab=0;
  for (auto &line:vcandLine) {
  	while(iab<szAB) {
  		int a=sortedAB[iab].fst,b=sortedAB[iab].snd; assert(a<b);
  		pii abLine=lineFor2Pt(vp[a],vp[b]);
  		if (cmpLine(line,abLine)) break;
  		int posa=id2pos[a],posb=id2pos[b];
  		if (abs(posa-posb)==1) {
  			goswap2(a,b,line);
    	  //for (int i=0;i<n;i++) {
    	  //  printf("%d ",pos2id[i]);
    	  //}
    	  //printf(" main a:%d b:%d line:%d %d\n",a,b,abLine.fst,abLine.snd);
  		}
  		else {
  			pendingSwap[a][b]=true;
  			pendingSwap[b][a]=true;
  		}
  		iab++;
  	}
  	checkmain(line);
    int ok=1;
    for (int cls=0;cls<ncls;cls++) {
      ll dot1=dot(vp[pos2id[cls+1]]-vp[pos2id[cls]], line);
      pii A=vp[pos2id[gn-1-cls]];
      pii B=vp[pos2id[gn-2-cls]];
      pii C=A-B;
      ll dot2=dot(C, line);
      if (dot1!=dot2) {ok=0; break;}
    }
    //if (ok) printf("x:%d y:%d\n",line.fst,line.snd);
    final+=ok;
  }
  printf("%d\n",final);
}





int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
long long rlong()
{
  long long x; scanf("%lld",&x); return x;
}