#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
class PermutationSignature {
	public:
	vector <int> reconstruct(string s) {
		ll n=s.length()+1;
		vector<ll> a; for (ll i=1;i<=n;i++) a.PB(i);
		ll x=0;
		vector<ll> ans;
		while(x<n-1) {
			ll len=1;
			for (;x<n-1;x++) {
				if (s[x]=='I') break;
				len++;
			}
			for (ll i=len-1;i>=0;i--) {
				ans.PB(a[i]);
				a.erase(a.begin()+i);
			}
			x++;
		}
		if (a.size()>0)ans.PB(a[0]);
		for (ll i=0;i<n-1;i++) {
			if (s[i]=='D'&&ans[i]<ans[i+1]) return {};
			if (s[i]=='I'&&ans[i]>ans[i+1]) return {};
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
		cout << "Testing PermutationSignature (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484462783;
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
		PermutationSignature _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string signature = "IIIII";
				int __expected[] = {1, 2, 3, 4, 5, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(signature); break;
			}
			case 1:
			{
				string signature = "DI";
				int __expected[] = {2, 1, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(signature); break;
			}
			case 2:
			{
				string signature = "IIIID";
				int __expected[] = {1, 2, 3, 4, 6, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(signature); break;
			}
			case 3:
			{
				string signature = "DIIDID";
				int __expected[] = {2, 1, 3, 5, 4, 7, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(signature); break;
			}
			/*case 4:
			{
				string signature = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(signature); break;
			}*/
			/*case 5:
			{
				string signature = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(signature); break;
			}*/
			/*case 6:
			{
				string signature = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.reconstruct(signature); break;
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
