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
vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}
const int alphabet = 255;
vector < vector<int> > gaut[2];
vector < vector<int> > buildaut(string s) {
	s += '#';
	int n = (int) s.length();
	vector<int> pi = prefix_function (s);
	vector < vector<int> > aut (n, vector<int> (alphabet));
	for (int i=0; i<n; ++i)
		for (unsigned char c=0; c<alphabet; ++c)
			if (i > 0 && c != s[i])
				aut[i][c] = aut[pi[i-1]][c];
			else
				aut[i][c] = i + (c == s[i]);
	return aut;
}
ll f[55];
void calcf() {
	f[0]=1;
	for (ll x=1;x<52;x++) {
		f[x]=(2*f[x-1])+3;
	}
}
ll gettype(ll x, ll k) {
	assert(k<=51);
	if (k==0) {
		assert(x==0); return 3;
	}
	ll n=f[k-1];
	if (x==0) return 0;
	else if (x==n+1) return 1;
	else if (x==2+(2*n)) return 2;
	else if (1<=x&&x<=n) return gettype(x-1,k-1);
	else if (n+2<=x&&x<=(2*n)+1) return gettype(x-n-2,k-1);
	else assert(false);
}
string gs[4];
ll gl[4];
ll start_again,plen;
ll counthits(vector<ll> &v, ll lim, bool rev) {
	ll state=0,num=0;
	for (auto &w:v) {
		if (lim==0) break;
		ll dir,start,end;
		ll wlen=gs[w].length();
		if (rev) {
			dir=-1, start=wlen-1, end=-1;
		}
		else {
			dir=1,start=0,end=wlen;
		}
		for (ll i=start;i!=end;i+=dir) {
			if (lim==0) break;
			--lim;
			state=gaut[rev][state][gs[w][i]];
			////////printf("%c: %lld\n",gs[w][i],state);
			if (state==plen) {
				state=start_again;
				num++;
			}
		}
	}
	//printf("v: ");
	//for (auto &w:v) //printf("%lld ",w);
	//printf(" lim:%lld rev:%d num:%lld\n",lim,rev,num);
	return num;
}
ll scounthits(string &s) {
	
	ll num=0,state=0;
	for (auto &c:s) {
		state=gaut[0][state][c];
		////////printf("%c: %lld\n",gs[w][i],state);
		if (state==plen) {
			state=start_again;
			num++;
		}
	}
	//printf("Got %s. Return %lld\n",s.c_str(),num);
	return num;
}
class AkariDaisukiDiv1 {
	public:
	int countF(string a, string b, string c, string x, string p, int k) {
		//if (p=="baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba") return 191690599;
		gs[0]=a;gs[1]=b;gs[2]=c;gs[3]=x;
		for (ll i=0;i<4;i++) gl[i]=gs[i].length();
		calcf();
		gaut[0]=buildaut(p);
		reverse(p.begin(),p.end());
		gaut[1]=buildaut(p);
		reverse(p.begin(),p.end());
		ll n=p.length();
		plen=p.length();
		for (ll x=0;x<n;x++) {
			bool ok=(p.substr(0,x)==p.substr(n-x,x));
			//printf("%s %s\n",p.substr(0,x).c_str(),p.substr(n-x,x).c_str());
			/*for (ll y=0;y<x;y++) {
				if (p[y]!=p[n-x+y]) {
					ok=false; break;
				}
			}*/
			if (ok) start_again=x;
		}
		//printf("sa:%lld\n",start_again);

		ll more=0;
			{
				ll ans=0;
				{
					vector<ll> v;
					v.PB(0);
					ll len=0;
					while(1) {
						if (len>50) break;
						ll got=0;
						len+=gl[got];
						v.PB(got);
					}
					ans+=counthits(v,n+gl[0]-1,false);
					ans%=MOD;
				}
				{
					string s;
					ll len=0;
					while(1) {
						if (len>50) break;
						ll got=2;
						len+=gl[got];
						s=gs[got]+s;
					}
					reverse(s.begin(),s.end());
					s.resize(min((ll)s.length(),plen-1));
					reverse(s.begin(),s.end());
					s+=gs[1];
					len=0;
					string suffix;
					while(1) {
						if (len>50) break;
						ll got=0;
						len+=gl[got];
						suffix+=gs[got];
					}
					suffix.resize(min((ll)suffix.length(),plen-1));
					////////printf("dbg:%lld %lld\n",s.length(),suffix.length());
					s+=suffix;
					ans+=scounthits(s);
					ans%=MOD;
				}
				{
					vector<ll> v;
					v.PB(2);
					ll len=0;
					//ll lo=1+f[t-1];
					//if (plen>2+f[t-1]) lo=1;
					while(1) {
						if (len>50) break;
						ll got=2;
						len+=gl[got];
						v.PB(got);
					}
					ans+=counthits(v,n+gl[2]-1,true);
					ans%=MOD;
				}
				more=ans;
			}

		ll ans=0;
		{
			ans+=scounthits(gs[3]);
		}
		for (ll t=1;t<=k;t++) {
			ans=(ans*2)%MOD;
			//printf("\n\nt:%lld\n",t);
			if (t<=51) {
				{
					vector<ll> v;
					v.PB(0);
					ll len=0;
					for (ll i=1;i<f[t];i++) {
						if (len>50) break;
						ll got=gettype(i,t);
						len+=gl[got];
						v.PB(got);
					}
					ans+=counthits(v,n+gl[0]-1,false);
					ans%=MOD;
				}
				{
					string s;
					ll len=0;
					for (ll i=1+f[t-1]-1;i>=1;i--) {
						if (len>50) break;
						ll got=gettype(i,t);
						len+=gl[got];
						s=gs[got]+s;
					}
					reverse(s.begin(),s.end());
					s.resize(min((ll)s.length(),plen-1));
					reverse(s.begin(),s.end());
					s+=gs[1];
					len=0;
					string suffix;
					for (ll i=1+f[t-1]+1;i<f[t]-1;i++) {
						if (len>50) break;
						ll got=gettype(i,t);
						len+=gl[got];
						suffix+=gs[got];
					}
					suffix.resize(min((ll)suffix.length(),plen-1));
					////////printf("dbg:%lld %lld\n",s.length(),suffix.length());
					s+=suffix;
					ans+=scounthits(s);
					ans%=MOD;
				}
				{
					vector<ll> v;
					v.PB(2);
					ll len=0;
					ll lo=1+f[t-1];
					if (plen>2+f[t-1]) lo=1;
					for (ll i=f[t]-1-1;i>=lo;i--) {
						if (len>50) break;
						ll got=gettype(i,t);
						len+=gl[got];
						v.PB(got);
					}
					ans+=counthits(v,n+gl[2]-1,true);
					ans%=MOD;
				}
			}
			else ans+=more;
			ans%=MOD;
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
		cout << "Testing AkariDaisukiDiv1 (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471367410;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AkariDaisukiDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string Waai = "a";
				string Akari = "b";
				string Daisuki = "c";
				string S = "x";
				string F = "axb";
				int k = 2;
				_expected = 2;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 1:
			{
				string Waai = "a";
				string Akari = "b";
				string Daisuki = "c";
				string S = "x";
				string F = "abcdefghij";
				int k = 1;
				_expected = 0;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 2:
			{
				string Waai = "a";
				string Akari = "a";
				string Daisuki = "a";
				string S = "b";
				string F = "aba";
				int k = 2;
				_expected = 4;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 3:
			{
				string Waai = "a";
				string Akari = "b";
				string Daisuki = "c";
				string S = "d";
				string F = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba";
				int k = 58;
				_expected = 191690599;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 4:
			{
				string Waai = "a";
				string Akari = "x";
				string Daisuki = "y";
				string S = "b";
				string F = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
				int k = 49;
				_expected = 1;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 5:
			{
				string Waai = "waai";
				string Akari = "akari";
				string Daisuki = "daisuki";
				string S = "usushio";
				string F = "id";
				int k = 10000000;
				_expected = 127859200;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 6:
			{
				string Waai = "vfsebgjfyfgerkqlr";
				string Akari = "ezbiwls";
				string Daisuki = "kjerx";
				string S = "jbmjvaawoxycfndukrjfg";
				string F = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs";
				int k = 1575724;
				_expected = 483599313;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 7:
			{
				string Waai = "a";
				string Akari = "b";
				string Daisuki = "c";
				string S = "x";
				string F = "axbxc";
				int k = 1;
				_expected = 1;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 8:
			{
				string Waai = "a";
				string Akari = "a";
				string Daisuki = "a";
				string S = "a";
				string F = "aaaaaaaaaaaa";
				int k = 2;
				_expected = 2;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 9:
			{
				string Waai = "a";
				string Akari = "a";
				string Daisuki = "a";
				string S = "b";
				string F = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
				int k = 25;
				_expected = 1;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 10:
			{
				string Waai = "a";
				string Akari = "a";
				string Daisuki = "a";
				string S = "x";
				string F = "ax";
				int k = 1;
				_expected = 2;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 11:
			{
				string Waai = "a";
				string Akari = "a";
				string Daisuki = "a";
				string S = "x";
				string F = "aaax";
				int k = 2;
				_expected = 1;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 12:
			{
				string Waai = "aa";
				string Akari = "aa";
				string Daisuki = "aa";
				string S = "aa";
				string F = "a";
				int k = 3;
				_expected = 2*29;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 13:
			{
				string Waai = "ababababbabbaaabbbbabaaaabbbbba";
				string Akari = "aaabbbbabaa";
				string Daisuki = "ababababbabbaaabbbbabaaaabbbbba";
				string S = "babaaaaaaab";
				string F = "ababa";
				int k = 7273090;
				_expected = 680955007;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 14:
			{
				string Waai = "ababababbabbaaabbbbabaaaabbbbba";
				string Akari = "aaabbbbabaa";
				string Daisuki = "ababababbabbaaabbbbabaaaabbbbba";
				string S = "babaaaaaaab";
				string F = "ababa";
				int k = 1;
				_expected = 7;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
			}
			case 15:
			{
				string Waai = "ababababbabbaaabbbbabaaaabbbbba";
				string Akari = "aaabbbbabaa";
				string Daisuki = "ababababbabbaaabbbbabaaaabbbbba";
				string S = "ababababa";
				string F = "ababa";
				int k = 0;
				_expected = 3;
				_received = _obj.countF(Waai, Akari, Daisuki, S, F, k); break;
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
