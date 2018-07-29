#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
ll f[9][51][51][51];
class ThreeProgrammers {
	public:
	string validCodeHistory(string s) {
		ll n=s.length();
		for (ll k=0;k<=n;k++) {
			for (ll t=0;t<9;t++) {
				for (ll x=0;x<=k;x++) {
					for (ll y=0;y<=k-x;y++) {
						for (ll z=0;z<=k-x-y;z++) {
							f[t][x][y][z]=UNDEF;
						}
					}
				}
			}
		}
		f[0][0][0][0]=0;
		for (ll k=0;k<n;k++) {
			for (ll t=0;t<9;t++) {
				ll a[2]; a[0]=t/3; a[1]=t%3;
				for (ll i=0;i<3;i++) {
					bool good=true;
					for (ll j=0;j<i;j++) {
						if (i==a[j]) {good=false; break;}
					}
					if (!good) continue;
					ll nt=(t/3)+(i*3);
					for (ll x=0;x<=k;x++) {
						for (ll y=0;y<=k-x;y++) {
							for (ll z=0;z<=k-x-y;z++) {
								if (f[t][x][y][z]!=UNDEF) {
									if (i==0) {
										f[nt][x+1][y][z]=t;
									}
									else if (i==1) {
										f[nt][x][y+1][z]=t;
									}
									else {
										f[nt][x][y][z+1]=t;
									}
								}
							}
						}
					}
				}
			}
		}
		{
			ll x=0,y=0,z=0;
			for (ll i=0;i<n;i++) {
				if (s[i]=='A') x++;
				else if (s[i]=='B') y++;
				else if (s[i]=='C') z++;
			}
			for (ll t=0;t<9;t++) {
				if (f[t][x][y][z]!=UNDEF) {
					string ans="";
					while(x+y+z>0) {
						//printf("%d %d %d %d:%d\n",t,x,y,z,f[t][x][y][z]);
						ll last=t/3;
						t=f[t][x][y][z];
						if (last==0) {
							x--;
							ans+='A';
						}
						else if (last==1) {
							y--;
							ans+='B';
						}
						else if (last==2) {
							z--;
							ans+='C';
						}
						else assert(false);
					}
					reverse(ans.begin(),ans.end());
					return ans;
				}
			}
			return "impossible";
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
		cout << "Testing ThreeProgrammers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1462118960;
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
		ThreeProgrammers _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string code = "CAB";
				_expected = "BCA";
				_received = _obj.validCodeHistory(code); break;
			}
			case 1:
			{
				string code = "CBB";
				_expected = "BCB";
				_received = _obj.validCodeHistory(code); break;
			}
			case 2:
			{
				string code = "BB";
				_expected = "impossible";
				_received = _obj.validCodeHistory(code); break;
			}
			case 3:
			{
				string code = "BBA";
				_expected = "BAB";
				_received = _obj.validCodeHistory(code); break;
			}
			case 4:
			{
				string code = "CAC";
				_expected = "impossible";
				_received = _obj.validCodeHistory(code); break;
			}
			case 5:
			{
				string code = "ACAC";
				_expected = "CAAC";
				_received = _obj.validCodeHistory(code); break;
			}
			case 6:
			{
				string code = "ACABC";
				_expected = "ACABC";
				_received = _obj.validCodeHistory(code); break;
			}
			case 7:
			{
				string code = "BAABCABBCCACBAACABAABABBCCAACABCCAACCABCACACCBABAB";
				_expected = "BACBABCAACBACABCBACBACABCBACBACABCABCAACBACAACABCA";
				_received = _obj.validCodeHistory(code); break;
			}
			/*case 8:
			{
				string code = ;
				_expected = ;
				_received = _obj.validCodeHistory(code); break;
			}*/
			/*case 9:
			{
				string code = ;
				_expected = ;
				_received = _obj.validCodeHistory(code); break;
			}*/
			/*case 10:
			{
				string code = ;
				_expected = ;
				_received = _obj.validCodeHistory(code); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
