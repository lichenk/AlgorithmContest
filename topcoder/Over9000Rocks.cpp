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
class Over9000Rocks {
	public:
	int countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
		ll n=lowerBound.size();
		ll zlim=1LL<<n;
		vector<pair<ll,ll> > v;
		for (ll z=0;z<zlim;z++) {
			ll lo=0,hi=0;
			for (ll k=0;k<n;k++) {
				if ((1LL<<k)&z) {
					lo+=lowerBound[k];
					hi+=upperBound[k];
				}
			}
			v.PB(MP(lo,1));
			v.PB(MP(hi+1,-1));
		}
		sort(v.begin(),v.end());
		ll active=0;
		const ll mingo=9001;
		ll prev=mingo;
		ll ans=0;
		for (auto &w:v) {
			ll prevactive=active;
			if (w.second==-1) active--;
			else active++;
			if (active==1&&prevactive==0) {
				prev=w.first;
			}
			else if (active==0){
				ans+=max(0LL,(w.first-prev));
			}
			prev=max(prev,mingo);
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
		cout << "Testing Over9000Rocks (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471535976;
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
		Over9000Rocks _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int lowerBound[] = {9000};
				int upperBound[] = {9001};
				_expected = 1;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			case 1:
			{
				int lowerBound[] = {9000, 1, 10};
				int upperBound[] = {9000, 2, 20};
				_expected = 15;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			case 2:
			{
				int lowerBound[] = {1001, 2001, 3001, 3001};
				int upperBound[] = {1003, 2003, 3003, 3003};
				_expected = 9;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			case 3:
			{
				int lowerBound[] = {9000,90000,1,10};
				int upperBound[] = {9000,90000,3,15};
				_expected = 38;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			case 4:
			{
				int lowerBound[] = {1,1,1,1,1,1};
				int upperBound[] = {3,4,5,6,7,8};
				_expected = 0;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			case 5:
			{
				int lowerBound[] = {90000,1,10};
				int upperBound[] = {90000,3,15};
				_expected = 13;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			case 6:
			{
				int lowerBound[] = {9000,70000,1};
				int upperBound[] = {9000,70000,3};
				_expected = 11;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
			}
			/*case 7:
			{
				int lowerBound[] = ;
				int upperBound[] = ;
				_expected = ;
				_received = _obj.countPossibilities(vector <int>(lowerBound, lowerBound+sizeof(lowerBound)/sizeof(int)), vector <int>(upperBound, upperBound+sizeof(upperBound)/sizeof(int))); break;
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
