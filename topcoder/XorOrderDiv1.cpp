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
const ll mk=31;
const ll mn=2e5+4;
ll a[mn];
ll f[2][mk][mn];
//ll g[mn][2][mk];
class XorOrderDiv1 {
	public:
	int get(int m, int n, int _a0, int _b) {
		memset(f,0,sizeof f);
		ll a0=_a0,b=_b;
		ll pm=1LL<<m;pm--;
		for (ll i=0;i<n;i++) {
			a[i]=(a0+i*b)&pm;
		}
		vector<vector<int>> v[2];
		{
			vector<int> tmp;
			for (ll i=0;i<n;i++) tmp.PB(i);
			v[(mk-1)&1].PB(tmp);
		}
		for (ll k=mk-1;k>=0;k--) {
			ll cur=k&1;ll nxt=cur^1;
			v[nxt].clear();
			for (auto &q:v[cur]) {
				vector<int> tmp[2];
				for (auto &w:q) {
					ll b=((1LL<<k)&a[w])>>k;
					tmp[b].PB(w);
				}
				ll sz[2];
				for (ll b=0;b<2;b++) sz[b]=tmp[b].size();
				for (auto &w:tmp[0]) {
					f[1][k][w]+=sz[1];
					//f[1][k][w]%=MOD;
					//pr("b:%lld k:%lld w:%lld. %lld\n",1,k,w,sz[1]);
				}
				for (auto &w:tmp[1]) {
					f[0][k][w]+=sz[0];
					//f[0][k][w]%=MOD;
					//pr("b:%lld k:%lld w:%lld. %lld\n",0,k,w,sz[0]);
				}

				for (ll b=0;b<2;b++) {
					if(sz[b]>0) v[nxt].PB(tmp[b]);
				}
			}
		}
		for (ll b=0;b<2;b++) for (ll k=0;k<mk;k++) for (ll x=0;x<n;x++) f[b][k][x]%=MOD;
		/*for (ll b=0;b<2;b++) for (ll k=0;k<mk;k++) for (ll x=0;x<n;x++) {
			g[x][b][k]=f[b][k][x];
		}*/
		ll psq=(1LL<<(m-1))%MOD;
		ll pcross=(1LL<<(m-1))%MOD;
		//if (m-2<0) pcross=0;
		ll final=0;
		for (ll x=0;x<n;x++) {
			ll sumsq=0;
			for (ll b=0;b<2;b++)for (ll k=0;k<mk;k++) {
				//ll v=g[x][b][k];
				ll v=f[b][k][x];
				//ll vsq=(v*v)%MOD;
				//if(v==1) //pr("isone: %lld %lld %lld\n",b,k,x);
				sumsq=(sumsq+v*v)%MOD;
			}
			ll all=0;
			for (ll b=0;b<2;b++) for (ll k=0;k<mk;k++) {
				all+=f[b][k][x]; all%=MOD;
			}
			all=(all*all)%MOD;
			ll bad=0;
			for (ll k=0;k<mk;k++) {
				bad+=(2*f[0][k][x]*f[1][k][x])%MOD;
				bad%=MOD;
			}
			ll sumbad=(sumsq+bad)%MOD;
			ll cross=(all-sumbad+MOD)%MOD;
			ll inv2=500000004;
			cross=(cross*inv2)%MOD;
			/*ll cross=0;
			for (ll b=0;b<2;b++) for (ll c=0;c<2;c++) {
				for (ll k=0;k<mk;k++) for (ll j=k+1;j<mk;j++) {
					//if (j==k) continue;
					//ll v=g[x][b][k];
					//ll o=g[x][c][j];
					ll v=f[b][k][x];
					ll o=f[c][j][x];
					//ll prod=(v*o)%MOD;
					cross+=v*o%MOD;
				}
			}*/
			sumsq=(sumsq*psq)%MOD;
			cross=(cross*pcross)%MOD;
			ll ans=(sumsq+cross)%MOD;
			//pr("x:%lld sumsq:%lld cross:%lld ans:%lld\n",x,sumsq,cross,ans);
			final^=ans;
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
		cout << "Testing XorOrderDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471575422;
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
		XorOrderDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int m = 2;
				int n = 3;
				int a0 = 0;
				int b = 1;
				_expected = 8;
				_received = _obj.get(m, n, a0, b); break;
			}
			case 1:
			{
				int m = 3;
				int n = 5;
				int a0 = 1;
				int b = 3;
				_expected = 48;
				_received = _obj.get(m, n, a0, b); break;
			}
			case 2:
			{
				int m = 16;
				int n = 100;
				int a0 = 41;
				int b = 5;
				_expected = 523436032;
				_received = _obj.get(m, n, a0, b); break;
			}
			case 3:
			{
				int m = 30;
				int n = 200000;
				int a0 = 399;
				int b = 18082016;
				_expected = 408585698;
				_received = _obj.get(m, n, a0, b); break;
			}
			case 4:
			{
				int m = 2;
				int n = 4;
				int a0 = 0;
				int b = 1;
				_expected = 0;
				_received = _obj.get(m, n, a0, b); break;
			}
			case 5:
			{
				int m = 2;
				int n = 3;
				int a0 = 1;
				int b = 1;
				_expected = 8;
				_received = _obj.get(m, n, a0, b); break;
			}
			/*case 6:
			{
				int m = ;
				int n = ;
				int a0 = ;
				int b = ;
				_expected = ;
				_received = _obj.get(m, n, a0, b); break;
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
