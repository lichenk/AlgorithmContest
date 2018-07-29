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
ll dist[100];
class TravelOnMars {
	public:
	int minTimes(vector <int> range, int startCity, int endCity) {
		ll n=range.size();
		for (ll x=0;x<n;x++) {
			dist[x]=INF;
		}
		queue<ll> q;
		q.push(startCity);
		dist[startCity]=0;
		while(!q.empty()) {
			ll v=q.front();
			//printf("Visit: %lld\n",v);
			q.pop();
			if (v==endCity) {
				return dist[v];
			}
			ll s=v;
			for (ll i=0;i<range[v];i++) {
				s = (s+n-1)%n;
			}
			for (ll i=0;i<=2*range[v];i++) {
				//printf("Try: %lld. %lld\n",s,dist[s]);
				if (dist[s]==INF) {
					//printf("Push: %lld. %lld\n",s,dist[s]);
					dist[s]=dist[v]+1;
					q.push(s);
				}
				s=(s+1)%n;
			}
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
		cout << "Testing TravelOnMars (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457328748;
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
		TravelOnMars _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int range[] = {2,1,1,1,1,1};
				int startCity = 1;
				int endCity = 4;
				_expected = 2;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			case 1:
			{
				int range[] = {2,1,1,1,1,1};
				int startCity = 4;
				int endCity = 1;
				_expected = 3;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			case 2:
			{
				int range[] = {2,1,1,2,1,2,1,1};
				int startCity = 2;
				int endCity = 6;
				_expected = 3;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			case 3:
			{
				int range[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3};
				int startCity = 6;
				int endCity = 13;
				_expected = 4;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			case 4:
			{
				int range[] = {1,1,1};
				int startCity = 1;
				int endCity = 2;
				_expected = 1;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}
			/*case 5:
			{
				int range[] = ;
				int startCity = ;
				int endCity = ;
				_expected = ;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
			}*/
			/*case 6:
			{
				int range[] = ;
				int startCity = ;
				int endCity = ;
				_expected = ;
				_received = _obj.minTimes(vector <int>(range, range+sizeof(range)/sizeof(int)), startCity, endCity); break;
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
