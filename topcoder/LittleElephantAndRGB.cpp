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
const ll MN=2504;
int pre[MN],post[MN],preg[MN][MN],postg[MN][MN];
ll c2(ll x, ll y) {
	ll num=y-x+1;
	return (num*(num+1))/2;
}
class LittleElephantAndRGB {
	public:
	long long getNumber(vector <string> list, int minGreen) {
		for (ll x=0;x<MN;x++) pre[x]=0,post[x]=0;
		for (ll x=0;x<MN;x++) for (ll y=0;y<MN;y++) preg[x][y]=0,postg[x][y]=0;
		string s; for (auto &w:list) s+=w;
		ll n=s.length();
		for (ll x=0;x<n;x++) {
			ll g=0;
			for (ll y=x;y>=0;y--) {
				if (s[y]!='G') g=0;
				else g++;
				if (g==minGreen) {
					pre[x]=y+1; break;
				}
			}
		}
		for (ll x=1;x<n;x++) {
			ll g=0;
			for (ll y=x;y<n;y++) {
				if (s[y]!='G') g=0;
				else g++;
				if (g==minGreen) {
					post[x]=n-y; break;
				}
			}
		}
		for (ll x=0;x<n;x++) {
			ll g=0;
			ll initg=0;
			bool ok=true;
			for (ll y=x;y>=0;y--) {
				if (s[y]!='G') {ok=false;g=0;}
				else {g++; if(ok) initg++;}
				if (g>=minGreen) break;
				preg[x][initg]++;
			}
		}
		for (ll x=1;x<n;x++) {
			ll g=0,initg=0; bool ok=true;
			for (ll y=x;y<n;y++) {
				if (s[y]!='G') {ok=false;g=0;}
				else {g++; if(ok) initg++;}
				if (g>=minGreen) break;
				postg[x][initg]++;
				//printf("x:%lld initg:%lld v:%lld\n",x,initg,postg[x][initg]);
			}
		}
		for (ll x=1;x<n;x++) {
			for (ll g=MN-2;g>=0;g--) {
				postg[x][g]+=postg[x][g+1];
			}
		}
		for (ll x=n-2;x>=1;x--) {
			for (ll g=0;g<MN;g++) {
				postg[x][g]+=postg[x+1][g];
			}
		}
		for (ll x=1;x<n;x++) for (ll g=0;g<4;g++) {
			//printf("%lld %lld: %lld\n",x,g,postg[x][g]);
		}
		ll ans=0;
		for (ll x=0;x<=n-2;x++) {
			ll fst=pre[x]*c2(x+1,n-1);
			ll sec=c2(0,x)*post[x+1];
			ll both=0;
			for (ll y=x+1;y<n;y++) both+=post[y];
			both*=pre[x];
			ll special=0;
			for (ll g=0;g<=minGreen;g++) {
				special+=preg[x][g]*((ll)postg[x+1][minGreen-g]);
				//printf("g:%lld %lld*%lld=%lld\n",g,preg[x][g],postg[x+1][minGreen-g],preg[x][g]*postg[x+1][minGreen-g]);
			}
			//printf("x:%lld fst:%lld*%lld=%lld sec:%lld both:%lld special:%lld\n",x,pre[x],c2(x+1,n-1),fst,sec,both,special);
			ll cand=fst+sec-both+special;
			ans+=cand;
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
		cout << "Testing LittleElephantAndRGB (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470846983;
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
		LittleElephantAndRGB _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string list[] = {"GRG"};
				int minGreen = 2;
				_expected = 1LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}
			case 1:
			{
				string list[] = {"GG", "GG"};
				int minGreen = 3;
				_expected = 9LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}
			case 2:
			{
				string list[] = {"GRBGRBBRG"};
				int minGreen = 2;
				_expected = 11LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}
			case 3:
			{
				string list[] = {"RRBRBBRRR", "R", "B"};
				int minGreen = 1;
				_expected = 0LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}
			case 4:
			{
				string list[] = {"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"};
				int minGreen = 4;
				_expected = 12430LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}
			/*case 5:
			{
				string list[] = ;
				int minGreen = ;
				_expected = LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}*/
			/*case 6:
			{
				string list[] = ;
				int minGreen = ;
				_expected = LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
			}*/
			/*case 7:
			{
				string list[] = ;
				int minGreen = ;
				_expected = LL;
				_received = _obj.getNumber(vector <string>(list, list+sizeof(list)/sizeof(string)), minGreen); break;
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
