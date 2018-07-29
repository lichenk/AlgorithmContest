#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define UNDEF 9999999999LL
#define MAXN 32
bool g[MAXN][MAXN];
ll t[MAXN][MAXN];
bool seen[MAXN];
ll parent[MAXN];
vector<ll> fromzero[MAXN], tozero[MAXN];
ll n;

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
				if (g[x][y] && g[y][z] && g[z][x]) {
					printf("Triangle: %lld %lld %lld\n",x,y,z);
					t[x][z] = y;
					t[z][x] = MAXN+y;
				}
			}
		}
	}	
}

vector<ll> shortestpath(ll initv, ll targetv) {
	for (ll x = 0; x < n; x++) {
		seen[x] = false;
		parent[x] = UNDEF;
	}
	queue<ll> q;
	q.push(initv);
	seen[initv] = true;
	while(!q.empty()) {
		ll x = q.front(); q.pop();
		for (ll y = 0; y < n; y++) {
			if (!seen[y] && g[y][x]) {
				seen[y] = true;
				parent[y] = x;
				q.push(y);
				if (y == targetv) break;
			}
		}
	}
	vector<ll> ans;
	ll v = targetv;
	while (v != initv) {
		ans.PB(v);
		v = parent[v];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<vector<ll> > cycledecomp(vector<int> perm) {
	vector<vector<ll> > ans;
	for (ll x = 0; x < n; x++) {seen[x] = false;}
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
		// Search for SP from 0 to x
		for (ll x = 0; x < n; x++) {
			fromzero[x] = shortestpath(0,x);
		}
		for (ll x = 0; x < n; x++) {
			tozero[x] = shortestpath(x,0);
		}
		vector<vector<ll> > cycles = cycledecomp(p);
		vector<pair<ll,ll> > swaps;
		for (auto& cycle: cycles) {
			if (cycle.size() == 1) continue;
			ll csz = cycle.size();
			ll ginit = -1;
			for (ll init = 0; init < csz; init++) {
				bool good = true;
				for (ll i = 0; i < csz-1; i++) {
					ll x = cycle[(init+i)%csz];
					ll z = cycle[(init+i+1)%csz];
					bool ok = false;
					if (t[x][z] != UNDEF) ok = true;
					for (ll v = 0; v < n; v++) {
						if (t[x][v] != UNDEF && t[v][z] != UNDEF) ok=true;
					}
					if(!ok) good = false;
				}
				if (good) ginit = init;
			}
			if (ginit == -1) assert(false);
			for (ll i = 0; i < csz-1; i++) {
				ll x = cycle[(ginit+i)%csz];
				ll z = cycle[(ginit+i+1)%csz];
				printf("Need to swap: %lld %lld\n",x,z);
				if (t[x][z] != UNDEF) {
					swaps.PB(MP(x,z));
				}
				else {
					for (ll v = 0; v < n; v++) {
						if (t[x][v] != UNDEF && t[v][z] != UNDEF) {
							swaps.PB(MP(x,v));
							swaps.PB(MP(v,z));
							swaps.PB(MP(x,v));
						}
					}
				}
			}
		}
		ll a[MAXN];
		for (ll x = 0; x < n; x++) {
			a[x] = x;
		}
		vector<int> final;
		for (auto& sw: swaps) {
			ll x = sw.first; ll z = sw.second;
			printf("Swap: %lld %lld\n",x,z);
			ll y = t[x][z];
			if (y >= MAXN) {
				y -= MAXN;
				swap(x,z);
			}
			assert(y != UNDEF && y >= 0 && y < n);
			printf("Shifting 0 to %lld\n",y);
			for (auto& w: fromzero[y]) {
				printf("w:%lld",w);
				final.PB(w);
				{
					bool ok = false;
					for (ll q = 0; q < n; q++) {
						if (graph[w][q] == 'Y' && a[q] == 0) {
							ok = true;
							swap(a[w],a[q]);
						}
					}
					assert(ok);
				}
			}
			printf("\n");
			printf("Perform swap: %lld %lld %lld\n",x,z,y);
			final.PB(x);
				{
					ll w = x;
					bool ok = false;
					for (ll q = 0; q < n; q++) {
						if (graph[w][q] == 'Y' && a[q] == 0) {
							ok = true;
							swap(a[w],a[q]);
						}
					}
					assert(ok);
				}
			final.PB(z);
				{
					ll w = z;
					bool ok = false;
					for (ll q = 0; q < n; q++) {
						if (graph[w][q] == 'Y' && a[q] == 0) {
							ok = true;
							swap(a[w],a[q]);
						}
					}
					assert(ok);
				}
			final.PB(y);
				{
					ll w = y;
					bool ok = false;
					for (ll q = 0; q < n; q++) {
						if (graph[w][q] == 'Y' && a[q] == 0) {
							ok = true;
							swap(a[w],a[q]);
						}
					}
					assert(ok);
				}
			printf("Shifting 0 back from %lld\n",y);
			for (auto& w: tozero[y]) {
				printf("w:%lld",w);
				final.PB(w);
				{
					bool ok = false;
					for (ll q = 0; q < n; q++) {
						if (graph[w][q] == 'Y' && a[q] == 0) {
							ok = true;
							swap(a[w],a[q]);
						}
					}
					assert(ok);
				}
			}
			printf("\n");
			ll len = fromzero[y].size() + tozero[y].size() + 1;
			for (ll i = 0; i <= len-1; i++) {
				for (auto& w: fromzero[y]) {
					final.PB(w);
					//printf("fromzero: %lld\n",w);
				}
				for (auto& w: tozero[y]) {
					final.PB(w);
					//printf("tozero: %lld\n",w);
				}
			}
		}
		return final;
	}
};

bool check(vector <string> graph, vector <int> p, vector<int> ans) {
	assert(ans.size() <= 2500);
	ll n = p.size();
	ll a[MAXN];
	for (ll x = 0; x < n; x++) {
		a[x] = x;
	}
	printf("Checker:\n");
	for (auto& x: ans) {
		bool ok = false;
		for (ll y = 0; y < n; y++) {
			if (graph[x][y] == 'Y' && a[y] == 0) {
				ok = true;
				swap(a[x],a[y]);
				printf("%d <-> %lld : ",x,y);
				break;
			}
		}
		for (ll i = 0; i < n; i++) {
			printf("%lld ",a[i]);
		}
		printf("\n");
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
			/*case 6:
			{
				string graph[] = ;
				int p[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findSolution(vector <string>(graph, graph+sizeof(graph)/sizeof(string)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}*/
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



{{"NNYYNNNY", "YNYYNYYY", "NNNNYYNY", "NNYNYNYY", "YYNNNYNY", "YNNYNNNN", "YNYNYYNY", "NNNNNYNN"}, {0, 1, 2, 3, 4, 5, 6, 7}}


Problem: 1000
Test Case: 6
Succeeded: No
Execution Time: 0 ms
Peak memory used: 0.000MB
Args:
{{"NNYNYNY", "YNNNYNY", "NYNNYNY", "YYYNYNY", "NNNNNNY", "YYYYYNN", "NNNNNYN"}, {0, 4, 1, 5, 3, 6, 2}}

Expected:
{1, 2, 5, 6, 4, 5, 6, 4, 0, 1, 2, 0, 1, 2, 5, 6, 4, 0, 1, 2, 0, 1, 2, 5, 6, 0, 1, 2, 0, 1, 2, 3, 5, 6, 3, 5, 6, 4, 0, 1, 2, 3, 5, 6, 4, 0, 1, 2, 3, 5, 6, 4, 0}

Received:
uncaught exception

Answer checking result:
null


Problem: 1000
Test Case: 10
Succeeded: No
Execution Time: 2 ms
Peak memory used: 11.621MB
Args:
{{"NYNNNYNNNNNNNNNNNNNYNYYNYYNNYY", "NNYYNNNNYYNYNNNNYNNYYYYYNNNNNN", "YNNYNYYYNNNNNNNYNNNNNYYYNYYNNY", "YNNNYNNYYNYNNYYYYNYNNNNNNYNNYN", "YYYNNNYNNYYNNNNYNNYYYYYYNYNYYN", "NYNYYNNYYNYYNNNNNYNNNYYNNNNNYN", "YYNYNYNYYYYNYNYNYNYNYNNNNYYYNN", "YYNNYNNNYNNNNYNNNNNNNNNYNNNYYN", "YNYNYNNNNNYYNYNNYNYYYYNYYYNNNN", "YNYYNYNYYNNYYYNNNNNYNNNYNYYNYY", "YYYNNNNYNYNNNNYNNYYYYNNNYNNNNN", "YNYYYNYYNNYNYNNNNNYYYNNYYYYYNY", "YYYYYYNYYNYNNNNNNNNNYYYYYNNNYY", "YYYNYYYNNNYYYNYNYYNYYYNNNYNNYY", "YYYNYYNYYYNYYNNYNYNYNNNYNYYNNY", "YYNNNYYYYYYYYYNNYNNYNYYYNNNYYY", "YNYNYYNYNYYYYNYNNNNNNYNYNNNYYY", "YYYYYNYYYYNYYNNYYNNYNYYYYYYYYY", "YYYNNYNYNYNNYYYYYYNYNYYNNYNYNY", "NNYYNYYYNNNNYNNNYNNNYNNYNNNYYY", "YNYYNYNYNYNNNNYYYYYNNNNNYNYNYY", "NNNYNNYYNYYYNNYNNNNYYNYYYNYNNY", "NNNYNNYYYYYYNYYNYNNYYNNYNYNYNY", "YNNYNYYNNNYNNYNNNNYNYNNNNYNNNN", "NYYYYYYYNYNNNYYYYNYYNNYYNYYYYY", "NYNNNYNYNNYNYNNYYNNYYYNNNNNNYY", "YYNYYYNYYNYNYYNYYNYYNNYYNYNYYY", "YYYYNYNNYYYNYYYNNNNNYYNYNYNNNY", "NYYNNNYNYNYYNNYNNNYNNYYYNNNYNY", "NYNYYYYYYNYNNNNNNNNNNNNYNNNNNN"}, {0, 18, 2, 29, 28, 14, 15, 6, 4, 11, 13, 7, 26, 1, 21, 25, 22, 19, 10, 23, 24, 17, 27, 16, 20, 8, 5, 12, 3, 9}}

Expected:
{4, 3, 2, 9, 1, 13, 7, 16, 15, 14, 10, 12, 11, 5, 23, 29, 27, 22, 26, 24, 21, 28, 24, 21, 28, 25, 0, 3, 6, 2, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 14, 10, 12, 18, 11, 5, 23, 27, 22, 24, 21, 28, 24, 21, 28, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 14, 10, 12, 11, 5, 23, 27, 22, 24, 21, 28, 25, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 11, 5, 23, 27, 22, 24, 21, 28, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 10, 12, 14, 10, 12, 11, 5, 23, 27, 22, 26, 24, 21, 28, 25, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 14, 10, 12, 11, 5, 23, 27, 19, 22, 26, 24, 21, 28, 0, 3, 2, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 14, 10, 12, 11, 5, 23, 27, 19, 22, 26, 24, 21, 28, 24, 21, 28, 25, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 14, 10, 12, 11, 5, 23, 27, 19, 22, 24, 21, 28, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 14, 10, 12, 11, 5, 23, 29, 27, 22, 26, 24, 21, 28, 24, 21, 28, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 14, 10, 12, 11, 5, 23, 27, 19, 22, 24, 21, 28, 24, 21, 28, 25, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 14, 10, 12, 11, 5, 20, 23, 29, 27, 22, 24, 21, 28, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 14, 10, 12, 11, 5, 20, 23, 29, 27, 22, 26, 24, 21, 28, 24, 21, 28, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 18, 11, 17, 5, 20, 23, 29, 27, 19, 22, 24, 21, 28, 24, 21, 28, 0, 3, 2, 9, 1, 13, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 10, 12, 18, 11, 17, 5, 20, 23, 29, 27, 22, 24, 21, 28, 24, 21, 28, 0, 3, 2, 9, 1, 13, 7, 16, 15, 14, 10, 12, 18, 11, 17, 5, 20, 23, 27, 19, 22, 26, 24, 21, 28, 24, 21, 28, 0, 3, 2, 9, 1, 13, 7, 16, 15, 14, 10, 12, 18, 11, 17, 5, 23, 29, 27, 19, 22, 24, 21, 28, 24, 21, 28, 0, 3, 2, 9, 1, 13, 7, 16, 15, 14, 10, 12, 18, 11, 5, 20, 23, 29, 27, 22, 24, 21, 28, 24, 21, 28, 25, 0, 3, 2, 9, 1, 13, 7, 16, 15, 14, 10, 12, 11, 17, 5, 20, 23, 27, 22, 24, 21, 28, 25, 0, 3, 2, 9, 1, 13, 7, 16, 15, 14, 10, 12, 14, 10, 12, 18, 11, 17, 5, 23, 29, 27, 22, 26, 24, 21, 28, 25, 0, 3, 6, 2, 9, 1, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 18, 11, 5, 20, 23, 29, 27, 19, 22, 26, 24, 21, 28, 25, 0, 3, 6, 2, 9, 1, 13, 7, 16, 15, 14, 10, 12, 11, 17, 5, 20, 23, 29, 27, 19, 22, 26, 24, 21, 28, 25, 0, 3, 6, 2, 9, 1, 13, 7, 16, 15, 14, 10, 12, 14, 10, 12, 18, 11, 17, 5, 20, 23, 29, 27, 19, 22, 26, 24, 21, 28, 25, 0, 3, 6, 2, 9, 1, 13, 7, 16, 15, 14, 16, 15, 14, 10, 12, 18, 11, 17, 5, 20, 23, 29, 27, 19, 22, 26, 24, 21, 28, 25, 0, 3, 6, 2, 9, 1, 13, 7, 16, 13, 7, 16, 15, 14, 10, 12, 18, 11, 17, 5, 20, 23, 29, 27, 19, 22, 26, 24, 21, 28, 25, 0, 3, 6, 2, 8, 9, 1, 13, 9, 1, 13, 7, 16, 15, 14, 10, 12, 18, 11, 17, 5, 20, 23, 29, 27, 19, 22, 26, 24, 21, 28, 25, 0, 3, 6, 2, 9, 1, 13, 7, 16, 15, 14, 10, 12, 18, 11, 17, 5, 20, 23, 29, 27, 19, 22, 26, 24, 21, 28, 25, 0, 3, 6, 2, 8, 9, 1, 13, 7, 16, 15, 14, 10, 12, 18, 11, 17, 5, 20, 23, 29, 27, 19, 22, 26, 24, 21, 28, 25, 0, 4, 3, 6, 2, 8, 9, 1, 13, 7, 16, 15, 14, 10, 12, 18, 11, 17, 5, 20, 23, 29, 27, 19, 22, 26, 24, 21, 28, 25, 0, 4, 3, 6, 2, 8, 9, 1, 13, 7, 16, 15, 14, 10, 12, 18, 11, 17, 5, 20, 23, 29, 27, 19, 22, 26, 24, 21, 28, 25, 0}

Received:
{23, 1, 13, 23, 1, 0, 23, 1, 0, 23, 1, 0, 23, 1, 0, 23, 1, 0, 23, 1, 18, 23, 1, 0, 23, 1, 0, 23, 1, 0, 23, 1, 0, 23, 1, 0, 3, 29, 18, 10, 29, 0, 3, 29, 0, 3, 29, 0, 3, 29, 0, 3, 29, 0, 4, 29, 28, 3, 29, 0, 4, 29, 0, 4, 29, 0, 4, 29, 0, 4, 29, 0, 2, 28, 3, 29, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 10, 29, 9, 10, 5, 0, 10, 5, 0, 10, 5, 0, 10, 5, 0, 10, 5, 0, 27, 11, 9, 27, 19, 0, 27, 19, 0, 27, 19, 0, 27, 19, 0, 27, 19, 0, 2, 28, 7, 11, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 7, 6, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 26, 6, 15, 26, 21, 0, 26, 21, 0, 26, 21, 0, 26, 21, 0, 26, 21, 0, 27, 15, 25, 27, 19, 0, 27, 19, 0, 27, 19, 0, 27, 19, 0, 27, 19, 0, 3, 29, 25, 8, 29, 0, 3, 29, 0, 3, 29, 0, 3, 29, 0, 3, 29, 0, 2, 28, 4, 8, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 3, 21, 5, 26, 21, 0, 3, 21, 0, 3, 21, 0, 3, 21, 0, 3, 21, 0, 2, 28, 5, 14, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 7, 25, 14, 21, 25, 0, 7, 25, 0, 7, 25, 0, 7, 25, 0, 7, 25, 0, 20, 21, 17, 20, 1, 0, 20, 1, 0, 20, 1, 0, 20, 1, 0, 20, 1, 0, 20, 19, 17, 20, 1, 0, 20, 1, 0, 20, 1, 0, 20, 1, 0, 20, 1, 0, 7, 25, 23, 19, 25, 0, 7, 25, 0, 7, 25, 0, 7, 25, 0, 7, 25, 0, 7, 25, 23, 16, 25, 0, 7, 25, 0, 7, 25, 0, 7, 25, 0, 7, 25, 0, 2, 28, 16, 22, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 3, 21, 27, 22, 21, 0, 3, 21, 0, 3, 21, 0, 3, 21, 0, 3, 21, 0, 2, 28, 12, 27, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 2, 28, 0, 27, 24, 20, 27, 19, 0, 27, 19, 0, 27, 19, 0, 27, 19, 0, 27, 19, 0}

Answer checking result:
Result is incorrect.
