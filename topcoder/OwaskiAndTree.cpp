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
const ll mn=1004;
vector<ll> g[mn];
vector<int> vp;
ll a[mn];
void ae(ll x, ll y) {
	g[x].PB(y);
	g[y].PB(x);
}

void dfs1(ll x, ll p, ll val) {
	a[x]=max(0ll, val+vp[x])-val;
	val+=vp[x];
	chkmax(val,0ll);
	for (auto &y:g[x]) {
		if (y==p) continue;
		dfs1(y,x,val);
	}
}
bool use[mn];
ll dfs2(ll x, ll p) {
	ll ans=a[x];
	for (auto &y:g[x]) {
		if (y==p) continue;
		ans+=dfs2(y,x);
	}
	if (ans>=0) {
		use[x]=true;
	}
	chkmax(ans,0ll);
	return ans;
}
void dfs3(ll x, ll p) {
	if (!use[x]) return;
	vp[x]=0;
	for (auto &y:g[x]) {
		if (y==p) continue;
		dfs3(y,x);
	}
}
#define repeat(i,n) for (int i=0; (i)<(n); ++(i))
const int root=0;
class OwaskiAndTree {
	public:
	int maximalScore(vector <int> parent, vector <int> pleasure) {
		int n=pleasure.size();
		vector<vector<int> > children(n);
		repeat(i,n-1) {
			children[parent[i]].PB(i+1);
		}
		vector<ll> acc(n); {
			function<void(int)> go=[&](int i) {
				acc[i]+=pleasure[i];
				for (int j:children[i]) {
					go(j);
					if (acc[j]>0) {
						acc[i]+=acc[j];
					}
				}
			};
			go(root);
		}
		vector<ll> dp(n); {
			function<void(int)> go = [&](int i) {
				for (int j:children[i]) {
					go(j);
					dp[i]+=dp[j];
				}
				chkmax(dp[i],acc[i]);
				chkmax(dp[i],0ll);
			};
			go(root);
		}
		return dp[root];
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
		cout << "Testing OwaskiAndTree (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1502759642;
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
		OwaskiAndTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
				int pleasure[] = {1, 1, -1, -1, -1, -1, 1, 1, 1, 1};
				_expected = 4;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {0, 0, 1, 2};
				int pleasure[] = {2, 3, 4, -1, -1};
				_expected = 9;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {0, 0, 1, 1, 2, 2, 5, 5};
				int pleasure[] = {1, 2, -3, -7, 3, 2, 7, -1, 3};
				_expected = 17;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {0, 1, 1, 1, 0, 3, 1, 3, 4, 4, 3, 6, 8, 0, 12, 12, 11, 7, 7};
				int pleasure[] = {-154011, 249645, 387572, 292156, -798388, 560085, -261135, -812756, 191481, -165204, 81513, -448791, 608073, 354614, -455750, 325999, 227225, -696501, 904692, -297238};
				_expected = 3672275;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			/*case 4:
			{
				int parent[] = {};
				int pleasure[] = {-1};
				_expected = 0;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}*/
			case 5:
			{
				int parent[] = {0};
				int pleasure[] = {-1,2};
				_expected = 2;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 6:
			{
				int parent[] = {0};
				int pleasure[] = {2,-2};
				_expected = 2;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 7:
			{
				int parent[] = {0,0};
				int pleasure[] = {-3,1,2};
				_expected = 3;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
			}
			case 8:
			{
				int n=1000;
				vector<int> parent;
				for (int i=1;i<n;i++) parent.PB(0);
				vector<int> pleasure;
				for (int i=0;i<n;i++) pleasure.PB(1000*1000);
				_expected = 1000*1000*1000;
				_received = _obj.maximalScore(parent,pleasure); break;
			}
			case 9:
			{
				srand(1);
				int n=1000;
				vector<int> parent;
				for (int i=1;i<n;i++) parent.PB(rand()%i);
				vector<int> pleasure;
				for (int i=0;i<n;i++) pleasure.PB((rand()%(2*1000*1000))-1000*1000);
				_expected = 0;
				_received = _obj.maximalScore(parent,pleasure);
				break;
			}
			case 10:
			{
				srand(1);
				int n=10;
				vector<int> parent;
				for (int i=1;i<n;i++) parent.PB(rand()%i);
				vector<int> pleasure;
				for (int i=0;i<n;i++) pleasure.PB((rand()%(2*1000*1000))-1000*1000);
				_expected = 0;
				_received = _obj.maximalScore(parent,pleasure);
				break;
			}
			case 11:
			{
				int parent[] = {0,0,1,2};
				int pleasure[] = {10,-7,-7,6,6};
				_expected = 12;
				_received = _obj.maximalScore(vector <int>(parent, parent+sizeof(parent)/sizeof(int)), vector <int>(pleasure, pleasure+sizeof(pleasure)/sizeof(int))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
