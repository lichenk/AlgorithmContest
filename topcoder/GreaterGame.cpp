#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
bool seen[1000];
class GreaterGame {
	public:
	double calc(vector <int> hand, vector <int> sothe) {
		ll n=hand.size();
		for (ll i=1;i<=2*n;i++) {
			seen[i] = false;
		}
		for (auto &w:hand) seen[w] = true;
		for (auto &w:sothe) {if(w!=-1) seen[w] = true;}
		vector<ll> left;
		for (ll i=1;i<=2*n;i++) {
			if (!seen[i]) left.PB(i);
		}
		set<ll> s;
		for (auto &w: hand) s.insert(w);
		sort(sothe.begin(),sothe.end(), greater<int>());
		ll idx=0;
		ld ans = 0;
		for (ll i=0;i<n;i++) {
			ll x=sothe[i];
			if (x==-1) break;
			auto it = s.lower_bound(x);
			if (it == s.end()) {
				s.erase(s.begin());
			}
			else {
				s.erase(it);
				ans += 1;
			}
			idx++;
		}
		sort(left.begin(),left.end());
		for (auto &w: s) {
			ll lsz = left.size();
			ll low = 0;
			for (ll i=0;i<lsz;i++) {
				if (left[i] < w) low++;
			}
			ld cand = ((ld)low)/((ld)lsz);
			//printf("%d %f\n",w,(double)cand);
			ans += cand;
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
		cout << "Testing GreaterGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454793905;
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
		GreaterGame _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int hand[] = {4,2};
				int sothe[] = {-1,-1};
				_expected = 1.5;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 1:
			{
				int hand[] = {4,2};
				int sothe[] = {1,3};
				_expected = 2.0;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 2:
			{
				int hand[] = {2};
				int sothe[] = {-1};
				_expected = 1.0;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 3:
			{
				int hand[] = {1,3,5,7};
				int sothe[] = {8,-1,4,-1};
				_expected = 2.5;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			case 4:
			{
				int hand[] = {6,12,17,14,20,8,16,7,2,15};
				int sothe[] = {-1,-1,4,-1,11,3,13,-1,-1,18};
				_expected = 8.0;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}
			/*case 5:
			{
				int hand[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int hand[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int hand[] = ;
				int sothe[] = ;
				_expected = ;
				_received = _obj.calc(vector <int>(hand, hand+sizeof(hand)/sizeof(int)), vector <int>(sothe, sothe+sizeof(sothe)/sizeof(int))); break;
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
