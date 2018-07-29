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
ll n,m,k,l;
bool can(ll m) {
		for (ll s=0;s<=n-k;s++) {
			ll d=m-s;
			if (0<=d&&d<k) {
				ll x=s+(k-1-d);
				//printf("canx:%lld",x);
				if (x==l) return true;
			}
		}
		return false;
}
class StonesGame {
	public:
	string winner(int N, int M, int K, int L) {
		M--; L--;
		n=N,m=M,k=K,l=L;
		for (ll s=0;s<=n-k;s++) {
			ll d=m-s;
			if (0<=d&&d<k) {
				ll x=s+(k-1-d);
				//printf("s:%lld k:%lld m:%lld x:%lld\n",s,k,m,x);
				if (x==l) return "Romeo";
			}
		}
		if (l<m) {
			l=n-1-l;
			m=n-1-m;
		}
		vector<ll> v;
		for (ll s=0;s<=n-k;s++) {
			ll d=m-s;
			if (0<=d&&d<k) {
				ll x=s+(k-1-d);
				v.PB(x);
			}
		}
		//ll k=min(5,v.size());
		if(v.size()>0){
			if (!can(v[0])) return "Draw";
			if (!can(v[v.size()-1])) return "Draw";
		}
		return "Strangelet";
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
		cout << "Testing StonesGame (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484533707;
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
		StonesGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int M = 1;
				int K = 1;
				int L = 2;
				_expected = "Draw";
				_received = _obj.winner(N, M, K, L); break;
			}
			case 1:
			{
				int N = 5;
				int M = 1;
				int K = 2;
				int L = 2;
				_expected = "Romeo";
				_received = _obj.winner(N, M, K, L); break;
			}
			case 2:
			{
				int N = 5;
				int M = 5;
				int K = 2;
				int L = 3;
				_expected = "Strangelet";
				_received = _obj.winner(N, M, K, L); break;
			}
			case 3:
			{
				int N = 5;
				int M = 5;
				int K = 2;
				int L = 2;
				_expected = "Draw";
				_received = _obj.winner(N, M, K, L); break;
			}
			case 4:
			{
				int N = 1000000;
				int M = 804588;
				int K = 705444;
				int L = 292263;
				_expected = "Romeo";
				_received = _obj.winner(N, M, K, L); break;
			}
			case 5:
			{
				int N = 1000000;
				int M = 100000;
				int K = 500000;
				int L = 600000;
				_expected = "Strangelet";
				_received = _obj.winner(N, M, K, L); break;
			}
			case 6:
			{
				int N = 2;
				int M = 1;
				int K = 2;
				int L = 2;
				_expected = "Romeo";
				_received = _obj.winner(N, M, K, L); break;
			}
			case 7:
			{
				int N = 3;
				int M = 1;
				int K = 1;
				int L = 3;
				_expected = "Draw";
				_received = _obj.winner(N, M, K, L); break;
			}
			case 8:
			{
				int N = 6;
				int M = 2;
				int K = 4;
				int L = 6;
				_expected = "Draw";
				_received = _obj.winner(N, M, K, L); break;
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
