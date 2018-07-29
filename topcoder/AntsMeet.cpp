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
class AntsMeet {
	public:
	int countAnts(vector <int> x, vector <int> y, string direction) {
		ll n=x.size();
		for (ll i=0;i<n;i++) x[i]*=2,y[i]*=2;
		ll active=(1LL<<n)-1;
		for (ll qq=0;qq<4008;qq++) {
			for (ll k=0;k<n;k++) {
				if (active&(1LL<<k)) {
					if (direction[k]=='N') y[k]++;
					else if (direction[k]=='S') y[k]--;
					else if (direction[k]=='E') x[k]++;
					else if (direction[k]=='W') x[k]--;
				}
			}
			ll newactive=active;
			for (ll k=0;k<n;k++) {
				if (!(active&(1LL<<k))) continue;
				for (ll j=k+1;j<n;j++) {
					if (!(active&(1LL<<j))) continue;
					if (x[k]==x[j]&&y[k]==y[j]) {
						newactive=newactive&(~((1LL<<k)|(1LL<<j)));
					}
				}
			}
			active=newactive;
		}
	ll ans=__builtin_popcountll(active);
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
		cout << "Testing AntsMeet (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471321593;
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
		AntsMeet _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0,10,20,30};
				int y[] = {0,10,20,30};
				string direction = "NWNE";
				_expected = 2;
				_received = _obj.countAnts(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), direction); break;
			}
			case 1:
			{
				int x[] = {-10,0,0,10};
				int y[] = {0,-10,10,0};
				string direction = "NEWS";
				_expected = 0;
				_received = _obj.countAnts(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), direction); break;
			}
			case 2:
			{
				int x[] = {-1,-1,-1,0,0,0,1,1,1};
				int y[] = {-1,0,1,-1,0,1,-1,0,1};
				string direction = "ESEWNNEWW";
				_expected = 4;
				_received = _obj.countAnts(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), direction); break;
			}
			case 3:
			{
				int x[] = {4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3};
				int y[] = {2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3};
				string direction = "SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" ;
				_expected = 25;
				_received = _obj.countAnts(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), direction); break;
			}
			case 4:
			{
				int x[] = {478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423
				          ,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493};
				int y[] = {-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216
				          ,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337};
				string direction = "WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE";
				_expected = 44;
				_received = _obj.countAnts(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), direction); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				string direction = ;
				_expected = ;
				_received = _obj.countAnts(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), direction); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				string direction = ;
				_expected = ;
				_received = _obj.countAnts(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), direction); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				string direction = ;
				_expected = ;
				_received = _obj.countAnts(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), direction); break;
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
