#include "bits/stdc++.h"
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
bool g[46][46];
void ae(int x, int y) {
	if (x==y) return;
	g[x][y]=1; g[y][x]=1;
}
int check(bitset<46> b) {
	int ans=0;
	for (int x=0;x<46;x++) {
		if (b[x]==0) continue;
		for (int y=0;y<x;y++) {
			if (b[y]==0) continue;
			if (g[x][y]) ans++;
		}
	}
	return ans;
}
class Subgraphs {
	public:
	vector <string> findGroups(int k) {
		memset(g,0,sizeof g);
		for (int x=0;x<k;x++) {
			for (int y=0;y<k;y++) {
				if (x!=y) ae(x,y);
			}
		}
		for (int x=k;x<2*k;x++) {
			for (int y=x-k;y<k;y++) {
				ae(x,y);
			}
		}
		vector<string> ans;
		for (int x=0;x<2*k;x++) {
			string s; s.resize(2*k);
			for (int y=0;y<2*k;y++) {
				s[y]=(g[x][y]?'1':'0');
			}
			ans.PB(s);
		}
		int id=0;
		for (int s=1;s<=k;s++) {
			assert(id==(s*(s-1))/2);
			for (int d=0;d<s;d++) {
				bitset<46> b; b.reset();
				for (int x=0;x<s;x++) b[x]=true;
				int rem=k-s;
				b[2*k-rem-d]=true;
				for (int x=2*k-1;x>=2*k-rem+1;x--) {
					b[x]=true;
				}
				string ss; ss.resize(2*k);
				for (int x=0;x<2*k;x++) {
					ss[x]=b[x]?'Y':'N';
				}
				//cout<<ss<<endl;
				//assert(b.count()==k);
				ans.PB(ss);
				int got=check(b);
				assert(got==id);
				//if (got!=id) {
					//printf("%s\ngot:%d id:%d\n",ss.c_str(),got,id);
				//}
				++id;
				if (id>(k*(k-1))/2) break;
			}
			if (id>(k*(k-1))/2) break;
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
		cout << "Testing Subgraphs (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1520205858;
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
		Subgraphs _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int k = 2;
				string __expected[] = {"010", "100", "000", "NYY", "YYN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGroups(k); break;
			}
			case 1:
			{
				int k = 3;
				string __expected[] = {"000000000000", "000000000000", "000000000000", "000010000000", "000100000000", "000000000000", "000000011000", "000000100000", "000000100000", "000000000011", "000000000101", "000000000110", "YYYNNNNNNNNN", "NNNYYYNNNNNN", "NNNNNNYYYNNN", "NNNNNNNNNYYY" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGroups(k); break;
			}
			case 2:
			{
				int k = 4;
				string __expected[] = {"01111000", "10111100", "11011110", "11101111", "11110000", "01110000", "00110000", "00010000", "YNNNNYYY", "YYNNNNYY", "YNYNNNYY", "YNYNNYYN", "YNYNYYNN", "YNYYNYNN", "YYYYNNNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGroups(k); break;
			}
			case 3:
			{
				int k = 23;
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGroups(k); break;
			}
			/*case 4:
			{
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGroups(k); break;
			}*/
			/*case 5:
			{
				int k = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.findGroups(k); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
