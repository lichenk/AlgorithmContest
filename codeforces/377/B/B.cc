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

int rint()
{
  int x; scanf("%d",&x); return x;
}
char rch()
{
  char x; scanf("%c",&x); return x;
}
const int mn=1e5+4;
int ns,nb,passlim;
pair<int,int> vbug[mn];
pair<int,int> vstu[mn];
int vpass[mn];
bool f(int days) {
  int passrem=passlim;
  int sidx=0;
  map<int,int> h;
  for (int bug=0;bug<nb;bug+=days) {
    //printf("days:%d bug:%d\n",days,bug);
    int diff=vbug[bug].fst;
    //printf("vst:%d %d\n",vstu[sidx].fst,vstu[sidx].snd);
    while(sidx<ns&&vstu[sidx].fst>=diff) {
      int x=vstu[sidx].snd;
      //printf("Stu:%d\n",x);
      h[vpass[x]]++;
      sidx++;
    }
    //printf("Meow\n");
    auto it=h.begin();
    if (it==h.end()) return false;
    //printf("Use:%d\n",it->fst);
    passrem-=it->fst;
    if (passrem<0) return false;
    if (it->snd==1) h.erase(it);
    else it->snd--;
  }
  return true;
}
int vans[mn];
void g(int days) {
  int passrem=passlim;
  int sidx=0;
  map<int,vector<int> > h;
  for (int bug=0;bug<nb;bug+=days) {
    //printf("days:%d bug:%d\n",days,bug);
    int diff=vbug[bug].fst;
    //printf("vst:%d %d\n",vstu[sidx].fst,vstu[sidx].snd);
    while(sidx<ns&&vstu[sidx].fst>=diff) {
      int x=vstu[sidx].snd;
      //printf("Stu:%d\n",x);
      h[vpass[x]].PB(x);
      sidx++;
    }
    //printf("Meow\n");
    auto it=h.begin();
    passrem-=it->fst;
    int ans=it->snd.back();
    int mk=min(nb,bug+days);
    for (int k=bug;k<mk;k++) vans[vbug[k].snd]=ans;
    if (it->snd.size()==1) h.erase(it);
    else it->snd.pop_back();
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ns=rint();nb=rint();passlim=rint();
  for (int x=0;x<nb;x++) vbug[x]=MP(rint(),x);
  sort(vbug,vbug+nb,greater<pii>());
  for (int x=0;x<ns;x++) vstu[x]=MP(rint(),x);
  sort(vstu,vstu+ns,greater<pii>());
  for (int x=0;x<ns;x++) vpass[x]=rint();
  int imin=1,imax=nb+1;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (!f(imid)) imin=imid+1;
    else imax=imid;
  }
  if (imin==nb+1) {
    printf("NO\n");
  }
  else {
    printf("YES\n");
    g(imin);
    for (int x=0;x<nb;x++) printf("%d ",vans[x]+1);
    printf("\n");
  }
}