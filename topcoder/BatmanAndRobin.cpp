#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pll point;
typedef pair<ld,ld> pointd;
#define fst first
#define snd second
vector<point> vp;
long long ccw(point a, point b, point c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	return b.first * (long long)c.second - c.first * (long long)b.second;
}

vector<point> convexHull(vector<point> dat) {
	if (dat.size()<=2) return dat;
	vector<point> upper, lower;
	sort(dat.begin(), dat.end());
	for(ll i = 0; i < dat.size(); i++) {
		while(upper.size() >= 2 && ccw(*++upper.rbegin(),*upper.rbegin(),dat[i]) >= 0) upper.pop_back();
		while(lower.size() >= 2 && ccw(*++lower.rbegin(),*lower.rbegin(),dat[i]) <= 0) lower.pop_back();
		upper.emplace_back(dat[i]);
		lower.emplace_back(dat[i]);
	}
	upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
	return upper;
}

ld shoelace(vector<point> ch) {
	ll n=ch.size();
	if (n<=2) return 0;
	ld ans=0;
	for (ll i=0;i<n;i++) {
		ans+=ch[i].fst*ch[(i+1)%n].snd;
		ans-=ch[i].fst*ch[(i-1+n)%n].snd;
	}
	ans=fabs(ans)/2;
	return ans;
}

ld ccwd(pointd a, pointd b, pointd c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	return b.first * c.second - c.first * b.second;
}

ld solve(ll a, ll b) {
	vector<point> ga,gb;
	for (ll i=0;i<vp.size();i++) {
		ll gotccw=ccw(vp[a],vp[i],vp[b]);
		if (gotccw>0) {
			ga.PB(vp[i]);
		}
		else if (gotccw<0) {
			gb.PB(vp[i]);
		}
		else {
			if ((vp[i].fst-vp[a].fst)*(vp[b].fst-vp[a].fst)>0||
				  (vp[i].snd-vp[a].snd)*(vp[b].snd-vp[a].snd)>0
				) {
				// On b's side
				gb.PB(vp[i]);
			}
			else ga.PB(vp[i]);
		}
	}
	vector<point> cha=convexHull(ga),chb=convexHull(gb);
	ld ansa=shoelace(cha);
	ld ansb=shoelace(chb);
	return max(ansa,ansb);
}

class BatmanAndRobin {
	public:
	double minArea(vector <int> _px, vector <int> _py) {
		ll n=_px.size();
		if (n<=4) return 0;
		for (ll i=0;i<n;i++) vp.PB(MP(_px[i],_py[i]));
		ld final=INF;
		for (ll a=0;a<n;a++) {
			for (ll b=0;b<n;b++) {
				if (a==b) continue;
				chkmin(final,solve(a,b));
			}
		}
		return final;
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
		cout << "Testing BatmanAndRobin (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487951967;
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
		BatmanAndRobin _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {100,100,90,90,-100,-100,-90,-90};
				int y[] = {100,90,100,90,-100,-90,-100,-90};
				_expected = 100.0;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {-1000,-1000,1000,1000,1000,-1000};
				int y[] = {-1000,1000,-1000,1000,0,0};
				_expected = 0.0;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {-1000,-1000,1000,1000,0};
				int y[] = {-1000,1000,-1000,1000,0};
				_expected = 1000000.0;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {-904,-812,-763,-735,-692,-614,-602,-563,-435,-243,-87,-52,-28,121,126,149,157,185,315,336,390,470,528,591,673,798,815,837,853,874};
				int y[] = {786,10,-144,949,37,-857,-446,-969,-861,-712,5,-972,-3,-202,-845,559,-244,-542,-421,422,526,-501,-791,-899,-315,281,-275,467,743,-321};
				_expected = 1067472.0;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {0};
				int y[] = {0};
				_expected = 0;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
