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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=50+4;
vector<vector<ll> > origv,v;
bool done[MAXN];
class StringGame {
	public:
	vector <int> getWinningStrings(vector <string> S) {
		ll n=S.size();
		v.resize(n);
		for (ll x=0;x<n;x++) {
			v[x].resize(26);
			ll m=S[x].length();
			for (ll y=0;y<m;y++) {
				ll c=S[x][y]-'a';
				v[x][c]++;
			}
		}
		origv=v;
		vector<int> ans;
		for (ll x=0;x<n;x++) {
			{
				ll numc=0, special=-1;
				bool dup=false;
				for (ll c=0;c<26;c++) {if(origv[x][c]>0) {numc++; special=c;}}
				for (ll y=0;y<n;y++) {
					if(x==y) continue;
					bool ok=false;
					for (ll c=0;c<26;c++) {
						if (c==special)continue;
						if (origv[y][c]>0) ok=true;
					}
					if (origv[y][special]>origv[x][special]) ok=true;
					if (!ok) dup=true;
				}
				if (dup) continue;
			}
			/*bool dup=false;
			for (ll y=0;y<n;y++) {
				if (x==y) continue;
				bool ok=false;
				for (ll c=0;c<26;c++) {
					if (origv[x][c]<origv[y][c]) {
						ok=true; break;
					}
				}
				if (!ok) dup=true;
			}
			if(dup) continue;*/
			v=origv;
			v.erase(v.begin()+x);
			for (ll c=0;c<26;c++) {
				done[c]=false;
			}
			while(1) {
				ll vsz=v.size();
				if (vsz==0) {
					ans.PB(x);
					break;
				}
				ll numc=0, special=-1;
				for (ll c=0;c<26;c++) {if(!done[c]) {numc++; special=c;}}
				if (numc==1) {
					bool ok=true;
					for (ll y=0;y<vsz;y++) {
						if (origv[x][special]>=v[y][special]) {
							ok=false; break;
						}
					}
					if(ok) {
						ans.PB(x);
						break;
					}
				}
				bool found=false;
				for (ll c=0;c<26;c++) {
					if (done[c]) continue;
					bool ok=true;
					for (ll y=0;y<vsz;y++) {
						if (origv[x][c]<v[y][c]) {
							ok=false; break;
						}
					}
					if (!ok) continue;
					vector<int> todel;
					for (ll y=vsz-1;y>=0;y--) {
						if (origv[x][c]>v[y][c]) {
							todel.PB(y);
						}
					}
					for (auto &w:todel) {
						v.erase(v.begin()+w);
					}
					done[c]=true;
					found=true;
					break;
				}
				if (!found) break;
			}
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
		cout << "Testing StringGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460307414;
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
		StringGame _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S[] = {"a", "b", "c", "d"};
				int __expected[] = {0, 1, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getWinningStrings(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 1:
			{
				string S[] = {"aabbcc", "aaabbb", "aaaccc"};
				int __expected[] = {1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getWinningStrings(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 2:
			{
				string S[] = {"ab", "ba"};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getWinningStrings(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 3:
			{
				string S[] = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"};
				int __expected[] = {1, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getWinningStrings(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 4:
			{
				string S[] = {"aa","a"};
				int __expected[] = {1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getWinningStrings(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 5:
			{
				string S[] = {"aacc","ac"};
				int __expected[] = {0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getWinningStrings(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 6:
			{
				string S[] = {"aac","ac"};
				int __expected[] = {0,1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getWinningStrings(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 7:
			{
				string S[] = {"a","a"};
				int __expected[] = {};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getWinningStrings(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 8:
			{
				string S[] = {"z","zzzzzz"};
				int __expected[] = {0};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getWinningStrings(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 9:
			{
				string S[] = {"yyzz","yyyzzz"};
				int __expected[] = {1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getWinningStrings(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
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
