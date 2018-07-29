#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<29ULL;
const ll UNDEF = INF;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll f[2504],cst[2504][2504];
class EllysString {
	public:
	int theMin(vector <string> _s, vector <string> _t) {
		string s,t; for (auto &w:_s) s+=w; for (auto &w:_t) t+=w;
		ll n=s.length();
		for (auto &w:s) w-='a';
		for (auto &w:t) w-='a';
		for (ll x=0;x<n;x++) {
			vector<ll> a[26],b[26];
			ll la[26],lb[26];
			for (ll c=0;c<26;c++) {la[c]=0;lb[c]=0;}
			ll cost=0;
			for (ll y=x+1;y<=n;y++) {
				a[s[y-1]].PB(y-1);
				b[t[y-1]].PB(y-1);
				bool ok=true;
				for (ll c=0;c<26;c++) {
					if (a[c].size()!=b[c].size()) {ok=false; break;}
					ll sz=a[c].size();
					for (ll i=la[c];i<sz;i++) {
						cost+=abs(a[c][i]-b[c][i]);
					}
					la[c]=sz;
				}
				if (ok) cst[x][y]=cost/2;
				else cst[x][y]=INF;
				//printf("%d->%d has cost %lld\n",x,y,cst[x][y]);
			}
		}
		for (ll x=0;x<=n;x++) f[x]=INF;
		f[0]=0;
		for (ll x=0;x<n;x++) {
			ll v=f[x]; if (v==INF) continue;
			for (ll y=x+1;y<=n;y++) {
				chkmin(f[y],v+cst[x][y]);
			}
			chkmin(f[x+1],v+1);
		}
		return f[n];
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
		cout << "Testing EllysString (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471742478;
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
		EllysString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s[] = {"usagi"};
				string t[] = {"unagi"};
				_expected = 1;
				_received = _obj.theMin(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 1:
			{
				string s[] = {"unagi"};
				string t[] = {"nugai"};
				_expected = 2;
				_received = _obj.theMin(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 2:
			{
				string s[] = {"ellys", "string"};
				string t[] = {"e", "ll", "ysst", "ring"};
				_expected = 0;
				_received = _obj.theMin(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 3:
			{
				string s[] = {"fox"};
				string t[] = {"xfo"};
				_expected = 2;
				_received = _obj.theMin(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 4:
			{
				string s[] = {"salmon"};
				string t[] = {"camlon"};
				_expected = 2;
				_received = _obj.theMin(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 5:
			{
				string s[] = {"boajxuidva"};
				string t[] = {"jcayduvida"};
				_expected = 6;
				_received = _obj.theMin(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 6:
			{
				string s[] = {"vykdnujyezbcbmnatipqfuxqmgkvtn"};
				string t[] = {"qokbqyujeqcbwsinatupqfoegmvkdz"};
				_expected = 22;
				_received = _obj.theMin(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 7:
			{
				string s[] = {"ackwgkbskceehauirbgkagkshiuafdkv"};
				string t[] = {"bckwgksbkceeahlirgbkamkshiaufkdv"};
				_expected = 8;
				_received = _obj.theMin(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			case 8:
			{
				string s[] = {"xyab"};
				string t[] = {"axby"};
				_expected = 3;
				_received = _obj.theMin(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <string>(t, t+sizeof(t)/sizeof(string))); break;
			}
			/*case 9:
			{
				string s[] = ;
				string t[] = ;
				_expected = ;
				_received = _obj.theMin(vector <string>(s, s+sizeof(s)/sizeof(string)), vector <string>(t, t+sizeof(t)/sizeof(string))); break;
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
