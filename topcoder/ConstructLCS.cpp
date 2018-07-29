#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
int L[2000][2000];
int LCS(string X, string Y)
{
	int m=X.length(),n=Y.length();
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}
string solve(int _ab, int _bc, int _ca) {
		int want[3];
		want[0]=_ab;want[1]=_bc;want[2]=_ca;
		vector<int> d={_ab,_bc,_ca};
		sort(d.begin(),d.end());
		reverse(d.begin(),d.end());
		int ab=d[0],bc=d[1],ca=d[2];
		string A,B,C;
		A.resize(ca+ab);
		for (int i=0;i<ca;i++) A[i]='0';
		for (int i=ca;i<ca+ab;i++) A[i]='1';
		B.resize(ab+bc);
		for (int i=0;i<ab;i++) B[i]='1';
		for (int i=ab;i<ab+bc;i++) B[i]='0';
		C.resize(bc);
		for (int i=0;i<bc;i++) C[i]='0';
		string s[3]; s[0]=A,s[1]=B,s[2]=C;
		vector<int> p;
		for (int i=0;i<3;i++) p.PB(i);
		do {
			bool ok=1;
			for (int i=0;i<3;i++) {
				int j=(i+1)%3;
				string x=s[p[i]],y=s[p[j]];
				int lcs=LCS(x,y);
				if (lcs!=want[i]) ok=0;
			}
			if (ok) {
				assert(LCS(s[p[0]],s[p[1]])==_ab);
				assert(LCS(s[p[1]],s[p[2]])==_bc);
				assert(LCS(s[p[2]],s[p[0]])==_ca);
				assert(LCS(s[p[1]],s[p[0]])==_ab);
				assert(LCS(s[p[2]],s[p[1]])==_bc);
				assert(LCS(s[p[0]],s[p[2]])==_ca);
				return s[p[0]]+" "+s[p[1]]+" "+s[p[2]];
			}
		} while(next_permutation(p.begin(),p.end()));
		assert(0);
	}
string go(int ab, int bc, int ca) {
	assert(LCS(A,B)==ab);
	assert(LCS(B,C)==bc);
	assert(LCS(C,A)==ca);
}
void test() {
	srand(time(0)+rand()+clock());
	for (int i=0;i<1000;i++) {
		go(rand()%50+1,rand()%50+1,rand()%50+1);
	}
}
class ConstructLCS {
	public:
	string construct(int ab, int bc, int ca) {
		test();
		return solve(ab,bc,ca);
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
		cout << "Testing ConstructLCS (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1498525202;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ConstructLCS _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int ab = 3;
				int bc = 4;
				int ca = 2;
				_expected = "101 1010101 1111";
				_received = _obj.construct(ab, bc, ca); break;
			}
			case 1:
			{
				int ab = 7;
				int bc = 4;
				int ca = 4;
				_expected = "10101010 1010101 1011";
				_received = _obj.construct(ab, bc, ca); break;
			}
			case 2:
			{
				int ab = 8;
				int bc = 7;
				int ca = 8;
				_expected = "110101001011 010101101 10101010";
				_received = _obj.construct(ab, bc, ca); break;
			}
			case 3:
			{
				int ab = 8;
				int bc = 6;
				int ca = 7;
				_expected = "110101010 10101010 1111010";
				_received = _obj.construct(ab, bc, ca); break;
			}
			case 4:
			{
				int ab = 15;
				int bc = 17;
				int ca = 19;
				_expected = "000100101101111011000 11110111010011101010 100100001010101001010101000011111";
				_received = _obj.construct(ab, bc, ca); break;
			}
			case 5:
			{
				int ab = 50;
				int bc = 50;
				int ca = 50;
				_expected = "11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111";
				_received = _obj.construct(ab, bc, ca); break;
			}
			/*case 6:
			{
				int ab = ;
				int bc = ;
				int ca = ;
				_expected = ;
				_received = _obj.construct(ab, bc, ca); break;
			}*/
			/*case 7:
			{
				int ab = ;
				int bc = ;
				int ca = ;
				_expected = ;
				_received = _obj.construct(ab, bc, ca); break;
			}*/
			/*case 8:
			{
				int ab = ;
				int bc = ;
				int ca = ;
				_expected = ;
				_received = _obj.construct(ab, bc, ca); break;
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
