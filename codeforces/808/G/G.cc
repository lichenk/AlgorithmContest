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


int rint()
{
  int x; scanf("%d",&x); return x;
}

const int mp=1e5+2,mc=26;
int fail[mp];
int memo[mp][mc];
string p;
// Walk the KMP DFA from state j with letter x
int dfa(int oldk, char x) {
  int dpval=memo[oldk][x-'a'];
  if (dpval!=-1) return dpval;
  int k=oldk;
  int ans;
  if (p[k]==x) {
    ans=k+1;
  }
  else if (k==0) ans=0;
  else {
    ans=dfa(fail[k-1],x);
  }
  return memo[oldk][x-'a']=ans;
}
// Build KMP failure table
void buildfail(int m) {
  memset(memo,-1,sizeof memo);
  int k = 0;
  for (int i = 1; i < m; i++) {
    while (k > 0 && p[k] != p[i])
      k = fail[k - 1];
    if (p[k] == p[i])
      ++k;
    fail[i] = k;
    //printf("fail:%d %d\n",i,k);
  }
}

int f[2][mp];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s; cin>>s>>p;
  int m=p.length();
  buildfail(m);
  int n=s.length();
  memset(f[0],-1,(m+1)*sizeof(int));
  f[0][0]=0;
  int cur=0,nxt=1;
  //for (int y=0;y<=m;y++) {
  //  for (char c='a';c<='z';c++) {
  //    printf("y:%d c:%c ny:%d\n",y,c,dfa(y,c));
  //  }
  //}
  for (int x=0;x<n;x++) {
    memset(f[nxt],-1,(m+1)*sizeof(int));
    for (int y=0;y<=m;y++) {
      int occ=f[cur][y];
      if (occ==-1) continue;
      //printf("x:%d y:%d occ:%d\n",x,y,occ);
      if (s[x]=='?') {
        for (char c='a';c<='z';c++) {
          int ny=dfa(y,c);
          int nocc=occ;
          if (ny==m) nocc++;
          //printf("c:%c ny:%d nocc:%d m:%d\n",c,ny,nocc,m);
          chkmax(f[nxt][ny],nocc);
        }
      }
      else {
        int ny=dfa(y,s[x]);
        int nocc=occ;
        if (ny==m) nocc++;
        chkmax(f[nxt][ny],nocc);
      }
    }
    swap(cur,nxt);
  }
  int ans=0;
  for (int y=0;y<=m;y++) {
    chkmax(ans,f[cur][y]);
  }
  printf("%d\n",ans);
}

