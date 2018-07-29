#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<30LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
#define fst first
#define snd second
const ll maxk=6;
const ll xlim=200000;
vector<pair<ll,ld> > h[maxk];
ld eh[maxk][xlim];
ld f[maxk][xlim];
ld prefixsum[xlim+1];
ld getrangesum(ll l, ll r) {
	return prefixsum[r+1]-prefixsum[l];
}
const ld EPS=1e-20;
class OptimalBetting {
	public:
	double findProbability(int a, int b, int klim) {
		h[klim].PB(MP(0,0.0));
		h[klim].PB(MP(b,1.0));
		h[klim].PB(MP(INF,1.0));
		for (ll k=klim;k>=1;k--) {
			ll hsz=h[k].size()-1;
			ld prev=0;
			h[k-1].PB(MP(0,prev));
			for (ll x=1;x<b;x++) {
				ld ans=0;
				for (ll p=0;p<hsz;p++) for (ll q=p;q<hsz;q++) {
					ll pl=h[k][p].fst,pr=h[k][p+1].fst-1;
					ll ql=h[k][q].fst,qr=h[k][q+1].fst-1;
					ld prob=(h[k][p].snd+h[k][q].snd)/2;
					ll lok=max(max(0ll,x-pr),max(0ll,ql-x));
					ll hik=min(x,min(x-pl,qr-x));
					if (lok<=hik) {
						//printf("x:%d pl:%d pr:%d ql:%d qr:%d prob:%f lok:%d hik:%d\n",x,pl,pr,ql,qr,prob,lok,hik);
						chkmax(ans,prob);
					}
				}
				eh[k-1][x]=ans;
				//printf("k:%lld x:%lld ans:%f\n",k,x,ans);
				{
					if (fabs(prev-ans)>=EPS) {
						h[k-1].PB(MP(x,ans));
					}
				}
				prev=ans;
			}
			h[k-1].PB(MP(b,1.0));
			h[k-1].PB(MP(INF,1.0));
		}

		f[0][a]=1;
		ld final=0;
		for (ll k=1;k<=klim;k++) {
			for (ll x=0;x<b;x++) {
				ll hsz=h[k].size()-1;
				ll goodcnt=0;
				ld now=f[k-1][x];
				//if (now<EPS) continue;
				ll all=x+1;
				ld invall=now/(2*all);
				for (ll p=0;p<hsz;p++) for (ll q=p;q<hsz;q++) {
					ll pl=h[k][p].fst,pr=h[k][p+1].fst-1;
					ll ql=h[k][q].fst,qr=h[k][q+1].fst-1;
					ld prob=(h[k][p].snd+h[k][q].snd)/2;
					//if (k==1) printf("prob:%.10f\n",(double)prob);
					ll lok=max(max(0ll,x-pr),max(0ll,ql-x));
					ll hik=min(x,min(x-pl,qr-x));
					//if (now>EPS)printf("k:%d x:%d now:%f lok:%d hik:%d. pl:%d pr:%d ql:%d qr:%d\n",k,x,now,lok,hik,prob,eh[k-1][x],pl,pr,ql,qr);
					//if (now>EPS&&lok<=hik) printf("k:%d x:%d now:%f lok:%d hik:%d. prob: %f opt:%f\n",k,x,now,lok,hik,prob,eh[k-1][x]);
					if (lok<=hik&&fabs(prob-eh[k-1][x])<EPS) {
						//printf("k:%d x:%d now:%f lok:%d hik:%d. prob: %f opt:%f\n",k,x,now,lok,hik,prob,eh[k-1][x]);
						f[k][x+lok]+=invall;
						f[k][x+hik+1]-=invall;
						f[k][x-hik]+=invall;
						f[k][x-lok+1]-=invall;
						ll cnt=hik-lok+1;
						goodcnt+=cnt;
					}
				}
				ll badcnt=all-goodcnt;
				final+=(now*badcnt)/(ld)all;
				//printf("k:%d x:%d addbad:%f\n",k,x,(now*badcnt)/(ld)all);
			}
			for (ll x=1;x<b;x++) {
				f[k][x]+=f[k][x-1];
			}
		}
		return 1.0-final;
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
		cout << "Testing OptimalBetting (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486791813;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		OptimalBetting _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 23;
				int b = 26;
				int k = 1;
				_expected = 0.875;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 1:
			{
				int a = 7;
				int b = 1000;
				int k = 3;
				_expected = 1.0;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 2:
			{
				int a = 2;
				int b = 3;
				int k = 2;
				_expected = 0.8888888888888887;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 3:
			{
				int a = 7;
				int b = 8;
				int k = 3;
				_expected = 0.06785714285714287;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 4:
			{
				int a = 10;
				int b = 20;
				int k = 2;
				_expected = 0.09917355371900842;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 5:
			{
				int a = 1234;
				int b = 1567;
				int k = 5;
				_expected = 0.00861475126753315;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 6:
			{
				int a = 50123;
				int b = 87654;
				int k = 5;
				_expected = 0.02304278352341867;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 7:
			{
				int a = 1;
				int b = 2;
				int k = 1;
				_expected = 0.5;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 8:
			{
				int a = 1;
				int b = 3;
				int k = 1;
				_expected = 1.0;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 9:
			{
				int a = 1;
				int b = 4;
				int k = 2;
				_expected = 0.333333333333;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 10:
			{
				int a = 1;
				int b = 3;
				int k = 2;
				_expected = 0.416666666667;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 11:
			{
				int a = 3;
				int b = 4;
				int k = 2;
				_expected = 0.166666666667;
				_received = _obj.findProbability(a, b, k); break;
			}
			case 12:
			{
				int a = 87655;
				int b = 87656;
				int k = 5;
				_expected = 0.03228692395295418;
				_received = _obj.findProbability(a, b, k); break;
			}
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
