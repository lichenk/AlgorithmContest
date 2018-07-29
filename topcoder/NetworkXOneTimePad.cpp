#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
bool issubset(map<ll,ll> sub, map<ll,ll> dom) {
	for (auto &w:sub) {
		auto it=dom.find(w.fst);
		if (it==dom.end()) return false;
		if (it->second<w.snd) return false;
	}
	return true;
}
class NetworkXOneTimePad {
	public:
	int crack(vector <string> plaintexts, vector <string> ciphertexts) {
		vector<ll> p,c;
		for (auto &w:plaintexts) {
			ll x=0;
			for (auto &a:w) {
				x<<=1;
				if (a=='1') x|=1;
			}
			p.PB(x);
		}
		for (auto &w:ciphertexts) {
			ll x=0;
			for (auto &a:w) {
				x<<=1;
				if (a=='1') x|=1;
			}
			c.PB(x);
		}
		set<ll> final;
		ll n=p.size();
		map<ll,ll> good;
		for (auto &w:c) good[w]++;
		for (ll k=0;k<n;k++)
		for (ll x=0;x<n;x++) {
			ll key=p[k]^c[x];
			//printf("key:%lld\n",key);
			map<ll,ll> s;
			for (ll y=0;y<n;y++) {
				s[p[y]^key]++;
			}
			if (issubset(good,s)) final.insert(key);
		}
		return (ll)final.size();
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
		cout << "Testing NetworkXOneTimePad (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483814303;
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
		NetworkXOneTimePad _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string plaintexts[] = {"110", "001"};
				string ciphertexts[] = {"101", "010"};
				_expected = 2;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
			}
			case 1:
			{
				string plaintexts[] = {"00", "01", "10", "11"};
				string ciphertexts[] = {"00", "01", "10", "11"};
				_expected = 4;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
			}
			case 2:
			{
				string plaintexts[] = {"01", "10"};
				string ciphertexts[] = {"00"};
				_expected = 2;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
			}
			case 3:
			{
				string plaintexts[] = {"000", "111", "010", "101", "110", "001"};
				string ciphertexts[] = {"011", "100"};
				_expected = 6;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
			}
			/*case 4:
			{
				string plaintexts[] = ;
				string ciphertexts[] = ;
				_expected = ;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string plaintexts[] = ;
				string ciphertexts[] = ;
				_expected = ;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string plaintexts[] = ;
				string ciphertexts[] = ;
				_expected = ;
				_received = _obj.crack(vector <string>(plaintexts, plaintexts+sizeof(plaintexts)/sizeof(string)), vector <string>(ciphertexts, ciphertexts+sizeof(ciphertexts)/sizeof(string))); break;
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
