#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll INF = 1LL<<62LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const int mb=61;
const int mn=52;
//const int mb=2;
//const int mn=2;
bitset<mb> vor[mn];
bitset<mb> vsum[mn];

int enc(int var, int b) {
	return var*mb+b;
}

int ggvar;

void pr(int x) {
	if (x>=ggvar) {printf("~"); x-=ggvar;}
	printf("(%d[%d])",x/mb,x%mb);
}

struct TwoSat
{
	int n;
	int var;
	vector<vector<int>> graph;
	vector<vector<int>> grev;

	int vcnt;
	vector<int> v;

	void init(int var_) {
		var = var_;
		n = var_*2;
		//ggvar=var;
		graph.clear(); graph.resize(n);
		grev.clear(); grev.resize(n);

		vcnt = 0;
		v.clear(); v.resize(n);
	}

	int neg(int nod) {
		return nod >= var ? nod - var : nod + var;
	}

	// p implies q. p -> q
	void add(int p, int q, bool dbgpr=true) {
		//if (dbgpr) {pr(p); printf(" -> "); pr(q); printf("\n");}
		graph[p].push_back(q);
		graph[neg(q)].push_back(neg(p));
		grev[q].push_back(p);
		grev[neg(p)].push_back(neg(q));
	}

	void forceTrue(int p) {
		//pr(p); printf(" = true\n");
		add(neg(p),p,false);
	}

	void forceFalse(int p) {
		//pr(p); printf(" = false\n");
		add(p,neg(p),false);
	}

	// and (p or q)
	void addCNF(int p, int q) {
		add(neg(p), q);
	}

	vector<int> emit;
	void dfs(int nod, vector<vector<int>> &graph) {
		v[nod] = vcnt;
		for(int next : graph[nod]){
			if (v[next] == vcnt) continue;
			dfs(next, graph);
		}
		emit.push_back(nod);
	}

	vector<bool> solve() {
		vector<bool> solution(var);
		vector<int> scc_check(n);
		int scc_index = 0;

		++vcnt;
		emit.clear();
		for(int i = 0; i < n; i++) {
			if (v[i] == vcnt) continue;
			dfs(i, graph);
		}

		++vcnt;
		for(auto start : vector<int>(emit.rbegin(),emit.rend())) {
			if (v[start] == vcnt) continue;
			emit.clear();
			dfs(start, grev);
			++scc_index;
			for(auto node : emit) {
				scc_check[node] = scc_index;
				if (scc_check[neg(node)] == scc_index) {
					// contradiction found
					solution.clear();
					return solution;
				}
				solution[node >= var ? node-var : node] = (node < var);
			}
		}

		return solution;
	}
};


bitset<mb+1> vinCarry[mn];
class OrAndSum {
	public:
	string isPossible(vector<long long> inpvor, vector<long long> inpvsum) {
		int n=inpvor.size();
		for (int p=0;p<n;p++) {
			for (int b=0;b<mb;b++) {
				ll msk=1LL<<b;
				vor[p][b]=(inpvor[p]&msk)?1:0;
				vsum[p][b]=(inpvsum[p]&msk)?1:0;
			}
		}
		TwoSat ts;
		ts.init(enc(n,mb));
		//printf("lim:%d\n",enc(n,mb));
		for (int p=0;p<n;p++) {
			for (int b=0;b<mb;b++) {
				if (vor[p][b]==0) {
					//printf("in:%d\n",enc(p,b)); fflush(stdout);
					ts.forceFalse(enc(p,b));
					//printf("in:%d\n",enc(p+1,b)); fflush(stdout);
					ts.forceFalse(enc(p+1,b));
					if (vsum[p][b]==1&&b==0) return "Impossible";
					vinCarry[p][b]=vsum[p][b];
				}
			}
		}
		for (int p=0;p<n;p++) {
			for (int b=0;b<mb;b++) {
				if (vor[p][b]) {
					int inCarry=vinCarry[p][b];
					int outCarry=vinCarry[p][b+1];
					if (vsum[p][b]==0) {
						if (inCarry==0) {
							ts.forceTrue(enc(p,b));
							ts.forceTrue(enc(p+1,b));
						}
						else {
							int x=enc(p,b);
							int y=enc(p+1,b);
							ts.add(ts.neg(x),y);
							ts.add(ts.neg(y),x);
							ts.add(x,ts.neg(y));
							ts.add(y,ts.neg(x));
						}
						vinCarry[p][b+1]=1;
					}
					else {
						if (inCarry==0) {
							int x=enc(p,b);
							int y=enc(p+1,b);
							ts.add(ts.neg(x),y);
							ts.add(ts.neg(y),x);
							ts.add(x,ts.neg(y));
							ts.add(y,ts.neg(x));
							vinCarry[p][b+1]=0;
						}
						else {
							ts.forceTrue(enc(p,b));
							ts.forceTrue(enc(p+1,b));
							vinCarry[p][b+1]=1;
						}
					}
				}
			}
		}
		vector<bool> result = ts.solve();
		if (n > 0 && result.empty()) {
			return "Impossible";
		}
		else {
			vector<ll> vans;
			for (int x=0;x<=n;x++) {
				ll xval=0;
				for (int b=0;b<mb;b++) {
					if (result[enc(x,b)]) xval|=(1LL<<b);
				}
				vans.PB(xval);
			}
			for (int p=0;p<n;p++) {
				ll orVal=vans[p]|vans[p+1];
				ll sumVal=vans[p]+vans[p+1];
				if (orVal!=inpvor[p]) return "Impossible";
				if (sumVal!=inpvsum[p]) return "Impossible";
			}
			return "Possible";
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
		cout << "Testing OrAndSum (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1517173141;
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
		OrAndSum _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long pairOr[] = {7};
				long long pairSum[] = {11};
				_expected = "Possible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 1:
			{
				long long pairOr[] = {11};
				long long pairSum[] = {7};
				_expected = "Impossible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 2:
			{
				long long pairOr[] = {3,3,7,5,7};
				long long pairSum[] = {3,5,7,9,11};
				_expected = "Possible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 3:
			{
				long long pairOr[] = {1,100,1000};
				long long pairSum[] = {100,1000,10000};
				_expected = "Impossible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 4:
			{
				long long pairOr[] = {261208776456074191,261208776456074191,261208776456074191};
				long long pairSum[] = {333333333333333333,333333333333333333,333333333333333333};
				_expected = "Possible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 5:
			{
				long long pairOr[] = {0};
				long long pairSum[] = {0};
				_expected = "Possible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 6:
			{
				long long pairOr[] = {1};
				long long pairSum[] = {1};
				_expected = "Possible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			case 7:
			{
				long long pairOr[] = {1};
				long long pairSum[] = {2};
				_expected = "Possible";
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
			}
			/*case 8:
			{
				long long pairOr[] = ;
				long long pairSum[] = ;
				_expected = ;
				_received = _obj.isPossible(vector<long long>(pairOr, pairOr+sizeof(pairOr)/sizeof(long long)), vector<long long>(pairSum, pairSum+sizeof(pairSum)/sizeof(long long))); break;
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
