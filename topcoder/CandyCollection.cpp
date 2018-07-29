#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<20ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN = 2008;
const ll OFFSET = 1000;
vector<pair<ll,ll> > g[MAXN];
vector<ll> gv,hv,c1,c2;
ll f[MAXN][MAXN];
bool seen[MAXN];
void dfs(ll x, ll p) {
	if (seen[x]) return;
	seen[x]=true;
	if (x<OFFSET) gv.PB(x);
	else hv.PB(x-OFFSET);
	for (auto &w: g[x]) {
		if (p==w.first) continue;
		if (x<OFFSET) c2.PB(w.second);
		else c1.PB(w.second);
		dfs(w.first,x);
	}
}
class CandyCollection {
	public:
	int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2) {
		for (ll i=0;i<MAXN;i++) seen[i]=false;
		ll n=Type1.size();
		for (ll shape=0;shape<n;shape++) {
			{
				ll v=Type1[shape]+OFFSET;
				ll num=Number1[shape];
				g[v].PB(MP(shape,num));
				g[shape].PB(MP(v,num));
			}
			{
				ll v=Type2[shape]+OFFSET;
				ll num=Number2[shape];
				g[v].PB(MP(shape,num));
				g[shape].PB(MP(v,num));
			}
		}
		ll final=0;
		for (ll zflavor=OFFSET;zflavor<OFFSET+n;zflavor++) {
			if(seen[zflavor]) continue;
			gv.clear(); hv.clear(); c1.clear(); c2.clear();
			dfs(zflavor,-1);
			assert(gv.size()==hv.size());
			/*//printf("dbg:%d %d %d\n",gv.size(),c1.size(),c2.size());
			assert(gv.size()==c1.size());*/
			assert(gv.size()==c2.size());
			ll gvsz=gv.size();
			for (ll i=0;i<gvsz;i++) {
				//printf("%d %d %d %d\n",gv[i],hv[i],c1[i],c2[i]);
			}
			ll ans=INF;
			for (ll init=0;init<2;init++) {
				for (ll x=0;x<=gvsz;x++) {
					for (ll k=0;k<2;k++) {
						f[x][k]=INF;
					}
				}
				if (init) {f[0][1]=0;}
				else {f[0][0] = 0;}
				for (ll x=0;x<gvsz;x++) {
					for (ll k=0;k<2;k++) {
						ll v=f[x][k];
						//printf("%d %d: %d\n",x,k,v);
						if(k==1) {
							// go next
							chkmin(f[x+1][1],v+c1[x]+1);
							// dont go next
							chkmin(f[x+1][0],v);
						}
						else {
							// go next
							chkmin(f[x+1][1],v+max(c1[x],c2[x])+1);
							// dont go next
							chkmin(f[x+1][0],v+c2[x]+1);
						}
					}
				}
				ll cand = f[gvsz][init];
				chkmin(ans,cand);
			}
			final += ans;
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
		cout << "Testing CandyCollection (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457071994;
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
		CandyCollection _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int Type1[] = {0,0};
				int Number1[] = {1,1};
				int Type2[] = {1,1};
				int Number2[] = {1,1};
				_expected = 2;
				_received = _obj.solve(vector <int>(Type1, Type1+sizeof(Type1)/sizeof(int)), vector <int>(Number1, Number1+sizeof(Number1)/sizeof(int)), vector <int>(Type2, Type2+sizeof(Type2)/sizeof(int)), vector <int>(Number2, Number2+sizeof(Number2)/sizeof(int))); break;
			}
			case 1:
			{
				int Type1[] = {0,0};
				int Number1[] = {2,5};
				int Type2[] = {1,1};
				int Number2[] = {2,5};
				_expected = 3;
				_received = _obj.solve(vector <int>(Type1, Type1+sizeof(Type1)/sizeof(int)), vector <int>(Number1, Number1+sizeof(Number1)/sizeof(int)), vector <int>(Type2, Type2+sizeof(Type2)/sizeof(int)), vector <int>(Number2, Number2+sizeof(Number2)/sizeof(int))); break;
			}
			case 2:
			{
				int Type1[] = {0,0,2,3};
				int Number1[] = {1,1,2,2};
				int Type2[] = {1,1,3,2};
				int Number2[] = {1,1,2,2};
				_expected = 5;
				_received = _obj.solve(vector <int>(Type1, Type1+sizeof(Type1)/sizeof(int)), vector <int>(Number1, Number1+sizeof(Number1)/sizeof(int)), vector <int>(Type2, Type2+sizeof(Type2)/sizeof(int)), vector <int>(Number2, Number2+sizeof(Number2)/sizeof(int))); break;
			}
			case 3:
			{
				int Type1[] = {0,1,2,3};
				int Number1[] = {5,5,10,13};
				int Type2[] = {1,2,3,0};
				int Number2[] = {8,8,10,15};
				_expected = 20;
				_received = _obj.solve(vector <int>(Type1, Type1+sizeof(Type1)/sizeof(int)), vector <int>(Number1, Number1+sizeof(Number1)/sizeof(int)), vector <int>(Type2, Type2+sizeof(Type2)/sizeof(int)), vector <int>(Number2, Number2+sizeof(Number2)/sizeof(int))); break;
			}
			case 4:
			{
				int Type1[] = {12,9,0,16,9,18,12,3,6,0,8,2,10,6,5,2,14,10,5,13};
				int Number1[] = {895,704,812,323,334,674,665,142,712,254,869,548,645,663,758,38,860,724,742,530};
				int Type2[] = {1,4,7,11,15,8,18,13,17,17,19,14,7,11,4,1,15,19,3,16};
				int Number2[] = {779,317,36,191,843,289,107,41,943,265,649,447,806,891,730,371,351,7,102,394};
				_expected = 5101;
				_received = _obj.solve(vector <int>(Type1, Type1+sizeof(Type1)/sizeof(int)), vector <int>(Number1, Number1+sizeof(Number1)/sizeof(int)), vector <int>(Type2, Type2+sizeof(Type2)/sizeof(int)), vector <int>(Number2, Number2+sizeof(Number2)/sizeof(int))); break;
			}
			case 5:
			{
				int Type1[] =   {0,1,2};
				int Number1[] = {100,10,20};
				int Type2[] =   {1,2,0};
				int Number2[] = {30,10,100};
				_expected = 32;
				_received = _obj.solve(vector <int>(Type1, Type1+sizeof(Type1)/sizeof(int)), vector <int>(Number1, Number1+sizeof(Number1)/sizeof(int)), vector <int>(Type2, Type2+sizeof(Type2)/sizeof(int)), vector <int>(Number2, Number2+sizeof(Number2)/sizeof(int))); break;
			}
			case 6:
			{
				int Type1[] = {0,1};
				int Number1[] = {100,100};
				int Type2[] = {1,0};
				int Number2[] = {1,1};
				_expected = 4;
				_received = _obj.solve(vector <int>(Type1, Type1+sizeof(Type1)/sizeof(int)), vector <int>(Number1, Number1+sizeof(Number1)/sizeof(int)), vector <int>(Type2, Type2+sizeof(Type2)/sizeof(int)), vector <int>(Number2, Number2+sizeof(Number2)/sizeof(int))); break;
			}
			/*case 7:
			{
				int Type1[] = ;
				int Number1[] = ;
				int Type2[] = ;
				int Number2[] = ;
				_expected = ;
				_received = _obj.solve(vector <int>(Type1, Type1+sizeof(Type1)/sizeof(int)), vector <int>(Number1, Number1+sizeof(Number1)/sizeof(int)), vector <int>(Type2, Type2+sizeof(Type2)/sizeof(int)), vector <int>(Number2, Number2+sizeof(Number2)/sizeof(int))); break;
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
