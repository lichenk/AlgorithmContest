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
string add(string a, string b) {
	ll n=a.length();
	string ans=string(n,0);
	ll carry=0;
	for (ll x=n-1;x>=0;x--) {
		ll da=a[x];
		ll db=b[x];
		ll sum=da+db+carry;
		ans[x]=(sum+10)%10;
		carry=sum/10;
	}
	return ans;
}
string div2(string a) {
	ll n=a.length();
	string ans=string(n,0);
	ll borrow=0;
	for (ll x=0;x<n;x++) {
		ll have=borrow*10+a[x];
		ll got=have/2;
		ans[x]=got;
		borrow=have%2;
	}
	return ans;
}
const ll MAXN=51;
const ll LS=0;
const ll EQ=1;
const ll GR=2;
inline ll transfront(ll floc, ll dig, ll flo) {
	if (dig==flo) {
		if (floc==EQ) return EQ;
		else return floc;
	}
	else if (dig<flo) return LS;
	else return GR;
}
inline ll transback(ll bloc, ll dig, ll blo) {
	if (bloc==EQ) {
		if (dig==blo) return EQ;
		else if (dig<blo) return LS;
		else return GR;
	}
	else return bloc;
}
ll f[MAXN][MAXN][3];
bool solve(string lower, string upper, string digits, ll init, ll n) {
	for (ll sum=0;sum<=n;sum++)
		for (ll x=0;x<=init;x++) {
			ll y=sum-x;
			for (ll floc=0;floc<3;floc++)
				f[x][y][floc]=0;
		}
	f[0][0][1]=1LL<<(1*9+1*3+1);
	for (ll sum=0;sum<n;sum++) {
		for (ll x=0;x<=init;x++) {
			ll y=sum-x;
			for (ll floc=0;floc<3;floc++) {
				for (ll fhic=0;fhic<3;fhic++) {
					for (ll bloc=0;bloc<3;bloc++) {
						for (ll bhic=0;bhic<3;bhic++) {
							if (f[x][y][floc]&(1LL<<(fhic*9+bloc*3+bhic))) {
								ll flo=lower[(init-x-1)+1];
								ll blo=lower[(init+y)+1];
								ll fhi=upper[(init-x-1)+1];
								ll bhi=upper[(init+y)+1];
								ll dig=digits[sum];
								//printf("flo:%lld blo:%lld fhi:%lld bhi:%lld dig: %lld\n",flo,blo,fhi,bhi,dig);
								{
									// Put dig in front
									ll nfloc=transfront(floc,dig,flo);
									ll nfhic=transfront(fhic,dig,fhi);
									/*printf("x:%lld y:%lld floc:%lld fhic:%lld bloc:%lld bhic:%lld to x:%lld y:%lld floc:%lld fhic:%lld bloc:%lld bhic: %lld\n",
										x,y,floc,fhic,bloc,bhic,
										x+1,y,nfloc,nfhic,bloc,bhic
										);*/
									f[x+1][y][nfloc]|=1LL<<(nfhic*9+bloc*3+bhic);
									//f[x+1][y][nfloc][nfhic][bloc][bhic]=true;
								}
								{
									// Put dig at back
									ll nbloc=transback(bloc, dig, blo);
									ll nbhic=transback(bhic, dig, bhi);
									/*printf("x:%lld y:%lld floc:%lld fhic:%lld bloc:%lld bhic:%lld to x:%lld y:%lld floc:%lld fhic:%lld bloc:%lld bhic: %lld\n",
										x,y,floc,fhic,bloc,bhic,
										x,y+1,floc,fhic,nbloc,nbhic
										);*/
									f[x][y+1][floc]|=1LL<<(fhic*9+nbloc*3+nbhic);
									//f[x][y+1][floc][fhic][nbloc][nbhic]=true;
								}
							}
						}
					}
				}
			}
		}
	}
	{
		ll x=init; ll y=n-x;
		//printf("Check: %lld %lld\n",x,y);
		for (ll floc=0;floc<3;floc++) {
			for (ll fhic=0;fhic<3;fhic++) {
				for (ll bloc=0;bloc<3;bloc++) {
					for (ll bhic=0;bhic<3;bhic++) {
						bool gelo=(floc==GR)||(floc==EQ&&bloc!=LS);
						bool lehi=(fhic==LS||(fhic==EQ&&bhic!=GR));
						if (gelo&&lehi) {
							if (f[x][y][floc]&(1LL<<(fhic*9+bloc*3+bhic))) {
								//printf("%s %s: True\n",gs(lower),gs(upper));
								return true;
							}
						}
					}
				}
			}
		}
	}
	//printf("%s %s: False\n",gs(lower),gs(upper));
	return false;
}
bool gsolve(string lower, string upper, string digits, ll n) {
	for (ll init=0;init<n;init++) {
		if (solve(lower, upper, digits, init,n)) return true;
	}
	//printf("%s %s: False\n",gs(lower),gs(upper));
	return false;
}
class LeftRightDigitsGame2 {
	public:
	string minNumber(string _digits, string _lowerBound) {
		/*string in="12";
		for (auto &w:in) w-='0';
		printf("%s\n",gs(div2(in)));
		return "0";*/
		ll n=_digits.length();
		ll slen=n+1;
		string imax=string(slen,0);
		for (ll i=0;i<n;i++) imax[i]=0;
		imax[0]=1;
		string one=string(slen,0);
		for (ll i=0;i<slen;i++) one[i]=0;
		one[slen-1]=1;
		string digits=_digits;
		for (auto &w:digits) w-='0';
		string lowerBound=string(slen,0);
		for (ll i=0;i<slen;i++) lowerBound[i]=0;
		ll lsz=_lowerBound.length();
		for (ll i=0;i<lsz;i++) lowerBound[slen-1-i]=_lowerBound[lsz-1-i]-'0';
		string imin=lowerBound;
		string origimax=imax;
		while(imin<imax) {
			string imid=div2(add(imin,imax));
			//printf("imin:%s imax:%s sum:%s imid:%s\n",gs(imin),gs(imax),gs(add(imin,imax)),gs(imid));
			if (!gsolve(lowerBound,imid,digits,n)) {
				imin=add(imid,one);
			}
			else {
				imax=imid;
			}
		}
		if (imin==origimax) return "";
		for (auto &w:imin) w+='0';
		imin.erase(0,1);
		return imin;
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
		cout << "Testing LeftRightDigitsGame2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1467653897;
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
		LeftRightDigitsGame2 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string digits = "565";
				string lowerBound = "556";
				_expected = "556";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			case 1:
			{
				string digits = "565";
				string lowerBound = "566";
				_expected = "655";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			case 2:
			{
				string digits = "565";
				string lowerBound = "656";
				_expected = "";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			case 3:
			{
				string digits = "9876543210";
				string lowerBound = "5565565565";
				_expected = "5678943210";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			case 4:
			{
				string digits = "8016352";
				string lowerBound = "1000000";
				_expected = "1086352";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			case 5:
			{
				string digits = "00000000000000000000000000000000000000000000000000";
				string lowerBound = "10000000000000000000000000000000000000000000000000";
				_expected = "";
				_received = _obj.minNumber(digits, lowerBound); break;
			}
			/*case 6:
			{
				string digits = ;
				string lowerBound = ;
				_expected = ;
				_received = _obj.minNumber(digits, lowerBound); break;
			}*/
			/*case 7:
			{
				string digits = ;
				string lowerBound = ;
				_expected = ;
				_received = _obj.minNumber(digits, lowerBound); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
