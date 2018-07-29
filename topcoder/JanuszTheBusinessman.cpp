#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 108
bool overlap(ll al, ll ah, ll bl, ll bh) {
	for (ll x = al; x <= ah; x++) {
		if (bl <= x && x <= bh) {
			return true;
		}
	}
	return false;
}
bool chosen[1008];
class JanuszTheBusinessman {
	public:
	int makeGuestsReturn(vector <int> varrivals, vector <int> vdepartures) {
		set<pair<ll,ll> > s;
		ll N = varrivals.size();
		for (ll i = 0; i < N; i++) {
			s.insert(MP(vdepartures[i],varrivals[i]));
			chosen[i] = false;
		}
		while(!s.size()==0) {
			ll arr = (*(s.begin())).second;
			ll dep = (*(s.begin())).first;
			set<pair<ll,ll> > bestit;
			ll bestdep = -1;
			ll bestarr = -1;
			ll bestidx = -1;
			for (ll i = 0; i < N; i++) {
				ll tarr = varrivals[i]; ll tdep = vdepartures[i];
				if (tarr <= dep) {
					if (tdep >= bestdep) {
						bestdep = tdep;
						bestarr = tarr;
						bestidx = i;
					}
				}
			}
			chosen[bestidx] = true;
			for (auto it = s.cbegin(); it != s.cend();) {
				ll tarr = it->second; ll tdep = it->first;
				if (overlap(tarr,tdep,bestarr,bestdep)) {
					s.erase(it++);
				}
				else {
					++it;
				}
			}
		}
		ll ans = 0;
		for (ll i = 0; i < N; i++) {
			if (chosen[i]) ans++;
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
		cout << "Testing JanuszTheBusinessman (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453352621;
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
		JanuszTheBusinessman _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int arrivals[] = {2, 10, 6}	;
				int departures[] = {6, 11, 9};
				_expected = 2;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 1:
			{
				int arrivals[] = {2, 10, 23, 34, 45, 123, 1};
				int departures[] = {25, 12, 40, 50, 48, 187, 365};
				_expected = 1;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 2:
			{
				int arrivals[] = {8, 12, 20, 30, 54, 54, 68, 75};
				int departures[] = {13, 31, 30, 53, 55, 70, 80, 76};
				_expected = 3;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 3:
			{
				int arrivals[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148};
				int departures[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223};
				_expected = 2;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 4:
			{
				int arrivals[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6};
				int departures[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13};
				_expected = 14;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 5:
			{
				int arrivals[] = {1, 2, 3, 4, 5, 6, 7};
				int departures[] = {2, 3, 365, 5, 6, 7, 8};
				_expected = 2;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			/*case 6:
			{
				int arrivals[] = ;
				int departures[] = ;
				_expected = ;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int arrivals[] = ;
				int departures[] = ;
				_expected = ;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
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
