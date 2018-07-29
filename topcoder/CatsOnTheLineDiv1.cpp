#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
pair<ll,ll> p[1000];
const ll INF = 0x7fffffff;
ll f[2][1008][1008];
class CatsOnTheLineDiv1 {
	public:
	int getNumber(vector <int> position, vector <int> count, int tim) {
		ll n=position.size();
		map<ll,ll,greater<ll> > h;
		for (ll i=0;i<n;i++) {
			p[i]=MP(position[i],count[i]);
		}
		sort(p,p+n);
		for (ll i=0;i<n;i++) {
			h[p[i].first]=i;
		}
		for (ll t=0;t<2;t++) {
			for (ll i=0;i<=n+2;i++) {
				for (ll j=0;j<=n+2;j++) {
					f[t][i][j] = INF;
				}
			}
		}
		f[0][0][0] = -INF;
		for (ll x=0;x<n;x++) {
			ll pos = p[x].first;
			ll cnt = p[x].second;
			for (ll t=0;t<2;t++) {
				for (ll y=0;y<=n;y++) {
					ll last = f[t][x][y];
					if (last>=INF) continue;
					{
						ll center = pos+tim;
						ll rightbound = pos+2*tim;
						auto it = h.lower_bound(rightbound);
						//printf("Goto %lld of %lld for center %lld\n",it->second,n,center);
						f[1][it->second+1][y+1] = center;
					}
					{
						ll bestleft = max(pos-tim, last+1);
						ll bestright = bestleft + cnt-1;
						//printf("x:%lld y:%lld bl:%lld br:%lld\n",x,y,bestleft,bestright);
						if (bestright - pos > tim) continue;
						f[0][x+1][y] = bestright;
					}
				}
			}
		}
		ll final=INF;
		for (ll t=0;t<2;t++) {
			for (ll y=0;y<=n;y++) {
				if (f[t][n][y] < INF) final=min(final,y);
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
		cout << "Testing CatsOnTheLineDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455342034;
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
		CatsOnTheLineDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int position[] = {0};
				int count[] = {7};
				int time = 3;
				_expected = 0;
				_received = _obj.getNumber(vector <int>(position, position+sizeof(position)/sizeof(int)), vector <int>(count, count+sizeof(count)/sizeof(int)), time); break;
			}
			case 1:
			{
				int position[] = {0};
				int count[] = {6};
				int time = 2;
				_expected = 1;
				_received = _obj.getNumber(vector <int>(position, position+sizeof(position)/sizeof(int)), vector <int>(count, count+sizeof(count)/sizeof(int)), time); break;
			}
			case 2:
			{
				int position[] = {4, 7, 47};
				int count[] = {4, 7, 4};
				int time = 1;
				_expected = 3;
				_received = _obj.getNumber(vector <int>(position, position+sizeof(position)/sizeof(int)), vector <int>(count, count+sizeof(count)/sizeof(int)), time); break;
			}
			case 3:
			{
				int position[] = {3, 0, 7, 10};
				int count[] = {3, 7, 4, 5};
				int time = 2;
				_expected = 2;
				_received = _obj.getNumber(vector <int>(position, position+sizeof(position)/sizeof(int)), vector <int>(count, count+sizeof(count)/sizeof(int)), time); break;
			}
			case 4:
			{
				int position[] = {-5, 0, 7};
				int count[] = {47, 85, 10};
				int time = 6;
				_expected = 1;
				_received = _obj.getNumber(vector <int>(position, position+sizeof(position)/sizeof(int)), vector <int>(count, count+sizeof(count)/sizeof(int)), time); break;
			}
			case 5:
			{
				int position[] = {-8, 12, -15, -20, 17, -5, 7, 10};
				int count[] = {20, 10, 7, 9, 2, 8, 11, 10};
				int time = 2;
				_expected = 5;
				_received = _obj.getNumber(vector <int>(position, position+sizeof(position)/sizeof(int)), vector <int>(count, count+sizeof(count)/sizeof(int)), time); break;
			}
			case 6:
			{
				int position[] = {527, -279, -793, 900, 637, 542, 1, 826, 201, 877, -968, 88, 815, 618, -195, -982, -976, -335, 915, -288, -778, -432, 340, -482, -56, -22, 300, -930, 562, -276, -792, 510, 281, 352, 341, -617, 87, -42, -143, 13, -783, 839, 454, 356, 760, -473, -898, -481, 282, -269};
				int count[] = {750, 871, 338, 234, 714, 647, 1185, 249, 1154, 445, 211, 773, 973, 391, 911, 323, 510, 684, 296, 525, 149, 684, 1169, 142, 170, 1005, 561, 46, 845, 176, 510, 764, 228, 332, 538, 821, 1279, 321, 1263, 1101, 723, 814, 557, 1114, 729, 862, 437, 1195, 1050, 279};
				int time = 824;
				_expected = 1;
				_received = _obj.getNumber(vector <int>(position, position+sizeof(position)/sizeof(int)), vector <int>(count, count+sizeof(count)/sizeof(int)), time); break;
			}
			/*case 7:
			{
				int position[] = ;
				int count[] = ;
				int time = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(position, position+sizeof(position)/sizeof(int)), vector <int>(count, count+sizeof(count)/sizeof(int)), time); break;
			}*/
			/*case 8:
			{
				int position[] = ;
				int count[] = ;
				int time = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(position, position+sizeof(position)/sizeof(int)), vector <int>(count, count+sizeof(count)/sizeof(int)), time); break;
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
