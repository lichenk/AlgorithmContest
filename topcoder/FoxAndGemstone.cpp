#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll a[52][16+2];
vector<string> b;
const ll xlim=16LL;
const ll zlim=1LL<<xlim;
ll f[zlim];
ll g[zlim][50];
bool h[zlim];
class FoxAndGemstone {
	public:
	string isPossible(vector <string> bags) {
		set<string> ss;
		ll maxsz=0;
		for (auto &w: bags) {
			chkmax(maxsz,(ll)w.length());
		}
		for (auto &w: bags) {
			sort(w.begin(),w.end());
			ss.insert(w);
		}
		for (auto &w:ss) b.PB(w);
		ll n=b.size();
		for (ll i=0;i<n;i++) {
			for (ll j=0;j<16;j++) a[i][j]=0;
		}
		for (ll i=0;i<n;i++) {
			for (ll j=0;j<b[i].length();j++) a[i][b[i][j]-'A']++;
		}
		ll sum=0;
		for (ll i=0;i<n;i++) {
			string s=b[i];
			if (s.length()<maxsz) continue;
			for (ll z=0;z<zlim;z++) {
				for (ll j=0;j<n;j++) g[z][j]=0;
			}
			for (ll z=1;z<zlim;z++) {
				ll fs=__builtin_ffsll(z)-1;
				ll pz=z^(1LL<<fs);
				for (ll j=0;j<n;j++) {
					g[z][j]=g[pz][j];
				}
				bool ok=true;
				for (ll j=0;j<n;j++) {
					g[z][j]+=(a[i][fs]-a[j][fs]);
					if (g[z][j]<0) ok=false;
				}
				h[z]=ok;
			}
			for (ll z=0;z<zlim;z++) {
				f[z]=0;
			}
			f[0]=1;
			for (ll z=0;z<zlim;z++) {
				if (f[z]==0) continue;
				for (ll x=0;x<xlim;x++) {
					ll xmask=1LL<<x;
					if (z&(xmask)) continue;
					ll nz=z|xmask;
					if (!h[nz]) continue;
					//printf("z: %lld->%lld: add %lld\n",z,nz,f[z]);
					f[nz]+=f[z];
				}
			}
			ll cnt=f[zlim-1];
			//printf("i:%lld cnt:%lld\n",i,cnt);
			sum+=cnt;
		}
		ll fac16=1;
		for (ll t=1;t<=xlim;t++) fac16*=t;
		if (sum==fac16) return "Possible";
		else if (sum<fac16) return "Impossible";
		else assert(false);
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
		cout << "Testing FoxAndGemstone (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1464260404;
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
		FoxAndGemstone _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string bags[] = {"AB", "AC"};
				_expected = "Possible";
				_received = _obj.isPossible(vector <string>(bags, bags+sizeof(bags)/sizeof(string))); break;
			}
			case 1:
			{
				string bags[] = {"A", "BC"};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <string>(bags, bags+sizeof(bags)/sizeof(string))); break;
			}
			case 2:
			{
				string bags[] = {"A", "B", "C", "AB", "AC", "BC", "ABC"};
				_expected = "Possible";
				_received = _obj.isPossible(vector <string>(bags, bags+sizeof(bags)/sizeof(string))); break;
			}
			case 3:
			{
				string bags[] = {"AB","AC","AD","BC","BD","CD"};
				_expected = "Possible";
				_received = _obj.isPossible(vector <string>(bags, bags+sizeof(bags)/sizeof(string))); break;
			}
			case 4:
			{
				string bags[] = {"AB", "CD"};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <string>(bags, bags+sizeof(bags)/sizeof(string))); break;
			}
			case 5:
			{
				string bags[] = {"A", "A", "A"};
				_expected = "Possible";
				_received = _obj.isPossible(vector <string>(bags, bags+sizeof(bags)/sizeof(string))); break;
			}
			case 6:
			{
				string bags[] = {"AAB","AC","AD","BC","BD","CD"};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <string>(bags, bags+sizeof(bags)/sizeof(string))); break;
			}
			case 7:
			{
				string bags[] = {"ABC","AD"};
				_expected = "Impossible";
				_received = _obj.isPossible(vector <string>(bags, bags+sizeof(bags)/sizeof(string))); break;
			}
			case 8:
			{
				string bags[] = {"AA","A"};
				_expected = "Possible";
				_received = _obj.isPossible(vector <string>(bags, bags+sizeof(bags)/sizeof(string))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
