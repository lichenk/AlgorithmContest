#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<pair<ll,ll>,ll> ppll;
#define fst first
#define snd second
bool cmp(const ppll &xx, const ppll &yy) {
	pll x=xx.fst,y=yy.fst;
	ll a=x.fst,b=x.snd,c=y.fst,d=y.snd;
	return a*d>b*c;
}
const ll mn=1e5+4;
ll f[mn];
class TheProgrammingContestDivOne {
	public:
	int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime) {
		vector<ppll> v;
		ll n=pointsPerMinute.size();
		for (ll i=0;i<n;i++) {
			v.PB(MP(MP(pointsPerMinute[i],requiredTime[i]),maxPoints[i]));
		}
		sort(v.begin(),v.end(),cmp);
		fill(f+1,f+T+1,-INF);
		f[0]=0;
		for (auto &w:v) {
			ll ppm=w.fst.fst,rt=w.fst.snd,mp=w.snd;
			//printf("ppm:%lld\n",ppm);
			for (ll t=T;t>=rt;t--) {
				ll s=mp-ppm*t;
				if (s>0) {
					ll cand=s+f[t-rt];
					//if (cand>0) printf("%lld->%lld: %lld+%lld\n",t-rt,t,f[t-rt],s);
					chkmax(f[t],cand);
				}
			}
		}
		ll final=0;
		for (ll t=0;t<=T;t++) chkmax(final,f[t]);
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
		cout << "Testing TheProgrammingContestDivOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484380171;
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
		TheProgrammingContestDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int T = 74;
				int maxPoints[] = {502};
				int pointsPerMinute[] = {2};
				int requiredTime[] = {47};
				_expected = 408;
				_received = _obj.find(T, vector <int>(maxPoints, maxPoints+sizeof(maxPoints)/sizeof(int)), vector <int>(pointsPerMinute, pointsPerMinute+sizeof(pointsPerMinute)/sizeof(int)), vector <int>(requiredTime, requiredTime+sizeof(requiredTime)/sizeof(int))); break;
			}
			case 1:
			{
				int T = 40000;
				int maxPoints[] = {100000, 100000};
				int pointsPerMinute[] = {1, 100000};
				int requiredTime[] = {50000, 30000};
				_expected = 0;
				_received = _obj.find(T, vector <int>(maxPoints, maxPoints+sizeof(maxPoints)/sizeof(int)), vector <int>(pointsPerMinute, pointsPerMinute+sizeof(pointsPerMinute)/sizeof(int)), vector <int>(requiredTime, requiredTime+sizeof(requiredTime)/sizeof(int))); break;
			}
			case 2:
			{
				int T = 75;
				int maxPoints[] = {250, 500, 1000};
				int pointsPerMinute[] = {2, 4, 8};
				int requiredTime[] = {25, 25, 25};
				_expected = 1200;
				_received = _obj.find(T, vector <int>(maxPoints, maxPoints+sizeof(maxPoints)/sizeof(int)), vector <int>(pointsPerMinute, pointsPerMinute+sizeof(pointsPerMinute)/sizeof(int)), vector <int>(requiredTime, requiredTime+sizeof(requiredTime)/sizeof(int))); break;
			}
			case 3:
			{
				int T = 30;
				int maxPoints[] = {100, 100, 100000};
				int pointsPerMinute[] = {1, 1, 100};
				int requiredTime[] = {15, 15, 30};
				_expected = 97000;
				_received = _obj.find(T, vector <int>(maxPoints, maxPoints+sizeof(maxPoints)/sizeof(int)), vector <int>(pointsPerMinute, pointsPerMinute+sizeof(pointsPerMinute)/sizeof(int)), vector <int>(requiredTime, requiredTime+sizeof(requiredTime)/sizeof(int))); break;
			}
			/*case 4:
			{
				int T = ;
				int maxPoints[] = ;
				int pointsPerMinute[] = ;
				int requiredTime[] = ;
				_expected = ;
				_received = _obj.find(T, vector <int>(maxPoints, maxPoints+sizeof(maxPoints)/sizeof(int)), vector <int>(pointsPerMinute, pointsPerMinute+sizeof(pointsPerMinute)/sizeof(int)), vector <int>(requiredTime, requiredTime+sizeof(requiredTime)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int T = ;
				int maxPoints[] = ;
				int pointsPerMinute[] = ;
				int requiredTime[] = ;
				_expected = ;
				_received = _obj.find(T, vector <int>(maxPoints, maxPoints+sizeof(maxPoints)/sizeof(int)), vector <int>(pointsPerMinute, pointsPerMinute+sizeof(pointsPerMinute)/sizeof(int)), vector <int>(requiredTime, requiredTime+sizeof(requiredTime)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int T = ;
				int maxPoints[] = ;
				int pointsPerMinute[] = ;
				int requiredTime[] = ;
				_expected = ;
				_received = _obj.find(T, vector <int>(maxPoints, maxPoints+sizeof(maxPoints)/sizeof(int)), vector <int>(pointsPerMinute, pointsPerMinute+sizeof(pointsPerMinute)/sizeof(int)), vector <int>(requiredTime, requiredTime+sizeof(requiredTime)/sizeof(int))); break;
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
