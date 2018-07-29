#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ld f[2][1000];
ld pf[1000],g[1000];
class AToughGame {
	public:
	double expectedGain(vector <int> prob, vector <int> value) {
		ll n=prob.size();
		if(n==1) return value[0];
		ld succ=1;
		for (ll x=0;x<n;x++) {
			pf[x] = (ld)prob[x]/(ld)1000;
			succ*=pf[x];
		}
		if (fabs(1-succ)<1e-16) {
			ld ans=0;
			for (ll x=0;x<n;x++) ans+=value[x];
			return ans;
		}
		for (ll x=0;x<n;x++) {
			f[1][x]=0;
		}
		{
			ld pr=1;
			for (ll x=0;x<n;x++) {
				g[x]=pr*(1-pf[x])/(1-succ);
				pr*=pf[x];
			}
		}
		ld ans=0;
		ld left=1;
		//const ll LIM = 500*1000;
		const ll LIM = 40000000/(n+5);
		ld e=0;
		for (ll r=0;r<LIM;r++) {
			ll c=r%2; ll prev=(r+1)%2;
			for (ll x=0;x<n;x++) {
				f[c][x]=0;
			}
			e=0;
			for (ll x=0;x<n;x++) {
				e+=f[prev][x];
				f[c][x]+=e*g[x];
				e+=value[x];
			}
			ans += left*succ*e;
			left *= (1-succ);
		}
		ans += left*e;
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
		cout << "Testing AToughGame (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456624594;
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
		AToughGame _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int prob[] = {1000,500};
				int value[] = {3,4};
				_expected = 10.0;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 1:
			{
				int prob[] = {1000,1};
				int value[] = {3,4};
				_expected = 3003.9999999999977;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 2:
			{
				int prob[] = {500,500,500,500,500};
				int value[] = {1,2,3,4,5};
				_expected = 16.626830517153095;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 3:
			{
				int prob[] = {250,750};
				int value[] = {1000,1};
				_expected = 1067.6666666666667;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 4:
			{
				int prob[] = {916,932,927,988,958,996,944,968,917,939,960,965,960,998,920,990,915,972,995,916,902,
				             968,970,962,922,959,994,915,996,996,994,986,945,947,912,946,972,951,973,965,921,910,
				             938,975,942,950,900,983,960,998,982,980,902,974,952,938,900,962,920,931,964,974,953,
				             995,946,946,903,921,923,985,919,996,930,915,991,967,996,911,999,936,1000,962,970,929,
				             966,960,930,920,958,926,983};
				int value[] = {583,428,396,17,163,815,31,536,175,165,532,781,29,963,331,987,599,497,380,180,780,25,
				              931,607,784,613,468,140,488,604,401,912,204,785,697,173,451,849,714,914,650,652,338,
				              336,177,147,22,652,901,548,370,9,118,487,779,567,818,440,10,868,316,666,690,714,623,
				              269,501,649,324,773,173,54,391,745,504,578,81,627,319,301,16,899,658,586,604,83,520,
				              81,181,943,157};
				_expected = 54204.93356505282;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 5:
			{
				int prob[] = {1000};
				int value[] = {1};
				_expected = 1;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			case 6:
			{
				int prob[] = {1000,1000};
				int value[] = {1,1};
				_expected = 2;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
			}
			/*case 7:
			{
				int prob[] = ;
				int value[] = ;
				_expected = ;
				_received = _obj.expectedGain(vector <int>(prob, prob+sizeof(prob)/sizeof(int)), vector <int>(value, value+sizeof(value)/sizeof(int))); break;
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
