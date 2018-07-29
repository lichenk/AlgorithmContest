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
map<char,ll> ctod;
void init() {
	vector<char> d[10];
	d[2]={ 'a','b','c'};
	d[3]={ 'd','e','f'};
	d[4]={ 'g','h','i'};
	d[5]={ 'j','k','l'};
	d[6]={ 'm','n','o'};
	d[7]={'p','q','r','s'};
	d[8]={'t','u','v'};
	d[9]={'w','x','y','z'};
	for (ll x=2;x<=9;x++) {
		for (auto &c:d[x]) {
			//cout<<c<<":"<<x<<endl;
			ctod[c]=x;
		}
	}
}
map<string,ll> scost;
void ins(string s, ll cost) {
	auto it=scost.find(s);
	if(it==scost.end()) scost[s]=cost;
	else if (cost<it->second) scost[s]=cost;
}
ll f[55];
class QuickT9 {
	public:
	int minimumPressings(vector <string> _t9, string word) {
		init();
		vector<string> t9;
		for (auto &ss:_t9) {
			stringstream aa(ss);
			string s;
			while(aa>>s) {
				t9.PB(s);
				//cout<<s<<endl;
			}
		}
		map<string, set<string> > h;
		for (auto &s:t9) {
			string t="";
			for (ll i=0;i<s.length();i++) {
				t+=('0'+ctod[s[i]]);
				h[t].insert(s.substr(0,i+1));
			}
		}
		//for (auto &w:h) sort(w.second.begin(),w.second.end());
		for (auto &w:h) {
			ll len=w.first.length();
			ll star=0;
			for (auto &s:w.second) {
				//cout<<w.first<<" gives "<<s<<endl;
				ins(s,len+star+1);
				ll c=0;
				for (ll i=s.length()-1;i>=1;i--) {
					c++;
					ins(s.substr(0,i),len+star+c);
				}
				star++;
			}
		}
		//for (auto &w:scost) {
		//	//cout<<w.first<<":"<<w.second<<endl;
		//}
		ll n=word.length();
		for (ll x=1;x<=n;x++) f[x]=INF;
		f[0]=0;
		for (ll x=0;x<n;x++) {
			for (ll y=x+1;y<=n;y++) {
				string s=word.substr(x,y-x);
				auto it=scost.find(s);
				if (it!=scost.end()) {
					chkmin(f[y],f[x]+it->second);
					//cout<<s<<":"<<it->second<<endl;
				}
			}
		}
		if (f[n]>=INF/2) return -1;
		return f[n];
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
		cout << "Testing QuickT9 (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485055456;
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
		QuickT9 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string t9[] = {"aae", "bab", "abad", "bdbd", "beta"};
				string word = "babe";
				_expected = 9;
				_received = _obj.minimumPressings(vector <string>(t9, t9+sizeof(t9)/sizeof(string)), word); break;
			}
			case 1:
			{
				string t9[] = {"ann","ie"};
				string word = "annie";
				_expected = 7;
				_received = _obj.minimumPressings(vector <string>(t9, t9+sizeof(t9)/sizeof(string)), word); break;
			}
			case 2:
			{
				string t9[] = {"ann","amm"};
				string word = "annie";
				_expected = -1;
				_received = _obj.minimumPressings(vector <string>(t9, t9+sizeof(t9)/sizeof(string)), word); break;
			}
			case 3:
			{
				string t9[] = {"aaa aab","aac aba abb ccca"};
				string word = "aba";
				_expected = 6;
				_received = _obj.minimumPressings(vector <string>(t9, t9+sizeof(t9)/sizeof(string)), word); break;
			}
			case 4:
			{
				string t9[] = {"acac aba aaab","aab aa baa","bba bacade abb","baba"};
				string word = "abbaca";
				_expected = 10;
				_received = _obj.minimumPressings(vector <string>(t9, t9+sizeof(t9)/sizeof(string)), word); break;
			}
			case 5:
			{
				string t9[] = {"aaa aab aac","aba abb","ccca"};
				string word = "ccc";
				_expected = 5;
				_received = _obj.minimumPressings(vector <string>(t9, t9+sizeof(t9)/sizeof(string)), word); break;
			}
			/*case 6:
			{
				string t9[] = ;
				string word = ;
				_expected = ;
				_received = _obj.minimumPressings(vector <string>(t9, t9+sizeof(t9)/sizeof(string)), word); break;
			}*/
			/*case 7:
			{
				string t9[] = ;
				string word = ;
				_expected = ;
				_received = _obj.minimumPressings(vector <string>(t9, t9+sizeof(t9)/sizeof(string)), word); break;
			}*/
			/*case 8:
			{
				string t9[] = ;
				string word = ;
				_expected = ;
				_received = _obj.minimumPressings(vector <string>(t9, t9+sizeof(t9)/sizeof(string)), word); break;
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
