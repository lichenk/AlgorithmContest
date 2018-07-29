#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
vector<string> g;
const ll mn=55;
bool used[mn][mn];
vector<ll> resbfs;
ll n;
ll dist[mn],par[mn];
vector<ll> h[mn];
void buildgraph() {
	for (ll x=0;x<n;x++) {
		h[x].clear();
		for (ll y=0;y<n;y++) {
			if (g[x][y]=='Y'&&!used[x][y]) {
				h[x].PB(y);
			}
		}
	}
}
ll bfs(ll init, ll dest, bool go) {
	for (ll x=0;x<n;x++) dist[x]=INF;
	queue<ll> q;
	for (auto &y:h[init]) {
		{
			if (dist[y]==INF) {
				dist[y]=1;
				par[y]=init;
				q.push(y);
			}
		}
	}
	while(!q.empty()) {
		ll x=q.front(); q.pop();
		for (auto &y:h[x]) {
			{
				if (dist[y]==INF) {
					dist[y]=dist[x]+1;
					par[y]=x;
					q.push(y);
				}
			}
		}
	}
	if (go) {
		resbfs.clear();
		ll x=dest;
		ll y=par[dest];
		resbfs.PB(x);resbfs.PB(y);
		while(y!=init) {
			x=par[x]; y=par[y];
			resbfs.PB(y);
		}
		//resbfs.PB(init);
		reverse(resbfs.begin(),resbfs.end());
		/*for (auto &w:resbfs) {
			printf("%d->%d got %d\n",init,dest,w);
		}*/
	}
	//printf("Bfs %d %d got %lld\n",init,dest,dist[dest]);
	return dist[dest];
}
bool active[mn];
ll dp[mn][mn];
class GogoXMarisaKirisima {
	public:
	int solve(vector <string> choices) {
		g=choices;
		n=g.size();
		for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) used[x][y]=false;
		for (ll x=0;x<n;x++) active[x]=false;
		active[0]=true;active[n-1]=true;
		ll ans=0;
		bool isfst=true;
		while(1) {
			buildgraph();
			pair<ll,pair<ll,ll> > best=MP(INF,MP(INF,INF));
			if (isfst) {
				best=MP(bfs(0,n-1,false),MP(0ll,n-1));
			}
			else {
				for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) dp[x][y]=INF;
				//for (ll v=0;v<n;v++) dp[v][v]=0;
				for (ll x=0;x<n;x++) for (auto &y:h[x]) dp[x][y]=1;
				for (ll k=0;k<n;k++) for (ll i=0;i<n;i++) for (ll j=0;j<n;j++) {
					chkmin(dp[i][j],dp[i][k]+dp[k][j]);
				}
				for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) {
					if (active[x]&&active[y]) {
						pair<ll,pair<ll,ll> > cand=MP(dp[x][y],MP(x,y));
						chkmin(best,cand);
					}
				}
			}
			//printf("%d->%d\n",x,y)
			if (best.first>=INF) break;
			{
				ll x=best.second.first,y=best.second.second;
				//printf("%d->%d\n",x,y);
				bfs(x,y,true);
				ll k=resbfs.size();
				for (ll i=0;i<k-1;i++) {
					ll a=resbfs[i],b=resbfs[i+1];
					used[a][b]=true;
					active[a]=true;
					active[b]=true;
				}
			}
			ans++;
			isfst=false;
		}
		return ans;
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
		cout << "Testing GogoXMarisaKirisima (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472015412;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GogoXMarisaKirisima _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string choices[] = {"NYN"
				                   ,"YNY"
				                   ,"NNN"};
				_expected = 2;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 1:
			{
				string choices[] = {"NNY"
				                   ,"YNY"
				                   ,"YNN"};
				_expected = 2;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 2:
			{
				string choices[] = {"NN"
				                   ,"NN"};
				_expected = 0;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 3:
			{
				string choices[] = {"NYYY"
				                   ,"NNNY"
				                   ,"NNNY"
				                   ,"NNNN"};
				_expected = 3;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 4:
			{
				string choices[] = {"NNYYNNYNYYNNYNYYYYNNNYYYNNNNYYNYNNNYYNNYNNNNNYNNNN", "NNNNNYNNYNNYYNYNNNNYNYNNYNYNNNYYYYNNYNYYNNYYYNNYNN", "NNNYYYYNNNNNNNYYNYYYYNYNNYNNNNNNYNYYNYNNNYYNNNNYYN", "NNNNYNYYYYNYNYYNNNYNYNYYNNYNNNYNNNNYNYNYYNNYNYNNNN", "NNNNNYNYNYNYNYNYYYYNYNNNYYNNNYNNYNNNYYNNNNNNYNYNYY", "NNNNNNYYYYNNYYNYYNNYYNNYNNYNYNNYNNNNYYNYNYNYYNNNNN", "NNNNNNNNNNNNNYNNYNYYNNYNYYNYYNYNNYYNNYYNYNYYYYNNYN", "NNNNNNNNNYNYYYNYYNNYNNYNYNNYYNYYYNYNNNNYNNNNNYYYNY", "NNNNNNNNNNYNYYNYNNNNYNYNNYNNNYYYNNNYYYYNNNYYYYNNYY", "NNNNNNNNNNNNYNYNYNNYNNNYNYNYNNYYYNYYYYYNNNYNYNNYYY", "NNNNNNNNNNNNYYNYNYNNNNNYYYYYNYNNYYNYNYNYNNNYYNYYNY", "NNNNNNNNNNNNYYNNYNYNYNYNNYYYNNYYYNNYNNYYYNYYNNYYNN", "NNNNNNNNNNNNNNYYYNYYNNNYYYNYNNYYYNNYYYNYYYNNYNYNNN", "NNNNNNNNNNNNNNYNNNNYYYYNYYYYNYYYYYYNNNNNYNNYYYNNYN", "NNNNNNNNNNNNNNNYNNYNYYYYNYYYYNYNNNNYYNYNNNNYYNYYYY", "NNNNNNNNNNNNNNNNYYYNNNYYYNYYYYYYYNNYNNNYYYYYNNNYNN", "NNNNNNNNNNNNNNNNNYYNNNYYYYYYNNNYYYYNYYYYYYYNNNNYNN", "NNNNNNNNNNNNNNNNNNYYYYYNYNNYYNYYNNNNYYYYNYNYYNYYNY", "NNNNNNNNNNNNNNNNNNNNYNYNYYYYNYNNYNYNYYYYYNNYYYNYYY", "NNNNNNNNNNNNNNNNNNNNYYYNNNYNYYYNYYYNYNNYYYNYYYYYNY", "NNNNNNNNNNNNNNNNNNNNNYNNNYNYYYYNYNYYNYYYYYYYYYNYNY", "NNNNNNNNNNNNNNNNNNNNNNYNNYYYYYYYYYNNYYNYNNNYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNYYYYNYNNYNYYNYYYNYYYNYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNYYNYYYYNNYYYNYNYYYYYNYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNYNYNNYYYYYYYYYYYYYNYYNYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYNYYYYYYYNYYYYNYN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYNYYNYYYYYYYYYYYNY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYNYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYNYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN"};
				_expected = 723;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			case 5:
			{
				string choices[] = {"NYNNYYYYYYYNYYYYYYYYYYYYNYYYNNYYNNYYNYYNYYYYYYYYNN", "NNYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNNYNNNNNNNYNNNNNNNNNNNNYNNNYYNNYYNNYNNYNNNNNNNNYY", "NNYNNNNNNNNYNNNNNNNNNNNNYNNNYYNNYYNNYNNYNNNNNNNNYY", "NYYYNYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYNYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYNYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYNYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYNYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYNYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYNYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNYYNNNNNNNNNNNNNNNNNNNNYNNNYYNNYYNNYNNYNNNNNNNNYY", "NYYYYYYYYYYYNYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYNYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYNYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYNYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYNYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYYNYYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYYYNYYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYYYYNYYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYYYYYYNNYYYYYYYYYYYYYYYYYYYYYYYYYYY", "YYNNYYYYYYYNYYYYYYYYYYNYNYYYNNYYNNYYNYYNYYYYYYYYNN", "NYYYYYYYYYYYYYYYYYYYYYNNYYYYYYYYYYYYYYYYYYYYYYYYYY", "NNYYNNNNNNNYNNNNNNNNNNNNNNNNYYNNYYNNYNNYNNNNNNNNYY", "NYYYYYYYYYYYYYYYYYYYYYNYYNYYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYNYYYYYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYNYYYYYYYYYYYYYYYYYYYYYY", "NNYYNNNNNNNYNNNNNNNNNNNNYNNNNYNNYYNNYNNYNNNNNNNNYY", "NNYYNNNNNNNYNNNNNNNNNNNNYNNNYNNNYYNNYNNYNNNNNNNNYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYNYYYYYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYNYYYYYYYYYYYYYYYYYY", "NNYYNNNNNNNYNNNNNNNNNNNNYNNNYYNNNYNNYNNYNNNNNNNNYY", "NNYYNNNNNNNYNNNNNNNNNNNNYNNNYYNNYNNNYNNYNNNNNNNNYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYNYYYYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYNYYYYYYYYYYYYYY", "NNYYNNNNNNNYNNNNNNNNNNNNYNNNYYNNYYNNNNNYNNNNNNNNYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYNYYYYYYYYYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYNYYYYYYYYYYY", "NNYYNNNNNNNYNNNNNNNNNNNNYNNNYYNNYYNNYNNNNNNNNNNNYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYNYYYYYYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYNYYYYYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYNYYYYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYNYYYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYNYYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYNYYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYNYYY", "NYYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYYYYYYYYYYYNYY", "NNYYNNNNNNNYNNNNNNNNNNNNYNNNYYNNYYNNYNNYNNNNNNNNNY", "NNYYNNNNNNNYNNNNNNNNNNNNYNNNYYNNYYNNYNNYNNNNNNNNYN"};
				_expected = 1850;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}
			/*case 6:
			{
				string choices[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(choices, choices+sizeof(choices)/sizeof(string))); break;
			}*/
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
