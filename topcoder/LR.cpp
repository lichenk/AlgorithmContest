#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll INF=1e15+5;
class LR {
	public:
	string construct(vector<long long> _s, vector<long long> _t) {
		vector<ll> src;
		vector<ll> s[2];
		for (auto &w:_s) src.PB(w);
		int n=_s.size();
		for (int len=0;len<=100;len++) {
			for (int l=0;l<=len;l++) {
				bool ok=true;
				int r=len-l;
				int cur=0,nxt=1;
				s[cur]=src;
				s[nxt].resize(n);
				for (int step=0;step<l;step++) {
					for (int x=0;x<n;x++) {
						int left=x-1;
						if (left<0) left+=n;
						s[nxt][x]=s[cur][x]+s[cur][left];
						if (s[nxt][x]>INF) {ok=false; break;}
					}
					swap(cur,nxt);
				}
				for (int step=0;step<r;step++) {
					for (int x=0;x<n;x++) {
						int right=x+1;
						if (right>=n) right-=n;
						s[nxt][x]=s[cur][x]+s[cur][right];
						if (s[nxt][x]>INF) {ok=false; break;}
					}
					swap(cur,nxt);
				}
				if (ok&&s[cur]==_t) {
					string ans;
					for (int x=0;x<l;x++) ans+="L";
					for (int x=0;x<r;x++) ans+="R";
					return ans;
				}
			}
		}
		return "No solution";
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
		cout << "Testing LR (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1492703352;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LR _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long s[] = {0,1,0,0,0};
				long long t[] = {0,1,2,1,0};
				_expected = "LL";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 1:
			{
				long long s[] = {0,0,0,1};
				long long t[] = {0,1,0,0};
				_expected = "No solution";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 2:
			{
				long long s[] = {1,2,3,4,5,6,7,8,9,10};
				long long t[] = {12,24,56,95,12,78,0,100,54,88};
				_expected = "No solution";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 3:
			{
				long long s[] = {1,0,0};
				long long t[] = {11,11,10};
				_expected = "RRRRR";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 4:
			{
				long long s[] = {1,1};
				long long t[] = {562949953421312,562949953421312};
				_expected = "RLLLRRRLLRRRLRLRRLLLLRLLRRLRRRLRRLRRLLRRRLLRRRLLL";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 5:
			{
				long long s[] = {0,0,0,0,0};
				long long t[] = {0,0,0,1,0};
				_expected = "No solution";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			case 6:
			{
				long long s[] = {123,456};
				long long t[] = {123,456};
				_expected = "";
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}
			/*case 7:
			{
				long long s[] = ;
				long long t[] = ;
				_expected = ;
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}*/
			/*case 8:
			{
				long long s[] = ;
				long long t[] = ;
				_expected = ;
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
			}*/
			/*case 9:
			{
				long long s[] = ;
				long long t[] = ;
				_expected = ;
				_received = _obj.construct(vector<long long>(s, s+sizeof(s)/sizeof(long long)), vector<long long>(t, t+sizeof(t)/sizeof(long long))); break;
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
