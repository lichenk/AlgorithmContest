#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL

#define LESS -1
#define EQ 0
#define GREATER 1
ll gn, gx0, ga, gb;
map<int, int> ls;
map<int, int, greater<int> > gr;
ll f(ll guess, ll pos) {
	ll less = 0;
	ll greater = 0;
	ll y;
	y = gx0;
	if (y < guess) less++;
	if (y > guess) greater++;
	for (ll i = 1; i < gn; i++) {
		y = (y*ga + gb)%MOD;
		if (y < guess) less++;
		if (y > guess) greater++;
	}
	greater = gn - (greater-1);
	ls[less] = guess;
	gr[greater] = guess;
	pos = pos + 1;
	if (pos <= less) {
		return GREATER;
	}
	else if (pos >= greater) {
		return LESS;
	}
	else {
		return EQ;
	}
}


ll binsearch(ll key, ll imin, ll imax)
{
	printf("%lld %lld %lld\n",imin,imax,imax-imin);
	while (imin <= imax)
		{
			ll imid = (imin+imax)/2;
			ll ret = f(imid, key);
			if (ret == EQ)
			  	{return imid;}
			else if (ret == LESS)
			  	{imin = imid + 1;}
			else
				{imax = imid - 1;}
		}
	// key was not found
	assert(false);
}

class LimitedMemorySeries1 {
	public:
	long long getSum(int n, int x0, int a, int b, vector <int> query) {
		gn = n; gx0 = x0; ga = a; gb = b;
		ll ans = 0;
		sort(query.begin(), query.end());
		for (ll i = 0; i < query.size(); i++) {
			ll k = query[i];
			ll lo = 0; ll hi = MOD;
			auto hi_it = ls.lower_bound(k+1);
			if (hi_it != ls.end()) hi = hi_it->second;
			auto lo_it = gr.lower_bound(k-1);
			if (lo_it != gr.end()) lo = lo_it->second;
			ll cand = binsearch(query[i], lo, hi);
			ans += cand;
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
		cout << "Testing LimitedMemorySeries1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1449769397;
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
		LimitedMemorySeries1 _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 5;
				int x0 = 100;
				int a = 1;
				int b = 5;
				int query[] = {0,3};
				_expected = 215LL;
				_received = _obj.getSum(n, x0, a, b, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 5;
				int x0 = 123456789;
				int a = 987654321;
				int b = 1000000006;
				int query[] = {0,1,2,3};
				_expected = 733028692LL;
				_received = _obj.getSum(n, x0, a, b, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 5000000;
				int x0 = 482995837;
				int a = 512849030;
				int b = 120583724;
				int query[] = {4854010,3139503,1855546,219904,846357,2624639,891260,217467,4940091,4802760,2424821,424076,
				               3848272,2062765,2922407,4850301,1279972,4929307,2035456,3562859,1749594,4089499,3797495,1013980,
				               1650805,1245213,3020379,4661668,427170,1176815,292944,2435328,420809,4170355,2635197,3940607,
				               4311718,2098572,4868054,30319,4588969,1460677,1335028,3921495,3621970,4459335,966000,3686977,
				               2316560,1634961,2280624,1940395,3321546,3168811,1856547,3859093,4340475,1382782,3482928,2517843,
				               185008,1135373,2821050,3260484,4821220,1700954,3243343,2183615,394339,2630121,1811267,1060542,
				               3898314,892312,2015580,11161,4965095,2128470,2320933,1095881,3938450,1887098,975426,2098073,3300937,
				               1145560,2894728,1026181,3259403,4509345,3610224,3584456,1877483,2665752,2243671,616205,504849,3068426,
				               1471925,4144568};
				_expected = 49684994148LL;
				_received = _obj.getSum(n, x0, a, b, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			/*case 3:
			{
				int n = ;
				int x0 = ;
				int a = ;
				int b = ;
				int query[] = ;
				_expected = LL;
				_received = _obj.getSum(n, x0, a, b, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int n = ;
				int x0 = ;
				int a = ;
				int b = ;
				int query[] = ;
				_expected = LL;
				_received = _obj.getSum(n, x0, a, b, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int x0 = ;
				int a = ;
				int b = ;
				int query[] = ;
				_expected = LL;
				_received = _obj.getSum(n, x0, a, b, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
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
