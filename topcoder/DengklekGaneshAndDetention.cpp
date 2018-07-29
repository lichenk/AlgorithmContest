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
#define fst first
#define snd second

	double bf(int N, vector<int> lamps, vector<ld> probs) {
		int n=N;
		vector<int> suffixsum=lamps; suffixsum.PB(0);
		for (int i=n-1;i>=0;i--) suffixsum[i]+=suffixsum[i+1];
		map<int,ld> f[2][2];
		int cur=0,nxt=1;
		f[cur][0][0]=1;
		ld final=0;
		for (int x=0;x<n;x++) {
			for (int t=0;t<2;t++) f[nxt][t].clear();
			for (int t=0;t<2;t++) {
				if (lamps[x]^t) {
					for (auto &w:f[cur][t]) {
						int prevon=w.fst;
						ld nowprob=w.snd;
						//printf("x:%d t:%d prevon:%d nowprob:%f\n",x,t,prevon,nowprob);
						{
							ld heads=probs[x]*nowprob;
							final+=heads*(x-prevon);
							//printf("x:%d t:%d heads:%f x-prevon:%d\n",x,t,heads,x-prevon);
							f[nxt][t][x-prevon+1]+=heads;
						}
						{
							ld tails=(1-probs[x])*nowprob;
							int suffix=suffixsum[x+1];
							if (t==0) suffix=(n-x-1)-suffix;
							//printf("x:%d t:%d tails:%f suffix:%d\n",x,t,tails,suffix);
							final+=tails*suffix;
							f[nxt][t^1][prevon+1]+=tails;
						}
					}
				}
				else {
					for (auto &w:f[cur][t]) {
						int prevon=w.fst; ld nowprob=w.snd;
						f[nxt][t][prevon]+=nowprob;
					}
				}
			}
			swap(cur,nxt);
		}
		return final;
	}


