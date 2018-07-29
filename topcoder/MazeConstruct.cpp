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
class MazeConstruct {
	public:
	vector <string> construct(int k) {
		for (ll r=1;r<=25;r+=2) {
			for (ll d=2;d<=49;d++) {
				ll cut=d*((r-1)/2);
				ll now=r*d+(r-1)*2;
				ll extra=(now-k);
				if (extra<0) continue;
				if (0!=(extra%2)) continue;
				extra/=2;
				if (extra<=cut) {
					vector<string> ans;
					ll h=(2*r-1);
					ans.resize(h);
					ll w=d+1;
					for (ll x=0;x<h;x++) ans[x].resize(w);
					for (ll x=0;x<h;x++) for (ll y=0;y<w;y++) {
						ans[x][y]='.';
					}
					for (ll x=1;x<h;x+=4) {
						for (ll y=0;y<w-1;y++) ans[x][y]='#';
					}
					for (ll x=3;x<h;x+=4) {
						for (ll y=1;y<w;y++) ans[x][y]='#';
					}
					{
						for (ll x=3;x<h;x+=4) {
							ll take=min(extra,d);
							extra-=take;
							ans[x][take]='.';
						}
					}
					return ans;
				}
			}
		}
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
		cout << "Testing MazeConstruct (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485828002;
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
		MazeConstruct _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 3;
				string __expected[] = {"...." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 1:
			{
				int k = 4;
				string __expected[] = {"...", "...", "..." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 2:
			{
				int k = 10;
				string __expected[] = {"..#..", "#.#..", "..#..", ".#...", "....." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 3:
			{
				int k = 1000;
				string __expected[] = {"."};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			case 4:
			{
				int k = 50;
				string __expected[] = {"#"};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
			}
			/*case 5:
			{
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(k); break;
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
