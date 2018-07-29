#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
inline ll sq(ll x) {return x*x;}
vector<pair<ll,pair<ll,ll> > > v[20][20];
int sn[20][20];
ld lf[1000];
ld lognorm;
ld binom(ll n, ll k) {
	if (n<k) return 0;
	if (k < 0) return 0;
	return exp(lf[n]-lf[n-k]-lf[k]-lognorm);
}
class ClosestRabbit {
	public:
	double getExpected(vector <string> board, int r) {
		lf[0] = 0;
		for (ll i=1;i<1000;i++) {
			lf[i]=lf[i-1]+log(i);
		}
		ll n=board.size();
		ll m=board[0].length();
		ll dots=0;
		for (ll i=0;i<n;i++) {
			for (ll j=0;j<m;j++) {
				if (board[i][j]=='.') dots++;
			}
		}
		if (dots<r) return 0;
		lognorm = lf[dots]-lf[r]-lf[dots-r]+lf[2];
		//printf("Normalizer: %d %d %f\n",dots,r,(double)lognorm);
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<m;y++) {
				if (board[x][y]!='.') continue;
				for (ll i=0;i<n;i++) {
					for (ll j=0;j<m;j++) {
						if (board[i][j]!='.') continue;
						if (i==x&&j==y) continue;
						ll dist = sq(x-i)+sq(y-j);
						v[x][y].PB(MP(dist,MP(i,j)));
					}
				}
				sort(v[x][y].begin(),v[x][y].end());
			}
		}
		ld final = 0.0;
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<m;y++) {
				if (board[x][y]!='.') continue;
				for (ll i=0;i<n;i++) {
					for (ll j=0;j<m;j++) {
						if (board[i][j]!='.') continue;
						if (i==x&&j==y) continue;
						for (ll p=0;p<n;p++) {
							for (ll q=0;q<m;q++) {
								sn[p][q] = 1;
							}
						}
						for (auto &w: v[x][y]) {
							ll p=w.second.first;
							ll q=w.second.second;
							sn[p][q] = 0;
							if (p==i&&q==j) break;
						}
						for (auto &w: v[i][j]) {
							ll p=w.second.first;
							ll q=w.second.second;
							sn[p][q] = 0;
							if (p==x&&q==y) break;
						}
						ll k=0;
						for (ll p=0;p<n;p++) {
							for (ll q=0;q<m;q++) {
								if (board[p][q] == '.') {
									k += sn[p][q];
								}
							}
						}
						ld cand = binom(k,r-2);
						//printf("%d %d %d %d. %d choose %d. %f\n",x,y,i,j,k,r-2,(double)cand);
						final += cand;
					}
				}
			}
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
		cout << "Testing ClosestRabbit (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1454997633;
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
		ClosestRabbit _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".#.#."};
				int r = 2;
				_expected = 1.0;
				_received = _obj.getExpected(vector <string>(board, board+sizeof(board)/sizeof(string)), r); break;
			}
			case 1:
			{
				string board[] = {"..###.",
				                  ".###.#"};
				int r = 4;
				_expected = 1.6;
				_received = _obj.getExpected(vector <string>(board, board+sizeof(board)/sizeof(string)), r); break;
			}
			case 2:
			{
				string board[] = {"..###.",
				                  ".###.#"};
				int r = 5;
				_expected = 2.0;
				_received = _obj.getExpected(vector <string>(board, board+sizeof(board)/sizeof(string)), r); break;
			}
			case 3:
			{
				string board[] = {".....",
				                  "#...."};
				int r = 4;
				_expected = 1.253968253968254;
				_received = _obj.getExpected(vector <string>(board, board+sizeof(board)/sizeof(string)), r); break;
			}
			case 4:
			{
				string board[] = {".#####.#####..#....#",
				                  "#......#....#.##..##",
				                  ".####..#####..#.##.#",
				                  ".....#.#...#..#....#",
				                  "#####..#....#.#....#"};
				int r = 19;
				_expected = 5.77311527122319;
				_received = _obj.getExpected(vector <string>(board, board+sizeof(board)/sizeof(string)), r); break;
			}
			/*case 5:
			{
				string board[] = ;
				int r = ;
				_expected = ;
				_received = _obj.getExpected(vector <string>(board, board+sizeof(board)/sizeof(string)), r); break;
			}*/
			/*case 6:
			{
				string board[] = ;
				int r = ;
				_expected = ;
				_received = _obj.getExpected(vector <string>(board, board+sizeof(board)/sizeof(string)), r); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				int r = ;
				_expected = ;
				_received = _obj.getExpected(vector <string>(board, board+sizeof(board)/sizeof(string)), r); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
