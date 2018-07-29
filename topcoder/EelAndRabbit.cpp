#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
bool good[1000];
class EelAndRabbit {
	public:
	int getmax(vector <int> l, vector <int> t) {
		set<ll> s;
		ll m = l.size();
		for (ll i = 0; i < m; i++) {
			s.insert(t[i]);
			s.insert(t[i]+l[i]);
		}
		vector<ll> v;
		for (auto &p: s) {
			v.PB(p);
		}
		ll k = v.size();
		ll best = 0;
		for (ll aa=0;aa<k;aa++) {
			for (ll bb=aa+1;bb<k;bb++) {
				ll a = v[aa];
				ll b = v[bb];
				for (ll i=0;i<m;i++) {
					good[i] = false;
				}
				for (ll i=0;i<m;i++) {
					ll head = a-t[i];
					ll tail = a-t[i]-l[i];
					if (tail <= 0 && 0 <= head) {
						good[i] = true;
					}
				}
				for (ll i=0;i<m;i++) {
					ll head = b-t[i];
					ll tail = b-t[i]-l[i];
					if (tail <= 0 && 0 <= head) {
						good[i] = true;
					}
				}
				ll cand=0;
				for (ll i=0;i<m;i++) {
					if (good[i]) cand++;
				}
				best = max(best,cand);
			}
		}
		return best;
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
		cout << "Testing EelAndRabbit (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454728258;
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
		EelAndRabbit _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int l[] = {2, 4, 3, 2, 2, 1, 10};
				int t[] = {2, 6, 3, 7, 0, 2, 0};
				_expected = 6;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 1:
			{
				int l[] = {1, 1, 1};
				int t[] = {2, 0, 4};
				_expected = 2;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 2:
			{
				int l[] = {1};
				int t[] = {1};
				_expected = 1;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			case 3:
			{
				int l[] = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5};
				int t[] = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13};
				_expected = 7;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}
			/*case 4:
			{
				int l[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int l[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int l[] = ;
				int t[] = ;
				_expected = ;
				_received = _obj.getmax(vector <int>(l, l+sizeof(l)/sizeof(int)), vector <int>(t, t+sizeof(t)/sizeof(int))); break;
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
