#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<30LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef vector<ll> vll;
long long gk;
typedef array<int,3> a3;
ll dp[51][3][51][51][51];
const ll FAIL=123,SUCCESS=456;
ll f(ll disc, ll dest, a3 a) {
	for (ll i=0;i<3;i++) {
		if (a[i]<0) {
			return FAIL;
		}
	}
	if (a[0]+a[1]+a[2]==0) {
		return SUCCESS;
	}
	if (disc<0) return FAIL;
	ll dpval=dp[disc][dest][a[0]][a[1]][a[2]];
	if (dpval!=-1) return dpval;
	ll ans=FAIL;
	pair<int,a3> pte;
	if (gk&(1LL<<disc)) {
		for (ll putdelta=0;putdelta<=1;putdelta++) {
			ll put=(dest+1+putdelta)%3;
			ll ndest=(dest+1+(putdelta^1))%3;
			a3 na=a;
			na[put]--;
			auto got=f(disc-1,ndest,na);
			if (got!=FAIL) {
				pte=MP(ndest,na);
				ans=put;
				break;
			}
		}
	}
	else {
		a3 na=a;
		na[dest]--;
		auto got=f(disc-1,dest,na);
		if (got!=FAIL) {
			pte=MP(dest,na);
			ans=dest;
		}
	}
	return dp[disc][dest][a[0]][a[1]][a[2]]=ans;
}
pair<int,a3> g(ll disc, ll dest, a3 a) {
	ll ans=FAIL;
	pair<int,a3> pte;
	if (gk&(1LL<<disc)) {
		for (ll putdelta=0;putdelta<=1;putdelta++) {
			ll put=(dest+1+putdelta)%3;
			ll ndest=(dest+1+(putdelta^1))%3;
			a3 na=a;
			na[put]--;
			auto got=f(disc-1,ndest,na);
			if (got!=FAIL) {
				pte=MP(ndest,na);
				ans=put;
				break;
			}
		}
	}
	else {
		a3 na=a;
		na[dest]--;
		auto got=f(disc-1,dest,na);
		if (got!=FAIL) {
			pte=MP(dest,na);
			ans=dest;
		}
	}
	return pte;
}

class ClassicTowers {
	public:
	string findTowers(long long k, vector <int> count) {
		gk=k;
		memset(dp,-1,sizeof dp);
		ll disc=0;
		for (auto &w:count) disc+=w;
		if (k>(1LL<<(disc-1))-1) return "";
		for (ll dest=0;dest<3;dest++) {
			a3 a={count[0],count[1],count[2]};
			a[dest]--;
			auto get=f(disc-2,dest,a);
			if (get!=FAIL) {
				string s; s+=(char)('A'+dest);
				ll dst=dest;
				for (ll e=disc-2;e>=0;e--) {
					//printf("e:%d dst:%d a:%d %d %d\n",e,dst,a[0],a[1],a[2]);
					auto got=g(e,dst,a);
					s+=(char)('A'+dp[e][dst][a[0]][a[1]][a[2]]);
					dst=got.first;
					a=got.second;
				}
				reverse(s.begin(),s.end());
				return s;
			}
		}
		return "";
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
		cout << "Testing ClassicTowers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1496192919;
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
		ClassicTowers _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long k = 4LL;
				int count[] = {1,1,2};
				_expected = "CCAB";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 1:
			{
				long long k = 0LL;
				int count[] = {0, 0, 50};
				_expected = "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 2:
			{
				long long k = 0LL;
				int count[] = {10,20,20};
				_expected = "";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 3:
			{
				long long k = 123456123456123LL;
				int count[] = {10,10,30};
				_expected = "CCACCCACCABACCABBACCCBBCCBCCCBACCCCABBACCCCCACBCCC";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 4:
			{
				long long k = 314159265358979LL;
				int count[] = {15,16,17};
				_expected = "";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 5:
			{
				long long k = 1LL;
				int count[] = {0,1,2};
				_expected = "BCC";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 6:
			{
				long long k = 2LL;
				int count[] = {1,1,1};
				_expected = "ABC";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 7:
			{
				long long k = 3LL;
				int count[] = {0,1,2};
				_expected = "CCB";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 8:
			{
				long long k = 0LL;
				int count[] = {0,0,2};
				_expected = "CC";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 9:
			{
				long long k = 1LL;
				int count[] = {0,1,1};
				_expected = "BC";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
			case 10:
			{
				long long k = 0LL;
				int count[] = {0,1,0};
				_expected = "B";
				_received = _obj.findTowers(k, vector <int>(count, count+sizeof(count)/sizeof(int))); break;
			}
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
