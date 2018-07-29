#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ld f[1<<15];
ll neq[15];
ll ls[50];
ll gr[50];
ld solve(vector<string> words, string master) {
	//printf("%s\n",master.c_str());
	ll n=words.size();
	ll l=words[0].length();
	for (ll x=0;x<n;x++) {
		ll got=0;
		for (ll k=0;k<l;k++) {
			if (master[k]!=words[x][k]) {
				got|=1LL<<k;
			}
		}
		neq[x]=got;
	}
	for (ll k=0;k<l;k++) {
		ll got=0;
		for (ll x=0;x<n;x++) {
			if (words[x][k]<master[k])got|=1LL<<x;
		}
		ls[k]=got;
	}
	for (ll k=0;k<l;k++) {
		ll got=0;
		for (ll x=0;x<n;x++) {
			if (words[x][k]>master[k])got|=1LL<<x;
		}
		gr[k]=got;
	}

	ll zlim=1LL<<n;
	f[0]=1;
	for (ll z=1;z<zlim;z++) f[z]=0;
	for (ll z=0;z<zlim-1;z++) {
		ll unchosen=0;
		for (ll x=0;x<n;x++) {
			if (0==(z&(1LL<<x))) unchosen|=neq[x];
		}
		ll num_unchosen=__builtin_popcountll(unchosen);
		ld add_val=f[z]/num_unchosen;
		//printf("z:%lld unchosen:%lld f:%f add_val:%f\n",z,unchosen,f[z],add_val);
		for (ll k=0;k<l;k++) {
			if (unchosen&(1LL<<k)) {
				ll notz=~z;
				if (notz&ls[k]) continue;
				ll got=z|(gr[k]&notz);
				/*for (ll x=0;x<n;x++) {
					if (0==(z&(1LL<<x))) {
						if (words[x][k]<master[k]) {
							ok=false; break;
						}
						else if (words[x][k]>master[k]) {
							got|=1LL<<x;
						}
					}
					if (!ok) break;
				}
				if (!ok) continue;*/
				//printf("z:%lld k:%lld got:%lld add_val:%f\n",z,k,got,add_val);
				f[got]+=add_val;
			}
		}
	}
	return f[zlim-1];
}
class StrangeDictionary2 {
	public:
	vector <double> getProbabilities(vector <string> words) {
		ll n=words.size();
		vector<double> ans;
		if (n==1) {ans.PB(1); return ans;}
		ld last=1;
		for (ll x=0;x<n-1;x++) {
			vector<string> supply;
			for (ll y=0;y<n;y++) {
				if (y!=x) supply.PB(words[y]);
			}
			string master=words[x];
			ld get=solve(supply,master);
			last-=get;
			ans.PB(get);
		}
		ans.PB(last);
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
		cout << "Testing StrangeDictionary2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471248117;
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
		StrangeDictionary2 _obj;
		vector <double> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"hardesttestever"};
				double __expected[] = {1.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"ab", "ba"};
				double __expected[] = {0.5, 0.5 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"aza", "aab", "bba"};
				double __expected[] = {0.3333333333333333, 0.5, 0.16666666666666666 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"};
				double __expected[] = {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 };
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 4:
			{
				string words[] = {"bbkgaedkkcfaciujabesvladabicvadadbddalgucdcdrbbdcq", "bbctaedkbcfacqcbabegyladabicckdfwbddqlgbcdclbbbkfd", "bbcgaedkbcfacicfabecvladaqlccadzdbddalgbcdcdbbbdcd", "bbcgaeukbcfacicbablcvladabiczwyadhqdalgecdddbqbdcd", "wbcgaedkbcfacicxqbecvladabicyadadbddqlgbxncdbbbdcz", "bbclaeewbcfacidvabfciladabimcahadbddalgbcdvdbbbdcd", "bbclaedkbclanicbxbechladabiccawadbddalgbczcdbbbdcd", "bbcgaedkbefacicbibxcvladmticcadazbdtapgbidcdbbrdco", "bbcgaedkbcfaciobabecxlnjabiccadaxbdualgbcdtdsdbdxw", "bbcgaedkbefacicbqgecvsaoabiccadadzddalgbqdcqbbbdcd", "bbcgaedkbcfkcicbabecwladabikckdadbddawgznjcdbbbdcd", "bbcwagxkjcqacicbabecvzhdaziccndadbddfogbcdudbbbdcd", "bbcgaedkjcfacucbabecvladabiccpdadbddalibcdcdibbdcd", "bbcgsedkbcfacicbxbecyladabiccadadbddalgbcdcdbbbdcd", "bhcgaedkjcfacicbibecnladabiccadatbddelgbcdmdsbbvci", "bbcgakdkjcfacicyacecyladabiccadvdbidalgbcocdkbjocl"};
				double __expected[] = {0.018024997942205596, 0.013468341951099552, 0.16415935346366695, 0.016855559294993754, 0.019938197383277772, 0.04476268347749629, 0.17048901657541302, 0.009075975961488935, 0.015660565798487413, 0.029619155223832794, 0.043038084573614195, 0.007195664318781209, 0.10554436609826837, 0.30041193772819735, 0.03540820427765679, 0.006347895931518362};
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 5:
			{
				string words[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string words[] = ;
				double __expected[] = ;
				_expected = vector <double>(__expected, __expected+sizeof(__expected)/sizeof(double));
				_received = _obj.getProbabilities(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		bool _passed = _expected.size() == _received.size();
		for (unsigned i = 0; i < _received.size(); i++)
			_passed = _passed && (abs(_expected[i]-_received[i]) < 1e-9 || (_received[i] > min(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9)) && _received[i] < max(_expected[i]*(1.0-1e-9), _expected[i]*(1.0+1e-9))));
		if (_passed)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
