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
inline vector<ll> load(vector<string> L) {
	string s = "";
	ll Lsz=L.size();
	for (ll i=0; i<Lsz;++i) s+=L[i];
	stringstream in(s);
	ll x;
	vector<ll> ret;
	while (in>>x) {
		ret.push_back(x);
	}
	return ret;
}
ld getc(ld x1,ld y1,ld x2,ld y2) {
	return y1-x1*(y2-y1)/(x2-x1);
}
class Ear {
	public:
	long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
		vector<ll> rxv=load(redX);
		vector<ll> bx=load(blueX);
		vector<ll> by=load(blueY);
		sort(rxv.begin(),rxv.end());
		map<ll,ll,greater<ll> > rxf;
		map<ll,ll,greater<ll> > rxr;
		ll bn=bx.size(),rn=rxv.size();
		for (ll i=0;i<rn;i++) {
			rxf[-rxv[i]]=rn-1-i;
			rxr[rxv[i]]=i;
		}
		ll ans=0;
		for (ll a=0;a<bn;a++) {
			for (ll b=0;b<bn;b++) {
				if (!(by[a]>by[b])) continue;
				ll lf=0,rt=0;
				{
					//printf("bxa:%lld bxb:%lld\n",bx[a],bx[b]);
					ld out=getc(by[a],bx[a],by[b],bx[b]);
					ll iout;
					if (fabs(out-round(out))<1e-9) iout=round(out);
					else iout=ceil(out);
					auto ait=rxr.upper_bound(min(bx[a],iout));
					if (ait==rxr.end()) continue;
					ll ai=ait->second;
					auto bit=rxr.upper_bound(bx[b]);
					if (bit==rxr.end()) continue;
					ll bi=bit->second;
					for (ll j=bi;j>=1;j--) {
						lf+=min(j,ai+1);
					}
				}
				{
					//printf("bxa:%lld bxb:%lld\n",bx[a],bx[b]);
					ld out=getc(by[a],-bx[a],by[b],-bx[b]);
					ll iout;
					if (fabs(out-round(out))<1e-9) iout=round(out);
					else iout=ceil(out);
					auto ait=rxf.upper_bound(min(-bx[a],iout));
					if (ait==rxf.end()) continue;
					ll ai=ait->second;
					auto bit=rxf.upper_bound(-bx[b]);
					if (bit==rxf.end()) continue;
					ll bi=bit->second;
					for (ll j=bi;j>=1;j--) {
						rt+=min(j,ai+1);
					}
				}
				ll cand=lf*rt;
				//if (cand>0) printf("%lld %lld. %lld %lld. cand:%lld\n",bx[a],by[a],bx[b],by[b],cand);
				ans+=cand;
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
		cout << "Testing Ear (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1466743889;
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
		Ear _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string redX[] = {"3 2 8 7"};
				string blueX[] = {"5 4"};
				string blueY[] = {"2 4"};
				_expected = 1LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 1:
			{
				string redX[] = {"3 2 8 7"};
				string blueX[] = {"2 8"};
				string blueY[] = {"3 4"};
				_expected = 0LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 2:
			{
				string redX[] = {"1 2 6 9"};
				string blueX[] = {"3 6 8 5"};
				string blueY[] = {"1 5 4 3"};
				_expected = 4LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 3:
			{
				string redX[] = {"10000"};
				string blueX[] = {"10000 9999"};
				string blueY[] = {"10000 9999"};
				_expected = 0LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 4:
			{
				string redX[] = {"100 2", "00", " 39", "9", " 800 900 9", "99"};
				string blueX[] = {"15", "0 250 ", "349"};
				string blueY[] = {"2 3 1"};
				_expected = 12LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 5:
			{
				string redX[] = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"};
				string blueX[] = {"4", " ", "5", " ", "6", " 7 ", "8"};
				string blueY[] = {"1", " 2 ", "3 4", " 5"};
				_expected = 204LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			case 6:
			{
				string redX[] = {"9 8 4 1"};
				string blueX[] = {"7 4 2 5"};
				string blueY[] = {"1 5 4 3"};
				_expected = 4LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}
			/*case 7:
			{
				string redX[] = ;
				string blueX[] = ;
				string blueY[] = ;
				_expected = LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string redX[] = ;
				string blueX[] = ;
				string blueY[] = ;
				_expected = LL;
				_received = _obj.getCount(vector <string>(redX, redX+sizeof(redX)/sizeof(string)), vector <string>(blueX, blueX+sizeof(blueX)/sizeof(string)), vector <string>(blueY, blueY+sizeof(blueY)/sizeof(string))); break;
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
