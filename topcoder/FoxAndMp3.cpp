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
class FoxAndMp3 {
	public:
	vector <string> playList(int _n) {
		ll n=_n;
		set<string> ans;
		vector<string> final;
		if (n<=50) {
			for (ll x=1;x<=n;x++) {
				string s=to_string(x);
				ans.insert(s);
			}
		}
		else {
			ll y;
			for (ll x=1;x<=n;x*=10) {
				string s=to_string(x);
				ans.insert(s);
				y=x;
			}
			while (y>0) {
				for (ll x=y;x<=min(y+51,n);x++) {
					string s=to_string(x);
					ans.insert(s);
				}
				y/=10;
			}
		}
		ll cnt=0;
		for (auto &w: ans) {
			final.PB(w+".mp3");
			cnt++;
			if (cnt>=50) break;
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
		cout << "Testing FoxAndMp3 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459096405;
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
		FoxAndMp3 _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				string __expected[] = {"1.mp3", "2.mp3", "3.mp3" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.playList(n); break;
			}
			case 1:
			{
				int n = 10;
				string __expected[] = {"1.mp3", "10.mp3", "2.mp3", "3.mp3", "4.mp3", "5.mp3", "6.mp3", "7.mp3", "8.mp3", "9.mp3" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.playList(n); break;
			}
			case 2:
			{
				int n = 16;
				string __expected[] = {"1.mp3", "10.mp3", "11.mp3", "12.mp3", "13.mp3", "14.mp3", "15.mp3", "16.mp3", "2.mp3", "3.mp3", "4.mp3", "5.mp3", "6.mp3", "7.mp3", "8.mp3", "9.mp3" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.playList(n); break;
			}
			case 3:
			{
				int n = 32;
				string __expected[] = {"1.mp3", "10.mp3", "11.mp3", "12.mp3", "13.mp3", "14.mp3", "15.mp3", "16.mp3", "17.mp3", "18.mp3", "19.mp3", "2.mp3", "20.mp3", "21.mp3", "22.mp3", "23.mp3", "24.mp3", "25.mp3", "26.mp3", "27.mp3", "28.mp3", "29.mp3", "3.mp3", "30.mp3", "31.mp3", "32.mp3", "4.mp3", "5.mp3", "6.mp3", "7.mp3", "8.mp3", "9.mp3" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.playList(n); break;
			}
			case 4:
			{
				int n = 100000009;
				string __expected[] = {"1.mp3", "10.mp3", "100.mp3", "1000.mp3", "10000.mp3", "100000.mp3", "1000000.mp3", "10000000.mp3", "100000000.mp3", "100000001.mp3", "100000002.mp3", "100000003.mp3", "100000004.mp3", "100000005.mp3", "100000006.mp3", "100000007.mp3", "100000008.mp3", "100000009.mp3", "10000001.mp3", "10000002.mp3", "10000003.mp3", "10000004.mp3", "10000005.mp3", "10000006.mp3", "10000007.mp3", "10000008.mp3", "10000009.mp3", "1000001.mp3", "10000010.mp3", "10000011.mp3", "10000012.mp3", "10000013.mp3", "10000014.mp3", "10000015.mp3", "10000016.mp3", "10000017.mp3", "10000018.mp3", "10000019.mp3", "1000002.mp3", "10000020.mp3", "10000021.mp3", "10000022.mp3", "10000023.mp3", "10000024.mp3", "10000025.mp3", "10000026.mp3", "10000027.mp3", "10000028.mp3", "10000029.mp3", "1000003.mp3" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.playList(n); break;
			}
			case 5:
			{
				int n = 1;
				string __expected[] = {"1.mp3" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.playList(n); break;
			}
			/*case 6:
			{
				int n = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.playList(n); break;
			}*/
			/*case 7:
			{
				int n = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.playList(n); break;
			}*/
			/*case 8:
			{
				int n = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.playList(n); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
