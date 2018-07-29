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
typedef vector<int> vi;
bool solve(int xlim, int ylim, vector<string> s){
	int sz=xlim/2;
	for (int z=0;z<(1<<xlim);z++) {
		if (__builtin_popcount(z)!=sz) continue;
		for(int ex=0;ex<=xlim;ex++) {
			if (xlim%2==0 && ex!=xlim) continue;
			if ((1<<ex)&z) continue;
			vector<int> qvx,qox;
			for (int x=0;x<xlim;x++) {
				if (x==ex) continue;
				if (z&(1<<x)) qvx.PB(x);
				else qox.PB(x);
			}
			reverse(qox.begin(),qox.end());
			do {
				vector<int> vx=qvx,ox=qox;
				if (ex!=xlim) {
					vx.PB(ex); ox.PB(ex);
				}
				vector<string> a,b;
				for (int y=0;y<ylim;y++) {
					string got; got.resize(vx.size());
					for (int i=0;i<vx.size();i++) {
						//printf("i:%d vx:%d y:%d\n",i,vx[i],y); fflush(stdout);
						//assert(i<got.size());
						//assert(vx[i]<s.size());
						//assert(y<s[vx[i]].size());
						got[i]=s[vx[i]][y];
					}
					a.PB(got);
				}
				sort(a.begin(),a.end());
				for (int y=0;y<ylim;y++) {
					string got; got.resize(ox.size());
					for (int i=0;i<ox.size();i++) {
						got[i]=s[ox[i]][y];
					}
					b.PB(got);
				}
				sort(b.begin(),b.end());
				if (a==b) {
					//for (auto &w:vx) printf("%d ",w); printf("\n");
					//for (auto &w:a) printf("%s\n",w.c_str());
					//for (auto &w:ox) printf("%d ",w); printf("\n");
					//for (auto &w:b) printf("%s\n",w.c_str());
					return true;
				}
			} while(next_permutation(qvx.begin(),qvx.end()));
		}
	}
	return false;
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long H;
	long long W;
	cin>>H;
	vector<string> S(H-1+1);
	cin>>W;
	for(int i = 0 ; i <= H-1 ; i++){
		cin >> S[i];
	}
	bool ans=solve(H, W, S);
	if (ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}

