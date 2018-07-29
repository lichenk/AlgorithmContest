#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define QMAX 16375
typedef pair<ll,ll> rat;

bool cmp(pair<pair<ll,ll>, ll> x, pair<pair<ll,ll>, ll> y) {
	ll a = x.first.first; ll b = x.first.second;
	ll c = y.first.first; ll d = y.first.second;
	ll ad = a*d; ll bc = b*c;
	if (ad > bc) return true;
	else if (ad < bc) return false;
	else {
		if (b < d) {
			return true;
		}
		else if (b > d) {
			return false;
		}
		else {
			return x.second <y.second;
		}
	}
}
ll cnt[80], w[80], v[80], bestcleft[80], cleft[QMAX+1][80], value[QMAX+1], f[QMAX+1], g[QMAX+1], last[80];
class ClassicProblem {
	public:
	long long maximalValue(vector <int> cnti, vector <int> wi, vector <int> vi, int limit) {
		vector<pair<pair<ll,ll>, ll> > a;
		ll n = wi.size();
		for (ll i = 0; i < n; i++) {
			a.PB(MP(MP(vi[i],wi[i]),i));
		}
		sort(a.begin(), a.end(), cmp);
		for (ll j = 0; j < n; j++) {
			ll i = a[j].second;
			cnt[j] = cnti[i];
			w[j] = wi[i];
			v[j] = vi[i];
			//printf("%lld %lld %lld\n",cnt[j],w[j],v[j]);
		}
		for (ll i = 0; i < n; i++) {
			bestcleft[i] = cnt[i];
		}
		ll q = min(QMAX, limit);
		for (ll k = q; k >= 0; k--) {
			for (ll i = 0; i < n; i++) {
				cleft[k][i] = cnt[i];
			}
			ll rem = limit - k;
			ll val = 0;
			for (ll i = 0; i < n; i++) {
				ll add = min(cleft[k][i], rem/w[i]);
				rem -= add*w[i];
				val += add*v[i];
				cleft[k][i] -= add;
				//printf("k: %lld, i: %lld, cleft: %lld\n",k,i,cleft[k][i]);
			}
			value[k] = val;
			for (ll i = 0; i < n; i++) {
				bestcleft[i] = min(bestcleft[i], cleft[k][i]);
			}
		}
		for (ll x = 0; x <= q; x++) {
			f[x] = 0;
		}
		for (ll i = 0; i < n; i++) {
			ll wt = w[i];
			ll va = v[i];
			ll num = bestcleft[i];
			//printf("%lld %lld %lld\n", wt, va, num);
			for (ll j = 0; j < num; j++) {
				for (ll x = q; x >= wt; x--) {
					f[x] = max(f[x], f[x-wt]+va);
				}
			}
		}
		ll final = 0;
		ll prev = -1;
		for (ll k = 0; k <= q; k++) {
			// if (k < q && value[k] <= value[k+1]) continue;
			if (k < q && value[k] <= value[k+1]) continue;
			bool good = false;
			if (k > 0) {
				good = true;
				for (ll i = 0; i < n; i++) {
					if (cleft[k][i] < cleft[prev][i]) {
						//printf("%lld %lld less than %lld\n",i,cleft[k][i],cleft[k-1][i]);
						good = false; break;
					}
				}
			}
			if (!good) {
				for (ll x = 0; x <= q; x++) {
					g[x] = f[x];
				}
				for (ll i = 0; i < n; i++) {
					last[i] = bestcleft[i];
				}
			}
			else {
				for (ll i = 0; i < n; i++) last[i] = cleft[prev][i];
			}
			prev = k;
			//printf("\n");
			for (ll i = 0; i < n; i++) {
				ll wt = w[i];
				ll va = v[i];
				ll num = cleft[k][i] - last[i];
				//printf("wt: %lld va: %lld num: %lld\n",wt,va,num);
				for (ll j = 0; j < num; j++) {
					for (ll x = q; x >= wt; x--) {
						g[x] = max(g[x], g[x-wt]+va);
					}
				}
			}
			ll best = 0;
			for (ll x = 0; x <= k; x++) {
				best = max(g[x], best);
			}
			//for (ll x = 0; x <= q; x++) printf("%lld ", g[x]);
			//printf("\n%lld, %lld, %lld\n",k,best,value[k]);
			final = max(best + value[k], final);
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
		cout << "Testing ClassicProblem (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1448938335;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ClassicProblem _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cnt[] = {100,100};
				int w[] = {2,3};
				int v[] = {3,5};
				int limit = 6;
				_expected = 10LL;
				_received = _obj.maximalValue(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), limit); break;
			}
			
