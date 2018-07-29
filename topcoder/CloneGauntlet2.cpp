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
const ll mn=54;
vector<ll> g[mn];
class CloneGauntlet2 {
	public:
	int minClones(vector <int> parent, vector <int> connection) {
		ll n=connection.size();
		for (ll i=0;i<n-1;i++) {
			g[parent[i]].PB(i+1);
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
		cout << "Testing CloneGauntlet2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1473091800;
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
		CloneGauntlet2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {0,0};
				int connection[] = {1,2,0};
				_expected = 1;
				_received = _obj.minClones(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(connection, connection+sizeof(connection)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {0};
				int connection[] = {0,0};
				_expected = -1;
				_received = _obj.minClones(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(connection, connection+sizeof(connection)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {0};
				int connection[] = {1,1};
				_expected = 1;
				_received = _obj.minClones(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(connection, connection+sizeof(connection)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {0,0,0,0};
				int connection[] = {1,2,4,4,4};
				_expected = 2;
				_received = _obj.minClones(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(connection, connection+sizeof(connection)/sizeof(int))); break;
			}
			case 4:
			{
				int parent[] = {0,1,2,3,0,5,6,7};
				int connection[] = {1,5,6,7,8,2,3,4,0};
				_expected = 4;
				_received = _obj.minClones(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(connection, connection+sizeof(connection)/sizeof(int))); break;
			}
			/*case 5:
			{
				int parent[] = ;
				int connection[] = ;
				_expected = ;
				_received = _obj.minClones(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(connection, connection+sizeof(connection)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int connection[] = ;
				_expected = ;
				_received = _obj.minClones(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(connection, connection+sizeof(connection)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int parent[] = ;
				int connection[] = ;
				_expected = ;
				_received = _obj.minClones(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(connection, connection+sizeof(connection)/sizeof(int))); break;
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
