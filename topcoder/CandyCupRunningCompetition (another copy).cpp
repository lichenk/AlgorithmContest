#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL

#define MAXG 2008
#define INF 92233720368547758LL
#define NOPATH -1
#define UNDEF -1
ll path[MAXG];
bool seen[MAXG];
ll c[MAXG];
vector<pair<ll,ll> > g[MAXG];
ll ppow[MAXG];
pair<ll,ll> dbge[MAXG];
bool gte(ll z, ll p) {
	return c[z]>=ppow[p];
	/*for (ll i=p;i<MAXG;i++) {
		if (c[z][i]>0) return true;
	}
	return false;*/
}

void add(ll z, ll p) {
	c[z] += ppow[p];
	return;
	/*c[z][p]++;
	while(c[z][p]>=3) {
		c[z][p] %= 3;
		p++;
		assert(p<MAXG);
		c[z][p]++;
	}*/
}
void sub(ll z, ll p) {
	c[z] -= ppow[p];
	return;
	/*c[z][p]--;
	while(c[z][p]<0) {
		c[z][p] += 3;
		p++;
		assert(p<MAXG);
		c[z][p]--;
	}*/
}
ll getll(ll z) {
	return c[z];
	/*ll ans=0;
	for (ll i=MAXG-1;i>=0;i--) {
		ans *= 3;
		ans += c[z][i];
	}
	return ans;*/
}

pair<ll,ll> dfs(ll x, ll k, ll nv, ll p) {
	ll t = nv-1;
	seen[x] = true;
	if (x == t) {
		return MP(p,k);
	}
	for(auto &e: g[x]) {
		ll y = e.first;
		ll z = e.second;
		if (p==1) {
			printf("dfs: %lld to %lld with %lld\n",x,y,getll(z));
		}
		if (!seen[y] && gte(z,p)) {
			pair<ll,ll> cand = dfs(y, k+1, nv, p);
			if (cand.first != NOPATH) {
				path[k] = z;
				return MP(p, cand.second);
			}
		}
	}
	return MP(NOPATH,UNDEF);
}

ll maxflow(ll src, ll target, ll nv, ll n) {
	ll ans = 0;
	//printf("n:%lld\n",n);
	for (ll p=n-1;p>=0;p--) {
		ans = (ans * 3)%MOD;
		for (ll i = 0; i < nv; i++) {
			seen[i] = false;
		}
		pair<ll,ll> cap_len = dfs(src,0, nv, p);
		ll cap = cap_len.first;
		if (cap == NOPATH) continue;
		ll len = cap_len.second;
		ans=(ans+1)%MOD;
		printf("Found path for p:%lld. ",p);
		for (ll i = 0; i < len; i++) {
			ll z = path[i];
			printf("%lld ",dbge[z].second);
			sub(z,p);
			add(z^1,p);
		}
		printf("\n");
	}
	return ans;
}

class CandyCupRunningCompetition {
	public:
	int findMaximum(int N, vector <int> A, vector <int> B) {
		ppow[0]=1;
		for (ll i=1;i<MAXG;i++) {
			ppow[i] = (ppow[i-1]*3);
		}
		/*for (ll i=0;i<MAXG;i++) {
			for (ll j=0;j<MAXG;j++) {
				c[i][j]=0;
			}
		}*/
		ll z=0;
		for (ll i=0;i<A.size();i++) {
			ll x=A[i];
			ll y=B[i];
			//c[z][i] = 1;
			c[z]=ppow[i];
			c[z+1]=ppow[i];
			g[x].PB(MP(y,z));
			g[y].PB(MP(x,z+1));
			dbge[z]=MP(x,y);
			dbge[z+1]=MP(y,x);
			z += 2;
		}
		ll ans = maxflow(0, N-1, N, N);
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
		cout << "Testing CandyCupRunningCompetition (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455344051;
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
		CandyCupRunningCompetition _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int A[] = {0,1};
				int B[] = {1,2};
				_expected = 1;
				_received = _obj.findMaximum(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 4;
				int A[] = {0,1,0,2};
				int B[] = {1,3,2,3};
				_expected = 10;
				_received = _obj.findMaximum(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 3;
				int A[] = {0};
				int B[] = {1};
				_expected = 0;
				_received = _obj.findMaximum(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 5;
				int A[] = {};
				int B[] = {};
				_expected = 0;
				_received = _obj.findMaximum(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 6;
				int A[] = {1,1,2,0,4,3,0,1,4};
				int B[] = {3,2,3,1,5,5,2,4,3};
				_expected = 39;
				_received = _obj.findMaximum(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.findMaximum(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.findMaximum(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int A[] = ;
				int B[] = ;
				_expected = ;
				_received = _obj.findMaximum(N, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int))); break;
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
