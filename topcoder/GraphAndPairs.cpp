#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
vector<pii> v;
vector<pii> v2;
int vsz;
void prep() {
	for (int x=1;x<=500;x++) {
		for (int y=max(1,x-5);y<=x+5;y++) {
			v.PB(MP(x*y,x));
		}
	}
	for (int x=1;x<=700;x++) v2.PB(MP((x*(x-1))/2,x));
	sort(v.begin(),v.end());
	vsz=v.size();
}
vector<int> edges;
int gid=0;
int gv() {
	return gid++;
}
void ae(int x, int y) {
	edges.PB(x); edges.PB(y);
}
void ac(int l, int r, int d) {
	int s=gv();
	int t=s;
	int prev=s;
	for (int i=0;i<d-2;i++) {
		int y=gv();
		ae(prev,y);
		t=y;
		prev=y;
	}
	for (int i=0;i<l;i++) {
		int x=gv();
		ae(x,s);
	}
	for (int i=0;i<r;i++) {
		int x=gv();
		ae(x,t);
	}
}

void go(int k, int d) {
	edges.clear();
	gid=0;
	int e=0,n=0;
	if (d==2) {
		while(k>0) {
			int imin=0,imax=v2.size();
			while(imin<imax) {
				int imid=(imin+imax)>>1;
				if (v2[imid].fst<=k) imin=imid+1;
				else imax=imid;
			}
			int idx=imin-1;
			int got=v2[idx].fst;
			k-=got;
			int x=v2[idx].snd;
			int y=0;
			//printf("got:%d x:%d\n",got,x);
			ac(x,y,d);
		}
		return;
	}
	while(k>0) {
		int imin=0,imax=vsz;
		while(imin<imax) {
			int imid=(imin+imax)>>1;
			if (v[imid].fst<=k) imin=imid+1;
			else imax=imid;
		}
		int idx=imin-1;
		int got=v[idx].fst;
		k-=got;
		int x=v[idx].snd;
		int y=v[idx].fst/v[idx].snd;
		ac(x,y,d);
	}
}
vector<int> solve(int k, int d) {
	go(k,d);
	vector<int> final;
	final.PB(gid);
	for (auto &w:edges) final.PB(w);
	return final;
}
class GraphAndPairs {
	public:
	vector <int> construct(int _d, int _k) {
		prep();
		return solve(_k,_d);
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
		cout << "Testing GraphAndPairs (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1506440581;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		GraphAndPairs _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int d = 2;
				int k = 1;
				int __expected[] = {4, 0, 1, 1, 3, 3, 2, 2, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}
			case 1:
			{
				int d = 2;
				int k = 2;
				int __expected[] = {8, 0, 1, 1, 3, 3, 2, 2, 0, 1, 2, 4, 5, 5, 7, 7, 6, 6, 4, 5, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}
			case 2:
			{
				int d = 4;
				int k = 4;
				int __expected[] = {8, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}
			case 3:
			{
				int d = 5;
				int k = 2;
				int __expected[] = {10, 0, 1, 1, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8, 8, 9, 0, 5, 1, 6, 2, 7, 3, 8, 4, 9 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}
			case 4:
			{
				int d = 2;
				int k = 4;
				int __expected[] = {1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}
			/*case 5:
			{
				int d = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
			}*/
			/*case 6:
			{
				int d = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(d, k); break;
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
