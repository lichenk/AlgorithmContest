#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 100008LL
#define INF 99999999999LL
pair<ll,ll> P[MAXN];
pair<ll,ll> Q[MAXN];
map<ll,ll> xtoreqy;
bool f(ll T, ll n, ll M) {
	map<ll,ll> ytobestx;
	{
		ll bestx = -INF;
		for (ll i = n-1; i >= 0; i--) {
			ll x = Q[i].second + T;
			if (x > bestx) {
				bestx = x;
				ll y = Q[i].first + T;
				if (ytobestx.find(y) == ytobestx.end()) {
					ytobestx[y] = bestx;
				}
				else {
					ytobestx[y] = max(ytobestx[y], bestx);
				}
			}
		}
	}
	set<ll> used;
	ll dy = -1; ll dx = -1;
	for (auto& req: xtoreqy) {
		ll reqx = req.first; ll reqy = req.second;
		//printf("%lld %lld\n",reqx,reqy);
		if (dy >= reqy && dx >= reqx) continue;
		auto best = ytobestx.lower_bound(reqy);
		if (best == ytobestx.end()) {
			return false;
		}
		ll bestx = best->second;
		ll besty = best->first;
		dx = bestx; dy = besty;
		//printf("%lld %lld %lld %lld\n",bestx,besty,dx,dy);
		used.insert(besty);
		assert(besty >= reqy);
		if (!(bestx >= reqx)) {
			return false;
		}
	}
	ll usedm = used.size();
	return (usedm <= M);
}

class TheEmpireStrikesBack {
	public:
	int find(int AXi, int BXi, int CXi, int AYi, int BYi, int CYi, int Ni, int Mi) {
		ll AX = AXi;
		ll BX = BXi;
		ll CX = CXi;
		ll AY = AYi;
		ll BY = BYi;
		ll CY = CYi;
		ll N = Ni;
		ll M = Mi;
		P[0].first = AX;
		for (ll i = 1; i <= N-1; i++) {
		    P[i].first = ((P[i-1].first * BX) + CX) % MOD;
		}
		P[0].second = AY;
		for (ll i = 1; i <= N-1; i++) {
    		P[i].second = ((P[i-1].second * BY) + CY) % MOD;
		}
		sort(P,P+N);
		ll reqy = -INF;
		for (ll i = N-1; i >= 0; i--) {
			ll x = P[i].first;
			ll y = P[i].second;
			if (y > reqy) {
				reqy = y;
				if(xtoreqy.find(x) == xtoreqy.end()) {
					xtoreqy[x] = reqy;
				}
				else {
					xtoreqy[x] = max(xtoreqy[x], reqy);
				}
			}
		}
		for (ll i = 0; i < N; i++) {
			Q[i] = MP(P[i].second, P[i].first);
		}
		sort(Q,Q+N);
		//assert(f(1,N,M));
		ll imin = 0; ll imax = MOD;
		while (imin < imax) {
			ll imid = imin + (imax-imin)/2;
			if (!f(imid, N,M)) {
				imin = imid+1;
			}
			else {
				imax = imid;
			}
		}
		assert(imin==imax);
		assert(f(imin,N,M));
		return imin;

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
		cout << "Testing TheEmpireStrikesBack (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1452651603;
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
		TheEmpireStrikesBack _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int AX = 2;
				int BX = 2;
				int CX = 2;
				int AY = 2;
				int BY = 2;
				int CY = 2;
				int N = 2;
				int M = 1;
				_expected = 0;
				_received = _obj.find(AX, BX, CX, AY, BY, CY, N, M); break;
			}
			case 1:
			{
				int AX = 2;
				int BX = 2;
				int CX = 2;
				int AY = 2;
				int BY = 4;
				int CY = 1000000000;
				int N = 2;
				int M = 1;
				_expected = 1;
				_received = _obj.find(AX, BX, CX, AY, BY, CY, N, M); break;
			}
			case 2:
			{
				int AX = 1;
				int BX = 3;
				int CX = 8;
				int AY = 10000;
				int BY = 10;
				int CY = 999910000;
				int N = 3;
				int M = 1;
				_expected = 30;
				_received = _obj.find(AX, BX, CX, AY, BY, CY, N, M); break;
			}
			case 3:
			{
				int AX = 0;
				int BX = 0;
				int CX = 0;
				int AY = 0;
				int BY = 0;
				int CY = 0;
				int N = 100000;
				int M = 1000;
				_expected = 0;
				_received = _obj.find(AX, BX, CX, AY, BY, CY, N, M); break;
			}
			case 4:
			{
				int AX = 10;
				int BX = 20;
				int CX = 30;
				int AY = 40;
				int BY = 50;
				int CY = 60;
				int N = 100000;
				int M = 10;
				_expected = 15720;
				_received = _obj.find(AX, BX, CX, AY, BY, CY, N, M); break;
			}
			/*case 5:
			{
				int AX = ;
				int BX = ;
				int CX = ;
				int AY = ;
				int BY = ;
				int CY = ;
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.find(AX, BX, CX, AY, BY, CY, N, M); break;
			}*/
			/*case 6:
			{
				int AX = ;
				int BX = ;
				int CX = ;
				int AY = ;
				int BY = ;
				int CY = ;
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.find(AX, BX, CX, AY, BY, CY, N, M); break;
			}*/
			/*case 7:
			{
				int AX = ;
				int BX = ;
				int CX = ;
				int AY = ;
				int BY = ;
				int CY = ;
				int N = ;
				int M = ;
				_expected = ;
				_received = _obj.find(AX, BX, CX, AY, BY, CY, N, M); break;
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
