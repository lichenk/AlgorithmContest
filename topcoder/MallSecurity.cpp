#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
#define fst first
#define snd second
const ll MOD = 1000000007LL;
const int INF = 1LL<<29LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef vector<int> vi;
typedef pair<int,int> pii;
vi va,vb,vc;
void load(vector<string> L) {
	string s = "";
	for (int i=0; i<L.size();++i) s+=L[i];
	stringstream in(s);
	int x;
	while(1) {
		int a,b,c;
		if (!(in>>a)) return;
		char tmp;
		in>>b>>c>>tmp;
		//printf("%d %d %d %c\n",a,b,c,tmp);
		va.PB(a); vb.PB(b);vc.PB(c);
	}
}
const int mn=104;

class HopcroftKarp {
public:
static const int MAXN=mn;
bitset<MAXN> g[MAXN];
static const int MAX_N = MAXN, MAX_M = MAXN;
int karp_n, karp_m;
int match[MAX_N];

int matched[MAX_M], depth[MAX_N], q[MAX_N];
int v[MAX_N], vcnt;
// matched is y to x
// match is x to y
  bool BFS(){
    int t = 0;
    for(int i = 0; i < karp_n; i++)
      if (match[i] == -1) depth[i] = 0, q[t++] = i;
      else depth[i] = -1;
    for(int h = 0; h < t; h++) {
      int cur = q[h];
      int curDepth = depth[cur];
      for(int i = 0; i < karp_m; i++) {
        if (g[cur][i]) {
          int adj=i;
          if (matched[adj] == -1)
            return true;
          int next = matched[adj];
          if (depth[next] != -1) continue;
          depth[next] = curDepth + 1, q[t++] = next;
        }
      }
    }
    return false;
  }

