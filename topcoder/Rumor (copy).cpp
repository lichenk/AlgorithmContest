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

const ll mn=55;
ll dist[mn];
bool f[2][1<<16];
ll have[mn];
ll both[mn];
class Rumor {
	public:
	int getMinimum(string knowledge, vector <string> graph) {
		ll n=knowledge.size();
		for (ll x=0;x<n;x++) dist[x]=INF;
		for (ll x=0;x<n;x++) {
			if (knowledge[x]=='Y') dist[x]=0;
		}
		for (ll t=0;t<2*n;t++) {
			for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) {
				if (graph[x][y]=='Y') chkmin(dist[y],dist[x]+1);
			}
		}
		ll maxdist=0;
		for (ll x=0;x<n;x++) chkmax(maxdist,dist[x]);
		if (maxdist==0) return 0;
		if (maxdist==INF) return -1;
		ll zlim=1; for (ll x=0;x<n;x++) zlim*=3;
		for (ll z=0;z<zlim;z++) f[0][z]=false;
		f[0][0]=true;
		bool yay=true;
		for (ll k=0;k<maxdist;k++) {
			ll cur=k&1,nxt=cur^1;
			for (ll z=0;z<zlim;z++) {
				f[nxt][z]=false;
			}
			for (ll z=0;z<zlim;z++) {
				if (f[cur][z]) {
					for (ll x=0;x<n;x++) {
						have[x]=0;
						both[x]=0;
					}
					printf("z:%lld\n",z);
					ll tmpz=z;
					for (ll x=0;x<n;x++) {
						ll got=tmpz%3;
						tmpz/=3;
						if (dist[x]==k) {
							for (ll y=0;y<n;y++) {
								if (dist[y]==k+1&&graph[x][y]=='Y') {
									have[y]|=got;
									if (got==0) both[y]++;
									printf("%lld->%lld. got:%lld\n",x,y,got);
								}
							}
						}
					}
					ll nz=0;
					for (ll x=n-1;x>=0;x--) {
						nz*=3;
						if (dist[x]==k+1) {
							ll hv=have[x],b=both[x];
							if (k+1==maxdist) {
								if (hv&&b) hv=3;
								if (b>=2) hv=3;
								if (hv!=3) yay=false;
							}
							if (b) hv=3;
							printf("z:%lld x:%lld hv:%lld b:%d\n",z,x,hv,b);
							assert(hv!=0);
							if (hv!=3) nz+=hv;
						}
					}
					f[nxt][nz]=true;
				}
			}
		}
		if (yay) return maxdist;
		else return maxdist+1;
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
			/*case 6:
			{
				string knowledge = ;
				string graph[] = ;
				_expected = ;
				_received = _obj.getMinimum(knowledge, vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
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
