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
vector<int> a;
vector<int> b;
const ll mn=51;
ll f[mn][mn][mn];
class WhiteSpaceEditing {
	public:
	int getMinimum(vector <int> v) {
		set<ll> s;
		s.insert(0);
		for (auto &w:v) s.insert(w);
		map<ll,ll> h;
		ll idx=0;
		for (auto &w:s) {
			b.PB(w);h[w]=idx;idx++;
		}
		ll n=v.size();
		for (ll i=0;i<n;i++) {
			a.PB(h[v[i]]);
		}
		for (ll l=0;l<mn;l++) for (ll r=0;r<mn;r++) for (ll s=0;s<mn;s++) f[l][r][s]=INF;
		ll smax=b.size();
		for (ll l=0;l<n;l++) f[l][l][a[l]]=0;
		for (ll len=1;len<=n;len++) {
			for (ll l=0;l<n;l++) {
				ll r=l+len-1;
				if (r>=n) continue;
				for (ll s=0;s<smax;s++) {
					ll ans=INF;
					for (ll k=l;k<r;k++) {
						chkmin(ans,f[l][k][s]+f[k+1][r][s]+1);
					}
					if (ans<INF) {
						f[l][r][s]=ans;
						//printf("l:%lld r:%lld s:%lld\n",l,r,s);
					}
				}
				for (ll s=1;s<smax;s++) {
					chkmin(f[l][r][s],f[l][r][s-1]+b[s]-b[s-1]);
				}
				for (ll s=smax-2;s>=0;s--) {
					chkmin(f[l][r][s],f[l][r][s+1]+b[s+1]-b[s]);
				}
			}
		}
		ll ans=f[0][n-1][0];
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
		cout << "Testing WhiteSpaceEditing (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484456949;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		WhiteSpaceEditing _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int lines[] = { 3, 2, 3 };
				_expected = 6;
				_received = _obj.getMinimum(vector <int>(lines, lines+sizeof(lines)/sizeof(int))); break;
			}
			case 1:
			{
				int lines[] = { 0 };
				_expected = 0;
				_received = _obj.getMinimum(vector <int>(lines, lines+sizeof(lines)/sizeof(int))); break;
			}
			case 2:
			{
				int lines[] = { 1, 2, 4 };
				_expected = 6;
				_received = _obj.getMinimum(vector <int>(lines, lines+sizeof(lines)/sizeof(int))); break;
			}
			case 3:
			{
				int lines[] = { 250, 105, 155, 205, 350 };
				_expected = 499;
				_received = _obj.getMinimum(vector <int>(lines, lines+sizeof(lines)/sizeof(int))); break;
			}
			case 4:
			{
				int lines[] = {0,0};
				_expected = 1;
				_received = _obj.getMinimum(vector <int>(lines, lines+sizeof(lines)/sizeof(int))); break;
			}
			case 5:
			{
				int lines[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				_expected = 49;
				_received = _obj.getMinimum(vector <int>(lines, lines+sizeof(lines)/sizeof(int))); break;
			}
			/*case 6:
			{
				int lines[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <int>(lines, lines+sizeof(lines)/sizeof(int))); break;
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
