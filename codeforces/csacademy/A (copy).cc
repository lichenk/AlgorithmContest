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
set<int> t[2*mn];
int segn;
void combine(set<int> &dest, set<int> &src) {
	for (auto &w:src) dest.insert(w);
}

void modify(int l, int r, int value) {
	int n=segn;
	r++;
	if (l>r) return;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++].insert(value);
    if (r&1) t[--r].insert(value);
  }
}

void push() {
	int n=segn;
  for (int i = 1; i < n; ++i) {
  	combine(t[i<<1], t[i]);
  	combine(t[i<<1|1], t[i]);
  }
}

int query(int p) {
	int n=segn;
	return t[n+p].size();
/*  set<int> res;
  for (p += n; p > 0; p >>= 1) combine(res, t[p]);
  return res.size();*/
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint(),m=rint();
	segn=m+1;
	for (int i=0;i<n;i++) {
		int l=rint(),r=rint(),a=rint();
		modify(l,r,a);
		modify(0,l-1,0);
		modify(r+1,m,0);
	}
	push();
	int final=0;
	for (int p=1;p<=n;p++) {
		chkmax(final,query(p));
	}
	printf("%d\n",final);
}

