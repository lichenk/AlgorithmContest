#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
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
const int mn=50;
class Point3 {
public:
	typedef ll T;
	T x,y,z;
	Point3() {x=0;y=0;z=0;}
	Point3(T ox,T oy,T oz) {
		x=ox; y=oy; z=oz;
	}
  Point3 sub(Point3 a, Point3 b) {
      return Point3(a.x-b.x,a.y-b.y,a.z-b.z);
  }
	Point3 cross(Point3 a, Point3 b, Point3 c) {
    Point3 p = sub(b,a), q = sub(c,a);
    return Point3(p.y*q.z-p.z*q.y, p.z*q.x-p.x*q.z, p.x*q.y-p.y*q.x);
  }
  T normSquared() {
  	return x*x+y*y+z*z;
  }
  ld norm() {
    ld m = max(fabs(x),max(fabs(y),fabs(z)));
    ld dx = x / m, dy = y / m, dz = z / m;
    return sqrt(dx*dx+dy*dy+dz*dz) * m;
  }
  ld normFast() {
  	return sqrt((ld)normSquared()); // Watch for overflow!
  }
  Point3 normalize() {
  	ld normval = norm();
  	return Point3(x/normval,y/normval,z/normval);
  }
  Point3 normalizeFast() {
  	ld normval = normFast();
  	return Point3(x/normval,y/normval,z/normval);
  }
	T dot(Point3 a, Point3 b) { return a.x*b.x+a.y*b.y+a.z*b.z;}
	T dot(const Point3& b) { return x*b.x+y*b.y+z*b.z;}
	Point3 operator+(const Point3& b) const {return Point3(x+b.x,y+b.y,z+b.z);}
  Point3 operator-(const Point3& b) const {return Point3(x-b.x,y-b.y,z-b.z);}
  Point3 operator*(const T& c) const {return Point3(x*c,y*c,z*c);}
	Point3 &operator+=(Point3 b) { x+=b.x; y+=b.y; z+=b.z; return *this; }
	Point3 &operator-=(Point3 b) { x-=b.x; y-=b.y; z-=b.z; return *this; }
	Point3 operator-() const { return Point3(-x,-y,-z); }
};

ll bf(vector <int> vx, vector <int> vy, vector <int> vz) {
	ll final=0;
	int n=vx.size();
	vector<Point3> vo(n);
	for (int i=0;i<n;i++) {
		vo[i]=Point3(vx[i],vy[i],vz[i]);
	}
	Point3 sum(0,0,0); for (auto &w:vo) sum-=w;
	for (auto &w:vo) w+=w;
	int zlim=min(1LL<<n,(ll)INT_MAX);
	for (int z=0;z<zlim;z++) {
		Point3 got=sum;
		for (int i=0;i<n;i++) {
			if (z&(1<<i)) got+=vo[i]; 
		}
		chkmax(final,got.normSquared());
	}
	return final;
}

Point3 vd[]={
	Point3(0,0,0),Point3(1,0,0),Point3(0,1,0),Point3(0,0,1),
	Point3(-1,0,0),Point3(0,-1,0),Point3(0,0,-1),
};

ll smart(vector <int> vx, vector <int> vy, vector <int> vz) {
		int n=vx.size();
		vector<Point3> vo(n);
		for (int i=0;i<n;i++) {
			vo[i]=Point3(vx[i],vy[i],vz[i]);
		}

		ll final=0;
		if (n<3) {
			Point3 sum(0,0,0); for (auto &w:vo) sum-=w;
			for (auto &w:vo) w+=w;
			int zlim=min(1LL<<n,(ll)INT_MAX);
			for (int z=0;z<zlim;z++) {
				Point3 got=sum;
				for (int i=0;i<n;i++) {
					if (z&(1<<i)) got+=vo[i]; 
				}
				chkmax(final,got.normSquared());
			}
			return final;
		}

		//for (int i=1;i<n;i++) {
		//	if (vo[0].dot(vo[i])<0) vo[i]=-vo[i];
		//}
		for (int a=0;a<n;a++) for (int b=0;b<a;b++) for (int c=0;c<b;c++) {
			for (int da=0;da<4;da++) {
				for (int db=0;db<4;db++) {
					for (int dc=0;dc<7;dc++) {
						for (int k=0;k<4;k++) {
							Point3 aa=vo[a]+vd[da];
							Point3 bb=vo[b]+vd[db];
							Point3 cc=vo[c]+vd[dc];
							Point3 cross=cross.cross(
								(k==1)?aa:-aa,
								(k==2)?bb:-bb,
								(k==3)?cc:-cc
								);
							Point3 chosen(0,0,0);
							for (int i=0;i<n;i++) {
								if (cross.dot(vo[i])>0) {
									chosen+=vo[i];
								}
								else {
									chosen-=vo[i];
								}
							}
							chkmax(final,chosen.normSquared());
						}
					}
				}
			}
		}
		return final;
	}
