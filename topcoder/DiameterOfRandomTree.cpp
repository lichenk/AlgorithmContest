// Optimize: In loops, enforce d >= r
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXM 51
#define MAXQ 101
vector<ll> graph[MAXM];
ld dpf[MAXM][MAXQ][MAXQ];
ld dpg[MAXM][MAXQ][MAXQ];
ld f[2][MAXQ][MAXQ];
ld g[2][MAXQ][MAXQ];
ll m;
ll q;
void init() {
	for (ll i = 0; i < MAXM; i++) {
		for (ll j = 0; j < MAXQ; j++) {
			for (ll k = 0; k < MAXQ; k++) {
				dpf[i][j][k] = 0;
				dpg[i][j][k] = 0;
			}
		}
	}
}

void dfs(ll v, ll parent) {
	for (auto& w: graph[v]) {
		if (w == parent) continue;
		dfs(w, v);
	}
	{
		ll c = 1;
		for (ll r = 0; r <= q; r++) {
			for (ll d = 1; d <= q; d++) {
				f[c][r][d] = 0; g[c][r][d] = 0;
			}
		}
		f[c][0][0] = 1;
		for (ll r = 0; r <= q; r++) {
			g[c][r][0] = 0;
			for (ll d = 1; d <= q; d++) {
				g[c][r][d] = g[c][r][d-1] + f[c][r][d-1];
			}
		}
	}
	ll i = 0;
	for (auto& w: graph[v]) {
		if (w == parent) continue;
		ll c = i%2; ll p = (i+1)%2;
		for (ll r = 0; r <= q; r++) {
			for (ll d = 0; d <= q; d++) {
				f[c][r][d] = 0; g[c][r][d] = 0;
			}
		}
		for (ll r1 = 0; r1 <= q; r1++) {
			for (ll r2 = 0; r2 <= q; r2++) {
				for (ll d = min(r1,r2); d <= q; d++) {
					ld sum = g[p][r1][d] * dpf[w][r2][d];
					sum += f[p][r1][d] * dpg[w][r2][d];
					sum += f[p][r1][d] * dpf[w][r2][d];
					sum /= 2;
					//////printf("v: %lld w:%lld r1:%lld r2:%lld d:%lld sum:%f\n",v,w,r1,r2,d,sum);
					for (ll e = 1; e <= 2; e++) {
						ll finald = max(d, r1+r2+e);
						ll finalr = max(r1, r2+e);
						f[c][finalr][finald] += sum;
					}
				}
			}
		}
		for (ll r = 0; r <= q; r++) {
			g[c][r][0] = 0;
			for (ll d = 1; d <= q; d++) {
				g[c][r][d] = g[c][r][d-1] + f[c][r][d-1];
			}
		}

		for (ll r = 0; r <= q; r++) {
			for (ll d = 0; d <= q; d++) {
				////printf("v:%lld w:%lld r:%lld d:%lld f:%f\n",v,w,r,d,f[c][r][d]);
			}
		}

		i++;
	}
	{
		ll c = (i+1)%2;
		for (ll r = 0; r <= q; r++) {
			for (ll d = 0; d <= q; d++) {
				dpf[v][r][d] = f[c][r][d];
				//printf("q: %lld v:%lld r:%lld d:%lld dpf%f\n",q,v,r,d,dpf[v][r][d]);
			}
		}
	}
	for (ll r = 0; r <= q; r++) {
		dpg[v][r][0] = 0;
		for (ll d = 1; d <= q; d++) {
			dpg[v][r][d] = dpg[v][r][d-1] + dpf[v][r][d-1];
			//////printf("v:%lld r:%lld d:%lld dpg%f\n",v,r,d,dpg[v][r][d]);
		}
	}
}
class DiameterOfRandomTree {
	public:
	double getExpectation(vector <int> a, vector <int> b) {
		m = a.size()+1;
		q = 2*(m-1);
		//printf("q:%lld\n",q);
		init();
		for (ll i = 0; i < m-1; i++) {
			graph[a[i]].PB(b[i]); graph[b[i]].PB(a[i]);
		}
		dfs(0, -1);
		ld final = 0;
		for (ll r = 0; r <= q; r++) {
			for (ll d = 0; d <= q; d++) {
				ld cand = dpf[0][r][d] * d;
				final += cand;
			}
		}
		return final;
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
		cout << "Testing DiameterOfRandomTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451235971;
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
		DiameterOfRandomTree _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {0,1,2,3};
				int b[] = {1,2,3,4};
				_expected = 6.0;
				_received = _obj.getExpectation(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {0,0,0};
				int b[] = {1,2,3};
				_expected = 3.375;
				_received = _obj.getExpectation(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {0,0,0,1,4};
				int b[] = {1,2,3,4,5};
				_expected = 6.25;
				_received = _obj.getExpectation(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {0,0,0,0,0,0,0,0};
				int b[] = {1,2,3,4,5,6,7,8};
				_expected = 3.9609375;
				_received = _obj.getExpectation(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {0,0,0,1,2,3,5,6,8};
				int b[] = {1,2,3,4,5,6,7,8,9};
				_expected = 10.53125;
				_received = _obj.getExpectation(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {0};
				int b[] = {1};
				_expected = 1.5;
				_received = _obj.getExpectation(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int a[] = {0,1};
				int b[] = {1,2};
				_expected = 3.0;
				_received = _obj.getExpectation(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 7:
			{
				int a[] = {0,0};
				int b[] = {1,2};
				_expected = 3.0;
				_received = _obj.getExpectation(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 8:
			{
				int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
				int b[] = {0, 1, 1, 1, 2, 5, 5, 6, 6, 6, 8, 11, 9, 13, 13, 13, 15, 14, 14, 15, 16, 18, 22, 19, 20, 24, 25, 25, 24, 25, 28, 31, 31, 31, 31, 31, 35, 36, 38, 37, 39, 39, 38, 39, 40, 43, 43, 43, 48};
				_expected = 24.5585880279541;
				_received = _obj.getExpectation(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}


			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
