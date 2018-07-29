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
const ll MAXP=2e5+4;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
vector<ll> gpv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
		sp[i]=INF;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
				chkmin(sp[j],i);
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if(sieve_array[i]) {
			gpv.PB(i);
			chkmin(sp[i],i);
		}
	}
}
map<ll,ll> factorize(ll x) {
	map<ll,ll> h;
	while(x>=MAXP) {
		bool found=false;
		for (auto &p:gpv) {
			if (p*p>x) break;
			if ((x%p)==0) {
				x/=p;
				h[p]++;
				found=true;
				break;
			}
		}
		if (!found) break;
	}
	if (x<MAXP) {
		while(x>1) {
		ll p=sp[x];
		x/=p;
		h[p]++;
		}
	}
	if (x>1) h[x]++;
	return h;
}
ll ga,gb;
ll finalans=INF;
void getdivisors(ll inp, ll add) {
	map<ll,ll> h=factorize(inp);
	vector<ll> pr;
	vector<ll> mult;
	ll zlim=1;
	for (auto &w:h) {
		pr.PB(w.first);
		mult.PB(w.second+1);
		zlim*=w.second+1;
	}
	vector<ll> res;
	for (ll zz=0;zz<zlim;zz++) {
		ll z=zz;
		ll x=1;
		for (ll i=0;i<pr.size();i++) {
			ll p=pr[i];
			ll mul=mult[i];
			ll k=z%mul;
			z/=mul;
			for (ll j=0;j<k;j++) x*=p;
		}
		ll cand=add+abs(ga-x)+abs(gb-inp/x);
		chkmin(finalans,cand);
	}
}
const ll bound=sqrt(1e9)+1;
class CorrectMultiplication {
	public:
	long long getMinimum(int a, int b, int c) {
		sieve();
		ll xmin=max(1LL,c-bound); ll xmax=c+bound;
		ga=a;gb=b;
		for (ll x=xmin;x<=xmax;x++) {
			getdivisors(x,abs(x-c));
		}
		return finalans;
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
		cout << "Testing CorrectMultiplication (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1473443131;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CorrectMultiplication _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a = 19;
				int b = 28;
				int c = 522;
				_expected = 2LL;
				_received = _obj.getMinimum(a, b, c); break;
			}
			case 1:
			{
				int a = 10;
				int b = 30;
				int c = 500;
				_expected = 11LL;
				_received = _obj.getMinimum(a, b, c); break;
			}
			case 2:
			{
				int a = 11111;
				int b = 11111;
				int c = 123454321;
				_expected = 0LL;
				_received = _obj.getMinimum(a, b, c); break;
			}
			case 3:
			{
				int a = 1000;
				int b = 100;
				int c = 10;
				_expected = 1089LL;
				_received = _obj.getMinimum(a, b, c); break;
			}
			case 4:
			{
				int a = 399;
				int b = 522;
				int c = 199999;
				_expected = 24LL;
				_received = _obj.getMinimum(a, b, c); break;
			}
			/*case 5:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = LL;
				_received = _obj.getMinimum(a, b, c); break;
			}*/
			/*case 6:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = LL;
				_received = _obj.getMinimum(a, b, c); break;
			}*/
			/*case 7:
			{
				int a = ;
				int b = ;
				int c = ;
				_expected = LL;
				_received = _obj.getMinimum(a, b, c); break;
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
