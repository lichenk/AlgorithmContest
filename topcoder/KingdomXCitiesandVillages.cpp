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
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mn=51;
ll cx[mn],cy[mn],vx[mn],vy[mn];
map<ll,vector<ll> > dh[mn];
ld f[mn][mn];
class KingdomXCitiesandVillages {
	public:
	double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY) {
		ll cs=cityX.size();
		for (ll i=0;i<cs;i++) {
			cx[i]=cityX[i]; cy[i]=cityY[i];
		}
		ll vs=villageX.size();
		for (ll i=0;i<vs;i++) {
			vx[i]=villageX[i]; vy[i]=villageY[i];
		}
		for (ll i=0;i<vs;i++) {
			for (ll j=0;j<vs;j++) {
				if (i==j) continue;
				ll dx=(vx[i]-vx[j]),dy=(vy[i]-vy[j]);
				dh[i][(dx*dx+dy*dy)].PB(j);
			}
			for (ll j=0;j<cs;j++) {
				ll dx=(vx[i]-cx[j]),dy=(vy[i]-cy[j]);
				dh[i][(dx*dx+dy*dy)].PB(j+vs);
			}
		}
		ld final=0;
		for (ll t=0;t<vs;t++) {
			for (ll v=0;v<vs;v++) {
				ll nv=0,nc=0;
				ld prev=0;
				for (auto &w:dh[v]) {
					ll dist2=w.fst;
					for (auto &idx:w.snd) {
						//printf("idx:%lld\n",idx);
						if (idx>=vs) nc++;
						else nv++;
					}
					ld notchosen=1;
					for (ll i=0;i<t;i++) {
						notchosen*=(ld)(vs-nv-i-1)/(ld)(vs-i-1);
						//printf("num:%lld den:%lld\n",vs-nv-i-1,vs-i-1);
					}
					if (nc>0) notchosen=0;
					ld chosen=1-notchosen;
					ld contrib=(chosen-prev)*sqrt((ld)dist2);
					prev=chosen;
					//if (contrib>-1e-9)printf("t:%lld v:%lld dist:%f chosen:%f contrib:%f nv:%lld nc:%lld\n",t,v,sqrt(dist2),1-notchosen,contrib,nv,nc);
					final+=contrib;
				}
			}
		}
		final/=vs;
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
		cout << "Testing KingdomXCitiesandVillages (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484375303;
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
		KingdomXCitiesandVillages _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cityX[] = {3};
				int cityY[] = {0};
				int villageX[] = {3,3};
				int villageY[] = {2,1};
				_expected = 2.5;
				_received = _obj.determineLength(vector <int>(cityX, cityX+sizeof(cityX)/sizeof(int)), vector <int>(cityY, cityY+sizeof(cityY)/sizeof(int)), vector <int>(villageX, villageX+sizeof(villageX)/sizeof(int)), vector <int>(villageY, villageY+sizeof(villageY)/sizeof(int))); break;
			}
			case 1:
			{
				int cityX[] = {1,4,7,10};
				int cityY[] = {5,5,5,5};
				int villageX[] = {1,4,7,10};
				int villageY[] = {4,4,4,4};
				_expected = 4.0;
				_received = _obj.determineLength(vector <int>(cityX, cityX+sizeof(cityX)/sizeof(int)), vector <int>(cityY, cityY+sizeof(cityY)/sizeof(int)), vector <int>(villageX, villageX+sizeof(villageX)/sizeof(int)), vector <int>(villageY, villageY+sizeof(villageY)/sizeof(int))); break;
			}
			case 2:
			{
				int cityX[] = {1,2,3};
				int cityY[] = {4,4,4};
				int villageX[] = {4,5,6};
				int villageY[] = {4,4,4};
				_expected = 4.166666666666667;
				_received = _obj.determineLength(vector <int>(cityX, cityX+sizeof(cityX)/sizeof(int)), vector <int>(cityY, cityY+sizeof(cityY)/sizeof(int)), vector <int>(villageX, villageX+sizeof(villageX)/sizeof(int)), vector <int>(villageY, villageY+sizeof(villageY)/sizeof(int))); break;
			}
			/*case 3:
			{
				int cityX[] = ;
				int cityY[] = ;
				int villageX[] = ;
				int villageY[] = ;
				_expected = ;
				_received = _obj.determineLength(vector <int>(cityX, cityX+sizeof(cityX)/sizeof(int)), vector <int>(cityY, cityY+sizeof(cityY)/sizeof(int)), vector <int>(villageX, villageX+sizeof(villageX)/sizeof(int)), vector <int>(villageY, villageY+sizeof(villageY)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int cityX[] = ;
				int cityY[] = ;
				int villageX[] = ;
				int villageY[] = ;
				_expected = ;
				_received = _obj.determineLength(vector <int>(cityX, cityX+sizeof(cityX)/sizeof(int)), vector <int>(cityY, cityY+sizeof(cityY)/sizeof(int)), vector <int>(villageX, villageX+sizeof(villageX)/sizeof(int)), vector <int>(villageY, villageY+sizeof(villageY)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int cityX[] = ;
				int cityY[] = ;
				int villageX[] = ;
				int villageY[] = ;
				_expected = ;
				_received = _obj.determineLength(vector <int>(cityX, cityX+sizeof(cityX)/sizeof(int)), vector <int>(cityY, cityY+sizeof(cityY)/sizeof(int)), vector <int>(villageX, villageX+sizeof(villageX)/sizeof(int)), vector <int>(villageY, villageY+sizeof(villageY)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
