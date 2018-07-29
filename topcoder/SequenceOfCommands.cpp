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
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
class SequenceOfCommands {
	public:
	string whatHappens(vector <string> commands) {
		int x=0,y=0,k=0;

		for (int t=0;t<4;t++) for (auto &v:commands) for (auto &w:v) {
			if (w=='S') x+=dx[k],y+=dy[k];
			else if (w=='L') k=(k+1)%4;
			else k=(k+3)%4;
			//printf("x:%d y:%d\n",x,y);
		}
		if (x==0&&y==0) return "bounded";
		else return "unbounded";
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
		cout << "Testing SequenceOfCommands (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1501772575;
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
		SequenceOfCommands _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string commands[] = {"L"};
				_expected = "bounded";
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			case 1:
			{
				string commands[] = {"SRSL"};
				_expected = "unbounded";
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			case 2:
			{
				string commands[] = {"SSSS","R"};
				_expected = "bounded";
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			case 3:
			{
				string commands[] = {"SRSL","LLSSSSSSL","SSSSSS","L"};
				_expected = "unbounded";
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			/*case 4:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.whatHappens(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
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
