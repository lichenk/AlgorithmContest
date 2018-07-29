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
inline vector<ll> load(string s) {
	stringstream in(s);
	ll x;
	vector<ll> ret;
	while (in>>x) {
		ret.push_back(x);
	}
	return ret;
}
inline vector<ll> loads(vector<string> v) {
	string s;
	for (auto &w:v) {
		s+=w;
	}
	return load(s);
}
typedef pair<ll, ll> point;
long long ccw(point a, point b, point c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	return b.first * (long long)c.second - c.first * (long long)b.second;
}
ll dist2(point a, point b) {
	ll dx=(a.first-b.first);
	ll dy=(a.second-b.second);
	return (dx*dx)+(dy*dy);
}
bool ban[222][222][222];
class CheckerFreeness {
	public:
	string isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY) {
		vector<ll> wx=loads(whiteX);
		vector<ll> wy=loads(whiteY);
		vector<ll> bx=loads(blackX);
		vector<ll> by=loads(blackY);
		ll wn=wx.size(),bn=bx.size();
		for (ll i=0;i<222;i++) for (ll j=0;j<222;j++) for (ll k=0;k<222;k++) ban[i][j][k]=false;
		for (ll i=0;i<wn;i++) {
			for (ll j=i+1;j<wn;j++) {
				point a=MP(wx[i],wy[i]);
				point c=MP(wx[j],wy[j]);
				vector<pair<ld,ld> > v[2];
				for (ll k=0;k<bn;k++) {
					point b=MP(bx[k],by[k]);
					ld ang0,ang1;
					{
						ld A2=dist2(a,b);
						ld B2=dist2(a,c);
						ld C2=dist2(b,c);
						ld cosang=(A2+B2-C2)/sqrt(4*A2*B2);
						ang0=acos(cosang);
					}
					{
						ld A2=dist2(b,c);
						ld B2=dist2(a,c);
						ld C2=dist2(a,b);
						ld cosang=(A2+B2-C2)/sqrt(4*A2*B2);
						ang1=acos(cosang);
					}
					ll cross=ccw(a,b,c);
					//printf("%lld %lld. %lld %lld. %lld %lld. %Lf %Lf\n",a.first,a.second,b.first,b.second,c.first,c.second,ang0,ang1);
					if (cross>0) v[0].PB(MP(ang0,ang1));
					if (cross<0) v[1].PB(MP(ang0,ang1));
				}
				for (ll k=0;k<2;k++) sort(v[k].begin(),v[k].end());
				/*for (ll k=0;k<2;k++) {
					for (auto &w:v[k]) {
						printf("(%Lf %Lf), ",w.first,w.second);
					}
					printf("\n");
				}*/
				ll v0sz=v[0].size(),v1sz=v[1].size();
				ld minv=INF;
				for (ll x=0;x<v1sz;x++) {
					chkmin(minv,v[1][x].second);
					v[1][x].second=minv;
				}
				ll y=v1sz-1;
				for (ll x=0;x<v0sz;x++) {
					while(y>=0&&!(v[0][x].first+v[1][y].first<M_PIl)) y--;
					if (y>=0){
						/*if (!((v[0][x].first+v[1][y].first<M_PIl))) {
							for (ll k=0;k<2;k++) {
							for (auto &w:v[k]) {
								printf("(%Lf %Lf), ",w.first,w.second);
							}
							printf("\n");}
							printf("y:%lld v1sz:%lld. %.15Lf %.15Lf\n",y,v1sz,v[0][x].first,v[1][y].first);
						}*/
						//assert(v[0][x].first+v[1][y].first<M_PIl);
						if(v[0][x].first+v[1][y].first<M_PIl) {
							if (v[0][x].second+v[1][y].second<M_PIl) {
								//printf("%lld %lld. %Lf+%Lf=%Lf. %Lf+%Lf=%Lf.\n",i,j,v[0][x].first,v[1][y].first,v[0][x].first+v[1][y].first,
								//	v[0][x].second,v[1][y].second,v[0][x].second+v[1][y].second);
								return "NO";
							}
						}
					}
				}
			}
		}
		return "YES";
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
		cout << "Testing CheckerFreeness (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1464100025;
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
		CheckerFreeness _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string whiteX[] = {"1 2"};
				string whiteY[] = {"2 1"};
				string blackX[] = {"1 2"};
				string blackY[] = {"1 2"};
				_expected = "NO";
				_received = _obj.isFree(vector <string>(whiteX, whiteX+sizeof(whiteX)/sizeof(string)), vector <string>(whiteY, whiteY+sizeof(whiteY)/sizeof(string)), vector <string>(blackX, blackX+sizeof(blackX)/sizeof(string)), vector <string>(blackY, blackY+sizeof(blackY)/sizeof(string))); break;
			}
			case 1:
			{
				string whiteX[] = {"2", "5", "3", " ", "1", "7", "3"};
				string whiteY[] = {"180 254"};
				string blackX[] = {"32", "5 1", "42"};
				string blackY[] = {"462 423"};
				_expected = "YES";
				_received = _obj.isFree(vector <string>(whiteX, whiteX+sizeof(whiteX)/sizeof(string)), vector <string>(whiteY, whiteY+sizeof(whiteY)/sizeof(string)), vector <string>(blackX, blackX+sizeof(blackX)/sizeof(string)), vector <string>(blackY, blackY+sizeof(blackY)/sizeof(string))); break;
			}
			case 2:
			{
				string whiteX[] = {"1 10000000 9999999"};
				string whiteY[] = {"1 9999999 1"};
				string blackX[] = {"2 5000000 9999998"};
				string blackY[] = {"2 5000001 9999999"};
				_expected = "YES";
				_received = _obj.isFree(vector <string>(whiteX, whiteX+sizeof(whiteX)/sizeof(string)), vector <string>(whiteY, whiteY+sizeof(whiteY)/sizeof(string)), vector <string>(blackX, blackX+sizeof(blackX)/sizeof(string)), vector <string>(blackY, blackY+sizeof(blackY)/sizeof(string))); break;
			}
			case 3:
			{
				string whiteX[] = {"1"};
				string whiteY[] = {"2"};
				string blackX[] = {"3"};
				string blackY[] = {"4"};
				_expected = "YES";
				_received = _obj.isFree(vector <string>(whiteX, whiteX+sizeof(whiteX)/sizeof(string)), vector <string>(whiteY, whiteY+sizeof(whiteY)/sizeof(string)), vector <string>(blackX, blackX+sizeof(blackX)/sizeof(string)), vector <string>(blackY, blackY+sizeof(blackY)/sizeof(string))); break;
			}
			case 4:
			{
				string whiteX[] = {"6115 9723 3794 2275 2268 2702 3657 915 7953 2743 7"
				                  ,"716 9645 2547 9490 9365 326 6601 5215 6771 7153 72"
				                  ,"93 5922 714 2258 4369 9524 302 8417 6620 1143"};
				string whiteY[] = {"621 1611 7140 503 5345 7202 681 4908 2510 5908 279"
				                  ,"6 6286 6873 6682 9197 6710 8517 1913 7784 8533 665"
				                  ,"4 446 3561 7241 6168 2025 4739 9501 5340 6446"};
				string blackX[] = {"6833 131 4151 1776 1959 7210 1903 6107 598 6220 94"
				                  ,"24 5374 6718 2919 6068 6644 5070 710 7121 1630 370"
				                  ,"3 1051 5739 9294 8798 3371 8107 2130 6608 534"};
				string blackY[] = {"7496 2412 2801 3473 5810 2714 7853 9714 5470 3558 "
				                  ,"8143 2391 8234 7292 9311 1636 8978 1107 2262 9175 "
				                  ,"7259 8842 5294 7209 2317 3825 3413 820 3774 5393"};
				_expected = "NO";
				_received = _obj.isFree(vector <string>(whiteX, whiteX+sizeof(whiteX)/sizeof(string)), vector <string>(whiteY, whiteY+sizeof(whiteY)/sizeof(string)), vector <string>(blackX, blackX+sizeof(blackX)/sizeof(string)), vector <string>(blackY, blackY+sizeof(blackY)/sizeof(string))); break;
			}
			case 5:
			{
				string whiteX[] = {"219211 1996214 1706774 3634920 909831 1774128 8503"
				                  ,"52 2233050 2099138 3380396 1128982 3682525 1483700"
				                  ," 763080 487867 8203 1791027 463556 1103323 1406861"
				                  ," 6374234 760949 4340236 727393 2073832 1289052 103"
				                  ,"8147 4448130 151066 412440 1068735 377239 2677933 "
				                  ,"1299598 339843 289973 3707319 555280 230418 431719"};
				string whiteY[] = {"1638083 5698739 3105504 9726902 9745795 5049444 15"
				                  ,"80592 3952120 6606668 7460527 7239299 8726128 4913"
				                  ,"547 6264100 5701660 8865937 4969114 8014845 327236"
				                  ,"1 6389154 9739755 2561669 9412417 5452337 3150506 "
				                  ,"5832197 1571976 8779325 3306446 948271 5133709 949"
				                  ,"394 6919798 7525636 3568024 6833196 9237472 733313"
				                  ,"1 9939064 9720014"};
				string blackX[] = {"5860334 8007503 7455523 4864927 9573526 2718360 81"
				                  ,"12104 6684287 9921506 4840886 5415948 3451454 5320"
				                  ,"996 9268757 9261724 8254668 2292750 8035828 233352"
				                  ,"1 7676906 5234406 8533320 6562751 4884098 4971897 "
				                  ,"5569360 8519168 3100295 9351613 7733878 7579030 32"
				                  ,"46775 7297460 8370542 7099759 5782969 2978083 3390"
				                  ,"488 7482758 1332401 6094629 9717305 5503121 572842"
				                  ,"1 4903563 6331656 2867455 3410007 7751527 7228221 "
				                  ,"4111694 5171296 6847697 4601273 7599828 5515929 94"
				                  ,"60593 9332762 5389080 4512091 8668538 5711743 5838"
				                  ,"534 4825079 8145628 3810005 2964724 5594550 785748"
				                  ,"3 6283769"};
				string blackY[] = {"5911694 8009943 212555 5838688 9896256 607434 5857"
				                  ,"663 4616750 1477573 7168026 3090917 4379806 326465"
				                  ,"7 4189076 2104028 3279691 94211 8503556 78457 4394"
				                  ,"360 3344176 3223317 2624498 4883494 1532240 732937"
				                  ,"1 1518674 1353567 892134 5536454 8527392 2603965 6"
				                  ,"623264 8830827 2030444 3002706 83058 4475866 20876"
				                  ,"25 1790695 4034441 5409379 3571098 4600050 736561 "
				                  ,"250475 3733256 3011439 2144994 4523046 3119883 607"
				                  ,"582 8361403 6525451 7518329 926803 4884524 8424659"
				                  ," 7088689 5762049 9532481 4914186 7314621 4339084 3"
				                  ,"741685 3837953 3177252 612550 9688871 5872931"};
				_expected = "YES";
				_received = _obj.isFree(vector <string>(whiteX, whiteX+sizeof(whiteX)/sizeof(string)), vector <string>(whiteY, whiteY+sizeof(whiteY)/sizeof(string)), vector <string>(blackX, blackX+sizeof(blackX)/sizeof(string)), vector <string>(blackY, blackY+sizeof(blackY)/sizeof(string))); break;
			}
			case 6:
			{
				string whiteX[] = {"5194720 3469149 6336130"};
				string whiteY[] = {"6655252 4341007 4003740"};
				string blackX[] = {"453043 5472397 9074558"};
				string blackY[] = {"7079708 22365 7897925"};
				_expected = "YES";
				_received = _obj.isFree(vector <string>(whiteX, whiteX+sizeof(whiteX)/sizeof(string)), vector <string>(whiteY, whiteY+sizeof(whiteY)/sizeof(string)), vector <string>(blackX, blackX+sizeof(blackX)/sizeof(string)), vector <string>(blackY, blackY+sizeof(blackY)/sizeof(string))); break;
			}
			/*case 7:
			{
				string whiteX[] = ;
				string whiteY[] = ;
				string blackX[] = ;
				string blackY[] = ;
				_expected = ;
				_received = _obj.isFree(vector <string>(whiteX, whiteX+sizeof(whiteX)/sizeof(string)), vector <string>(whiteY, whiteY+sizeof(whiteY)/sizeof(string)), vector <string>(blackX, blackX+sizeof(blackX)/sizeof(string)), vector <string>(blackY, blackY+sizeof(blackY)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string whiteX[] = ;
				string whiteY[] = ;
				string blackX[] = ;
				string blackY[] = ;
				_expected = ;
				_received = _obj.isFree(vector <string>(whiteX, whiteX+sizeof(whiteX)/sizeof(string)), vector <string>(whiteY, whiteY+sizeof(whiteY)/sizeof(string)), vector <string>(blackX, blackX+sizeof(blackX)/sizeof(string)), vector <string>(blackY, blackY+sizeof(blackY)/sizeof(string))); break;
			}*/
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
