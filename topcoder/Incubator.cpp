#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const char UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll MAXZ=1LL<<25LL;
char dp[MAXZ];
const ll MAXN=50;
vector<ll> ch[MAXN];
bool topsort_valid[MAXN],self[MAXN];
char solve(ll z) {
	ll origz=z;
	if (z<MAXZ&&dp[z]!=UNDEF) return dp[z];
	ll x=63-__builtin_clzll(z);
	char ans;
	if (self[x]) {
		z&=~(1LL<<x);
		ans=solve(z);
	}
	else if (ch[x].size()==0) {
		z&=~(1LL<<x);
		ans=1+solve(z);
	}
	else if (ch[x].size()==1) {
		z&=~(1LL<<x);
		z&=~(1LL<<ch[x][0]);
		ans=1+solve(z);
		//////printf("origz:%lld Zero out bit %lld %lld. Query %lld to get %lld.\n",origz,x,ch[x][0],z,ans);
	}
	else {
		ll zno=z;
		zno&=~(1LL<<x);
		ll zyes=z;
		zyes&=~(1LL<<x);
		for (auto &w:ch[x]) {
			zyes&=~(1LL<<w);
		}
		ans=max((int)solve(zno),1+solve(zyes));
	}
	if (origz<MAXZ) dp[origz]=ans;
	//////printf("origz:%lld ans:%d\n",origz,ans);
	return ans;
}

ll n;
ll g[MAXN],h[MAXN];
ll seen;
ll cycle_internal;
stack<ll> STK;
ll cycle_ans;
bool findcycle(ll x) {
	if (cycle_internal&(1LL<<x)) {
		cycle_ans=0;
		while(!STK.empty()) {
			ll tp=STK.top();
			//printf("tp:%lld\n",tp);
			STK.pop();
			cycle_ans|=1LL<<tp;
			if (tp==x) break;
		}
		while(!STK.empty()) STK.pop();
		return true;
	}
	if (seen&(1LL<<x)) return false;
	STK.push(x); cycle_internal|=1LL<<x; seen|=1LL<<x;
	for (ll w=0;w<n;w++) {
		if (g[x]&(1LL<<w)&&x!=w) {
			//printf("%lld->%lld, ",w,x);
			if(findcycle(w)) return true;
		}
	}
	STK.pop();
	cycle_internal&=~(1LL<<x);
	return false;
}
bool contract() {
	for (ll vv=0;vv<n;vv++) {
		cycle_internal=0;
		cycle_ans=0;
		seen=0;
		//printf("Trying vv:%lld\n",vv);
		bool hasc=findcycle(vv);
		if (hasc) {
			ll rep=__builtin_ffsll(cycle_ans)-1;
			for (ll x=0;x<n;x++) {
				if (cycle_ans&(1LL<<x)) {
					//printf("%lld, ",x);
				}
			}
			//printf("\n");
			for (ll x=0;x<n;x++) {
				if (cycle_ans&(1LL<<x) && x!=rep) {
					topsort_valid[x]=false;
				}
			}
			//printf("Cycle: %lld. Rep:%lld\n",cycle_ans,rep);
			for (ll x=0;x<n;x++) h[x]=0;
			for (ll x=0;x<n;x++) {
				ll nx=(cycle_ans&(1LL<<x))?rep:x;
				for (ll w=0;w<n;w++) {
					ll nw=(cycle_ans&(1LL<<w))?rep:w;
					if ((g[x]&(1LL<<w))) {
						////printf("%lld->%lld\n",nx,nw);
						h[nx]|=(1LL<<nw);
					}
				}
			}
			for (ll x=0;x<n;x++) g[x]=h[x];
			return true;
		}
	}
	return false;
}

vector<int> topsort_g[MAXN];
bool topsort_used[MAXN];
vector<int> topsort_ans;

void dfs (int v) {
	////////printf("dfs v:%d\n",v);
	topsort_used[v] = true;
	for (size_t i=0; i<topsort_g[v].size(); ++i) {
		int to = topsort_g[v][i];
		if (!topsort_used[to])
			dfs (to);
	}
	topsort_ans.push_back (v);
}
 
