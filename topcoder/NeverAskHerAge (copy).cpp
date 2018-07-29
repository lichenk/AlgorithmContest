#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll vmin[101],vmax[101];
bool bad=false;
const ll prec=10000;
ld doop(ld x, ld y, string op) {
	if (op=="+") return x+y;
	else if (op=="-") return x-y;
	else if (op=="*") return x*y;
	else if (op=="/") {
		if (fabs(y)<1e-9) {bad=true; return INF;}
		else return x/y;
	}
	else assert(false);
}
bool check(ll x, ll y, string op, string rl, ld val) {
	ll lhsprec=round(prec*doop(x,y,op));
	ll rhsprec=val*prec/1000.0;
	printf("lhs:%lld rhs:%lld\n",lhsprec,rhsprec);
	if (rl=="=") return lhsprec==rhsprec;
	else if (rl=="<") return lhsprec<rhsprec;
	else if (rl=="<=") return lhsprec<=rhsprec;
	else if (rl==">") return lhsprec>rhsprec;
	else if (rl==">=") return lhsprec>=rhsprec;
	else assert(false);
}
string invertop(string op) {
	if (op=="+") return "-";
	else if (op=="-") return "+";
	else if (op=="*") return "/";
	else if (op=="/") return "*";
	else assert(false);
}
string invertrl(string rl) {
	if (rl=="=") return "=";
	else if (rl==">=") return "<=";
	else if (rl==">") return "<";
	else if (rl=="<=") return ">=";
	else if (rl=="<") return ">";
	else assert(false);
}
ll rup(ll x) {
	return (x+999)/prec;
}
ll rdown(ll x) {
	return x/prec;
}
pll getPairHelper(ll rhsprec, string rl) {
	if (rl=="=") return MP(rup(rhsprec),rdown(rhsprec));
	else if (rl=="<=") return MP(1,rdown(rhsprec));
	else if (rl=="<") return MP(1,rdown(rhsprec-1));
	else if (rl==">=") return MP(rup(rhsprec),100);
	else if (rl==">") return MP(rup(rhsprec+1),100);
	else assert(false);	
}
pll getx(ll y, string op, string rl, ld val) {
	ll rhsprec=round(doop(val/1000.0,y,invertop(op))*prec);
	return getPairHelper(rhsprec,rl);
}
pll gety(ll x, string op, string rl, ld val) {
	if (op=="+"||op=="*") return getx(x,op,rl,val);
	ll rhsprec;
	if (op=="-") rhsprec=round(doop(x,val/1000.0,invertop(op))*prec);
	else if (op=="/") rhsprec=round(doop(x,val/1000.0,op)*prec);
	return getPairHelper(rhsprec,invertrl(rl));
}
pll getrelaxed(pll a, pll b) {
	return MP(min(a.first,b.first),max(a.second,b.second));
}
vector<ll> g[101];
class NeverAskHerAge {
	public:
	vector <int> possibleSolution(int n, vector <int> id1, vector <int> id2, vector <string> op, vector <string> rl, vector <int> val) {
		for (ll x=1;x<=n;x++) {
			vmin[x]=1,vmax[x]=100;
		}
		ll k=id1.size();
		for (ll i=0;i<k;i++) {
			g[id1[i]].PB(i);g[id2[i]].PB(i);
		}
		queue<pll> q;
		for (ll x=1;x<=n;x++) q.push(MP(x,vmax[x]));
		for (ll x=1;x<=n;x++) q.push(MP(-x,vmin[x]));
		while(!q.empty()) {
			pll got=q.front(); q.pop();
			ll rawid=got.first;
			ll id=abs(rawid);
			printf("id:%lld vmin:%lld vmax:%lld\n",id,vmin[id],vmax[id]);
			if (rawid>0 && (got.second>vmax[id])) continue; // vmax should be decreasing
			if (rawid<0 && (got.second<vmin[id])) continue; // vmin should be increasing
			for (auto &ei:g[id]) {
				pll constr;
				ll otherid;
				if (id==id1[ei]) {
					otherid=id2[ei];
					constr=getrelaxed(gety(vmin[id],op[ei],rl[ei],val[ei]),gety(vmax[id],op[ei],rl[ei],val[ei]));
				}
				else {
					assert(id==id2[ei]);
					otherid=id1[ei];
					constr=getrelaxed(getx(vmin[id],op[ei],rl[ei],val[ei]),getx(vmax[id],op[ei],rl[ei],val[ei]));
				}
				ll minx=constr.first,maxx=constr.second;
				printf("Result: %lld %lld\n",minx,maxx);
				if (minx>vmin[otherid]) {
					vmin[otherid]=minx;
					q.push(MP(-otherid,vmin[otherid]));
				}
				if (maxx<vmax[otherid]) {
					vmax[otherid]=maxx;
					q.push(MP(otherid,vmax[otherid]));
				}
			}
		}
		for (ll id=1;id<=n;id++) {
			if (vmin[id]>vmax[id]) return {};
		}
		for (ll ei=0;ei<k;ei++) {
			if (!check(vmin[id1[ei]],vmin[id2[ei]],op[ei],rl[ei],val[ei])) {
				printf("Oops\n");
				return {};
			}
		}
		vector<int> ans;
		for (ll id=1;id<=n;id++) ans.PB(vmin[id]);
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
		cout << "Testing NeverAskHerAge (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486451101;
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
		NeverAskHerAge _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int id1[] = {1,1};
				int id2[] = {2,2};
				string op[] = {"+","*"};
				string rl[] = {"=","="};
				int val[] = {10000,21000};
				int __expected[] = {3, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleSolution(n, vector <int>(id1, id1+sizeof(id1)/sizeof(int)), vector <int>(id2, id2+sizeof(id2)/sizeof(int)), vector <string>(op, op+sizeof(op)/sizeof(string)), vector <string>(rl, rl+sizeof(rl)/sizeof(string)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 7;
				int id1[] = {1,2,3,4,5,6};
				int id2[] = {2,3,4,5,6,7};
				string op[] = {"/","/","/","/","/","/"};
				string rl[] = {"=","=","=","=","=","="};
				int val[] = {2000,2000,2000,2000,2000,2000};
				int __expected[] = {64, 32, 16, 8, 4, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleSolution(n, vector <int>(id1, id1+sizeof(id1)/sizeof(int)), vector <int>(id2, id2+sizeof(id2)/sizeof(int)), vector <string>(op, op+sizeof(op)/sizeof(string)), vector <string>(rl, rl+sizeof(rl)/sizeof(string)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 2;
				int id1[] = {1,1};
				int id2[] = {2,2};
				string op[] = {"/","/"};
				string rl[] = {">","<"};
				int val[] = {2621,2622};
				int __expected[] = {97, 37 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleSolution(n, vector <int>(id1, id1+sizeof(id1)/sizeof(int)), vector <int>(id2, id2+sizeof(id2)/sizeof(int)), vector <string>(op, op+sizeof(op)/sizeof(string)), vector <string>(rl, rl+sizeof(rl)/sizeof(string)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 2;
				int id1[] = {1,1};
				int id2[] = {2,2};
				string op[] = {"*","+"};
				string rl[] = {">","<="};
				int val[] = {6000,5000};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleSolution(n, vector <int>(id1, id1+sizeof(id1)/sizeof(int)), vector <int>(id2, id2+sizeof(id2)/sizeof(int)), vector <string>(op, op+sizeof(op)/sizeof(string)), vector <string>(rl, rl+sizeof(rl)/sizeof(string)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 8;
				int id1[] = {1,3,5,7};
				int id2[] = {2,4,6,8};
				string op[] = {"+","-","*","/"};
				string rl[] = {">=","<=","=","<="};
				int val[] = {200000,-99000,3589000,10};
				int __expected[] = {100, 100, 1, 100, 97, 37, 1, 100 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleSolution(n, vector <int>(id1, id1+sizeof(id1)/sizeof(int)), vector <int>(id2, id2+sizeof(id2)/sizeof(int)), vector <string>(op, op+sizeof(op)/sizeof(string)), vector <string>(rl, rl+sizeof(rl)/sizeof(string)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			case 5:
			{
				int n = 8;
				int id1[] = {7,1,3,4,4,3,7,2,3,6,4,4,6,5,2,8,2,2,7,6,2,2,8,6,5,6,5,4,4,8,6,1,3,5,5,4,3,7,4,8};
				int id2[] = {2,7,6,6,1,2,4,7,4,4,8,3,8,2,4,1,7,7,6,2,5,7,6,5,8,2,8,1,8,1,3,2,7,1,2,2,1,8,3,3};
				string op[] = {"/","*","/","-","*","+","*","+","/","+","-","+","*","+","/","*","-","/","-","*","/","/","/","*","/","+","+","*","*","-","-","*","+","+","+","-","+","/","+","*"};
				string rl[] = {"<","<","<=",">","<","<=","<",">","<","<=","<=",">",">",">=","<",">","<","<",">",">=","<=","<","<=",">=","<=",">=",">=",">=","<=",">=","<=",">","<=","<",">","<=",">=","<","<=","<="};
				int val[] = {47636,5754558,3307,-41496,7043286,144246,5048203,72315,85384,182630,50604,9802,3843942,152392,60035,149684,94234,31209,-73898,195742,8383,71993,98477,4859384,74619,146266,60163,377564,5357728,-80040,72545,1088942,87517,192354,18629,45785,44151,95334,140360,1063484};
				int __expected[] = {56, 77, 19, 59, 77, 87, 43, 51 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleSolution(n, vector <int>(id1, id1+sizeof(id1)/sizeof(int)), vector <int>(id2, id2+sizeof(id2)/sizeof(int)), vector <string>(op, op+sizeof(op)/sizeof(string)), vector <string>(rl, rl+sizeof(rl)/sizeof(string)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			case 6:
			{
				int n = 8;
				int id1[] = {7,1,3,4,4,3,7,2,3,6,4,4,6,5,2,8,2,2,7,6,2,2,8,6,5,6,5,4,4,8,6,1,3,5,5,4,3,7,4,8};
				int id2[] = {2,7,6,6,1,2,4,7,4,4,8,3,8,2,4,1,7,7,6,2,5,7,6,5,8,2,8,1,8,1,3,2,7,1,2,2,1,8,3,3};
				string op[] = {"/","*","/","-","*","+","*","+","/","+","-","+","*","+","/","*","-","/","-","*","/","/","/","*","/","+","+","*","*","-","-","*","+","+","+","-","+","/","+","*"};
				string rl[] = {"=","<","<=",">","<","<=","<",">","<","<=","<=",">",">",">=","<",">","<","<",">",">=","<=","<","<=",">=","<=",">=",">=",">=","<=",">=","<=",">","<=","<",">","<=",">=","<","<=","<="};
				int val[] = {2000,5754558,3307,-41496,7043286,144246,5048203,72315,85384,182630,50604,9802,3843942,152392,60035,149684,94234,31209,-73898,195742,8383,71993,98477,4859384,74619,146266,60163,377564,5357728,-80040,72545,1088942,87517,192354,18629,45785,44151,95334,140360,1063484};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleSolution(n, vector <int>(id1, id1+sizeof(id1)/sizeof(int)), vector <int>(id2, id2+sizeof(id2)/sizeof(int)), vector <string>(op, op+sizeof(op)/sizeof(string)), vector <string>(rl, rl+sizeof(rl)/sizeof(string)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}
			/*case 7:
			{
				int n = ;
				int id1[] = ;
				int id2[] = ;
				string op[] = ;
				string rl[] = ;
				int val[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleSolution(n, vector <int>(id1, id1+sizeof(id1)/sizeof(int)), vector <int>(id2, id2+sizeof(id2)/sizeof(int)), vector <string>(op, op+sizeof(op)/sizeof(string)), vector <string>(rl, rl+sizeof(rl)/sizeof(string)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int n = ;
				int id1[] = ;
				int id2[] = ;
				string op[] = ;
				string rl[] = ;
				int val[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleSolution(n, vector <int>(id1, id1+sizeof(id1)/sizeof(int)), vector <int>(id2, id2+sizeof(id2)/sizeof(int)), vector <string>(op, op+sizeof(op)/sizeof(string)), vector <string>(rl, rl+sizeof(rl)/sizeof(string)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int n = ;
				int id1[] = ;
				int id2[] = ;
				string op[] = ;
				string rl[] = ;
				int val[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleSolution(n, vector <int>(id1, id1+sizeof(id1)/sizeof(int)), vector <int>(id2, id2+sizeof(id2)/sizeof(int)), vector <string>(op, op+sizeof(op)/sizeof(string)), vector <string>(rl, rl+sizeof(rl)/sizeof(string)), vector <int>(val, val+sizeof(val)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
