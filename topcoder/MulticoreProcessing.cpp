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
ll f(ll j, ll s, ll c, ll p) {
	return (j+s*c-1)/(s*c) + p*(c-1);
}

class MulticoreProcessing {
	public:
	long long fastestTime(long long j, int p, vector <int> speed, vector <int> cores) {
		int n=speed.size();
		ll ans=1LL<<62;
		for (int i=0;i<n;i++) {
			ll s=speed[i];
			vector<int> vc={1,cores[i]};
			ll ce=sqrt(j/((ld)(s*p)));
			for (int c=max(1LL,ce-200);c<=min((ll)cores[i],ce+200);c++) {
				vc.PB(c);
			}
			for (auto &c:vc) {
				ll cand=f(j,s,c,p);
				//printf("i:%d c:%d cand:%lld\n",i,c,cand);
				chkmin(ans,cand);
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
		cout << "Testing MulticoreProcessing (350.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1520820267;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 350.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MulticoreProcessing _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long jobLength = 2000LL;
				int corePenalty = 5;
				int speed[] = {40,20};
				int cores[] = {2,4};
				_expected = 30LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 1:
			{
				long long jobLength = 2000LL;
				int corePenalty = 5;
				int speed[] = {10,20};
				int cores[] = {2,4};
				_expected = 40LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 2:
			{
				long long jobLength = 1000LL;
				int corePenalty = 0;
				int speed[] = {10};
				int cores[] = {3};
				_expected = 34LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			case 3:
			{
				long long jobLength = 10000LL;
				int corePenalty = 5;
				int speed[] = {39,37,44};
				int cores[] = {8,16,6};
				_expected = 63LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}
			/*case 4:
			{
				long long jobLength = LL;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				long long jobLength = LL;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				long long jobLength = LL;
				int corePenalty = ;
				int speed[] = ;
				int cores[] = ;
				_expected = LL;
				_received = _obj.fastestTime(jobLength, corePenalty, vector <int>(speed, speed+sizeof(speed)/sizeof(int)), vector <int>(cores, cores+sizeof(cores)/sizeof(int))); break;
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
