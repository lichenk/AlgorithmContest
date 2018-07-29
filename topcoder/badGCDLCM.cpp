#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll MAXP = 31631;
bool a[MAXP+1];
vector<ll> pv;
set<ll> ps;
const ll MAXN = 204;
const ll UNDEF = -1;
bool fseen[MAXN],seen[MAXN];
unordered_map<ll,ll> factors[MAXN];
vector<pair<ll,ll> > g[MAXN];
ll d[MAXN],ppow[MAXN],fd[MAXN];
string gtype;
ll gprime;
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
ll gn;
void freset() {
	ll n=gn;
	for (ll x=0;x<n;x++) {
		fseen[x]=false;
		fd[x]=UNDEF;
	}
}
void reset() {
	ll n=gn;
	for (ll x=0;x<n;x++) {
		seen[x]=fseen[x];
		d[x]=fd[x];
	}
}
void commit() {
	for (ll x=0;x<gn;x++) {
		fseen[x]=seen[x];
		fd[x]=d[x];
	}
}


bool dfs(ll x) {
	if (d[x]==UNDEF) return true;
	seen[x]=true;
	ll lo = -1;
	ll hi = 0x7fffffff;
	for (auto &edge: g[x]) {
		ll i=edge.second;
		//if (ppow[i]==0&&gtype[i]=='L') ////printf("%lld %lld: %c\n",x,edge.first,gtype[i]);
		if (gtype[i] == 'G') {
			lo=max(lo,ppow[i]);
		}
		else if (gtype[i]=='L') {
			hi=min(hi,ppow[i]);
		}
		else {
			////printf("Invalid gtype: %c\n",gtype[i]);
			assert(false);
		}
	}
	if (d[x] != UNDEF) {
		if (!(lo <= d[x] && d[x] <= hi)) {
			//printf("FALSE: %lld %lld %lld %lld\n",x,d[x],lo,hi);
			return false;
		}
	}
	bool ok=true;
	for (auto &edge: g[x]) {
		ll y=edge.first;
		ll ei=edge.second;
		ll t=gtype[ei];
		ll pp = ppow[ei];
		if (seen[y]) continue;
		if (d[x] == pp) {
			// OK
		}
		else if (d[x]==UNDEF && lo<=pp&&pp<=hi) {
			d[x] = pp;
		}
		else {
			d[y] = pp;
		}
		bool cand=dfs(y);
		ok=ok&&cand;
	}
	return ok;
}

ll go(ll x) {
	ll n=gn;
	if (fd[x] != UNDEF) return x;
	if (g[x].size()==0) {
		fseen[x]=true;
		fd[x]=0;
		return x;
	}
	ll y=-1;
	ll ei=-1;
	for (auto &ed: g[x]) {
		if (fd[ed.first]==UNDEF) {
			y=ed.first;
			ei=ed.second;
			break;
		}
	}
	
	if (fd[x]==UNDEF) {
		reset();
		d[x]=ppow[ei];
		////printf("Go:%lld %lld\n",x,d[x]);
		bool ok = dfs(x);
		if (ok) {
			assert(d[x]!=UNDEF);
			commit();
			return x;
		}
	}
	printf("x:%lld gprime:%lld\n",x,gprime);
	if (y!=-1) {
		reset();
		d[y]=ppow[ei];
		printf("Go:%lld %lld\n",y,d[y]);
		bool ok=dfs(y);
		if(ok) {
			assert(d[y]!=UNDEF);
			commit();
			return y;
		}
	}
	printf("x:%lld gprime:%lld\n",x,gprime);
	for (ll i=0;i<n;i++) {
		if (!fseen[i] && seen[i]) {
			printf("%lld %lld: ",i,g[i].size());
			for (auto edge:g[i]) {
				ll y=edge.first;
				ll ei=edge.second;
				if (!fseen[y]&&seen[y]) {
					printf("y:%lld t:%c pp:%lld, ",y,gtype[ei],ppow[ei]);
				}
			}
			printf("\n");
		}
	}
	assert(false);
	commit();
	return -1;
}

class GCDLCM {
	public:
	string possible(int nn, string type, vector <int> A, vector <int> B, vector <int> C) {
		sieve();
		gn=nn;
		gtype=type;
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
				////printf("large prime: %lld\n",x);
				ps.insert(x);
			}
		}
		for (ll i=0;i<A.size();i++) {
			ll x=A[i];
			ll y=B[i];
			g[x].PB(MP(y,i));
			g[y].PB(MP(x,i));
		}
		bool ans=true;
		for (auto &p:ps) {
			gprime=p;
			for (ll x=0;x<A.size();x++) {
				ppow[x]=factors[x][p];
			}
			freset();
			set<ll> S;
			for (ll x=0;x<A.size();x++) {
				S.insert(x);
			}
			while (!S.empty()) {
				ll x=*(S.begin());
				ll y = go(x);
				printf("x:%lld y:%lld\n",x,y);
				if (y==-1) {
					ans=false;
					break;
				}
				assert(fd[y]!=UNDEF);
				S.erase(y);
			}
			if (ans) {
				for (ll x=0;x<A.size();x++) {
					ll lo=-1;
					ll hi=0x7fffffff;
					for (auto &edge: g[x]) {
						ll i=edge.second;
						ll pp=ppow[i];
						ll y=edge.first;
						char t = gtype[i];
						//printf("%lld %c %lld. %lld %lld. %lld %lld\n",p,t,pp,x,y,fd[x],fd[y]);
						assert(fd[x]!=UNDEF&&fd[y]!=UNDEF);
						if (!(fd[x]==pp||fd[y]==pp)) ans=false;
						if (t=='G'&&!(fd[x]>=pp&&fd[y]>=pp)) ans=false;
						if (t=='L'&&!(fd[x]<=pp&&fd[y]<=pp)) ans=false;
					}
				}
			}
		}
		if (ans) {
			return "Solution exists";
		}
		else {
			return "Solution does not exist";
		}
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
			/*case 7:
			{
				int n = ;
				string type = ;
				int A[] = ;
				int B[] = ;
				int C[] = ;
				_expected = ;
				_received = _obj.possible(n, type, vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}*/
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
