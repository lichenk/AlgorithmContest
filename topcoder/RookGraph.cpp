#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
bool a[100][100];
bool seen[100];
ll row[100];
ll col[100];
ll dp[2][100][100];
ll k = -1;
ll fact[100], invfact[100];
bool take[100][100];
typedef pair<ll,ll> info;
info f(ll initv) {
	queue<ll> active;
	//printf("Vertices: ");
	{
		queue<ll> q;
		q.push(initv);
		seen[initv] = true;
		while(!q.empty()) {
			ll x = q.front(); q.pop();
			active.push(x);
			//printf("%lld ",x);
			for (ll y = 0; y < k; y++) {
				if (a[x][y] && !seen[y]) {
					seen[y] = true;
					q.push(y);
				}
			}
		}
	}
	//printf("\n");
	for (ll i = 0; i < 100; i++) {
		for (ll j = 0; j < 100; j++) {
			take[i][j] = false;
		}
	}
	{
		assert(active.front() == initv); active.pop();
		row[initv] = 0;
		col[initv] = 0;
		take[0][0] = true;
		if (active.empty()) return MP(0LL, 0LL);
		ll neigh = active.front(); active.pop(); assert(a[initv][neigh] && initv != neigh);
		row[neigh] = 0;
		col[neigh] = 1;
		take[0][1] = true;
		ll nrow = 0; ll ncol = 1;
		vector<ll> done;
		done.PB(initv); done.PB(neigh);
		while(!active.empty()) {
			ll x = active.front(); active.pop();
			set<ll> xrow; set<ll> xcol;
			for (auto& y: done) {
				if(a[x][y]) {
					xrow.insert(row[y]);
					xcol.insert(col[y]);
				}
			}
			for (auto& y: done) {
				if(!a[x][y]) {
					xrow.erase(row[y]);
					xcol.erase(col[y]);
				}
			}
			xrow.insert(nrow+1);
			xcol.insert(ncol+1);
			ll finalrow = -1; ll finalcol = -1;
			ll numgoods = 0;
			for (auto& xr: xrow) {
				for (auto& xc: xcol) {
					if (take[xr][xc]) continue;
					bool good = true;
					for (auto& y: done) {
						bool intersect = ((xr == row[y]) || (xc == col[y]));
						if(a[x][y] && (!intersect)) {
							//printf("FailA at y:%lld. %lld %lld %lld %lld\n",y,xr,row[y],xc,col[y]);
							good = false;
						}
						if((!a[x][y]) && intersect) {
							//printf("FailB at y:%lld\n",y);
							good = false;
						}
					}
					//printf("%lld try %lld %lld res %d\n",x,xr,xc,good);
					if (good) {
						numgoods++;
						finalrow = xr;
						finalcol = xc;
					}
				}
			}
			if (finalrow == -1 || finalcol == -1) return MP(-1LL,-1LL);
			// Hypothesis check: Row/Col choice is determined
			assert(numgoods == 1);
			row[x] = finalrow;
			col[x] = finalcol;
			take[finalrow][finalcol] = true;
			if (finalrow == nrow+1) nrow++;
			if (finalcol == ncol+1) ncol++;
			//printf("x:%lld row:%lld col:%lld\n",x,row[x],col[x]);
			done.PB(x);
		}
		return MP(nrow, ncol);
	}
}

ll modexp(ll base, ll e) {
	ll ans = 1;
	while(e > 0) {
		if (e % 2 == 1) {
			ans = (ans * base) % MOD;
			e--;
		}
		else {
			base = (base*base) % MOD;
			e /= 2;
		}
	}
	return ans;
}

ll inv(ll x) {
	return modexp(x,MOD-2);
}

ll binom(ll n, ll x) {
	ll denom = (invfact[x]*invfact[n-x])%MOD;
	return (fact[n]*denom)%MOD;
}

