#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 3008
ll a[MAXN],b[MAXN];
class ANewHope {
	public:
	int count(vector <int> first, vector <int> last, int d) {
		int n = first.size();
		bool good = true;
		for (int i=0; i <n; i++) {
			if (first[i]!=last[i]) {
				good = false;
			}
		}
		if (good) return 1;
		for (int i=0; i<n;i++) {
			first[i]--;
			last[i]--;
		}
		int *firstOrder = new int[n];
		int *lastOrder = new int[n];
		for (int i=0;i<n;i++) {
			firstOrder[first[i]]=i;
			lastOrder[last[i]]=i;
		}
		int result = 1;
		for (int j=0; j<n; j++) {
			int f = firstOrder[j];
			int l = lastOrder[j];
			int count=1;
			for (int i=0; i<100000;i++) {
				count++;
				f = f+d;
				if (f<n) break;
				f %= n;
				if (f<=l) break;
			}
			result = max(result,count);
		}
		return result;
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
		cout << "Testing ANewHope (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1452650404;
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
		ANewHope _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int firstWeek[] = {1,2,3,4};
				int lastWeek[] = {4,3,2,1};
				int D = 3;
				_expected = 4;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			case 1:
			{
				int firstWeek[] = {8,5,4,1,7,6,3,2};
				int lastWeek[] = {2,4,6,8,1,3,5,7};
				int D = 3;
				_expected = 3;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			case 2:
			{
				int firstWeek[] = {1,2,3,4};
				int lastWeek[] = {1,2,3,4};
				int D = 2;
				_expected = 1;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			case 3:
			{
				int firstWeek[] = {1};
				int lastWeek[] = {1};
				int D = 0;
				_expected = 1;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			case 4:
			{
				int firstWeek[] = {2,1};
				int lastWeek[] = {1,2};
				int D = 1;
				_expected = 2;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			case 5:
			{
				int firstWeek[] = {3,2,1};
				int lastWeek[] = {1,2,3};
				int D = 2;
				_expected = 3;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			case 6:
			{
				int firstWeek[] = {1,2,3,4,5};
				int lastWeek[] = {3,4,5,1,2};
				int D = 3;
				_expected = 2;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			case 7:
			{
				int firstWeek[] = {1,2,3,4,5};
				int lastWeek[] = {5,1,2,3,4};
				int D = 4;
				_expected = 5;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
			}
			case 8:
			{
				int firstWeek[2500];
				int lastWeek[2500];
				for (int i = 0; i < 2500; i++) {
					firstWeek[i] = i+1;
				}
				for (int i = 0; i < 2500; i++) {
					lastWeek[i] = i;
				}
				lastWeek[0] = 2500;
				int D = 2499;
				_expected = 5;
				_received = _obj.count(vector <int>(firstWeek, firstWeek+sizeof(firstWeek)/sizeof(int)), vector <int>(lastWeek, lastWeek+sizeof(lastWeek)/sizeof(int)), D); break;
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