void topological_sort(ll n) {
	for (int i=0; i<n; ++i) {
		topsort_used[i] = false;
	}
	topsort_ans.clear();
	for (int i=0; i<n; ++i){
		if (!topsort_valid[i]) continue;
		if (!topsort_used[i]){
			dfs(i);
		}
	}
	reverse (topsort_ans.begin(), topsort_ans.end());
}
ll canreach(ll x) {
	if (seen&(1LL<<x)) return 1LL<<x;
	seen|=1LL<<x;
	ll ans=0;
	for (ll w=0;w<n;w++) {
		if (g[x]&(1LL<<w)) {
			ans|=1LL<<w;
			ans|=canreach(w);
		}
	}
	return ans;
}
class Incubator {
	public:
	int maxMagicalGirls(vector <string> love) {
		n=love.size();
		for (ll x=0;x<n;x++) {
			ll msk=0;
			for (ll y=0;y<n;y++) {
				if(love[x][y]=='Y') {
					////printf("%lld->%lld\n",x,y);
					msk|=1LL<<y;
				}
			}
			g[x]=msk;
		}
		//printf("\n\n");
		for (ll x=0;x<n;x++) topsort_valid[x]=true;
		while(contract());
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<n;y++) {
				if (g[x]&(1LL<<y)) {
					////////printf("%lld->%lld\n",x,y);
					topsort_g[x].PB(y);
				}
			}
		}
		topological_sort(n);
		//return -12345;
		reverse (topsort_ans.begin(), topsort_ans.end());
		map<ll,ll> mapping;
		for (ll i=0;i<topsort_ans.size();i++) {
			////////printf("topsort: %d:%d\n",i,topsort_ans[i]);
			mapping[topsort_ans[i]]=i;
		}
		//printf("topsort size:%lld. %d\n",topsort_ans.size(),topsort_valid[n-1]);
		for (ll x=0;x<n;x++) self[x]=false;
		for (ll x=0;x<n;x++) {
			if (mapping.find(x)==mapping.end()) continue;
			seen=0;
			ll cr=canreach(x);
			for (ll y=0;y<n;y++) {
				if (cr&(1LL<<y)) {
					//printf("child: %lld->%lld\n",mapping[x],mapping[y]);
					ch[mapping[x]].PB(mapping[y]);
					if (x==y) {
						self[mapping[x]]=true;
						//////printf("self: %d\n",mapping[x]);
					}
				}
			}
		}
		for (ll z=1;z<MAXZ;z++) {
			dp[z]=UNDEF;
		}
		dp[0]=0;
		//////printf("Query: %lld\n",(1LL<<(topsort_ans.size()))-1);
		return solve((1LL<<(topsort_ans.size()))-1);
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing Incubator (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1467583642;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Incubator _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string love[] = {"NY","NN"};
				_expected = 1;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			case 1:
			{
				string love[] = {"NYN", "NNY", "NNN"};
				_expected = 1;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			case 2:
			{
				string love[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"};
				_expected = 2;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			case 3:
			{
				string love[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"};
				_expected = 2;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			case 4:
			{
				string love[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
				_expected = 5;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			case 5:
			{
				string love[] = {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"};
				_expected = 2;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			case 6:
			{
				string love[] = {"Y"};
				_expected = 0;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			case 7:
			{
				string love[] = {
					"NYNN",
					"NNYN",
					"YNNN",
					"NNNN",
				};
				_expected = 1;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			case 8:
			{
				string love[] = {"NNNYNNY", "NYNNYNN", "NNYNYNN", "NYNNNNN", "NNNNNNY", "NNNYNYN", "NNNNNNN"};
				_expected = 1;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			case 9:
			{
				string love[] = {"NYNYNNNNNN", "NNNNNYNNNN", "NNYYNNNNYY", "NNYNNNNNNN", "YYNNYNNYNY", "NNNNNNNNYN", "NYYNYNNNNN", "NYNNNYNYYN", "NYNNNYNNNY", "YYYYNNNNNN"};
				_expected = 1;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			case 10:
			{
				string love[] = {"NYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN"};
				_expected = 1;
				_received = _obj.maxMagicalGirls(vector <string>(love, love+sizeof(love)/sizeof(string))); break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
