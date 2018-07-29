#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const int INF = 1<<20;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
string s;
int slen;
vector<int> f[2];

int go(int dot, int need, int other) {
	if (need==0&&f[dot].size()>0) return INF;
	int ans1=0;
	for (auto &ox:f[dot]) {
		int x=ox;
		if (x>=need) {
			ans1+=((x/need)-1)*other;
			x%=need;
			if (x!=0) ans1+=need-x+other;
		}
		else {
			ans1+=need-x;
		}
		//printf("x:%d need:%d ans1:%d\n",ox,need,ans1);
	}
	return ans1;
}

int solve(int w, int a, int head) {
	int rhs=head-a;
	int C=max(0,(head-a)/w);
	if (C*w+a<head) C++;
	return C*w+a-head;
}

class Subrectangle {
	public:
	int minMissed(string _S) {
		clock_t start = clock();
		s=_S;
		slen=s.length();
		int head=0;
		for (auto &c:s) {
			if (c=='#') break;
			head++;
		}
		if (head==slen) {
			// All dots
			return 1;
		}
		int tail=0;
		for (int i=slen-1;i>=0;i--) {
			if (s[i]=='#') break;
			tail++;
		}
		{
			int cum=0;
			int dot=0;
			for (int i=head;i<slen-tail;i++) {
				char c=s[i];
				//printf("i:%d %c %d\n",i,c,cum);
				if (i==head||c!=s[i-1]) {
					if(cum>0) {
						f[dot].PB(cum);
					}
					cum=1;
					dot^=1;
				}
				else cum++;
			}
			if (cum>0) {f[dot].PB(cum);}
		}
		int best=INF;
		for (int w=1;w<=40000;w++) {
		//for (int w=4;w<=4;w++) {
			for (int d=1;d<=w;d++) {
				//if (d!=2) continue;
				if (clock()-start > 1.75 * CLOCKS_PER_SEC) return best;
				int plus=INF;
				for (int a=0;a<=w-d;a++) {
					int b=w-d-a;
					int cand1=solve(w,a,head);
					int cand2=solve(w,b,tail);
					int cand=cand1+cand2;
					chkmin(plus,cand);
				}
				int ans1=go(1,d,w-d);
				int ans0=go(0,w-d,d);
				int ans=ans0+ans1+plus;
				//if (ans==4) printf("w:%d d:%d plus:%d ans1:%d ans0:%d\n",w,d,plus,ans1,ans0);
				chkmin(best,ans);
			}
		}
		return best;
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
		cout << "Testing Subrectangle (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515975245;
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
		Subrectangle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "..###.##";
				_expected = 2;
				_received = _obj.minMissed(S); break;
			}
			case 1:
			{
				string S = "#.##.#.#..";
				_expected = 2;
				_received = _obj.minMissed(S); break;
			}
			case 2:
			{
				string S = "####";
				_expected = 0;
				_received = _obj.minMissed(S); break;
			}
			case 3:
			{
				string S = "";
				_expected = 1;
				_received = _obj.minMissed(S); break;
			}
			case 4:
			{
				string S = "........................................";
				_expected = 1;
				_received = _obj.minMissed(S); break;
			}
			case 5:
			{
				string S = "###...###";
				_expected = 3;
				_received = _obj.minMissed(S); break;
			}
			case 6:
			{
				string S = ".#.###.##...#.####.###...###.##";
				_expected = 15;
				_received = _obj.minMissed(S); break;
			}
			case 7:
			{
				string S = ".................................................##..##...##..............................";
				_expected = 5;
				_received = _obj.minMissed(S); break;
			}
			/*case 8:
			{
				string S = ;
				_expected = ;
				_received = _obj.minMissed(S); break;
			}*/
			/*case 9:
			{
				string S = ;
				_expected = ;
				_received = _obj.minMissed(S); break;
			}*/
			/*case 10:
			{
				string S = ;
				_expected = ;
				_received = _obj.minMissed(S); break;
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
