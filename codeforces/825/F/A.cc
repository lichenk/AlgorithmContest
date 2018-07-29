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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const ll mod1=1000000033ll;
const ll mod2=1000000007ll;
const ll st1=47ll;
const ll st2=33ll;
const ll base=31;
const int mx=8e3+10;

int main() {
	srand(time(0));
	set<string> ss;
	map<ll,string> hs;
	int n=6;
	for (int k=0;;k++) {
		string s; s.resize(n);
		for (int i=0;i<n;i++) {
			s[i]=(rand()%26)+'a';
		}
		auto it=ss.find(s);
		if (it!=ss.end()) continue;
		ss.insert(s);
		ll has1=0,has2=0;
		for (int i=0;i<n;i++) {
			ll c=s[i]-'a'+1;
			has1=(has1*1ll*st1+c)%mod1;
			has2=(has2*1ll*st2+c)%mod2;
		}
		ll hi=(has1<<32)|has2;
		auto jt=hs.find(hi);
		if (jt!=hs.end()) {
			printf("%s\n%s\n",s.c_str(),jt->snd.c_str());
			exit(0);
		}
		hs[hi]=s;
		if (0==(k&0xffff)) printf("k:%d\n",k);
	}
}