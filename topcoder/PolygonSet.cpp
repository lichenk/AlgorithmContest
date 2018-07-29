#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<30ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=52;
const ll mx=102;
const ll my=mn*mx;
ll f[mn][mn][my];
class PolygonSet {
	public:
	long long count(vector <int> S) {
		sort(S.begin(),S.end());
		ll n=S.size();
		for (ll x=0;x<mn;x++) for (ll k=0;k<mn;k++) for (ll y=0;y<my;y++) f[x][k][y]=0;
		f[0][0][0]=1;
		ll ans=0;
		S.PB(INF);
		for (ll x=0;x<=n;x++) {
			for (ll k=0;k<=n;k++) {
				for (ll y=0;y<my;y++) {
					ll v=f[x][k][y];
					if (v<=0) continue;
					if (x<n) {
						f[x+1][k+1][y+S[x]]+=v;
						{
							if (k+1>=2) {
								ll imin=0,imax=n+1;
								while(imin<imax) {
									ll imid=(imin+imax)/2;
									if (S[imid]<y+S[x]) imin=imid+1;
									else imax=imid;
								}
								ll get=max(0LL,imin-(x+1));
								//if(get)printf("x:%d k:%d y:%d v:%d imin:%d left:%d\n",x,k,y,v,imin,get);
								ans+=get*v;
							}
						}
						f[x+1][k][y]+=v;
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
		cout << "Testing PolygonSet (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470974986;
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
		PolygonSet _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int S[] = {1,2,3,4};
				_expected = 2LL;
				_received = _obj.count(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 1:
			{
				int S[] = {90,91,92,93,94,95,96,97,98,99};
				_expected = 968LL;
				_received = _obj.count(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 2:
			{
				int S[] = {2,5,8,7,4,3,9,1,6};
				_expected = 402LL;
				_received = _obj.count(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 3:
			{
				int S[] = {11,12,13,14,15,91,92,93,94,95};
				_expected = 838LL;
				_received = _obj.count(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 4:
			{
				int S[] = {1,2,3,4,5,6,7,8,9,100};
				_expected = 402LL;
				_received = _obj.count(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			case 5:
			{
				int S[] = {90,91,92,93};
				_expected = 5LL;
				_received = _obj.count(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}
			/*case 6:
			{
				int S[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int S[] = ;
				_expected = LL;
				_received = _obj.count(vector <int>(S, S+sizeof(S)/sizeof(int))); break;
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
