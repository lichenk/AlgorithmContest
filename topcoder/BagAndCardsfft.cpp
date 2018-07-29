#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXN 508
#define MAXM 508
#define MAXP 512






#define P 1000000007
#define N1 (262144/2)
#define N2 (N1+1)
#define P1 998244353
#define P2 995622913
#define E1 996173970
#define E2 88560779
#define F1 121392023
#define F2 840835547
#define I1 998240545
#define I2 995619115
#define M1 397550359381069386LL
#define M2 596324591238590904LL
#define MM 993874950619660289LL
ll n;
ll mul(ll x,ll y,ll z){return (x*y-(ll)(x/(ld)z*y+1e-3)*z+z)%z;}
int trf(int x1,int x2){return (mul(M1,x1,MM)+mul(M2,x2,MM))%MM%P;}
int A[N2],B[N2],C[N2];
int A1[N2],B1[N2],C1[N2];
void fft(int*A,int PM,int PW)
{
	for(int m=N1,h;h=m/2,m>=2;PW=(ll)PW*PW%PM,m=h){
		for(int i=0,w=1;i<h;i++,w=(ll)w*PW%PM)
			for(int j=i;j<N1;j+=m)
			{
				int k=j+h,x=(A[j]-A[k]+PM)%PM;
				(A[j]+=A[k])%=PM;
				A[k]=(ll)w*x%PM;
			}
	}
	for(int i=0,j=1;j<N1-1;j++)
	{
		for(int k=N1/2;k>(i^=k);k/=2);
		if(j<i)swap(A[i],A[j]);
	}
}
void mul()
{
	memset(C,0,sizeof C);
	memcpy(A1,A,sizeof A);
	memcpy(B1,B,sizeof B);
	fft(A1,P1,E1);fft(B1,P1,E1);
	for(int i=0;i<N1;i++)C1[i]=(ll)A1[i]*B1[i]%P1;
	fft(C1,P1,F1);
	for(int i=0;i<N1;i++)C1[i]=(ll)C1[i]*I1%P1;
	fft(A,P2,E2);fft(B,P2,E2);
	for(int i=0;i<N1;i++)C[i]=(ll)A[i]*B[i]%P2;
	fft(C,P2,F2);
	for(int i=0;i<N1;i++)C[i]=(ll)C[i]*I2%P2;
	for (ll i = 0; i < n; i++) printf("i:%lld %lld %lld\n",i,C[i],C1[i]);
	for(int i=0;i<N1;i++)C[i]=trf(C1[i],C[i]);
	for(int i=n;i<N1;i++)C[i]=0;
}


ll cnt[MAXN][MAXN];
class BagAndCards {
	public:
	int getHash(int ni, int mi, int xi, int ai, int bi, int ci, string isGood) {
		ll Nlocal = ni;
		ll M = mi;
		ll Xlocal = xi;
		ll Alocal = ai;
		ll Blocal = bi;
		ll Clocal = ci;
		for (ll i = 0; i <= Nlocal-1; i++) {
			for (ll j = 0; j <= M-1; j++) {
				cnt[i][j] = Xlocal;
				Xlocal = ((Xlocal * Alocal + Blocal) ^ Clocal) % MOD;
			}
		}
    	ll final = 0;
    	for (ll x = 0; x < Nlocal; x++) {
    	for (ll y= x+1; y < Nlocal; y++) {
    		memset(A,0,sizeof A);
    		memset(B,0,sizeof B);
    		for (ll j = 0; j < M; j++) {
    			A[j] = cnt[x][j];
    			B[j] = cnt[y][j];
    		}
			n = 2*M;
			mul();
    		ll ways = 0;
    		for (ll i = 0; i <= 2*M-2; i++) {
    			if (isGood[i] == 'Y') {
    				ll cand = C[i]%MOD;
    		    	ways = (cand + ways)%MOD;
    		    }
    		}
    		final = final ^ ways;
    	}}
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
		cout << "Testing BagAndCards (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1453310194;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BagAndCards _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int m = 4;
				int x = 1;
				int a = 1;
				int b = 0;
				int c = 0;
				string isGood = "NNYYNYN";
				_expected = 9;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}
			case 1:
			{
				int n = 3;
				int m = 5;
				int x = 1;
				int a = 1;
				int b = 1;
				int c = 2;
				string isGood = "NNYYNYNYN";
				_expected = 1532;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}
			case 2:
			{
				int n = 10;
				int m = 20;
				int x = 111;
				int a = 222;
				int b = 333;
				int c = 444;
				string isGood = "NNNNNYYYNNNYYYYYYNNYYYYNNNNYNNYYYNNNYYN" ;
				_expected = 450750683;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}
			case 3:
			{
				int n = 2;
				int m = 2;
				int x = 1;
				int a = 1;
				int b = 0;
				int c = 0;
				string isGood = "NNY";
				_expected = 1;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}
			/*case 4:
			{
				int n = ;
				int m = ;
				int x = ;
				int a = ;
				int b = ;
				int c = ;
				string isGood = ;
				_expected = ;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}*/
			/*case 5:
			{
				int n = ;
				int m = ;
				int x = ;
				int a = ;
				int b = ;
				int c = ;
				string isGood = ;
				_expected = ;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
			}*/
			/*case 6:
			{
				int n = ;
				int m = ;
				int x = ;
				int a = ;
				int b = ;
				int c = ;
				string isGood = ;
				_expected = ;
				_received = _obj.getHash(n, m, x, a, b, c, isGood); break;
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
