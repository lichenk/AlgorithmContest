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
	pii ans=MP(p.fst+q.fst,p.snd+q.snd);
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

inline int quadrant(pii p) {
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
	int x1=l1.fst,y1=l1.snd;
	int x2=l2.fst,y2=l2.snd;
	int q1=quad(l1);
	int q2=quad(l2);
	if (q1==q2) {
		if (0==(q&1)) return false; // Equal
		return y1*(ll)x2 < x1*(ll)y2;
	}
	return q1<q2;
}

inline bool cmpAB(int a, int b) {
	return cmpLine(vp[a],vp[b]);
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
int pos2id[mn];
bitset<mn> pendingSwap[mn];
map<pii, int> h;
inline void rmLine(pii line) {
	auto it=h.find(line);
	if (it->snd>1) {--(it->snd);}
	else {
		assert(it->snd==1);
		h.erase(it);
	}
}
inline void addAdj(int st, int en, bool add) {

}
set<pii> final;
void goswap(int a, int b) {
	int posa=id2pos[a],posb=id2pos[b];
	assert(abs(posa-posb)==1);
	if (posa>posb) {
		swap(a,b); swap(posa,posb);
	}
	int st=max(posa-1,0);
	int en=min(posa+1,n-2);
	addAdj(st,en,false);
	swap(pos2id[posa],pos2id[posb]);
	swap(id2pos[a],id2pos[b]);
	addAdj(st,en,true);
	pendingSwap[a][b]=false;
	pendingSwap[b][a]=false;
	for (int pos=st;pos<=en;pos++) {
		int na=pos2id[pos],nb=pos2id[pos+1];
		if (pendingSwap[na][nb]) {
			goswap(na,nb);
		}
	}
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) pos2id[i]=i;
  for (int i=0;i<n;i++) {
  	int x=rint(); int y=rint();
  	vp[i]=MP(x,y);
  }
  if (n<=2) {
  	printf("-1\n"); exit(0);
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
  int adjs=(n-1)/2;
  for (int adj=0;adj<adjs;adj++) {
  	int a=pos2id[adj],b=pos2id[adj+1];
  	int c=pos2id[n-2-adj],d=pos2id[n-1-adj];
  	pii line=lineFor4Pt(a,b,c,d);
  	++h[line];
  }
  if (h.size()==1) final.insert((h.begin())->fst);
  sort(sortedAB,sortedAB+szAB,cmpAB);
  for (int iab=0;iab<szAB;iab++) {
  	int a=sortedAB[iab].fst,b=sortedAB[iab].snd;
  	int posa=id2pos[a],posb=id2pos[b];
  	if (abs(posa-posb)==1) {
  		goswap(a,b);
  		if (h.size()==1) final.insert((h.begin())->fst);
  	}
  	else {
  		pendingSwap[a][b]=true;
  		pendingSwap[b][a]=true;
  	}
  }

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