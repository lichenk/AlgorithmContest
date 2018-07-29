#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

const ll MAXN=1e4+4;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
			}
		}
	}
}
string c;
ll cs,n;
bool possible(ll x, ll si) {
	if (!(
				(c[si]=='B'&&!sieve_array[x])||
				(c[si]=='R'&&sieve_array[x])
				)) return false;
	for (ll i=si;i<cs;i++) {
		while(x<=n&&
			!(
				(c[i]=='B'&&!sieve_array[x])||
				(c[i]=='R'&&sieve_array[x])
				)) x++;
		if (x<=n) {
			x++;
		}
		else return false;
	}
	return true;
}
class ColorfulCards {
	public:
	vector <int> theCards(int N, string _c) {
		n=N;
		c=_c;
		sieve();
		cs=c.size();
		ll x=1;
		vector<int> ans;
		for (ll i=0;i<cs;i++) {
			vector<ll> v;
			for (ll y=x;y<=N;y++) {
				if (possible(y,i)) v.PB(y);
			}
			if (v.size()>1) ans.PB(-1);
			else ans.PB(v[0]);
			x=v[0]+1;
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
		cout << "Testing ColorfulCards (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484513510;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ColorfulCards _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 5;
				string colors = "RRR";
				int __expected[] = {2, 3, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.theCards(N, colors); break;
			}
			case 1:
			{
				int N = 7;
				string colors = "BBB";
				int __expected[] = {1, 4, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.theCards(N, colors); break;
			}
			case 2:
			{
				int N = 6;
				string colors = "RBR";
				int __expected[] = {-1, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.theCards(N, colors); break;
			}
			case 3:
			{
				int N = 58;
				string colors = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
				int __expected[] = {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.theCards(N, colors); break;
			}
			case 4:
			{
				int N = 495;
				string colors = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
				int __expected[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.theCards(N, colors); break;
			}
			/*case 5:
			{
				int N = ;
				string colors = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.theCards(N, colors); break;
			}*/
			/*case 6:
			{
				int N = ;
				string colors = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.theCards(N, colors); break;
			}*/
			/*case 7:
			{
				int N = ;
				string colors = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.theCards(N, colors); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
