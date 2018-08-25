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
int negmemo[mc][mp];
int memo[mc][mp];
char p[mp];
// Walk the KMP DFA from state j with letter x
int dfa(int j, char x) {
  int oldj = j;
  int z = x - 'a';
  if (memo[z][j] != -1) {
    return memo[z][j];
  }
  while (j > 0 && x != p[j]) {
    j = fail[j];
  }
  j++;
  memo[z][oldj] = j;
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



class RmqSparseTable {

  int* logTable;
  int** rmq;
  int* a;
  int n;
  public:
  void init(int *_a, int _n) {
    a=_a;
    n=_n;

    logTable = new int[n + 1];
    fill(logTable,logTable+n+1,0);
    for (int i = 2; i <= n; i++)
      logTable[i] = logTable[i >> 1] + 1;

    rmq = new int*[logTable[n] + 1];
    for (int i=0;i<logTable[n] + 1;i++) {
      rmq[i]=new int[n];
    }
    for (int i = 0; i < n; ++i)
      rmq[0][i] = i;

    for (int k = 1; (1 << k) < n; ++k) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        int x = rmq[k - 1][i];
        int y = rmq[k - 1][i + (1 << k - 1)];
        rmq[k][i] = a[x] <= a[y] ? x : y;
      }
    }
  }

  int minPos(int i, int j) {
    int k = logTable[j - i];
    int x = rmq[k][i];
    int y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? x : y;
  }
  int minVal(int i, int j) {
    if (i>j) return INF;
    int k = logTable[j - i];
    int x = rmq[k][i];
    int y = rmq[k][j - (1 << k) + 1];
    return a[x] <= a[y] ? a[x] : a[y];
  }
};

RmqSparseTable sparse[mc][2];

const int ms=2004;
char s[ms];
typedef pair<int,int> pii;
pii flo[ms][ms];
pii fhi[ms][ms];
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
      flo[x][r].fst=-1;
      fhi[x][r].fst=-1;
    }
  }
  for (int c=0;c<26;c++) {
    for (int t=1;t<=m;t++) {
      memo[c][t]=dfa(t,c+'a');
      negmemo[c][t]=-memo[c][t];
    }
    sparse[c][0].init(memo[c],m+1);
    sparse[c][1].init(negmemo[c],m+1);
  }
  flo[0][0]=MP(0,-1);
  fhi[0][0]=MP(0,1);
  for (int x=0;x<n;x++) {
    for (int r=0;r<=n;r++) {
      assert(flo[x][r].fst==fhi[x][r].fst);
      if (flo[x][r].fst==-1) continue;
      chkmax(flo[x+1][r+1],flo[x][r]);
      chkmax(fhi[x+1][r+1],fhi[x][r]);
      int slo=-flo[x][r].snd,shi=fhi[x][r].snd;
      assert(slo>0&&shi>0);
      int c=s[x]-'a';
      int nslo=sparse[c][0].minVal(slo,shi);
      int nshi=-sparse[c][1].minVal(slo,shi);
      //printf("x:%d r:%d slo:%d shi:%d nslo:%d nshi:%d c:%c\n",x,r,slo,shi,nslo,nshi,(char)(c+'a'));
      {
        int occ=flo[x][r].fst;
        if (nslo==m+1) {occ++; nslo=1;}
        chkmax(flo[x+1][r],MP(occ,-nslo));
        chkmax(fhi[x+1][r],MP(occ,nslo));
      }
      {
        int occ=fhi[x][r].fst;
        if (nshi==m+1) {occ++; nshi=1;}
        chkmax(fhi[x+1][r],MP(occ,nshi));
        chkmax(flo[x+1][r],MP(occ,-nshi));
      }
    }
  }
  for (int r=0;r<=n;r++) {
    printf("%d ",flo[n][r].fst);
  }
  printf("\n");
}

