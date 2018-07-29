#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll MAXN=100;
ll r[MAXN];
ll tmp[MAXN];
class SurveillanceSystem {
	public:
	string getContainerInfo(string containers, vector <int> reports, int L) {
		ll n=containers.length();
		string ans;
		for (ll i=0;i<n;i++) {
			ans += "-";
		}
		for (ll k=0;k<MAXN;k++) {
			r[k]=0;
		}
		for (ll k=0;k<reports.size();k++) {
			r[reports[k]]++;
		}
		for (ll k=0;k<MAXN;k++) {
			if (r[k]==0) continue;
			for (ll x=0;x<n;x++) {
				tmp[x]=0;
			}
			ll cand=0;
			vector<ll> v;
			for (ll x=0;x<=n-L;x++) {
				ll cnt=0;
				for (ll y=x;y<x+L;y++) {
					if (containers[y]=='X') cnt++;
				}
				if (cnt == k) {
					for (ll y=x;y<x+L;y++) {
						tmp[y]++;
					}
					cand++;
				}
			}
			for (ll x=0;x<n;x++) {
				if (tmp[x] > 0 && ans[x]=='-') {
					ans[x] = '?';
				}
				if (r[k] > cand - tmp[x]) {
					ans[x] = '+';
				}
			}
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
		cout << "Testing SurveillanceSystem (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456192796;
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
		SurveillanceSystem _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string containers = "-X--XX";
				int reports[] = {1, 2};
				int L = 3;
				_expected = "??++++";
				_received = _obj.getContainerInfo(containers, vector <int>(reports, reports+sizeof(reports)/sizeof(int)), L); break;
			}
			case 1:
			{
				string containers = "-XXXXX-";
				int reports[] = {2};
				int L = 3;
				_expected = "???-???";
				_received = _obj.getContainerInfo(containers, vector <int>(reports, reports+sizeof(reports)/sizeof(int)), L); break;
			}
			case 2:
			{
				string containers = "------X-XX-";
				int reports[] = {3, 0, 2, 0};
				int L = 5;
				_expected = "++++++++++?";
				_received = _obj.getContainerInfo(containers, vector <int>(reports, reports+sizeof(reports)/sizeof(int)), L); break;
			}
			case 3:
			{
				string containers = "-XXXXX---X--";
				int reports[] = {2, 1, 0, 1};
				int L = 3;
				_expected = "???-??++++??";
				_received = _obj.getContainerInfo(containers, vector <int>(reports, reports+sizeof(reports)/sizeof(int)), L); break;
			}
			case 4:
			{
				string containers = "-XX--X-XX-X-X--X---XX-X---XXXX-----X";
				int reports[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
				int L = 7;
				_expected = "???++++?++++++++++++++++++++??????--";
				_received = _obj.getContainerInfo(containers, vector <int>(reports, reports+sizeof(reports)/sizeof(int)), L); break;
			}
			/*case 5:
			{
				string containers = ;
				int reports[] = ;
				int L = ;
				_expected = ;
				_received = _obj.getContainerInfo(containers, vector <int>(reports, reports+sizeof(reports)/sizeof(int)), L); break;
			}*/
			/*case 6:
			{
				string containers = ;
				int reports[] = ;
				int L = ;
				_expected = ;
				_received = _obj.getContainerInfo(containers, vector <int>(reports, reports+sizeof(reports)/sizeof(int)), L); break;
			}*/
			/*case 7:
			{
				string containers = ;
				int reports[] = ;
				int L = ;
				_expected = ;
				_received = _obj.getContainerInfo(containers, vector <int>(reports, reports+sizeof(reports)/sizeof(int)), L); break;
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
