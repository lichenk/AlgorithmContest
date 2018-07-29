#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=1e5+4;
bool a[mn];
class CompositeSmash {
	public:
	string thePossible(int N, int target) {
		memset(a,0,sizeof a);
		for (ll x=2;x<=N;x++) {
			if (x==target) continue;
			ll dlim=min((ll)sqrt(x)+2,x);
			bool isprime=true;
			for (ll y=2;y<dlim;y++) {
				if (x%y==0) {
					isprime=false;
					if (a[y]&&a[x/y]) {
						a[x]=true;
						break;
					}
				}
			}
			if (isprime) a[x]=true;
		}
		if (a[N]) return "No";
		else return "Yes";
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
		cout << "Testing CompositeSmash (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483772514;
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
		CompositeSmash _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 517;
				int target = 47;
				_expected = "Yes";
				_received = _obj.thePossible(N, target); break;
			}
			case 1:
			{
				int N = 8;
				int target = 4;
				_expected = "Yes";
				_received = _obj.thePossible(N, target); break;
			}
			case 2:
			{
				int N = 12;
				int target = 6;
				_expected = "No";
				_received = _obj.thePossible(N, target); break;
			}
			case 3:
			{
				int N = 5;
				int target = 8;
				_expected = "No";
				_received = _obj.thePossible(N, target); break;
			}
			case 4:
			{
				int N = 100000;
				int target = 100000;
				_expected = "Yes";
				_received = _obj.thePossible(N, target); break;
			}
			case 5:
			{
				int N = 5858;
				int target = 2;
				_expected = "Yes";
				_received = _obj.thePossible(N, target); break;
			}
			case 6:
			{
				int N = 81461;
				int target = 2809;
				_expected = "No";
				_received = _obj.thePossible(N, target); break;
			}
			case 7:
			{
				int N = 65536;
				int target = 256;
				_expected = "No";
				_received = _obj.thePossible(N, target); break;
			}
			/*case 8:
			{
				int N = ;
				int target = ;
				_expected = ;
				_received = _obj.thePossible(N, target); break;
			}*/
			/*case 9:
			{
				int N = ;
				int target = ;
				_expected = ;
				_received = _obj.thePossible(N, target); break;
			}*/
			/*case 10:
			{
				int N = ;
				int target = ;
				_expected = ;
				_received = _obj.thePossible(N, target); break;
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
