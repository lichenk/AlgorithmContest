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

class KMP {
// State starts with 0. State is equal to the number of chars in the prefix matched.
// If state = length of string, then it is fully matched.
// Supports further matching after fully matched. Matches may intersect.
// So if pattern = ABAB, and str = ABABAB, then there are 2 matches.
// http://codeforces.com/contest/346/submission/28895320
// http://codeforces.com/contest/346/submission/28895339
public:
  int *fail;
  int **memo;
  char *p;
  int gm;
  // Walk the KMP DFA from state j with letter x
  int dfa(int j, char x) {
    int oldj = j;
    int z = x - 'A';
    if (memo[z][j] != -1) {
      return memo[z][j];
    }
    ++j;
    while (j > 0 && x != p[j-1]) {
      j = fail[j];
    }
    memo[z][oldj] = j;
    return j;
  }
  
  // Build KMP failure table
  void buildfail()
  {
    int m=gm;
    int j = 0;
    for (int i = 1; i <= m; i++) {
      fail[i] = j;
      while (j > 0 && p[i-1] != p[j-1]) {
        j = fail[j];
      }
      j++;
    }
    fail[m+1] = j;
  }
  void initstr(string pattern) {
    int m=pattern.length();
    gm=m;
    p = new char[m+1];
    for (int i = 0; i < m; i++) p[i] = pattern[i];
    common_init();
  }
  void initchar_array(char *pattern, int m) {
    gm=m;
    p = pattern;
    common_init();
  }
  void common_init() {
    int m=gm;
    memo = new int*[26];
    for (int i = 0; i < 26; i++) {
      memo[i] = new int[m+2];
      memset(memo[i],-1,sizeof(int)*(m+2));
    }
    fail = new int[m+2];
    for (int i = 0; i <= m+1; i++) fail[i] = 0;
    buildfail();
  }
};


const int mn=104;
int f[mn][mn][mn];
string g[mn][mn][mn];
void gomax(int x, int y, int z, int len, string &s, char ch) {
  if (f[x][y][z]<len) {
    f[x][y][z]=len;
    if (ch) g[x][y][z]=s+ch;
    else g[x][y][z]=s;
  }
}
char vv[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s,t,v; cin>>s>>t>>v;
  KMP kmp;
  int xlim=s.length(),ylim=t.length(),zlim=v.length();
  for (int z=0;z<zlim;z++) vv[z]=v[z];
  kmp.initchar_array(vv,zlim);
  for (int x=0;x<=xlim;x++) for (int y=0;y<=ylim;y++) for (int z=0;z<zlim;z++) {
    int now=f[x][y][z];
    if (x<xlim&&y<ylim&&s[x]==t[y]) {
      char c=s[x];
      int nz=kmp.dfa(z,c);
      assert(nz<=zlim+1);
      gomax(x+1,y+1,nz,now+1,g[x][y][z],c);
    }
    gomax(x+1,y,z,now,g[x][y][z],0);
    gomax(x,y+1,z,now,g[x][y][z],0);
  }
  int ans=0;
  string sans;
  for (int z=0;z<zlim;z++) {
    if (ans<f[xlim][ylim][z]) {
      ans=f[xlim][ylim][z];
      sans=g[xlim][ylim][z];
    }
  }
  if (ans==0) printf("%d\n",ans);
  else printf("%s\n",sans.c_str());
}

