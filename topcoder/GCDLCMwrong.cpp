#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define foreach(v,c) for(vector<int>::iterator v=(c).begin(); v!=(c).end();++v)
#define rep(i,s,e) for (int i=(s);i<(e);++i)
#define clr(x,y) memset(x,y,sizeof x)
#define pb push_back
const ll MAXP = 31631;
bool a[MAXP+1];
vector<ll> pv;
set<ll> ps;
const ll MAXN = 204;
const ll UNDEF = -1;
unordered_map<ll,ll> factors[MAXN];
ll ppow[MAXN];
void sieve() {
	for (ll i = 0; i <= MAXP; i++) a[i] = true;
	a[0] = false; a[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(a[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				a[j] = false;
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if (a[i]) pv.PB(i);
	}
}

/* 2SAT bookcode */
const int maxn = 1600; // 2-sat: maxn = 2*maxvars
vector<int> adj[maxn], radj[maxn];
bool vis[maxn];
int col, color[maxn];
vector<int> bycol[maxn];
vector<int> st;

void init() { rep(i,0,maxn) adj[i].clear(), radj[i].clear(); }
void dfs(int u, vector<int> adj[]) {
  if (vis[u]) return;
  vis[u] = 1;
  foreach(it,adj[u]) dfs(*it, adj);
  if (col) {
    color[u] = col;
    bycol[col].pb(u);
  } else st.pb(u);
}
// this computes SCCs, outputs them in bycol, in topological order
void kosaraju(int n) { // n = number of nodes
  st.clear();
  clr(vis,0);
  col=0;
  rep(i,0,n) dfs(i,adj);
  clr(vis,0);
  clr(color,0);
  while(!st.empty()) {
    bycol[++col].clear();
    int x = st.back(); st.pop_back();
    if(color[x]) continue;
    dfs(x, radj);
  }
}
// 2-SAT
int assign[maxn]; // for 2-sat only
int var(int x) { return x<<1; }
bool solvable(int vars) {
  kosaraju(2*vars);
  rep(i,0,vars) if (color[var(i)] == color[1^var(i)]) return 0;
  return 1;
}
void assign_vars() {
  clr(assign,0);
  rep(c,1,col+1) {
    foreach(it,bycol[c]) {
      int v = *it >> 1;
      bool neg = *it&1;
      if (assign[v]) continue;
      assign[v] = neg?1:-1;
    }
  }
}
void add_impl(int v1, int v2) {
	assert(v1!=v2);
	//printf("%d implies %d\n",v1,v2);
	adj[v1].push_back(v2); radj[v2].push_back(v1);
}
void add_equiv(int v1, int v2) { add_impl(v1, v2); add_impl(v2, v1); }
void add_or(int v1, int v2) { add_impl(1^v1, v2); add_impl(1^v2, v1); }
void add_xor(int v1, int v2) { add_or(v1, v2); add_or(1^v1, 1^v2); }
void add_true(int v1) { add_impl(1^v1, v1); }
void add_and(int v1, int v2) { add_true(v1); add_true(v2); }




class GCDLCM {
	public:
	string possible(int nn, string type, vector <int> A, vector <int> B, vector <int> C) {
		sieve();
		for (ll i=0;i<C.size();i++) {
			ll x=C[i];
			for (auto &p: pv) {
				ll m=0;
				while(x%p==0) {
					x/=p;
					m++;
				}
				if (m>0) {
					factors[i][p]=m;
					ps.insert(p);
				}
			}
			if (x>1) {
				factors[i][x]=1;
				ps.insert(x);
			}
		}
		ll m=A.size();
		set<ll> vpow[MAXN];
		map<ll,ll> getvarnum[MAXN];
		map<ll,pair<ll,ll> > numvartopow;
		for (auto &p:ps) {
			init(); // Reset 2SAT
			for (ll x=0;x<nn;x++) {
				vpow[x].clear();
			}
			for (ll i=0;i<m;i++){
				ppow[i]=factors[i][p];
				ll x=A[i]; ll y=B[i];
				vpow[x].insert(ppow[i]);
				vpow[y].insert(ppow[i]);
			}
			ll numvar=0;
			for (ll x=0;x<nn;x++) {
				ll startvar = numvar;
				for (auto &pp:vpow[x]) {
					getvarnum[x][pp] = numvar;
					numvartopow[numvar] = MP(x,pp);
					//printf("x:%d pp:%d numvar:%d\n",x,pp,numvar);
					numvar+=2;
				}
				ll endvar = numvar-2;
				//printf("%lld to %lld\n",startvar,endvar);
				for (ll vara=startvar;vara<=endvar;vara+=2) {
					for (ll varb=startvar;varb<=endvar;varb+=2) {
						if (vara==varb) continue;
						assert(vara%2==0);
						// If one power is chosen, then any other power is not allowed
						add_impl(vara,varb^1);
					}
				}
			}
			for (ll i=0;i<m;i++) {
				ll pp=ppow[i];
				ll x=A[i]; ll y=B[i];
				ll varx = getvarnum[x][pp];
				ll vary = getvarnum[y][pp];
				// Not x implies y
				add_impl(varx^1,vary);
				// Not y implies x
				add_impl(vary^1,varx);
				bool sign = (type[i]=='G');
				{
					// If x is chosen to be pp, then all powers above pp are not allowed on y
					for (auto &w: getvarnum[y]) {
						ll qq = w.first; ll var = w.second;
						if ((qq>pp)!=sign) add_impl(varx,var^1);
					}
					for (auto &w: getvarnum[x]) {
						ll qq = w.first; ll var = w.second;
						if ((qq>pp)!=sign) add_impl(vary,var^1);
					}
				}
			}
			// Run 2SAT
			assert(numvar<maxn);
			if (!solvable(numvar)) {
				//printf("prime:%lld\n",p);
				return "Solution does not exist";
			}
		}
		return "Solution exists";
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
		cout << "Testing GCDLCM (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455257291;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GCDLCM _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				string type = "GLGLGLGL";
				int A[] = {0,0,1,1,2,2,3,3};
				int B[] = {1,1,2,2,3,3,0,0};
				int C[] = {6,12,6,12,6,12,6,12};
				_expected = "Solution exists";
				_received = _obj.possible(n, type, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 5;
				string type = "GLGLGLGLGL";
				int A[] = {0,0,1,1,2,2,3,3,4,4};
				int B[] = {1,1,2,2,3,3,4,4,0,0};
				int C[] = {6,12,6,12,6,12,6,12,6,12};
				_expected = "Solution does not exist";
				_received = _obj.possible(n, type, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 11;
				string type = "GGGGGGGGGG";
				int A[] = {0,0,0,0,0,0,0,0,0,0};
				int B[] = {1,2,3,4,5,6,7,8,9,10};
				int C[] = {2,3,5,7,11,13,17,19,23,29};
				_expected = "Solution exists";
				_received = _obj.possible(n, type, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 12;
				string type = "GLLGGGLGLLGL";
				int A[] = {0,1,2,3,4,5,6,7,8,9,10,11};
				int B[] = {1,2,3,4,5,6,7,8,9,10,11,0};
				int C[] = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000};
				_expected = "Solution exists";
				_received = _obj.possible(n, type, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 12;
				string type = "GLLGGGLGLLGL";
				int A[] = {0,1,2,3,4,5,6,7,8,9,10,11};
				int B[] = {1,2,3,4,5,6,7,8,9,10,11,0};
				int C[] = {1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,1000000000,999999999};
				_expected = "Solution does not exist";
				_received = _obj.possible(n, type, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 200;
				string type = "G";
				int A[] = {11};
				int B[] = {20};
				int C[] = {19911120};
				_expected = "Solution exists";
				_received = _obj.possible(n, type, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 79;
				string type = "GGGGLGGGGLGGGGGLGLGGGGGGLGGGGGGGGLLLGLGGGGGGGGGGGGGLLLGGGLGGLLGGLGGLGLGGLGGGGLGLLLGGGGGGGGLGGLGGLLGGLGGGGGGGGGGLLG";
				int A[] = {2, 34, 11, 22, 36, 65, 73, 70, 14, 51, 12, 16, 54, 71, 73, 27, 72, 36, 69, 36, 55, 44, 62, 53, 28, 1, 76, 40, 19, 48, 74, 2, 38, 10, 72, 12, 20, 45, 61, 22, 48, 2, 38, 57, 78, 17, 15, 25, 3, 45, 5, 36, 37, 21, 54, 33, 6, 13, 77, 34, 24, 9, 55, 1, 62, 33, 23, 24, 26, 10, 71, 26, 11, 12, 4, 4, 27, 58, 22, 34, 69, 47, 30, 43, 57, 24, 6, 44, 13, 0, 73, 77, 72, 36, 51, 9, 30, 54, 69, 78, 22, 28, 62, 18, 10, 67, 64, 47, 9, 35, 39, 71, 7, 37};
				int B[] = {11, 59, 26, 24, 28, 16, 8, 73, 3, 66, 14, 51, 0, 50, 12, 25, 24, 3, 2, 61, 7, 27, 24, 15, 17, 56, 40, 24, 10, 69, 23, 57, 65, 37, 55, 49, 41, 58, 2, 5, 74, 21, 50, 72, 2, 46, 36, 78, 74, 75, 65, 59, 27, 59, 11, 52, 32, 68, 55, 2, 18, 55, 43, 57, 46, 5, 7, 26, 45, 39, 5, 22, 25, 10, 51, 42, 78, 28, 58, 6, 51, 1, 37, 18, 34, 43, 0, 12, 5, 37, 75, 9, 23, 25, 67, 77, 71, 14, 36, 68, 15, 15, 26, 71, 52, 17, 25, 4, 33, 15, 53, 26, 25, 30};
				int C[] = {1, 1, 3, 1, 31651074, 4, 1, 1, 1, 23012220, 1, 1, 1, 1, 1, 24438920, 1, 298606014, 1, 6, 1, 1, 1, 1, 558275822, 1, 1, 1, 1, 3, 2, 1, 1, 252830085, 443642591, 14745614, 1, 338712696, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 65779938, 755542920, 43841080, 3, 2, 1, 15631153, 1, 1, 87357331, 357704327, 1, 1, 62370742, 1, 2, 105006420, 1, 11423670, 1, 5, 659055, 1, 1, 1, 8, 327563496, 1, 134459985, 12952065, 361897088, 1, 1, 1, 1, 1, 1, 1, 1, 34325223, 1, 1, 89308170, 1, 1, 431600985, 813085875, 3, 1, 27907085, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 20755260, 80263780, 1};
				_expected = "Solution exists";
				_received = _obj.possible(n, type, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 7:
			{
				int n = 2;
				string type = "G";
				int A[] = {0};
				int B[] = {1};
				int C[] = {2};
				_expected = "Solution exists";
				_received = _obj.possible(n, type, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			/*case 8:
			{
				int n = ;
				string type = ;
				int A[] = ;
				int B[] = ;
				int C[] = ;
				_expected = ;
				_received = _obj.possible(n, type, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
