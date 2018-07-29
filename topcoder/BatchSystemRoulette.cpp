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
#define fst first
#define snd second
typedef vector<ll> vll;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class BatchSystemRoulette {
	public:
	vector <double> expectedFinishTimes(vector <int> d, vector <string> u) {
		map<string,vll> name2job;
		ll n=d.size();
		for (ll i=0;i<n;i++) name2job[u[i]].PB(i);
		map<ll,vector<string> > time2name;
		for (auto &w:name2job) {
			ll sum=0;
			for (auto &job:w.snd) {
				sum+=d[job];
			}
			time2name[sum].PB(w.fst);
		}
		vector<double> vans;
		vans.resize(n);
		ll base=0;
		for (auto &t2n:time2name) {
			vll alljobs;
			ld sumall=t2n.fst*t2n.snd.size();
			for (auto &name:t2n.snd) {
				for (auto &job: name2job[name]) {
					ld jobtime=d[job];
					ld ans=base+(sumall-jobtime)/2 + jobtime;
					vans[job]=ans;
				}
			}
			base+=t2n.fst*t2n.snd.size();
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
		cout << "Testing BatchSystemRoulette (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491239420;
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
		BatchSystemRoulette _obj;
		vector <double> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int duration[] = {3, 2, 4, 1};
				string user[] = {"Gil Grissom", "Sarah Sidle", "Warrick Brown", "Catherine Willows"};
				double __expected[] = {6.0, 3.0, 10.0, 1.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedFinishTimes(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <string>(user, user+sizeof(user)/sizeof(string))); break;
			}
			case 1:
			{
				int duration[] = {3, 2, 4, 1};
				string user[] = {"mac taylor", "Mac Taylor", "Mac Taylor", "Peyton Driscoll"};
				double __expected[] = {4.0, 8.0, 9.0, 1.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedFinishTimes(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <string>(user, user+sizeof(user)/sizeof(string))); break;
			}
			case 2:
			{
				int duration[] = {13, 14, 15, 56, 56};
				string user[] = {"Tim Speedle", "Tim Speedle", "Tim Speedle", "Horatio Caine", "YEEEAAAAAAAAAAH"};
				double __expected[] = {27.5, 28.0, 28.5, 126.0, 126.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedFinishTimes(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <string>(user, user+sizeof(user)/sizeof(string))); break;
			}
			case 3:
			{
				int duration[] = {1,1};
				string user[] = {"a","a"};
				double __expected[] = {1.5,1.5};
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedFinishTimes(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <string>(user, user+sizeof(user)/sizeof(string))); break;
			}
			/*case 4:
			{
				int duration[] = ;
				string user[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedFinishTimes(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <string>(user, user+sizeof(user)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int duration[] = ;
				string user[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.expectedFinishTimes(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <string>(user, user+sizeof(user)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		bool _passed = _expected.size() == _received.size();
		for (unsigned i = 0; i < _received.size(); i++)
			_passed = _passed && (abs(_expected[i]-_received[i]) < 1e-9 || (_received[i] > min(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9)) && _received[i] < max(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9))));
		if (_passed)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
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
