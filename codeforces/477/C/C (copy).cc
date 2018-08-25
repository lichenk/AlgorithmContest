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
const int UNDEF = -1;
const int INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;


int rint()
{
  int x; scanf("%d",&x); return x;
}
const int mp=504,mc=26;
int fail[mp];
int memo[mp][mc];
char p[mp];
// Walk the KMP DFA from state j with letter x
int dfa(int j, char x) {
  int oldj = j;
  int z = x - 'a';
  if (memo[j][z] != -1) {
    return memo[j][z];
  }
  while (j > 0 && x != p[j]) {
    j = fail[j];
  }
  j++;
  memo[oldj][z] = j;
  return j;
}

// Build KMP failure table
void buildfail(int m)
{
  memset(memo,-1,sizeof memo);
  int j = 0;
  for (int i = 1; i <= m; i++) {
    fail[i] = j;
    while (j > 0 && p[i] != p[j]) {
      j = fail[j];
    }
    j++;
  }
  fail[m+1] = j;
}
const int ms=2004;
char s[ms];
typedef pair<int,int> pii;
pii f[ms][ms];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%s\n%s\n",s,p);
  int m=strlen(p);
  for (ll i = m-1; i>=0;i--) {p[i+1] = p[i];}
	p[0] = '$';
  buildfail(m);
  int n=strlen(s);
  for (int x=0;x<=n;x++) {
    for (int r=0;r<=n;r++) {
      f[x][r].fst=-1;
    }
  }
  f[0][0]=MP(0,1);
  for (int x=0;x<n;x++) {
    for (int r=0;r<=n;r++) {
      pii now=f[x][r];
      if (now.fst==-1) continue;
      chkmax(f[x+1][r+1],now);
      int occ=now.fst;
      int newstate=dfa(now.snd,s[x]);
      if (newstate==m+1) {occ++; newstate=1;}
      //printf("%c (%d,%d) -> (%d,%d)\n",s[x],now.fst,now.snd,occ,newstate);
      chkmax(f[x+1][r], MP(occ,newstate));
    }
  }
  for (int r=0;r<=n;r++) {
    printf("%d ",f[n][r].fst);
  }
  printf("\n");
}

