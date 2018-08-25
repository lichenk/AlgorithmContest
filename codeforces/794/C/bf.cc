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
string a,b; int n;
string f(string s, int p) {
  if (p==n) return s;
  string ans="";
  for (int x=0;x<n;x++) {
    if (s[x]=='?') {
      string ns=s;
      if (p%2==0) ns[x]=a[p/2];
      else ns[x]=b[p/2];
      string cand=f(ns,p+1);
      if (ans=="") ans=cand;
      else if (p%2==0) chkmin(ans,cand);
      else if (p%2==1) chkmax(ans,cand);
      else assert(0);
    }
  }
  return ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>a>>b;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  n=a.length();
  string inp; for (int i=0;i<n;i++) inp+="?";
  string ans=f(inp,0);
  cout<<ans<<endl;
}

