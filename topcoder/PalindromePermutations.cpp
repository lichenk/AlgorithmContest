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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ld binom(ll n, ll k) {
	ld ans=1;
	for (ll x=n,y=k;y>=1;x--,y--) {
		ans*=x;
		ans /=y;
	}
	return ans;
}
ll f[100];
class PalindromePermutations {
	public:
	double palindromeProbability(string word) {
		ld ans=1;
		for (ll c=0;c<26;c++) {
			f[c]=0;
		}
		for (ll i=0;i<word.length();i++) {
			ll c=word[i]-'a';
			f[c]++;
		}
		vector<ll> v,w;
		for (ll c=0;c<26;c++) {
			if (f[c]>0 && f[c]%2==0) v.PB(f[c]);
			if (f[c]%2!=0) w.PB(f[c]);
		}
		ll n=word.length();
		if (w.size()>1) return 0;
		if (w.size()==1) {
			ll a=w[0];
			ans*=binom((n-1)/2,(a-1)/2)/binom(n,a);
			n-=a;
		}
		for (auto &a:v) {
			ans*=binom(n/2,a/2)/binom(n,a);
			//printf("(%d,%d)=%f,(%d,%d)=%f\n",n/2,a/2,(double)binom(n/2,a/2),n,a,(double)binom(n,a));
			n-=a;
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
		cout << "Testing PalindromePermutations (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457544030;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PalindromePermutations _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string word = "haha";
				_expected = 0.3333333333333333;
				_received = _obj.palindromeProbability(word); break;
			}
			case 1:
			{
				string word = "xxxxy";
				_expected = 0.2;
				_received = _obj.palindromeProbability(word); break;
			}
			case 2:
			{
				string word = "xxxx";
				_expected = 1.0;
				_received = _obj.palindromeProbability(word); break;
			}
			case 3:
			{
				string word = "abcde";
				_expected = 0.0;
				_received = _obj.palindromeProbability(word); break;
			}
			case 4:
			{
				string word = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff";
				_expected = 0.025641025641025637;
				_received = _obj.palindromeProbability(word); break;
			}
			/*case 5:
			{
				string word = ;
				_expected = ;
				_received = _obj.palindromeProbability(word); break;
			}*/
			/*case 6:
			{
				string word = ;
				_expected = ;
				_received = _obj.palindromeProbability(word); break;
			}*/
			/*case 7:
			{
				string word = ;
				_expected = ;
				_received = _obj.palindromeProbability(word); break;
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
