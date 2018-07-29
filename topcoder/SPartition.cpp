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
vector<ll> f[2][2][22];
ll g[2];
char a[22],b[22];
void build(string s, ll k) {
	g[k]=0;
	for (auto &w:s) {
		if (w=='o') w=1;
		else w=2;
	}
	ll n=s.length();
	ll zlim=1LL<<n;
	for (ll z=0;z<zlim;z++) {
		ll aidx=0,bidx=0;
		for (ll k=0;k<n;k++) {
			if (z&(1LL<<k)) a[aidx++]=s[k];
			else b[bidx++]=s[k];
		}
		bool ok=true;
		ll midx=min(aidx,bidx);
		for (ll i=0;i<midx;i++) if (a[i]!=b[i]) {ok=false; break;}
		if (!ok) continue;
		if (aidx>bidx) {
			ll sig=0;
			if(k) {
				for (ll i=aidx-1;i>=bidx;i--) {
					sig*=2;
					sig+=a[i];
				}
			}
			else {
				for (ll i=bidx;i<aidx;i++) {
					sig*=2;
					sig+=a[i];
				}
			}
			f[k][0][aidx-bidx].PB(sig);
			/*for (ll i=0;i<aidx;i++) a[i]+='a';
			for (ll i=0;i<bidx;i++) b[i]+='a';
			a[aidx]='\0';
			b[bidx]='\0';
			printf("k:%lld t:%lld d:%lld a:%s b:%s sig:%lld\n",k,0,aidx-bidx,a,b,sig);*/
		}
		else if (aidx<bidx) {
			ll sig=0;
			if (k) {
				for (ll i=bidx-1;i>=aidx;i--) {
					sig*=2;
					sig+=b[i];
				}
			}
			else {
				for (ll i=aidx;i<bidx;i++) {
					sig*=2;
					sig+=b[i];
				}
			}
			f[k][1][bidx-aidx].PB(sig);
			/*for (ll i=0;i<aidx;i++) a[i]+='a';
			for (ll i=0;i<bidx;i++) b[i]+='a';
			a[aidx]='\0';
			b[bidx]='\0';
			printf("k:%lld t:%lld d:%lld a:%s b:%s sig:%lld\n",k,1,bidx-aidx,a,b,sig);*/
		}
		else {
			g[k]++;
			/*for (ll i=0;i<aidx;i++) a[i]+='a';
			for (ll i=0;i<bidx;i++) b[i]+='a';
			a[aidx]='\0';
			b[bidx]='\0';
			//printf("EQ k:%lld a:%s b:%s\n",k,a,b);*/
		}
	}
	for (ll t=0;t<2;t++) {
		for (ll d=0;d<=n;d++) {
			sort(f[k][t][d].begin(),f[k][t][d].end());
		}
	}
}
ll solve(vector<ll> &a, vector<ll> &b) {
	ll aidx=0,bidx=0;
	ll alen=a.size(),blen=b.size();
	ll ans=0;
	while(aidx<alen) {
		ll orig=a[aidx];
		while(bidx<blen&&b[bidx]<orig) {
			bidx++;
		}
		ll acnt=0;
		while(aidx<alen&&a[aidx]==orig) {
			aidx++;acnt++;
		}
		ll bcnt=0;
		while(bidx<blen&&b[bidx]==orig) {
			bidx++;bcnt++;
		}
		//if (acnt*bcnt) printf("solve %lld: %lld %lld\n",orig,acnt,bcnt);
		ans+=acnt*bcnt;
	}
	return ans;
}
class SPartition {
	public:
	long long getCount(string s) {
		ll slen=s.length();
		build(s.substr(0,slen/2), 0);
		string sec=s.substr(slen/2,slen-slen/2);
		reverse(sec.begin(),sec.end());
		build(sec, 1);
		//printf("g0g1: %lld %lld\n",g[0],g[1]);
		ll ans=g[0]*g[1];
		for (ll d=0;d<22;d++) {
			ans+=solve(f[0][0][d],f[1][1][d]);
			ans+=solve(f[0][1][d],f[1][0][d]);
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
		cout << "Testing SPartition (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1472188982;
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
		SPartition _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "oxox";
				_expected = 2LL;
				_received = _obj.getCount(s); break;
			}
			case 1:
			{
				string s = "oooxxx";
				_expected = 0LL;
				_received = _obj.getCount(s); break;
			}
			case 2:
			{
				string s = "xoxxox";
				_expected = 4LL;
				_received = _obj.getCount(s); break;
			}
			case 3:
			{
				string s = "xo";
				_expected = 0LL;
				_received = _obj.getCount(s); break;
			}
			case 4:
			{
				string s = "ooooxoox";
				_expected = 8LL;
				_received = _obj.getCount(s); break;
			}
			case 5:
			{
				string s = "ooxxoxox";
				_expected = 8LL;
				_received = _obj.getCount(s); break;
			}
			case 6:
			{
				string s = "oooooooooooooooooooooooooooooooooooooooo";
				_expected = 137846528820LL;
				_received = _obj.getCount(s); break;
			}
			case 7:
			{
				string s = "ooooooooooooooooooooooooooooooooooooooox";
				_expected = 0LL;
				_received = _obj.getCount(s); break;
			}
			case 8:
			{
				string s = "xx";
				_expected = 2LL;
				_received = _obj.getCount(s); break;
			}
			case 9:
			{
				string s = "oooo";
				_expected = 6LL;
				_received = _obj.getCount(s); break;
			}
			case 10:
			{
				string s = "xxxxxx";
				_expected = 20LL;
				_received = _obj.getCount(s); break;
			}
			case 11:
			{
				string s = "ox";
				_expected = 0LL;
				_received = _obj.getCount(s); break;
			}
			case 12:
			{
				string s = "xxxo";
				_expected = 0LL;
				_received = _obj.getCount(s); break;
			}
			case 13:
			{
				string s = "ooooox";
				_expected = 0LL;
				_received = _obj.getCount(s); break;
			}
			case 14:
			{
				string s = "oooooooo";
				_expected = 70LL;
				_received = _obj.getCount(s); break;
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
