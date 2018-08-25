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
  int n=a.length();
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  a.resize((n+1)/2); b.resize(n/2);
  int al=0,bl=0;
  int ar=a.size()-1,br=b.size()-1;
  int l=0,r=n-1;
  string ans; ans.resize(n);
  for (int p=0;p<n;p++) {
    if (0==(p&1)) {
      if (a[al]<b[bl]) {
        ans[l++]=a[al++];
      }
      else if (a[al]==b[bl]) {
        ans[r--]=a[ar--];
      }
      else {
        ans[r--]=a[ar--];
      }
    }
    else {
      if (b[bl]>a[al]) {
        ans[l++]=b[bl++];
      }
      else if (b[bl]==a[al]) {
        ans[r--]=b[br--];
      }
      else {
        ans[r--]=b[br--];
      }
    }
  }
  cout<<ans<<endl;
}

