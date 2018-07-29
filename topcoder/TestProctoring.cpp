#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class TestProctoring {
	public:
	double expectedTime(vector <int> vp, vector <int> vq) {
		int n=vp.size();
		vector<ld> q;
		for (int i=0;i<n;i++) q.PB(1-(vp[i]/((ld)vq[i])));
		ld final=0;
		for (int z=1;z<(1<<n);z++) {
			int j=__builtin_popcount(z);
			int neg=((j+1)%2)?-1:1;
			ld prodq=1;
			for (int x=0;x<n;x++) {
				if (z&(1<<x)) prodq*=q[x];
			}
			ld res=1/(1-prodq);
			final+= (neg==-1)?(-res):res;
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
		cout << "Testing TestProctoring (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1532048775;
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
		TestProctoring _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {2};
				int q[] = {4};
				_expected = 2.0;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {1,2};
				int q[] = {2,4};
				_expected = 2.6666666666666665;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {3,1,2,4,2,5};
				int q[] = {3,1,2,4,2,5};
				_expected = 1.0;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {1,1,1,1,1,1,1,1};
				int q[] = {1,2,3,4,5,6,7,8};
				_expected = 13.604834665120991;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {2,3,5,7,11,13,17};
				int q[] = {3,5,7,11,13,17,19};
				_expected = 2.6299445065924276;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 5:
			{
				int p[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int q[] = {1000000000,1000000000,1000000000,1000000000,1000000000,
				          1000000000,1000000000,1000000000,1000000000,1000000000,
				          1000000000,1000000000,1000000000,1000000000,1000000000,
				          1000000000,1000000000,1000000000,1000000000,1000000000};
				_expected = 3.597740924491638E9;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 6:
			{
				int p[] = {1};
				int q[] = {1};
				_expected = 1;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 7:
			{
				int p[] = {1000000000};
				int q[] = {1000000000};
				_expected = 1;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 8:
			{
				int p[] = {1};
				int q[] = {5};
				_expected = 5;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 9:
			{
				int p[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int q[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 1;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
			}
			case 10:
			{
				int p[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				int q[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
				_expected = 1;
				_received = _obj.expectedTime(vector <int>(p, p+sizeof(p)/sizeof(int)), vector <int>(q, q+sizeof(q)/sizeof(int))); break;
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
