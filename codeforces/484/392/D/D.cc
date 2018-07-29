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
const int INF=1<<25;
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
const int mn=100004;
int vkey[3][mn],vd[3*mn];
int key2fi[3][mn];
int uniq[3*mn]; int usz=1;
int keycnt[3*mn];
int bins(int key) {
  int imin=0,imax=usz;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (uniq[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin+1;
}
map<int,int> g;
inline void addg(int x) {
	//if(x==1)printf("+addg:%d\n",x);
	g[x]++;
}
inline void rmg(int x) {
	//if(x==1)printf("-rmg:%d\n",x);
	auto it=g.find(x);
	if (it->snd==1) g.erase(it);
	else it->snd -=1;
}
inline int getg() {
	auto it=g.begin();
	if (it==g.end()) return 0;
	//printf("getg:%d %d\n",it->fst,it->snd);
	//assert(it->snd>=1);
	return it->fst;
}
map<int,int> h;
void ins(int k, int v) {
	auto git=h.lower_bound(k);
	if (git!=h.end()) {
		//--git;
		//printf("gitv:%d gitk:%d v:%d k:%d\n",git->snd,git->fst,v,k);
		if (git->snd-git->fst>v-k) return;
	}
	auto oit=h.find(k);
	if (oit==h.end()) {
		h[k]=v;
		oit=h.find(k);
	}
	else {
		rmg(oit->snd);
		oit->snd=v;
	}
	addg(v);
	auto bit=oit;
	++oit;
	//printf("v:%d k:%d\n",v,k);
	//for (auto w:h) printf("(%d %d), ",w.fst,w.snd);
	//printf("\n");
	while(oit!=h.end()) {
		//printf("oitv:%d oitk:%d v:%d k:%d\n",oit->snd,oit->fst,v,k);
		if (oit->snd-oit->fst<=v-k) {
			rmg(oit->snd);
			oit=h.erase(oit);
		}
		else break;
	}
	oit=bit;
	vector<int> tmp;
	while(1) {
		//printf("oitv:%d oitk:%d v:%d k:%d\n",oit->snd,oit->fst,v,k);
		if (oit->snd-oit->fst<=v-k) {
			rmg(oit->snd);
			tmp.PB(oit->fst);
			if (oit==h.begin()) break;
			--oit;
		}
		else break;
	}
	for (auto &w:tmp) h.erase(w);
}
int pp[3]={0,1,2};
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt();
  srand(time(0)+clock());
  //random_shuffle(pp,pp+3);
  for (int kk=0;kk<3;kk++) {
  	int k=pp[kk];
  	for (int i=1;i<=n;i++) vkey[k][i]=readInt();
  	memcpy(vd+k*n,vkey[k]+1,sizeof(int)*n);  
	}
  sort(vd,vd+3*n);
  uniq[0]=vd[0];
  for (int i=1;i<3*n;i++) {
  	//printf("%d ",vd[i]);
    if (vd[i]!=vd[i-1]) uniq[usz++]=vd[i];
  }
  //printf("vd\n");
  for (int k=0;k<3;k++) for (int key=0;key<=usz;key++) key2fi[k][key]=INF;
  for (int k=0;k<3;k++) {
  	for (int i=1;i<=n;i++) {
  	  int key=bins(vkey[k][i]);
  	  //printf("k:%d i:%d key:%d o:%d\n",k,i,key,vkey[k][i]);
  	  if (key2fi[k][key]==INF) {
  	  	key2fi[k][key]=i;
  	  	vkey[k][i]=key;
  	  }
  	  else vkey[k][i]=0;
  	}
  }
  for (int k=0;k<2;k++) for (int i=1;i<=n;i++) {
  	keycnt[vkey[k][i]]++;
  }
  int needc=0;
  for (int i=n;i>=1;i--) {
  	int key=vkey[2][i];
  	//printf("i:%d key:%d cnt:%d\n",i,key,keycnt[key]);
  	if (keycnt[key]==0) {
  		needc=i; break;
  	}
  }
  //printf("start new_needc:%d\n",needc);
  ins(n,n+needc);
  set<int,greater<int> > sbi; sbi.insert(0);
  for (int bi=1;bi<=n;bi++) {
  	int key=vkey[1][bi];
  	if (key!=0&&keycnt[key]==1) sbi.insert(bi);  	
  }
  for (int bi=n;bi>=1;bi--) {
  	// Remove bi
  	int key=vkey[1][bi];
  	if (key!=0&&keycnt[key]==1) chkmax(needc, key2fi[2][key]);
  	//printf("bi-1:%d needc:%d\n",bi-1,needc);
  	//int nbi=*(sbi.upper_bound(bi));
  	int nbi=bi-1;
  	ins(nbi,nbi+needc);
  	//printf("key:%d nbi:%d needc:%d\n",key,nbi,needc);
  }
  int final=n+getg();
  //printf("final:%d getg:%d\n",final,getg());
  for (int ai=n;ai>=1;ai--) {
  	int key=vkey[0][ai];
  	int bi=-1,ci=-1,nbi=-1;
  	if (key!=0) {
  		bi=key2fi[1][key];
  		ci=key2fi[2][key];
  		if (bi==INF&&ci==INF) break;
  		sbi.insert(bi);
  		nbi=*(sbi.upper_bound(bi));
  		ins(nbi,nbi+ci);
  	}
  	int cand=getg()+ai-1;
  	//printf("ai:%d cand:%d key:%d bi:%d ci:%d nbi:%d\n",ai,cand,key,bi,ci,nbi);
  	chkmin(final,cand);
  }
  printf("%d\n",final);
}
