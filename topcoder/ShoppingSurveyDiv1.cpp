#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
vector<int> v;
int gshoppers;
int gK;
bool f(ll big) {
	ll n=v.size();
	for (ll i=0;i<n;i++) {
		v[i] = max(0, v[i]-big);
	}
	for (ll j=0;j<gshoppers-big;j++) {
		sort(v.begin(),v.end(),greater<int>());
		ll left = gK-1;
		for (ll i=0;i<n;i++) {
			if (left==0) break;
			if (v[i]==0) continue;
			else {
				//printf("Shopper %d takes %d\n",j,i);
				v[i]--;
				left--;
			}
		}
	}
	for (ll i=0;i<n;i++) {
		//printf("%d ",v[i]);
	}
	//printf("\n");
	for (ll i=0;i<n;i++) {
		if (v[i]>0) return false;
	}
	return true;
}

class ShoppingSurveyDiv1 {
	public:
	int minValue(int N, int K, vector <int> s) {
		gshoppers=N;
		gK=K;
		//v=s;
		//assert(!f(0));
		ll imin=0; ll imax=N+1;
		while (imin<imax) {
			ll imid=(imin+imax)/2;
			v=s;
			if (!f(imid)) {
				imin=imid+1;
			}
			else {
				imax=imid;
			}
		}
		return imin;
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
		cout << "Testing ShoppingSurveyDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455340144;
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
		ShoppingSurveyDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 10;
				int K = 2;
				int s[] = {1, 2, 3};
				_expected = 0;
				_received = _obj.minValue(N, K, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 5;
				int K = 2;
				int s[] = {1, 2, 3};
				_expected = 1;
				_received = _obj.minValue(N, K, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 4;
				int K = 4;
				int s[] = {4, 4, 4, 2};
				_expected = 2;
				_received = _obj.minValue(N, K, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 20;
				int K = 3;
				int s[] = {1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3};
				_expected = 10;
				_received = _obj.minValue(N, K, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 4;
				int K = 2;
				int s[] = {1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1};
				_expected = 2;
				_received = _obj.minValue(N, K, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 2;
				int K = 3;
				int s[] = {1, 1, 1, 2};
				_expected = 1;
				_received = _obj.minValue(N, K, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int K = ;
				int s[] = ;
				_expected = ;
				_received = _obj.minValue(N, K, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				int s[] = ;
				_expected = ;
				_received = _obj.minValue(N, K, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int K = ;
				int s[] = ;
				_expected = ;
				_received = _obj.minValue(N, K, vector <int>(s, s+sizeof(s)/sizeof(int))); break;
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
