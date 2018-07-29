#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000009LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
const ll MAXN=42;
ll c[42][42];
ll s[42][42];
pair<ll,ll> getseen(ll rot, ll xlim, ll ylim,ll t,ll y) {
	if (rot==0) return MP(t,y);
	else if (rot==1) return MP(xlim+1-t,y);
	else if (rot==2) return MP(y,t);
	else return MP(y,xlim+1-t);	
}
ll bar(ll rot, ll xlim, ll ylim) {
	/*for (ll x=1;x<=xlim;x++) {
		for (ll y=1;y<=ylim;y++) {
			printf("%d ",c[x][y]);
		}
		printf("\n");
	}*/
	// Search for straight
	ll ans=0;
	for (ll x=1;x<=xlim;x++) {
		set<ll> stuff;
		for (ll y0=2;y0<=ylim-1;y0++) {
			for (ll y1=y0;y1<=ylim-1;y1++) {
				bool ok=true;
				for (ll y=y0;y<=y1;y++) {
					if (c[x-1][y]==1) {ok=false;}////printf("A");}
				}
				for (ll t=x;t<=xlim;t++) {
					if (c[t][y0-1]==1) {ok=false;} ////printf("B");}
					if (c[t][y1+1]==1) {ok=false;} ////printf("C");}
				}
				for (ll t=x;t<=xlim;t++) {
					for (ll y=y0;y<=y1;y++) {
						if (c[t][y]!=1) {ok=false;} ////printf("D");}
					}
				}
				if (ok) {
					//printf("x %d y %d %d ok %d\n",x,y0,y1,ok);
					for (ll t=x;t<=xlim;t++) {
						for (ll y=y0;y<=y1;y++)  {
							if (rot==0) s[t][y]|=1ULL<<rot;
							else if (rot==1) s[xlim+1-t][y]|=1ULL<<rot;
							else if (rot==2) s[y][t]|=1ULL<<rot;
							else s[y][xlim+1-t]|=1ULL<<rot;
						}
					}
					pair<ll,ll> seenp=getseen(rot,xlim,ylim,x,y0);
					if (s[seenp.first][seenp.second]&(1ULL<<(rot^1))) {
						// Do nothing due to reflection
					}
					else {
						for (ll i=y0;i<=y1;i++) stuff.insert(i);
					}
				}
			}
		}
		ll cnt=stuff.size();
		//if (cnt>0) printf("cnt:%d times %d\n",cnt,xlim-x+1);
		ans+=((1ULL<<cnt)-1)*(xlim-x+1);
		ans%=MOD;
	}
	//printf("rot %d got %d\n",rot,ans);
	return ans;
}
ll bx,by,cx,cy;
ll di[]={1,-1,0,0};
ll dj[]={0,0,1,-1};
ll b[MAXN][MAXN];
bool sn[2*MAXN][2*MAXN];
bool dfs(ll x,ll y) {
	if(b[bx+x][by+y]!=b[cx+x][cy+y]) return false;
	if (sn[x+MAXN][y+MAXN]) return true;
	sn[x+MAXN][y+MAXN]=1;
	if(b[bx+x][by+y]!=1) return true;
	for (ll z=0;z<4;z++) {
		ll i=di[z],j=dj[z];
		if(!dfs(x+i,y+j)) return false;
	}
	return true;
}
bool reach(ll x,ll y) {
	////printf("reach: %d %d\n",x,y);
	sn[x][y]=true;
	if (b[x][y]==2) return true;
	for (ll z=0;z<4;z++) {
		ll i=di[z],j=dj[z];
		ll nx=x+i,ny=y+j;
		if (!sn[nx][ny]&&b[nx][ny]) {
			if(reach(nx,ny)) return true;
		}
	}
	return false;
}
class CoinsGame {
	public:
	int ways(vector <string> board) {
		ll xlim=board.size(),ylim=board[0].length();
		for (ll x=0;x<=xlim+1;x++) for (ll y=0;y<=ylim+1;y++) b[x][y]=2;
		for (ll x=1;x<=xlim;x++) for (ll y=1;y<=ylim;y++) b[x][y]=(board[x-1][y-1]=='.')?1:0;
		ll final=0;
		for (ll rot=0;rot<4;rot++) {
			for (ll x=0;x<MAXN;x++) for (ll y=0;y<MAXN;y++) c[x][y]=2;
			if (rot==0){
				for (ll x=1;x<=xlim;x++) for (ll y=1;y<=ylim;y++) c[x][y]=b[x][y];
				final+=bar(rot,xlim,ylim);
			}
			if (rot==1){
				for (ll x=1;x<=xlim;x++) for (ll y=1;y<=ylim;y++) c[xlim+1-x][y]=b[x][y];
				final+=bar(rot,xlim,ylim);
			}
			if (rot==2){
				for (ll x=1;x<=xlim;x++) for (ll y=1;y<=ylim;y++) c[y][x]=b[x][y];
				final+=bar(rot,ylim,xlim);
			}
			if (rot==3){
				for (ll x=1;x<=xlim;x++) for (ll y=1;y<=ylim;y++) c[ylim+1-y][x]=b[x][y];
				final+=bar(rot,ylim,xlim);
			}
		}
		for (ll x=1;x<=xlim;x++) for (ll y=1;y<=ylim;y++) {
			bool minused=false;
			for (ll a=0;a<2;a++) for (ll b=2;b<4;b++) {
				ll msk=(1ULL<<a)|(1ULL<<b);
				if (!minused&&((s[x][y]&msk)==msk)) {
					final--;
					//printf("Minus due to %d %d. %d\n",x,y,s[x][y]);
					minused=true;
				}
			}
		}
		// Noreach?
		ll noreach=0;
		for (ll x=1;x<=xlim;x++) 
			for (ll y=1;y<=ylim;y++) {
				if (s[x][y]) continue;
				for (ll i=0;i<2*MAXN;i++)for (ll j=0;j<2*MAXN;j++) sn[i][j]=false;
				if (b[x][y]&&!reach(x,y)) {
					s[x][y]=true;
					noreach++;
				}
			}
		ll noreachpow=1;
		for (ll i=0;i<noreach;i++) noreachpow=(noreachpow*2)%MOD;
		noreachpow--;
		//printf("nr:%d nrp:%d\n",noreach,noreachpow);
		final=(final+noreachpow)%MOD;
		// Search for similar
		for (ll x0=1;x0<=xlim;x0++) {
			for (ll y0=1;y0<=ylim;y0++) {
				if (s[x0][y0]) continue;
				if (b[x0][y0]==0) continue;
				s[x0][y0]=true;
				ll cnt=1;
				for (ll x1=x0;x1<=xlim;x1++) {
					for (ll y1=y0;y1<=ylim;y1++) {
						if (!(x0==x1||y0==y1)) continue;
						if (s[x1][y1]) continue;
						if (b[x1][y1]==0) continue;
						for (ll i=0;i<2*MAXN;i++)for (ll j=0;j<2*MAXN;j++) sn[i][j]=false;
						bx=x0,by=y0,cx=x1,cy=y1;
						if (dfs(0,0)) {
							cnt++;
							s[x1][y1]=true;
						}
					}
				}
				//printf("%d %d has cnt %d\n",x0,y0,cnt);
				final+=(1ULL<<cnt)-1;
				final%=MOD;
			}
		}
		final++;
		ll ans=1;
		for (ll x=1;x<=xlim;x++)
			for (ll y=1;y<=ylim;y++) {
				if (b[x][y]==1) ans=(ans*2)%MOD;
			}
		//printf("ans:%d final:%d\n",ans,final);
		ans=(ans-final+MOD)%MOD;
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
		cout << "Testing CoinsGame (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463354825;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CoinsGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {".."};
				_expected = 1;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"##.#",
				                  ".###",
				                  "###.",
				                  "#.##"};
				_expected = 11;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {"####",
				                  "#..#",
				                  "#..#",
				                  "####"};
				_expected = 0;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"#.#.#"};
				_expected = 0;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {"........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........",
				                  "........"};
				_expected = 688856388;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"#.",
				                  "##"};
				_expected = 0;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 6:
			{
				string board[] = {"########",
				                  "#..##..#",
				                  "##.###.#",
				                  "##.###.#",
				                  "##.###.#",
				                  "##.###.#",
				                  "##.###.#",
				                  "##.###.#"};
				_expected = ((1<<16)-3*8-1)%MOD;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 7:
			{
				string board[] = {"."};
				_expected = 0;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 8:
			{
				string board[] = {"#..#",
													"#..#",
													"####"};
				_expected = 9;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 9:
			{
				string board[] = {"#..",
													"#..",
													"###"};
				_expected = (1<<4)-5;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 10:
			{
				string board[] = {"#..###",
													"#..#..",
													"####..",
												  "######"};
				_expected = (1<<8)-12-1;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 11:
			{
				string board[] = {"###################################", ".................#.................", ".................#.................", ".................#.................", ".................#.................", "###################################", "......#............................", "......#............................", "###################################", ".................#.................", ".................#.................", ".................#.................", ".................#.................", ".................#.................", "###################################", "......#............................", "......#............................", "......#............................", "###################################", ".................#.................", ".................#.................", ".................#.................", ".................#.................", ".................#.................", ".................#.................", "###################################", "......#............................", "......#............................", "......#............................", "......#............................", "......#............................", "......#............................", "......#............................", "......#............................", "###################################"};
				_expected = 156369431;
				_received = _obj.ways(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
