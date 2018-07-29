#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const int INF = 1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

const int mn=20000+1;
int f[mn];
int solve(vector<int> a, vector<int> cost, int K) {
	for (int x=0;x<mn;x++) f[x]=INF;
	f[0]=0;
	int n=a.size();
	for (int i=0;i<n;i++) {
		int v=a[i]-1;
		int c=cost[i];
		for (int x=mn-v-1;x>=0;x--) {
			if (f[x]<INF) {
				chkmin(f[x+v],f[x]+c);
			}
		}
	}
	int ans=INF;
	for (int x=K;x<mn;x++) chkmin(ans,f[x]);
	return ans;
}
class Unpacking {
	public:
	int getcost(vector <int> a, vector <int> b, vector <int> cost, int K) {
		for (int x=0;x<mn;x++) f[x]=INF;
		f[0]=0;
		int n=a.size();
		for (int i=0;i<n;i++) {
			int v=a[i]+b[i];
			int c=cost[i];
			for (int x=mn-v-1;x>=0;x--) {
				if (f[x]<INF) {
					chkmin(f[x+v],f[x]+c);
				}
			}
		}
		int ans=INF;
		for (int x=2*K-1;x<mn;x++) chkmin(ans,f[x]);
		int ans2=min(solve(a,cost,K),solve(b,cost,K));
		chkmin(ans,ans2);
		if (ans>=INF) ans=-1;
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
		cout << "Testing Unpacking (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1513964393;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Unpacking _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {6,5};
				int b[] = {4,4};
				int cost[] = {1,1};
				int K = 10;
				_expected = 2;
				_received = _obj.getcost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), K); break;
			}
			case 1:
			{
				int a[] = {5,5};
				int b[] = {4,4};
				int cost[] = {1,1};
				int K = 10;
				_expected = -1;
				_received = _obj.getcost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), K); break;
			}
			case 2:
			{
				int a[] = {10};
				int b[] = {5};
				int cost[] = {13};
				int K = 9;
				_expected = 13;
				_received = _obj.getcost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), K); break;
			}
			case 3:
			{
				int a[] = {1,2,3,4,5};
				int b[] = {1,2,3,4,5};
				int cost[] = {1,2,3,4,5};
				int K = 10;
				_expected = 10;
				_received = _obj.getcost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), K); break;
			}
			case 4:
			{
				int a[] = {1,2,3,4,15};
				int b[] = {1,2,3,4,5};
				int cost[] = {1,2,3,4,5};
				int K = 17;
				_expected = 9;
				_received = _obj.getcost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), K); break;
			}
			case 5:
			{
				int a[] = {82, 372, 114, 299, 549, 371, 541, 338, 358, 222, 592, 611, 463, 441, 242, 597, 467, 632, 302, 314, 361, 177, 46, 369, 78, 203, 612, 611, 263, 409, 427, 99, 341, 276, 228, 283, 355, 318, 46, 557, 355, 380, 469, 443, 359, 566, 410, 643, 550, 498};
				int b[] =  {292, 166, 240, 463, 394, 291, 158, 112, 372, 135, 520, 471, 10, 165, 196, 184, 108, 500, 408, 65, 104, 512, 425, 55, 583, 42, 58, 541, 638, 189, 574, 210, 595, 548, 98, 381, 130, 515, 86, 269, 59, 368, 490, 587, 241, 247, 225, 304, 164, 323};
				int cost[] = {453, 176, 24, 2, 1, 111, 99, 323, 119, 169, 176, 227, 272, 297, 437, 59, 237, 370, 165, 203, 225, 54, 237, 397, 248, 402, 312, 446, 445, 284, 6, 344, 146, 10, 444, 67, 80, 206, 25, 332, 399, 267, 57, 423, 318, 220, 443, 364, 436, 50};
				int K = 10000;
				_expected = 2894;
				_received = _obj.getcost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), K); break;
			}
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				int cost[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getcost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				int cost[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getcost(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int)), vector <int>(cost, cost+sizeof(cost)/sizeof(int)), K); break;
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
