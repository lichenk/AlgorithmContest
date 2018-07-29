#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<28ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXC=27;
ll f[2][MAXC][MAXC];
ll g[MAXC][MAXC][MAXC];
class StringWeight {
	public:
	int getMinimum(vector <int> L) {
		for (ll a=0;a<MAXC;a++) {
			for (ll b=0;b<MAXC-a;b++) {
				f[1][a][b]=INF;
			}
		}
		f[1][26][0]=0;
		ll lsz=L.size();
		for (ll j=0;j<lsz;j++) {
			ll w=L[j];
			ll gones=min(w,26);
			ll glast=UNDEF;
			if (w>26) {gones--; glast=w-25;}
			w=min(L[j],26);
			for (ll _l=0;_l<=w;_l++) {
				for (ll _m=0;_m<=w-_l;_m++) {
					for (ll _r=0;_r<=w-_l-_m;_r++) {
						ll ln=_l,rn=_r;
						ll cost=0; ll lpos=0,rpos=0;
						ll ones=gones,last=glast;
						while(1) {
							if (ln+rn==0) break;
							ll k=ones?1:last;
							if (ln>=rn) {
								ln--;
								lpos+=k;
								cost+=lpos;
							}
							else {
								rn--;
								rpos+=k;
								cost+=(rpos-1);
							}
							ones--;
						}
						ll m=_m;
						while(m>0) {
							ll k=ones?1:last;
							m--;
							cost+=(k-1);
							ones--;
						}
						g[_l][_m][_r]=cost;
					}
				}
			}
			for (ll a=0;a<MAXC;a++) {
				for (ll b=0;b<MAXC-a;b++) {
					f[j&1][a][b]=INF;
				}
			}
			for (ll a=0;a<MAXC;a++) {
				for (ll b=0;b<MAXC-a;b++) {
					ll c=26-a-b;
					assert(c>=0);
					ll val=f[(j&1)^1][a][b];
					if (val==INF) continue;
					//printf("j:%d a:%d b:%d val:%d\n",j-1,a,b,val);
					for (ll l=0;l<=w;l++) {
						for (ll m=0;m<=w-l;m++) {
							if (l+m+b<w) continue;
							if (l+m>a) continue;
							ll rlim=min(w-l-m,b);
							for (ll r=0;r<=rlim;r++) {
								ll pass=(b-r)*L[j];
								assert(a-l-m>=0);
								assert(b-r>=0);
								chkmin(f[j&1][a-l-m][b+l-r],val+g[l][m][r]+pass);
							}
						}
					}
				}
			}
		}
		{
			ll ans=INF;
			ll j=(L.size()-1)&1;
			for (ll a=0;a<MAXC;a++) {
				for (ll b=0;b<MAXC-a;b++) {
					ans=min(ans,f[j][a][b]);
				}
			}
			return ans;
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
		cout << "Testing StringWeight (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460930400;
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
		StringWeight _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L[] = {1};
				_expected = 0;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 1:
			{
				int L[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 1;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 2:
			{
				int L[] = {26, 2, 2};
				_expected = 8;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 3:
			{
				int L[] = {25, 25, 25, 25};
				_expected = 1826;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 4:
			{
				int L[] = {14, 6, 30, 2, 5, 61};
				_expected = 1229;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 5:
			{
				int L[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = 2;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 6:
			{
				int L[] = {1,27};
				_expected = 2;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 7:
			{
				int L[] = {14,6,30};
				_expected = 284;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 8:
			{
				int L[] = {30, 7, 61};
				_expected = 897;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 9:
			{
				int L[] = {26, 1, 26};
				_expected = 702;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 10:
			{
				int L[] = {27, 1, 27};
				_expected = 704;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 11:
			{
				int L[] = {28, 1, 29};
				_expected = 707;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 12:
			{
				int L[] = {27, 1, 28};
				_expected = 705;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 13:
			{
				int L[] = {27, 28};
				_expected = 679;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
			}
			case 14:
			{
				int L[] = {27, 27};
				_expected = 678;
				_received = _obj.getMinimum(vector <int>(L, L+sizeof(L)/sizeof(int))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
