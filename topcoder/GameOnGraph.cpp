#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define UNDEF 9999999999LL
#define INF 99999999999LL
#define MAXN 32
bool g[MAXN][MAXN];
ll t[MAXN][MAXN];
bool seen[MAXN];
ll parent[MAXN];
ll n;
ll a[MAXN], acopy[MAXN];
vector<int> final;

void findtriangle() {
	for (ll x = 0; x < n; x++) {
		for (ll y = 0; y < n; y++) {
			t[x][y] = UNDEF;
		}
	}
	for (ll x = 0; x < n; x++) {
		for (ll y = 0; y < n; y++) {
			if (x==y) continue;
			for (ll z = 0; z < n; z++) {
				if (x==z || y==z) continue;
				if (g[x][z] && g[z][y] && g[y][x]) {
					////////printf("Triangle: %lld %lld %lld\n",x,y,z);
					t[x][z] = y;
					t[z][x] = MAXN+y;
				}
			}
		}
	}	
}

pair<bool, vector<ll> > shortestpath(ll initv, ll targetv) {
	for (ll x = 0; x < n; x++) {
		parent[x] = UNDEF;
	}
	queue<ll> q;
	q.push(initv);
	seen[initv] = true;
	bool found = false;
	while(!q.empty()) {
		ll x = q.front(); q.pop();
		if (x == targetv) {found = true; break;}
		for (ll y = 0; y < n; y++) {
			if (!seen[y] && g[y][x]) {
				seen[y] = true;
				parent[y] = x;
				q.push(y);
				if (y == targetv) {found = true; break;}
			}
		}
	}
	vector<ll> ans;
	if (!found) return MP(found, ans);
	ll v = targetv;
	while (v != initv) {
		ans.PB(v);
		v = parent[v];
	}
	reverse(ans.begin(), ans.end());
	return MP(found, ans);
}

void clearseen() {
	for (ll x = 0; x < n; x++) {seen[x] = false;}
}

void doit(ll w){
	final.PB(w);
	bool ok = false;
	for (ll q = 0; q < n; q++) {
		if (g[w][q] && a[q] == 0) {
			ok = true;
			swap(a[w],a[q]);
			break;
		}
	}
	////printf("%lld<->%lld : ",w,foundq);
	//for (ll x = 0; x < n; x++) {
	//	////printf("%lld ",a[x]);
	//}
	////printf("\n");
	assert(ok);
}

bool checkswap() {
	//printf("CHECKSWAP\n");
	for (ll x = 0; x < n; x++) {
		//printf("%lld ", a[x]);
	}
	//printf("\n");
	for (ll x = 0; x < n; x++) {
		//printf("%lld ", acopy[x]);
	}
	//printf("\n");
	for (ll x = 0; x < n; x++) {
		if(a[x] != acopy[x]) {
			return false;
		}
	}
	return true;
}

vector<vector<ll> > cycledecomp(vector<int> perm) {
	for (ll x = 0; x < n; x++) {seen[x] = false;}
	vector<vector<ll> > ans;
	for (ll x = 1; x < n; x++) {
		if (!seen[x]) {
			ll y = x;
			vector<ll> cand;
			while(!seen[y]) {
				seen[y] = true;
				cand.PB(y);
				y = perm[y];
			}
			ans.PB(cand);
		}
	}
	return ans;
}

bool checkcond(ll a1, ll a2, ll a3, ll b1, ll b2, ll b3) {
	return (a1 == a[b1]) && (a2 == a[b2]) && (a3 == a[b3]);
}
vector<ll> dp[MAXN][MAXN];
bool dpseen[MAXN][MAXN];
vector<ll> f(ll x, ll y) {
	if (dpseen[x][y]) return dp[x][y];
	dpseen[x][y] = true;
	vector<ll> ans;
	if (t[x][y] != UNDEF) {
		ans.PB(x);
	}
	else {
		ll best = INF;
		ll bestz = -1;
		for (ll z = 1; z < n; z++) {
			if (x==z || z==y) continue;
			vector<ll> ans1 = f(x,z);
			if (ans1.size() == 0) continue;
			vector<ll> ans2 = f(z,y);
			if (ans1.size() > 0 && ans2.size() > 0) {
				ll cand = ans1.size() + ans2.size();
				if (cand < best) {
					best = cand;
					bestz = z;
				}
			}
		}
		{
			ll z = bestz;
			assert(z!=-1);
			vector<ll> ans1 = f(x,z);
			vector<ll> ans2 = f(z,y);
			ans.insert(ans.end(), ans1.begin(), ans1.end());
			ans.insert(ans.end(), ans2.begin(), ans2.end());
		}
	}
	dp[x][y] = ans;
	return ans;
}

