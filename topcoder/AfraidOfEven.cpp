#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef __int128 ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll lim=(1LL<<31)-1;
ll labs(ll x) {
	return (x>=0)?x:-x;
}
class AfraidOfEven {
	public:
	vector <int> restoreProgression(vector <int> v) {
		ll n=v.size();
		vector<int> final;
		const ll m=30;
		for (ll a=0;a<m;a++) {
			ll c0=v[0];
			for (ll i=0;i<a;i++) c0*=2;
			if (c0>(lim)) break;
			for (ll b=0;b<m;b++) {
				ll c1=v[1];
				for (ll i=0;i<b;i++) c1*=2;
				if (c1>(lim)) break;
				ll d=c1-c0;
				bool bad=false;
				for (ll i=2;i<n;i++) {
					ll want=c0+i*d;
					if (labs(want)>lim) {
						bad=true;
						break;
					}
					while(want>0&&want%2==0) want/=2;
					if (want!=v[i]) {
						bad=true;
						break;
					}
				}
				if (!bad) {
					vector<int> ans;
					for (ll i=0;i<n;i++) {
						ans.PB(c0+d*i);
					}
					if (final.size()==0) final=ans;
					chkmin(final,ans);
				}
			}
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
		cout << "Testing AfraidOfEven (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487911220;
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
		AfraidOfEven _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int seq[] = {1, 1, 3, 1, 5};
				int __expected[] = {1, 2, 3, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 1:
			{
				int seq[] = {9, 7, 5, 3, 1};
				int __expected[] = {9, 7, 5, 3, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 2:
			{
				int seq[] = {999, 999, 999, 999};
				int __expected[] = {999, 999, 999, 999 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 3:
			{
				int seq[] = {7, 47, 5, 113, 73, 179, 53};
				int __expected[] = {14, 47, 80, 113, 146, 179, 212 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 4:
			{
				int seq[] = {749, 999, 125, 1};
				int __expected[] = {1498, 999, 500, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			/*case 5:
			{
				int seq[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int seq[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int seq[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.restoreProgression(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
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
