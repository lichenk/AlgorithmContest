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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
typedef pair<ld,ld> pt;
pt f[4];
pt getint(ld a,ld b,ld c, ld d) {
	ld x=(d-b)/(a-c);
	ld y=a*x+b;
	//cout<<"getint:"<<a<<","<<b<<","<<c<<","<<d<<":"<<x<<endl;
	return MP(x,y);
}
ld getarea(ll k) {
	ld ans=0;
	for (ll i=0;i<k;i++) {
		ll a=i; ll b=(i+1)%k;
		ans+=(f[a].first*f[b].second)-(f[a].second*f[b].first);
	}
	return fabs(ans)/2;
}
class TriangleXor {
	public:
	int theArea(int n) {
		ld nf=n;
		ld ans=0;
		for (ll _k=1;_k<n;_k+=2) {
			ld kf=_k;
			{
				ld a=1/nf; ld b=0; ld c=-1/kf; ld d=1;
				f[0]=getint(a,b,c,d);
			}
			{
				ld a=1/nf; ld b=0; ld c=-1/(kf+1); ld d=1;
				f[1]=getint(a,b,c,d);
			}
			{
				ld a=1/(nf-1); ld b=-1/(nf-1); ld c=-1/(kf+1); ld d=1;
				f[2]=getint(a,b,c,d);
			}
			{
				ld a=1/(nf-1); ld b=-1/(nf-1); ld c=-1/kf; ld d=1;
				f[3]=getint(a,b,c,d);
			}
			//cout<<_k<<":"<<(n-_k)*getarea(4)<<endl;
			ans+=(n-_k)*getarea(4);
		}
		ld top = nf/2 - nf/8;
		if ((n%2)==1) top-=nf/8;
		for (ll _k=1;_k<n;_k+=2) {
			ld kf=_k;
			ld a=1/nf; ld b=0;
			f[0]=MP(0,1);
			{
				ld c=-1/kf; ld d=1;
				f[1]=getint(a,b,c,d);
			}
			{
				ld c=-1/(kf+1); ld d=1;
				f[2]=getint(a,b,c,d);
			}
			/*for (ll i=0;i<3;i++) {
				cout<<i<<"::"<<f[i].first<<", "<<f[i].second<<endl;
			}
			cout<<_k<<":"<<getarea(3)<<endl;*/
			top-=getarea(3);
		}
		//cout<<"Top: " << top << endl;
		ans+=2*top;
		cout<<"Ans: " << ans<<endl;
		ll final=floor(ans);
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
		cout << "Testing TriangleXor (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460913385;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TriangleXor _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int W = 1;
				_expected = 0;
				_received = _obj.theArea(W); break;
			}
			case 1:
			{
				int W = 2;
				_expected = 1;
				_received = _obj.theArea(W); break;
			}
			case 2:
			{
				int W = 3;
				_expected = 1;
				_received = _obj.theArea(W); break;
			}
			case 3:
			{
				int W = 4;
				_expected = 2;
				_received = _obj.theArea(W); break;
			}
			case 4:
			{
				int W = 5;
				_expected = 2;
				_received = _obj.theArea(W); break;
			}
			case 5:
			{
				int W = 12345;
				_expected = 4629;
				_received = _obj.theArea(W); break;
			}
			/*case 6:
			{
				int W = ;
				_expected = ;
				_received = _obj.theArea(W); break;
			}*/
			/*case 7:
			{
				int W = ;
				_expected = ;
				_received = _obj.theArea(W); break;
			}*/
			/*case 8:
			{
				int W = ;
				_expected = ;
				_received = _obj.theArea(W); break;
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