const int mn=1e6+4;
vector<int> lamps; vector<ld> probs; vector<int> suffixlamps;
typedef struct ST {
	ld E[2];
	ld P[2];
	ld ansright;
} S;
S dp[2][2];
int n;
void f(int x, int toggle) {
	S ans;
	if (x==n) {
		ans.E[0]=ans.E[1]=0;
		ans.P[0]=1; ans.P[1]=0;
		ans.ansright=0;
	}
	else if (lamps[x]^toggle) {
		for (int t=0;t<2;t++) {ans.E[t]=0; ans.P[t]=0;}
		ans.ansright=0;
		// Heads
		ld headprob=probs[x];
		S head=dp[(x+1)&1][toggle];
		for (int t=0;t<2;t++) {
			ans.E[t^1]+=headprob*(head.E[t^1]+head.P[t]);
			ans.P[t^1]+=headprob*head.P[t];
		}
		ld tailprob=1-headprob;
		S tail=dp[(x+1)&1][toggle^1];
		for (int t=0;t<2;t++) {
			ans.E[t]+=tailprob*tail.E[t];
			ans.P[t]+=tailprob*tail.P[t];
		}
		int suffixadd=suffixlamps[x+1];
		if (!toggle) suffixadd=n-1-x-suffixadd;
		ans.ansright+=headprob*head.ansright;
		//printf("A:%f\n",ans.ansright);
		ans.ansright+=tailprob*(tail.ansright+suffixadd);
		//printf("B:%f\n",ans.ansright);
		ans.ansright+=headprob*head.E[0]+tailprob*tail.E[0];
		//printf("C:%f\n",ans.ansright);
	}
	else {
		ans=dp[(x+1)&1][toggle];
		ans.ansright+=ans.E[1];
	}
	//printf("x:%d toggle:%d ansright:%f E0:%f E1:%f P0:%f P1:%f\n",x,toggle,ans.ansright,
	//	ans.E[0],ans.E[1],ans.P[0],ans.P[1]);
	dp[x&1][toggle]=ans;
}
double smart(int N) {// vector<int> vlamps, vector<ld> vprobs) {
	//lamps=vlamps; probs=vprobs;
	//for (int i=0;i<=N;i++) for (int t=0;t<2;t++) dp[i][t].valid=false;
	n=N;
	suffixlamps=lamps; suffixlamps.PB(0);
	for (int i=n-1;i>=0;i--) {
		suffixlamps[i]=suffixlamps[i+1]+lamps[i];
	}
	for (int x=n;x>=0;x--) for (int t=0;t<2;t++) f(x,t);
	return dp[0][0].ansright;
}
/*
void bf() {
	for (int k=0;k<50;k++) {
		int seed=time(0)+clock()+rand();
		srand(seed);
		int N=rand()%500+1;
		vector<int> vlamps; vector<ld> vprobs;
		for (int i=0;i<N;i++) {
			vlamps.PB(rand()%2);
			vprobs.PB((ld)(rand()%101)/100.0);
		}
		double brute=bf(N,vlamps,vprobs);
		double sma=smart(N,vlamps,vprobs);
		if (fabs(brute-sma)>1e-6) {
			for (auto &w:vlamps) printf("%d ",w); printf("\n");
			for (auto &w:vprobs) printf("%f ",w); printf("\n");
			printf("N:%d correct:%f sma:%f seed:%d\n",N,brute,sma,seed);
			exit(0);
		}
		//printf("Passed\n");
	}
	printf("Passed bf\n");
}
*/
int val[mn];
class DengklekGaneshAndDetention {
	public:
	double getExpected(int N, int valInit, int valMul, int valAdd, int valMod) {
		//bf();
		val[0]=valInit;
		for (int i=1;i<=N-1;i++) {
			val[i]=(val[i-1] * (ll)valMul + valAdd) % valMod;
		}
		//vector<int> vlamps; vector<ld> vprobs; vlamps.resize(N); vprobs.resize(N);
		lamps.resize(N); probs.resize(N);
		for (int i=0;i<=N-1;i++) {
    	lamps[i] = val[i] % 2;
    	probs[i]=((ld)(val[i] % 101))/100;
		}
		return smart(N);
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
		cout << "Testing DengklekGaneshAndDetention (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1499702733;
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
		DengklekGaneshAndDetention _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int valInit = 0;
				int valMul = 1;
				int valAdd = 25;
				int valMod = 100;
				_expected = 1.375;
				_received = _obj.getExpected(N, valInit, valMul, valAdd, valMod); break;
			}
			case 1:
			{
				int N = 3;
				int valInit = 20;
				int valMul = 2;
				int valAdd = 10;
				int valMod = 57;
				_expected = 1.06;
				_received = _obj.getExpected(N, valInit, valMul, valAdd, valMod); break;
			}
			case 2:
			{
				int N = 8;
				int valInit = 10;
				int valMul = 3;
				int valAdd = 10;
				int valMod = 29;
				_expected = 7.8002283556316;
				_received = _obj.getExpected(N, valInit, valMul, valAdd, valMod); break;
			}
			case 3:
			{
				int N = 820968;
				int valInit = 776629771;
				int valMul = 777021349;
				int valAdd = 200921492;
				int valMod = 999997457;
				_expected = 8.428130292928278E10;
				_received = _obj.getExpected(N, valInit, valMul, valAdd, valMod); break;
			}
			/*case 4:
			{
				int N = ;
				int valInit = ;
				int valMul = ;
				int valAdd = ;
				int valMod = ;
				_expected = ;
				_received = _obj.getExpected(N, valInit, valMul, valAdd, valMod); break;
			}*/
			/*case 5:
			{
				int N = ;
				int valInit = ;
				int valMul = ;
				int valAdd = ;
				int valMod = ;
				_expected = ;
				_received = _obj.getExpected(N, valInit, valMul, valAdd, valMod); break;
			}*/
			/*case 6:
			{
				int N = ;
				int valInit = ;
				int valMul = ;
				int valAdd = ;
				int valMod = ;
				_expected = ;
				_received = _obj.getExpected(N, valInit, valMul, valAdd, valMod); break;
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
