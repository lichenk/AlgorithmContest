#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1LL<<60LL;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }

const int MAXN=50;
bool g[MAXN][MAXN];
const int MAX_N = MAXN, MAX_M = MAXN;
int karp_n, karp_m;
int match[MAX_N];

int matched[MAX_M], depth[MAX_N], q[MAX_N];
int v[MAX_N], vcnt;
  bool BFS(){
    int t = 0;
    for(int i = 0; i < karp_n; i++)
      if (match[i] == -1) depth[i] = 0, q[t++] = i;
      else depth[i] = -1;
    for(int h = 0; h < t; h++) {
      int cur = q[h];
      int curDepth = depth[cur];
      for(int i = 0; i < karp_n; i++) {
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
    for(int i = 0; i < karp_n; i++) {
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
		karp_n=rightPartiteSize;
    karp_m=leftPartiteSize;
		memset(match, -1, sizeof(match));
		memset(matched, -1, sizeof(matched));
		memset(q,0,sizeof q);
		memset(v,0,sizeof v);
		memset(depth,0,sizeof depth);
		int ans = 0;
		while(BFS()) {
			++vcnt;
			for(int i = 0; i < karp_n; i++) if (depth[i] == 0 && DFS(i)) ans++;
		}
		return ans;
	}
set<string> h[52][52];
char tmp[52];

class DengklekGaneshAndChains {
	public:
	string getBestChains(vector <string> chains, vector <int> lengths) {
int n=chains.size();
		int k=chains[0].length();
		for (int l=1;l<=k;l++) {
			for (int i=0;i<n;i++) {
				string &s=chains[i];
				int slen=s.length();
				for (int x=0;x<slen;x++) {
					int j=0;
					for (int y=x;y<x+l;y++) {
						tmp[j++]=s[y>=slen?y-slen:y];
					}
					tmp[j]='\0';
					string news=string(tmp);
					h[l][i].insert(news);
				}
			}
		}
		int wantlen=0;
		for (auto &w:lengths) wantlen+=w;
		vector<int> vl; vl.PB(0);
		int lidx=0;
		int ansstart=0;
		string ans;
		ans.resize(wantlen);
		for (int ii=0;ii<wantlen;ii++) {
			if (vl.back()<lengths[lidx]) {
				vl.back()++;
			}
			else {
				ansstart=ii;
				vl.PB(1); lidx++;
			}
			int vlbk=vl.back();
			string olook="";
			for (int x=ansstart;x<ansstart+vlbk-1;x++) {
				olook.append(1,ans[x]);
			}
			int vlsz=vl.size();
			for (char c='z';c>='a';c--) {
				ans[ii]=c;
				memset(g[vlsz-1],0,sizeof g[vlsz-1]);
				int l=vl.back();
				string look=olook;
				look.append(1,c);
				for (int word=0;word<n;word++) {
					auto it=h[l][word].find(look);
					if (it!=h[l][word].end()) {
						g[vlsz-1][word]=true;
					}
				}
				int flow=Match(vlsz,n);
				if (flow>=vlsz) break;
			}
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
		cout << "Testing DengklekGaneshAndChains (300.0 points)" << endl << endl;
		for (int i = 0; i < 500; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1499529602;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DengklekGaneshAndChains _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string chains[] = {"topc", "oder", "open", "twob"};
				int lengths[] = {2, 1, 3};
				_expected = "wotrod";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 1:
			{
				string chains[] = {"ssh", "she", "see", "sea"};
				int lengths[] = {2, 3, 2, 3};
				_expected = "ssshesesee";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 2:
			{
				string chains[] = {"wri", "ter", "who", "are", "you"};
				int lengths[] = {3};
				_expected = "you";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 3:
			{
				string chains[] = {"harus", "imfyo"};
				int lengths[] = {5, 5};
				_expected = "yoimfushar";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 4:
			{
				string chains[] = {"y"};
				int lengths[] = {1};
				_expected = "y";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 5:
			{
				string chains[] = {"abcd"};
				int lengths[] = {3};
				_expected = "dab";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 6:
			{
				string chains[] = {"abcd"};
				int lengths[] = {4};
				_expected = "dabc";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 7:
			{
				string s; for (int i=0;i<50;i++) s+="a";
				vector<string> chains; for (int i=0;i<50;i++) chains.PB(s);
				vector<int> lengths; for (int i=0;i<50;i++) lengths.PB(50);
				_expected = "";for (int i=0;i<50*50;i++) _expected+="a";
				_received = _obj.getBestChains(chains,lengths); break;
			}
			case 8:
			{
				string s; for (int i=0;i<50;i++) s+="z";
				vector<string> chains; for (int i=0;i<50;i++) chains.PB(s);
				vector<int> lengths; for (int i=0;i<50;i++) lengths.PB(50);
				_expected = "";for (int i=0;i<50*50;i++) _expected+="z";
				_received = _obj.getBestChains(chains,lengths); break;
			}
			case 9:
			{
				string s; for (int i=0;i<50;i++) s+="y";
				vector<string> chains; for (int i=0;i<50;i++) chains.PB(s);
				vector<int> lengths; for (int i=0;i<50;i++) lengths.PB(50);
				_expected = "";for (int i=0;i<50*50;i++) _expected+="y";
				_received = _obj.getBestChains(chains,lengths); break;
			}
			case 10:
			{
				string chains[] = {"zza","zzb"};
				int lengths[] = {2,3};
				_expected = "zzzzb";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			case 11:
			{
				string chains[] = {"zzb","zza"};
				int lengths[] = {2,3};
				_expected = "zzzzb";
				_received = _obj.getBestChains(vector <string>(chains, chains+sizeof(chains)/sizeof(string)), vector <int>(lengths, lengths+sizeof(lengths)/sizeof(int))); break;
			}
			/*case 8:
			{
				srand(time(0));
				vector<string> chains; for (int i=0;i<50;i++) {
					string s; s.resize(50); for (int j=0;j<50;j++) s[j]='a'+(rand()%26);
					chains.PB(s);
				}
				vector<int> lengths; for (int i=0;i<50;i++) lengths.PB(50);
				_expected = "";
				_received = _obj.getBestChains(chains,lengths); break;
			}*/
			default: {
				return 0;
				/*{
					srand(time(0)+clock()+rand());
					int n=rand()%50+1;
					int k=rand()%50+1;
					vector<string> chains; for (int i=0;i<n;i++) {
						string s; s.resize(k); for (int j=0;j<k;j++) s[j]='a'+(rand()%3);
						chains.PB(s);
					}
					vector<int> lengths; for (int i=0;i<n;i++) lengths.PB(rand()%k+1);
					string received = _obj.getBestChains(chains,lengths);
					string cor=correct(chains,lengths);
					if (received!=cor) {
						for (auto &w:chains) printf("\"%s\",",w.c_str()); printf("\n");
						for (auto &w:lengths) printf("%d,",w); printf("\n");
						printf("cor:%s\n",cor.c_str());
						printf("incor:%s\n",received.c_str());
					}
					return 0;
				}*/
			}
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
