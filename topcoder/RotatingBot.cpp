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
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
const ll MAXN=2504;
bool g[MAXN][MAXN];
class RotatingBot {
	public:
	int minArea(vector <int> v) {
		ll n=v.size();
		if (n>=4) {
			ll sx,sy;
			ll xlim,ylim;
			{
				ll xl=0,yl=0;
				ll xh=0,yh=0;
				ll x=0,y=0,lok=0;
				for (ll k=0;k<n;k++) {
					x+=dx[k%4]*v[k];
					y+=dy[k%4]*v[k];
					chkmin(xl,x);
					chkmin(yl,y);
					chkmax(xh,x);
					chkmax(yh,y);
				}
				sx=-xl,sy=-yl;
				xlim=(xh-xl)+1; ylim=(yh-yl)+1;
			}
			ll sum=0;
			for (auto &w:v) {
				sum+=w;
			}
			vector<int> ans;
			ll cnt=0;
			ll k=0;
			for (ll x=0;x<MAXN;x++) for (ll y=0;y<MAXN;y++) g[x][y]=false;
			{
				ll nx=sx,ny=sy;
				if (!(nx>=0&&ny>=0&&nx<xlim&&ny<ylim&&!g[nx][ny])) return -1;
			}
			g[sx][sy]=true;
			bool turn=false;
			for (ll j=0;j<sum;) {
				g[sx][sy]=true;
				ll nx=sx+dx[k%4];
				ll ny=sy+dy[k%4];
				//printf("Try %lld %lld -> %lld %lld\n",sx,sy,nx,ny);
				if (nx>=0&&ny>=0&&nx<xlim&&ny<ylim&&!g[nx][ny]) {
					////printf("Go %lld %lld -> %lld %lld\n",sx,sy,nx,ny);
					sx=nx;sy=ny;
					cnt++;
					j++;
					turn=false;
				}
				else {
					if (turn) break;
					ans.PB(cnt);
					//printf("Turn %lld->%lld. PB %lld\n",k,(k+1)%4,cnt);
					cnt=0;
					k++; k%=4;
					turn=true;
				}
			}
			if (cnt) ans.PB(cnt);
			for (auto &w:ans) {
				//printf("%d ",w);
			}
			//printf(" end ans\n");
			if (ans==v) return xlim*ylim;
			else return -1;
		}
		else if (n==1) {
			return v[0]+1;
		}
		else if (n==2) {
			return (v[0]+1)*(v[1]+1);
		}
		else {
			return (1+max(v[0],v[2]))*(1+v[1]);
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
		cout << "Testing RotatingBot (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1469905098;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RotatingBot _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int moves[] = {15};
				_expected = 16;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 1:
			{
				int moves[] = {3,10};
				_expected = 44;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 2:
			{
				int moves[] = {1,1,1,1};
				_expected = -1;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 3:
			{
				int moves[] = {9,5,11,10,11,4,10};
				_expected = 132;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 4:
			{
				int moves[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
				_expected = 420;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 5:
			{
				int moves[] = {8,6,6,1};
				_expected = -1;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 6:
			{
				int moves[] = {8,6,6};
				_expected = 63;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 7:
			{
				int moves[] = {5,4,5,3,3};
				_expected = 30;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 8:
			{
				int moves[] = {1,1,2,1};
				_expected = 6;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			case 9:
			{
				int moves[] = {6,6,8,1};
				_expected = (6+1)*(8+1);
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
			}
			/*case 10:
			{
				int moves[] = ;
				_expected = ;
				_received = _obj.minArea(vector <int>(moves, moves+sizeof(moves)/sizeof(int))); break;
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
