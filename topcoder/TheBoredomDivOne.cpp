#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll all;
ld dp[55];
ld f(ll m) {
	if (dp[m]>-1) return dp[m];
	if (m==0) return dp[m]=0;
	ll n=all-m;
	ll choose2=(m*(m-1))/2;
	ll choose1=m*n;
	ll allpair=((n+m)*(n+m-1))/2;
	//printf("allpair:%d choose1:%d choose2:%d\n",allpair,choose1,choose2);
	ld probchoosesomething=(ld)(choose1+choose2)/((ld)allpair);
	ld t=1.0/probchoosesomething;
	ld probchoose1=(ld)choose1/((ld)choose1+choose2);
	ld probchoose2=(ld)choose2/((ld)choose1+choose2);
	if (choose2>0) {
		return dp[m]=t+probchoose1*f(m-1)+probchoose2*f(m-2);
	}
	else {
		return dp[m]=t+probchoose1*f(m-1);
	}
}
class TheBoredomDivOne {
	public:
	double find(int n, int m) {
		all=n+m;
		for (ll x=0;x<=m;x++) dp[x]=-2;
		return f(m);
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
		cout << "Testing TheBoredomDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485158165;
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
		TheBoredomDivOne _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				int m = 1;
				_expected = 1.0;
				_received = _obj.find(n, m); break;
			}
			case 1:
			{
				int n = 2;
				int m = 1;
				_expected = 1.5;
				_received = _obj.find(n, m); break;
			}
			case 2:
			{
				int n = 1;
				int m = 2;
				_expected = 2.0;
				_received = _obj.find(n, m); break;
			}
			case 3:
			{
				int n = 4;
				int m = 7;
				_expected = 13.831068977298521;
				_received = _obj.find(n, m); break;
			}
			/*case 4:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.find(n, m); break;
			}*/
			/*case 5:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.find(n, m); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				_expected = ;
				_received = _obj.find(n, m); break;
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
