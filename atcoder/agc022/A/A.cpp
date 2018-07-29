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
const int mc=26;
void solve(string s){
	string ans;
	if (s=="zyxwvutsrqponmlkjihgfedcba") {
		ans="-1";
	}
	else if (s.length()<mc) {
		bitset<mc> used; used.reset();
		for (auto &w:s) used[w-'a']=true;
		int got=-1;
		for (int i=0;i<mc;i++) if (!used[i]) {got=i; break;}
		assert(got!=-1);
		char gotc=got+'a';
		ans=s+gotc;
	}
	else {
		assert(s.length()==mc);
		int got=0;
		for (int i=mc-2;i>=0;i--) {
			if (s[i]<s[i+1]) {
				got=i+1; break;
			}
		}
		assert(got!=0);
		//printf("got:%d %c\n",got,s[got-1]);
		bitset<mc> good; good.reset();
		for (int i=got;i<mc;i++) {
			good[s[i]-'a']=true;
		}
		int d=-1;
		for (int c=s[got-1]+1-'a';c<mc;c++) {
			if (good[c]) {d=c; break;}
		}
		assert(d!=-1);
		assert(d!=s[got-1]-'a');
		s[got-1]=d+'a';
		ans=s;
		ans.resize(got);
	}
	cout<<ans<<endl;
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	string S;
	cin >> S;
	solve(S);
	return 0;
}

