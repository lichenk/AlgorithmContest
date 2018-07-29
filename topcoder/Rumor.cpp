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

const ll mn=20;
ll dist[mn][2];
bool used[mn][mn];
bool spread[mn][2];
typedef pair<ll,pair<ll,ll> > pqt;
class Rumor {
	public:
	int getMinimum(string knowledge, vector <string> graph) {
		ll n=knowledge.size();
		ll zlim=1LL<<n;
		ll final=INF;
		for (ll z=0;z<zlim;z++) {
			for (ll x=0;x<n;x++) for (ll d=0;d<=n;d++) used[x][d]=false;
			for (ll x=0;x<n;x++) for (ll t=0;t<2;t++) spread[x][t]=false;
			priority_queue<pqt,vector<pqt>, greater<pqt> > q;
			for (ll x=0;x<n;x++) for (ll t=0;t<2;t++) dist[x][t]=INF;
			for (ll y=0;y<n;y++) for (ll t=0;t<2;t++) {
				if (knowledge[y]=='Y') {
					dist[y][t]=0;
					ll pri=dist[y][t]*2+((z&(1LL<<y))?t:t^1);
					q.push(MP(pri,MP(y,t)));
				}
			}
			while(!q.empty()) {
				auto top=q.top();
				q.pop();
				ll x=top.second.first;
				ll t=top.second.second;
				ll d=dist[x][t];
				//printf("z:%lld x:%lld t:%lld d:%lld\n",z,x,t,d);
				if (spread[x][t]) continue;
				spread[x][t]=true;
				if (used[x][d]) d++;
				assert(!used[x][d]);
				used[x][d]=true;
				for (ll y=0;y<n;y++) {
					if (graph[x][y]!='Y') continue;
					ll cand=d+1;
					if (cand<dist[y][t]) {
						dist[y][t]=cand;
						ll pri=dist[y][t]*2+((z&(1LL<<y))?t:t^1);
						//printf("Push: y:%lld t:%lld cand:%lld\n",y,t,cand);
						q.push(MP(pri,MP(y,t)));
					}
				}
			}
			ll ans=0;
			for (ll x=0;x<n;x++) for (ll t=0;t<2;t++) chkmax(ans,dist[x][t]);
			chkmin(final,ans);
		}
		if (final>=INF) return -1;
		else return final;
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
		cout << "Testing Rumor (525.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472664493;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 525.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Rumor _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string knowledge = "YNN";
				string graph[] = {"NYN"
				                 ,"NNY"
				                 ,"NNN"};
				_expected = 3;
				_received = _obj.getMinimum(knowledge, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 1:
			{
				string knowledge = "YNNY";
				string graph[] = {"NYYN"
				                 ,"YNNY"
				                 ,"YNNY"
				                 ,"NYYN"};
				_expected = 1;
				_received = _obj.getMinimum(knowledge, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 2:
			{
				string knowledge = "YYYY";
				string graph[] = {"NYNN"
				                 ,"YNYN"
				                 ,"NYNY"
				                 ,"NNYN"};
				_expected = 0;
				_received = _obj.getMinimum(knowledge, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 3:
			{
				string knowledge = "YYYYYN";
				string graph[] = {"NYYYYN"
				                 ,"YNYYYN"
				                 ,"YYNYYN"
				                 ,"YYYNYN"
				                 ,"YYYYNN"
				                 ,"NNNNNN"};
				_expected = -1;
				_received = _obj.getMinimum(knowledge, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 4:
			{
				string knowledge = "NNNY";
				string graph[] = {"NNNN"
				                 ,"YNNN"
				                 ,"YNNN"
				                 ,"NYYN"};
				_expected = 3;
				_received = _obj.getMinimum(knowledge, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 5:
			{
				string knowledge =  "NNNNNNNYYY";
				string graph[] = {"NYNNYNNYNN"
				                 ,"NNYNYNNNNY"
				                 ,"YYNNNYNNNN"
				                 ,"YNNNYNYNNN"
				                 ,"NNYNNYNNYN"
				                 ,"NNNNYNNNYY"
				                 ,"NYNYNYNNNN"
				                 ,"NNNNNNYNYY"
				                 ,"NNNYNNNYNY"
				                 ,"NYYNNNNYNN"};
				_expected = 2;
				_received = _obj.getMinimum(knowledge, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 6:
			{
				string knowledge = "NYNNNNNNNNNNNYN";
				string graph[] = {"NNYNNYNNYYYNNYN", "NNNYYYNNNNNNNNY", "YNNNNNNNYNNYYNN", "NNNNYYYNYYNNNNN", "YNYNNNNNNNNNNNY", "NNNNNNNNNNNNNNN", "NYNNYYNNNNNNNNN", "NYNYNNYNNNNNNYN", "NYNNNNNNNNNNYNN", "NNYNYNNYYNNNNNN", "NNNNNYNNYNNNNNN", "NYNNNNYYNNNNYNN", "NNNNNYNNNNNNNYN", "NNNYYYNNNNNNYNN", "NNYNNNNNNNNNNNN"};
				_expected = 4;
				_received = _obj.getMinimum(knowledge, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			/*case 7:
			{
				string knowledge = ;
				string graph[] = ;
				_expected = ;
				_received = _obj.getMinimum(knowledge, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string knowledge = ;
				string graph[] = ;
				_expected = ;
				_received = _obj.getMinimum(knowledge, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
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
