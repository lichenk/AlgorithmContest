#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll MAXF = 3000;
ll fact[MAXF], invfact[MAXF];
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
void init() {
	fact[0] = 1;
	for (ll x=1; x<MAXF; x++) {
		fact[x] = (fact[x-1] * x)%MOD;
	}
	for (ll x=0;x<MAXF;x++) {
		invfact[x] = modexp(fact[x],MOD-2);
	}
}

ll binomperm(ll m, ll k) {
	return (fact[m] * invfact[m-k]) % MOD;
}

class NarrowPassage2 {
	public:
	int count(vector <int> _size, int _maxSizeSum) {
		init();
		ll maxSizeSum = _maxSizeSum + 1;
		vector<ll> size;
		size.PB(maxSizeSum);
		for (auto &w: _size) {
			size.PB(w);
		}
		size.PB(maxSizeSum);
		ll mid = maxSizeSum/2 - 1;
		set<ll, greater<ll> > s;
		for (auto &w: size) {
			//if (w <= mid) s.insert(w);
			s.insert(w);
		}
		ll n = size.size();
		ll ans = 1;
		for (auto &y: s) {
			ll p = 0;
			ll numy = 0;
			ll other = 0;
			for (ll i = 1; i < n; i++) {
				//printf("y:%lld. Processing: %lld\n",y,size[i]);
				if (size[i] + y >= maxSizeSum) {
					ll m = other+numy;
					ll k = numy;
					//printf("y:%lld: %lld %lld %lld %lld\n",y,other,numy,m,k);
					ll cand = binomperm(m,k);
					ans = (ans * cand) % MOD;
					p = i;
					other = 0;
					numy = 0;
				}
				else if (size[i] == y) {
					numy++;
				}
				else if (size[i] > y && size[i] + y < maxSizeSum) {
					other++;
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
		cout << "Testing NarrowPassage2 (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454042739;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		NarrowPassage2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int size[] = {1, 2, 3};
				int maxSizeSum = 3;
				_expected = 2;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			case 1:
			{
				int size[] = {1, 2, 3};
				int maxSizeSum = 1000;
				_expected = 6;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			case 2:
			{
				int size[] = {1, 2, 3};
				int maxSizeSum = 4;
				_expected = 3;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			case 3:
			{
				int size[] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
				int maxSizeSum = 2;
				_expected = 227020758;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			case 4:
			{
				int size[] = {2,4,6,1,3,5};
				int maxSizeSum = 8;
				_expected = 60;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			case 5:
			{
				int size[] = {1000000000};
				int maxSizeSum = 1000000000;
				_expected = 1;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}
			/*case 6:
			{
				int size[] = ;
				int maxSizeSum = ;
				_expected = ;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}*/
			/*case 7:
			{
				int size[] = ;
				int maxSizeSum = ;
				_expected = ;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
			}*/
			/*case 8:
			{
				int size[] = ;
				int maxSizeSum = ;
				_expected = ;
				_received = _obj.count(vector <int>(size, size+sizeof(size)/sizeof(int)), maxSizeSum); break;
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
