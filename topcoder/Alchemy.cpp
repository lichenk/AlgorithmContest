#include "bits/stdc++.h"
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
typedef pair<int,int> pii;
#define fst first
#define snd second
typedef vector<int> vi;
const int mg=2*(1e4)+6;
const int ml=100;
bitset<mg+2> f[2];
vi l2g[ml+2];
vi v;
const int ma=2*(1e6+2e4)+6;
bitset<ma+2> a;
template<typename T> void sortmakeunique(vector<T> & myvector) {
  sort(myvector.begin(), myvector.end());
  auto it = std::unique (myvector.begin(), myvector.end());
  myvector.resize( std::distance(myvector.begin(),it) );
}

bool frobeniusCoin(vector<ll> &prepared, ll goal) {
	// Pass in prepared vector returned from prepareFrobeniusCoin
	if (goal<0) return false;
	if (prepared.size()==0) return (goal==0);
	return prepared[goal%((int)prepared.size())]<=goal;
}

vector<ll> prepareFrobeniusCoin(vi &inp) {
	// Assumes all v[i]>=0. Runtime is min(inp)^2 * inp.size().
	// f[k] is the lowest x st. x%k==0 that is attainable from an infinite number of coins in inp.
	vi v;
	for (auto &w:inp) {
		assert(w>=0);
		if (w>0) v.PB(w);
	}
	if (v.size()==0) return vector<ll>();
	sortmakeunique(v);
	int k=v[0];
	vector<ll> f(k); f[0]=0; for (int x=1;x<k;x++) f[x]=LLONG_MAX;
	queue<int> q; q.push(0);
	while(!q.empty()) {
		int x=q.front(); q.pop();
		for (auto &w:v) {
			ll cand=f[x]+w;
			int c=cand%k;
			if (cand<f[c]) {
				f[c]=cand;
				q.push(c);
			}
		}
	}
	return f;
}

string subleadToGold(vector <int> &vl, vector <int> &vg, long long goal) {
	int ts=vl.size();
	for (int t=0;t<ts;t++) {
		l2g[vl[t]].PB(vg[t]);
	}
	for (int l=0;l<=ml;l++) {
		sortmakeunique(l2g[l]);
	}
	f[0][0]=true;
	for (int l=1;l<=ml;l++) {
		int nxt=l&1; int cur=nxt^1;
		for(int i=f[cur]._Find_first();i< f[cur].size();i = f[cur]._Find_next(i)) {
			for (auto &g:l2g[l]) {
				v.PB(g+i);
			}
		}
		if (l==ml) break;
		f[nxt].reset();
		for (auto &w:l2g[0]) {
			f[nxt]|=f[cur]<<w;
		}
	}
	vector<ll> prepared = prepareFrobeniusCoin(v);
	for (auto &w:l2g[0]) {
		ll lft=goal-w;
		if (frobeniusCoin(prepared,lft)) {
			return "Possible";
		}
	}
	return "Impossible";
}


class Alchemy {
	public:
	string leadToGold(vector <int> vl, vector <int> vg, long long goal) {
		string ans=subleadToGold(vl,vg,goal);
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
		cout << "Testing Alchemy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 50; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1532050361;
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
		Alchemy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int leadOutput[] = {1,1,1};
				int goldOutput[] = {0,1,2};
				long long goal = 47LL;
				_expected = "Impossible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 1:
			{
				int leadOutput[] = {4,0};
				int goldOutput[] = {1,3};
				long long goal = 23LL;
				_expected = "Possible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 2:
			{
				int leadOutput[] = {3,0,0};
				int goldOutput[] = {0,5,7};
				long long goal = 9876543210LL;
				_expected = "Impossible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 3:
			{
				int leadOutput[] = {3,0,0};
				int goldOutput[] = {0,5,7};
				long long goal = 123456789LL;
				_expected = "Possible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 4:
			{
				int leadOutput[] = {0};
				int goldOutput[] = {0};
				long long goal = 0LL;
				_expected = "Possible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 5:
			{
				int leadOutput[] = {1};
				int goldOutput[] = {0};
				long long goal = 0LL;
				_expected = "Impossible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 6:
			{
				int leadOutput[] = {0};
				int goldOutput[] = {100};
				long long goal = 100LL;
				_expected = "Possible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 7:
			{
				int leadOutput[] = {0,1,1};
				int goldOutput[] = {0,100,99};
				long long goal = 50LL;
				_expected = "Impossible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 8:
			{
				int leadOutput[] = {100, 98, 96, 94, 92, 90, 88, 86, 84, 82, 80, 78, 76, 74, 72, 70, 68, 66, 64, 62, 60, 59, 58, 57, 56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				int goldOutput[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76};
				long long goal = 4355LL;
				_expected = "Impossible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			default: {
				exit(0);
				srand(clock());
				vector<int> l,g;
				//int n=rand()%50+1;
				int n=50;
				for (int i=0;i<n;i++) {
					l.PB(10*(rand()%11));
					g.PB(10*(rand()%11));
				}
				ll goal=(((ll)rand())<<28)^rand();
				int leadOutput[] = {1};
				int goldOutput[] = {0};
				_received = _obj.leadToGold(l,g, goal);
				_expected = _received;
				break;
			}
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
