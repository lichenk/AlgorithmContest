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
inline ll MK(int x, int y) {
	return (((ll)x)<<32)|y;
}

const int mn=200000;


int *p2m[mn];
int p2msz[mn];

const int mp=237718814;
ll prealloc[mp];
int preallocsz=0;

ll *precompute_request[mn];
int precompute_request_sz[mn];
vector<int> precompute_result;
int precompute_id;
void do_precompute(int n) {
	precompute_result.resize(precompute_id);
	for (int p=0;p<n;p++) {
		sort(precompute_request[p],precompute_request[p]+precompute_request_sz[p]);
		int idx=0;
		int maxidx=p2msz[p];
		int psz=precompute_request_sz[p];
		for (int i=0;i<psz;i++) {
			auto &request=precompute_request[p][i];
			int wantx=request>>32, request_id=request&0xffffffff;
			while(idx<maxidx&&p2m[p][idx]<wantx) idx++;
			//printf("p:%d x:%d idx:%d p2m:%d maxidx:%d\n",p,wantx,idx,p2m[p][idx],maxidx);
			precompute_result[request_id]=idx;
		}
	}
}
void cntask(int p, int x) {
	precompute_request_sz[p]++;
}
void fakeask(int p, int x) {
	precompute_request[p][precompute_request_sz[p]++]=MK(x,precompute_id++);
}
int ask(int p, int x) {
	return precompute_result[precompute_id++];
}
int mo_left,mo_right;
#define cntrm cntins
void cntins(int p) {
	cntask(p,mo_right+1);
	cntask(p,mo_left);
}
#define fakerm fakeins
void fakeins(int p) {
	fakeask(p,mo_right+1);
	fakeask(p,mo_left);
}
ll live=0;
void ins(int p) {
  int got=ask(p,mo_right+1);
  got-=   ask(p,mo_left);
  live+=got;
}
void rm(int p) {
  int got=ask(p,mo_right+1);
  got-=ask(p,mo_left);
  live-=got;
}
const int blk=sqrt(mn);
bool cmp(const pair<pii, int> &x, const pair<pii, int> &y) {
  int l1=x.first.first/blk,l2=y.first.first/blk;
  int r1=x.first.second,r2=y.first.second;
  return (l1<l2)||(l1==l2&&r1<r2);
}
void do_mo_algorithm(int interval_n, int qn, pair<pii,int> *q, ll*vans) {
  sort(q,q+qn,cmp);
  precompute_id=0,mo_left=0,mo_right=-1,live=0;
  for (int i=0;i<qn;i++) {
    int L=q[i].first.first,R=q[i].first.second;
    while(mo_right<R) cntins(mo_right+1),mo_right++;
    while(mo_right>R) cntrm (mo_right),mo_right--;
    while(mo_left>L)  cntins(mo_left-1),mo_left--;
    while(mo_left<L)  cntrm (mo_left),mo_left++;
  }
  for (int p=0;p<interval_n;p++) {
  	precompute_request[p] = prealloc+preallocsz;
  	preallocsz+=precompute_request_sz[p];
  }
  memset(precompute_request_sz,0,sizeof precompute_request_sz);
  precompute_id=0,mo_left=0,mo_right=-1,live=0;
  for (int i=0;i<qn;i++) {
    int L=q[i].first.first,R=q[i].first.second;
    while(mo_right<R) fakeins(mo_right+1),mo_right++;
    while(mo_right>R) fakerm (mo_right),mo_right--;
    while(mo_left>L)  fakeins(mo_left-1),mo_left--;
    while(mo_left<L)  fakerm (mo_left),mo_left++;
  }
  do_precompute(interval_n);
  precompute_id=0,mo_left=0,mo_right=-1,live=0;
  for (int i=0;i<qn;i++) {
    int L=q[i].first.first,R=q[i].first.second;
    while(mo_right<R) ins(mo_right+1),mo_right++;
    while(mo_right>R) rm(mo_right),mo_right--;
    while(mo_left>L) ins(mo_left-1),mo_left--;
    while(mo_left<L) rm(mo_left),mo_left++;
    int qi=q[i].snd;
    vans[qi]=live+R-L+1;
  }
}






const int mh=4544226;
int _prealloc[mh];
int _preallocsz=0;
pair<pii, int> q[mn];
int p2v[mn];
int v2p[mn+1];
ll vans[mn];
int tmp[mn+1];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),qn=rint();
  memset(v2p,-1,sizeof v2p);
  for (int p=0;p<n;p++) {
    int v=rint();
    p2v[p]=v;
    v2p[v]=p;
  }
  for (int x=1;x<=n;x++) {
    for (int y=x+x;y<=n;y+=x) tmp[y]++;
  }
  for (int p=0;p<n;p++) {
    int v=p2v[p];
    p2m[p]=_prealloc+_preallocsz;
    _preallocsz += tmp[v] + n/v - 1;
  }
  for (int p=0;p<n;p++) {
    int v=p2v[p];
    _preallocsz += n/v;
    for (int x=v+v;x<=n;x+=v) {
      int posx=v2p[x];
      if (posx!=-1) {
        p2m[p][p2msz[p]++]=posx;
        p2m[posx][p2msz[posx]++]=p;
      }
    }
  }
  for (int p=0;p<n;p++) {
    sort(p2m[p],p2m[p]+p2msz[p]);
  }
  for (int qi=0;qi<qn;qi++) {
    int L=rint()-1,R=rint()-1;
    q[qi]=MP(MP(L,R),qi);
  }
  do_mo_algorithm(n,qn,q, vans);
  for (int qi=0;qi<qn;qi++) {
    printf("%lld\n",vans[qi]);
  }
}

