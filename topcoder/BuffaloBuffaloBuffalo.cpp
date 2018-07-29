#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const int MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const int mk=15;
const int mz=759375;
int f[2][759375];
void decode(int z, int *a) {
	for (int i=4;i>=0;i--) {
		a[i]=z%mk;
		//printf("z:%d i:%d ai:%d\n",z,i,a[i]);
		if(i!=0) z/=mk;
	}
}
int encode(int *a) {
	int z=0;
	for (int i=0;i<5;i++) {
		z*=mk;
		z+=a[i];
	}
	return z;
}
bool check(int *x, int q) {
	for (int i=0;i<5;i++) if (x[i]>14) return false;
	int b=x[0],u=x[1],a=x[2],l=x[3],o=x[4];
	int f=q; for (int i=0;i<5;i++) f-=x[i];
	//printf("b:%d u:%d f:%d a:%d l:%d o:%d\n",b,u,f,a,l,o);
	return b>=u&&(2*u)>=f&&f>=(2*a)&&a>=l&&l>=o&&f<=28;
}
bool checke(int *x, int q) {
	int b=x[0],u=x[1],a=x[2],l=x[3],o=x[4];
	int f=q; for (int i=0;i<5;i++) f-=x[i];
	//printf("b:%d u:%d f:%d a:%d l:%d o:%d\n",b,u,f,a,l,o);
	return b==u&&(2*u)==f&&f==(2*a)&&a==l&&l==o;
}
int a[5];
int b[5];
int c2i[256],i2c[6];

class BuffaloBuffaloBuffalo {
	public:
	int count(string pattern) {
		{
			memset(c2i,-1,sizeof c2i);
			int idx=0;
			c2i['b']=idx++;
			c2i['u']=idx++;
			c2i['a']=idx++;
			c2i['l']=idx++;
			c2i['o']=idx++;
			c2i['f']=idx++;
			for (int c=0;c<256;c++) {
				if (c2i[c]!=-1) i2c[c2i[c]]=c;
			}
		}
		int n=pattern.length();
		f[0][0]=1;
		for (int q=0;q<n;q++) {
			int cur=q&1; int nxt=cur^1;
			memset(f[nxt],0,sizeof f[0]);
			for (int z=0;z<mz;z++) {
				int now=f[cur][z];
				if (now==0) continue;
				//printf("q:%d z:%d now:%d\n",q,z,now);
				decode(z,a);
				for (int i=0;i<6;i++) {
					char c=i2c[i];
					if (pattern[q]=='?'||pattern[q]==c) {
						memcpy(b,a,sizeof a);
						if (i!=5) b[i]++;
						//printf("COnsider i:%d c:%c\n",i,c);
						if (check(b,q+1)) {
							int nz=encode(b);
							//printf("nz:%d\n",nz);
							f[nxt][nz]+=now;
							if (f[nxt][nz]>=MOD) f[nxt][nz]-=MOD;
						}
					}
				}
			}
		}
		int ans=0;
		for (int z=0;z<mz;z++) {
			decode(z,a);
			if (checke(a,n)){
				ans+=f[n&1][z];
				if (ans>=MOD) ans-=MOD;
			}
		}
		ans%=MOD; if (ans<0) ans+=MOD;
		return ans%MOD;
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
		cout << "Testing BuffaloBuffaloBuffalo (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1519708626;
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
		BuffaloBuffaloBuffalo _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string pattern = "buffa????ffalo";
				_expected = 6;
				_received = _obj.count(pattern); break;
			}
			case 1:
			{
				string pattern = "buffal????????";
				_expected = 7;
				_received = _obj.count(pattern); break;
			}
			case 2:
			{
				string pattern = "b??????b??????b??????b??????";
				_expected = 1;
				_received = _obj.count(pattern); break;
			}
			case 3:
			{
				string pattern = "???????????????????????????????????";
				_expected = 420429295;
				_received = _obj.count(pattern); break;
			}
			case 4:
			{
				string pattern = "x";
				_expected = 0;
				_received = _obj.count(pattern); break;
			}
			case 5:
			{
				string pattern = "buffalo";
				_expected = 1;
				_received = _obj.count(pattern); break;
			}
			case 6:
			{
				string pattern = "";
				for (int i=0;i<98;i++) pattern+="?";
				_expected = -1;
				_received = _obj.count(pattern); break;
			}
			/*case 7:
			{
				string pattern = ;
				_expected = ;
				_received = _obj.count(pattern); break;
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
