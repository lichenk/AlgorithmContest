#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
pair<ll,ll> p[1000];
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
struct rat { ll nu, de;
  rat(const ll &n = 0, const ll &d = 1) {
    ll g = gcd(abs(n), abs(d)); nu = n / g; de = d / g;
    if (de < 0) { nu = -nu; de = -de; } }
  rat operator+(const rat& b) const
  { return rat( nu*b.de+de*b.nu, de*b.de ); }
  rat operator-(const rat& b) const
  { return rat( nu*b.de-de*b.nu, de*b.de ); }
  rat operator-() { return rat(-nu, de); }
  rat operator*(const rat& b) const
  { return rat( nu*b.nu, de*b.de ); }
  rat operator/(const rat& b) const
  { return rat( nu*b.de, de*b.nu ); }
  ld getf() const {return ((ld)(nu))/((ld)(de));}
  bool operator== (const rat & b) const {return nu * b.de == b.nu * de;}
  bool operator== (const int &k) const { return nu == k * de; }
  bool operator< (const rat& b) const { return nu * b.de < b.nu * de; }
  bool operator> (const rat& b) const { return nu * b.de > b.nu * de; }
};

class ConsecutiveFloors {
	public:
	string isConsistent(vector <int> x, vector <int> y) {
		ll n=x.size();
		for (ll i=0;i<n;i++) {
			p[i]=MP(x[i],y[i]);
		}
		sort(p,p+n);
		bool ok=true;
		rat prev = rat(0x7fffffff,1);
		for (ll i=0;i<n-1;i++) {
			rat slope = rat(y[i]-y[i+1],x[i+1]-x[i]);
			ll slopeint = slope.nu/slope.de;
			if (!(slopeint>0 || (slopeint==0&&y[i]==0&&y[i+1]==0))) ok=false;
			if (!(slope<prev||slope==prev)) ok=false;
			prev=rat(slopeint,1);
		}
		if (ok) {
			return "Consistent";
		}
		else {
			return "Inconsistent";
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
		cout << "Testing ConsecutiveFloors (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455482325;
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
		ConsecutiveFloors _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {1, 2};
				int y[] = {3, 1};
				_expected = "Consistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {1, 3};
				int y[] = {2, 1};
				_expected = "Inconsistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1, 2, 3};
				int y[] = {6, 3, 1};
				_expected = "Consistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {1, 2, 3};
				int y[] = {6, 4, 1};
				_expected = "Inconsistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {1, 2, 3};
				int y[] = {30, 20, 10};
				_expected = "Consistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {477381380, 518025930, 570087601, 737384427};
				int y[] = {933387341, 532515987, 318113054, 112496297};
				_expected = "Consistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 6:
			{
				int x[] = {308943472, 309514623, 420739506, 433180054, 824938090};
				int y[] = {825002165, 692190478, 565185585, 520367469, 109640379};
				_expected = "Inconsistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 7:
			{
				int x[] = {120488476, 120910581, 191235701, 273389056, 325781420, 732516446};
				int y[] = {984130593, 891325429, 628742451, 440622881, 368262567, 198194666};
				_expected = "Inconsistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 8:
			{
				int x[] = {2,3};
				int y[] = {0,0};
				_expected = "Consistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 9:
			{
				int x[] = {2,3};
				int y[] = {1,1};
				_expected = "Inconsistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 10:
			{
				int x[] = {1, 3, 5};
				int y[] = {6, 4, 1};
				_expected = "Inconsistent";
				_received = _obj.isConsistent(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
