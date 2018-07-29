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
class TheTips {
	public:
	double solve(vector <string> clues, vector <int> probability) {
		ll n=clues.size();
		for (ll x=0;x<n;x++) clues[x][x]='Y';
		for (ll k=0;k<n;k++) {
			for (ll x=0;x<n;x++) {
				for (ll y=0;y<n;y++) {
					if (clues[x][k]=='Y'&&clues[k][y]=='Y') {
						clues[x][y]='Y';
					}
				}
			}
		}
		ld ans=0.0;
		for (ll y=0;y<n;y++) {
			ld prob=1.0;
			for (ll x=0;x<n;x++) {
				if (clues[x][y]=='Y') {
					prob *= (1.0 - (ld)(probability[x])/100.0);
				}
			}
			//printf("%d: %f\n",(int)y,(double)(1.0-prob));
			ans+=1.0-prob;
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
		cout << "Testing TheTips (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1458964911;
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
		TheTips _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string clues[] = {"Y"};
				int probability[] = {50};
				_expected = 0.5;
				_received = _obj.solve(vector <string>(clues, clues+sizeof(clues)/sizeof(string)), vector <int>(probability, probability+sizeof(probability)/sizeof(int))); break;
			}
			case 1:
			{
				string clues[] = {"YN","NY"};
				int probability[] = {100,50};
				_expected = 1.5;
				_received = _obj.solve(vector <string>(clues, clues+sizeof(clues)/sizeof(string)), vector <int>(probability, probability+sizeof(probability)/sizeof(int))); break;
			}
			case 2:
			{
				string clues[] = {"YYY","NYY","NNY"};
				int probability[] = {100,0,0};
				_expected = 3.0;
				_received = _obj.solve(vector <string>(clues, clues+sizeof(clues)/sizeof(string)), vector <int>(probability, probability+sizeof(probability)/sizeof(int))); break;
			}
			case 3:
			{
				string clues[] = {"NNN","NNN","NNN"};
				int probability[] = {0,0,0};
				_expected = 0.0;
				_received = _obj.solve(vector <string>(clues, clues+sizeof(clues)/sizeof(string)), vector <int>(probability, probability+sizeof(probability)/sizeof(int))); break;
			}
			case 4:
			{
				string clues[] = {"NYYNYYNNNN","NNNNYNNNYN","YNNYYYYYNN","YYNYNNNNYN","NYNNNNNNNY","YNYYNNYNNY","NYNNYYYYYY","NYYYYNNNNN","YYNYNNYYYN","NNYYNYNYYY"};
				int probability[] = {11,66,99,37,64,45,21,67,71,62};
				_expected = 9.999891558057332;
				_received = _obj.solve(vector <string>(clues, clues+sizeof(clues)/sizeof(string)), vector <int>(probability, probability+sizeof(probability)/sizeof(int))); break;
			}
			case 5:
			{
				string clues[] = {"NNY","NNY","NNN"};
				int probability[] = {50, 50, 1};
				_expected = 1.7525;
				_received = _obj.solve(vector <string>(clues, clues+sizeof(clues)/sizeof(string)), vector <int>(probability, probability+sizeof(probability)/sizeof(int))); break;
			}
			/*case 6:
			{
				string clues[] = ;
				int probability[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(clues, clues+sizeof(clues)/sizeof(string)), vector <int>(probability, probability+sizeof(probability)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string clues[] = ;
				int probability[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(clues, clues+sizeof(clues)/sizeof(string)), vector <int>(probability, probability+sizeof(probability)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				string clues[] = ;
				int probability[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(clues, clues+sizeof(clues)/sizeof(string)), vector <int>(probability, probability+sizeof(probability)/sizeof(int))); break;
			}*/
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
