#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 301
#define INF 999999999
complex<ll> t[MAXN];
ll f[MAXN][MAXN][MAXN];
ll n;
const complex<ll> oner(1LL,0LL);
const complex<ll> onei(0LL,1LL);
ll g(ll x, ll y, ll z) {
	assert (x>=0 && y>=0 && z>=0);
	ll numzero = 0;
	if (x == 0) numzero++;
	if (y == 0) numzero++;
	if (z == 0) numzero++;
	if (numzero == 0) return f[x][y][z];
	else {
		ll a[3]; a[0] = x; a[1] = y; a[2] = z;
		sort(a,a+3);
		if (numzero == 1) return f[0][a[1]][a[2]];
		else if (numzero == 2) return f[0][0][a[2]];
		else assert(false);
	}
	assert(false);
}

void shift(ll l1, ll r1, ll l2, ll r2) {
	assert(r1 >= l1 && r2 >= l2);
	assert(r1-l1 == r2-l2);
	for (ll x = l2; x <= r2; x++) {assert(t[x] == t[l2]);}
	for (ll i = 0; i <= r1-l1; i++) {
		t[l2+i] += t[l1+i];
	}
	ll idx = 0;
	for (ll j = 0; j < n; j++) {
		if (l1 <= j && j <= r1) continue;
		t[idx] = t[j]; idx++;
	}
	//printf("Sub: %lld\n",r1-l1+1);
	n -= (r1-l1+1);
}

