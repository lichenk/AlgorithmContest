#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 1000008LL
#define INF 999999999999LL
#define MAXS 2508LL
ll f[MAXS][MAXS];
ll fact[MAXN];
ll invfact[MAXN];
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
	return modexp(x, MOD-2);
}
ll binom(ll n, ll k) {
	ll denom = (invfact[n-k]*invfact[k])%MOD;
	return (fact[n]*denom)%MOD;
}
class PermutationCounts {
	public:
	int countPermutations(int TOTAL, vector <int> RAWPOS) {
		sort(RAWPOS.begin(),RAWPOS.end());
		ll pos[MAXS];
		fact[0] = 1;
		for (ll x = 1; x < MAXN; x++) {
			fact[x] = (fact[x-1]*x)%MOD;
		}
		for (ll x = 0; x < MAXN; x++) {
			invfact[x] = inv(fact[x]);
			assert((invfact[x]*fact[x])%MOD == 1);
		}
		ll s = RAWPOS.size();
		pos[0] = 0;
		for (ll x = 1; x <= s; x++) {
			pos[x] = RAWPOS[x-1];
		}
		if (pos[s] != TOTAL) {
			pos[s+1] = TOTAL; s++;
		}
/*
f[x][y] is the number of permutations such that
0.....x-1 is good
x-1...y is bad
*/
		/*for (ll x = 0; x <= s; x++) {
			for (ll y = x; y <= s; y++) {
				f[x][y] = INF;
			}
		}*/
		for (ll y = 0; y <= s; y++) {
			f[0][y] = 1;
			f[1][y] = 1;
		}
		for (ll x = 2; x <= s; x++) {
			for (ll y = x; y <= s; y++) {
				// Good to x-1.
				// x-1 junction is free
				// x-1...y is decreasing
				ll all = (f[x-1][x-1] * binom(pos[y], pos[y] - pos[x-1]))%MOD;
				// Good to x-2 incl junction x-2
				// x-2...y is decreasing
				// So x-1 junction is decreasing, x-1...y decreasing
				ll violate = f[x-1][y];
				ll good = (all - violate)%MOD;
				while(good < 0) good += MOD;
				//printf("%lld %lld: %lld - %lld = %lld\n", x,y,all,violate,good);
				f[x][y] = good;
			}
		}
		return f[s][s];
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
		cout << "Testing PermutationCounts (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451195064;
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
		PermutationCounts _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				int pos[] = {3};
				_expected = 9;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 13;
				int pos[] = {12,11,10,9,8,7,6,5,4,3,2,1};
				_expected = 1;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 13;
				int pos[] = {};
				_expected = 1;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 9;
				int pos[] = {2,4,5};
				_expected = 1421;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 80;
				int pos[] = {31,41,59,26,53,58,9,79,32,3,8,46};
				_expected = 82650786;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 875;
				int pos[] = {295,311,98,345,420,547,646,734,380,325,608,783,141,65,305,437,769,252,44,
				            872,123,6,50,507,450,426,343,740,69,695,101,607,597,535,342,307,329,837,803,
				            237,459,444,498,15,712,134,473,14,715,223,787,192,710,750,193,293,242,652,
				            212,580,545,488,506,533,774,460,285,534,350,210,559,805,686,67,159,541,706,
				            514,657,801,373,754,310,800,589,736,863,675,254,283,604,27,628,103,81,235,
				            677,461,609,30,581,75,756,688,262,563,679,21,217,515,836,868,13,728,717,
				            309,267,767,259,414,332,744,129,859,4,179,632,415,278,812,79,77,784,573,433,
				            865,407,121,477,567,790,127,593,57,674,114,239,599,552,738};
				_expected = 169176190;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 6:
			{
				int N = 5;
				int pos[] = {2,4};
				_expected = 16;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 7:
			{
				int N = 3;
				int pos[] = {1,2};
				_expected = 1;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 8:
			{
				int N = 2;
				int pos[] = {1};
				_expected = 1;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
			}
			case 9:
			{
				int N = 59236;
				int pos[] = {4958, 15094, 717, 22447, 109, 7058, 14669, 55244, 50950, 54203, 4442, 38048, 28943, 481, 8179, 9689, 6597, 53310, 34971, 1886, 43217, 12427, 1979, 513, 33654, 23116, 13467, 24592, 4, 5143, 18136, 2541, 40570, 23211, 53698, 17714, 3032, 24085, 215, 28850, 3185, 4010, 40794, 8004, 48, 10545, 1771, 16389, 23610, 41447, 32184, 44189, 32640, 6128, 22225, 7377, 4975, 26913, 22135, 3284, 35165, 7721, 1714, 8788, 51492, 16835, 20406, 999, 15484, 1716, 4135, 5695, 30279, 13522, 43854, 18330, 47657, 16, 35814, 15711, 8955, 10490, 2257, 29, 35807, 57828, 54312, 66, 17, 43351, 55963, 12376, 22478, 55151, 10048, 48201, 41254, 16642, 54002, 33162, 3023, 3553, 14032, 46679, 650, 239, 1688, 52573, 15799, 54982, 19083, 33169, 206, 34416, 18606, 11425, 13303, 28028, 364, 14585, 4778, 1238, 7296, 32428, 42420, 37827, 2842, 6805, 1183, 48835, 3202, 19191, 4011, 18687, 31704, 3544, 279, 8361, 40663, 10969, 31801, 58185, 2882, 6142, 44250, 24093, 351, 50055, 39656, 49621, 39254, 12387, 5579, 51040, 11032, 7714, 41816, 41826, 2754, 47803, 27907, 54985, 303, 19434, 53426, 15824, 9665, 31534, 998, 3999, 14419, 42498, 56231, 6210, 17710, 10650, 35957, 27307, 1909, 11568, 4686, 43277, 46918, 50056, 2569, 30377, 2949, 1518, 929, 6749, 26669, 49308, 24084, 4132, 543, 41420, 2712, 33285, 6539, 5304, 41047, 45177, 53090, 37034, 11898, 36987, 19807, 55004, 33403, 34805, 800, 18907, 305, 159, 219, 7954, 5624, 456, 32259, 15652, 28661, 113, 30097, 20504, 42193, 1561, 24447, 273, 51256, 52513, 122, 39853, 1505, 35100, 49519, 30810, 20071, 2192, 48231, 11916, 1985, 26648, 39067, 467, 24962, 6630, 15296, 2262, 25983, 47568, 50791, 18156, 20680, 29366, 36689, 6, 11624, 19024, 33988, 8646, 19959, 44192, 5183, 24659, 2111, 2960, 792, 5620, 31309, 48263, 3817, 645, 25442, 52530, 58391, 53902, 13856, 57850, 14713, 9943, 43398, 31749, 42993, 23795, 29779, 37242, 8202, 9118, 29602, 54232, 11281, 6902, 905, 26885, 41115, 10231, 20, 38542, 18921, 26, 612, 32427, 6947, 3869, 49295, 185, 17814, 10133, 214, 2004, 4480, 18409, 102, 22461, 981, 181, 46255, 14522, 51822, 19746, 1426, 25089, 814, 3192, 1071, 12787, 11173, 1017, 50609, 3151, 1198, 56652, 56894, 271, 53373, 53592, 422, 37595, 1357, 10547, 1151, 23853, 2593, 49852, 2995, 54174, 20627, 47, 2485, 52379, 1480, 36964, 47132, 5993, 10569, 21072, 2085, 232, 1662, 12418, 36415, 9772, 8476, 129, 1498, 1422, 4160, 42165, 1486, 49273, 926, 5554, 4237, 17225, 2396, 52413, 38838, 34166, 3381, 47828, 19982, 28805, 8396, 24059, 3164, 33006, 1530, 30, 14227, 315, 50279, 5426, 31588, 36881, 16536, 1713, 23088, 37272, 12543, 5634, 30522, 58401, 18868, 26148, 16860, 32311};
				_expected = 70074221;
				_received = _obj.countPermutations(N, vector <int>(pos, pos+sizeof(pos)/sizeof(int))); break;
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