class GameOnGraph {
	public:
	vector <int> findSolution(vector <string> graph, vector <int> p) {
		n = graph.size();
		for (ll x = 0; x < n; x++) {
			for (ll y = 0; y < n; y++) {
				g[x][y] = (graph[x][y] == 'Y');
			}
		}
		// Scan for triangles
		findtriangle();
		for (ll x = 0; x < n; x++) {
			for (ll y = 0; y < n; y++) {
				dpseen[x][y] = false;
			}
		}
		vector<vector<ll> > cycles = cycledecomp(p);
		vector<pair<ll,ll> > swaps;
		for (auto& cycle: cycles) {
			if (cycle.size() == 1) continue;
			ll csz = cycle.size();
			ll best = INF;
			ll ginit = -1;
			for (ll init = 0; init < csz; init++) {
				bool good = true;
				ll cand = 0;
				for (ll i = 0; i < csz-1; i++) {
					ll x = cycle[(init+i)%csz];
					ll z = cycle[(init+i+1)%csz];
					bool ok = false;
					vector<ll> c = f(x,z);
					if (c.size() > 0) ok = true;
					cand += c.size();
					if(!ok) good = false;
				}
				if (good) {
					if (cand < best) {
						ginit = init;
						best = cand;
					}
				}
			}
			if (ginit == -1) assert(false);
			printf("best:%lld\n",best);
			for (ll i = 0; i < csz-1; i++) {
				ll x = cycle[(ginit+i)%csz];
				ll z = cycle[(ginit+i+1)%csz];
				vector<ll> c = f(x,z);
				assert(c.size() > 0);
				c.PB(z);
				for (ll k = 0; k <= c.size() - 2; k++) {
					swaps.PB(MP(c[k],c[k+1]));
					//printf("SwapA: %lld %lld\n",c[k],c[k+1]);
				}
				for (ll k = c.size() - 3; k >= 0; k--) {
					swaps.PB(MP(c[k],c[k+1]));
					//printf("SwapB: %lld %lld\n",c[k],c[k+1]);
				}
			}
		}
		for (ll x = 0; x < n; x++) {
			a[x] = x;
			acopy[x] = x;
		}
		// Checking swap
		for (auto& sw: swaps) {
			swap(acopy[sw.first], acopy[sw.second]);
		}
		for (ll x = 0; x < n; x++) {
			assert(acopy[x] == p[x]);
		}
		// Continue execution
		for (ll x = 0; x < n; x++) {
			a[x] = x;
			acopy[x] = x;
		}

		reverse(swaps.begin(), swaps.end());
		stack<pair<ll,ll> > swapstack;
		vector<pair<ll,ll> > testswap;
		for (auto& sw: swaps) {
			swapstack.push(sw);
		}
		while (!swapstack.empty()) {
			pair<ll,ll> sw = swapstack.top();
			swapstack.pop();
			ll x = sw.first; ll z = sw.second;
			assert(x!=0); assert(z!=0);
			ll y = t[x][z];
			if (y >= MAXN) {
				y -= MAXN; swap(x,z);
			}
			//printf("Swap x:%lld z:%lld using y:%lld\n",x,z,y);
			clearseen();
			seen[x] = true; seen[z] = true;
			pair<bool, vector<ll> > spt = shortestpath(0, y);
			bool reroute = false;
			if (spt.first) {
				////printf("Using E1\n");
				vector<ll> sp1 = spt.second;
				clearseen();
				vector<ll> sp2 = shortestpath(y,0).second;
				for (auto& w: sp1) {
					doit(w);
				}
				doit(z); doit(x); doit(y);
				for (auto& w: sp2) {
					doit(w);
				}
				//ll len = sp1.size() + sp2.size();
				////printf("len:%lld\n",len);
				swap(acopy[sw.first], acopy[sw.second]);
				while(1) {
					if (checkswap()) break;
					for (auto& w: sp1) {
						doit(w);
						if (checkswap()) break;
					}
					if (checkswap()) break;
					for (auto& w: sp2) {
						doit(w);
						if (checkswap()) break;
					}
					if (checkswap()) break;
				}
			}
			else {
				clearseen();
				seen[y] = true; seen[z] = true;
				pair<bool,vector<ll> > spt1 = shortestpath(0,x);
				if (!spt1.first) {
					//cout << "Reroute" << endl;
					//printf("Rerouting %lld %lld, %lld %lld, %lld %lld\n",y,z,x,y,y,z);
					swapstack.push(MP(y,z));
					swapstack.push(MP(x,y));
					swapstack.push(MP(y,z));
					reroute = true;
				}
				else {
					swap(acopy[sw.first], acopy[sw.second]);
					////printf("Using E2\n");
					clearseen();
					seen[x] = true; seen[z] = true;
					pair<bool,vector<ll> > spt2 = shortestpath(y,0);
					assert(spt2.first);
					vector<ll> sp1 = spt1.second;
					vector<ll> sp2 = spt2.second;
					//ll len = sp1.size() + sp2.size() + 1;
					//ll cnt = (len-1)*(len-1);
					//////printf("cnt:%lld\n",cnt);
					ll oldax = a[x]; ll olday = a[y];
					ll a1 = 0; ll b1 = x;
					ll a2 = a[x]; ll b2 = y;
					ll a3 = a[y]; ll b3 = sp2[0];
					while(1) {
						if (checkcond(a1,a2,a3,b1,b2,b3)) break;
						for (auto& w: sp1) {
							////printf("w:%lld\n",w);
							doit(w);
							if (checkcond(a1,a2,a3,b1,b2,b3)) break;
						}
						if (checkcond(a1,a2,a3,b1,b2,b3)) break;
						//////printf("%lld ",y);
						doit(y);
						if (checkcond(a1,a2,a3,b1,b2,b3)) break;
						for (auto& w: sp2) {
							//////printf("%lld ",w);
							doit(w);
							if (checkcond(a1,a2,a3,b1,b2,b3)) break;
						}
						if (checkcond(a1,a2,a3,b1,b2,b3)) break;
						//////printf("\n");
					}
					assert(checkcond(a1,a2,a3,b1,b2,b3));
					assert(a[x] == 0);
					assert(a[y] == oldax);
					assert(a[sp2[0]] == olday);
					doit(y);
					doit(z);
					doit(x);
					doit(y);
					for (auto& w: sp2) {
						doit(w);
					}
				}
			}
			if (!reroute) {
				assert(checkswap());
				testswap.PB(sw);
			}

		}
		{// Continue execution
		for (ll x = 0; x < n; x++) {
			a[x] = x;
			acopy[x] = x;
		}
		// Checking swap
		for (auto& sw: testswap) {
			swap(acopy[sw.first], acopy[sw.second]);
		}
		for (ll x = 0; x < n; x++) {
			assert(acopy[x] == p[x]);
		}
		// Continue execution
		for (ll x = 0; x < n; x++) {
			a[x] = x;
			acopy[x] = x;
		}}

		return final;
	}
};

