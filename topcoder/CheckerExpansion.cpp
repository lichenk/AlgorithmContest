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
ll powt[60];
char f(ll x, ll y, ll k) {
	//printf("%lld %lld %lld\n",x,y,k);
	if (k==-1) {
		if (x==0&&y==0) return 'A';
		if (x==1&&y==1) return 'B';
		if (x==2&&y==0) return 'B';
		return '.';
	}
	ll m=powt[k];
	if (x>=2*m&&y>=2*m) return f(x-2*m,y-2*m,k-1);
	else if (x>=4*m) return f(x-4*m,y,k-1);
	else return f(x,y,k-1);
}
class CheckerExpansion {
	public:
	vector <string> resultAfter(long long t, long long x0, long long y0, int w, int h) {
		powt[0]=1;
		for (ll t=1;t<60;t++) {
			powt[t]=powt[t-1]*2;
		}
		vector<string> ans;
		ans.resize(h); for (ll i=0;i<h;i++) ans[i].resize(w);
		for (ll i=0;i<h;i++) {
			for (ll j=0;j<w;j++) {
				ll x=x0+j,y=y0+h-i-1;
				if (x+y>2*(t-1)) ans[i][j]='.';
				else ans[i][j]=f(x,y,59);
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
		cout << "Testing CheckerExpansion (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1469907777;
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
		CheckerExpansion _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long t = 1LL;
				long long x0 = 0LL;
				long long y0 = 0LL;
				int w = 4;
				int h = 4;
				string __expected[] = {"....", "....", "....", "A..." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}
			case 1:
			{
				long long t = 5LL;
				long long x0 = 4LL;
				long long y0 = 1LL;
				int w = 3;
				int h = 4;
				string __expected[] = {"A..", "...", "B..", ".B." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}
			case 2:
			{
				long long t = 1024LL;
				long long x0 = 1525LL;
				long long y0 = 512LL;
				int w = 20;
				int h = 2;
				string __expected[] = {"B...B...B...........", ".B.A.B.A.B.........." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}
			case 3:
			{
				long long t = 53LL;
				long long x0 = 85LL;
				long long y0 = 6LL;
				int w = 5;
				int h = 14;
				string __expected[] = {".....", ".....", "B....", ".B.A.", ".....", ".....", ".....", ".....", ".....", ".....", "B....", ".B...", "..B..", ".A.B." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}
			case 4:
			{
				long long t = 2LL;
				long long x0 = 0LL;
				long long y0 = 0LL;
				int w = 2;
				int h = 2;
				string __expected[] = {".B","A."};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}
			/*case 5:
			{
				long long t = LL;
				long long x0 = LL;
				long long y0 = LL;
				int w = ;
				int h = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
			}*/
			/*case 6:
			{
				long long t = LL;
				long long x0 = LL;
				long long y0 = LL;
				int w = ;
				int h = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.resultAfter(t, x0, y0, w, h); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
