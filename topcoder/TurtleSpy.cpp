#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
vector<ll> go[2];
vector<ll> dir;
bool f[55][360];
class TurtleSpy {
	public:
	double maxDistance(vector <string> commands) {
		ld fwd=0,bak=0;
		for (auto &s:commands) {
			stringstream in(s);
			string cmd; ll x;
			in>>cmd>>x;
			if (cmd=="forward") {
				fwd+=x;
				go[0].PB(x);
			}
			else if (cmd=="backward") {
				bak+=x;
				go[1].PB(x);
			}
			else if (cmd=="left") {
				dir.PB(x);
			}
			else {
				assert(cmd=="right");
				dir.PB(-x);
			}
		}
		ll n=dir.size();
		for (ll x=0;x<55;x++) for (ll y=0;y<360;y++) f[x][y]=false;
		f[0][0]=true;
		for (ll x=0;x<n;x++) {
			ll a=dir[x];
			for (ll y=0;y<360;y++) {
				if (f[x][y]) {
					//pr("%lld %lld %lld->%lld\n",x,y,a,(y+a)%360);
					f[x+1][y]=true;
					f[x+1][(y+a+360)%360]=true;
					//f[x+1][(y-a+360)%360]=true;
				}
			}
		}
		ll mindeg=359;
		for (ll y=0;y<360;y++) {
			if (f[n][y])chkmin(mindeg,abs(180-y));
		}
		//pr("%f %f %lld\n",fwd,bak,mindeg);
		if (fwd<bak) swap(fwd,bak);
		assert(fwd>=bak);
		ld radian=mindeg;
		radian=(radian/180)*M_PI;
		ld x=fwd+bak*cos(radian);
		ld y=bak*sin(radian);
		return sqrt(x*x+y*y);
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
		cout << "Testing TurtleSpy (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471614436;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TurtleSpy _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string commands[] = {"forward 100", "backward 100", "left 90" };
				_expected = 141.4213562373095;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			case 1:
			{
				string commands[] = {"left 45", "forward 100", "right 45", "forward 100"};
				_expected = 200.0;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			case 2:
			{
				string commands[] = {"left 10", "forward 40",  "right 30", "left 10", "backward 4", "forward 4" };
				_expected = 40.58520737741619;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}
			/*case 3:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string commands[] = ;
				_expected = ;
				_received = _obj.maxDistance(vector <string>(commands, commands+sizeof(commands)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
