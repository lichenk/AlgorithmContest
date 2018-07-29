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
vector<ll> v;
ll n;
class CarrotBoxes {
	public:
	double theProbability(vector <string> vv) {
		n=vv.size();
		for (ll i=0;i<n;i++) {
			ll z=0;
			for (ll j=0;j<n;j++) {
				if (vv[i][j]=='Y') z|=(1LL<<j);
			}
			v.PB(z);
		}
		bool change=true;
		while(change) {
			change=false;
			for (ll i=0;i<n;i++) {
				for (ll j=0;j<n;j++) {
					if(v[i]&(1LL<<j)) {
						ll cand=v[i]|v[j];
						if (cand!=v[i]) change=true;
						v[i]=cand;
					}
				}
			}
		}
		for (ll i=0;i<n;i++) {
			for (ll j=0;j<n;j++) {
				if (i!=j&&(v[i]|v[j])==v[j]) v[i]=0;
			}
		}
		vector<ll> kv;
		for (ll k=0;k<n;k++) {
			bool good=true;
			for (ll i=0;i<n;i++) {
				if (i!=k&&v[i]&(1LL<<k)) good=false;
			}
			if (good) {
				kv.PB(k);
			}
		}
		ll hasone=0;
		for (ll k=0;k<n;k++) {
			ll z=0;
			for (auto &j:kv) {
				if (j!=k) z|=v[j];
			}
			if (__builtin_popcountll(v[k]&~z)==1) hasone=1;
		}
		ll comps=kv.size();
		return 1.0L-((comps-hasone)/(ld)n);
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
		cout << "Testing CarrotBoxes (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484514183;
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
		CarrotBoxes _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string information[] = {"YYYYY",
				                        "NYNNN",
				                        "NNYNN",
				                        "NNNYN",
				                        "NNNNY"};
				_expected = 0.8;
				_received = _obj.theProbability(vector <string>(information, information+sizeof(information)/sizeof(string))); break;
			}
			case 1:
			{
				string information[] = {"YNNNN",
				                        "NYNNN",
				                        "NNYNN",
				                        "NNNYN",
				                        "NNNNY"};
				_expected = 0.2;
				_received = _obj.theProbability(vector <string>(information, information+sizeof(information)/sizeof(string))); break;
			}
			case 2:
			{
				string information[] = {"Y"};
				_expected = 1.0;
				_received = _obj.theProbability(vector <string>(information, information+sizeof(information)/sizeof(string))); break;
			}
			case 3:
			{
				string information[] = {"YNNNN",
				                        "YYNNN",
				                        "YNYNN",
				                        "NNNYY",
				                        "NNNYY"};
				_expected = 0.6;
				_received = _obj.theProbability(vector <string>(information, information+sizeof(information)/sizeof(string))); break;
			}
			case 4:
			{
				string information[] = {"YYYNNNYN",
				                        "NYNNNNYN",
				                        "NNYNNNNN",
				                        "NYNYNNNN",
				                        "YNNNYNNY",
				                        "NNYNNYNN",
				                        "NNNNYNYN",
				                        "NNYNNNNY"};
				_expected = 0.875;
				_received = _obj.theProbability(vector <string>(information, information+sizeof(information)/sizeof(string))); break;
			}
			case 5:
			{
				string information[] = {"YNNNNNNNNYNNNNNNNNNN",
				                        "NYNNNNNNNNNNNNNNNNNN",
				                        "NNYNNNNNNNYNNNNNYNNN",
				                        "NNNYNYNNNNNNNNYNNNNN",
				                        "NNNNYNNNNNNNNNYNNNNY",
				                        "NNNNNYNNNNNNNNNNNNNY",
				                        "NNNNYNYNYNNNNNNNNNNN",
				                        "NNNNNNNYNNNYYNNNNNNN",
				                        "NNNNNNNNYNNNNNNNNNNN",
				                        "YNNNNNNNNYNNNNNYNNNN",
				                        "NNNNNNNNNNYNNNNNNNNN",
				                        "NYNNNNNNNNNYNNNNNNNN",
				                        "NNNNNNNYNNNNYNNNNNNN",
				                        "NNNNNNNNNNNNNYNNNYNN",
				                        "NNNNNNNNNNNYNNYNNNYN",
				                        "NYNNNNNNNNNNNNNYNNNN",
				                        "NNYNNNNNNNNNNNNNYNNN",
				                        "NNNNNNNNNNNNNYNYNYNN",
				                        "NNNNNNNNYNYNNNNNNNYY",
				                        "NNNYNNNNNNNNNNNNNNNY"};
				_expected = 0.75;
				_received = _obj.theProbability(vector <string>(information, information+sizeof(information)/sizeof(string))); break;
			}
			case 6:
			{
				string information[] = {"YNNYYYNNN", "NYNNYYYYN", "NNYNNNYYY", "NNNYNNNNN", "NNNNYNNNN", "NNNNNYNNN", "NNNNNNYNN", "NNNNNNNYN", "NNNNNNNNY"};
				_expected = 0.7777777777777778;
				_received = _obj.theProbability(vector <string>(information, information+sizeof(information)/sizeof(string))); break;
			}
			case 7:
			{
				string information[] = {"YNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN", "NYNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNYNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNYNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN", "NNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY", "NNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNYNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNYNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNYNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNYNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN", "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN", "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNYNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNYNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY"};
				_expected = 0.54;
				_received = _obj.theProbability(vector <string>(information, information+sizeof(information)/sizeof(string))); break;
			}
			/*case 8:
			{
				string information[] = ;
				_expected = ;
				_received = _obj.theProbability(vector <string>(information, information+sizeof(information)/sizeof(string))); break;
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
