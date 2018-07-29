#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll INF = 1ULL<<30ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=53;
ll f[MAXN][3*MAXN];
ll choose[MAXN][MAXN];
void init() {
	for (ll i=0;i<MAXN;i++) {
		for (ll j=0;j<=i;j++) {
			if (j==0||j==i) choose[i][j]=1;
			else choose[i][j]=choose[i-1][j-1]+choose[i-1][j];
		}
		for (ll j=i+1;j<MAXN;j++) {
			choose[i][j]=0;
		}
	}
}
ll binom(ll n,ll k) {
	if (n<k) return 0;
	if (n<0||k<0) return 0;
	return choose[n][k];
}

class Excavations {
	public:
	long long count(vector <int> kind, vector <int> depth, vector <int> _found, int K) {
		init();
		unordered_set<ll> found;
		for (auto &w: _found) {
			found.insert(w);
		}
		ll final=0;
		ll n=kind.size();
		map<ll,ll> zh;
		for (ll c=0;c<n;c++) {
			ll dc=depth[c];
			ll kc=kind[c];
			if (found.find(kc)==found.end()) zh[dc]++;
		}
		zh[INF]=0;
		for (auto &w:zh) {
			ll dz=w.first; ll nz=w.second;
			map<ll,ll> oh;
			ll left=-nz;
			for (ll c=0;c<n;c++) {
				ll dc=depth[c];
				ll kc=kind[c];
				if (found.find(kc)!=found.end()&&dc<dz) {
					oh[kc]++;
				}
				if (dc>=dz) left++;
			}
			if (oh.size() < found.size()) continue;
			for (ll x=0;x<MAXN;x++) {
				for (ll y=0;y<MAXN;y++) {
					f[x][y]=0;
				}
			}
			for (ll y=1;y<=nz;y++) {
				f[0][y]=binom(nz,y);
			}
			if (dz==INF) f[0][0]=1;
			for (ll y=0;y<MAXN;y++) {
				for (ll a=0;a<=left;a++) {
					f[1][y+a]+=(binom(left,a)*f[0][y]);
				}
			}
			auto it=oh.begin();
			for (ll x=1;x<1+oh.size();x++) {
				ll no=it->second;
				for (ll y=0;y<=K;y++) {
					//ll lim=min(no,K-y);
					ll lim=no;
					for (ll a=1;a<=lim;a++) {
						if (y+a>K) break;
						f[x+1][y+a]+=(binom(no,a)*f[x][y]);
					}
				}
				++it;
			}
			{
				ll x=1+oh.size();
				//if (f[x][K]>0) printf("%d %d %d\n",dz,nz,f[x][K]);
				final=(final+f[x][K]);
			}
		}
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
		cout << "Testing Excavations (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458662581;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Excavations _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int kind[] = {1, 1, 2, 2};
				int depth[] = {10, 15, 10, 20};
				int found[] = {1};
				int K = 2;
				_expected = 3LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 1:
			{
				int kind[] = {1, 1, 2, 2};
				int depth[] = {10, 15, 10, 20};
				int found[] = {1, 2};
				int K = 2;
				_expected = 4LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 2:
			{
				int kind[] = {1, 2, 3, 4};
				int depth[] = {10, 10, 10, 10};
				int found[] = {1, 2};
				int K = 3;
				_expected = 0LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 3:
			{
				int kind[] = {1, 2, 2, 3, 1, 3, 2, 1, 2};
				int depth[] = {12512, 12859, 125, 1000, 99, 114, 125, 125, 114};
				int found[] = {1, 2, 3};
				int K = 7;
				_expected = 35LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 4:
			{
				int kind[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
				int depth[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3};
				int found[] = {50};
				int K = 18;
				_expected = 9075135300LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 5:
			{
				int kind[] = {1};
				int depth[] = {10};
				int found[] = {1};
				int K = 1;
				_expected = 1LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 6:
			{
				int kind[] = {1,2};
				int depth[] = {10,20};
				int found[] = {1};
				int K = 1;
				_expected = 1LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 7:
			{
				int kind[] = {1,1};
				int depth[] = {10,20};
				int found[] = {1};
				int K = 1;
				_expected = 2LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 8:
			{
				int kind[] = {1,1};
				int depth[] = {10,20};
				int found[] = {1};
				int K = 2;
				_expected = 1LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 9:
			{
				int kind[] = {1, 1, 2};
				int depth[] = {10, 15, 20};
				int found[] = {1};
				int K = 2;
				_expected = 3LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 10:
			{
				int kind[] = {1, 1, 2};
				int depth[] = {10, 15, 10};
				int found[] = {1};
				int K = 2;
				_expected = 1LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			case 11:
			{
				int kind[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
				int depth[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
				int found[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
				int K = 50;
				_expected = 1LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
			}
			/*case 7:
			{
				int kind[] = ;
				int depth[] = ;
				int found[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.count(vector <int>(kind, kind+sizeof(kind)/sizeof(int)), vector <int>(depth, depth+sizeof(depth)/sizeof(int)), vector <int>(found, found+sizeof(found)/sizeof(int)), K); break;
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
