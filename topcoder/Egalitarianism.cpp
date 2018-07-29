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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll dist[100];
class Egalitarianism {
	public:
	int maxDifference(vector <string> isFriend, int d) {
		ll n=isFriend.size();
		ll ans=0;
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<n;y++) {
				for (ll v=0;v<n;v++) dist[v]=INF;
				dist[x]=0;
				queue<ll> q;
				q.push(x);
				while(!q.empty()) {
					ll a=q.front(); q.pop();
					for (ll b=0;b<n;b++) {
						if (isFriend[a][b]=='N') continue;
						if (dist[b]>dist[a]+1) {
							dist[b]=dist[a]+1;
							q.push(b);
						}
					}
				}
				if(dist[y]==INF) return -1;
				ans=max(ans,dist[y]*d);
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
		cout << "Testing Egalitarianism (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458360096;
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
		Egalitarianism _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string isFriend[] = {"NYN",
				                     "YNY",
				                     "NYN"};
				int d = 10;
				_expected = 20;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 1:
			{
				string isFriend[] = {"NN",
				                     "NN"};
				int d = 1;
				_expected = -1;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 2:
			{
				string isFriend[] = {"NNYNNN",
				                     "NNYNNN",
				                     "YYNYNN",
				                     "NNYNYY",
				                     "NNNYNN",
				                     "NNNYNN"};
				int d = 1000;
				_expected = 3000;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 3:
			{
				string isFriend[] = {"NNYN",
				                     "NNNY",
				                     "YNNN",
				                     "NYNN"};
				int d = 584;
				_expected = -1;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 4:
			{
				string isFriend[] = {"NYNYYYN",
				                     "YNNYYYN",
				                     "NNNNYNN",
				                     "YYNNYYN",
				                     "YYYYNNN",
				                     "YYNYNNY",
				                     "NNNNNYN"};
				int d = 5;
				_expected = 20;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 5:
			{
				string isFriend[] = {"NYYNNNNYYYYNNNN",
				                     "YNNNYNNNNNNYYNN",
				                     "YNNYNYNNNNYNNNN",
				                     "NNYNNYNNNNNNNNN",
				                     "NYNNNNYNNYNNNNN",
				                     "NNYYNNYNNYNNNYN",
				                     "NNNNYYNNYNNNNNN",
				                     "YNNNNNNNNNYNNNN",
				                     "YNNNNNYNNNNNYNN",
				                     "YNNNYYNNNNNNNNY",
				                     "YNYNNNNYNNNNNNN",
				                     "NYNNNNNNNNNNNNY",
				                     "NYNNNNNNYNNNNYN",
				                     "NNNNNYNNNNNNYNN",
				                     "NNNNNNNNNYNYNNN"};
				int d = 747;
				_expected = 2988;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			case 6:
			{
				string isFriend[] = {"NY",
				                     "YN"};
				int d = 0;
				_expected = 0;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}
			/*case 7:
			{
				string isFriend[] = ;
				int d = ;
				_expected = ;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}*/
			/*case 8:
			{
				string isFriend[] = ;
				int d = ;
				_expected = ;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
			}*/
			/*case 9:
			{
				string isFriend[] = ;
				int d = ;
				_expected = ;
				_received = _obj.maxDifference(vector <string>(isFriend, isFriend+sizeof(isFriend)/sizeof(string)), d); break;
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
