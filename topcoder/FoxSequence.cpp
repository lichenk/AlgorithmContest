#include <bits/stdc++.h>
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
class FoxSequence {
	public:
	string isValid(vector <int> a) {
		ll n=a.size();
		ll state=0;
		ll old=INF;
		for (ll x=0;x<n-1;x++) {
			ll d=a[x+1]-a[x];
			if (d!=old) {
				state++;
				old=d;
				if (state==3&&old>0) state++;
				//printf("d:%lld old:%lld state:%lld\n",d,old,state);
				if (state==1&&!(d>0)) return "NO";
				if (state==2&&!(d<0)) return "NO";
				if (state==3&&!(d==0)) return "NO";
				if (state==4&&!(d>0)) return "NO";
				if (state==5&&!(d<0)) return "NO";
				if (state>5) return "NO";
			}
		}
		if (state!=5) return "NO";
		return "YES";
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
		cout << "Testing FoxSequence (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484459447;
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
		FoxSequence _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int seq[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1};
				_expected = "YES";
				_received = _obj.isValid(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 1:
			{
				int seq[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4};
				_expected = "YES";
				_received = _obj.isValid(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 2:
			{
				int seq[] = {3,6,9,1,9,5,1};
				_expected = "YES";
				_received = _obj.isValid(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 3:
			{
				int seq[] = {1,2,3,2,1,2,3,2,1,2,3,2,1};
				_expected = "NO";
				_received = _obj.isValid(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 4:
			{
				int seq[] = {1,3,4,3,1,1,1,1,3,4,3,1};
				_expected = "NO";
				_received = _obj.isValid(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 5:
			{
				int seq[] = {6,1,6};
				_expected = "NO";
				_received = _obj.isValid(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 6:
			{
				int seq[] = {1};
				_expected = "NO";
				_received = _obj.isValid(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			/*case 7:
			{
				int seq[] = ;
				_expected = ;
				_received = _obj.isValid(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int seq[] = ;
				_expected = ;
				_received = _obj.isValid(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
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
