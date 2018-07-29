#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
#define fst first
#define snd second
class BunnyExam {
	public:
	double getExpected(int m, int klim, vector <int> linkage) {
		ld ans=(ld)m/(ld)klim;
		if (klim==1) {
			if (m==1) return ans;
			else return -1;
		}
		ll lsz=linkage.size()/2;
		for (ll i=0;i<lsz;i++) {
			if (abs(linkage[2*i]-linkage[2*i+1])<=1) return -1.0;
		}
		if (klim<=5) {
			ll zlim=1; for (ll i=0;i<lsz;i++) zlim*=klim;
			for (ll zz=0;zz<zlim;zz++) {
				ll z=zz;
				vector<pll> constraints;
				for (ll i=0;i<lsz;i++) {
					constraints.PB(MP(linkage[2*i],z%klim));
					constraints.PB(MP(linkage[2*i+1],z%klim));
					z/=klim;
				}
				sort(constraints.begin(),constraints.end());
				bool ok=true;
				ll csz=constraints.size();
				for (ll i=0;i<csz-1;i++) {
					ll l=constraints[i].fst,r=constraints[i+1].fst;
					ll lc=constraints[i].snd,rc=constraints[i+1].snd;
					if (lc==rc&&abs(l-r)<=1) {
						//if (zz==1) printf("Ai:%lld\n",i);
						ok=false; break;
					}
					if (klim==2) {
						if (lc==rc) {
							if ((r-l)%2==1) {
								//if (zz==1) printf("Bi:%lld\n",i);
								ok=false; break;
							}
						}
						if (lc!=rc) {
							if ((r-l)%2==0) {
								//if (zz==1) printf("Ci:%lld\n",i);
								ok=false; break;
							}
						}
					}
				}
				if (ok) return ans;
			}
			return -1.0;
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
		cout << "Testing BunnyExam (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486953937;
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
		BunnyExam _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m = 3;
				int k = 2;
				int linkage[] = { 1, 3 };
				_expected = 1.5;
				_received = _obj.getExpected(m, k, vector <int>(linkage, linkage+sizeof(linkage)/sizeof(int))); break;
			}
			case 1:
			{
				int m = 4;
				int k = 2;
				int linkage[] = { 1, 4 };
				_expected = -1.0;
				_received = _obj.getExpected(m, k, vector <int>(linkage, linkage+sizeof(linkage)/sizeof(int))); break;
			}
			case 2:
			{
				int m = 2;
				int k = 8;
				int linkage[] = { };
				_expected = 0.25;
				_received = _obj.getExpected(m, k, vector <int>(linkage, linkage+sizeof(linkage)/sizeof(int))); break;
			}
			case 3:
			{
				int m = 1000000000;
				int k = 1;
				int linkage[] = { 11, 13, 2010, 487 };
				_expected = -1.0;
				_received = _obj.getExpected(m, k, vector <int>(linkage, linkage+sizeof(linkage)/sizeof(int))); break;
			}
			case 4:
			{
				int m = 128;
				int k = 64;
				int linkage[] = { 32, 16, 8, 4, 2, 1 };
				_expected = -1.0;
				_received = _obj.getExpected(m, k, vector <int>(linkage, linkage+sizeof(linkage)/sizeof(int))); break;
			}
			case 5:
			{
				int m = 13;
				int k = 3;
				int linkage[] = { 1, 3, 7, 9, 13, 10, 6, 2  };
				_expected = 4.333333333333333;
				_received = _obj.getExpected(m, k, vector <int>(linkage, linkage+sizeof(linkage)/sizeof(int))); break;
			}
			case 6:
			{
				int m = 18800429;
				int k = 2;
				int linkage[] = {15311717, 3702861, 17811936, 9486478, 3779377, 2245115, 13900461, 8862969, 15886268, 767934, 7009840, 7407384, 9254518, 3986752, 7074291, 18485585, 6772979, 18615931, 16817829, 7812559};
				_expected = 9400214.5;
				_received = _obj.getExpected(m, k, vector <int>(linkage, linkage+sizeof(linkage)/sizeof(int))); break;
			}
			case 7:
			{
				int m = 4;
				int k = 2;
				int linkage[] = {4, 2, 3, 1};
				_expected = 2.0;
				_received = _obj.getExpected(m, k, vector <int>(linkage, linkage+sizeof(linkage)/sizeof(int))); break;
			}
			/*case 8:
			{
				int m = ;
				int k = ;
				int linkage[] = ;
				_expected = ;
				_received = _obj.getExpected(m, k, vector <int>(linkage, linkage+sizeof(linkage)/sizeof(int))); break;
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
