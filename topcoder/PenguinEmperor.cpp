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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }

typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = MOD;
const ll MAXN=352;
vvi matrixDONTUSEUnit(int n) {
    vvi res(n, vi(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}

vvi matrixDONTUSEMul(const vvi &a, const vvi &b) {
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    vvi res(n, vi(k));
    for (int j=0;j<k;j++) {
    	int sum=0;
    	for (int p=0;p<m;p++) {
    		sum = (sum + (long long) a[0][p] * b[p][j]) % MOD;
    	}
    	res[0][j]=sum;
    }
    for (int i=1;i<n;i++) {
    	for (int j=0;j<n;j++) {
    		int d=abs(i-j);
    		res[i][j]=res[0][d];
    	}
    }
    return res;
}

vvi matrixDONTUSEPow(const vvi &a, ll p) {
	vvi ans=matrixDONTUSEUnit(a.size());
	vvi base=a;
	while(p>0) {
		if ((p%2)==0) {
			base=matrixDONTUSEMul(base,base);
			p/=2;
		}
		else {
			ans=matrixDONTUSEMul(base,ans);
			p--;
		}
	}
	return ans;
}
ll v[MAXN],w[MAXN];
vvi tab[2][MAXN];
ll need[2];
void initf(unordered_set<ll> s) {
	for (auto &n:s) {
		vvi mat(n, vi(n));
		for (ll x=0;x<n;x++) {
			for (ll y=0;y<n;y++) {
				mat[x][y]=0;
			}
		}
		for (ll x=0;x<n;x++) {
			mat[x][(x+1)%n]=1;
			mat[x][(x-1+n)%n]=1;
		}
		for (ll k=0;k<2;k++) {
			tab[k][n]=matrixDONTUSEPow(mat,need[k]);
		}
	}
}
ll gmat[MAXN][MAXN];

class PenguinEmperor {
	public:
	int countJourneys(int numCities, long long daysPassed) {
		ll n=numCities;
		need[0]=daysPassed/n;
		need[1]=(daysPassed/n)+1;
		unordered_set<ll> s;
		for (ll d=1;d<n;d++) {
			s.insert(n/__gcd(d,n));
		}
		initf(s);
		for (ll x=0;x<n;x++) v[x]=0;
		v[0]=1;
		for (ll d=1;d<n;d++) {
			ll localneed = (daysPassed+n-d)/n;
			//printf("d:%lld need:%lld\n",d,localneed);
			ll k=(localneed==need[0])?0:1;
			assert(need[k]==localneed);
			ll gcd=__gcd(d,n);
			for (ll x=0;x<n;x++) {
				for (ll y=0;y<n;y++) {
					gmat[x][y]=0;
				}
			}
			for (ll init=0;init<n;init++) {
				ll y=init;
				ll h=n/gcd;
				for (ll i=0;i<h;i++) {
					gmat[init][y]=tab[k][h][0][i];
					y=(y+d)%n;
				}
				assert(y==init);
			}
			for (ll x=0;x<n;x++) {
				ll sum=0;
				for (ll y=0;y<n;y++) {
					//printf("%lld ",gmat[x][y]);
					sum+=(gmat[x][y]*v[y])%MOD;
				}
				//printf("\n");
				w[x]=sum%MOD;
			}
			for (ll x=0;x<n;x++) {
				v[x]=w[x];
			}
		}
		return v[0];
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
		cout << "Testing PenguinEmperor (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1460329848;
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
		PenguinEmperor _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numCities = 3;
				long long daysPassed = 2LL;
				_expected = 2;
				_received = _obj.countJourneys(numCities, daysPassed); break;
			}
			case 1:
			{
				int numCities = 4;
				long long daysPassed = 3LL;
				_expected = 2;
				_received = _obj.countJourneys(numCities, daysPassed); break;
			}
			case 2:
			{
				int numCities = 5;
				long long daysPassed = 36LL;
				_expected = 107374182;
				_received = _obj.countJourneys(numCities, daysPassed); break;
			}
			case 3:
			{
				int numCities = 300;
				long long daysPassed = 751LL;
				_expected = 413521250;
				_received = _obj.countJourneys(numCities, daysPassed); break;
			}
			case 4:
			{
				int numCities = 300;
				long long daysPassed = 750LL;
				_expected = 0;
				_received = _obj.countJourneys(numCities, daysPassed); break;
			}
			case 5:
			{
				int numCities = 350;
				long long daysPassed = 1000000000000000000LL;
				_expected = 667009739;
				_received = _obj.countJourneys(numCities, daysPassed); break;
			}
			case 6:
			{
				int numCities = 5;
				long long daysPassed = 7LL;
				_expected = 12;
				_received = _obj.countJourneys(numCities, daysPassed); break;
			}
			case 7:
			{
				int numCities = 6;
				long long daysPassed = 750LL;
				_expected = 0;
				_received = _obj.countJourneys(numCities, daysPassed); break;
			}
			case 8:
			{
				int numCities = 2;
				long long daysPassed = 1000000000000000000LL;
				_expected = 1;
				_received = _obj.countJourneys(numCities, daysPassed); break;
			}
			case 9:
			{
				int numCities = 2;
				long long daysPassed = 100000000001LL;
				_expected = 0;
				_received = _obj.countJourneys(numCities, daysPassed); break;
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
