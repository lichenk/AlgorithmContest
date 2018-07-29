#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const int mn=10000+4;
int query(int *v, int l,int r) {
	return v[r]-v[l-1];
}
int a[2][mn];
int pa[2][mn];
ll p2a[2][mn];
class DrawingLines {
	public:
	double countLineCrossings(int n, vector <int> startDot, vector <int> endDot) {
		for (int t=0;t<2;t++) for (int x=1;x<=n;x++) a[t][x]=1;
		for (auto &x:startDot) a[0][x]=0;
		for (auto &x:endDot) a[1][x]=0;
		for (int t=0;t<2;t++) for (int x=1;x<=n;x++) pa[t][x]=pa[t][x-1]+a[t][x];
		for (int t=0;t<2;t++) {
			ll last=0;
			for (int x=1;x<=n;x++) {
				p2a[t][x]=p2a[t][x-1];
				if (a[t][x]) {
					p2a[t][x]+=last;
					last=pa[t][x];
				}
			}
		}
		int k=startDot.size();
		ld ans1=0,ans2=0,ans3=0,ans4=0;
		ld norm=(1.0L/(n-k));
		ld othernorm=(1.0L/(n-k))*(1.0L/(n-k-1));
		if ((n-k)*(ll)(n-k-1)!=0) {
			for (int x=1;x<=n;x++) {
				if (a[0][x]) {
					ld suf=query(pa[0],x+1,n);
					ld p2=p2a[1][n];
					ld contrib=(suf*p2);
					ans1+=contrib*othernorm;
				}
			}
		}
		if (n-k!=0) {
			for (int i=0;i<k;i++) {
				int x=startDot[i],y=endDot[i];
				ld suf=query(pa[0],x+1,n);
				ld pre=query(pa[1],1,y-1);
				ld contrib=suf*pre;
				ans2+=contrib*norm;
			}
			for (int i=0;i<k;i++) {
				int x=startDot[i],y=endDot[i];
				ld pre=query(pa[0],1,x-1);
				ld suf=query(pa[1],y+1,n);
				ld contrib=suf*pre;
				//printf("(%d,%d) pre:%f suf:%f contrib:%f\n",x,y,pre,suf,contrib);
				ans3+=contrib*norm;
			}
		}
		for (int i=0;i<k;i++) {
			int x1=startDot[i],y1=endDot[i];
			for (int j=0;j<k;j++) {
				int x2=startDot[j],y2=endDot[j];
				if (x2>x1&&y2<y1) {
					ans4+=1;
				}
			}
		}
		return ans1+ans2+ans3+ans4;
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
		cout << "Testing DrawingLines (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521177013;
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
		DrawingLines _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int startDot[] = {2};
				int endDot[] = {3};
				_expected = 1.5;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 5;
				int startDot[] = {1,4};
				int endDot[] = {3,1};
				_expected = 5.5;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 4;
				int startDot[] = {4,1};
				int endDot[] = {4,1};
				_expected = 0.5;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 8;
				int startDot[] = {1,4,3,6,7};
				int endDot[] = {1,3,2,4,5};
				_expected = 7.5;
				_received = _obj.countLineCrossings(n, vector <int>(startDot, startDot+sizeof(startDot)/sizeof(int)), vector <int>(endDot, endDot+sizeof(endDot)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 8;
				vector<int> startDot = {1,4,3,6,7};
				vector<int> endDot = {1,3,2,4,5};
				for (auto &w:startDot) w=9-w;
				for (auto &w:endDot) w=9-w;
				assert(startDot[0]==8);
				_expected = 7.5;
				_received = _obj.countLineCrossings(n, startDot, endDot); break;
			}
			case 5:
			{
				int n = 2;
				vector<int> startDot;
				vector<int> endDot;
				_expected = 0.5;
				_received = _obj.countLineCrossings(n, startDot, endDot); break;
			}
			case 6:
			{
				int n = 2;
				vector<int> startDot={1};
				vector<int> endDot={2};
				_expected = 1;
				_received = _obj.countLineCrossings(n, startDot, endDot); break;
			}
			case 7:
			{
				int n = 2;
				vector<int> startDot={2};
				vector<int> endDot={1};
				_expected = 1;
				_received = _obj.countLineCrossings(n, startDot, endDot); break;
			}
			case 8:
			{
				int n = 2;
				vector<int> startDot={1};
				vector<int> endDot={1};
				_expected = 0;
				_received = _obj.countLineCrossings(n, startDot, endDot); break;
			}
			case 9:
			{
				int n = 2;
				vector<int> startDot={2};
				vector<int> endDot={2};
				_expected = 0;
				_received = _obj.countLineCrossings(n, startDot, endDot); break;
			}
			case 10:
			{
				int n = 3;
				vector<int> startDot={1,2,3};
				vector<int> endDot={2,3,1};
				_expected = 2;
				_received = _obj.countLineCrossings(n, startDot, endDot); break;
			}
			case 11:
			{
				int n = 10000;
				vector<int> startDot={1,2,30};
				vector<int> endDot={2,3,10};
				_expected = -1;
				_received = _obj.countLineCrossings(n, startDot, endDot); break;
			}
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
