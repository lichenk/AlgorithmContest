#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const int INF = 250000000+1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

int a[50][50];
int vdist[1<<8][50][50];
struct Node{
	int d,x,y;
  Node(int d,int x,int y): d(d),x(x),y(y) {}
  bool operator < (Node a)const{
    // MUST reverse since priority_queue is a max-heap.
    // Do not just do !(a<b). This function must return false for equality.
    return a.d<d;
  }
};

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
//bitset<50> done[50];
void dij(int z, int xlim, int ylim) {
		priority_queue<Node> pq;
		for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) {
			if (vdist[z][x][y]<INF) pq.push(Node(vdist[z][x][y],x,y));
		}
		//for (int x=0;x<xlim;x++) done[x].reset();
		while(!pq.empty()) {
			auto got=pq.top();
			pq.pop();
			int dist=got.d,x=got.x,y=got.y;
			if (dist>vdist[z][x][y]) continue;
			//if (z==1) printf("x:%d y:%d dist:%d\n",x,y,dist);
			//if (done[x][y]) continue;
			//done[x][y]=true;
			if (dist<INF) {
				for (int k=0;k<4;k++) {
					int nx=x+dx[k],ny=y+dy[k];
					if (0<=nx&&nx<xlim && 0<=ny&&ny<ylim) {
						int ndist=dist;
						if (a[x][y]!=a[nx][ny]) {
							ndist+=a[nx][ny];
						}
						if (ndist<vdist[z][nx][ny]) {
							//if(z==1)printf("nx:%d ny:%d ndist:%d\n",nx,ny,ndist);
							vdist[z][nx][ny]=ndist;
							pq.push(Node(ndist,nx,ny));
						}
					}
				}
			}
		}
}

