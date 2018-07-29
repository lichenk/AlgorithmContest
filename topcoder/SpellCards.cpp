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
const ll MAXN=50+4;
ll f[MAXN][MAXN][MAXN];
class SpellCards {
	public:
	int maxDamage(vector <int> level, vector <int> damage) {
		ll n=level.size();
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<n;y++) {
				for (ll t=0;t<=n;t++) {
					f[x][y][t]=UNDEF;
				}
			}
		}
		for (ll x=0;x<n;x++) {
			f[x][x][0]=0;
		}
		ll final=0;
		for (ll s=0;s<n;s++) {
			for (ll x=0;x<n;x++) {
				ll y=(x+s)%n;
				for (ll t=0;t<=s;t++) {
					ll val=f[x][y][t];
					if (val==UNDEF) continue;
					chkmax(f[(x-1+n)%n][y][t+1],val);
					chkmax(f[x][(y+1)%n][t+1],val);
					ll castx=(x-1+n)%n;
					ll need=level[castx]-1;
					ll taket=min(need,t);
					ll newt=t-taket;
					ll needy=need-taket;
					if (1+needy+s>n) continue;
					ll newy=(y+needy)%n;
					if (castx!=newy) chkmax(f[castx][newy][newt],val+damage[castx]);
					//printf("%d %d %d to %d %d %d: %d+%d\n",x,y,t,castx,newy,newt,val,damage[castx]);
					chkmax(final,val+damage[castx]);
				}
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
		cout << "Testing SpellCards (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463349767;
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
		SpellCards _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int level[] = {1,1,1};
				int damage[] = {10,20,30};
				_expected = 60;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 1:
			{
				int level[] = {3,3,3};
				int damage[] = {10,20,30};
				_expected = 30;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 2:
			{
				int level[] = {4,4,4};
				int damage[] = {10,20,30};
				_expected = 0;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 3:
			{
				int level[] = {50,1,50,1,50};
				int damage[] = {10,20,30,40,50};
				_expected = 60;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 4:
			{
				int level[] = {2,1,1};
				int damage[] = {40,40,10};
				_expected = 80;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 5:
			{
				int level[] = {1,2,1,1,3,2,1};
				int damage[] = {10,40,10,10,90,40,10};
				_expected = 170;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			case 6:
			{
				int level[] = {1,2,2,3,1,4,2};
				int damage[] = {113,253,523,941,250,534,454};
				_expected = 1918;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}
			/*case 7:
			{
				int level[] = ;
				int damage[] = ;
				_expected = ;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int level[] = ;
				int damage[] = ;
				_expected = ;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int level[] = ;
				int damage[] = ;
				_expected = ;
				_received = _obj.maxDamage(vector <int>(level, level+sizeof(level)/sizeof(int)), vector <int>(damage, damage+sizeof(damage)/sizeof(int))); break;
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
