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
bool poss(string &pre, ll k, string &s, string &t) {
	//printf("Try k:%lld\n",k);
	ll x=0;
	ll n=s.length();
	ll pl=pre.length();
	for (ll i=0;i<k;i++) {
		while(x<n&&
			!((i>=pl||pre[i]==s[x])&&
			(k+i>=pl||pre[k+i]==t[x]))
			) {
			//printf("INC k:%lld x:%lld for i:%lld. s[x]:%c pre[i];%c. t[x]:%c pre[k+i]:%c\n",k,x,i,s[x],pre[i],t[x],pre[k+i]);
			x++;
		}
		if (x==n) return false;
		//printf("k:%lld x:%lld for i:%lld. s[x]:%c pre[i];%c. i:%lld pl:%lld\n",k,x,i,s[x],pre[i],i,pl);
		x++;
	}
	//printf("k:%lld\n",k);
	return true;
}
bool po(string pre, string &s, string &t) {
	ll len=(pre.length()+1)/2;
	for (ll k=len;k<=s.length();k++) {
		if (poss(pre,k,s,t)) return true;
	}
	return false;
}
class TheLargestString {
	public:
	string find(string s, string t) {
		ll n=s.length();
		string final="";
		for (ll x=0;;x++) {
			char ch=0;
			for (char c='z';c>='a';c--) {
				string pre=final+c;
				//printf("Try %s\n",pre.c_str());
				if (po(pre,s,t)) {
					//printf("%s\n",pre.c_str());
					ch=c; break;
				}
			}
			if (ch==0) return final;
			final+=ch;
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
		cout << "Testing TheLargestString (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483070659;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheLargestString _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "ab";
				string t = "zy";
				_expected = "by";
				_received = _obj.find(s, t); break;
			}
			case 1:
			{
				string s = "abacaba";
				string t = "zzzaaaa";
				_expected = "cbaaaa";
				_received = _obj.find(s, t); break;
			}
			case 2:
			{
				string s = "x";
				string t = "x";
				_expected = "xx";
				_received = _obj.find(s, t); break;
			}
			case 3:
			{
				string s = "abbabbabbababaaaabbababab";
				string t = "bababbaabbbababbbbababaab";
				_expected = "bbbbbbbbbbbbbbbbbbaaab";
				_received = _obj.find(s, t); break;
			}
			/*case 4:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.find(s, t); break;
			}*/
			/*case 5:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.find(s, t); break;
			}*/
			/*case 6:
			{
				string s = ;
				string t = ;
				_expected = ;
				_received = _obj.find(s, t); break;
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