  bool DFS(int nod) {
    v[nod] = vcnt;
    for(int i = 0; i < karp_m; i++) {
      if (g[nod][i]) {
        int adj = i;
        int next = matched[adj];
        if (next >= 0 && (v[next] == vcnt || depth[next] != depth[nod] + 1))
          continue;
        if (next == -1 || DFS(next)) {
          match[nod] = adj;
          matched[adj] = nod;
          return true;
        }
      }
    }
    return false;
  }
	int Match(int leftPartiteSize, int rightPartiteSize)
	{
		// If you filled in g[x][y], leftPartite is for x, rightPartite is for y
		vcnt=0;
		karp_n=leftPartiteSize;
    karp_m=rightPartiteSize;
		memset(match, -1, sizeof(match[0])*karp_n);
		memset(matched, -1, sizeof(matched[0])*karp_m);
		memset(q,0,(sizeof q[0])*karp_n);
		memset(v,0,(sizeof v[0])*karp_m);
		memset(depth,0,sizeof depth);
		int ans = 0;
		while(BFS()) {
			++vcnt;
			for(int i = 0; i < karp_n; i++) if (depth[i] == 0 && DFS(i)) ans++;
		}
		return ans;
	}
};
HopcroftKarp mf;
bitset<mn> og[mn];
int h[52][mn];
int hcnt[mn];
int gid[2];
int getid(int c, int a) {
	if (h[c][a]!=-1) return h[c][a];
	h[c][a]=gid[c&1];
	++gid[c&1];
	return h[c][a];
}
vector<pair<int,int> > vg[mn];
bitset<mn> bad[2];
class MallSecurity {
	public:
	int maxGuards(int n, vector <string> escDescription) {
		memset(h,-1,sizeof h);
		load(escDescription);
		int k=va.size();
		if (n%2==0) {
			for (int i=0;i<k;i++) {
				int a=va[i],b=vb[i],c=vc[i];
				int d=c+1; if (d==n+1) d=1;
				int x=getid(c,a);
				int y=getid(d,b);
				if (c&1) swap(x,y);
				og[x][y]=true;
			}
			for (int x=0;x<gid[0];x++) {
				mf.g[x]=og[x];
			}
			int flow=mf.Match(gid[0],gid[1]);
			return gid[0]+gid[1]-flow;
		}
		for (int i=0;i<k;i++) {
			int a=va[i],b=vb[i],c=vc[i];
			int d=c+1; if (d==n+1) d=1;
			chkmax(hcnt[c],a); chkmax(hcnt[d],b);
		}
		pii best=MP(INF,INF);
		for (int c=1;c<=n;c++) {
			chkmin(best,MP(hcnt[c],c));
		}
		int csmall=best.snd;
		int csmallsz=best.fst;
		for (auto &w:vc) {
			w-=(csmall-1);
			if (w<1) w+=n;
		}

		for (int i=0;i<k;i++) {
			int a=va[i],b=vb[i],c=vc[i];
			int d=c+1; if (d==n+1) d=1;
			//printf("c:%d a:%d d:%d b:%d\n",c,a,d,b);
			if (c==1) {
				int y=getid(d,b);
				//printf("vg a:%d y:%d d:%d\n",a,y,d);
				vg[a].PB(MP(y,d));
			}
			else if (d==1) {
				int x=getid(c,a);
				//printf("vg b:%d x:%d c:%d\n",a,x,c);
				vg[b].PB(MP(x,c));
			}
			else {
				int x=getid(c,a);
				int y=getid(d,b);
				//printf("c:%d a:%d x:(%d %d)    d:%d b:%d y:(%d %d)\n",c,a,c&1,x,d,b,d&1,y);
				if (c&1) swap(x,y);
				og[x][y]=true;
			}
		}
		int final=0;
		//printf("c:%d\n",c);
		for (int zz=0;zz<(1<<csmallsz);zz++) {
			int preans=__builtin_popcount(zz);
			int z=zz<<1;
			for (int x=0;x<gid[0];x++) {
				mf.g[x]=og[x];
			}
			for (int t=0;t<2;t++) bad[t].reset();
			for (int i=1;i<=csmallsz;i++) {
				if (z&(1<<i)) {
					int x=i;
					for (auto &w:vg[x]) {
						int y=w.fst,d=w.snd;
						//if (zz==1) printf("x:%d y:%d d:%d\n",x,y,d);
						bad[d&1][y]=true;
						if (d&1) {
							for (int z=0;z<gid[0];z++) mf.g[z][y]=false;
						}
						else {
							mf.g[y].reset();
						}
					}
				}
			}
			int flow=mf.Match(gid[0],gid[1]);
			int rm=bad[0].count()+bad[1].count();
			int cand=gid[0]+gid[1]-rm-flow+preans;
			/*if (zz==1) {
				for (int x=0;x<gid[0];x++) {
					for (int y=0;y<gid[1];y++) {
						if (mf.g[x][y])printf("%d->%d\n",x,y);
					}
				}
				printf("zz:%d. gid[0]:%d gid[1]:%d rm:%d flow:%d preans:%d\n",zz,
				gid[0],gid[1],rm,flow,preans);
			}*/
			chkmax(final,cand);
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
		cout << "Testing MallSecurity (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1523766550;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MallSecurity _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 10;
				string escDescription[] = {"1 1 1,1 1 2,1 1 3,1 1 4,1 1 5,1 1 6,1 1 7,1 1 8,1 ", 
				                           "1 9,1 1 10"};
				_expected = 5;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 11;
				string escDescription[] = {"1 1 1,1 1 2,1 1 3,1 1 4,1 1 5,1 1 6,1 1 7,1 1 8,1 ", 
				                           "1 9,1 1 10"};
				_expected = 6;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 10;
				string escDescription[] = {"1 1 7,1 2 9,2 1", 
				                           " 8,1 2 6,1 1 8,1 2 3,1 2 2,2 ", 
				                           "2 4,1 1 1,2 1 2,3 2 3,1 1 5,2 1 1,4 ", 
				                           "1 7,1 1 10,3 2 5,1 2 5,3 3 1,", 
				                           "3 2 8,3 1 2,1 1 3,4 4 2,2", 
				                           " 4 6,4 2 5,2 3 3,6 4 1,5 2 8,1 3 6,1 3 7,", 
				                           "4 3 8,1 3 8,5 2 3,4 2 8,2 6 7,1 3 9,", 
				                           "1 1 4,6 1 1,2 3 1,5 1 5,6 1 8,5 ", 
				                           "2 2,3 2 10,3 3 9,1 5 2,4 1 1,1 5 10"};
				_expected = 25;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 3;
				string escDescription[] = {"1 1 1,1 1 2,1 1 3"};
				_expected = 1;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			case 4:
			{
				int N = 3;
				string escDescription[] = {"1 1 1,1 1 2"};
				_expected = 2;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			case 5:
			{
				int N = 3;
				string escDescription[] = {"1 3 1,2 1 1,2 2 1,3 1 2,3 2 2"};
				_expected = 5;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			case 6:
			{
				int N = 3;
				string escDescription[] = {"1 3 1,2 1 1,2 2 1,3 1 2,3 2 2,1 2 3"};
				_expected = 5;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
			}
			case 7:
			{
				int N = 3;
				string escDescription[] = {"1 3 1,2 1 1,2 2 1,3 1 2,3 2 2,1 1 3"};
				_expected = 4;
				_received = _obj.maxGuards(N, vector <string>(escDescription, escDescription+sizeof(escDescription)/sizeof(string))); break;
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
