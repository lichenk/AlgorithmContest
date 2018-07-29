#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<28;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll mp=8;
const ll mk=mp*2+1;
const ll mz=1<<mk;
ll f[mz],g[mz];
vector<int> a,r;
ll asz;
bool dbg=false;
bool valid(ll x, ll z) {
	ll ans=0;
	for (ll y=x-mp;y<=x+mp;y++) {
		if ((z&1)&&0<=y&&y<asz) {
			ans+=a[y]>>abs(y-x);
		}
		z>>=1;
	}
	//if (x==1&&r[x]-ans<=0) {
	//	printf("x:%d z:%d\n",x,z);
	//}
	return r[x]-ans<=0;
}
class Bribes {
	public:
	int minBribes(vector <int> _a, vector <int> _r) {
		a=_a;r=_r;
		ll n=a.size();
		asz=n;
		for (ll z=0;z<mz;z++) f[z]=__builtin_popcount(z);
		for (ll x=0;x<n;x++) {
			//for (ll z=0;z<mz;z++) g[z]=INF;
			fill(g,g+mz,INF);
			//bool ok=false;
			for (ll z=0;z<mz;z++) {
				if (!valid(x,z)||f[z]==INF) continue;
				//printf("x:%d z:%d f:%d\n",x,z,f[z]);
				for (ll nxt=0;nxt<2;nxt++) {
					ll nz=(z>>1)|(nxt<<(mk-1));
					chkmin(g[nz],f[z]+nxt);
				}
				//ok=true;
			}
			/*if (!ok) {
				dbg=true;
				printf("x:%d\n",x);
				valid(x,mz-1);
				break;
			}*/
			swap(f,g);
		}
		ll ans=INF;
		for (ll z=0;z<mz;z++) {
			chkmin(ans,f[z]);
		}
		if (ans>=INF) return -1;
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
		cout << "Testing Bribes (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1488263776;
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
		Bribes _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int influence[] = { 10, 3, 5, 3, 1 };
				int resistance[] = { 11, 2, 7, 3, 1 };
				_expected = 2;
				_received = _obj.minBribes(vector <int>(influence, influence+sizeof(influence)/sizeof(int)), vector <int>(resistance, resistance+sizeof(resistance)/sizeof(int))); break;
			}
			case 1:
			{
				int influence[] = { 15, 15, 15 };
				int resistance[] = { 13, 42, 13 };
				_expected = -1;
				_received = _obj.minBribes(vector <int>(influence, influence+sizeof(influence)/sizeof(int)), vector <int>(resistance, resistance+sizeof(resistance)/sizeof(int))); break;
			}
			case 2:
			{
				int influence[] = { 10, 16, 4, 7, 1, 1, 13 };
				int resistance[] = { 10, 16, 4, 7, 1, 1, 13 };
				_expected = 4;
				_received = _obj.minBribes(vector <int>(influence, influence+sizeof(influence)/sizeof(int)), vector <int>(resistance, resistance+sizeof(resistance)/sizeof(int))); break;
			}
			case 3:
			{
				int influence[] = { 479, 340, 398, 40, 477, 181, 422, 377, 60, 486, 15, 500, 307, 1, 2, 65, 411, 374, 446, 401 };
				int resistance[] = { 402, 87, 20, 76, 468, 493, 252, 98, 216, 58, 89, 500, 89, 26, 8, 125, 269, 116, 426, 81 };
				_expected = 7;
				_received = _obj.minBribes(vector <int>(influence, influence+sizeof(influence)/sizeof(int)), vector <int>(resistance, resistance+sizeof(resistance)/sizeof(int))); break;
			}
			case 4:
			{
				int influence[] = { 21, 196, 401, 157, 9, 497, 371, 84, 395, 495, 401, 190, 465, 359, 47, 441, 245, 487, 118, 405 };
				int resistance[] = { 127, 313, 376, 94, 66, 37, 237, 142, 315, 495, 257, 153, 437, 339, 483, 356, 16, 132, 231, 342 };
				_expected = 8;
				_received = _obj.minBribes(vector <int>(influence, influence+sizeof(influence)/sizeof(int)), vector <int>(resistance, resistance+sizeof(resistance)/sizeof(int))); break;
			}
			case 5:
			{
				int influence[] = {0,0,4,0,0,0,4};
				int resistance[] ={1,2,4,2,2,2,4};
				_expected = 2;
				_received = _obj.minBribes(vector <int>(influence, influence+sizeof(influence)/sizeof(int)), vector <int>(resistance, resistance+sizeof(resistance)/sizeof(int))); break;
			}
			case 6:
			{
				int influence[] = {409, 260, 205, 320, 446, 167, 368, 288, 57, 448, 284, 332, 84, 224, 19, 221};
				int resistance[] = {224, 435, 487, 459, 307, 201, 193, 33, 475, 22, 223, 377, 449, 483, 277, 112};
				_expected = 13;
				_received = _obj.minBribes(vector <int>(influence, influence+sizeof(influence)/sizeof(int)), vector <int>(resistance, resistance+sizeof(resistance)/sizeof(int))); break;
			}
			case 7:
			{
				int influence[] = {409, 260, 205, 320, 446, 167, 368, 288, 57, 448, 284, 332, 84, 224, 19, 221,409, 260, 205, 320, 446, 167, 368, 288, 57, 448, 284, 332, 84, 224, 19, 221,409, 260, 205, 320, 446, 167, 368, 288, 57, 448, 284, 332, 84, 224, 19, 221};
				int resistance[] = {224, 435, 487, 459, 307, 201, 193, 33, 475, 22, 223, 377, 449, 483, 277, 112,224, 435, 487, 459, 307, 201, 193, 33, 475, 22, 223, 377, 449, 483, 277, 112,224, 435, 487, 459, 307, 201, 193, 33, 475, 22, 223, 377, 449, 483, 277, 112};
				_expected = 13;
				_received = _obj.minBribes(vector <int>(influence, influence+sizeof(influence)/sizeof(int)), vector <int>(resistance, resistance+sizeof(resistance)/sizeof(int))); break;
			}
			/*case 7:
			{
				int influence[] = ;
				int resistance[] = ;
				_expected = ;
				_received = _obj.minBribes(vector <int>(influence, influence+sizeof(influence)/sizeof(int)), vector <int>(resistance, resistance+sizeof(resistance)/sizeof(int))); break;
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
