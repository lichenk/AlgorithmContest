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
string s;
string rgb="RGB";
const ll MAXN=100;
ll f[3][MAXN];
ll n;
bool ok(ll x, ll k, ll c) {
	char ch=rgb[c];
	if (!(x<n&&x-k+1>=0)) {return false;}
	for (ll i=x;i>x-k;i--) {
		if (s[i]!=ch&&s[i]!='*') {return false;}
	}
	return true;
}
class Stamp {
	public:
	int getMinimumCost(string desiredColor, int stampCost, int pushCost) {
		s=desiredColor;
		n=desiredColor.length();
		ll final=1e18;
		for (ll k=1;k<=n;k++) {
			for (ll c=0;c<3;c++) {
				for (ll x=0;x<=n;x++) f[c][x]=INF;
				f[c][0]=k*stampCost;
			}
			for (ll x=0;x<n;x++) {
				for (ll c=0;c<3;c++) {
					if (f[c][x]>=INF) continue;
					for (ll d=0;d<3;d++) {
						for (ll y=x;y<min(n,x+k);y++) {
							if (c!=d&&y!=x+k-1) continue;
							if (ok(y,k,d)) {
								/*if (k==3) {
									prinf("OK: ")
								}*/
								chkmin(f[d][y+1],f[c][x]+pushCost);
							}
						}
					}
				}
			}
			for (ll c=0;c<3;c++) chkmin(final,f[c][n]);
		}
		return final;
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
		cout << "Testing Stamp (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1466655808;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Stamp _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string desiredColor = "RRGGBB";
				int stampCost = 1;
				int pushCost = 1;
				_expected = 5;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 1:
			{
				string desiredColor = "R**GB*";
				int stampCost = 1;
				int pushCost = 1;
				_expected = 5;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 2:
			{
				string desiredColor = "BRRB";
				int stampCost = 2;
				int pushCost = 7;
				_expected = 30;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 3:
			{
				string desiredColor = "R*RR*GG";
				int stampCost = 10;
				int pushCost = 58;
				_expected = 204;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 4:
			{
				string desiredColor = "*B**B**B*BB*G*BBB**B**B*";
				int stampCost = 5;
				int pushCost = 2;
				_expected = 33;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 5:
			{
				string desiredColor = "*R*RG*G*GR*RGG*G*GGR***RR*GG";
				int stampCost = 7;
				int pushCost = 1;
				_expected = 30;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			case 6:
			{
				string desiredColor = "RR*GG";
				int stampCost = 1;
				int pushCost = 100000;
				_expected = 300002;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}
			/*case 7:
			{
				string desiredColor = ;
				int stampCost = ;
				int pushCost = ;
				_expected = ;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
			}*/
			/*case 8:
			{
				string desiredColor = ;
				int stampCost = ;
				int pushCost = ;
				_expected = ;
				_received = _obj.getMinimumCost(desiredColor, stampCost, pushCost); break;
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
