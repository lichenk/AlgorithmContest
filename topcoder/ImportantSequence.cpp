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
ll getceil(ll a, ll b) {
	assert(a>=0&&b>0);
	return (a+b)/b;
}
ll getfloor(ll a, ll b) {
	assert(a>=0&&b>0);
	return (a-1)/b;
}
class ImportantSequence {
	public:
	int getCount(vector <int> B, string operators) {
		ll n=B.size();
		pair<ll,ll> p=MP(0ll,1ll);
		ll lo=1;
		ll hi=INF;
		bool ok=true;
		for (ll x=0;x<n;x++) {
			char op=operators[x];ll k=B[x];
			pair<ll,ll> q;
			q.first=k-p.first;
			q.second=-p.second;
			//printf("%lld %lld\n",q.second,-p.second);
			if (op=='-') {q.first=-q.first; q.second=-q.second;}
			//printf("%lld %lld\n",q.second,-p.second);
			ll a=q.first,b=q.second;
			if (b>0) {
				if (a<0) {
					a=abs(a);
					chkmax(lo,getceil(a,b));
				}
				// a>=0 is OK
			}
			else if (b<0) {
				b=abs(b);
				if (a<=0) {
					ok=false;
				}
				else {
					chkmin(hi,getfloor(a,b));
				}
			}
			else {
				// b==0
				if (a<=0) {
					ok=false;
				}
				// a>0 is OK
			}
			//printf("a:%lld b:%lld lo:%lld hi:%lld p:%lld %lld\n",q.first,q.second,lo,hi,p.first,p.second);
			p=q;
		}
		ll ans=hi-lo+1;
		if (!ok||ans<0) return 0;
		if (ans>=INF/2) return -1;
		else return ans;
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
		cout << "Testing ImportantSequence (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471444571;
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
		ImportantSequence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int B[] = {3, -1, 7};
				string operators = "+-+";
				_expected = 2;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 1:
			{
				int B[] = {1};
				string operators = "-";
				_expected = -1;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 2:
			{
				int B[] = {1};
				string operators = "+";
				_expected = 0;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 3:
			{
				int B[] = {10};
				string operators = "+";
				_expected = 9;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			case 4:
			{
				int B[] = {540, 2012, 540, 2012, 540, 2012, 540};
				string operators = "-+-+-+-";
				_expected = 1471;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}
			/*case 5:
			{
				int B[] = ;
				string operators = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}*/
			/*case 6:
			{
				int B[] = ;
				string operators = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
			}*/
			/*case 7:
			{
				int B[] = ;
				string operators = ;
				_expected = ;
				_received = _obj.getCount(vector <int>(B, B+sizeof(B)/sizeof(int)), operators); break;
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
