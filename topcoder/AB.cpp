#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
ll h[51];
class AB {
	public:
	string createString(int N, int K) {
		ll numa = N/2;
		ll numb = N - numa;
		ll lim = numa * numb;
		if (K > lim) return "";
		for (ll i = 0; i < numa; i++) {
			h[i] = 0;
		}
		ll idx = 0;
		for (ll j = 0; j < K; j++) {
			h[idx]++;
			if (h[idx] >= numb) idx++;
		}
		//sort(h,h+numa, greater<ll>);
		sort(h,h+numa);
		ll curb = 0;
		idx = 0;
		string ans = "";
		for (ll j = 0; j < numa; j++) {
			while(h[j] > curb) {ans += "B"; curb++;}
			ans += "A";
			//printf("%lld %lld\n",j,h[j]);
		}
		while (ans.length() < N) ans += "B";
		reverse(ans.begin(), ans.end());
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
		cout << "Testing AB (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1451778129;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AB _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 2;
				_expected = "ABB";
				_received = _obj.createString(N, K); break;
			}
			case 1:
			{
				int N = 2;
				int K = 0;
				_expected = "BA";
				_received = _obj.createString(N, K); break;
			}
			case 2:
			{
				int N = 5;
				int K = 8;
				_expected = "";
				_received = _obj.createString(N, K); break;
			}
			case 3:
			{
				int N = 10;
				int K = 12;
				_expected = "BAABBABAAB";
				_received = _obj.createString(N, K); break;
			}
			/*case 4:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.createString(N, K); break;
			}*/
			/*case 5:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.createString(N, K); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				_expected = ;
				_received = _obj.createString(N, K); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
