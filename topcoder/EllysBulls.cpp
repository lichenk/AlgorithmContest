#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
vector<pair<int,string> > g;
ll numg;
ll d;
const ll MAXD=10;
unordered_set<char> ban[MAXD];
string final="Liar";
string liar="Liar";
string ambi="Ambiguity";
vector<vector<ll> >ch[MAXD][MAXD];
bool check(string s) {
	for (ll i=0;i<numg;i++) {
		ll cnt=0;
		for (ll j=0;j<d;j++) {
			if (s[j]==((g[i]).second)[j]) {
				cnt++;
			}
		}
		if (cnt!=g[i].first) return false;
	}
	return true;
}

void solve(string s, ll idx) {
	/*if (idx<numg){
	//cout<<idx<<":"<<s<<" with "<<g[idx].first<<" "<<g[idx].second<< endl;
	}*/
	if (idx>=numg||g[idx].first==0) {
		for (ll j=0;j<d;j++) {
			ban[j].clear();
		}
		for (ll i=0;i<numg;i++) {
			ll cnt=0;
			for (ll j=0;j<d;j++) {
				if (s[j]==((g[i]).second)[j]) {
					cnt++;
				}
			}
			if (g[i].first==cnt) {
				for (ll j=0;j<d;j++) {
					ban[j].insert(g[i].second[j]);
				}
			}
		}

		bool bambi=false;
		for (ll i=0;i<d;i++) {
			if (s[i]=='?') {
				s[i]='0';
				ll sols=0;
				for (ll x=0;x<10;x++) {
					char c='0'+x;
					if (ban[i].find(c)==ban[i].end()) {
						s[i]=c;
						sols++;
						//cout<<s<<":"<<i<<":"<<c<<":"<<sols<<endl;
					}
				}
				if (sols>=2) {
					//cout<<s<<":"<<i<<endl;
					bambi=true;
				}
			}
		}
		if (check(s)) {
			if(bambi) {
				//cout<<s<<endl;
				final=ambi;
				return;
			}
			if (final==liar) {
				final=s;
			}
			else {
				final=ambi;
			}
		}
		return;
	}
	vector<ll> emp;
	for (ll i=0;i<d;i++) {
		if(s[i]=='?') emp.PB(i);
	}
	if (emp.size()==0) {
		if (check(s)) {
			if (final==liar) {
				final=s;
			}
			else {
				final=ambi;
			}
		}
		return;
	}
	ll esz=emp.size();
	ll correct=g[idx].first;
	for (ll j=0;j<d;j++) {
		if (s[j]==((g[idx]).second)[j]) {
			correct--;
		}
	}
	for (auto &w: ch[esz][correct]) {
		string t=s;
		for (auto &wi:w) {
			ll y=emp[wi];
			t[y]=g[idx].second[y];
		}
		solve(t,idx+1);
	}
	return;
}
void choose(ll n) {
	for (ll x=1;x<=n;x++) {
		vector<ll> emptyv;
		ch[x][0].PB(emptyv);
		for (ll t=0;t<x;t++) {
			vector<ll> singleton;
			singleton.PB(t);
			ch[x][1].PB(singleton);
		}
		for (ll y=1;y<n;y++) {
			for (auto &w:ch[x][y]) {
				ll s=w[w.size()-1];
				for (ll t=s+1;t<x;t++) {
					vector<ll> v=w;
					v.PB(t);
					ch[x][y+1].PB(v);

				}
			}
		}
	}
	/*for (ll x=1;x<=n;x++) {
		for (ll y=0;y<=n;y++) {
			printf("%d %d:\n",x,y);
			for (auto &w: ch[x][y]) {
				printf("(");
				for (auto &z:w) {
					printf("%d ",z);
				}
				printf(")\n");
			}
		}
	}*/
}
class EllysBulls {
	public:
	string getNumber(vector <string> guesses, vector <int> bulls) {
		numg=guesses.size();
		d=guesses[0].length();
		choose(d);
		for (ll i=0;i<numg;i++) {
			g.PB(MP(-bulls[i],guesses[i]));
		}
		sort(g.begin(),g.end());
		for (ll i=0;i<numg;i++) g[i].first=-g[i].first;
		string v;
		for (ll i=0;i<d;i++) v+="?";
		solve(v,0);
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
		cout << "Testing EllysBulls (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459110014;
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
		EllysBulls _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string guesses[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
				int bulls[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
				_expected = "1337";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 1:
			{
				string guesses[] = {"0000", "1111", "2222"};
				int bulls[] = {2, 2, 2};
				_expected = "Liar";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 2:
			{
				string guesses[] = {"666666", "666677", "777777", "999999"};
				int bulls[] = {2, 3, 1, 0};
				_expected = "Ambiguity";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 3:
			{
				string guesses[] = {"000", "987", "654", "321", "100", "010"};
				int bulls[] = {2, 1, 0, 0, 1, 1};
				_expected = "007";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 4:
			{
				string guesses[] = {"28", "92", "70", "30", "67", "63", "06", "65",
				                    "11", "06", "88", "48", "09", "65", "48", "08"};
				int bulls[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
				_expected = "54";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 5:
			{
				string guesses[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
				                    "4166623", "1166638", "2767693", "8650248", "2486509",
				                    "6138934", "4018642", "6236742", "2961643", "8407361",
				                    "2097376", "6575410", "6071777", "3569948", "2606380"};
				int bulls[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1};
				_expected = "4266642";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 6:
			{
				string guesses[] = {"00","99"};
				int bulls[] = {1,1};
				_expected = "Ambiguity";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 7:
			{
				string guesses[] = {"000000000", "555555555", "100000001", "920000000", "083000000", "007400000", "000606000", "000004700", "000000380", "000000029"};
				int bulls[] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = "Ambiguity";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 8:
			{
				string guesses[] = {"000000000"};
				int bulls[] = {0};
				_expected = "Ambiguity";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}
			case 9:
			{
				string guesses[] = {"00", "01", "02", "03", "04", "05", "06", "07", "08"};
				int bulls[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
				_expected = "09";
				_received = _obj.getNumber(vector <string>(guesses, guesses+sizeof(guesses)/sizeof(string)), vector <int>(bulls, bulls+sizeof(bulls)/sizeof(int))); break;
			}

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
