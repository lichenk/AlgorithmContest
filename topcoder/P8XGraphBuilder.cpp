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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=205;
ll f[mn][mn];
class P8XGraphBuilder {
	public:
	int solve(vector <int> scores) {
		for (ll x=0;x<mn;x++) for (ll y=0;y<mn;y++) f[x][y]=-INF;
		f[0][0]=0;
		ll n=scores.size()+1;
		ll elim=2*n-2;
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<=elim;y++) {
				if (f[x][y]<0) continue;
				for (ll adde=1;adde<n;adde++) {
					ll z=y+adde;
					if (z<=elim) {
						ll add=scores[adde-1];
						//printf("%lld %lld->%lld %lld. %lld+%lld\n",x,y,x+1,z,f[x][y],add);
						chkmax(f[x+1][z],f[x][y]+add);
					}
				}
			}
		}
		ll ans=f[n][2*n-2];
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
		cout << "Testing P8XGraphBuilder (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472620203;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		P8XGraphBuilder _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int scores[] = {1, 3, 0};
				_expected = 8;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 1:
			{
				int scores[] = {0, 0, 0, 10};
				_expected = 10;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 2:
			{
				int scores[] = {1, 2, 3, 4, 5, 6};
				_expected = 12;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 3:
			{
				int scores[] = {5, 0, 0};
				_expected = 15;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			case 4:
			{
				int scores[] = {1, 3, 2, 5, 3, 7, 5};
				_expected = 20;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}
			/*case 5:
			{
				int scores[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int scores[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int scores[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(scores, scores+sizeof(scores)/sizeof(int))); break;
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
