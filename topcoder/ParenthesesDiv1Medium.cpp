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
const ll MAXN=2004;
bool la[MAXN];
bool ra[MAXN];
class ParenthesesDiv1Medium {
	public:
	int minSwaps(string s, vector <int> L, vector <int> R) {
		ll k=L.size();
		for (ll i=0;i<k;i++) {
			if ((R[i]-L[i]+1)&1) return -1;
		}
		ll gplus=0;
		ll gminus=0;
		while(1) {
			ll n=s.length();
			k=L.size();
			if(k==0) break;
			for (ll i=0;i<n;i++) {la[i]=false;ra[i]=false;}
			for (ll i=0;i<k;i++) {
				la[L[i]]=true; ra[R[i]]=true;
			}
			ll lastl=UNDEF; ll lastr=UNDEF;
			for (ll x=0;x<n;x++) {
				if (ra[x]&&lastl!=UNDEF) {
					lastr=x; break;
				}
				if (la[x]) lastl=x;
				if(!la[x]&&ra[x]) lastl=UNDEF;
			}
			assert(lastl<lastr&&lastl!=UNDEF&&lastr!=UNDEF);
			ll rmlen=lastr-lastl+1;
			assert(((rmlen)%2)==0);
			ll sum=0;
			ll pk=0;
			for (ll x=lastl;x<=lastr;x++) {
				if (s[x]=='(') sum++;
				else sum--;
				//printf("%d:%c. %d\n",x,s[x],sum);
				chkmin(pk,sum);
			}
			sum/=2;
			pk=-((abs(pk)+1)/2);
			ll plus=0,minus=0;
			if (sum<0) {
				ll add=min(abs(sum),abs(pk));
				plus+=add;
				pk+=add; sum+=add;
			}
			if (sum<0) {
				plus+=abs(sum);
			}
			else {
				minus+=abs(sum);
			}
			plus+=abs(pk); minus+=abs(pk);
			//printf("s: %s l:%d r:%d sum:%d pk:%d +:%d -:%d\n",s.c_str(),lastl,lastr,sum,pk,plus,minus);
			gplus+=plus;
			gminus+=minus;
			vector<int> nL,nR;
			nL.clear();nR.clear();
			for (ll i=0;i<k;i++) {
				assert(L[i]<=lastl||L[i]>=lastr);
				assert(R[i]<=lastl||R[i]>=lastr);
				if (L[i]>=lastr) L[i]-=rmlen;
				if (R[i]>=lastr) R[i]-=rmlen;
				if (L[i]<R[i]) {
					nL.PB(L[i]); nR.PB(R[i]);
				}
			}
			L=nL;R=nR;
			s=s.substr(0,lastl)+s.substr(lastr+1,n-(lastr+1)+1);
			assert((ll)s.length()==n-rmlen);
		}
		{
			ll plus=gplus,minus=gminus;
			ll ans=min(plus,minus);
			ll hplus=0,hminus=0;
			ll n=s.length();
			for (ll x=0;x<n;x++) {
				if (s[x]=='(') hplus++;
				else hminus++;
			}
			ll needplus = max(0LL,plus-minus);
			ll needminus= max(0LL,minus-plus);
			if (hplus<needplus) return -1;
			if (hminus<needminus) return -1;
			ans+=needplus+needminus;
			return ans;
		}
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
		cout << "Testing ParenthesesDiv1Medium (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460734475;
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
		ParenthesesDiv1Medium _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = ")(";
				int L[] = {0,0,0,0};
				int R[] = {1,1,1,1};
				_expected = 1;
				_received = _obj.minSwaps(s, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 1:
			{
				string s = "(())";
				int L[] = {0,2};
				int R[] = {1,3};
				_expected = 1;
				_received = _obj.minSwaps(s, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 2:
			{
				string s = "(((())";
				int L[] = {0,2};
				int R[] = {1,3};
				_expected = 2;
				_received = _obj.minSwaps(s, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 3:
			{
				string s = "(((((((((";
				int L[] = {0,2};
				int R[] = {1,3};
				_expected = -1;
				_received = _obj.minSwaps(s, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 4:
			{
				string s = "()()()()";
				int L[] = {0,0,0,0,2,2,2,4,4,6};
				int R[] = {1,3,5,7,3,5,7,5,7,7};
				_expected = 0;
				_received = _obj.minSwaps(s, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			case 5:
			{
				string s = ")()(()()((())()()()()()()))(()())()()()(";
				int L[] = {3,5,17,25,35};
				int R[] = {12,10,30,30,38};
				_expected = 3;
				_received = _obj.minSwaps(s, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}
			/*case 6:
			{
				string s = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.minSwaps(s, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				string s = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.minSwaps(s, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				string s = ;
				int L[] = ;
				int R[] = ;
				_expected = ;
				_received = _obj.minSwaps(s, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int))); break;
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
