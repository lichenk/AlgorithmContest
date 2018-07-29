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
class RouteIntersection {
	public:
	string isValid(int N, vector <int> coords, string moves) {
		int sz=coords.size();
		set<map<int,int> > s;
		map<int,int> h;
		s.insert(h);
		for (int i=0;i<sz;i++) {
			if (moves[i]=='+') {
				if((++h[coords[i]]) == 0) {
					h.erase(coords[i]);
				}
			}
			else {
				if((--h[coords[i]]) == 0) {
					h.erase(coords[i]);
				}
			}
			if (s.find(h)!=s.end()) return "NOT VALID";
			s.insert(h);
		}
		return "VALID";
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
		cout << "Testing RouteIntersection (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1501515139;
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
		RouteIntersection _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 1;
				int coords[] = {1};
				string moves = "+";
				_expected = "VALID";
				_received = _obj.isValid(N, vector <int>(coords, coords+sizeof(coords)/sizeof(int)), moves); break;
			}
			case 1:
			{
				int N = 2;
				int coords[] = {1,2,1,2};
				string moves = "++--";
				_expected = "NOT VALID";
				_received = _obj.isValid(N, vector <int>(coords, coords+sizeof(coords)/sizeof(int)), moves); break;
			}
			case 2:
			{
				int N = 3;
				int coords[] = {1,2,3,1,2};
				string moves = "+++--";
				_expected = "VALID";
				_received = _obj.isValid(N, vector <int>(coords, coords+sizeof(coords)/sizeof(int)), moves); break;
			}
			case 3:
			{
				int N = 344447;
				int coords[] = {132,51717,628,344447,628,51717,344447,2};
				string moves = "+-++-+--";
				_expected = "NOT VALID";
				_received = _obj.isValid(N, vector <int>(coords, coords+sizeof(coords)/sizeof(int)), moves); break;
			}
			case 4:
			{
				int N = 1;
				int coords[] = {1,1};
				string moves = "+-";
				_expected = "NOT VALID";
				_received = _obj.isValid(N, vector <int>(coords, coords+sizeof(coords)/sizeof(int)), moves); break;
			}
			case 5:
			{
				int N = 990630;
				int coords[] = {833196,524568,361663,108056,28026,824639,269315,440977,440977,765458,
				               988451,242440,948414,130873,773990,765458,130873,28026,853121,553636,
				               581069,82254,735536,833196,898562,898562,940783,988451,540613,317306,
				               623194,940783,571384,988451,108056,514374,97664};
				string moves = "--+---+-+++-+-+---++-++-+---+-+--+-++";
				_expected = "NOT VALID";
				_received = _obj.isValid(N, vector <int>(coords, coords+sizeof(coords)/sizeof(int)), moves); break;
			}
			case 6:
			{
				int N = 2;
				int coords[] = {1,2,2};
				string moves = "++-";
				_expected = "NOT VALID";
				_received = _obj.isValid(N, vector <int>(coords, coords+sizeof(coords)/sizeof(int)), moves); break;
			}
			/*case 7:
			{
				int N = ;
				int coords[] = ;
				string moves = ;
				_expected = ;
				_received = _obj.isValid(N, vector <int>(coords, coords+sizeof(coords)/sizeof(int)), moves); break;
			}*/
			/*case 8:
			{
				int N = ;
				int coords[] = ;
				string moves = ;
				_expected = ;
				_received = _obj.isValid(N, vector <int>(coords, coords+sizeof(coords)/sizeof(int)), moves); break;
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
