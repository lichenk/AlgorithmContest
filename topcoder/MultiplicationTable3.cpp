#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll a[21][21];
class MultiplicationTable3 {
	public:
	vector <int> construct(int x) {
  	x++;
  	vector<ll> v;
    while (x>1) {
    	if (x%2==0) {
    		v.PB(2);
    		x/=2;
    	}
    	else {
    		v.PB(1);
    		x--;
    	}
    }
    reverse(v.begin(),v.end());
    ll n=v.size();
    for (ll i=0;i<n;i++) {
    	for (ll j=0;j<n;j++) {
    		a[i][j]=i;
    	}
    }
    for (ll k=0;k<n;k++) {
    	if (v[k]==1) {
    		for (ll y=0;y<=k;y++) {
    			a[k][y]=(y+1)%(k+1);
    		}
    	}
    	else if (v[k]==2) {
    		for (ll y=0;y<=k;y++) {
    			a[k][y]=k;
    		}
    	}
    	else assert(false);
    }
    vector<int> ans;
    for (ll i=0;i<n;i++) {
    	for (ll j=0;j<n;j++) {
    		ans.PB(a[i][j]);
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
		cout << "Testing MultiplicationTable3 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1461776258;
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
		MultiplicationTable3 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 2;
				int __expected[] = {1, 1, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 1:
			{
				int x = 3;
				int __expected[] = {0, 1, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 2:
			{
				int x = 6;
				int __expected[] = {0, 1, 1, 0, 1, 2, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 3:
			{
				int x = 31;
				int __expected[] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 4:
			{
				int x = 1;
				int __expected[] = {0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			/*case 5:
			{
				int x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}*/
			/*case 6:
			{
				int x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}*/
			/*case 7:
			{
				int x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
