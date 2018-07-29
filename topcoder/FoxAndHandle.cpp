#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<30ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll need[100],s[100],cur[100],tmp[100];
class FoxAndHandle {
	public:
	string lexSmallestName(string _S) {
		ll n=_S.length();
		for (ll i=0;i<n;i++) s[i]=_S[i]-'a';
		for (ll i=0;i<26;i++) {need[i]=0; cur[i]=0;}
		for (ll i=0;i<n;i++) need[s[i]]++;
		for (ll i=0;i<26;i++) need[i]/=2;
		string ans="";
		for (ll p=0;p<n;) {
			pair<ll,ll> best=MP(INF,-1);
			for (ll x=p;x<n;x++) {
				if (cur[s[x]]>=need[s[x]]) continue;
				for (ll i=0;i<26;i++) tmp[i]=cur[i];
				for (ll y=x;y<n;y++) tmp[s[y]]++;
				bool ok=true;
				for (ll i=0;i<26;i++) {if(tmp[i]<need[i]) {ok=false;break;}}
				if (ok) {
					best=min(best,MP(s[x],x));
				}
			}
			//printf("p:%d bestc:%c bestx:%d\n",p,_S[best.second],best.second);
			cur[best.first]++;
			p=best.second+1;
			ans+=_S[best.second];
			if (ans.length()==n/2) break;
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
		cout << "Testing FoxAndHandle (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463342470;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FoxAndHandle _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "foxfox";
				_expected = "fox";
				_received = _obj.lexSmallestName(S); break;
			}
			case 1:
			{
				string S = "ccieliel";
				_expected = "ceil";
				_received = _obj.lexSmallestName(S); break;
			}
			case 2:
			{
				string S = "abaabbab";
				_expected = "aabb";
				_received = _obj.lexSmallestName(S); break;
			}
			case 3:
			{
				string S = "bbbbaaaa";
				_expected = "bbaa";
				_received = _obj.lexSmallestName(S); break;
			}
			case 4:
			{
				string S = "fedcbafedcba";
				_expected = "afedcb";
				_received = _obj.lexSmallestName(S); break;
			}
			case 5:
			{
				string S = "nodevillivedon";
				_expected = "deilvon";
				_received = _obj.lexSmallestName(S); break;
			}
			case 6:
			{
				string S = "nssnlatrvxqgdcatobphpnssnlatrvxqgdcatobphp";
				_expected = "aabhnssnltrvxqgdctopp";
				_received = _obj.lexSmallestName(S); break;
			}
			/*case 7:
			{
				string S = ;
				_expected = ;
				_received = _obj.lexSmallestName(S); break;
			}*/
			/*case 8:
			{
				string S = ;
				_expected = ;
				_received = _obj.lexSmallestName(S); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
