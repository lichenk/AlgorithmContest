#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
ll a[1000];
vector<int> fail;
vector<pair<int,int> > v;
ll fac[21];
vector<pair<int,int> > go;
bool f(int k, ll x) {
	if(k==1) {
		return x==1;
	}
	if (f(k-1,x)) return true;
	ll d=fac[k];
	ll num=0;
	while(x%d==0) {
		num++;
		x/=d;
		if (f(k-1,x)) {
			go.PB(MP(k,num));
			return true;
		}
	}
	return false;
}

class AutomorphicTree {
	public:
	vector <int> construct(long long age) {
		fac[0]=1;
		for (ll x=1;x<=20;x++) fac[x]=(fac[x-1]*x);
		bool ok=f(20,age);
		if (!ok) return fail;
		for (auto &w: go) {
			ll x=w.first; ll cnt=w.second;
			//printf("x:%lld cnt:%lld\n",x,cnt);
			if (cnt<0) {return fail;}
			while (cnt>0) {
				ll t=1;
				ll num=-1;
				for (ll i=0;i<100;i++) {
					if (cnt-t<0) {num=i;break;}
					cnt -= t;
					t*=x;
				}
				v.PB(MP(num,x));
			}
		}
		//sort(v.begin(),v.end(),greater<pair<int,int> >());
		vector<int>ans;
		ll k=1;
		ll extra=3;
		for (auto &p:v) {
			ll q=0;
			for (ll i=0;i<extra;i++) {
				ans.PB(q);
				ans.PB(k);
				ll oldq=q;
				q=k;
				k++;
				if (i==extra-1) {
					for (ll j=0;j<extra-2;j++) {
						ans.PB(oldq);
						ans.PB(k);
						oldq=k;
						k++;
					}
				}
			}
			vector<int> active[2];
			active[0].PB(q);
			ll x=p.second; ll num=p.first;
			for (ll j=0;j<num;j++) {
				ll c=j%2;
				ll d=(j+1)%2;
				active[d].clear();
				for (auto &w:active[c]) {
					for (ll i=0;i<x;i++) {
						ans.PB(w);
						ans.PB(k);
						active[d].PB(k);
						k++;
					}
				}
			}
			extra++;
		}
		vector<int> final;
		final.PB(k);
		for (auto &w: ans) {
			final.PB(w);
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
		cout << "Testing AutomorphicTree (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455249579;
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
		AutomorphicTree _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long age = 1LL;
				int __expected[] = {1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(age); break;
			}
			case 1:
			{
				long long age = 8LL;
				int __expected[] = { 7, 0, 1, 0, 2, 1, 3, 1, 4, 2, 5, 2, 6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(age); break;
			}
			case 2:
			{
				long long age = 1000000000000000000LL;
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(age); break;
			}
			case 3:
			{
				long long age = 609508546352094986LL;
				int __expected[] = {};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(age); break;
			}
			case 4:
			{
				long long age = 120LL;
				int __expected[] = { 6, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(age); break;
			}
			case 5:
			{
				long long age = 72LL;
				int __expected[] = { 18, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 3, 6, 4, 7, 5, 8, 0, 9, 0, 10, 0, 11, 9, 12, 12, 13, 10, 14, 14, 15, 11, 16, 16, 17 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(age); break;
			}
			case 6:
			{
				long long age = 639106080130990080LL;
				int __expected[] = {1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(age); break;
			}
			case 7:
			{
				long long age = 4LL;
				int __expected[] = {0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(age); break;
			}
			case 8:
			{
				long long age = 2LL;
				int __expected[] = {0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(age); break;
			}
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
