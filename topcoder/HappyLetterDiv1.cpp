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
ll a[26];
class HappyLetterDiv1 {
	public:
	string getHappyLetters(string letters) {
		for (ll i=0;i<26;i++) a[i]=0;
		ll n=letters.length();
		for (ll i=0;i<n;i++) {
			ll c=letters[i]-'a';
			a[c]++;
		}
		string ans="";
		for (ll cc=0;cc<26;cc++) {
			if (a[cc]<=0) continue;
			priority_queue<pair<ll,ll> > pq;
			for (ll x=0;x<26;x++) {
				if (x==cc) continue;
				if(a[x]>0) pq.push(MP(a[x],x));
			}
			pq.push(MP(-a[cc],cc));

			while(pq.size()>1) {
				auto c=pq.top(); pq.pop();
				auto d=pq.top(); pq.pop();
				if (d.second==cc) {
					d.first = -d.first;
				}
				c.first--; d.first--;
				if (d.second==cc) {
					d.first = -d.first;
				}
				if (c.first!=0) pq.push(c);
				if (d.first!=0) pq.push(d);
			}
			bool ok=false;
			if (pq.size()==1) {
				auto d=pq.top();
				if (d.second==cc) {
					ok=true;
				}
			}
			if(ok) {
				char ch='a'+cc;
				ans += string(1,ch);
			}
		}
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
		cout << "Testing HappyLetterDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457116306;
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
		HappyLetterDiv1 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string letters = "aabbacccc";
				_expected = "abc";
				_received = _obj.getHappyLetters(letters); break;
			}
			case 1:
			{
				string letters = "aaaaaaaccdd";
				_expected = "a";
				_received = _obj.getHappyLetters(letters); break;
			}
			case 2:
			{
				string letters = "ddabccadb";
				_expected = "abcd";
				_received = _obj.getHappyLetters(letters); break;
			}
			case 3:
			{
				string letters = "aaabbb";
				_expected = "";
				_received = _obj.getHappyLetters(letters); break;
			}
			case 4:
			{
				string letters = "rdokcogscosn";
				_expected = "cos";
				_received = _obj.getHappyLetters(letters); break;
			}
			/*case 5:
			{
				string letters = ;
				_expected = ;
				_received = _obj.getHappyLetters(letters); break;
			}*/
			/*case 6:
			{
				string letters = ;
				_expected = ;
				_received = _obj.getHappyLetters(letters); break;
			}*/
			/*case 7:
			{
				string letters = ;
				_expected = ;
				_received = _obj.getHappyLetters(letters); break;
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
