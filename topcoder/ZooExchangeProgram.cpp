#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
unordered_map<ll,ll> f[2];
class ZooExchangeProgram {
	public:
	int getNumber(vector <int> label, int lower, int upper) {
		
		ll lsz=label.size();
		for (ll i=0;i<lsz;i++) {
			label[i] -= lower;
		}
		upper -= lower;
		lower=0;
		vector<ll> s;
		ll start=0;
		while(!(lower<=label[start]&&label[start]<=upper)) start++;
		ll y=0;
		for (ll i=start;i<lsz;i++) {
			ll x=label[i];
			if (!(lower<=x&&x<=upper)) {
				s.PB(y);
				y=0;
			}
			else y |= (1ULL<<x);
		}
		if (y!=0) s.PB(y);
		//for (auto &w:s) //printf("w:%lld\n",w);
		ll n=s.size();
		ll lim=1ULL<<(upper+1);
		f[0][0]=0;
		for (ll x=0;x<n;x++) {
			ll c=x%2;
			ll a=(x+1)%2;
			f[a].clear();
			ll t=s[x];
			for (auto &p: f[c]) {
				f[a][p.first] = p.second;
			}
			for (auto &p: f[c]) {
				ll z=p.first;
				ll v=p.second+1;
				ll r=z|t;
				auto it = f[a].find(r);
				if (it==f[a].end()) f[a][r] = v;
				else it->second = min(it->second,v);
			}
		}
		//printf("dbg:%lld %lld\n",n%2,lim-1);
		auto jt = f[n%2].find(lim-1);
		if (jt==f[n%2].end()) return -1;
		return jt->second;
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
		cout << "Testing ZooExchangeProgram (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455248318;
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
		ZooExchangeProgram _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int label[] = {2, 1, 3};
				int lower = 1;
				int upper = 3;
				_expected = 1;
				_received = _obj.getNumber(vector <int>(label, label+sizeof(label)/sizeof(int)), lower, upper); break;
			}
			case 1:
			{
				int label[] = {3, 4, 1, 3, 4, 2};
				int lower = 1;
				int upper = 3;
				_expected = 2;
				_received = _obj.getNumber(vector <int>(label, label+sizeof(label)/sizeof(int)), lower, upper); break;
			}
			case 2:
			{
				int label[] = {3, 4, 3, 1, 6, 2, 5, 7, 5, 2};
				int lower = 2;
				int upper = 6;
				_expected = 2;
				_received = _obj.getNumber(vector <int>(label, label+sizeof(label)/sizeof(int)), lower, upper); break;
			}
			case 3:
			{
				int label[] = {3, 1, 4};
				int lower = 2;
				int upper = 4;
				_expected = -1;
				_received = _obj.getNumber(vector <int>(label, label+sizeof(label)/sizeof(int)), lower, upper); break;
			}
			case 4:
			{
				int label[] = {2, 1, 3, 1, 4};
				int lower = 1;
				int upper = 4;
				_expected = 1;
				_received = _obj.getNumber(vector <int>(label, label+sizeof(label)/sizeof(int)), lower, upper); break;
			}
			case 5:
			{
				int label[] = {7, 12, 2, 12, 10, 13, 6, 5, 3, 3, 4, 11, 12, 4, 3, 1, 8, 11, 4, 7, 6, 5, 47};
				int lower = 2;
				int upper = 7;
				_expected = 3;
				_received = _obj.getNumber(vector <int>(label, label+sizeof(label)/sizeof(int)), lower, upper); break;
			}
			/*case 6:
			{
				int label[] = ;
				int lower = ;
				int upper = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(label, label+sizeof(label)/sizeof(int)), lower, upper); break;
			}*/
			/*case 7:
			{
				int label[] = ;
				int lower = ;
				int upper = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(label, label+sizeof(label)/sizeof(int)), lower, upper); break;
			}*/
			/*case 8:
			{
				int label[] = ;
				int lower = ;
				int upper = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(label, label+sizeof(label)/sizeof(int)), lower, upper); break;
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
