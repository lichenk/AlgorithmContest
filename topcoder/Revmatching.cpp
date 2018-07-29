#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<40ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll f[22];
class Revmatching {
	public:
	int smallest(vector <string> A) {
		ll n=A.size();
		ll zlim=1ULL<<n;
		ll ans=INF;
		for (ll z=1;z<zlim;z++) {
			for (ll y=0;y<n;y++) {
				f[y]=0;
			}
			for (ll x=0;x<n;x++) {
				if ((1ULL<<x)&z) {
					for (ll y=0;y<n;y++) {
						if (A[x][y]!='0') {
							f[y]+=(A[x][y]-'0');
						}
					}
				}
			}
			ll ycnt=0;
			for (ll y=0;y<n;y++) {
				if (f[y]==0) f[y]=INF;
				else ycnt++;
			}
			ll need = ycnt-__builtin_popcountll(z)+1;
			ll sum=0;
			sort(f,f+n);
			for (ll i=0;i<need;i++) {
				sum+=f[i];
			}
			ans=min(ans,sum);
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
		cout << "Testing Revmatching (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458961722;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Revmatching _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A[] = {"1"};
				_expected = 1;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 1:
			{
				string A[] = {"0"};
				_expected = 0;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 2:
			{
				string A[] = {"44","44"};
				_expected = 8;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 3:
			{
				string A[] = {"861","870","245"};
				_expected = 6;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 4:
			{
				string A[] = {"01000","30200","11102","10001","11001"};
				_expected = 0;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			case 5:
			{
				string A[] = {"0111101100","0001101001","1001001000","1000100001","0110011111","0011110100","1000001100","0001100000","1000100001","0101110010"};
				_expected = 1;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}
			/*case 6:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string A[] = ;
				_expected = ;
				_received = _obj.smallest(vector <string>(A, A+sizeof(A)/sizeof(string))); break;
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
