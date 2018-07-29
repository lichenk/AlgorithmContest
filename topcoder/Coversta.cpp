#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define BASE 100
ll f[100][100], b[300][300];
class Coversta {
	public:
	int place(vector <string> a, vector <int> x, vector <int> y) {
		ll n = a.size();
		ll m = a[0].length();
		vector<pair<ll,ll> > h[200][200];
		for (ll i = 0; i < 300; i++) {
			for (ll j = 0; j < 300; j++) {
				b[i][j] = 0;
			}
		}
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				b[i+BASE][j+BASE] = a[i][j] - '0';
			}
		}
		ll k = x.size();
		for (ll i = 0; i < k; i++) {
			for (ll j = 0; j < k; j++) {
				ll dx = x[i] - x[j];
				ll dy = y[i] - y[j];
				if (-n <= dx && dx <= n && -m <= dy && dy <= m) {
					h[BASE+dx][BASE+dy].PB(MP(x[i],y[i]));
				}
			}
		}
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				f[i][j] = 0;
			}
		}
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < m; j++) {
				for (ll t = 0; t < k; t++) {
					ll fx = i+x[t];
					ll fy = j+y[t];
					f[i][j] += b[BASE+fx][BASE+fy];
				}
			}
		}
		ll ans = 0;
		for (ll x1 = 0; x1 < n; x1++) {
			for (ll y1 = 0; y1 < m; y1++) {
				ll a1 = f[x1][y1];
				for (ll x2 = x1; x2 < n; x2++) {
					for (ll y2 = 0; y2 < m; y2++) {
						ll cand = a1 + f[x2][y2];
						ll dx = x2-x1;
						ll dy = y2-y1;
						for (auto& w: h[BASE+dx][BASE+dy]) {
							ll fx = x1+w.first;
							ll fy = y1+w.second;
							cand -= b[BASE+fx][BASE+fy];
						}
						//printf("%d %d %d %d: %d\n",x1,y1,x2,y2,cand);
						ans = max(ans, cand);
					}
				}
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
		cout << "Testing Coversta (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1450802327;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Coversta _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string a[] = {"11",
				              "11"};
				int x[] = {0,0};
				int y[] = {0,1};
				_expected = 4;
				_received = _obj.place(vector <string>(a, a+sizeof(a)/sizeof(string)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 1:
			{
				string a[] = {"11",
				              "11"};
				int x[] = {0,1};
				int y[] = {0,1};
				_expected = 3;
				_received = _obj.place(vector <string>(a, a+sizeof(a)/sizeof(string)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 2:
			{
				string a[] = {"15",
				              "61"};
				int x[] = {0};
				int y[] = {0};
				_expected = 11;
				_received = _obj.place(vector <string>(a, a+sizeof(a)/sizeof(string)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 3:
			{
				string a[] = {"151",
				              "655",
				              "661"};
				int x[] = {0,0,-1};
				int y[] = {0,1,0};
				_expected = 33;
				_received = _obj.place(vector <string>(a, a+sizeof(a)/sizeof(string)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 4:
			{
				string a[] = {"303",
				              "333",
				              "000"};
				int x[] = {-1,-1};
				int y[] = {-1,1};
				_expected = 12;
				_received = _obj.place(vector <string>(a, a+sizeof(a)/sizeof(string)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 5:
			{
				string a[] = {"0000000",
				              "1010101"};
				int x[] = {-1,-1};
				int y[] = {-1,1};
				_expected = 0;
				_received = _obj.place(vector <string>(a, a+sizeof(a)/sizeof(string)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			case 6:
			{
				string a[] = {"80018508928085147361680865710283", "55614938323373014878989791958969", "33141457634638342789014073494568", "98997084569362006516197350065182", "72452258698355058150734156417040", "61055258327852729763159895495252", "23087283754182968981637541012285", "46773449183879711435291556790231", "98784443580294983504352577744041", "15402868147649873862809804968284", "79407481822146693813645220103873", "31456121918047741198103250322633", "61582193972132092745032978011474", "39967620962303519679275682463091", "87684037962273073073646740124463", "45020169379152441346887034467181", "21231110891097745167839313963752", "07170671754817521753100050078649", "14808997999606380369420443691891", "18635091082268977893056397743583", "33610474271572270360989640290322", "47745313343521698841457302777020", "08645015732791140331583051025104", "06489562221747860021392415406681", "33105893898439969772523283385788", "13512086553953548503508435812602", "21650177383513219423014866138794", "43544277566907098673201535654681", "58533287696463210587003734620116", "53495343770915400712377333915888", "02443367661481659687191676371279", "47182488162048594449945321743190", "73842698774878321937444351328090", "34944398538123898510618187728236", "69651380761603104315895457446775", "26889198050296022926736052171153", "26681586946628816878979058269717", "51644996155607507956853707523049", "85800977447592322319730437808812", "74919362072005357744338644592442", "42532340237207761756790857425658", "82852767335694459692956178372691", "00456364676391475005588698156060", "47864034100436105686767894510286", "70774622965640696291264708241003", "61798029897477539129611498697482", "58256193713206899391134824914394", "95216725180757429184481284673158", "54266461404667581151190763445726", "56296532163490565065332660620052", "05610494026640726685100213843508", "70535630299379393025118337467194", "61282577842065056072444050662631", "75554899812779218297990064253519", "78491987969564744865149887345775", "13379653402498042615610504870817", "28011910323228187562647437054373", "80568268126624302051058013828457", "23891622138566893576957700259303", "76152595355366852102689625886616", "71252492700490810017356950662367", "52566678645580044228650999387151", "99852310738859693119124680895046", "86733173134277336553609563329963", "55147179965223709769569935818961", "84534641521754838523132000852887", "10863222708474344460553721908880", "91678659805467640188494640929124", "39977667939454698682675868243566", "26492429662256529574434921337330", "54512856018927384267630293992229", "49484634283378375914917625228615", "59626890640663541884473243251249", "50685419192322291750998980180684", "55086054629325635728548928688859", "94299878313066340837660520736879", "48085724292015014005747752835978", "96090191601434796907554942097337", "70531264246035271149659878402905", "82629698395701207656328558801945", "67718363383596119439192607093873", "08683068539860563896059917548841", "17025688053437560610987953711731", "69142708649701311999593561439545", "50372243058030654088481778090002", "04542168466628852769216076005584", "43963684115542924057604475591844", "65104995875486026273159598974084", "72088602391379331256206177056122", "61055331257217122809493141430487", "32823985083515837160905314201590", "42605242385053297374988809730761", "24286398351096254853170804696852", "22178599296950625231610221035500", "80164490925140215163082564245211", "50517237309844950512406019937056", "08579102690959911475139843440174"};
				int x[] = {61, 2, -87, 20, -44, -47, -86, -10, -7, 35};
				int y[] = {19, -24, -8, -11, -20, 30, -5, 24, 29, -23};
				_expected = 68;
				_received = _obj.place(vector <string>(a, a+sizeof(a)/sizeof(string)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}
			/*case 7:
			{
				string a[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.place(vector <string>(a, a+sizeof(a)/sizeof(string)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				string a[] = ;
				int x[] = ;
				int y[] = ;
				_expected = ;
				_received = _obj.place(vector <string>(a, a+sizeof(a)/sizeof(string)), vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
