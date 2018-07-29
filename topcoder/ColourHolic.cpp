#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000009LL;
const ll MAXN = 204;
const ll MAXT = 404;
const ll MAXF=150001;
int f[MAXN][MAXN][MAXT][3];
ll fact[MAXF],invfact[MAXF],powtwo[MAXF];
ll modexp(ll base, ll e) {
	ll ans = 1;
	while(e > 0) {
		if (e % 2 == 1) {
			ans = (ans * base) % MOD;
			e--;
		}
		else {
			base = (base*base) % MOD;
			e /= 2;
		}
	}
	
	return ans%MOD;
}

ll init() {
	fact[0]=1;
	for (ll x=1;x<MAXF;x++) {
		fact[x]=(fact[x-1]*x)%MOD;
		
	}
	for (ll x=0;x<MAXF;x++) {
		invfact[x]=modexp(fact[x],MOD-2);
		
		
	}
	ll t=1;
	for (ll x=0;x<MAXF;x++) {
		powtwo[x] = t;
		t = (t*2)%MOD;
		
	}
}

ll binom(ll n,ll k) {
	if (n<k) return 0;
	if (n<0||k<0) return 0;
	
	ll ans = (invfact[k]*invfact[n-k])%MOD;
	
	return (fact[n]*ans)%MOD;
}

ll starbar(ll stars, ll parts) {
	if (parts==0) {
		return (stars==0)?1:0;
	}
	return binom(stars+parts-1,parts-1);
}

class ColourHolic {
	public:
	int countSequences(vector <int> v) {
		init();
		sort(v.begin(),v.end());
		ll a=v[0];
		ll b=v[1];
		ll lim = a+b+(a+b+1);
		ll zl = a+b+1;
		for (ll x=0;x<=a;x++)
			for (ll y=0;y<=b;y++)
				for (ll z=0;z<=zl;z++)
					for (ll c=0;c<3;c++)
						f[x][y][z][c]=0;
		f[0][0][1][0]=1;
		f[0][1][0][1]=1;
		f[1][0][0][2]=1;
		for (ll len=1;len<=lim;len++) {
			ll xl=min(a,len);
			for (ll x=0;x<=xl;x++) {
				ll yl=min(b,len-x);
				for (ll y=0;y<=yl;y++) {
					ll z=len-(x+y);
					if (z>x+y+1||x>a||y>b) {
						continue;
					}
					for (ll c=0;c<3;c++) {
						ll val=f[x][y][z][c]%MOD;
						
						for (ll d=0;d<3;d++) {
							if (c==d) continue;
							if(d==0) {
								f[x][y][z+1][d]=(((ll)f[x][y][z+1][d])+val)%MOD;
							}
							else if (d==1) {
								f[x][y+1][z][d]=(((ll)f[x][y+1][z][d])+val)%MOD;
							}
							else {
								f[x+1][y][z][d]=(((ll)f[x+1][y][z][d])+val)%MOD;
							}
						}
					}
				}
			}
		}
		ll po=v[2];
		ll qo=v[3];
		ll final=0;
		for (ll len=0;len<=zl;len++) {
			for (ll x=0;x<=len;x++) {
				ll yl=len-x;
				for (ll y=0;y<=yl;y++) {
					ll z=len-x-y;
					ll p=po-x-z;
					ll q=qo-y-z;
					if (p!=q) continue;
					
					ll choose = (starbar(q,len) * powtwo[z])%MOD;
					
					choose = (choose*binom(len,x))%MOD;
					
					choose = (choose*binom(len-x,y))%MOD;
					
					//ll choose=starbar(q,len)*powtwo[z]*binom(len,x)*binom(len-x,y);
					ll v=0;
					for (ll c=0;c<3;c++) {
						v = (v+((ll)f[a][b][len][c]))%MOD;
						
					}
					ll cand=(choose*v)%MOD;
					
					//printf("x:%lld y:%lld z:%lld q:%lld v:%lld choose:%lld cand:%lld\n",x,y,z,q,v,choose,cand);
					final=(final+cand)%MOD;
					
				}
			}
		}
		return final%MOD;
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
		cout << "Testing ColourHolic (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455089833;
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
		ColourHolic _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n[] = {1,0,2,3};
				_expected = 10;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 1:
			{
				int n[] = {1,1,1,1};
				_expected = 24;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 2:
			{
				int n[] = {42,42,42,9001};
				_expected = 0;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 3:
			{
				int n[] = {8,0,0,8};
				_expected = 2;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 4:
			{
				int n[] = {0,5,1,3};
				_expected = 4;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 5:
			{
				int n[] = {4,2,1,3};
				_expected = 1074;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 6:
			{
				int n[] = {15,900,357,22};
				_expected = 0;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 7:
			{
				int n[] = {110,30000,200,29999};
				_expected = 118115350;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 8:
			{
				int n[] = {0,1,1,1};
				_expected = 6;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 9:
			{
				int n[] = {2,2,2,2};
				_expected = 864;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 10:
			{
				int n[] = {3,4,4,5};
				_expected = 1451004;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 11:
			{
				int n[] = {3,4,5,6};
				_expected = 6350554;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 12:
			{
				int n[] = {4,5,6,7};
				_expected = 460016238;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 13:
			{
				int n[] = {4,6,4,6};
				_expected = 65504944;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
			}
			case 14:
			{
				int n[] = {200, 201, 200, 200};
				_expected = 548618418;
				_received = _obj.countSequences(vector <int>(n, n+sizeof(n)/sizeof(int))); break;
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
