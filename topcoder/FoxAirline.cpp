#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll INF=0x7fffffff;
const ll MAXN=12;
const ll MAXZ=531441;
const ll NONE=0;
const ll HPATH=1;
const ll DONE=2;
ll f[MAXZ][MAXN], t[MAXN];
vector<pair<ll,ll> > g[MAXN];
vector<ll> v[MAXN+1][MAXN+1];
ll gn;
/*
void //printz(string s, ll z) {
	//printf("%s",s.c_str());
	for (ll i=0;i<gn;i++) {
		//printf("%lld ",z%3);
		z/=3;
	}
	//printf(".");
}*/
class FoxAirline {
	public:
	int minimalCost(int n, vector <int> a, vector <int> b, vector <int> c) {
		gn=n;
		for (ll i=0;i<a.size();i++) {
			ll x=a[i]; ll y=b[i];
			g[x].PB(MP(y,c[i]));
		}
		ll lim=1;
		for (ll i=0;i<n;i++) lim*=3;
		for (ll z=0;z<lim;z++) {
			for (ll last=0;last<n;last++) {
				f[z][last]=INF;
			}
		}
		for (ll zz=0;zz<lim;zz++) {
			ll hpath=0;
			ll done=0;
			ll tmpz=zz;
			for (ll i=0;i<n;i++) {
				ll zmod=tmpz%3;
				if (zmod==DONE)done++;
				else if (zmod==HPATH)hpath++;
				tmpz /= 3;
			}
			v[done][hpath].PB(zz);
		}
		{
			ll done=1;
			for (auto &zz:v[done][0]) {
				f[zz][0]=0;
			}
		}
		for (ll done=1;done<=n;done++) {
			{
				ll hpath=0;
				for (auto &zz:v[done][hpath]) {
					ll val=f[zz][0];
					//printz("old0z:",zz);
					//printf(" f:%lld\n",val);
					if (val>=INF) continue;
					ll tmpz=zz;
					for (ll x=0;x<n;x++) {
						t[x]=tmpz%3;
						tmpz/=3;
					}
					for (ll last=0;last<n;last++) {
						if (t[last]!=DONE) continue;
						for (auto &e: g[last]) {
							ll y=e.first;
							if (t[y]!=NONE) continue;
							ll valcost=val+e.second;
							ll newz=0;
							for (ll i=n-1;i>=0;i--) {
								newz*=3;
								ll type = (i==y)?HPATH:t[i];
								newz+=type;
							}
							//printz("newz:",newz);
							//printf("last:%lld y:%lld valcost:%lld\n",last,y,valcost);
							f[newz][y] = min(f[newz][y], valcost);
						}
					}
				}
			}
			for (ll hpath=1;hpath<=n;hpath++) {
				for (auto &zz:v[done][hpath]) {
					ll tmpz=zz;
					for (ll x=0;x<n;x++) {
						t[x]=tmpz%3;
						tmpz/=3;
					}
					for (ll last=0;last<n;last++) {
						if (t[last]!=HPATH) continue;
						ll val=f[zz][last];
						//printz("old1z:",zz);
						//printf(" last:%lld f:%lld\n",last,val);
						if (val>=INF) continue;
						for (auto &e: g[last]) {
							ll y=e.first;
							ll valcost=val+e.second;
							if (t[y]==NONE) {
								ll newz=0;
								for (ll i=n-1;i>=0;i--) {
									newz*=3;
									ll type = (i==y)?HPATH:t[i];
									newz+=type;
								}
								f[newz][y] = min(f[newz][y],valcost);
							}
							else if (t[y]==DONE) {
								ll newz=0;
								for (ll i=n-1;i>=0;i--) {
									newz*=3;
									ll type = (t[i]==NONE)?NONE:DONE;
									newz+=type;
								}
								f[newz][0] = min(f[newz][0],valcost);
							}
						}
					}
				}
			}
		}
		{
			ll newz=0;
			for (ll i=n-1;i>=0;i--) {
				newz*=3;
				newz+=DONE;
			}
			ll ans=f[newz][0];
			if (ans>=INF) return -1;
			return ans;
		}
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
		cout << "Testing FoxAirline (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455478891;
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
		FoxAirline _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int a[] = {0,0,1,2,1,2};
				int b[] = {1,2,0,0,2,1};
				int c[] = {1,1,1,1,10,10};
				_expected = 4;
				_received = _obj.minimalCost(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 3;
				int a[] = {0,1,0,1};
				int b[] = {1,0,2,2};
				int c[] = {1,2,3,4};
				_expected = -1;
				_received = _obj.minimalCost(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 4;
				int a[] = {0,1,2,3};
				int b[] = {1,2,3,0};
				int c[] = {10,20,30,40};
				_expected = 100;
				_received = _obj.minimalCost(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 5;
				int a[] = {0,1,2,3};
				int b[] = {1,2,3,0};
				int c[] = {10,20,30,40};
				_expected = -1;
				_received = _obj.minimalCost(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 12;
				int a[] = {5,7,1,9,5,7,3,1,11,8,1,10,2,7,8,7,2,11,6,4,6,9,4,4,3,7,1,0,4,
				          10,0,6,6,8,9,0,6,6,11,10,5,5,9,0,11,3,5,0,9,7,7,5,11,8,1,8,3,
				          4,7,4,3,8,3,4,3,8,10,0,11,11,0,6,4,0,1,6,0,3,0,9,11,2,1,3,8,1,
				          2,4,11,1,7,5,5,9,9,7,5,2,4,8,2,10,3,9,5,0,11,3,2,6,6,1,6,4,2,
				          9,10,11,10,2,7,8,8,2,10,2,10,9,1,5,10,10};
				int b[] = {0,3,2,3,3,11,0,4,1,0,9,3,1,8,5,9,5,2,11,1,1,2,7,9,4,2,0,10,0,
				          0,7,2,9,4,4,9,7,8,8,8,9,2,11,11,10,10,4,6,5,10,6,10,0,2,3,10,
				          1,3,0,2,2,6,5,11,6,3,5,8,6,3,2,4,10,5,5,5,4,9,3,8,7,4,7,11,7,
				          10,11,8,4,8,4,11,8,7,10,5,6,7,5,1,9,2,8,0,1,1,5,7,0,3,0,11,10,
				          6,8,6,1,9,9,6,1,9,11,3,6,10,7,1,6,7,11,4};
				int c[] = {25984,89713,21689,14734,59359,53691,32670,17291,10665,7734,
				          78780,41871,51780,29833,83512,65961,1102,19919,82940,78302,
				          33977,93139,34297,40731,43477,27993,57723,12152,3980,70786,
				          35521,70833,64827,59029,43895,90715,48944,83551,24446,16475,
				          87602,93225,97981,94059,22358,99691,62932,90503,97309,87273,
				          52990,70178,95405,60529,54542,18236,3626,390,7246,93273,91896,
				          95133,94136,17526,40131,66971,3155,80877,27302,35933,20726,
				          36474,60672,64932,97730,17345,80773,3805,33962,10994,41796,
				          94727,81676,52518,36032,67199,99638,79108,39564,48423,20062,
				          43372,78076,70519,6529,80526,64653,68090,49366,82926,96800,
				          46972,3187,21071,40295,59157,98610,21594,64406,26409,54502,
				          32364,42991,32988,31586,90087,48361,86876,32023,64035,36642,
				          25221,35100,6541,61459,22219,93856,34767,87048,90635,29986,
				          21603};
				_expected = 189591;
				_received = _obj.minimalCost(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 1;
				int a[] = {};
				int b[] = {};
				int c[] = {};
				_expected = 0;
				_received = _obj.minimalCost(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 2;
				int a[] = {0,1};
				int b[] = {1,0};
				int c[] = {3,5};
				_expected = 8;
				_received = _obj.minimalCost(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			case 7:
			{
				int n = 3;
				int a[] = {0,0,1,2,1};
				int b[] = {1,2,0,0,2};
				int c[] = {1,1,1,1,10};
				_expected = 4;
				_received = _obj.minimalCost(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
			}
			/*case 8:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int c[] = ;
				_expected = ;
				_received = _obj.minimalCost(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(c, c+sizeof(c)/sizeof(int))); break;
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
