#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const int mn=52;
vector<int> g[mn];
int n;
int getc(int x, int p) {
	int ans=1;
	for (auto &y:g[x]) {
		if (y!=p) ans+=getc(y,x);
	}
	return ans;
}
bitset<mn> leafed;
int getleaf(int x, int p) {
	if (leafed[x]) return -1;
	for (auto &y:g[x]) {
		if (y==p) continue;
		int got=getleaf(y,x);
		if (got!=-1) return got;
	}
	return x;
}
vector<int> vpath;
int dest;
bool getpath(int x, int p) {
	if (x==dest) {
		return true;
	}
	for (auto &y:g[x]) {
		if (y==p) continue;
		if (getpath(y,x)) {
			vpath.PB(y);
			return true;
		}
	}
	return false;
}
typedef pair<int,int> pii;
typedef vector<int> vi;
pair<vi,vi> go(int r) {
	leafed.reset();
	priority_queue<pii> pq;
	for (auto &x:g[r]) {
		int c=getc(x,r);
		pq.push(MP(c,x));
	}
	vi perm;
	perm.PB(r);
	while(!pq.empty()) {
		pii top1=pq.top(); pq.pop();
		pii top2=MP(-1,-1);
		if (!pq.empty()) {
			top2=pq.top(); pq.pop();
		}
		{
			auto top=top1;
			int leaf=getleaf(top.snd,r);
			assert(leaf!=-1);
			leafed[leaf]=true;
			perm.PB(leaf);
			top.fst--;
			if (top.fst>0) pq.push(top);
		}
		if (top2!=MP(-1,-1)){
			auto top=top2;
			int leaf=getleaf(top.snd,r);
			assert(leaf!=-1);
			leafed[leaf]=true;
			perm.PB(leaf);
			top.fst--;
			if (top.fst>0) pq.push(top);
		}
	}
	vi vans(n);
	vans[r]++;
	int cur=r;
	for (auto &w:perm) {
		if (w==r) continue;
		vpath.clear();
		dest=w;
		bool found=getpath(cur,-1);
		assert(found);
		for (auto &v:vpath) {
			vans[v]++;
		}
		cur=w;
	}
	sort(vans.begin(),vans.end(),greater<int>());
	/*printf("r:%d\n",r);
	for (auto &p:perm) printf("%d ",p);printf(" end perm\n");
	for (auto &p:vans) printf("%d ",p);printf(" end cnt\n");*/
	return MP(vans,perm);
}
class HeroVacation {
	public:
	vector <int> getPermutation(vector <int> p) {
		n=p.size()+1;
		for (int i=0;i<n-1;i++) {
			int x=i+1,y=p[i];
			g[x].PB(y); g[y].PB(x);
		}
		pair<vi,vi> final;
		for (int r=0;r<n;r++) {
			auto got=go(r);
			chkmax(final,got);
		}
		return final.snd;
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
		cout << "Testing HeroVacation (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1513966062;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HeroVacation _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int p[] = {0,1,2};
				int __expected[] = {1, 3, 0, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 1:
			{
				int p[] = {0,1,2,3};
				int __expected[] = {2, 0, 4, 1, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 2:
			{
				int p[] = {0,0,0,0};
				int __expected[] = {0, 1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 3:
			{
				int p[] = {0,1,0,2,0,2,2,5};
				int __expected[] = {1, 8, 7, 5, 6, 3, 4, 0, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 4:
			{
				int p[] = {0,0,0,1,1,1,2,2,2,3,3,3};
				int __expected[] = {0, 6, 9, 12, 5, 8, 11, 4, 7, 10, 1, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			case 5:
			{
				int p[] = {0,1,2,0,0,5,6,6,8,9,10,11,11,13,10,9};
				int __expected[] = {8, 7, 16, 5, 15, 4, 14, 3, 13, 2, 12, 1, 11, 0, 10, 6, 9 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}
			/*case 6:
			{
				int p[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int p[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int p[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getPermutation(vector <int>(p, p+sizeof(p)/sizeof(int))); break;
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