void test() {
	vector<int> vx,vy,vz;
	ll seed=clock();
	srand(seed);
	int n=rand()%10;
	for (int i=0;i<n;i++) {
		int x=(rand()%100)-50;
		int y=(rand()%100)-50;
		int z=(rand()%100)-50;
		if (x==0&&y==0&&z==0) x=1;
		vx.PB(x);vy.PB(y);vz.PB(z);
	}
	ll sm=smart(vx,vy,vz);
	ll bb=bf(vx,vy,vz);
	if(sm!=bb) {
		for (auto &x:vx) printf("%d ",x); printf("\n");
		for (auto &x:vy) printf("%d ",x); printf("\n");
		for (auto &x:vz) printf("%d ",x); printf("\n");
		printf("sm:%lld bb:%lld seed:%lld\n",sm,bb,seed);
	}
	//printf("seed:%lld n:%d\n",seed,n);
}
class ConstructPolyline {
	public:
	long long maximizeLength(vector <int> vx, vector <int> vy, vector <int> vz) {
		for (int k=0;k<5000;k++) test();
		return smart(vx,vy,vz);
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
		cout << "Testing ConstructPolyline (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1520829374;
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
		ConstructPolyline _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {10,15,-5,-10};
				int y[] = {20,5,-20,5};
				int z[] = {5,-5,0,15};
				_expected = 3425LL;
				_received = _obj.maximizeLength(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(z, z+sizeof(z)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {51,23,350,-18,-69,200};
				int y[] = {-100,-50,1,45,-69,-70};
				int z[] = {211,-245,56,566,23,24};
				_expected = 1559907LL;
				_received = _obj.maximizeLength(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(z, z+sizeof(z)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1,-1,2,-2,3,-3,4,-4,5,-5,6,-6};
				int y[] = {0,0,0,0,0,0,0,0,0,0,0,0};
				int z[] = {0,0,0,0,0,0,0,0,0,0,0,0};
				_expected = 1764LL;
				_received = _obj.maximizeLength(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(z, z+sizeof(z)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {-368,-473,135,50,-125,82,-204,272};
				int y[] = {401,-153,39,-283,-37,-40,-347,-358};
				int z[] = {-91,-271,450,427,359,396,359,92};
				_expected = 8705702LL;
				_received = _obj.maximizeLength(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(z, z+sizeof(z)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {10,10,10};
				int y[] = {21,21,21};
				int z[] = {-5,-5,-5};
				_expected = 5094LL;
				_received = _obj.maximizeLength(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(z, z+sizeof(z)/sizeof(int))); break;
			}
			case 5:
			{
				vector<int> v[3];
				for (int i=0;i<50;i++) {
					for (int t=0;t<3;t++) v[t].PB((rand()%20000) - 10000);
				}
				_expected = 84449092214LL;
				_received = _obj.maximizeLength(v[0],v[1],v[2]); break;
			}
			case 6:
			{
				int x[] = {-415, -485, 467, -211, -328, 7, 123, -160, 153, 245, -385, 62, 479, -163, -206, 435, 419, 153, -297, 280, 91, -322, 374, -334, -390, 41, -446, 195, -234, -385, -176, -374, 412, -463, 46, -318, 47, -149, -245, -106, 311, -391, -233, 173, -271, 133, -29, -299, -46, 393};
				int y[] = {-186, -225, 29, -326, 467, -333, -157, -235, -312, -158, -54, -498, 222, -216, 315, 261, -294, 213, 257, -322, 391, -76, -229, 343, 77, -479, -410, 240, -26, -161, 202, -202, 289, 463, -471, -354, -313, 120, -416, -476, 211, 204, 472, -277, 192, -312, 7, 340, 449, -49};
				int z[] = {415, -351, -112, -243, -114, 79, 279, 320, -126, -407, -125, -375, -233, -26, -314, -242, -207, -498, 217, -321, -408, -425, 149, 135, -281, 306, -400, -478, -380, -38, 208, -130, 390, -316, -306, 409, 237, 356, 39, 448, -424, -356, 286, -410, 214, -90, -35, 342, 17, 370};
				_expected = 182064050LL;
				_received = _obj.maximizeLength(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(z, z+sizeof(z)/sizeof(int))); break;
			}
			case 7:
			{
				int x[] = {10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000, 10000, -10000};
				int y[] = {10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000, -10000, -10000, 10000, 10000};
				int z[] = {10000, 10000, 10000, 10000, -10000, -10000, -10000, -10000, 10000, 10000, 10000, 10000, -10000, -10000, -10000, -10000, 10000, 10000, 10000, 10000, -10000, -10000, -10000, -10000, 10000, 10000, 10000, 10000, -10000, -10000, -10000, -10000, 10000, 10000, 10000, 10000, -10000, -10000, -10000, -10000, 10000, 10000, 10000, 10000, -10000, -10000, -10000, -10000, 10000, 10000};
				_expected = 250400000000LL;
				_received = _obj.maximizeLength(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(z, z+sizeof(z)/sizeof(int))); break;
			}
			case 8:
			{
				int x[] = {1};
				int y[] = {0};
				int z[] = {0};
				_expected = 1LL;
				_received = _obj.maximizeLength(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), vector <int>(z, z+sizeof(z)/sizeof(int))); break;
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
