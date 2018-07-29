#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define pb(x) push_back(x)
#define mp(x) make_pair(x)
#define ins(x) insert(x)
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class ConvexSequence {
	public:
	long long getMinimum(vector <int> _a) {
		ll ans=0;
		vector<ll> a; for (auto &w:_a) a.PB(w);
		ll n=a.size();
		while(1) {
			ll oldans=ans;
			for (ll i=1;i<=n-2;i++) {
				ll delta=max(0ll,(1+2*a[i]-(a[i-1]+a[i+1]))/2);
				//printf("i:%d a[i]:%d delta:%d\n",i,a[i],delta);
				a[i]-=delta;
				ans+=delta;
			}
			if (ans==oldans) break;
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
		cout << "Testing ConvexSequence (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483553554;
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
		ConvexSequence _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {6,5,1,5,3,3};
				_expected = 7LL;
				_received = _obj.getMinimum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {3,0,1,4};
				_expected = 0LL;
				_received = _obj.getMinimum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {1,1,1,0,2,2,2};
				_expected = 5LL;
				_received = _obj.getMinimum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {854159326, 317144183, 781399725, 287076509, 894967145, 882577367, 174517516, 134415519,
				           274494874, 709819883, 59717133, 732212854, 40551288, 232526958, 811785438, 930853743,
				           946882902, 321325300, 397702677, 376192501, 599310562, 889156198, 135776890, 882710939,
				           823196361, 681959076, 318666702, 94469186, 536320456, 116468376, 530320850, 436708006,
				           903344748, 659080120, 774722507, 967315412, 566063635, 43970906, 497687103, 781266213,
				           876086123, 366960001, 587364849, 191948103, 172568553, 539762057, 83507466, 71569625,
				           686305822, 663789601};
				_expected = 20178337330LL;
				_received = _obj.getMinimum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {5};
				_expected = 0LL;
				_received = _obj.getMinimum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.getMinimum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.getMinimum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				_expected = LL;
				_received = _obj.getMinimum(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
