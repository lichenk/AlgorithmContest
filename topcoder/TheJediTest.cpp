#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<62ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll a[30];
ll b[30];
class TheJediTest {
	public:
	int minimumSupervisors(vector <int> students, int K) {
		ll n=students.size();
		ll lim=1ULL<<(n-1);
		ll final=INF;
		for (ll z=0;z<lim;z++) {
			for (ll x=0;x<n;x++) {
				a[x]=students[x];
				b[x]=0;
			}
			for (ll x=0;x<n-1;x++) {
				if ((1ULL<<x)&z) {
					// Suck
					ll suck = (K-((a[x]+b[x])%K))%K;
					suck=min(suck,a[x+1]);
					a[x]+=suck;
					a[x+1]-=suck;
				}
				else {
					// Push
					ll push=a[x]%K;
					a[x]-=push;
					b[x+1]+=push;
				}
			}
			ll ans=0;
			//if(ans==0) printf("%lld\n",z);
			for (ll x=0;x<n;x++) {
				//printf("%lld %lld\n",a[x],b[x]);
				ans+=((a[x]+b[x]+K-1)/K);
			}
			final=min(final,ans);
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
		cout << "Testing TheJediTest (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459135160;
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
		TheJediTest _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int students[] = {3, 6, 3};
				int K = 4;
				_expected = 3;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}
			case 1:
			{
				int students[] = {1, 1, 1, 1};
				int K = 4;
				_expected = 2;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}
			case 2:
			{
				int students[] = {0, 0, 0, 0};
				int K = 12345;
				_expected = 0;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}
			case 3:
			{
				int students[] = {15, 0, 13, 4, 29, 6, 2};
				int K = 7;
				_expected = 10;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}
			case 4:
			{
				int students[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68};
				int K = 114;
				_expected = 102138;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int students[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int students[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int students[] = ;
				int K = ;
				_expected = ;
				_received = _obj.minimumSupervisors(vector <int>(students, students+sizeof(students)/sizeof(int)), K); break;
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
