#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef __int128 ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
bool cmp(const pair<pll,vector<int> > x, const pair<pll,vector<int> > y) {
	ll a=x.fst.fst,b=x.fst.snd;
	ll c=y.fst.fst,d=y.fst.snd;
	ll res=a*d-b*c;
	if (res==0) {
		return x.snd<y.snd;
	}
	return res<0;
}
	vector <int> findTuple(vector <int> x) {
		vector<int> p;
		for (int i=0;i<5;i++) p.PB(i);
		vector<pair<pll,vector<int> > > v;
		do {
			ll a=x[p[0]];
			ll b=x[p[1]];
			ll c=x[p[2]];
			ll d=x[p[3]];
			vector<int> t;
			for (int i=0;i<4;i++) t.PB(p[i]);
			ll num=(a*d-b*c);
			if (num<0) num=-num;
			ll den=b*d;
			v.PB(MP(MP(num,den),t));
		} while(next_permutation(p.begin(),p.end()));
		sort(v.begin(),v.end(),cmp);
		return v[0].snd;
	}
	vector <int> bf(vector <int> x) {
		vector<int> p;
		for (int i=0;i<5;i++) p.PB(i);
		vector<pair<float,vector<int> > > v;
		do {
			ll a=x[p[0]];
			ll b=x[p[1]];
			ll c=x[p[2]];
			ll d=x[p[3]];
			vector<int> t;
			for (int i=0;i<4;i++) t.PB(p[i]);
			ll num=(a*d-b*c);
			if (num<0) num=-num;
			ll den=b*d;
			v.PB(MP(num/(float)den,t));
		} while(next_permutation(p.begin(),p.end()));
		sort(v.begin(),v.end());
		return v[0].snd;
	}
void go() {
	int seed=clock();
	srand(clock());
	vector<int> v={9994,10000,10000,10000,9997};
	/*for (int i=0;i<5;i++) {
		int t=rand()%7;
		v.PB(10000-t);
	}*/
	vi bff=bf(v);
	vi cor=findTuple(v);
	if (bff!=cor) {
		for (auto &w:v) printf("%d ",w);
		exit(0);
	}
}
class MinimizeAbsoluteDifferenceDiv1 {
	public:
	vector <int> findTuple(vector <int> x) {
		while(1) go();
		vector<int> p;
		for (int i=0;i<5;i++) p.PB(i);
		vector<pair<pll,vector<int> > > v;
		do {
			ll a=x[p[0]];
			ll b=x[p[1]];
			ll c=x[p[2]];
			ll d=x[p[3]];
			vector<int> t;
			for (int i=0;i<4;i++) t.PB(p[i]);
			ll num=(a*d-b*c);
			if (num<0) num=-num;
			ll den=b*d;
			v.PB(MP(MP(num,den),t));
		} while(next_permutation(p.begin(),p.end()));
		sort(v.begin(),v.end(),cmp);
		return v[0].snd;
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
		cout << "Testing MinimizeAbsoluteDifferenceDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1523721602;
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
		MinimizeAbsoluteDifferenceDiv1 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1,1,1,1,1};
				int __expected[] = {0, 1, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {2,3,5,7,11};
				int __expected[] = {0, 3, 1, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {8, 2, 4, 2, 6};
				int __expected[] = {1, 0, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {124, 182, 9, 33, 70};
				int __expected[] = {2, 4, 3, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {9947, 3, 7, 11, 13};
				int __expected[] = {1, 4, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {10000, 4, 10, 4, 10};
				int __expected[] = {1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findTuple(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
