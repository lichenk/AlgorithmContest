#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define KMAX 20000
char b[100][100];
ll nim[2][100][100];
//ll cycle[52][52][2500];
ll r,c;

ll mex(ll a0, ll a1, ll a2, ll a3) {
	ll a[4];
	a[0] = a0;
	a[1] = a1;
	a[2] = a2;
	a[3] = a3;
	sort(a,a+4);
	ll m = 0;
	//for (ll i = 0; i < 5; i++) {
	for (ll j = 0; j < 4; j++) {
		if (a[j] == m) m++;
	}//}
	return m;
}

void f(ll klim) {
	for (ll k = 1; k <= klim; k++) {
		ll p = (k+1)%2;
		ll d = k%2;
		//printf("%lld\n",k);
		for (ll x = 1; x <= r; x++) {
			for (ll y = 1; y <= c; y++) {
				if (b[x][y] == '#') nim[d][x][y] = -1;
				else if (b[x][y] == 'E') nim[d][x][y] = 0;
				else {
					nim[d][x][y] = mex(nim[p][x-1][y],nim[p][x+1][y],nim[p][x][y-1],nim[p][x][y+1]);
				}
				//printf("%lld,",nim[d][x][y]);
			}
			//printf("\n");
		}
	}
}


class BoardEscape {
	public:
	string findWinner(vector <string> s, int k) {
		r = s.size();
		c = s[0].length();
		for (ll i = 0; i < 100; i++) {
			for (ll j = 0; j < 100; j++) {
				b[i][j] = '#';
				nim[0][i][j] = -1;
				nim[1][i][j] = -1;
			}
		}
		for (ll i = 0; i < r; i++) {
			for (ll j = 0; j < c; j++) {
				b[i+1][j+1] = s[i][j];
			}
		}

		for (ll i = 1; i <= r; i++) {
			for (ll j = 1; j <= c; j++) {
				if (b[i][j] == '#') nim[0][i][j] = -1;
				else nim[0][i][j] = 0;
			}
		}
		int kmax = KMAX;
		if (k%2 == 1) kmax++;
		ll left = max(k - kmax, 0);
		ll ans = 0;
		ll klim = min(k, kmax);
		f(klim);
		ll d = klim%2;
		ll p = (klim+1)%2;
		//printf("left: %lld\n", left);
		for (ll i = 1; i <= r; i++) {
			for (ll j = 1; j <= c; j++) {
				if (b[i][j] == 'T') {
					ll final = nim[d][i][j];
					//printf("%lld %lld %lld %lld\n",i,j,nim[d][i][j],nim[p][i][j]);
					ans = ans ^ final;
				}
			}
		}
		if (ans == 0) {
			return "Bob";
		}
		else {
			return "Alice";
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
		cout << "Testing BoardEscape (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450455339;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BoardEscape _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s[] = {"TE"};
				int k = 2;
				_expected = "Alice";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 1:
			{
				string s[] = {"E#E",
				              "#T#",
				              "E#E"};
				int k = 1000000;
				_expected = "Bob";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 2:
			{
				string s[] = {"T.T.T.",
				              ".E.E.E"};
				int k = 1;
				_expected = "Alice";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 3:
			{
				string s[] = {"TTE"};
				int k = 6;
				_expected = "Alice";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 4:
			{
				string s[] = {"..........................",
				              "......TTT..TTT..T...T.....",
				              ".....T.....T..T.TT.TT.....",
				              "......TTT..TTT..T.T.T.....",
				              ".........T.T.T..T...T.....",
				              "......TTT..T..T.T...T.....",
				              "..........................",
				              "...E#E#E#E#E#E#E#E#E#E#...",
				              "..........................",
				              "......TTT..TTT...TTT......",
				              ".....T........T.T.........",
				              "......TTT.....T..TTT......",
				              ".....T...T...T..T...T.....",
				              "......TTT....T...TTT......",
				              "..........................",
				              "...#E#E#E#E#E#E#E#E#E#E...",
				              "..........................",
				              "....TT...T...T..T.TTT.T...",
				              "...T.....T...T..T.T...T...",
				              "...T.TT..T...TTTT.TT..T...",
				              "...T..T..T...T..T.T.......",
				              "....TT...TTT.T..T.T...T...",
				              ".........................."};
				int k = 987654321;
				_expected = "Bob";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			case 5:
			{
				string s[] = "#T.#";
				int k = 100000000;
				_expected = "Bob";
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}
			/*case 6:
			{
				string s[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
			}*/
			/*case 7:
			{
				string s[] = ;
				int k = ;
				_expected = ;
				_received = _obj.findWinner(vector <string>(s, s+sizeof(s)/sizeof(string)), k); break;
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
