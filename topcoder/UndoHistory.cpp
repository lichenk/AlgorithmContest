#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define MAXALPHA 26
#define UNDEF -1
struct Node {
	Node *child[26];
	bool leaf;
	bool done;
};
typedef struct Node node;
ll newnodes;
node *init() {
	newnodes++;
	node *v = (node*)malloc(sizeof(struct Node));
	for (ll i = 0; i < MAXALPHA; i++) {
		v->child[i] = NULL;
	}
	v->leaf = false;
	v->done = false;
	return v;
}
void insert(node *root, string s) {
	node *v = root;
	ll slen = s.length();
	for (ll i = 0; i < slen; i++) {
		ll c = s[i]-'a';
		node *next = v->child[c];
		if (next == NULL) {
			v->child[c] = init();
		}
		v = v->child[c];
	}
	v->leaf = true;
}

class UndoHistory {
	public:
	int minPresses(vector <string> lines) {
		node *root = init();
		string cur = "";
		ll ans = 0;
		for (auto& s: lines) {
			newnodes = 0;
			insert(root, s);
			ll cand = newnodes + 2;
			ll other = 99999999999LL;
			bool good = true;
			for (ll i = 0; i < cur.length(); i++) {
				if (s[i] != cur[i]) good = false;
			}
			if (good) {
				other = s.length() - cur.length();
			}
			cand = min(cand, other);
			ans += cand;
			ans++;
			cur = s;
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
		cout << "Testing UndoHistory (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1452746758;
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
		UndoHistory _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string lines[] = {"tomorrow", "topcoder"};
				_expected = 18;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}
			case 1:
			{
				string lines[] = {"a","b"};
				_expected = 6;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}
			case 2:
			{
				string lines[] = {"a", "ab", "abac", "abacus" };
				_expected = 10;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}
			case 3:
			{
				string lines[] = {"pyramid", "sphinx", "sphere", "python", "serpent"};
				_expected = 39;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}
			case 4:
			{
				string lines[] = {"ba","a","a","b","ba"};
				_expected = 13;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}
			/*case 5:
			{
				string lines[] = ;
				_expected = ;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string lines[] = ;
				_expected = ;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string lines[] = ;
				_expected = ;
				_received = _obj.minPresses(vector <string>(lines, lines+sizeof(lines)/sizeof(string))); break;
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
