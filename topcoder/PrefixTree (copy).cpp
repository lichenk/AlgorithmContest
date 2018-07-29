#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef short ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define PB push_back
#define MP make_pair
const ll INF = 50*51+1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
vector<vector<ll> > gv;
vector<int> tv[1<<16];
ll tsum[1<<16];
ll n;
ll dp[1<<16][51];
void init(int iz) {
	vector<vector<ll> > v=gv;
	ll sum=0;
	for (ll c=0;c<26;c++) {
		ll cnt=INF;
		for (ll i=0;i<n;i++) {
			if ((1LL<<i)&iz) {
				chkmin(cnt,v[i][c]);
			}
		}
		for (ll i=0;i<n;i++) {
			if ((1LL<<i)&iz) {
				v[i][c]-=cnt;
			}
		}
		sum+=cnt;
	}
	tsum[iz]=sum;
	ll all=0;
	for (ll i=0;i<n;i++) if ((1LL<<i)&iz) for (ll c=0;c<26;c++) all+=v[i][c];
	if (all==0&&sum<51) dp[iz][sum]=0;
	for (ll c=0;c<26;c++) {
		int sig=0;
		for (ll i=0;i<n;i++) {
			if ((1LL<<i)&iz) {
				if (v[i][c]>0) {
					sig|=1LL<<i;
				}
			}
		}
		if (sig==0) continue;
		tv[iz].PB(sig);
	}
}
ll f(int iz, ll k) {
	ll val=dp[iz][k];
	if (val!=-1) return val;
	ll diff=tsum[iz]-k;
	if (diff>0) return dp[iz][k]=diff+f(iz,k+diff);
	ll final=INF;
	for (int sub = 0; (sub = (sub - iz) & iz);)  {
		for (auto &w:tv[iz]) {
			if ((w&sub)==sub) {
				chkmin(final,(short)(1+f(sub,k+1)+f(iz&(~sub),k)));
				break;
			}
		}
	}
	//printf("iz:%lld k:%lld final:%lld\n",iz,k,final);
	return dp[iz][k]=final;
}
class PrefixTree {
	public:
	int getNumNodes(vector <string> words) {
		for (auto &w:words) {
			map<ll,ll> h;
			for (auto &c:w) {
				h[(ll)(c-'a')]++;
			}
			vector<ll> v;
			for (ll i=0;i<26;i++) v.PB(h[i]);
				gv.PB(v);
		}
		n=gv.size();
		int zlim=1LL<<n;
		memset(dp,-1,sizeof dp);
		for (int z=1;z<zlim;z++) init(z);
		for (ll i=0;i<51;i++) dp[0][i]=0;
		return f(zlim-1,0)+1;
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
		cout << "Testing PrefixTree (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1484896076;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PrefixTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"topcoder"};
				_expected = 9;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"topcoder","topcoder"};
				_expected = 9;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"aab","ca"};
				_expected = 5;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"aab","ca","ba"};
				_expected = 5;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 4:
			{
				string words[] = {"ab","cd","ef"};
				_expected = 7;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 5:
			{
				string words[] = {"a","aa","aaa"};
				_expected = 4;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 6:
			{
				string words[] = {"a"};
				_expected = 2;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 7:
			{
				string words[] = {"z","z"};
				_expected = 2;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 8:
			{
				string words[] = {"abc","bad"};
				_expected = 5;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 9:
			{
				string words[] = {"ohjhnxhfiossggfpevwnxaacfw", "i", "uuecbrgzkxyriuzsxviabptgalnzoxjviaiopg", "tktmyukvpdcxanzslgcfhfamotajqcj", "qkzgtwcltonceubevungamytwxzluircjefwqcnnildp", "bgukh", "oljguixdfkufdwvrnrvgsif", "bwiwmux", "yfnpbkqc", "mkocauocqgzlqqhhscrjmqqc", "qyil", "xybif", "mlnoomlhwrofpcprmzzbsmrgdffbhb"};
				_expected = 162;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 10:
			{
				string words[] = {"dmjkrcgcgzomlcigumrmgwmdxxkyaiqjr", "kcekmjdxpjssayimsiymcjdsmuqupuywe", "xbwodfokvqoofywosvpugauxwzxahqtnk", "kgnwhybramfccmiimdwjkmxbekjuojihq", "zstnbeqtrsaiacjynfetaiymjzqngiige", "idfnkoubxcqqqsvhrhsayfzajberpyjfa", "fecqpqwlmxkktskybxfdzqvuqsdonoeea", "imgfivoixlfgssixknkshzyfmjenpifto", "xzifdzjvqwrevszvpteixlkqtgpbuwpkz", "jniizfhmhlymjxllhmqvbditsodqikynv", "guqaoycvctrvdjseuttcdfkhwxjvnrviw", "zeycznlizezwytehmhogakzwvbvqmvyyr", "yqpakparzqdnjeizjrespkjckrkrphgdr", "othonprovujlrjtkqnaafwbaajevhzpae", "cjtfsqgabytjdqhktlbbgsspjtzhrjohd", "aklfqqufujdncdzcaullwjtbilrbixcoc"};
				_expected = 317;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 11:
			{
				string words[] = {"topcoder", "is", "just", "a", "game", "but", "it", "is", "the", "best", "mmorpg", "i", "have", "ever", "played"};
				_expected = 37;
				_received = _obj.getNumNodes(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
