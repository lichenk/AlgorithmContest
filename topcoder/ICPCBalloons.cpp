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
class ICPCBalloons {
	public:
	int minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted) {
		ll m=balloonCount.size();
		vector<ll> have[2];
		for (ll i=0;i<m;i++) {
			if (balloonSize[i]=='L') have[0].PB(balloonCount[i]);
			else have[1].PB(balloonCount[i]);
		}
		for (ll i=0;i<2;i++) sort(have[i].begin(),have[i].end(),greater<ll>());
		for (ll i=0;i<2;i++) have[i].resize(50);
		ll sum[2]; for (ll i=0;i<2;i++) sum[i]=0;
		for (ll i=0;i<2;i++) for (auto &w: have[i]) sum[i]+=w;
		ll k=maxAccepted.size();
		sort(maxAccepted.begin(),maxAccepted.end(),greater<ll>());
		ll klim=1LL<<k;
		ll ans=1LL<<60LL;
		for (ll z=0;z<klim;z++) {
			vector<ll> want[2];
			for (ll i=0;i<k;i++) {
				if (z&(1LL<<(k-1-i))) want[1].PB(maxAccepted[i]);
				else want[0].PB(maxAccepted[i]);
			}
			for (ll i=0;i<2;i++) want[i].resize(50);
			/*if (z==25) {
				for (ll t=0;t<2;t++) {
					for (auto &w: want[t]) printf("%lld ", w);
					printf("\n");
				}
				for (ll t=0;t<2;t++) {
					for (auto &w: have[t]) printf("%lld ", w);
					printf("\n");
				}
			}*/
			bool ok=true;
			ll cand=0;
			for (ll i=0;i<2;i++) {
				ll pos=0,neg=0;
				for (ll x=0;x<50;x++) {
					ll val=have[i][x]-want[i][x];
					if (val>0) pos+=val;
					else neg-=val;
				}
				//printf("%lld: %lld %lld\n",z,pos,neg);
				if (pos<neg) ok=false;
				else cand+=min(pos,neg);
			}
			if(!ok) continue;
			//printf("ok:%lld %d\n",z,ok);
			chkmin(ans,cand);
		}
		if (ans>=1LL<<60LL) return -1;
		else return ans;
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
		cout << "Testing ICPCBalloons (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1464187154;
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
		ICPCBalloons _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int balloonCount[] = {100};
				string balloonSize = "L";
				int maxAccepted[] = {1,2,3,4,5};
				_expected = 10;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 1:
			{
				int balloonCount[] = {100};
				string balloonSize = "M";
				int maxAccepted[] = {10,20,30,40,50};
				_expected = -1;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 2:
			{
				int balloonCount[] = {5,6,1,5,6,1,5,6,1};
				string balloonSize = "MLMMLMMLM";
				int maxAccepted[] = {7,7,4,4,7,7};
				_expected = 6;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 3:
			{
				int balloonCount[] = {100,100};
				string balloonSize = "ML";
				int maxAccepted[] = {50,51,51};
				_expected = -1;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 4:
			{
				int balloonCount[] = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9};
				string balloonSize = "MMMLLLMMLLMLMLM";
				int maxAccepted[] = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2};
				_expected = 5;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 5:
			{
				int balloonCount[] = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9};
				string balloonSize = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL";
				int maxAccepted[] = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47};
				_expected = 210;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			case 6:
			{
				int balloonCount[] = {46, 57, 33, 47, 52, 30, 30, 62, 51, 9, 22, 60, 46, 2, 18, 37, 28, 58};
				string balloonSize = "LLLLLLMLLLLLLLLLLL";
				int maxAccepted[] = {68, 61, 21, 83, 90, 58, 58, 15, 69, 24, 7, 35, 11, 23, 63};
				_expected = 124;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}
			/*case 7:
			{
				int balloonCount[] = ;
				string balloonSize = ;
				int maxAccepted[] = ;
				_expected = ;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int balloonCount[] = ;
				string balloonSize = ;
				int maxAccepted[] = ;
				_expected = ;
				_received = _obj.minRepaintings(vector <int>(balloonCount, balloonCount+sizeof(balloonCount)/sizeof(int)), balloonSize, vector <int>(maxAccepted, maxAccepted+sizeof(maxAccepted)/sizeof(int))); break;
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