bool iscanonical(ll x, ll y, ll z) {
	ll numzero = 0;
	if (x == 0) numzero++;
	if (y == 0) numzero++;
	if (z == 0) numzero++;
	if (numzero == 0) return true;
	else if (numzero == 1) return x==0;
	else if (numzero == 2) return x==0&&y==0;
	else {assert(false); return false;}
}

	int getNumberHelper(string pallets, bool try1, bool tie) {
		n = pallets.length();
		for (ll i = 0; i < n; i++) {
			if (pallets[i] == 'B') {
				t[i] = oner;
			}
			else if (pallets[i] == 'R') {
				t[i] = onei;
			}
			else {
				//printf("Bad char:%c\n",pallets[i]);
				assert(false);
			}
		}
		vector<pair<ll,ll> > segx, segy;
		ll init = 0;
		while(1) {
			segx.clear(); segy.clear();
			complex<ll> x = t[0];
			complex<ll> y(-1LL,-1LL);
			for (ll i = 0; i < n; i++) {
				if (t[i] != x) {y = t[i]; break;}
			}
			//printf("%lld:",n);
			//for (ll i = 0; i < n; i++) {
			//	if (t[i].real() == 1) printf("B");
			//	if (t[i].imag() == 1) printf("R");
			//}
			//printf("\n");
			for (ll i = 0; i < n; i++) {
				if (t[i] != x && t[i] != y) {
					printf("A:-1\n");
					return -1;
				}
			}
			ll left = 0;
			complex<ll> prev = t[0];
			for (ll i = 0; i <= n; i++) {
				if (i == n || t[i] != prev) {
					ll right = i-1;
					pair<ll,ll> seg = MP(left, right);
					if (prev == x) segx.PB(seg);
					else if (prev == y) segy.PB(seg);
					else assert(false);
					left = i;
					prev = t[i];
				}
			}
			if (segx.size() + segy.size() <= 3) break;
			bool halvegood1 = false;
			bool halvegood2 = false;
			if (n%2 == 0) {
				halvegood1 = true;
				halvegood2 = true;
				for (ll i = 0; i < n/2; i++) {
					if (t[i] != t[0]) halvegood1 = false;
				}
				for (ll i = n/2; i < n; i++) {
					if (t[i] != t[n/2]) halvegood2 = false;
				}
			}
			if (halvegood1) {
				shift(n/2, n-1, 0, n/2-1);
			}
			else if (halvegood2) {
				shift(0, n/2-1, n/2, n-1);
			}
			else {
				if (segy.size() == 2 &&
					segy[1].second - segy[1].first == segy[0].second - segy[0].first &&
					tie) {
					swap(segx, segy);
				}
				if (segx.size() == 2 &&
					segx[1].second - segx[1].first == segx[0].second - segx[0].first) {
					if (try1) shift(segx[1].first, segx[1].second, segx[0].first, segx[0].second);
					else shift(segx[0].first, segx[0].second, segx[1].first, segx[1].second);
				}
				else {
					//printf("B:-1\n");
					return -1;
				}
			}
			init++;
		}




		for (ll x = 0; x <= n; x++) {
			for (ll y = 0; y <= n; y++) {
				for (ll z = 0; z <= n; z++) {
					f[x][y][z] = INF;
				}
			}
		}
		f[0][0][1] = 0;
		f[0][1][0] = 0;
		for (ll sum = 2; sum <= n; sum++) {
			for (ll x = 0; x <= sum; x++) {
				for (ll y = 0; y <= sum-x; y++) {
					ll z = sum-x-y;
					if (f[x][y][z] != INF) continue;
					ll ans = INF;
					if (!iscanonical(x,y,z)) continue;
					// Case for 3 segs
					if (x > 0 && y > 0 && z > 0) {
						if (x >= y || z >= y) {
							ans = min(ans, g(0,y,x+z-y)+1);
						}
						if (y%2 == 0) {
							//printf("B:%lld\n", g(x,y/2,z)+1);
							ans = min(ans, g(x,y/2,z)+1);
						}
						if (x+y == z) {
							//printf("D:%lld\n", g(0,x,y)+1);
							ans = min(ans, g(0,x,y)+1);
						}
						if (x == y+z) {//printf("E:%lld\n", g(0,y,z)+1);
							ans = min(ans, g(0,y,z)+1);
						}
						if (x == y) {//printf("F:%lld\n",g(0,y,z)+1); 
							ans = min(ans, g(0,y,z)+1);
						}
						if (x == z) {//printf("G:%lld\n",g(0,y,z)+1); 
							ans = min(ans, g(0,y,z)+1);
						}
						if (y == z) {//printf("H:%lld\n",g(0,x,z)+1); 
							ans = min(ans, g(0,x,z)+1);
						}
						ll len = x+y+z;
						if (len%2 == 0 && z >= len/2) {
							ans = min(ans, g(x,y,z-len/2)+1);
						}
						if (len%2 == 0 && x >= len/2) {
							ans = min(ans, g(x-len/2,y,z)+1);
						}
					}
					// Case for 2 segs
					else if (x==0 && y > 0 && z > 0) {
						if (y%2 == 0) {
							ans = min(ans, g(0,y/2,z)+1);
						}
						if (z%2 == 0) {
							ans = min(ans, g(0,y,z/2)+1);
						}
						if ((y+z)%2 == 0) {
							if (((y+z)/2) - y >= 0) {
								ans = min(ans, g(0,y,((y+z)/2) - y)+1);
							}
							if (((y+z)/2) - z >= 0) {
								ans = min(ans, g(0,z,((y+z)/2) - z)+1);
							}
						}
						ll y2 = min(y,z);
						ll z2 = max(y,z);
						assert(y2<=z2);
						ans = min(ans, g(0,z2-y2,y2)+1);

						for (ll i=0;z2-y2-i>=0;i++) {
							//if (g(i,y2,z2-i-y2)+1 < ans) {
							//	printf("%lld: %lld\n", i,g(i,y2,z2-i-y2)+1);
							//}
							ans = min(ans, g(i,y2,z2-i-y2)+1);
						}
					}
					// Case for 1seg
					else if (x==0 && y==0 && z>0){
						assert(x==0 && y==0);
						for (ll k = 1; k <= z/2; k++) {
							ans = min(ans, g(0,z-2*k,k)+1);
						}
					}
					else {
						assert(false);
					}
					//printf("%lld %lld %lld: %lld\n",x,y,z,ans);
					f[x][y][z] = ans;
				}
			}
		}
		{
			ll x,y,z;
			if (segx.size() + segy.size() == 3) {
				x = segx[0].second-segx[0].first+1;
				y = segy[0].second-segy[0].first+1;
				z = segx[1].second-segx[1].first+1;
			}
			else if (segx.size() + segy.size() == 2) {
				x = 0;
				y = segx[0].second-segx[0].first+1;
				z = segy[0].second-segy[0].first+1;
			}
			else if (segx.size() + segy.size() == 1) {
				x = 0;
				y = 0;
				z = segx[0].second-segx[0].first+1;
			}
			else {
				assert(false);
			}
			assert(iscanonical(x,y,z));
			//printf("Final: %lld %lld %lld: %lld\n",x,y,z,f[x][y][z]);
			if (f[x][y][z] == INF) return -1;
			return f[x][y][z]+init;

		}
		assert(false);
	}

