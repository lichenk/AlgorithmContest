#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
//typedef long double ld;
typedef double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ld EPS=1e-11;
inline int flr(ld x) {
	return floor(x+EPS);
}
const int BASE=300;
ld vans[2*BASE][2*BASE];
ld vansx[2*BASE][2*BASE];
ld vansy[2*BASE][2*BASE];
bool mark[2*BASE][2*BASE];
bool markx[2*BASE][2*BASE];
bool marky[2*BASE][2*BASE];
inline bool eq(ld x, ld y) {
	return fabs(x-y)<EPS;
}
void f(int ox, int ex, int oy, int ey, int gen, int vert) {
	//if (gen==5) printf("%d %d %d %d %d %d\n",ox,ex,oy,ey,gen,vert);
	int genleft=500-gen;
	if (genleft<0) return;
	int len=abs(ex-ox);
	if (len==1) {
		ld contrib=genleft/3.0L;
		int px=min(ox,ex);
		if (vert) {
			vansx[BASE+oy][BASE+px]+=1; //if (markx[BASE+oy][BASE+ox]) {printf("A\n");printf("%d %d %d %d %d %d\n",ox,ex,oy,ey,gen,vert);}
			vans[BASE+oy][BASE+px]+=contrib+1; //if (mark[BASE+oy][BASE+ox]) {printf("B\n");printf("%d %d %d %d %d %d\n",ox,ex,oy,ey,gen,vert);}
			vans[BASE+oy-1][BASE+px]+=contrib; //if (mark[BASE+oy-1][BASE+ox]) {printf("C\n");printf("%d %d %d %d %d %d\n",ox,ex,oy,ey,gen,vert);}
		}
		else {
			vansy[BASE+px][BASE+oy]+=1; //if (marky[BASE+ox][BASE+oy]) {printf("D\n"); printf("%d %d %d %d %d %d\n",ox,ex,oy,ey,gen,vert);}
			vans[BASE+px][BASE+oy]+=contrib+1; //if (mark[BASE+ox][BASE+oy]) {printf("E\n"); printf("%d %d %d %d %d %d\n",ox,ex,oy,ey,gen,vert);}
			vans[BASE+px][BASE+oy-1]+=contrib; //if (mark[BASE+ox][BASE+oy-1]) {printf("F\n"); printf("%d %d %d %d %d %d\n",ox,ex,oy,ey,gen,vert);}
		}
	}
	else {
		int nx=(ox+2*ex)/3;
		int lx=min(ox,nx),rx=max(ox,nx);
		int fy=flr(oy);
		for (int x=lx;x<=rx;x++) {
			int got=min(rx,(x+1))-max(lx,x);
			if (vert) vans[BASE+fy][BASE+x]+=got;
			else vans[BASE+x][BASE+fy]+=got;
			if (vert) vansx[BASE+fy][BASE+x]+=got;
			else vansy[BASE+x][BASE+fy]+=got;
		}
		f(nx,ex,oy,oy,gen+1,vert);
		f(oy,oy+len/3,nx,nx,gen+1,vert^1);
		f(oy,oy-len/3,nx,nx,gen+1,vert^1);
	}
}
class FractalPicture {
	public:
	double getLength(int x1, int y1, int x2, int y2) {
		for (int x=x1;x<x2;x++) for (int y=y1;y<y2;y++) mark[BASE+x][BASE+y]=1;
		for (int x=x1;x<x2;x++) marky[BASE+x][BASE+y2]=1;
		for (int y=y1;y<y2;y++) markx[BASE+x2][BASE+y]=1;
		//f(0,1,0,0,1,1);
		f(0,81,0,0,1,1);
		ld final=0;
		for (int x=x1;x<x2;x++) for (int y=y1;y<y2;y++) final+=vans[BASE+x][BASE+y];
		for (int x=x1;x<x2;x++) final+=vansy[BASE+x][BASE+y2];
		for (int y=y1;y<y2;y++) final+=vansx[BASE+x2][BASE+y];
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
		cout << "Testing FractalPicture (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1500918218;
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
		FractalPicture _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x1 = -1;
				int y1 = 0;
				int x2 = 1;
				int y2 = 53;
				_expected = 53.0;
				_received = _obj.getLength(x1, y1, x2, y2); break;
			}
			case 1:
			{
				int x1 = 1;
				int y1 = 1;
				int x2 = 10;
				int y2 = 10;
				_expected = 0.0;
				_received = _obj.getLength(x1, y1, x2, y2); break;
			}
			case 2:
			{
				int x1 = -10;
				int y1 = 54;
				int x2 = 10;
				int y2 = 55;
				_expected = 21.0;
				_received = _obj.getLength(x1, y1, x2, y2); break;
			}
			case 3:
			{
				int x1 = 14;
				int y1 = 45;
				int x2 = 22;
				int y2 = 54;
				_expected = 2999.0;
				_received = _obj.getLength(x1, y1, x2, y2); break;
			}
			case 4:
			{
				int x1 = 0;
				int y1 = 0;
				int x2 = 0;
				int y2 = 2;
				_expected = 2.0;
				_received = _obj.getLength(x1, y1, x2, y2); break;
			}
			case 5:
			{
				int x1 = -27;
				int y1 = 54;
				int x2 = 27;
				int y2 = 54;
				_expected = 54;
				_received = _obj.getLength(x1, y1, x2, y2); break;
			}
			case 6:
			{
				int x1 = -9;
				int y1 = 72;
				int x2 = 9;
				int y2 = 72;
				_expected = 18;
				_received = _obj.getLength(x1, y1, x2, y2); break;
			}
			case 7:
			{
				int x1 = 0;
				int y1 = 80;
				int x2 = 1;
				int y2 = 81;
				_expected = 332.0;
				_received = _obj.getLength(x1, y1, x2, y2); break;
			}
			/*
			case 7:
			{
				int x1 = -1;
				int y1 = 0;
				int x2 = 1;
				int y2 = 1;
				_expected = 1+(499*2)/3.0L;
				_received = _obj.getLength(x1, y1, x2, y2); break;
			}
			case 8:
			{
				int x1 = -1;
				int y1 = 0;
				int x2 = 0;
				int y2 = 1;
				_expected = 1+(499*1)/3.0L;
				_received = _obj.getLength(x1, y1, x2, y2); break;
			}
			case 9:
			{
				int x1 = 0;
				int y1 = 0;
				int x2 = 0;
				int y2 = 1;
				_expected = 1;
				_received = _obj.getLength(x1, y1, x2, y2); break;
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
