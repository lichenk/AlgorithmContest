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

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  string a,b;
	cin>>a>>b;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  int ai=0,bi=0;
  int n=a.length();
  int l=0,r=n-1;
  string ans; ans.resize(n);
  for (int p=0;p<n;p++) {
    if (0==(p&1)) {
      if (a[ai]<b[bi]) {
        ans[l++]=a[ai++];
      }
      else if (a[ai]==b[bi]) {
        if (rand()%2) ans[l++]=a[ai++];
        else ans[r--]=a[ai++];
      }
      else {
        ans[r--]=a[ai++];
      }
    }
    else {
      if (b[bi]>a[ai]) {
        ans[l++]=b[bi++];
      }
      else if (a[ai]==b[bi]) {
        if (rand()%2) ans[l++]=b[ai++];
        else ans[r--]=b[ai++];
      }
      else {
        ans[r--]=b[bi++];
      }
    }
  }
  cout<<ans<<endl;
}

