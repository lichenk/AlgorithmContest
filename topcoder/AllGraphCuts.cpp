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
const ll MAXN=64;
ll g[MAXN][MAXN];
ll n;
ll go(ll x, ll p, ll dest) {
	//if(dest==1) printf("go:%lld %lld\n",x,p);
	for (ll y=0;y<n;y++) {
		if (g[x][y]==UNDEF) continue;
		if (y==x||y==p) continue;
		if (y==dest) return g[x][y];
		ll cand=go(y,x,dest);
		if (cand!=UNDEF) return min(cand,g[x][y]);
	}
	return UNDEF;
}
class AllGraphCuts {
	public:
	vector <int> findGraph(vector <int> input) {
		vector<int> fail = {-1};
		n=round(sqrt(input.size()));
		vector<pair<ll,pair<ll,ll> > > v;
		for (ll x=0;x<n;x++) {
			if (input[x*n+x]!=0) return fail;
		}
		for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) {
			if (input[x*n+y]!=input[y*n+x]) return fail;
		}
		for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) g[x][y]=UNDEF;
		for (ll x=0;x<n;x++) {
			for (ll y=x+1;y<n;y++) {
				v.PB(MP(input[x*n+y],MP(x,y)));
			}
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		for (auto &q: v) {
			ll w=q.first;
			ll x=q.second.first,y=q.second.second;
			//printf("Src:%lld Dest:%lld\n",x,y);
			ll p=go(x,-1,y);
			if (p==UNDEF) {
				g[x][y]=w;
				g[y][x]=w;
			}
			else if (p==w) {
				//pass
			}
			else {
				return fail;
			}
		}
		vector<int> final;
		for (ll x=0;x<n;x++) {
			for (ll y=x+1;y<n;y++) {
				if (g[x][y]!=UNDEF) {
					//printf("%lld %lld: %lld\n",x,y,g[x][y]);
					final.PB(g[x][y]*n*n + x*n + y);
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
		cout << "Testing AllGraphCuts (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460226979;
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
		AllGraphCuts _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0,1,
				           1,0};
				int __expected[] = {6 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGraph(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {0,1,
				           1,1};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGraph(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {0,2,2,
				           2,0,2,
				           2,2,0};
				int __expected[] = {10, 11, 14 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGraph(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {0,1,2,3,4,
				           1,0,2,3,4,
				           1,2,0,3,4,
				           1,2,3,0,4,
				           1,2,3,4,0};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGraph(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {0,0,0,0};
				int __expected[] = {2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGraph(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 5:
			{
				int x[] = {
				          0, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3044, 3082,
				          2545, 0, 2348, 2545, 2545, 2545, 2013, 2545, 2545, 2440, 2495, 2262, 2342, 2545, 2545, 2545, 2545, 2545, 2545, 2545,
				          2348, 2348, 0, 2348, 2348, 2348, 2013, 2348, 2348, 2348, 2348, 2262, 2342, 2348, 2348, 2348, 2348, 2348, 2348, 2348,
				          2993, 2545, 2348, 0, 2606, 2623, 2013, 2993, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 2993, 2993,
				          2606, 2545, 2348, 2606, 0, 2606, 2013, 2606, 2606, 2440, 2495, 2262, 2342, 2606, 2606, 2606, 2606, 2606, 2606, 2606,
				          2623, 2545, 2348, 2623, 2606, 0, 2013, 2623, 2623, 2440, 2495, 2262, 2342, 2617, 2623, 2623, 2623, 2623, 2623, 2623,
				          2013, 2013, 2013, 2013, 2013, 2013, 0, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013, 2013,
				          3001, 2545, 2348, 2993, 2606, 2623, 2013, 0, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3001, 3001,
				          2626, 2545, 2348, 2626, 2606, 2623, 2013, 2626, 0, 2440, 2495, 2262, 2342, 2617, 2626, 2626, 2626, 2626, 2626, 2626,
				          2440, 2440, 2348, 2440, 2440, 2440, 2013, 2440, 2440, 0, 2440, 2262, 2342, 2440, 2440, 2440, 2440, 2440, 2440, 2440,
				          2495, 2495, 2348, 2495, 2495, 2495, 2013, 2495, 2495, 2440, 0, 2262, 2342, 2495, 2495, 2495, 2495, 2495, 2495, 2495,
				          2262, 2262, 2262, 2262, 2262, 2262, 2013, 2262, 2262, 2262, 2262, 0, 2262, 2262, 2262, 2262, 2262, 2262, 2262, 2262,
				          2342, 2342, 2342, 2342, 2342, 2342, 2013, 2342, 2342, 2342, 2342, 2262, 0, 2342, 2342, 2342, 2342, 2342, 2342, 2342,
				          2617, 2545, 2348, 2617, 2606, 2617, 2013, 2617, 2617, 2440, 2495, 2262, 2342, 0, 2617, 2617, 2617, 2617, 2617, 2617,
				          2773, 2545, 2348, 2773, 2606, 2623, 2013, 2773, 2626, 2440, 2495, 2262, 2342, 2617, 0, 2662, 2736, 2773, 2773, 2773,
				          2662, 2545, 2348, 2662, 2606, 2623, 2013, 2662, 2626, 2440, 2495, 2262, 2342, 2617, 2662, 0, 2662, 2662, 2662, 2662,
				          2736, 2545, 2348, 2736, 2606, 2623, 2013, 2736, 2626, 2440, 2495, 2262, 2342, 2617, 2736, 2662, 0, 2736, 2736, 2736,
				          2827, 2545, 2348, 2827, 2606, 2623, 2013, 2827, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 0, 2827, 2827,
				          3044, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 0, 3044,
				          3082, 2545, 2348, 2993, 2606, 2623, 2013, 3001, 2626, 2440, 2495, 2262, 2342, 2617, 2773, 2662, 2736, 2827, 3044, 0
				          };
				int __expected[] = {76801, 87602, 76403, 15604, 14005, 14406, 95607, 14408, 45609, 54010, 113211, 102812, 53613, 72414, 10015, 90416, 110417, 108818, 76819, 20022, 5223, 16824, 14025, 20426, 37227, 115628, 118829, 105230, 39631, 114032, 70833, 2434, 9235, 71636, 3637, 108438, 68439, 16443, 24444, 37245, 54046, 118447, 46048, 13249, 38450, 27651, 23652, 105253, 76054, 22455, 112056, 5657, 82458, 28859, 31264, 117665, 73666, 91667, 11268, 67269, 110870, 18471, 114872, 119673, 22074, 86075, 44876, 22477, 74478, 93679, 96085, 8486, 59687, 110088, 1689, 107290, 56091, 56092, 74893, 61294, 109295, 109296, 18097, 66498, 20899, 12506, 98907, 82908, 77309, 51710, 110111, 108112, 22513, 66514, 43315, 36516, 19717, 15318, 26519, 34127, 70128, 8929, 20930, 131, 81732, 80133, 29334, 68935, 53336, 81737, 36538, 57739, 35348, 96149, 25750, 19351, 15752, 4153, 80554, 107355, 96556, 70557, 66958, 48559, 33769, 81370, 55771, 15372, 61373, 72574, 11375, 2976, 66577, 108178, 57779, 590, 78991, 14992, 10593, 69794, 47395, 33796, 113397, 77398, 68999, 77811, 28212, 12613, 64614, 80215, 9816, 27017, 30618, 73819, 46632, 66633, 7834, 100635, 636, 7437, 4238, 76639, 87453, 16254, 10255, 31856, 50257, 18258, 3459, 73474, 69475, 63876, 41077, 3878, 28679, 13495, 56696, 109497, 101098, 116699, 60316, 107517, 12318, 98719, 51137, 91138, 81139, 108358, 119959, 106379 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGraph(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGraph(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGraph(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGraph(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
