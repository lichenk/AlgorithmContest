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
const ll MAXN=54;
const ll MAXY=54*54;
ll f[MAXN][MAXY];
class KingdomAndDice {
	public:
	double newFairness(vector <int> firstDie, vector <int> secondDie, int X) {
		ll n=firstDie.size();
		set<ll> used;
		ll k=0;
		for (auto &w:firstDie) {
			if (w==0) k++;
			else used.insert(w);
		}
		sort(secondDie.begin(),secondDie.end());
		vector<ll> ran;
		ran.PB(0);
		for (auto &w:secondDie) ran.PB(w);
		ran.PB(INF);
		assert(ran.size()==n+2);
		map<ll,ll> h;
		for (ll i=0;i<=n+1;i++) {
			h[ran[i]]=i-1;
		}
		ll add_final=0;
		for (auto &w:firstDie) {
			if (w!=0) {
				auto it=h.upper_bound(w);
				add_final+=it->second;
				//printf("w:%lld got %lld %lld\n",w,it->first,it->second);
			}
		}
		map<ll,ll> sd;
		for (ll i=0;i<=n;i++) sd[secondDie[i]]=i;
		for (ll x=0;x<MAXN;x++) for (ll y=0;y<MAXY;y++) f[x][y]=INF;
		f[0][0]=0;
		for (ll x=0;x<k;x++) {
			for (ll y=0;y<MAXY;y++) {
				ll val=f[x][y];
				if (val>=INF) continue;
				//printf("%lld %lld got %lld\n",x,y,val);
				vector<ll> cand;
				if (val==0) {
					//printf("%lld %lld->%lld %lld: %lld\n",x,y,x+1,y+0,0);
					chkmin(f[x+1][y+0],0LL);
				}
				val++;
				while(used.find(val)!=used.end()) val++;
				for (ll i=0;i<=n;i++) {
					ll lo=ran[i]+1,hi=ran[i+1]-1;
					if (lo>hi) continue;
					if (val>hi) continue;
					ll take=max(val,lo);
					while(used.find(take)!=used.end()) take++;
					if (take>hi) continue;
					if (take>X) continue;
					ll newy=i;
					chkmin(f[x+1][y+i],take);
					//printf("%lld %lld->%lld %lld: %lld\n",x,y,x+1,y+i,take);
				}
			}
		}
		//printf("addfinal:%lld\n",add_final);
		pair<ll,ll> best=MP(INF,INF);
		ll mid=n*n;
		for (ll y=0;y<MAXY;y++) {
			if (f[k][y]<INF) {
				chkmin(best,MP(abs(2*(y+add_final)-mid),y+add_final));
			}
		}
		//printf("best:%lld\n",best.second);
		ld ans=best.second;
		ans/=(ld)(n*n);
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
		cout << "Testing KingdomAndDice (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470673144;
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
		KingdomAndDice _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int firstDie[] = {0, 2, 7, 0};
				int secondDie[] = {6, 3, 8, 10};
				int X = 12;
				_expected = 0.4375;
				_received = _obj.newFairness(vector <int>(firstDie, firstDie+sizeof(firstDie)/sizeof(int)), vector <int>(secondDie, secondDie+sizeof(secondDie)/sizeof(int)), X); break;
			}
			case 1:
			{
				int firstDie[] = {0, 2, 7, 0};
				int secondDie[] = {6, 3, 8, 10};
				int X = 10;
				_expected = 0.375;
				_received = _obj.newFairness(vector <int>(firstDie, firstDie+sizeof(firstDie)/sizeof(int)), vector <int>(secondDie, secondDie+sizeof(secondDie)/sizeof(int)), X); break;
			}
			case 2:
			{
				int firstDie[] = {0, 0};
				int secondDie[] = {5, 8};
				int X = 47;
				_expected = 0.5;
				_received = _obj.newFairness(vector <int>(firstDie, firstDie+sizeof(firstDie)/sizeof(int)), vector <int>(secondDie, secondDie+sizeof(secondDie)/sizeof(int)), X); break;
			}
			case 3:
			{
				int firstDie[] = {19, 50, 4};
				int secondDie[] = {26, 100, 37};
				int X = 1000;
				_expected = 0.2222222222222222;
				_received = _obj.newFairness(vector <int>(firstDie, firstDie+sizeof(firstDie)/sizeof(int)), vector <int>(secondDie, secondDie+sizeof(secondDie)/sizeof(int)), X); break;
			}
			case 4:
			{
				int firstDie[] = {6371, 0, 6256, 1852, 0, 0, 6317, 3004, 5218, 9012};
				int secondDie[] = {1557, 6318, 1560, 4519, 2012, 6316, 6315, 1559, 8215, 1561};
				int X = 10000;
				_expected = 0.49;
				_received = _obj.newFairness(vector <int>(firstDie, firstDie+sizeof(firstDie)/sizeof(int)), vector <int>(secondDie, secondDie+sizeof(secondDie)/sizeof(int)), X); break;
			}
			/*case 5:
			{
				int firstDie[] = ;
				int secondDie[] = ;
				int X = ;
				_expected = ;
				_received = _obj.newFairness(vector <int>(firstDie, firstDie+sizeof(firstDie)/sizeof(int)), vector <int>(secondDie, secondDie+sizeof(secondDie)/sizeof(int)), X); break;
			}*/
			/*case 6:
			{
				int firstDie[] = ;
				int secondDie[] = ;
				int X = ;
				_expected = ;
				_received = _obj.newFairness(vector <int>(firstDie, firstDie+sizeof(firstDie)/sizeof(int)), vector <int>(secondDie, secondDie+sizeof(secondDie)/sizeof(int)), X); break;
			}*/
			/*case 7:
			{
				int firstDie[] = ;
				int secondDie[] = ;
				int X = ;
				_expected = ;
				_received = _obj.newFairness(vector <int>(firstDie, firstDie+sizeof(firstDie)/sizeof(int)), vector <int>(secondDie, secondDie+sizeof(secondDie)/sizeof(int)), X); break;
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
