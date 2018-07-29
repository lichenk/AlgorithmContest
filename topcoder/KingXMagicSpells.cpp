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
ld f[55][55][32][2];
class KingXMagicSpells {
	public:
	double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K) {
		ll n=ducks.size();
		for (ll t=0;t<K;t++) for (ll d=0;d<n;d++) for (ll b=0;b<32;b++) for (ll r=0;r<2;r++) f[t][d][b][r]=0;
		for (ll d=0;d<n;d++)for (ll b=0;b<32;b++)  {
			f[0][d][b][1]=(ducks[d]>>b)&1;
			f[0][d][b][0]=1-f[0][d][b][1];
		}
		for (ll t=0;t<K;t++) {
			for (ll d=0;d<n;d++) for (ll b=0;b<32;b++) for (ll r=0;r<2;r++) {
				ld v=f[t][d][b][r]/2.0;
				{
					ll one=1&(spellOne[d]>>b);
					f[t+1][d][b][r^one]+=v;
					//if (v>0) printf("so: %d %d %d %f\n",t+1,d,b^one,v);
				}
				{
					f[t+1][spellTwo[d]][b][r]+=v;
					//if (v>0) printf("st: %d %d %d %f\n",t+1,spellTwo[d],b,v);
				}
			}
		}
		ld ans=0;
		for (ll b=0;b<32;b++) {
			ans+=(f[K][0][b][1]*(1LL<<b));
		}
		return ans;
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
		cout << "Testing KingXMagicSpells (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471616505;
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
		KingXMagicSpells _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int ducks[] = {5, 3, 7};
				int spellOne[] = {1, 7, 4};
				int spellTwo[] = {1, 0, 2};
				int K = 1;
				_expected = 3.5;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}
			case 1:
			{
				int ducks[] = {5, 8};
				int spellOne[] = {53, 7};
				int spellTwo[] = {1, 0};
				int K = 2;
				_expected = 21.5;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}
			case 2:
			{
				int ducks[] = {123, 456, 789, 1234, 56789};
				int spellOne[] = {0, 0, 0, 0, 0};
				int spellTwo[] = {0, 1, 2, 3, 4};
				int K = 50;
				_expected = 123.0;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}
			case 3:
			{
				int ducks[] = {83291232, 3124231, 192412, 3813249, 629231, 9998989};
				int spellOne[] = {58, 37, 44, 66, 72, 19};
				int spellTwo[] = {2, 0, 1, 5, 4, 3};
				int K = 11;
				_expected = 2.888186784716797E7;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}
			/*case 4:
			{
				int ducks[] = ;
				int spellOne[] = ;
				int spellTwo[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}*/
			/*case 5:
			{
				int ducks[] = ;
				int spellOne[] = ;
				int spellTwo[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int ducks[] = ;
				int spellOne[] = ;
				int spellTwo[] = ;
				int K = ;
				_expected = ;
				_received = _obj.expectedNumber(vector <int>(ducks, ducks+sizeof(ducks)/sizeof(int)), vector <int>(spellOne, spellOne+sizeof(spellOne)/sizeof(int)), vector <int>(spellTwo, spellTwo+sizeof(spellTwo)/sizeof(int)), K); break;
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
