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
const ll mn=50;
ll a[mn][mn];
ll g(char c) {
	if ('a'<=c&&c<='z') return (c-'a')+26;
	else return (c-'A');
}
class BallsConverter {
	public:
	string theGood(vector <string> convert) {
		ll n=convert.size();
		for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) a[x][y]=g(convert[x][y]);
		for (ll x=0;x<n;x++) for (ll y=0;y<n;y++) for (ll z=0;z<n;z++) {
			if (a[a[x][y]][z]!=a[x][a[y][z]]) return "Bad";
		}
		return "Good";
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
		cout << "Testing BallsConverter (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485058332;
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
		BallsConverter _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string convert[] = {"AB", "BA"};
				_expected = "Good";
				_received = _obj.theGood(vector <string>(convert, convert+sizeof(convert)/sizeof(string))); break;
			}
			case 1:
			{
				string convert[] = {"BA", "AA"};
				_expected = "Bad";
				_received = _obj.theGood(vector <string>(convert, convert+sizeof(convert)/sizeof(string))); break;
			}
			case 2:
			{
				string convert[] = {"ACB", "CBA", "BAC"};
				_expected = "Bad";
				_received = _obj.theGood(vector <string>(convert, convert+sizeof(convert)/sizeof(string))); break;
			}
			case 3:
			{
				string convert[] = {"AAAA", "ABBB", "ABCC", "ABCD"};
				_expected = "Good";
				_received = _obj.theGood(vector <string>(convert, convert+sizeof(convert)/sizeof(string))); break;
			}
			case 4:
			{
				string convert[] = {"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
				                   "ABCDEFGHIJKLMNOPQRSTUVWXYZabcd",
				                   "ACEGIKMOQSUWYacACEGIKMOQSUWYac",
				                   "ADGJMPSVYbADGJMPSVYbADGJMPSVYb",
				                   "AEIMQUYcCGKOSWaAEIMQUYcCGKOSWa",
				                   "AFKPUZAFKPUZAFKPUZAFKPUZAFKPUZ",
				                   "AGMSYAGMSYAGMSYAGMSYAGMSYAGMSY",
				                   "AHOVcFMTaDKRYBIPWdGNUbELSZCJQX",
				                   "AIQYCKSaEMUcGOWAIQYCKSaEMUcGOW",
				                   "AJSbGPYDMVAJSbGPYDMVAJSbGPYDMV",
				                   "AKUAKUAKUAKUAKUAKUAKUAKUAKUAKU",
				                   "ALWDOZGRcJUBMXEPaHSdKVCNYFQbIT",
				                   "AMYGSAMYGSAMYGSAMYGSAMYGSAMYGS",
				                   "ANaJWFSBObKXGTCPcLYHUDQdMZIVER",
				                   "AOcMaKYIWGUESCQAOcMaKYIWGUESCQ",
				                   "APAPAPAPAPAPAPAPAPAPAPAPAPAPAP",
				                   "AQCSEUGWIYKaMcOAQCSEUGWIYKaMcO",
				                   "AREVIZMdQDUHYLcPCTGXKbOBSFWJaN",
				                   "ASGYMASGYMASGYMASGYMASGYMASGYM",
				                   "ATIbQFYNCVKdSHaPEXMBUJcRGZODWL",
				                   "AUKAUKAUKAUKAUKAUKAUKAUKAUKAUK",
				                   "AVMDYPGbSJAVMDYPGbSJAVMDYPGbSJ",
				                   "AWOGcUMEaSKCYQIAWOGcUMEaSKCYQI",
				                   "AXQJCZSLEbUNGdWPIBYRKDaTMFcVOH",
				                   "AYSMGAYSMGAYSMGAYSMGAYSMGAYSMG",
				                   "AZUPKFAZUPKFAZUPKFAZUPKFAZUPKF",
				                   "AaWSOKGCcYUQMIEAaWSOKGCcYUQMIE",
				                   "AbYVSPMJGDAbYVSPMJGDAbYVSPMJGD",
				                   "AcaYWUSQOMKIGECAcaYWUSQOMKIGEC",
				                   "AdcbaZYXWVUTSRQPONMLKJIHGFEDCB"};
				_expected = "Good";
				_received = _obj.theGood(vector <string>(convert, convert+sizeof(convert)/sizeof(string))); break;
			}
			case 5:
			{
				string convert[] = {"AAAAAFAAAAAAAAAAAAAAAAAXAAAAcAAAAAAAAAAnAAAAAAAvAA",
				                   "ABBBBFBBBBBLBBBBQBBBBBBXYBBBcBBBBBBBBBBnBBBBBBBvwB",
				                   "ABCCCFCCCCCLMCOCQRCCCCCXYCCCcCCCCCCCCCCnCCCCsCCvwC",
				                   "ABCDEFGHDDDLMDODQRSDUVWXYDDbcdDfghDDklDnopDrsDDvwx",
				                   "ABCEEFEEEEELMEOEQRSEUVWXYEEbcEEfEhEEklEnEpEEsEEvwE",
				                   "FFFFFFFFFFFFFFFFFFFFFFFXFFFFcFFFFFFFFFFFFFFFFFFvFF",
				                   "ABCGEFGGGGGLMGOGQRSGUVWXYGGbcGGfGhGGklGnGpGGsGGvwG",
				                   "ABCHEFGHHHHLMHOHQRSHUVWXYHHbcdHfHhHHklHnHpHHsHHvwH",
				                   "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwx",
				                   "ABCDEFGHJJJLMJOJQRSJUVWXYJJbcdJfghJJklJnopJrsJJvwx",
				                   "ABCDEFGHKJKLMNOPQRSTUVWXYZKbcdefghijklmnopqrsKKvwx",
				                   "ALLLLFLLLLLLLLLLLLLLLLLXLLLLcLLLLLLLLLLnLLLLLLLvwL",
				                   "ABMMMFMMMMMLMMOMQMMMMMMXYMMMcMMMMMMMMMMnMMMMMMMvwM",
				                   "ABCDEFGHNJNLMNOPQRSTUVWXYZNbcdefghijklmnopqrsNNvwx",
				                   "ABOOOFOOOOOLOOOOQOOOOOOXYOOOcOOOOOOOOOOnOOOOOOOvwO",
				                   "ABCDEFGHPJPLMPOPQRSTUVWXYZPbcdPfghiPklmnopPrsPPvwx",
				                   "AQQQQFQQQQQLQQQQQQQQQQQXQQQQcQQQQQQQQQQnQQQQQQQvwQ",
				                   "ABRRRFRRRRRLMRORQRRRRRRXYRRRcRRRRRRRRRRnRRRRRRRvwR",
				                   "ABCSSFSSSSSLMSOSQRSSSSSXYSSScSSSSSSSSSSnSSSSsSSvwS",
				                   "ABCDEFGHTJTLMTOTQRSTUVWXYTTbcdTfghiTklTnopTrsTTvwx",
				                   "ABCUUFUUUUULMUOUQRSUUUWXYUUUcUUUUhUUklUnUUUUsUUvwU",
				                   "ABCVVFVVVVVLMVOVQRSVUVWXYVVbcVVfVhVVklVnVVVVsVVvwV",
				                   "ABCWWFWWWWWLMWOWQRSWWWWXYWWWcWWWWhWWkWWnWWWWsWWvwW",
				                   "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXvXX",
				                   "AYYYYFYYYYYLYYYYQYYYYYYXYYYYcYYYYYYYYYYnYYYYYYYvwY",
				                   "ABCDEFGHZJZLMZOZQRSTUVWXYZZbcdZfghiZklZnopZrsZZvwx",
				                   "ABCDEFGHaJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwx",
				                   "ABCbbFbbbbbLMbObQRSbUbWXYbbbcbbfbhbbklbnbbbbsbbvwb",
				                   "cccccccccccccccccccccccXcccccccccccccccccccccccvcc",
				                   "ABCdEFGddddLMdOdQRSdUVWXYddbcddfdhddkldndpddsddvwd",
				                   "ABCDEFGHeJeLMeOPQRSTUVWXYZebcdefghijklmnoperseevwx",
				                   "ABCffFfffffLMfOfQRSfUfWXYfffcffffhffklfnffffsffvwf",
				                   "ABCgEFGHgggLMgOgQRSgUVWXYggbcdgfghggklgngpggsggvwg",
				                   "ABChhFhhhhhLMhOhQRShhhhXYhhhchhhhhhhkhhnhhhhshhvwh",
				                   "ABCDEFGHiJiLMiOiQRSiUVWXYiibcdifghiiklinopirsiivwx",
				                   "ABCDEFGHjJjLMjOPQRSTUVWXYZjbcdjfghijklmnopjrsjjvwx",
				                   "ABCkkFkkkkkLMkOkQRSkkkkXYkkkckkkkkkkkkknkkkkskkvwk",
				                   "ABCllFlllllLMlOlQRSlllWXYlllcllllhllkllnllllsllvwl",
				                   "ABCDEFGHmJmLMmOmQRSTUVWXYZmbcdmfghimklmnopmrsmmvwx",
				                   "nnnnnFnnnnnnnnnnnnnnnnnXnnnncnnnnnnnnnnnnnnnnnnvnn",
				                   "ABCoEFGHoooLMoOoQRSoUVWXYoobcdofghooklonoporsoovwx",
				                   "ABCppFpppppLMpOpQRSpUVWXYppbcppfphppklpnpppSsppvwp",
				                   "ABCDEFGHqJqLMqOPQRSTUVWXYZqbcdefghijklmnopqrsqqvwx",
				                   "ABCrEFGHrrrLMrOrQRSrUVWXYrrbcdrfghrrklrnrSrrsrrvwx",
				                   "ABsssFsssssLMsOsQRsssssXYssscssssssssssnsssssssvws",
				                   "ABCDEFGHtJKLMNOPQRSTUVWXYZtbcdefghijklmnopqrsttvwx",
				                   "ABCDEFGHuJKLMNOPQRSTUVWXYZubcdefghijklmnopqrstuvwx",
				                   "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
				                   "AwwwwFwwwwwwwwwwwwwwwwwXwwwwcwwwwwwwwwwnwwwwwwwvww",
				                   "ABCxEFGHxxxLMxOxQRSxUVWXYxxbcdxfghxxklxnxpxxsxxvwx"};
				_expected = "Bad";
				_received = _obj.theGood(vector <string>(convert, convert+sizeof(convert)/sizeof(string))); break;
			}
			/*case 6:
			{
				string convert[] = ;
				_expected = ;
				_received = _obj.theGood(vector <string>(convert, convert+sizeof(convert)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string convert[] = ;
				_expected = ;
				_received = _obj.theGood(vector <string>(convert, convert+sizeof(convert)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string convert[] = ;
				_expected = ;
				_received = _obj.theGood(vector <string>(convert, convert+sizeof(convert)/sizeof(string))); break;
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
