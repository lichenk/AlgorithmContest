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
#define fst first
#define snd second
const int mn=14;
bitset<mn> g[mn];
ll gn;
pll h[mn][1<<mn];
pll f(ll x, ll z) {
	ll n=gn;
	pll dpval=h[x][z];
	if (dpval.fst!=-1) return dpval;
	ll anscnt=0;
	ll ansz=z;
	for (ll y=0;y<n;y++) {
		ll ym=1<<y;
		if (0==(ym&z)&&g[x][y]) {
			pll child=f(y,z|ym);
			ll cnt=child.fst,newz=child.snd;
			pll nxt=f(x,newz);
			anscnt+=cnt*nxt.fst;
			if (ansz==z) ansz=nxt.snd;
		}
	}
	if (z==ansz) anscnt=1;
	return h[x][z]=MP(anscnt,ansz);
}
class DFSCount {
	public:
	long long count(vector <string> G) {
		ll n=G.size();
		gn=n;
		for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) g[x][y]=(G[x][y]=='Y');
		for (ll x=0;x<n;x++) for (ll z=0;z<(1<<n);z++) h[x][z].fst=-1;
		ll final=0;
		for (ll x=0;x<n;x++) {
			final+=f(x,1<<x).fst;
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
		cout << "Testing DFSCount (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1493258355;
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
		DFSCount _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string G[] = {"NYY",
				              "YNY",
				              "YYN"};
				_expected = 6LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}
			case 1:
			{
				string G[] = {"NYNN",
				              "YNYN",
				              "NYNY",
				              "NNYN"};
				_expected = 6LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}
			case 2:
			{
				string G[] = {"NYYY",
				              "YNYY",
				              "YYNN",
				              "YYNN"};
				_expected = 16LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}
			case 3:
			{
				string G[] = {"NYYYYYYYYYYYYY",
				              "YNYYYYYYYYYYYY",
				              "YYNYYYYYYYYYYY",
				              "YYYNYYYYYYYYYY",
				              "YYYYNYYYYYYYYY",
				              "YYYYYNYYYYYYYY",
				              "YYYYYYNYYYYYYY",
				              "YYYYYYYNYYYYYY",
				              "YYYYYYYYNYYYYY",
				              "YYYYYYYYYNYYYY",
				              "YYYYYYYYYYNYYY",
				              "YYYYYYYYYYYNYY",
				              "YYYYYYYYYYYYNY",
				              "YYYYYYYYYYYYYN"};
				_expected = 87178291200LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}
			case 4:
			{
				string G[] = {"N"};
				_expected = 1LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}
			/*case 5:
			{
				string G[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string G[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string G[] = ;
				_expected = LL;
				_received = _obj.count(vector <string>(G, G+sizeof(G)/sizeof(string))); break;
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