bool check(vector <string> graph, vector <int> p, vector<int> ans) {
	assert(ans.size() <= 2500);
	n = p.size();
	for (ll x = 0; x < n; x++) {
		a[x] = x;
	}
	//////printf("Checker:\n");
	for (auto& x: ans) {
		bool ok = false;
		for (ll y = 0; y < n; y++) {
			if (graph[x][y] == 'Y' && a[y] == 0) {
				ok = true;
				swap(a[x],a[y]);
				//////printf("%d <-> %lld : ",x,y);
				break;
			}
		}
		for (ll i = 0; i < n; i++) {
			//////printf("%lld ",a[i]);
		}
		//////printf("\n");
		assert(ok);
	}
	bool good = true;
	for (ll x = 0; x < n; x++) {
		if (a[x] != p[x]) good = false;
	}
	cout << endl;
	return good;
}

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
		cout << "Testing GameOnGraph (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451282129;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GameOnGraph _obj;
		vector <int> _expected, _received;
		bool passed = false;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string graph[] = {"NYN",
				                  "NNY",
				                  "YNN"};
				int p[] = {0,2,1};
				int __expected[] = {2, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;
			}
			case 1:
			{
				string graph[] = {"NYN",
				                  "NNY",
				                  "YNN"};
				int p[] = {0,1,2};
				int __expected[] = {2, 1, 0, 2, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;
			}
			case 2:
			{
				string graph[] = {"NYYN",
				                  "NNYY",
				                  "NNNY",
				                  "YNNN"};
				int p[] = {0,3,2,1};
				int __expected[] = {3, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;
			}
			case 3:
			{
				string graph[] = {"NNYYNNNY",
				                  "YNYYNYYY",
				                  "NNNNYYNY",
				                  "NNYNYNYY",
				                  "YYNNNYNY",
				                  "YNNYNNNN",
				                  "YNYNYYNY",
				                  "NNNNNYNN"};
				int p[] = {0,1,4,5,2,3,6,7};
				int __expected[] = {4, 2, 0, 5, 2, 3, 5, 2, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;
			}
			case 4:
			{
				string graph[] = {"NNYYNNNY",
				                  "YNYYNYYY",
				                  "NNNNYYNY",
				                  "NNYNYNYY",
				                  "YYNNNYNY",
				                  "YNNYNNNN",
				                  "YNYNYYNY",
				                  "NNNNNYNN"};
				int p[] = {0,1,4,3,2,5,6,7};
				int __expected[] = {4, 2, 0, 5, 2, 3, 5, 2, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;
			}
			case 5:
			{
				string graph[] = {"NNYYNNNY",
				                  "YNYYNYYY",
				                  "NNNNYYNY",
				                  "NNYNYNYY",
				                  "YYNNNYNY",
				                  "YNNYNNNN",
				                  "YNYNYYNY",
				                  "NNNNNYNN"};
				int p[] = {0,1,2,5,4,3,6,7};
				int __expected[] = {4, 2, 0, 5, 2, 3, 5, 2, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;
			}
			case 6:
			{
				string graph[] = {"NNYNYNY", "YNNNYNY", "NYNNYNY", "YYYNYNY", "NNNNNNY", "YYYYYNN", "NNNNNYN"};
				int p[] = {0, 4, 1, 5, 3, 6, 2};
				int __expected[] = {1, 2, 5, 6, 4, 5, 6, 4, 0, 1, 2, 0, 1, 2, 5, 6, 4, 0, 1, 2, 0, 1, 2, 5, 6, 0, 1, 2, 0, 1, 2, 3, 5, 6, 3, 5, 6, 4, 0, 1, 2, 3, 5, 6, 4, 0, 1, 2, 3, 5, 6, 4, 0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;			}
			case 7:
			{
				string graph[] = {"NNYNYNY", "YNNNYNY", "NYNNYNY", "YYYNYNY", "NNNNNNY", "YYYYYNN", "NNNNNYN"};
				int p[] = {0, 6, 2, 3, 4, 5, 1};
				int __expected[] = {1, 2, 5, 6, 4, 5, 6, 4, 0, 1, 2, 0, 1, 2, 5, 6, 4, 0, 1, 2, 0, 1, 2, 5, 6, 0, 1, 2, 0, 1, 2, 3, 5, 6, 3, 5, 6, 4, 0, 1, 2, 3, 5, 6, 4, 0, 1, 2, 3, 5, 6, 4, 0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;
			}
			case 8:
			{
				string graph[] = {"NYYNNNNNYN", "NNYNNYYYNN", "NNNNYNYNYY", "YYYNNYYNYY", "YYNYNNNYYY", "YNYNYNYNYY", "YNNNYNNNNY", "YNYYNYYNNN", "NYNNNNYYNN", "YYNNNNNYYN"};
				int p[] = {0, 2, 1, 9, 8, 6, 3, 7, 5, 4};
				int __expected[] = {9, 3, 4, 6, 2, 5, 1, 8, 0, 3, 4, 6, 5, 1, 0, 9, 3, 4, 6, 3, 4, 6, 5, 7, 1, 8, 0, 3, 4, 6, 3, 4, 6, 5, 7, 1, 8, 0, 3, 4, 6, 3, 4, 6, 2, 5, 7, 1, 0, 9, 3, 4, 6, 2, 5, 1, 8, 0, 9, 3, 4, 6, 2, 5, 7, 1, 8, 0, 9, 3, 4, 6, 2, 5, 7, 1, 8, 0, 9, 3, 4, 6, 2, 5, 7, 1, 8, 0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;
			}
			case 9:
			{
				string graph[] = {"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNN", "YNNYNNNNNNNNNNNNNNNNNNNNNNNNNN", "YYNNYNNNNNNNNNNNNNNNNNNNNNNNNN", "YYYNNYNNNNNNNNNNNNNNNNNNNNNNNN", "YYYYNNYNNNNNNNNNNNNNNNNNNNNNNN", "YYYYYNNYNNNNNNNNNNNNNNNNNNNNNN", "YYYYYYNNYNNNNNNNNNNNNNNNNNNNNN", "YYYYYYYNNYNNNNNNNNNNNNNNNNNNNN", "YYYYYYYYNNYNNNNNNNNNNNNNNNNNNN", "YYYYYYYYYNNYNNNNNNNNNNNNNNNNNN", "YYYYYYYYYYNNYNNNNNNNNNNNNNNNNN", "YYYYYYYYYYYNNYNNNNNNNNNNNNNNNN", "YYYYYYYYYYYYNNYNNNNNNNNNNNNNNN", "YYYYYYYYYYYYYNNYNNNNNNNNNNNNNN", "YYYYYYYYYYYYYYNNYNNNNNNNNNNNNN", "YYYYYYYYYYYYYYYNNYNNNNNNNNNNNN", "YYYYYYYYYYYYYYYYNNYNNNNNNNNNNN", "YYYYYYYYYYYYYYYYYNNYNNNNNNNNNN", "YYYYYYYYYYYYYYYYYYNNYNNNNNNNNN", "YYYYYYYYYYYYYYYYYYYNNYNNNNNNNN", "YYYYYYYYYYYYYYYYYYYYNNYNNNNNNN", "YYYYYYYYYYYYYYYYYYYYYNNYNNNNNN", "YYYYYYYYYYYYYYYYYYYYYYNNYNNNNN", "YYYYYYYYYYYYYYYYYYYYYYYNNYNNNN", "YYYYYYYYYYYYYYYYYYYYYYYYNNYNNN", "YYYYYYYYYYYYYYYYYYYYYYYYYNNYNN", "YYYYYYYYYYYYYYYYYYYYYYYYYYNNYN", "YYYYYYYYYYYYYYYYYYYYYYYYYYYNNY", "YYYYYYYYYYYYYYYYYYYYYYYYYYYYNN"};
				int p[] = {0, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
				int __expected[] = {};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;
			}
			case 10:
			{
				string graph[] = {"NYYNNNNNYN", "NNYNNYYYNN", "NNNNYNYNYY", "YYYNNYYNYY", "YYNYNNNYYY", "YNYNYNYNYY", "YNNNYNNNNY", "YNYYNYYNNN", "NYNNNNYYNN", "YYNNNNNYYN"};
				int p[] = {0, 2, 1, 9, 8, 6, 3, 7, 5, 4};
				int __expected[] = {9, 3, 4, 6, 2, 5, 1, 8, 0, 3, 4, 6, 5, 1, 0, 9, 3, 4, 6, 3, 4, 6, 5, 7, 1, 8, 0, 3, 4, 6, 3, 4, 6, 5, 7, 1, 8, 0, 3, 4, 6, 3, 4, 6, 2, 5, 7, 1, 0, 9, 3, 4, 6, 2, 5, 1, 8, 0, 9, 3, 4, 6, 2, 5, 7, 1, 8, 0, 9, 3, 4, 6, 2, 5, 7, 1, 8, 0, 9, 3, 4, 6, 2, 5, 7, 1, 8, 0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)));
				passed = check(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int)), _received);
				break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (passed)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
