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
const int mn=1e5+2;
int inp[mn];
int s[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
	for (int i=0;i<n;i++) inp[i]=rint();
	int id=0;
	for (int i=0;i<n;i++) {
		int x=inp[i];
		if (x==1) s[i]=id++;
		else s[i]=s[i-x+1];
	}
	/* Manacher */
  vector<vector<int>> p(2,vector<int>(n,0));
  for(int z=0,l=0,r=0;z<2;z++,l=0,r=0)
      for(int i=0;i<n;i++)
      {
          if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
          int L=i-p[z][i], R=i+p[z][i]-!z;
          while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
          if(R>r) l=L,r=R;
      }
  for (int i=0;i<n;i++) printf("%d ",1+2*p[1][i]);
  printf("\n");
}
