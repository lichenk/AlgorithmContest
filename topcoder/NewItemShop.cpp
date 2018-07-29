#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
bool cmp(const string &a, const string &b) {
	return a.length()>b.length();
}
vector<ll> vt,vc,vp;
void unpack(string _s) {
	vt.clear(),vc.clear(),vp.clear();
	stringstream s(_s);
	char tmp;
	ll t,c,p;
	while(s>>t) {
		s>>tmp;
		s>>c;
		s>>tmp;
		s>>p;
		vt.PB(t); vc.PB(c); vp.PB(p);
	}
}
ll cc[24],id[24];
ld pp[24];
ld dp[25][25][1<<12];
ld f(ll x, ll swords, ll z) {
	if (x==24) return 0;
	if (dp[x][swords][z]>=-1) return dp[x][swords][z];
	ld ans=0;
	if (id[x]==-1) ans=f(x+1,swords,z);
	else {
		ll idx=id[x];
		ld noappear=f(x+1,swords,z);
		if (((1LL<<idx)&z)) ans=noappear;
		else {
			ll nz=z;
			if (idx<12) nz|=(1LL<<idx);
			ld notake=f(x+1,swords,nz);
			ld take=0;
			if (swords>0) take=f(x+1,swords-1,nz)+cc[x];
			ld appear=max(notake,take);
			ans=appear*pp[x]+noappear*(1-pp[x]);
		}
	}
	//if (ans>1e-9) printf("x:%lld swords:%lld z:%lld ans:%f\n",x,swords,z,ans);
	return dp[x][swords][z]=ans;
}
class NewItemShop {
	public:
	double getMaximum(int swords, vector <string> customers) {
		sort(customers.begin(),customers.end(),cmp);
		ll n=customers.size();
		memset(id,-1,sizeof id);
		for (ll i=0;i<n;i++) {
			unpack(customers[i]);
			ll k=vt.size();
			ld full=1;
			for (ll j=0;j<k;j++) {
				ll t=vt[j],c=vc[j],_p=vp[j];
				//printf("i:%lld t:%lld c:%lld p:%lld\n",i,t,c,_p);
				ld p=_p/100.0;
				cc[t]=c;pp[t]=p/full; id[t]=i;
				full-=p;
			}
		}
		for (ll x=0;x<25;x++)for (ll y=0;y<25;y++) for (ll z=0;z<(1<<12);z++) dp[x][y][z]=-2;
		ld ans=f(0,swords,0);
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
		cout << "Testing NewItemShop (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483845160;
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
		NewItemShop _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int swords = 1;
				string customers[] = { "8,1,80 16,100,11", "12,10,100" };
				_expected = 19.0;
				_received = _obj.getMaximum(swords, vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}
			case 1:
			{
				int swords = 2;
				string customers[] = { "8,1,80 16,100,11", "12,10,100" };
				_expected = 21.8;
				_received = _obj.getMaximum(swords, vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}
			case 2:
			{
				int swords = 1;
				string customers[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" };
				_expected = 90.0;
				_received = _obj.getMaximum(swords, vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}
			case 3:
			{
				int swords = 3;
				string customers[] = { "17,31,41 20,59,26 23,53,5", "19,89,79", "16,32,38 22,46,26", "18,43,38 21,32,7" };
				_expected = 135.5121414;
				_received = _obj.getMaximum(swords, vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}
			case 4:
			{
				int swords = 5;
				string customers[] = { "1,1,10", "2,2,9", "3,3,8", "4,4,7", "5,5,6", "6,6,5", "7,7,4", "8,8,3", "9,9,2", "10,10,1" };
				_expected = 2.1999744634845344;
				_received = _obj.getMaximum(swords, vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}
			/*case 5:
			{
				int swords = ;
				string customers[] = ;
				_expected = ;
				_received = _obj.getMaximum(swords, vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int swords = ;
				string customers[] = ;
				_expected = ;
				_received = _obj.getMaximum(swords, vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int swords = ;
				string customers[] = ;
				_expected = ;
				_received = _obj.getMaximum(swords, vector <string>(customers, customers+sizeof(customers)/sizeof(string))); break;
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
