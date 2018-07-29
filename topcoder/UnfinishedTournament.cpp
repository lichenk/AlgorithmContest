#include "bits/stdc++.h"
//#include <assert.h>
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

vector<int> orig;
vector<int> f;
vector<int> ques;
int n;
inline int varForWins(int w) {
	int ans=2*w-(n-1);
	return ans*ans;
}
inline int varForX(int x) {
	return varForWins(__builtin_popcount(f[x]));
}
inline int varForN() {
	int ans=0;
	for (int x=0;x<n;x++) {ans+=varForX(x);}
	return ans;
}
vector<string> succ() {
		vector<string> ans(n);
		for (int x=0;x<n;x++) {
			ans[x].resize(n);
			for (int y=0;y<n;y++) ans[x][y]=(f[x]&(1<<y))?'W':'L';
			ans[x][x]='-';
		}
		return ans;
}
vector<int> p;
class UnfinishedTournament {
	public:
	vector <string> construct(vector <string> inp, int ix) {
		clock_t start=clock();
		n=inp.size();
		orig.resize(n);
		for (int x=0;x<n;x++) {
			for (int y=0;y<n;y++) {
				if (inp[x][y]=='W') orig[x]|=(1<<y);
				if (x<y&&inp[x][y]=='?') ques.PB((x<<16)|y);
			}
		}
		int D=2*(n-1); int D2=D*D*n;
		int HI=((ix+20000)*(ll)D2)/1000000;
		int LO=(((ix-20000)*(ll)D2)+1000000-1)/1000000;
		int qsz=ques.size();
		p.resize(qsz);
		for (int x=0;x<qsz;x++) p[x]=x;
		while(1) {
			clock_t now=clock();
			if (now-start > 1.75 * CLOCKS_PER_SEC) return {};
			f=orig;
			srand(clock());
			for (int i=0;i<ques.size();i+=16) {
				int jlim=min((int)ques.size(),i+16);
				int rd=rand();
				for (int j=i;j<jlim;j++) {
					int w=ques[j];int x=w>>16,y=w&((1<<16)-1);
					if (rd&1) {
						f[x]|=1<<y;
					}
					else {
						f[y]|=1<<x;
					}
					rd>>=1;
				}
			}
			int var=varForN();
			if (LO<=var&&var<=HI) return succ();
			for (int k=0;k<10;k++) {
				clock_t seed=clock();
				if (seed-start > 1.75 * CLOCKS_PER_SEC) return {};
				srand(seed); random_shuffle(p.begin(),p.end());
				for (int ei=0;ei<qsz;ei++) {
					int ep=ques[p[ei]];
					int x=ep>>16,y=ep&((1<<16)-1);
					if (f[x]&(1<<y)) swap(x,y);
					int xc=__builtin_popcount(f[x]),yc=__builtin_popcount(f[y]);
					int delta=(varForWins(xc+1)+varForWins(yc-1))-(varForWins(xc)+varForWins(yc));
					bool flip=(delta==0)||(delta>0&&var<LO)||(delta<0&&var>HI);
					if (flip) {
						f[x]^=1<<y; f[y]^=1<<x;
						var+=delta;
						if (LO<=var&&var<=HI) return succ();
					}
				}
			}
		}
		return {};
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
		cout << "Testing UnfinishedTournament (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1518801311;
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
		UnfinishedTournament _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string G[] = {"-??",
				              "?-?",
				              "?\?-"};
				int x = 20000;
				string __expected[] = {"-WL", "L-W", "WL-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
			}
			case 1:
			{
				string G[] = {"-??",
				              "?-?",
				              "?\?-"};
				int x = 166666;
				string __expected[] = {"-WW", "L-W", "LL-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
			}
			case 2:
			{
				string G[] = {"-??",
				              "?-?",
				              "??-"};
				int x = 100000;
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
			}
			case 3:
			{
				string G[] = {"-LW?",
				              "W-??",
				              "L?-W",
				              "??L-"};
				int x = 70000;
				string __expected[] = {"-LWW", "W-LW", "LW-W", "LLL-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
			}
			case 4:
			{
				string G[] = {"-WL?WL??LL","L-???WWLW?","W?-??L?LL?","???-???LLL","L???-?LW?L","WLW??-?WWW","?L??W?-L?W","?WWWLLW-?W","WLWW?L??-?","W??WWLLL?-"};
				int x = 54321;
				string __expected[] = {"-WLLWLLLLL", "L-LLWWWLWW", "WW-LLLLLLL", "WWW-LWLLLL", "LLWW-LLWLL", "WLWLW-WWWW", "WLWWWL-LLW", "WWWWLLW-LW", "WLWWWLWW-W", "WLWWWLLLL-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
			}
			case 5:
			{
				string G[] = {"-?",
				              "?-"};
				int x = 1000000;
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
			}
			case 6:
			{
				string G[] = {"-??",
				              "?-?",
				              "??-"};
				int x = 166666+20000;
				string __expected[] = {"-WW", "L-W", "LL-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
			}
			case 7:
			{
				string G[] = {"-??",
				              "?-?",
				              "??-"};
				int x = 166666-20000;
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
			}
			case 8:
			{
				string G[] = {"-??",
				              "?-?",
				              "??-"};
				int x = 166667-20000;
				string __expected[] = {"-WW", "L-W", "LL-" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
			}
			case 9:
			{
				string G[] = {"-??",
				              "?-?",
				              "??-"};
				int x = 166667+20000;
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
			}
			case 10:
			{
				string G[] = {"-??W???????????????", "?-????W?????W???W??", "??-???????????????L", "L??-???????W???????", "????-?W??????W????W", "?????-???????L??W??", "?L??L?-L???????????", "??????W-???W???????", "????????-L???W???W?", "????????W-?W???????", "??????????-????????", "???L???L?L?-???????", "?L??????????-?W????", "????LW??L????-?????", "????????????L?-????", "???????????????-L??", "?L???L?????????W-??", "????????L????????-L", "??W?L????????????W-"};
				int x = 228434;
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <string>(G, G+sizeof(G)/sizeof(string)), x); break;
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
