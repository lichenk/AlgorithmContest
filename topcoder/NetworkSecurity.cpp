#include <bits/stdc++.h>
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
bitset<50> f[50];
class NetworkSecurity {
	public:
	int secureNetwork(vector <string> cc, vector <string> cs) {
		ll nc=cc.size();
		ll ns=cs[0].size();
		for (ll x=0;x<nc;x++) {
			for (ll y=0;y<nc;y++) {
				f[x][y]=(cc[x][y]=='Y');
			}
			f[x][x]=true;
		}
		for (ll z=0;z<nc;z++)for (ll x=0;x<nc;x++) for (ll y=0;y<nc;y++) {
			if (f[x][z]&&f[z][y]) f[x][y]=true;
		}
		ll ans=0;
		for (ll s=0;s<ns;s++) {
			bitset<50> goodc;
			goodc.reset();
			for (ll c=0;c<nc;c++) {
				goodc[c]=(cs[c][s]=='Y');
				//if (s==0) printf("c:%d got:%d\n",c,goodc[c]?1:0);
			}
			for (ll c=0;c<nc;c++) {
				for (ll d=0;d<nc;d++) {
					//if (s==0)printf("c:%d d:%d f:%d\n",c,d,f[c][d]?1:0);
					if (d!=c&&f[c][d]&&goodc[d]) {
						goodc[c]=false;
						//if (c==3) printf("c:%d zeroed out by d:%d\n",c,d);
					}
				}
			}
			//assert(goodc[3]);
			ans+=goodc.count();
		}
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
		cout << "Testing NetworkSecurity (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491406714;
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
		NetworkSecurity _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string clientCable[] = {"NYN"
				                       ,"NNN"
				                       ,"NYN"};
				string serverCable[] = {"YN"
				                       ,"YN"
				                       ,"NY"};
				_expected = 2;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
			}
			case 1:
			{
				string clientCable[] = {"NN"
				                       ,"NN"};
				string serverCable[] = {"NNN"
				                       ,"NNN"};
				_expected = 0;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
			}
			case 2:
			{
				string clientCable[] = {"NYNN"
				                       ,"NNNN"
				                       ,"NNNY"
				                       ,"NNNN"};
				string serverCable[] = {"YYN"
				                       ,"NNN"
				                       ,"NNY"
				                       ,"NNN"};
				_expected = 3;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
			}
			case 3:
			{
				string clientCable[] = {
					"NYYY",
					"NNYY",
					"NNNY",
					"NNNN"
				};
				string serverCable[] = {
					"YYYYNNNNNNN",
					"YYYNYYYNNNN",
					"YYNNYYNYYNN",
					"YNNNYNNYNYY"
				};
				_expected = 11;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
			}
			/*case 4:
			{
				string clientCable[] = ;
				string serverCable[] = ;
				_expected = ;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string clientCable[] = ;
				string serverCable[] = ;
				_expected = ;
				_received = _obj.secureNetwork(vector <string>(clientCable, clientCable+sizeof(clientCable)/sizeof(string)), vector <string>(serverCable, serverCable+sizeof(serverCable)/sizeof(string))); break;
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
