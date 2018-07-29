#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000009LL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=36*36+2;
ll col[MAXN],tmp[MAXN];
ll f[MAXN][MAXN], mul[MAXN], total[MAXN];
class ColorfulBuilding {
	public:
	int count(vector <string> color1, vector <string> color2, int L) {
		string c1,c2;
		for (auto &s: color1) c1+=s;
		for (auto&s:color2) c2+=s;
		ll n=c1.size();
		for (ll x=0;x<n;x++) {
			ll col1 = (c1[x]>='a')?c1[x]-'a'+26:c1[x]-'A';
			ll col2 = (c2[x]>='a')?c2[x]-'a'+26:c2[x]-'A';
			tmp[x] = col1*52+col2;
		}
		ll maxc=0;
		for (ll x=n-1;x>=0;x--) {
			bool good=false;
			for (ll y=x+1;y<n;y++) {
				if (tmp[x]==tmp[y]) {
					col[x]=col[y]; good=true;
					break;
				}
			}
			if (!good) {
				col[x]=maxc;
				maxc++;
			}
		}
		reverse(col,col+n);
		for (ll j=0;j<=L;j++) {total[j]=0;}
		for (ll c=0;c<maxc;c++) {
			mul[c]=1;
			for (ll j=0;j<=L;j++) f[c][j]=0;
		}
		f[col[0]][1]=1; total[1]=1;
		for (ll i=1;i<n;i++) {
			ll co = col[i];
			for (ll j=L;j>=1;j--) {
				ll p0=(f[co][j]*mul[co])%MOD;
				total[j] += (MOD-p0);
				total[j]%=MOD;
				/*if (i==4&&j==2) {
					printf("%d %d %d=%d %d-%d=%d\n",
						f[co][j],mul[co],(i+1),f[co][j]*mul[co]*(i+1),
						total[j-1],f[co][j-1]*mul[co],(total[j-1]-f[co][j-1]*mul[co]));
				}*/
				ll t1=(f[co][j]*mul[co])%MOD;
				ll p1=(t1*(i+1))%MOD;
				ll t2=(f[co][j-1]*mul[co])%MOD;
				ll p2=(total[j-1]+MOD-t2)%MOD;
				f[co][j] = (p1+p2)%MOD;
				total[j] *=i;
				total[j]%=MOD;
				total[j] += f[co][j];
				total[j]%=MOD;
			}
			for (ll c=0;c<maxc;c++) {mul[c]=(mul[c]*i)%MOD;}
			mul[co]=1;
			
			/*
			printf("i:%d col:%d\n",i,col[i]);
			for (ll c=0;c<maxc;c++) {
				for (ll j=0;j<=L;j++) {
					printf("c:%d j:%d f:%d\n",c,j,f[c][j]);
				}
			}
			for (ll j=0;j<=L;j++) {
				printf("j:%d total:%d mul:%d\n",j,total[j],mul[j]);
			}
			*/
		}
		ll final=0;
		for (ll c=0;c<maxc;c++) final+=(f[c][L]*mul[c])%MOD;
		return final%MOD;
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
		cout << "Testing ColorfulBuilding (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1456710033;
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
		ColorfulBuilding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string color1[] = {"aaba"};
				string color2[] = {"aaaa"};
				int L = 3;
				_expected = 6;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			case 1:
			{
				string color1[] = {"aaba"};
				string color2[] = {"aaba"};
				int L = 4;
				_expected = 0;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			case 2:
			{
				string color1[] = {"ab", "ba", "a", "aab"};
				string color2[] = {"bb", "ba", "a", "aba"};
				int L = 5;
				_expected = 432;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			case 3:
			{
				string color1[] = {"xxxxxxxxxxxxxxxxxxxx",
				                   "xxxxxxxxxxxxxxxxxxxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOxxxxxxxxxxxxxxxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxxxxxxxxxxxxxxxOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxxxxxxxxxxxxxxxxxxx",
				                   "xxxxxxxxxxxxxxxxxxxx"};
				string color2[] = {"xxxxxxxxxxxxxxxxxxxx",
				                   "xxxxxxxxxxxxxxxxxxxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOxxxxxxxxxxxxOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxOOOOOOOOOOOOOOOOxx",
				                   "xxxxxxxxxxxxxxxxxxxx",
				                   "xxxxxxxxxxxxxxxxxxxx"};
				int L = 58;
				_expected = 619787617;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			case 4:
			{
				string color1[] = {"SJXcabKTWeUXhwxGixFepQaQlFxrAedNAtVP",
				                   "gorBIkcTlOFbLDbFeElYAyAqszQdMbpxSRdE",
				                   "SQVHPehlNtesbJDflyGxMqvgzjXisRnqDcQO",
				                   "pIAEBwbmpPWCooQAujbGXFGLvXxTmExLARkf",
				                   "AFnWyWKVObfxDGCjTxdZaObgwdxlPKtIxaAd",
				                   "uznMpJVNjAofbHJjOrZeSHgSagOCUMGbvkVR",
				                   "LBRrDbTAyKfVnedKiRfzgRzECpcsziqaTwdo",
				                   "JrJHvsEVVGDkNVGqLbpxyLDPloBuNDQKnReI",
				                   "SSYpbjKHSCnQhuyYrVauWDHDyhAoGyecrZMv",
				                   "UdetQfWEUWHHuAxRSdkJOOJSixKpQXpCFZHO",
				                   "KXVsQbuQtIgsULOMsTvPFNUqkBldMTLCipYK",
				                   "hoXConjnDWQkZVtyZlwSedvdVrNWqQhGUClQ",
				                   "TpsvvyoXsXmQpBAGGVDrXCkodoRHQZmpoQDW",
				                   "csiJspzTqeFBRmPgeEtTAzfrfCGlTZqcPuyO",
				                   "vsPDVBJVaJmUAtDdcsKoUkPEbDmAwtZKwjjP",
				                   "MOfoMhMiKIvGQoeIJXHzyClWRtRuKXMqxUAF",
				                   "KyyUCkRBjsYvmPFFEGBqqVhIUdtvIyyLacfu",
				                   "BfuwfSajSlcuTzhMufHSQLudvGEGlyHsEmBD",
				                   "PLpIXZkdyXveTMfSvqnDGKWOZrTBMUIlZrqF",
				                   "dzVMCqrSLbanRJTYpDJNHAOLPSzmvSEPQJYm",
				                   "rAjRkrSjouJyFaCSPPLYSzqDmMoADyWAbobJ",
				                   "eOCBrJNoyFnGpXpxiExXcoOHnVsaEPXhPfLe",
				                   "XMjRksnxWssPEINhdhbiLBSYpCLtwNshFjXS",
				                   "HnnDeUAbuswsgsYQuAaXySLkFYUwFXwYTreM",
				                   "uqLnwOEGbwZZDgAAWEdLRZxFlogDmlhjhgHM",
				                   "NcfaQsgPQfirkYDRFrLQpySmBGfRHumKULZf",
				                   "mOpmmgclsxRzXskEywfryqCRyATNoJwnlHiD",
				                   "AnoKoKAjrasttjNlHCROnvTJMhEHlVPVoVMo",
				                   "yegLyIuRkkENFAjwzDoPLKjgUHHEkfzYDIpo",
				                   "EcxRGGfuaBXUFXkSxctJWOLmmVbvoMkWtTvV",
				                   "nBMkOBHgaltEVzfyGxseGhmBscfGIbxFbqRn",
				                   "GvkEcLtqdOofGtsbWDafVMbNdJxsffKDzSiR",
				                   "jhZQUVzTzalrZcebvyqPWtOUUyniBKTWdyLi",
				                   "ODJLQPMdjDdTlxrfGsNmBfeGYjzeXApqKDhJ",
				                   "vlJkWMzdVQujKdLViQClOrJXMTBkuZEasFgg",
				                   "FAsbuzrLVIgaryqXBfuBRAbReleXSSgEKSvt"};
				string color2[] = {"XAhlUHtfjOpOlQlowWppQcodMGUiqoLobxnD",
				                   "IDzGlKrHiVGdBjZxIcoxjwagbWieKvUwZrjg",
				                   "SkpkTVeIFeoNQzUUgmYAYskKONNZdgXxSiWd",
				                   "rXBGhTmqnvxkmqiutoDzPusDiOUggEFXGCzm",
				                   "fzrxVuTbFXunGbeEavjshmrIRlDorTuISCxn",
				                   "LsvIaxTkOBjcskiekmrKNNFEXqnfMNXLWqqu",
				                   "ekzxGIlbJPVEQPYAbTuMtZKsCiubDXDiBVzU",
				                   "hZuOCJxvBOYENGSFcUiKKAKfCdebutVmnyvB",
				                   "UveNkKRQmHnedrROQOpHJfrHjwcNLUShlDbn",
				                   "ptUkvbaGDryHRkYfHKLkSgVpjWCEcgazyxGK",
				                   "nVPYEqTTJsRPjzjfdOiULhnZPFeNcnbXaQlk",
				                   "IPXBXRhMQIkxpygsgbcRfMuvIcuzUPPHGOWX",
				                   "yWWlNyEyqZSIOXBFAybIuFpVqpvmKRaRFrAE",
				                   "EvBJVtHvKhjrFcmtpdBbFTdTVtXXZQKAglKT",
				                   "bCVjHzUvyINFkxXageZQMzCyNhcifACdJVDh",
				                   "lZITYcDSeIbLweyFtoMAfOQyBNupKlhcNpgo",
				                   "BduslNrJdWOUukYFFidEkMFaghfofpxVgvJd",
				                   "YrJpDZKqdjEPzdLsOQEdkcrBfNHPemXHokCW",
				                   "GjeUKSGjDlgKTyUGNrMQbBLxRUcgrWpkAwOD",
				                   "wgxTcswqdJHaDugNIRMvrhBsdDaJAssVbSRW",
				                   "qmVmqFEpvgGioMXDSFqEoQcDOAaUoGPEovSO",
				                   "KrukPlpfOhawaovCfteTSCIdLMrtImVtiMyQ",
				                   "ykwmxHsKMFzFHwcbyyedLvhZPnaNGqJMMCxd",
				                   "HUNYCXjNLQIFCLLGpCXHBCHLTxLynBxnHFbx",
				                   "uwjzbNbJepVFgMPUXVirxYHzExquBEtPmKju",
				                   "xXAxAbJePyUsVHeLytDvAxBGMRtnvCEiZZqe",
				                   "xMkQoIVxWPXPgaOYmDjTOXiMImVdzojERNxS",
				                   "dwICFwMAmdOIUxyAdXdshasnzwyhfnVWVqZJ",
				                   "etypXNVvSTEQvriGBZdSGmDEHhvpSqkFklCS",
				                   "YkxpFBCRYUueRcKaJUXVdaMoYMYEooPQVMOr",
				                   "DTrexDqclZNKdPuTRFHualJSFziCLPCZjpxo",
				                   "TfEijcAsSJPikkmBSbXMqYHAhPTcpcKVSkIX",
				                   "xKXHYPYMJxFpSbxltDKYuRiTkOLxpQKnXZPs",
				                   "YFYuvuYHfpFJcrLNIdlNfBxRnWdppsdalBkx",
				                   "NFTysBvNFjejdnlhRTclbcfGipNCxpFEOriY",
				                   "thkgVflJYmbUYbIlafNUMGePQWiZyYzYXvUR"};
				int L = 1200;
				_expected = 396065426;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			case 5:
			{
				string color1[] = {"aabbaabb"};
				string color2[] = {"aaaaaaaa"};
				int L = 4;
				_expected = 1680;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			case 6:
			{
				string color1[] = {"abbccbcacba"};
				string color2[] = {"aaaaaaaaaaa"};
				int L = 5;
				_expected = 1976436;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
			}
			/*case 7:
			{
				string color1[] = ;
				string color2[] = ;
				int L = ;
				_expected = ;
				_received = _obj.count(vector <string>(color1, color1+sizeof(color1)/sizeof(string)), vector <string>(color2, color2+sizeof(color2)/sizeof(string)), L); break;
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
