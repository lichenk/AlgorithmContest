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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
vector<string> f;
class GogoXCake {
	public:
	string solve(vector <string> wantedcake, vector <string> cutter) {
		f=wantedcake;
		for (auto &a:f) for (auto &b:a) b='X';
		ll fxlim=f.size(),fylim=f[0].length();
		ll cxlim=cutter.size(),cylim=cutter[0].length();
		for (ll fx=0;fx<fxlim-cxlim+1;fx++) for (ll fy=0;fy<fylim-cylim+1;fy++) {
			bool ok=true;
			for (ll cx=0;cx<cxlim;cx++) for (ll cy=0;cy<cylim;cy++) {
				if (cutter[cx][cy]=='.'&&
					(wantedcake[fx+cx][fy+cy]=='X'||f[fx+cx][fy+cy]=='.')
					) ok=false;
			}
			if (!ok) continue;
			//printf("OK:%d %d\n",fx,fy);
			for (ll cx=0;cx<cxlim;cx++) for (ll cy=0;cy<cylim;cy++) {
				if (cutter[cx][cy]=='.') f[fx+cx][fy+cy]='.';
			}
		}
		if (f==wantedcake) return "YES";
		else return "NO";
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
		cout << "Testing GogoXCake (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472014350;
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
		GogoXCake _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string cake[] = {"X.X"
				                ,"..."
				                ,"..."
				                ,"X.X"};
				string cutter[] = {".X"
				                  ,".."
				                  ,"X."};
				_expected = "YES";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 1:
			{
				string cake[] = {"..XX"
				                ,"...X"
				                ,"X..."
				                ,"XX.."};
				string cutter[] = {".."
				                  ,".."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 2:
			{
				string cake[] = {"...X..."};
				string cutter[] = {"..."};
				_expected = "YES";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 3:
			{
				string cake[] = {".X."
				                ,"X.X"
				                ,".X."};
				string cutter[] = {"."};
				_expected = "YES";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 4:
			{
				string cake[] = {"XXXXXXX"
				                ,"X.....X"
				                ,"X.....X"
				                ,"X.....X"
				                ,"XXXXXXX"};
				string cutter[] = {".X."
				                  ,"XXX"
				                  ,".X."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 5:
			{
				string cake[] = {".."
				                ,"X."
				                ,".X"};
				string cutter[] = {".."
				                  ,".X"
				                  ,"X."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			case 6:
			{
				string cake[] = {"X.."
				                ,".XX"
				                ,".XX"};
				string cutter[] = {".XX"
				                  ,".XX"
				                  ,"X.."};
				_expected = "NO";
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}
			/*case 7:
			{
				string cake[] = ;
				string cutter[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string cake[] = ;
				string cutter[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string cake[] = ;
				string cutter[] = ;
				_expected = ;
				_received = _obj.solve(vector <string>(cake, cake+sizeof(cake)/sizeof(string)), vector <string>(cutter, cutter+sizeof(cutter)/sizeof(string))); break;
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
