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
class ColorfulChocolates {
	public:
	int maximumSpread(string t, int maxSwaps) {
		ll n=t.length();
		ll best=0;
		for (ll s=0;s<n;s++) {
			for (ll cc=0;cc<26;cc++) {
				char c='A'+cc;
				if (t[s]==c) {
					ll ans=1;
					vector<ll> v;
					{
						ll y=s+1;
						for (ll x=s+1;x<n;x++) {
							if (t[x]==c) {
								//if (s==3&&c=='C') printf("%lld gets %lld\n",x,abs(x-y));
								v.PB(abs(x-y)); y++;
							}
						}
					}
					{
						ll y=s-1;
						for (ll x=s-1;x>=0;x--) {
							if (t[x]==c) {
								//if (s==3&&c=='C') printf("%lld gets %lld\n",x,abs(x-y));
								v.PB(abs(x-y)); y--;
							}
						}
					}
					sort(v.begin(),v.end());
					ll left=maxSwaps;
					for (auto &w:v) {
						if (left-w<0) break;
						left-=w;
						ans++;
					}
					//if (ans==3) printf("s:%lld c:%c\n",s,c);
					chkmax(best,ans);
				}
				else {
					for (ll k=0;k<2;k++) {

					ll ans=0;
					vector<ll> v;
					{
						ll y=(k==0)?s:s+1;
						for (ll x=s+1;x<n;x++) {
							if (t[x]==c) {
								//if (s==3&&c=='C') printf("%lld gets %lld\n",x,abs(x-y));
								v.PB(abs(x-y)); y++;
							}
						}
					}
					{
						ll y=(k==0)?s-1:s;
						for (ll x=s-1;x>=0;x--) {
							if (t[x]==c) {
								//if (s==3&&c=='C') printf("%lld gets %lld\n",x,abs(x-y));
								v.PB(abs(x-y)); y--;
							}
						}
					}
					sort(v.begin(),v.end());
					ll left=maxSwaps;
					for (auto &w:v) {
						if (left-w<0) break;
						left-=w;
						ans++;
					}
					//if (ans==3) printf("s:%lld c:%c\n",s,c);
					chkmax(best,ans);


					}
				}
			}
		}
		return best;
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
		cout << "Testing ColorfulChocolates (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1469803457;
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
		ColorfulChocolates _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chocolates = "ABCDCBC";
				int maxSwaps = 1;
				_expected = 2;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 1:
			{
				string chocolates = "ABCDCBC";
				int maxSwaps = 2;
				_expected = 3;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 2:
			{
				string chocolates = "ABBABABBA";
				int maxSwaps = 3;
				_expected = 4;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 3:
			{
				string chocolates = "ABBABABBA";
				int maxSwaps = 4;
				_expected = 5;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			case 4:
			{
				string chocolates = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
				int maxSwaps = 77;
				_expected = 5;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}
			/*case 5:
			{
				string chocolates = ;
				int maxSwaps = ;
				_expected = ;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}*/
			/*case 6:
			{
				string chocolates = ;
				int maxSwaps = ;
				_expected = ;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
			}*/
			/*case 7:
			{
				string chocolates = ;
				int maxSwaps = ;
				_expected = ;
				_received = _obj.maximumSpread(chocolates, maxSwaps); break;
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
