#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll MAXN = 54;
ll gn;
vector<ll> g[MAXN];
bool take[MAXN];
bool newtake[MAXN];
bool seen[MAXN];
bool dfs(ll x, ll p, ll left) {
	//printf(",%lld(%lld)",x,left);
	if (left<0) return false;
	if (!take[x]) {
		//printf("...%lld\n",x);
		return true;
	}
	if (left>0) {
		for (auto &w: g[x]) {
			if (w==p) continue;
			if (dfs(w,x,left-1)) return true;
		}
	}
	return false;
}

class Treestrat {
	public:
	int roundcnt(vector <int> tree, vector <int> A, vector <int> B) {
		ll n=tree.size()+1;
		gn=n;
		for (ll i=1;i<=n-1;i++) {
			ll x=i; ll y=tree[i-1];
			g[x].PB(y);
			g[y].PB(x);
		}
		for (ll i=0;i<n;i++) {
			take[i]=false;
		}
		for (auto &b:B) {
			take[b]=true;
			////printf("take: %lld\n",b);
		}
		for (ll rnd=0;;rnd++) {
			//printf("Round %lld\n",rnd);
			for (ll x=0;x<n;x++) newtake[x]=false;
			for (ll x=0;x<n;x++) {
				if (take[x]) {
					newtake[x]=true;
					for (auto &w:g[x]) {
						newtake[w]=true;
					}
				}
			}
			for (ll x=0;x<n;x++) {
				take[x]=newtake[x];
			}
			for (auto &a: A) {
				//printf("Dfs a:%lld ",a);
				bool ok=dfs(a,-1,rnd+1);
				if (!ok) return rnd+1;
			}
		}
		assert(false);
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
		cout << "Testing Treestrat (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455558843;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Treestrat _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int tree[] = {0};
				int A[] = {0};
				int B[] = {1};
				_expected = 1;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 1:
			{
				int tree[] = {0,1};
				int A[] = {1};
				int B[] = {2};
				_expected = 2;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 2:
			{
				int tree[] = {0,0,0,3,4};
				int A[] = {2};
				int B[] = {1};
				_expected = 2;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 3:
			{
				int tree[] = {0,0,0,3,4,2};
				int A[] = {1};
				int B[] = {6};
				_expected = 5;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 4:
			{
				int tree[] = {0,0,0,3,4,2};
				int A[] = {1};
				int B[] = {6,5};
				_expected = 3;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 5:
			{
				int tree[] = {0,0,0,3,4,2};
				int A[] = {4,1};
				int B[] = {3,6};
				_expected = 2;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			/*case 6:
			{
				int tree[] = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int tree[] = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int tree[] = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.roundcnt(vector <int>(tree, tree+sizeof(tree)/sizeof(int)), vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
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
