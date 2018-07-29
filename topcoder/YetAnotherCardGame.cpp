#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<30ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll f[2][52][52][101];
class YetAnotherCardGame {
	public:
	int maxCards(vector <int> _a, vector <int> _b) {
		ll as=_a.size(); ll bs=_b.size(); ll ts=as+bs;
		set<ll> a,b;
		for (auto &w:_a) a.insert(w);
		for (auto &w:_b) b.insert(w);
		for (ll mv=0;mv<2;mv++) {
			for (ll x=0;x<=as;x++) {
				for (ll y=0;y<=bs;y++) {
					for (ll z=0;z<101;z++) {
						f[mv][x][y][z]=UNDEF;
					}
				}
			}
		}
		f[0][0][0][0]=0;
		ll ans=0;
		for (ll mv=0;mv<=ts;mv++) {
			ll c=(mv+1)%2;
			ll p=(mv)%2;
			for (ll x=0;x<=as;x++) {
				for (ll y=0;y<=bs;y++) {
					for (ll z=0;z<101;z++) {
						ll v=f[p][x][y][z];
						if (v==UNDEF) continue;
						//printf("%d %d %d %d:%d\n",mv,x,y,z,v);
						ans=max(ans,v);
						bool isa = !(mv%2);
						if (isa) {
							auto ait = a.upper_bound(z);
							if (ait!=a.end()) {
								chkmax(f[c][x+1][y][*ait],v+1);
							}
							chkmax(f[c][x+1][y][z],v);
						}
						else {
							auto bit = b.upper_bound(z);
							if (bit!=b.end()) {
								chkmax(f[c][x][y+1][*bit],v+1);
							}
							chkmax(f[c][x][y+1][z],v);
						}
					}
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
		cout << "Testing YetAnotherCardGame (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456631372;
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
		YetAnotherCardGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int petr[] = {2, 5};
				int snuke[] = {3, 1};
				_expected = 3;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}
			case 1:
			{
				int petr[] = {1, 1, 1, 1, 1};
				int snuke[] = {1, 1, 1, 1, 1};
				_expected = 1;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}
			case 2:
			{
				int petr[] = {1, 4, 6, 7, 3};
				int snuke[] = {1, 7, 1, 5, 7};
				_expected = 6;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}
			case 3:
			{
				int petr[] = {19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29};
				int snuke[] = {28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83};
				_expected = 28;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}
			/*case 4:
			{
				int petr[] = ;
				int snuke[] = ;
				_expected = ;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int petr[] = ;
				int snuke[] = ;
				_expected = ;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int petr[] = ;
				int snuke[] = ;
				_expected = ;
				_received = _obj.maxCards(vector <int>(petr, petr+sizeof(petr)/sizeof(int)), vector <int>(snuke, snuke+sizeof(snuke)/sizeof(int))); break;
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