			case 1:
			{
				int cnt[] = {100,100};
				int w[] = {2,3};
				int v[] = {3,5};
				int limit = 5;
				_expected = 8LL;
				_received = _obj.maximalValue(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), limit); break;
			}
			case 2:
			{
				int cnt[] = {100,102};
				int w[] = {2,3};
				int v[] = {3,5};
				int limit = 1000000000;
				_expected = 810LL;
				_received = _obj.maximalValue(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), limit); break;
			}
			case 3:
			{
				int cnt[] = {100,100};
				int w[] = {2,3};
				int v[] = {3,5};
				int limit = 1;
				_expected = 0LL;
				_received = _obj.maximalValue(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), limit); break;
			}
			case 4:
			{
				int cnt[] = {1,2,3,4,5,6,7,8};
				int w[] = {4,2,6,7,5,8,3,1};
				int v[] = {3,6,4,1,2,8,5,7};
				int limit = 15;
				_expected = 73LL;
				_received = _obj.maximalValue(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), limit); break;
			}
			
			case 5:
			{
				int cnt[] = {1000000000};
				int w[] = {1};
				int v[] = {1000000000};
				int limit = 1000000000;
				_expected = 1000000000000000000LL;
				_received = _obj.maximalValue(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), limit); break;
			}
			
			case 6:
			{
				int cnt[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 6, 6, 6, 6};
				int w[] = {2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 2};
				int v[] = {3, 3, 3, 3, 3, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
				int limit = 57645;
				_expected = 738LL;
				_received = _obj.maximalValue(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), limit); break;
			}
			case 7:
			{
				int cnt[] = {8, 58, 58, 58, 58, 58, 1, 58, 58, 58, 58, 58, 9, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 7, 58, 58, 58, 1, 7, 58, 58, 58, 58, 58, 58, 58, 31, 58, 53, 58};
				int w[] = {30, 3, 26, 1, 2, 31, 10, 10, 9, 30, 16, 7, 21, 26, 11, 15, 3, 7, 8, 15, 2, 19, 13, 9, 23, 20, 17, 6, 1, 17, 8, 26, 19, 13, 30, 8, 24, 5, 6, 10, 28, 25};
				int v[] = {2095, 2095, 47, 2095, 2095, 332, 2095, 2095, 40, 2095, 2095, 2095, 2095, 444, 2095, 2095, 962, 2095, 2095, 6, 2095, 2095, 2, 529, 884, 2095, 2095, 2095, 2095, 38, 10, 2095, 2095, 2095, 778, 2095, 659, 120, 2095, 2095, 2095, 6};
				int limit = 22496;
				_expected = 3031857LL;
				_received = _obj.maximalValue(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), limit); break;
			}
			case 8:
			{
				int cnt[] = {12, 12, 12, 12, 12, 7, 12, 12, 12, 12, 2, 12, 12, 12, 12, 12, 12, 12, 12, 1, 12, 12, 5, 10, 12, 12, 12, 12, 12, 12, 1, 12, 7, 12, 12, 12, 12, 12, 12, 6, 12, 12, 12, 12, 12, 12, 3, 12, 12, 12};
				int w[] = {11, 31, 14, 33, 45, 9, 3, 13, 18, 24, 9, 21, 27, 50, 35, 20, 1, 27, 7, 32, 21, 46, 16, 10, 11, 37, 37, 44, 28, 5, 8, 14, 30, 31, 15, 37, 16, 15, 39, 25, 2, 49, 8, 2, 46, 26, 35, 30, 39, 26};
				int v[] = {8, 77, 20218, 20218, 5, 20218, 20218, 20218, 14602, 20218, 20218, 5, 93, 20218, 20218, 7, 20218, 20218, 20218, 4769, 836, 20218, 20218, 20218, 681, 5570, 861, 326, 20218, 16795, 379, 20218, 4500, 8, 20218, 20218, 20218, 20218, 846, 2, 20218, 20218, 20218, 20218, 20218, 20218, 20218, 20218, 5, 20218};
				int limit = 4490;
				_expected = 5639439LL;
				_received = _obj.maximalValue(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), limit); break;
			}
			case 9:
			{
				int cnt[] = {181, 1, 620, 620, 620, 620, 620, 21, 620};
				int w[] = {4, 4, 5, 2, 13, 3, 12, 11, 16};
				int v[] = {553, 8, 59, 532, 16, 553, 553, 553, 553};
				int limit = 3;
				_expected = 553LL;
				_received = _obj.maximalValue(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int)), vector <int>(w, w+sizeof(w)/sizeof(int)), vector <int>(v, v+sizeof(v)/sizeof(int)), limit); break;
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