class ForkliftTruckOperator {
	public:
	int getNumber(string pallets) {
		ll final = INF;
		for (ll i = 0; i < 2; i++) {
			for (ll j = 0; j < 2; j++) {
				ll cand = getNumberHelper(pallets, i==1,j==1);		
				if (cand != -1) {
					final = min(final, cand);
				}
			}
		}
		if (final == INF) return -1;
		else return final;
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
		cout << "Testing ForkliftTruckOperator (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451195126;
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
		ForkliftTruckOperator _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string pallets = "RRBRBR";
				_expected = 4;
				_received = _obj.getNumber(pallets); break;
			}
			case 1:
			{
				string pallets = "RB";
				_expected = 1;
				_received = _obj.getNumber(pallets); break;
			}
			case 2:
			{
				string pallets = "RRRRRR";
				_expected = 3;
				_received = _obj.getNumber(pallets); break;
			}
			case 3:
			{
				string pallets = "RRRRBBBBBBBBB";
				_expected = 5;
				_received = _obj.getNumber(pallets); break;
			}
			case 4:
			{
				string pallets = "RBRBRBRBRBRBRB";
				_expected = -1;
				_received = _obj.getNumber(pallets); break;
			}
			case 5:
			{
				string pallets = "B";
				_expected = 0;
				_received = _obj.getNumber(pallets); break;
			}
			case 6:
			{
				string pallets = "BBBBBBBBBBBBBBBBRRRRRRRRBRBBRRRR";
				_expected = 5;
				_received = _obj.getNumber(pallets); break;
			}
			case 7:
			{
				string pallets = "RRRRRRRBBBBBB";
				_expected = 4;
				_received = _obj.getNumber(pallets); break;
			}
			case 8:
			{
				string pallets = "RRRRBBBBBR";
				_expected = -1;
				_received = _obj.getNumber(pallets); break;
			}
			case 9:
			{
				string pallets = "RRRRBRRRRRR";
				_expected = 5;
				_received = _obj.getNumber(pallets); break;
			}
			case 10:
			{
				string pallets = "RBR";
				_expected = 2;
				_received = _obj.getNumber(pallets); break;
			}
			case 11:
			{
				string pallets = "RRBBBBBR";
				_expected = -1;
				_received = _obj.getNumber(pallets); break;
			}
			case 12:
			{
				string pallets = "BRRRRRRRRRR";
				_expected = 4;
				_received = _obj.getNumber(pallets); break;
			}
			case 13:
			{
				string pallets = "RBRRRR";
				_expected = 3;
				_received = _obj.getNumber(pallets); break;
			}
			case 14:
			{
				string pallets = "RBRRBRRR";
				_expected = 4;
				_received = _obj.getNumber(pallets); break;
			}
			case 15:
			{
				string pallets = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR";
				_expected = 9;
				_received = _obj.getNumber(pallets); break;
			}
			case 16:
			{
				string pallets = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR";
				_expected = 8;
				_received = _obj.getNumber(pallets); break;
			}
			case 17:
			{
				string pallets = "RRRRRRRRRRRRRRRRRRRBBBBB";
				_expected = 5;
				_received = _obj.getNumber(pallets); break;
			}
			case 18:
			{
				string pallets = "BBBBBRRRRRRRRRRRRRR";
				_expected = 5;
				_received = _obj.getNumber(pallets); break;
			}
			case 19:
			{
				string pallets = "RRRRRRRBBBBB";
				_expected = 4;
				_received = _obj.getNumber(pallets); break;
			}
			case 20:
			{
				string pallets = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR";
				_expected = 10;
				_received = _obj.getNumber(pallets); break;
			}
			case 21:
			{
				string pallets = "RRBRRB";
				_expected = 3;
				_received = _obj.getNumber(pallets); break;
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
