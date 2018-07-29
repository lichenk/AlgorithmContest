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
const ll mn=2004;
vector<ll> g[mn];
ll dist[mn];
class FromToDivisible {
	public:
	int shortest(int N, int S, int T, vector <int> _a, vector <int> _b) {
		if (S==T) return 0;
		vector<ll> a,b;
		for (auto &w:_a) a.PB(w);
		for (auto &w:_b) b.PB(w);
		ll m=a.size();
		for (ll x=0;x<m;x++) for (ll y=0;y<m;y++) {
			if (x==y) continue;
			ll p=b[x],q=a[y];
			ll lcm=(p*q)/__gcd(p,q);
			if (lcm<=N) {
				g[x].PB(y);
			}
		}

		for (ll x=0;x<m;x++) {
			dist[x]=INF;
		}
		priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
		for (ll x=0;x<m;x++) {
			if ((S%a[x])==0) {
				dist[x]=0;
				pq.push(MP(dist[x],x));
			}
		}
		while(!pq.empty()) {
			auto get=pq.top(); pq.pop();
			ll u=get.second,dst=get.first;
			if (dst>dist[u]) continue;
			if ((T%b[u])==0) return dist[u]+1;
			for (auto &v:g[u]) {
				ll alt=dist[u]+1;
				if (alt<dist[v]) {
					//printf("%lld->%lld\n",u,v);
					dist[v]=alt;
					pq.push(MP(dist[v],v));
				}
			}
		}
		return -1;
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
		cout << "Testing FromToDivisible (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1474904128;
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
		FromToDivisible _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 11;
				int S = 9;
				int T = 6;
				int a[] = {3,10};
				int b[] = {5,2};
				_expected = 2;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 123456789;
				int S = 18;
				int T = 12;
				int a[] = {1,42,50};
				int b[] = {1,17,3};
				_expected = 1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 60;
				int S = 30;
				int T = 8;
				int a[] = {16,15,12};
				int b[] = {2,20,5};
				_expected = -1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 77;
				int S = 10;
				int T = 62;
				int a[] = {2,5,7,4,17,26};
				int b[] = {25,7,11,13,31,34};
				_expected = 4;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 100;
				int S = 90;
				int T = 40;
				int a[] = {20,30,100,99,100};
				int b[] = {10,30,100,100,99};
				_expected = 2;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 1000000000;
				int S = 7000;
				int T = 424212345;
				int a[] = {35000000,120000000,424212345,200000000,3500,19};
				int b[] = {15,1,7000,200000000,400000000,17};
				_expected = 3;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 6:
			{
				int N = 2;
				int S = 1;
				int T = 2;
				int a[] = {2};
				int b[] = {1};
				_expected = -1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 7:
			{
				int N = 5;
				int S = 5;
				int T = 4;
				int a[] = {2};
				int b[] = {2};
				_expected = -1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 8:
			{
				int N = 10;
				int S = 6;
				int T = 8;
				int a[] = {2};
				int b[] = {2};
				_expected = 1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 9:
			{
				int N = 1000000000;
				int S = 14;
				int T = 7;
				int a[] = {7,1000000000};
				int b[] = {1000000000,7};
				_expected = 2;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 10:
			{
				int N = 1000000000;
				int S = 6;
				int T = 11;
				int a[] = {2,3};
				int b[] = {7,11};
				_expected = 1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 11:
			{
				int N = 1000000000;
				int S = 6;
				int T = 7;
				int a[] = {2,3};
				int b[] = {7,11};
				_expected = 1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 12:
			{
				int N = 1000000000;
				int S = 6;
				int T = 77;
				int a[] = {2,3};
				int b[] = {7,11};
				_expected = 1;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 13:
			{
				int N = 1000000000;
				int S = 221699492;
				int T = 869825265;
				int a[] = {906660545, 914071332, 546674226, 65436974, 36486149, 541052406, 74684889, 846035224, 714756927, 70561759, 569874292, 592953677, 718101400, 887495882, 30141044, 449916121, 13730386, 694259170, 824307829, 6918727, 69523629, 439518988, 64297856, 62701634, 717988662, 939079403, 571549186, 439518988, 864330042, 509570973, 846296315, 39037046, 367927383, 530406650, 464896663, 367927383, 37972588, 718101400, 362730712, 569874292, 756861067, 401675068, 64148788, 61457693, 1853091, 456291950, 437683803, 780926758, 402151583, 790392502, 569874292, 509570973, 774229806, 756861067, 887495882, 31008221, 59813555, 24430873, 439518988, 938070375, 906660545, 815206147, 55240555, 780926758, 10564143, 482726064, 846296315, 335892162, 402151583, 939079403, 439518988, 50597680, 335892162, 5845109, 21644, 467239961, 45844853, 402151583, 4740950, 379362613, 530406650, 26535733, 43836875, 714756927, 947203968, 927862863, 938070375, 464631653, 30873575, 717988662, 456291950, 343659772, 824879753, 592953677, 914071332, 335892162, 63813832, 52930780, 23819381, 33262379, 464896663, 467239961, 834168160, 21644, 864330042, 846035224, 401675068, 718101400, 34054864, 741279325, 694259170, 774229806, 356979952, 568832871, 569874292, 44106987, 50958426, 546674226, 996976128, 482726064, 31173818, 790392502, 362730712, 15222085, 571549186, 44561943, 824879753, 815206147, 32740421, 996976128, 530406650, 456291950, 464896663, 12874433, 780926758, 6026077, 482726064, 914071332, 568832871, 694259170, 449916121, 899371520, 996976128, 714756927, 33829152, 834168160, 887495882, 938070375, 906660545, 66682213, 718101400, 815206147, 35555112, 69696763, 437683803, 993743446, 996976128, 32675805, 8000944, 55527912, 50697748, 20516577, 927862863, 367927383, 10696452};
				int b[] = {64423968, 9821551, 938070375, 780926758, 571549186, 569874292, 927862863, 864330042, 65718887, 824307829, 33311470, 864330042, 18649526, 335892162, 887495882, 694259170, 824879753, 78460429, 914071332, 717988662, 694259170, 82690294, 717988662, 568832871, 18549127, 509570973, 335892162, 31328554, 467239961, 68128813, 343659772, 780926758, 993743446, 482726064, 717988662, 2863264, 467239961, 21380465, 482726064, 13467004, 846296315, 939079403, 993743446, 906660545, 509570973, 546674226, 26007730, 4017496, 439518988, 53348843, 28002264, 774229806, 906660545, 53161556, 834168160, 815206147, 509570973, 756861067, 464896663, 824307829, 63221441, 846035224, 887495882, 24045528, 401675068, 43814313, 32776003, 362730712, 12220929, 906660545, 717988662, 846035224, 81467516, 439518988, 41205621, 14193208, 714756927, 464896663, 509570973, 437683803, 68936705, 541052406, 362730712, 34837095, 899371520, 541052406, 914071332, 456291950, 717988662, 815206147, 824879753, 947203968, 938070375, 996976128, 887495882, 2181153, 694259170, 541052406, 482726064, 927862863, 57424961, 464631653, 571549186, 379362613, 456291950, 22764969, 71493526, 541052406, 464631653, 449916121, 790392502, 26901586, 568832871, 6393307, 401675068, 993743446, 482726064, 824879753, 32063753, 780926758, 592953677, 714756927, 530406650, 717988662, 19905715, 571549186, 83165308, 592953677, 464631653, 846035224, 39864709, 53217989, 815206147, 509570973, 356979952, 947203968, 46229781, 36124900, 756861067, 7860274, 714756927, 258185, 17300595, 718101400, 947203968, 64948714, 67993575, 20986054, 402151583, 947203968, 927862863, 60265451, 335892162, 439518988, 367927383, 741279325, 34066792, 569874292, 356979952, 401675068, 568832871, 464631653, 55443020, 58252076, 356979952};
				_expected = 35;
				_received = _obj.shortest(N, S, T, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
