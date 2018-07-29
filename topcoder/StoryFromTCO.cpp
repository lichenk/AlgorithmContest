#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
const ll INF = 0x7fffffff;
pair<ll,ll> p[1008];
class StoryFromTCO {
	public:
	int minimumChanges(vector <int> places, vector <int> cutoff) {
		ll n=places.size();
		for (ll i=0;i<n;i++) {
			p[i]=MP(cutoff[i],places[i]);
		}
		sort(p,p+n);
		for (ll i=0;i<n;i++) {
			places[i]=p[i].second;
			cutoff[i]=p[i].first;
		}
		ll final=0;
		multiset<ll, greater<ll> > s;
		for (ll i=0;i<n;i++) {
			if (places[i] > cutoff[i]) {
				auto it = s.lower_bound(cutoff[i]);
				if (it != s.end()) {
					ll got = *it;
					s.erase(it);
					if (places[i] < INF) {s.insert(places[i]);}
					places[i] = got;
					//printf("%d,%d gets %d\n",i,cutoff[i],got);
					final++;
				}
				else {
					for (ll j=n-1;j>=i+1;j--) {
						if (places[j] <= cutoff[i]) {
							ll oldplacej = places[j];
							places[j] = INF;
							if (places[i] < INF) {s.insert(places[i]);}
							places[i] = oldplacej;
							//printf("%d,%d steals %d from %d\n",i,cutoff[i],oldplacej,j);
							final++;
							break;
						}
					}
				}
			}
		}
		bool ok=true;
		for (ll i=0;i<n;i++) {
			//printf("pl:%d co:%d\n",places[i],cutoff[i]);
			if (!(places[i]<=cutoff[i])) ok=false;
		}
		/*for (auto &w:s) {
			printf("s:%d\n",w);
		}*/
		if (ok) return final;
		else return -1;
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
		cout << "Testing StoryFromTCO (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1455087983;
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
		StoryFromTCO _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int places[] = {20,100,500,50};
				int cutoff[] = {7500,2250,150,24};
				_expected = 3;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 1:
			{
				int places[] = {5,4,3,2,1};
				int cutoff[] = {5,4,3,2,1};
				_expected = 0;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 2:
			{
				int places[] = {1,5,5,5};
				int cutoff[] = {8,6,4,2};
				_expected = -1;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 3:
			{
				int places[] = {3,1,5};
				int cutoff[] = {6,4,2};
				_expected = 3;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 4:
			{
				int places[] = {14,11,42,9,19};
				int cutoff[] = {11,16,37,41,47};
				_expected = 4;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 5:
			{
				int places[] = {4,1,3,3,2,4,5,5,4,4};
				int cutoff[] = {3,3,5,2,4,4,5,4,3,5};
				_expected = 6;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			case 6:
			{
				int places[] = {213,177,237,444,497,315,294,104,522,635,13,26,22,276,88,249,374,17,42,245,80,553,121,625,62,105,
				               53,132,178,250,18,210,492,181,2,99,29,21,62,218,188,584,702,63,41,79,28,452,2};
				int cutoff[] = {33,40,41,48,74,84,117,125,126,164,197,197,201,218,222,231,244,277,290,309,321,321,360,376,440,
				               442,465,477,491,513,639,645,647,675,706,710,726,736,736,765,801,838,845,854,863,865,887,902,908};
				_expected = 23;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}
			/*case 7:
			{
				int places[] = ;
				int cutoff[] = ;
				_expected = ;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int places[] = ;
				int cutoff[] = ;
				_expected = ;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int places[] = ;
				int cutoff[] = ;
				_expected = ;
				_received = _obj.minimumChanges(vector <int>(places, places+sizeof(places)/sizeof(int)), vector <int>(cutoff, cutoff+sizeof(cutoff)/sizeof(int))); break;
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
