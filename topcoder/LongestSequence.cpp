#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<30ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll BASE=1000;
const ll mn=2002;
ll f(ll x, ll xmax, ll y, ll ymax) {
	if (x>y) {
		swap(x,y); swap(xmax,ymax);
	}
	ll seg=y-x;
	ll mindist=min(xmax,ymax)-y;
	ll last=y-seg;
	ll segmax=seg+mindist;
	if (mindist+1>=last) {
		segmax=min(xmax+seg,ymax);
	}
	if (segmax<seg) return UNDEF;
	return segmax;
}
ll vmax[mn];
class LongestSequence {
	public:
	int maxLength(vector <int> C) {
		ll imin=0,imax=INF;
		while(imin<imax) {
		//{
			ll imid=imin+(imax-imin)/2;
			//ll imid=17;
			priority_queue<pair<ll,ll> > pq;
			for (ll x=0;x<mn;x++) vmax[x]=UNDEF;
			for (auto &w:C) {
				ll wraw=w+BASE;
				if (imid>=abs(w)) {
					pq.push(MP(imid,wraw));
					vmax[wraw]=imid;
				}
			}
			while(!pq.empty()) {
				auto top=pq.top(); pq.pop();
				ll xmax=top.first; ll xraw=top.second;
				if (xmax<vmax[xraw]) continue;
				assert(xmax==vmax[xraw]);
				ll x=xraw-BASE;
				ll ylo,yhi;
				if (x>0) {ylo=-1000,yhi=-1;}
				else {ylo=1,yhi=1000;}
				for (ll y=ylo;y<=yhi;y++) {
					//printf("x:%lld y:%lld\n",x,y);
					if (abs(x)==abs(y)) continue;
					assert(x*y<0);
					ll yraw=y+BASE;
					ll ymax=vmax[yraw];
					if (ymax==UNDEF) continue;
					ll zmax=f(abs(x),xmax,abs(y),ymax);
					ll z=abs(abs(x)-abs(y));
					if (abs(x)>abs(y)&&x<0) z=-z;
					if (abs(y)>abs(x)&&y<0) z=-z;
					//printf("x:%lld xmax:%lld y:%lld ymax:%lld z:%lld zmax:%lld\n",x,xmax,y,ymax,z,zmax);
					ll zraw=z+BASE;
					if (vmax[zraw]<zmax) {
						pq.push(MP(zmax,zraw));
						vmax[zraw]=zmax;
					}
				}
			}
			bool ok=true;
			for (ll x=1;x<=1000;x++) {
				ll y=-x;
				ll xraw=x+BASE,yraw=y+BASE;
				if (vmax[xraw]!=UNDEF&&vmax[yraw]!=UNDEF) {
					ok=false;
				}
			}
			//printf("ok:%d\n",ok);
			if (ok) imin=imid+1;
			else imax=imid;
		}
		imin--;
		if (imin>=INF-100) return -1;
		else return imin;
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
		cout << "Testing LongestSequence (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472829827;
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
		LongestSequence _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int C[] = {-2,3};
				_expected = 3;
				_received = _obj.maxLength(vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 1:
			{
				int C[] = {524};
				_expected = -1;
				_received = _obj.maxLength(vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 2:
			{
				int C[] = {1, -1};
				_expected = 0;
				_received = _obj.maxLength(vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 3:
			{
				int C[] = {11,-7};
				_expected = 16;
				_received = _obj.maxLength(vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			case 4:
			{
				int C[] = {-227,690,590,-524};
				_expected = 713;
				_received = _obj.maxLength(vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}
			/*case 5:
			{
				int C[] = ;
				_expected = ;
				_received = _obj.maxLength(vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int C[] = ;
				_expected = ;
				_received = _obj.maxLength(vector <int>(C, C+sizeof(C)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int C[] = ;
				_expected = ;
				_received = _obj.maxLength(vector <int>(C, C+sizeof(C)/sizeof(int))); break;
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
