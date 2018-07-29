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
ll vcnt[26];
class BalancedStrings {
	public:
	vector <string> findAny(int N) {
		if (N==1) {
			return {"a"};
		}
		for (ll extra=1;;extra++) {
			memset(vcnt,0,sizeof vcnt);
			ll n=N-extra;
			ll clim=26-extra*2;
			vector<string> ans;
			while(1) {
				for (ll i=0;i<clim;i++) {
					if (n==0) break;
					vcnt[i]++;
					char c='a'+i;
					string s; s+=c;
					ans.PB(s);
					n--;
				}
				if (n==0) break;
			}
			ll sim=0;
			for (ll i=0;i<26;i++) {
				ll k=vcnt[i];
				sim+=((k*(k-1)))/2;
			}
			//printf("extra:%d sim:%d\n",extra,sim);
			//for (auto &w:ans) printf("%s, ",w.c_str());
			//printf("\n");
			for (ll e=0;e<extra;e++) {
				string s="";
				char a[2];
				a[0]='a'+26-2*(e+1);
				a[1]='a'+26-2*(e+1)+1;
				ll cur=0;
				s+=a[cur];
				for (ll i=0;i<99;i++) {
					if (sim==0) break;
					cur^=1;
					s+=a[cur];
					sim--;
				}
				ans.PB(s);
			}
			if (sim==0) return ans;
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
		cout << "Testing BalancedStrings (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486785451;
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
		BalancedStrings _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				string __expected[] = {"eertree", "topcoder", "arena" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			case 1:
			{
				int N = 4;
				string __expected[] = {"hello", "little", "polar", "bear" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			case 2:
			{
				int N = 5;
				string __expected[] = {"abbbbbbbbbbbbczaaaaaao", "c", "zz", "c", "xxxyyyzvvv" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			case 3:
			{
				int N = 1;
				string __expected[] = {"kkkkkkkkkkkkkkkkkkk" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			case 4:
			{
				int N = 10;
				string __expected[] = {"asdflkjhsdfsfffkdhjfdlshlfds", "pudelek", "xo", "xo", "mnbvmnmbbr", "plox", "qqwwrrttyyy", "you", "are", "awesome" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			case 5:
			{
				int N = 85;
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			case 6:
			{
				int N = 100;
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
			}
			/*case 7:
			{
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findAny(N); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
