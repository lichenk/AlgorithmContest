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
bool overflow(ll a, ll b) {
	ll x = a * b;
	return  (a != 0 && x / a != b);
}
class BuffingPixie {
	public:
	int fastestVictory(int HP, int normalAttack, int buffedAttack) {
			ll imin=0,imax=1e9+1;
			while(imin<imax) {
				ll imid=imin+(imax-imin)/2;
				ll buffed=imid/2;
				ll norm=imid%2;
				ll res=buffedAttack*buffed+norm;
				if (!overflow(buffedAttack,buffed)&&res>=0&&res<HP) imin=imid+1;
				else imax=imid;
			}
			return min(imin,(ll)(HP+normalAttack-1)/normalAttack);
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
		cout << "Testing BuffingPixie (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472960895;
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
		BuffingPixie _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int HP = 5;
				int normalAttack = 1;
				int buffedAttack = 3;
				_expected = 4;
				_received = _obj.fastestVictory(HP, normalAttack, buffedAttack); break;
			}
			case 1:
			{
				int HP = 10;
				int normalAttack = 20;
				int buffedAttack = 50;
				_expected = 1;
				_received = _obj.fastestVictory(HP, normalAttack, buffedAttack); break;
			}
			case 2:
			{
				int HP = 24;
				int normalAttack = 2;
				int buffedAttack = 5;
				_expected = 10;
				_received = _obj.fastestVictory(HP, normalAttack, buffedAttack); break;
			}
			case 3:
			{
				int HP = 497;
				int normalAttack = 40;
				int buffedAttack = 45;
				_expected = 13;
				_received = _obj.fastestVictory(HP, normalAttack, buffedAttack); break;
			}
			case 4:
			{
				int HP = 8400;
				int normalAttack = 1;
				int buffedAttack = 5;
				_expected = 3360;
				_received = _obj.fastestVictory(HP, normalAttack, buffedAttack); break;
			}
			case 5:
			{
				int HP = 10;
				int normalAttack = 2;
				int buffedAttack = 1;
				_expected = 5;
				_received = _obj.fastestVictory(HP, normalAttack, buffedAttack); break;
			}
			/*case 6:
			{
				int HP = ;
				int normalAttack = ;
				int buffedAttack = ;
				_expected = ;
				_received = _obj.fastestVictory(HP, normalAttack, buffedAttack); break;
			}*/
			/*case 7:
			{
				int HP = ;
				int normalAttack = ;
				int buffedAttack = ;
				_expected = ;
				_received = _obj.fastestVictory(HP, normalAttack, buffedAttack); break;
			}*/
			/*case 8:
			{
				int HP = ;
				int normalAttack = ;
				int buffedAttack = ;
				_expected = ;
				_received = _obj.fastestVictory(HP, normalAttack, buffedAttack); break;
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
