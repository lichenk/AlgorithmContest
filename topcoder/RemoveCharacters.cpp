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
ll g[26];
//ll dp[1<<26];
ll f(ll z) {
	if (z==0) return 0;
	ll ans;
	ll x=63-__builtin_clzll(z);
	//printf("z:%lld x:%lld\n",z,x);
	ll neigh=g[x];
	ll nz1=z&~neigh;
	ll nz2=z&~(1LL<<x);
	if (nz1==nz2) ans=f(nz1)+1;
	else ans=max(f(nz1)+1,f(nz2));
	//dp[z]=ans;
	return ans;
}
class RemoveCharacters {
	public:
	int minimalDistinct(string A, string B) {
		ll n=A.length(),m=B.length();
		set<ll> allc;
		for (auto &c:A) allc.insert(c); for (auto &c:B) allc.insert(c);
		map<char,ll> ma,mb;
		for (auto &c:A) ma[c]++;
		for (auto &c:B) mb[c]++;
		vector<char> cv;
		for (auto &w:ma) {
			char c=w.first;
			if (ma[c]==mb[c]) cv.PB(c);
		}
		ll csz=cv.size();
		for (ll cc=0;cc<csz;cc++) {
			g[cc]=1LL<<cc;
		}
		for (ll cc=0;cc<csz;cc++) {
			char c=cv[cc];
			for (ll dd=cc+1;dd<csz;dd++) {
				char d=cv[dd];
				vector<pair<ll,ll> > va,vb;
				{
					ll ci=0,di=2000;
					for (ll x=0;x<n;x++) {
						if (A[x]==c) va.PB(MP(x,ci++));
						if (A[x]==d) va.PB(MP(x,di++));
					}
				}
				{
					ll ci=0,di=2000;
					for (ll x=0;x<m;x++) {
						if (B[x]==c) vb.PB(MP(x,ci++));
						if (B[x]==d) vb.PB(MP(x,di++));
					}
				}
				bool ok=true;
				if (va.size()!=vb.size()) ok=false;
				if (ok) {
					sort(va.begin(),va.end());
					sort(vb.begin(),vb.end());
					ll vsz=va.size();
					for (ll x=0;x<vsz;x++) {
						if (va[x].second!=vb[x].second) {
							ok=false; break;
						}
					}
				}
				if (!ok) {
					//printf("Adding edge: %lld %lld\n",cc,dd);
					g[cc]|=1LL<<dd;
					g[dd]|=1LL<<cc;
				}
			}
		}
		ll zlim=1LL<<csz;
		//for (ll z=0;z<zlim;z++) dp[z]=UNDEF;
		//dp[0]=0;
		ll ans=f(zlim-1);
		//printf("ans:%lld csz:%lld allc:%lld\n",ans,csz,(ll)allc.size());
		ll final=allc.size();
		final-=ans;
		return final;
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
		cout << "Testing RemoveCharacters (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472443820;
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
		RemoveCharacters _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string A = "acabc";
				string B = "accabcc";
				_expected = 1;
				_received = _obj.minimalDistinct(A, B); break;
			}
			case 1:
			{
				string A = "aabbcc";
				string B = "ccbbaa";
				_expected = 2;
				_received = _obj.minimalDistinct(A, B); break;
			}
			case 2:
			{
				string A = "aaaabc";
				string B = "bcaaaaa";
				_expected = 1;
				_received = _obj.minimalDistinct(A, B); break;
			}
			case 3:
			{
				string A = "abcde";
				string B = "abcde";
				_expected = 0;
				_received = _obj.minimalDistinct(A, B); break;
			}
			case 4:
			{
				string A = "abcdefghijklm";
				string B = "nopqrstuvwxyz";
				_expected = 26;
				_received = _obj.minimalDistinct(A, B); break;
			}
			/*case 5:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.minimalDistinct(A, B); break;
			}*/
			/*case 6:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.minimalDistinct(A, B); break;
			}*/
			/*case 7:
			{
				string A = ;
				string B = ;
				_expected = ;
				_received = _obj.minimalDistinct(A, B); break;
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
