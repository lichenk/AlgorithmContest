#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 2508
vector<ll> graph[MAXN];
ll v[MAXN];
ll dfs(ll x, ll p) {
	ll ans = v[x];
	for (auto& y: graph[x]) {
		if(y==p) continue;
		ans += dfs(y, x);
	}
	//printf("%lld %lld: %lld. %lld\n",x,p,ans,v[x]);
	ans = max(0LL,ans);
	return ans;
}

class FiringEmployees {
	public:
	int fire(vector <int> manager, vector <int> salary, vector <int> productivity) {
		ll n = manager.size();
		v[0] = 0;
		for (ll x = 1; x <= n; x++) {
			v[x] = productivity[x-1] - salary[x-1];
			graph[manager[x-1]].PB(x);
		}
		ll final = dfs(0,-1);
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
		cout << "Testing FiringEmployees (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453309416;
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
		FiringEmployees _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int manager[] = {0,0,0};
				int salary[] = {1,2,3};
				int productivity[] = {3,2,1};
				_expected = 2;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}
			case 1:
			{
				int manager[] = {0,1,2,3};
				int salary[] = {4,3,2,1};
				int productivity[] = {2,3,4,5};
				_expected = 4;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}
			case 2:
			{
				int manager[] = {0,1};
				int salary[] = {1,10};
				int productivity[] = {5,5};
				_expected = 4;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}
			case 3:
			{
				int manager[] = {0,1,2,1,2,3,4,2,3};
				int salary[] = {5,3,6,8,4,2,4,6,7};
				int productivity[] = {2,5,7,8,5,3,5,7,9};
				_expected = 6;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}
			case 4:
			{
				int manager[] = {0,0,1,1,2,2};
				int salary[] = {1,1,1,2,2,2};
				int productivity[] = {2,2,2,1,1,1};
				_expected = 3;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}
			/*case 5:
			{
				int manager[] = ;
				int salary[] = ;
				int productivity[] = ;
				_expected = ;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int manager[] = ;
				int salary[] = ;
				int productivity[] = ;
				_expected = ;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int manager[] = ;
				int salary[] = ;
				int productivity[] = ;
				_expected = ;
				_received = _obj.fire(vector <int>(manager, manager+sizeof(manager)/sizeof(int)), vector <int>(salary, salary+sizeof(salary)/sizeof(int)), vector <int>(productivity, productivity+sizeof(productivity)/sizeof(int))); break;
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
