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
const ll ON=-1,OFF=-2;
ll cr[1<<21];
ll ans[1<<21];
class Clicounting {
	public:
	int count(vector <string> _g) {
		ll n=_g.size();
		set<ll> s;
		for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) if (_g[x][y]=='?') {s.insert(x);s.insert(y);}
		map<ll,ll> h;
		{
			ll idx=0;
			for (auto &w:s) {
				h[w]=idx;
				idx++;
			}	
			for (ll x=0;x<n;x++) {
				if (s.find(x)==s.end()) {
					h[x]=idx;
					idx++;
				}
			}
		}
		vector<string> tmp=_g;
		for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) tmp[h[x]][h[y]]=_g[x][y];
		ll g[50][50];
		ll qn;
		for (ll x=0;x<n;x++) for (ll y=0;y<=x;y++) {
			char c=tmp[x][y];ll res;
			if (c=='1') res=ON;
			if (c=='0') res=OFF;
			if (c=='?') res=qn++;
			if (x==y) res=ON;
			g[x][y]=res;
		}
		for (ll x=0;x<n;x++) for (ll y=x;y<n;y++) {
			g[x][y]=g[y][x];
		}
		for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) {
			//printf("%lld %lld: %lld\n",x,y,g[x][y]);
		}
		ll c=max(n/2,(ll)s.size());
		ll d=n-c;
		{
			ll zlim=1LL<<d;
			for (ll z=0;z<zlim;z++) {
				ll got=0;
				bool ok=true;
				for (ll x=0;x<d;x++) {
					if (!(z&(1LL<<x))) continue;
					for (ll y=0;y<d;y++) {
						if (!(z&(1LL<<y))) continue;
						ll got=g[x+c][y+c];
						//printf("x+c:%lld y+c:%lld c:%lld got:%lld\n",x,y,c,got);
						assert(got<0);
						if (got==OFF) {ok=false; break;}
					}
				}
				if (ok) cr[z]=__builtin_popcountll(z);
				else cr[z]=0;
			}
			for (ll x=0;x<d;x++) {
				ll m=1LL<<x;
				for (ll z=0;z<zlim;z++) {
					if (!(z&m)) {
						chkmax(cr[z^m],cr[z]);
					}
				}
			}
			for (ll z=0;z<zlim;z++) {
				//printf("z:%lld cr:%lld\n",z,cr[z]);
			}
		}
		{
			ll zlim=1LL<<qn;
			for (ll z=0;z<zlim;z++) ans[z]=0;
		}
		{
			ll zlim=1LL<<c;
			for (ll z=0;z<zlim;z++) {
				ll got=0;
				ll need=0;
				bool ok=true;
				for (ll x=0;x<c;x++) {
					if (!(z&(1LL<<x))) continue;
					for (ll y=0;y<c;y++) {
						if (!(z&(1LL<<y))) continue;
						if (g[x][y]==OFF) {ok=false;break;}
						else if (g[x][y]==ON) {}
						else {
							need|=1LL<<g[x][y];
						}
					}
				}
				if (!ok) continue;
				ll have=0;
				for (ll y=0;y<d;y++) {
					bool cany=true;
					for (ll x=0;x<c;x++) {
						if (!(z&(1LL<<x))) continue;
						ll got=g[x][y+c];
						assert(got<0);
						if (got==OFF) {cany=false; break;}
					}
					if (cany) {
						have|=1LL<<y;
					}
				}
				ll csize=cr[have]+__builtin_popcountll(z);
				chkmax(ans[need],csize);
			}
		}
		{
			ll zlim=1LL<<qn;
			for (ll x=0;x<qn;x++) {
				ll m=1LL<<x;
				for (ll z=0;z<zlim;z++) {
					if (!(z&m)) {
						chkmax(ans[z^m],ans[z]);
					}
				}
			}
			ll final=0;
			for (ll z=0;z<zlim;z++) final+=ans[z];
			return final;
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
		cout << "Testing Clicounting (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470879511;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Clicounting _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string g[] = {"011","101","110"};
				_expected = 3;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 1:
			{
				string g[] = {"01?","101","?10"};
				_expected = 5;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 2:
			{
				string g[] = {"0?","?0"};
				_expected = 3;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 3:
			{
				string g[] = {"0??","?0?","??0"};
				_expected = 16;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 4:
			{
				string g[] = {"0???","?0??","??0?","???0"};
				_expected = 151;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			case 5:
			{
				string g[] = {"01111001000001101010101000111", "10101101010010111110010110001", "110110101101010100001000?1110", "10101100110110110001111110110", "1111010?100001010111001101010", "01011010101111010110001100111", "00100101110101101110111011011", "1100?010011101000010011100111", "00111110000011010111111100000", "01110011000011100111110110010", "00000101000111100011110001100", "00110111001010101101001111010", "01010100111101?10110110101101", "1010111111101010111001001010?", "110100100111?1011010111000100", "01111100100010101001111111001", "11000010000101110001101111111", "01001110110111000001111000100", "11001111111011100000100011010", "00011000111100011100111000011", "10110010111010111111011110001", "01010011111011110101101110011", "100111111001001111011100001?0", "01011101110110011000110000111", "01?10010010101011010110001111", "00101010001110011010000010001", "10110101001011101100001110001", "1011111101010000101101?110000", "1100011100001?011001110111100"};
				_expected = 224;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}
			/*case 6:
			{
				string g[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string g[] = ;
				_expected = ;
				_received = _obj.count(vector <string>(g, g+sizeof(g)/sizeof(string))); break;
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
