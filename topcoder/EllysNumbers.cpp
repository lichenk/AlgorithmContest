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
const ll MAXN=sqrt(1e9)+4;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
vector<ll> gpv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if(sieve_array[i]) {
			gpv.PB(i);
		}
	}
}
inline vector<ll> load(string s) {
	stringstream in(s);
	ll x;
	vector<ll> ret;
	while (in>>x) {
		ret.push_back(x);
	}
	return ret;
}
set<ll> opv;
map<ll,ll> factorize(ll x) {
	map<ll,ll> h;
	for (auto &p:gpv) {
		while(0==x%p) {
			opv.insert(p);
			h[p]++;
			x/=p;
		}
		if (x==1) break;
	}
	if (x>1) {h[x]++;opv.insert(x);}
	return h;
}
set<ll> wantp;
ll wantpsz;
map<ll,ll> factorize2(ll x) {
	map<ll,ll> h;
	for (auto &p:opv) {
		while(0==x%p) {
			wantp.insert(p);
			h[p]++;
			x/=p;
		}
		if (x==1) break;
	}
	if (x>1) h[0]=-1;
	return h;
}
vector<ll> go;
ll gosz;
ll dp[2][1<<20];
class EllysNumbers {
	public:
	long long getSubsets(long long n, vector <string> special) {
		sieve();
		string spec; for (auto &w:special) spec+=w;
		vector<ll> a=load(spec);
		vector<map<ll,ll> > mapfac;
		ll mul=1;
		for (auto &w:a) {
			if (w==1) mul*=2;
			else mapfac.PB(factorize(w));
		}
		map<ll,ll> fn=factorize2(n);
		if (fn[0]==-1) return 0;
		map<ll,ll> h;
		ll idx=0;
		for (auto &w:wantp) {
			//pr("%lld maps to %lld\n",w,idx);
			h[w]=idx++;
		}
		wantpsz=idx;
		for (auto &sp:mapfac) {
			bool bad=false;
			ll got=0;
			for (auto &pw:sp) {
				ll p=pw.first;
				auto it=fn.find(p);
				if (it==fn.end()) {bad=true; break;}
				else if (it->second!=pw.second) {bad=true; break;}
				got|=1LL<<h[p];
			}
			if (bad) continue;
			//printf("gotttt:%lld\n",got);
			go.PB(got);
		}
		gosz=go.size();
		ll zlim=1LL<<idx;
		for (ll z=0;z<zlim;z++) dp[0][z]=0;
		dp[0][0]=1;
		for (ll i=0;i<gosz;i++) {
			ll cur=i&1,nxt=cur^1;
			for (ll z=0;z<zlim;z++) dp[nxt][z]=dp[cur][z];
			for (ll z=0;z<zlim;z++) {
				ll have=z;
				//ll left=(zlim-1)&(~have);
				ll w=go[i];
				if (have&w) continue;
				ll nz=have|w;
				dp[nxt][nz]+=dp[cur][z];
			}
		}
		ll ans=mul*dp[gosz&1][zlim-1];
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
		cout << "Testing EllysNumbers (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471711908;
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
		EllysNumbers _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long n = 12LL;
				string special[] = {"4 2 5 6 3"};
				_expected = 1LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 1:
			{
				long long n = 42LL;
				string special[] = {"1 2 3 4 5 6 7 13 14 21 42"};
				_expected = 10LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 2:
			{
				long long n = 1337LL;
				string special[] = {"1 13 42 666 2674"};
				_expected = 0LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 3:
			{
				long long n = 1073741824LL;
				string special[] = {"1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 1",
				                    "6384 32768 65536 131072 262144 524288 1048576 2097",
				                    "152 4194304 8388608 16777216 33554432 67108864 134",
				                    "217728 268435456 536870912"};
				_expected = 0LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 4:
			{
				long long n = 7420738134810LL;
				string special[] = {"435 625199055 4199 33263 17 222870 284870433 72093",
				                    "2379 7 11 31 247110827 23 1771 81809 851968487 13 ", 
				                    "476379795 1001 5 435274114 38264554 7429 239906525",
				                    " 3 227183706 887045414 606786670 3795 797605175 29",
				                    " 30 747186719 19 2 562347843 74 2294 588002688 743",
				                    "6429 703 591740547 36657492 37 444178205 1002001 2",
				                    "17626404"};
				_expected = 110LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 5:
			{
				long long n = 999999866000004473LL;
				string special[] = {"1 42 999999883 999999937 999999929"};
				_expected = 2LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 6:
			{
				long long n = 12LL;
				string special[] = {"6 5 4 3 2 1"};
				_expected = 2LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 7:
			{
				long long n = 89136273185960LL;
				string special[] = {"41 637 5 6877 392 4961 2107 1 5929 14104 43 1573 6", "05 49 64009 2645 3224 215 932627 131192 31 533 121", " 205 1333 25921 86387 104 2009 559 22747 5203 2131", "87 65 328 7865 26015 13 245 8 27391 281957 1763 24", "8 21160 1271 47432 40 968 16399 403 65317 295711 1", "83799 4232 10168 1519 173512 26117"};
				_expected = 4472LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 8:
			{
				long long n = 12180501929485890LL;
				string special[] = {"1 2 3 6 5 10 15 30 7 14 21 42 35 70 105 11 22 33 6", "6 55 110 165 77 154 231 385 13 26 39 78 65 130 195", " 91 182 273 455 143 286 429 715 1001 17 34 51 102 ", "85 170 255 119 238 357 595 187 374 561 935 1309 22", "1 442 663 1105 1547 2431 19 38 57 114 95 190 285 1", "33 266 399 665 209 418 627 1045 1463 247 494 741 1", "235 1729 2717 323 646 969 1615 2261 3553 4199 23 4", "6 69 138 115 230 345 161 322 483 805 253 506 759 1", "265 1771 299 598 897 1495 2093 3289 391 782 1173 1", "955 2737 4301 5083 437 874 1311 2185 3059 4807 568", "1 7429 27 54 81 162 135 270 405 189 378 567 945 29", "7 594 891 1485 2079 351 702 1053 1755 2457 3861 45", "9 918 1377 2295 3213 5049 5967 513 1026 1539 2565 ", "3591 5643 6669 8721 621 1242 1863 3105 4347 6831 8", "073 10557 11799 31 62 93 186 155 310 465 217 434 6", "51 1085 341 682 1023 1705 2387 403 806 1209 2015 2", "821 4433 527 1054 1581 2635 3689 5797 6851 589 117", "8 1767 2945 4123 6479 7657 10013 713 1426 2139 356", "5 4991 7843 9269 12121 13547 837 1674 2511 4185 58", "59 9207 10881 14229 15903 19251 37 74 111 222 185 ", "370 555 259 518 777 1295 407 814 1221 2035 2849 48", "1 962 1443 2405 3367 5291 629 1258 1887 3145 4403 ", "6919 8177 703 1406 2109 3515 4921 7733 9139 11951 ", "851 1702 2553 4255 5957 9361 11063 14467 16169 999", " 1998 2997 4995 6993 10989 12987 16983 18981 22977", " 1147 2294 3441 5735 8029 12617 14911 19499 21793 ", "26381 30969 41 82 123 246 205 410 615 287 574 861 ", "1435 451 902 1353 2255 3157 533 1066 1599 2665 373", "1 5863 697 1394 2091 3485 4879 7667 9061 779 1558 ", "2337 3895 5453 8569 10127 13243 943 1886 2829 4715", " 6601 10373 12259 16031 17917 1107 2214 3321 5535 ", "7749 12177 14391 18819 21033 25461 1271 2542 3813 ", "6355 8897 13981 16523 21607 24149 29233 34317 1517", " 3034 4551 7585 10619 16687 19721 25789 28823 3489", "1 40959 47027 43 86 129 258 215 430 645 301 602 90", "3 1505 473 946 1419 2365 3311 559 1118 1677 2795 3", "913 6149 731 1462 2193 3655 5117 8041 9503 817 163", "4 2451 4085 5719 8987 10621 13889 989 1978 2967 49", "45 6923 10879 12857 16813 18791 1161 2322 3483 580", "5 8127 12771 15093 19737 22059 26703 1333 2666 399", "9 6665 9331 14663 17329 22661 25327 30659 35991 15", "91 3182 4773 7955 11137 17501 20683 27047 30229 36", "593 42957 49321 1763 3526 5289 8815 12341 19393 22", "919 29971 33497 40549 47601 54653 65231"};
				_expected = 10865408LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
			}
			case 9:
			{
				long long n = 614889782588491410LL;
				string special[] = {"2 3 4 5 6 7 8 9 10 11 12 13 14 15 17 18 19 1927 21", " 22 23 25 26 28 29 30 31 33 34 35 37 38 39 41 42 4", "3 44 946 46 47 49 50 51 52 1763 55 57 58 1034 62 6", "5 66 68 69 70 74 76 77 78 82 85 86 87 602 91 92 93", " 94 95 98 611 102 529 110 111 114 115 116 629 119 ", "121 123 124 638 533 129 130 133 646 138 141 143 14", "5 658 148 154 155 161 164 1189 169 170 517 174 182", " 185 186 187 188 190 703 1739 1222 713 518 203 205", " 209 215 217 731 221 222 1247 1147 230 235 238 242", " 246 247 253 172 258 259 266 779 782 1066 282 559 ", "286 287 289 290 806 1073 299 1118 301 814 817 1333", " 310 1849 319 322 323 329 1591 551 338 851 341 108", "1 1369 1681 361 370 574 374 377 893 899 902 391 57", "8 1517 403 406 407 410 598 418 667 754 430 943 145", "7 434 437 841 442 799 961 962 451 2209 697 1271 58", "9 470 20 527 473 986 989 481 2021 493 494 1363 506", " 682"};
				_expected = 18478352LL;
				_received = _obj.getSubsets(n, vector <string>(special, special+sizeof(special)/sizeof(string))); break;
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
