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

class SpaceWarDiv1 {
	public:
	long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount) {
		vector<int> mgs = magicalGirlStrength;
		sort(mgs.begin(),mgs.end());
		vector<pair<ll,ll> > vorig;
		for (ll i=0;i<enemyCount.size();i++) {
			vorig.PB(MP((ll)enemyStrength[i],enemyCount[i]));
		}
		sort(vorig.begin(),vorig.end(),greater<pair<ll,ll> >());
		ll en=enemyCount.size();
		vector<pair<ll,ll> > v;
		ll mgss=mgs.size();
		sort(v.begin(),v.end());
		ll imin=0; ll imax=1e18;
		while (imin<imax) {
			ll imid=imin+(imax-imin)/2;
			{
				v=vorig;
				//printf("imid:%lld\n");
				for (ll i=0;i<mgss;i++) {
					ll left=imid;
					for (ll j=0;j<en;j++) {
						if (v[j].first>mgs[i]) continue;
						ll take = min(v[j].second,left);
						v[j].second -= take;
						left-=take;
					}
				}
				bool ok=true;
				for (ll j=0;j<en;j++) {
					if (v[j].second>0) {ok=false;break;}
				}
				if(!ok){
					imin=imid+1;
				}
				else {
					imax=imid;
				}
			}
		}
		if (imin>1e17) return -1;
		return imin;
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
		cout << "Testing SpaceWarDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456709175;
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
		SpaceWarDiv1 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int magicalGirlStrength[] = {2, 3, 5};
				int enemyStrength[] = {1, 3, 4};
				long long enemyCount[] = {2, 9, 4};
				_expected = 7LL;
				_received = _obj.minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength+sizeof(magicalGirlStrength)/sizeof(int)), vector <int>(enemyStrength, enemyStrength+sizeof(enemyStrength)/sizeof(int)), vector<long long>(enemyCount, enemyCount+sizeof(enemyCount)/sizeof(long long))); break;
			}
			case 1:
			{
				int magicalGirlStrength[] = {2, 3, 5};
				int enemyStrength[] = {1, 1, 2};
				long long enemyCount[] = {2, 9, 4};
				_expected = 5LL;
				_received = _obj.minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength+sizeof(magicalGirlStrength)/sizeof(int)), vector <int>(enemyStrength, enemyStrength+sizeof(enemyStrength)/sizeof(int)), vector<long long>(enemyCount, enemyCount+sizeof(enemyCount)/sizeof(long long))); break;
			}
			case 2:
			{
				int magicalGirlStrength[] = {14, 6, 22};
				int enemyStrength[] = {8, 33};
				long long enemyCount[] = {9, 1};
				_expected = -1LL;
				_received = _obj.minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength+sizeof(magicalGirlStrength)/sizeof(int)), vector <int>(enemyStrength, enemyStrength+sizeof(enemyStrength)/sizeof(int)), vector<long long>(enemyCount, enemyCount+sizeof(enemyCount)/sizeof(long long))); break;
			}
			case 3:
			{
				int magicalGirlStrength[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417};
				int enemyStrength[] = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307};
				long long enemyCount[] = {20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
				                          61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
				                          78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296};
				_expected = 75030497287405LL;
				_received = _obj.minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength+sizeof(magicalGirlStrength)/sizeof(int)), vector <int>(enemyStrength, enemyStrength+sizeof(enemyStrength)/sizeof(int)), vector<long long>(enemyCount, enemyCount+sizeof(enemyCount)/sizeof(long long))); break;
			}
			/*case 4:
			{
				int magicalGirlStrength[] = ;
				int enemyStrength[] = ;
				long long enemyCount[] = ;
				_expected = LL;
				_received = _obj.minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength+sizeof(magicalGirlStrength)/sizeof(int)), vector <int>(enemyStrength, enemyStrength+sizeof(enemyStrength)/sizeof(int)), vector<long long>(enemyCount, enemyCount+sizeof(enemyCount)/sizeof(long long))); break;
			}*/
			/*case 5:
			{
				int magicalGirlStrength[] = ;
				int enemyStrength[] = ;
				long long enemyCount[] = ;
				_expected = LL;
				_received = _obj.minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength+sizeof(magicalGirlStrength)/sizeof(int)), vector <int>(enemyStrength, enemyStrength+sizeof(enemyStrength)/sizeof(int)), vector<long long>(enemyCount, enemyCount+sizeof(enemyCount)/sizeof(long long))); break;
			}*/
			/*case 6:
			{
				int magicalGirlStrength[] = ;
				int enemyStrength[] = ;
				long long enemyCount[] = ;
				_expected = LL;
				_received = _obj.minimalFatigue(vector <int>(magicalGirlStrength, magicalGirlStrength+sizeof(magicalGirlStrength)/sizeof(int)), vector <int>(enemyStrength, enemyStrength+sizeof(enemyStrength)/sizeof(int)), vector<long long>(enemyCount, enemyCount+sizeof(enemyCount)/sizeof(long long))); break;
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
