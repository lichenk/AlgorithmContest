#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const int INF = 1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef vector<int> vi;
vector<int> gl,gs;
int n;
const int MN=20;
const int START=74;
const int INC=47;
//const int MAXS=START+INC*MN;
int dp[1<<MN];
int gets(int z) {
	int scare=START;
	for (int x=0;x<n;x++) {
		if (z&(1<<x)) {
			scare+=INC-gl[x];
		}
	}
	return scare;	
}
bool cantrans(int scare, int x) {
		int atvs=scare-gs[x];
		if (atvs<0) return false;
		int atend=scare+INC-gl[x];
		if (atend<0) return false;
		return true;
}
int f(int z) {
	if (dp[z]!=-1) return dp[z];
	int scare=gets(z);
	int ans=0;
	for (int x=0;x<n;x++) {
		if (z&(1<<x)) continue;
		if (cantrans(scare,x)) {
			int nz=z|(1<<x);
			int cand=f(nz)+1;
			chkmax(ans,cand);
		}
	}
	return dp[z]=ans;
}

class TheMoviesLevelTwoDivOne {
	public:
	vector <int> find(vector <int> vl, vector <int> vs) {
		gl=vl,gs=vs,n=vl.size();
		memset(dp,-1,sizeof dp);
		vi vans;
		int z=0;
		for (int i=0;i<n;i++) {
			pair<int,int> best=MP(-INF,INF);
			int scare=gets(z);
			for (int x=0;x<n;x++) {
				if (z&(1<<x)) continue;
				if (cantrans(scare,x)) {
					auto cand=MP(f(z|(1<<x)),-x);
					//printf("i:%d x:%d z:%d cand:%d\n",i,x,z,f(z|(1<<x)));
					chkmax(best,cand);
				}
			}
			if (best.first==-INF) {
				for (int x=0;x<n;x++) {
					if (z&(1<<x)) continue;
					else {best=MP(0,-x); break;}
				}
			}
			z|=1<<(-best.second);
			vans.PB(-best.second);
		}
		return vans;
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
		cout << "Testing TheMoviesLevelTwoDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521477647;
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
		TheMoviesLevelTwoDivOne _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int length[] = {100, 50};
				int scary[] = {1, 1};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 1:
			{
				int length[] = {100, 50};
				int scary[] = {1, 49};
				int __expected[] = {1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 2:
			{
				int length[] = {100, 100, 100, 100};
				int scary[] = {77, 76, 75, 74};
				int __expected[] = {3, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 3:
			{
				int length[] = {100};
				int scary[] = {99};
				int __expected[] = {0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 4:
			{
				int length[] = {100,75};
				int scary[] = {99,74};
				int __expected[] = {1,0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 5:
			{
				int length[] = {100,76};
				int scary[] = {99,75};
				int __expected[] = {0,1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 6:
			{
				int length[] = {100,75,47};
				int scary[] = {99,74,46};
				int __expected[] = {1,2,0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 7:
			{
				int length[] = {100,75,48};
				int scary[] = {99,74,47};
				int __expected[] = {1,0,2};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vector <int>(length, length+sizeof(length)/sizeof(int)), vector <int>(scary, scary+sizeof(scary)/sizeof(int))); break;
			}
			case 8:
			{
				vi vl,vs;
				for (int i=0;i<20;i++) {
					vl.PB(47);
					vs.PB(46);
				}
				int __expected[] = {-1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.find(vl,vs); break;
			}
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