class RookGraph {
	public:
	int countPlacements(int N, vector <string> graph) {
		for (ll dpidx = 0; dpidx < 2; dpidx++) {
			for (ll i = 0; i <= N; i++) {
				for (ll j = 0; j <= N; j++) {
					dp[dpidx][i][j] = 0;
				}
			}
		}
		fact[0] = 1;
		for (ll i = 1; i < 100; i++) {
			fact[i] = (fact[i-1] * i)%MOD;
		}
		for (ll i = 0; i < 100; i++) {
			invfact[i] = inv(fact[i]);
			assert((invfact[i] * fact[i])%MOD == 1);
		}
		k = graph.size();
		for (ll x = 0; x < k; x++) {
			for (ll y = 0; y < k; y++) {
				a[x][y] = (graph[x][y] == '1');
			}
			seen[x] = false;
		}
		dp[1][0][0] = 1;
		ll finaldpidx = -1;
		ll basedpidx = 0;
		for (ll v = 0; v < k; v++) {
			if (seen[v]) continue;
			info cand = f(v);
			if (cand.first == -1 && cand.second == -1) return 0;
			assert(cand.first != -1);
			assert(cand.second != -1);
			ll x = cand.first + 1; ll y = cand.second + 1;
			//printf("resx:%lld resy:%lld\n",x,y);
			ll p = (fact[x] * fact[y])%MOD;
			ll dpidx = basedpidx%2;
			finaldpidx = dpidx;
			ll prevdpidx = (basedpidx+1)%2;
			basedpidx++;
			for (ll i = 0; i <= N; i++) {
				for (ll j = 0; j <= N; j++) {
					dp[dpidx][i][j] = 0;
				}
			}
			for (ll i = 0; i <= N; i++) {
				for (ll j = 0; j <= N; j++) {
					ll c = (dp[prevdpidx][i][j] * p) % MOD;
					{
						ll cx = i+x; ll cy = j+y;
						ll leftx = N-i; ll lefty = N-j;
						ll choose = (binom(leftx,x) * binom(lefty,y))%MOD;
						if (cx <= N && cy <= N) {
							dp[dpidx][cx][cy] += (c*choose)%MOD;
							dp[dpidx][cx][cy] %= MOD;
						}					
					}
					if (x*y > 1) {
						ll cx = i+y; ll cy = j+x;
						ll leftx = N-i; ll lefty = N-j;
						ll choose = (binom(leftx,y) * binom(lefty,x))%MOD;
						if (cx <= N && cy <= N) {
							dp[dpidx][cx][cy] += (c*choose)%MOD;
							dp[dpidx][cx][cy] %= MOD;
						}					
					}
				}
			}
		}
		ll ans = 0;
		{
			ll dpidx = finaldpidx;
			for (ll x = 0; x <= N; x++) {
				for (ll y = 0; y <= N; y++) {
					////printf("%lld %lld %lld\n",x,y,dp[dpidx][x][y]);
					ll cand = dp[dpidx][x][y];
					ans = (ans + cand)%MOD;
				}
			}
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
		cout << "Testing RookGraph (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451069807;
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
		RookGraph _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 8;
				string graph[] = {"11",
				                  "11"};
				_expected = 896;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 8;
				string graph[] = {"111",
				                  "110",
				                  "101"};
				_expected = 6272;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 2;
				string graph[] = {"11111",
				                  "11111",
				                  "11111",
				                  "11111",
				                  "11111"};
				_expected = 0;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 10;
				string graph[] = {"1010000100",
				                  "0100101000",
				                  "1011010100",
				                  "0011010000",
				                  "0100100000",
				                  "0011010010",
				                  "0100001001",
				                  "1010000110",
				                  "0000010110",
				                  "0000001001"};
				_expected = 289151874;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 4:
			{
				int N = 50;
				string graph[] = {"10111110000",
				                  "01011010000",
				                  "10100010011",
				                  "11010110001",
				                  "11001100101",
				                  "10011100110",
				                  "11110011111",
				                  "00000011100",
				                  "00001111100",
				                  "00100110010",
				                  "00111010001"};
				_expected = 0;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 5:
			{
				int N = 31;
				string graph[] = {"10000000000000000000000000000000000000000000000000",
				                  "01000000000000000000000000000000000010000000010000",
				                  "00100000000010000000000100001100000000010010000000",
				                  "00010000000010000000001000000000000000000000000000",
				                  "00001000000000000000000000000000000000100000000000",
				                  "00000100101000000010000000000000000000100100000001",
				                  "00000010000000000100000001000000000000000000000001",
				                  "00000001000000001000000000000000000000000000000100",
				                  "00000100101000000000000000000000000000000000000001",
				                  "00000000010000000000000010000010000000000000100000",
				                  "00000100101000000000000000000010000000000000000001",
				                  "00000000000100000010000100001000000001001000100000",
				                  "00110000000010000000001000001000000000000010000000",
				                  "00000000000001000000000000000000000000000000000000",
				                  "00000000000000100000000000000000001010000000000010",
				                  "00000000000000010000000000100000000000000000000000",
				                  "00000001000000001000000000000000000000010000000000",
				                  "00000010000000000100000001000000010000000000000000",
				                  "00000100000100000010000000001000000001101100000000",
				                  "00000000000000000001000000000001000000000000001100",
				                  "00000000000000000000110000000000100000000000000010",
				                  "00000000000000000000110010000000100000000010000000",
				                  "00010000000010000000001000000001000000000001000000",
				                  "00100000000100000000000100000100000000010000100000",
				                  "00000000010000000000010011000000000000000010000000",
				                  "00000010000000000100000011000000000000000000000000",
				                  "00000000000000010000000000100000001000001000000000",
				                  "00000000000000000000000000010000010100000000000000",
				                  "00100000000110000010000000001000000001001010000000",
				                  "00100000000000000000000100000100000000010000000000",
				                  "00000000011000000000000000000010000000000000100000",
				                  "00000000000000000001001000000001000000000001001100",
				                  "00000000000000000000110000000000100100000000000000",
				                  "00000000000000000100000000010000010000000000000000",
				                  "00000000000000100000000000100000001000001000000000",
				                  "00000000000000000000000000010000100100000000000000",
				                  "01000000000000100000000000000000000010000000010010",
				                  "00000000000100000010000000001000000001001000000000",
				                  "00001100000000000010000000000000000000100100000000",
				                  "00100000000000001000000100000100000000010000000000",
				                  "00000000000100000010000000101000001001001000000000",
				                  "00000100000000000010000000000000000000100100000000",
				                  "00100000000010000000010010001000000000000010000000",
				                  "00000000000000000000001000000001000000000001000000",
				                  "00000000010100000000000100000010000000000000100000",
				                  "01000000000000000000000000000000000010000000010000",
				                  "00000000000000000001000000000001000000000000001100",
				                  "00000001000000000001000000000001000000000000001100",
				                  "00000000000000100000100000000000000010000000000010",
				                  "00000110101000000000000000000000000000000000000001"};
				_expected = 0;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 6:
			{
				int N = 2;
				string graph[] = {"10","01"};
				_expected = 4;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 7:
			{
				int N = 2;
				string graph[] = 
{
"1110",
"1101",
"1011",
"0111"

};
				_expected = 8;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 8:
			{
				int N = 3;
				string graph[] = {"111","111","111"};
				_expected = 36;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 9:
			{
				int N = 34;
				string graph[] = {"10000010010000000000100000", "01000000000000101000000001", "00100000000000000000000000", "00010000000000010100000000", "00001000000001000001000001", "00000100000000000000000010", "10000010010000000001010000", "00000001000000000000000000", "00000000100010000000000000", "10000010010000000000000000", "00000000001100000000000000", "00000000001100000000000000", "00000000100010000000000000", "00001000000001000001000001", "01000000000000101000000000", "00010000000000010100000000", "01000000000000101000000000", "00010000000000010100000000", "00000000000000000010110000", "00001010000001000001010001", "10000000000000000010110000", "00000010000000000011110000", "00000000000000000000001100", "00000000000000000000001100", "00000100000000000000000010", "01001000000001000001000001"};
				_expected = 543576721;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 10:
			{
				int N = 3;
				string graph[] = {"110","110","001"};
				_expected = 9;
				_received = _obj.countPlacements(N, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
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
