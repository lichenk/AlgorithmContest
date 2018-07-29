#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<50ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ld v[50];
class FoxAndBusiness {
	public:
	double minimumCost(int _K, int totalWork, vector <int> _a, vector <int> _p) {
		vector<ll> a,p;for (auto &w:_a) a.PB(w); for (auto &w:_p) p.PB(w);
		ll n=a.size(),K=_K;
		ld imin=0,imax=1e30;
		for (ll jj=0;jj<420;jj++) {
			ld imid=(imin+imax)/2;
			for (ll i=0;i<n;i++) {
				v[i]=(imid-p[i])*a[i];
			}
			sort(v,v+n);
			ld sum=0;
			for (ll i=n-1;i>=n-K;i--) sum+=v[i];
			if (sum<K*3600) imin=imid;
			else imax=imid;
		}
		ld final=imin;
		final*=totalWork;
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
		cout << "Testing FoxAndBusiness (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471623710;
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
		FoxAndBusiness _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 1;
				int totalWork = 10;
				int a[] = {10};
				int p[] = {20};
				_expected = 3800.0;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 1:
			{
				int K = 1;
				int totalWork = 100;
				int a[] = {50, 60};
				int p[] = {1000, 2000};
				_expected = 107200.0;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 2:
			{
				int K = 2;
				int totalWork = 300;
				int a[] = {10, 20, 47};
				int p[] = {15, 20, 98765};
				_expected = 77500.0;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 3:
			{
				int K = 4;
				int totalWork = 1000;
				int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
				int p[] = {20, 30, 40, 58, 60, 70, 80, 90, 100, 150};
				_expected = 531764.705882353;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 4:
			{
				int K = 25;
				int totalWork = 1;
				int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
				int p[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
				_expected = 1094.7368421052633;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 5:
			{
				int K = 21;
				int totalWork = 29464;
				int a[] = {9, 9, 1, 5, 2, 4, 2, 8, 8, 2, 1, 6, 4, 6, 1, 1, 9, 1, 5, 8, 6, 8, 5, 7, 6, 4, 5, 2, 3, 5, 8, 3, 10, 1, 5, 1, 1, 6, 5, 7, 8, 5, 10, 5, 10, 1, 2, 6, 4, 7};
				int p[] = {14643, 38558, 44185, 26548, 52884, 70990, 14716, 45013, 96047, 89495, 2909, 81821, 5517, 28787, 40522, 18568, 59420, 72055, 89149, 79405, 86723, 53897, 89062, 21795, 51657, 36965, 33061, 6277, 80280, 61630, 75103, 34236, 42669, 8254, 69729, 30439, 73335, 10771, 35441, 67391, 8052, 78325, 12352, 68766, 24606, 25764, 28795, 83331, 58390, 92500};
				_expected = 5.860763289756098E8;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			/*case 6:
			{
				int K = ;
				int totalWork = ;
				int a[] = ;
				int p[] = ;
				_expected = ;
				_received = _obj.minimumCost(K, totalWork, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}*/
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