int base[256];
const int zlim=1<<8;
// Nonempty subset increasing
#define FORNESI(sub, full) for(int sub = 0 ;(sub = (sub - (full)) & (full))  ; )
int q[1<<4];
class BuildingRoads {
	public:
	int destroyRocks(vector <string> b) {
		int xlim=b.size(),ylim=b[0].size();
		for (int z=1;z<zlim;z++) for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) vdist[z][x][y]=INF;
		base['!']=0;
		base['@']=1;
		base['#']=2;
		base['$']=3;
		for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) {
			char c=b[x][y];
			if (c=='.') a[x][y]=0;
			else if ('a'<=c&&c<='z') a[x][y]=c-'a'+1;
			else if ('A'<=c&&c<='Z') a[x][y]=(c-'A'+1)*100;
			else if ('1'<=c&&c<='9') a[x][y]=(c-'1'+1)*10000;
			else if (c=='0') a[x][y]=100000;
			else {
				a[x][y]=0;
				int z=1<<base[c];
				vdist[z][x][y]=0;
				base[c]+=4;
			}
		}
		for (int z=1;z<zlim;z++) {
			FORNESI(sz,z) {
				if(sz==z) continue;
				int tz=z&(~sz);
				for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) {
					chkmin(vdist[z][x][y],vdist[tz][x][y]+vdist[sz][x][y]-a[x][y]);
				}
			}
			dij(z,xlim,ylim);
		}
		for (int z=1;z<(1<<4);z++) {
			int best=INF;
			int nz=(z<<4)|z;
			for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) chkmin(best,vdist[nz][x][y]);
			q[z]=best;
		}
		int ans=INF;
		for (int z=1;z<(1<<4);z++) {
			FORNESI(sz,z) {
				if(sz==z) continue;
				int tz=z&(~sz);
				for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) {
					chkmin(q[z],q[tz]+q[sz]);
				}
			}
			if (q[z]<INF) ans=q[z];
		}
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
		cout << "Testing BuildingRoads (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521180679;
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
		BuildingRoads _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string field[] = {"!1.!",
				                  "aab2"};
				_expected = 3;
				_received = _obj.destroyRocks(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 1:
			{
				string field[] = {"#@",
				                  "A.",
				                  "A1",
				                  "@#"};
				_expected = 100;
				_received = _obj.destroyRocks(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 2:
			{
				string field[] = {"$....",
				                  "BBBBB",
				                  "B000B",
				                  "B0$0B",
				                  "B000B",
				                  "BBBBB"};
				_expected = 100200;
				_received = _obj.destroyRocks(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 3:
			{
				string field[] = {"$a",
				                  ".B",
				                  "$3"};
				_expected = 0;
				_received = _obj.destroyRocks(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 4:
			{
				string field[] = {".#!@.$",
				                  ".11111",
				                  "..AB..",
				                  "33AB..",
				                  "$3AB..",
				                  "88888a",
				                  "#!@..."};
				_expected = 30301;
				_received = _obj.destroyRocks(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 5:
			{
				string field[] = {"0!0",
				                  "$a$",
				                  "0!0"};
				_expected = 1;
				_received = _obj.destroyRocks(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 6:
			{
				string field[] = {"00!0",
				                  "@$a$",
				                  "00!0",
				                  "00.@"
				                };
				_expected = 1;
				_received = _obj.destroyRocks(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 7:
			{
				string field[] = {"00!0",
				                  "@$a$",
				                  "00!0",
				                  "00b@"
				                };
				_expected = 3;
				_received = _obj.destroyRocks(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
			}
			case 8:
			{
				string field[] = {"3333333333333333333333333333333333333333333333333#", "39999999999999999999999999999999999999999999999993", "39OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO93", "39OKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKO93", "39OKCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCKO93", "39OKCbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbCKO93", "39OKCboooooooooooooooooooooooooooooooooooooobCKO93", "39OKCbollllllllllllllllllllllllllllllllllllobCKO93", "39OKCbolSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSlobCKO93", "39OKCbolSjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjSlobCKO93", "39OKCbolSjzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzjSlobCKO93", "39OKCbolSjzJJJJJJJJJJJJJJJJJJJJJJJJJJJJzjSlobCKO93", "39OKCbolSjzJmmmmmmmmmmmmmmmmmmmmmmmmmmJzjSlobCKO93", "39OKCbolSjzJmddddddddddddddddddddddddmJzjSlobCKO93", "39OKCbolSjzJmdUUUUUUUUUUUUUUUUUUUUUUdmJzjSlobCKO93", "39OKCbolSjzJmdULLLLLLLLLLLLLLLLLLLLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGGGGGGGGGGGGGGGGGGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMMMMMMMMMMMMMMMMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIIIIIIIIIIIIIIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxxxxxxxxxxxxIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxEEEEEEEEEExIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxEyyyyyyyyExIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxEy222222yExIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxEy211112yExIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxEy21#T12yExIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxEy21TT12yExIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxEy211112yExIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxEy222222yExIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxEyyyyyyyyExIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxEEEEEEEEEExIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIxxxxxxxxxxxxIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMIIIIIIIIIIIIIIMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGMMMMMMMMMMMMMMMMGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULGGGGGGGGGGGGGGGGGGLUdmJzjSlobCKO93", "39OKCbolSjzJmdULLLLLLLLLLLLLLLLLLLLUdmJzjSlobCKO93", "39OKCbolSjzJmdUUUUUUUUUUUUUUUUUUUUUUdmJzjSlobCKO93", "39OKCbolSjzJmddddddddddddddddddddddddmJzjSlobCKO93", "39OKCbolSjzJmmmmmmmmmmmmmmmmmmmmmmmmmmJzjSlobCKO93", "39OKCbolSjzJJJJJJJJJJJJJJJJJJJJJJJJJJJJzjSlobCKO93", "39OKCbolSjzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzjSlobCKO93", "39OKCbolSjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjSlobCKO93", "39OKCbolSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSlobCKO93", "39OKCbollllllllllllllllllllllllllllllllllllobCKO93", "39OKCboooooooooooooooooooooooooooooooooooooobCKO93", "39OKCbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbCKO93", "39OKCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCKO93", "39OKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKO93", "39OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO93", "39999999999999999999999999999999999999999999999993", "33333333333333333333333333333333333333333333333333"};
				_expected = 162631;
				_received = _obj.destroyRocks(vector <string>(field, field+sizeof(field)/sizeof(string))); break;
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
