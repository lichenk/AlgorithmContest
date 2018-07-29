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
ld f[41][52][52][52];
ld src[52][52][52];
ld dest[52][52][52];
class RandomColoring {
	public:
	double getProbability(int N, int _maxR, int _maxG, int _maxB, int startR, int startG, int startB, int d1, int d2) {
		N--;
		d1--;
		ll maxR=_maxR, maxG=_maxG, maxB=_maxB;
		for (ll r=0;r<maxR;r++)for (ll g=0;g<maxG;g++)for (ll b=0;b<maxB;b++) f[0][r][g][b]=0;
		f[0][startR][startG][startB]=1;
		ll vd[2];
		vd[0]=d2,vd[1]=d1;
		ll vsign[2];
		vsign[0]=1,vsign[1]=-1;
		for (ll x=0;x<N;x++) {
			for (ll r=0;r<maxR;r++)for (ll g=0;g<maxG;g++)for (ll b=0;b<maxB;b++) f[x+1][r][g][b]=0;
			for (ll r=0;r<maxR;r++)for (ll g=0;g<maxG;g++)for (ll b=0;b<maxB;b++) {
				ll cnt=0;
				{
					ll d=d2;
					ll lor=max(0LL,r-d);
					ll hir=min(maxR-1,r+d);
					ll log=max(0LL,g-d);
					ll hig=min(maxG-1,g+d);
					ll lob=max(0LL,b-d);
					ll hib=min(maxB-1,b+d);
					cnt=(hir-lor+1)*(hig-log+1)*(hib-lob+1);
					//if (r==2) //printf("%d %d %d %d %d %d %d\n",hir,lor,hig,log,hib,lob,cnt);
				}
				if (d1>=0){
					ll d=d1;
					ll lor=max(0LL,r-d);
					ll hir=min(maxR-1,r+d);
					ll log=max(0LL,g-d);
					ll hig=min(maxG-1,g+d);
					ll lob=max(0LL,b-d);
					ll hib=min(maxB-1,b+d);
					cnt-=(hir-lor+1)*(hig-log+1)*(hib-lob+1);
					//if (r==2) //printf("%d %d %d %d %d %d %d\n",hir,lor,hig,log,hib,lob,cnt);
				}
				//if (r==2) //printf("CNT %d\n",cnt);
				if (cnt!=0) f[x][r][g][b]/=cnt;
			}
			for (ll k=0;k<2;k++) {
				ll d=vd[k];
				//printf("d:%lld\n",d);
				if (d<0) continue;
				for (ll r=0;r<maxR;r++)for (ll g=0;g<maxG;g++)for (ll b=0;b<maxB;b++) {
					src[r][g][b]=f[x][r][g][b];
					//printf("r:%d g:%d b:%d %f\n",r,g,b,src[r][g][b]);
				}
				for (ll g=0;g<maxG;g++) for (ll b=0;b<maxB;b++)  {
					ld have=0;
					for (ll r=0;r<d;r++) have+=src[r][g][b];
					for (ll r=0;r<maxR;r++) {
						if (r+d<maxR) have+=src[r+d][g][b];
						if (r-d-1>=0) have-=src[r-d-1][g][b];
						////printf("Convolve r:%d g:%d b:%d have:%f\n",r,g,b,have);
						dest[r][g][b]=have;
					}
				}
				for (ll r=0;r<maxR;r++)for (ll g=0;g<maxG;g++)for (ll b=0;b<maxB;b++) {
					src[r][g][b]=dest[r][g][b];
					//printf("Convolved R. r:%d g:%d b:%d %f\n",r,g,b,dest[r][g][b]);
				}
				for (ll r=0;r<maxR;r++) for (ll b=0;b<maxB;b++) {
					ld have=0;
					for (ll g=0;g<d;g++) have+=src[r][g][b];
					for (ll g=0;g<maxG;g++) {
						if (g+d<maxG) have+=src[r][g+d][b];
						if (g-d-1>=0) have-=src[r][g-d-1][b];
						dest[r][g][b]=have;
					}
				}
				for (ll r=0;r<maxR;r++)for (ll g=0;g<maxG;g++)for (ll b=0;b<maxB;b++) {
					src[r][g][b]=dest[r][g][b];
					//printf("Convolved R,G. r:%d g:%d b:%d %f\n",r,g,b,dest[r][g][b]);
				}
				for (ll r=0;r<maxR;r++) for (ll g=0;g<maxG;g++) {
					ld have=0;
					for (ll b=0;b<d;b++) have+=src[r][g][b];
					for (ll b=0;b<maxB;b++) {
						if (b+d<maxB) have+=src[r][g][b+d];
						if (b-d-1>=0) have-=src[r][g][b-d-1];
						dest[r][g][b]=have;
					}
				}

				ll sign=vsign[k];
				for (ll r=0;r<maxR;r++){
					for (ll g=0;g<maxG;g++){
						for (ll b=0;b<maxB;b++) {
							f[x+1][r][g][b]+=dest[r][g][b]*sign;
							//printf("New f %lld %lld %lld: %f\n",r,g,b,dest[r][g][b]*sign);
						}
					}
				}
			}
		}
		ld ans=0;
		{
			ll r=startR, g=startG,b=startB;
				{
					ll d=d2;
					ll lor=max(0LL,r-d);
					ll hir=min(maxR-1,r+d);
					ll log=max(0LL,g-d);
					ll hig=min(maxG-1,g+d);
					ll lob=max(0LL,b-d);
					ll hib=min(maxB-1,b+d);
					for (ll r=lor;r<=hir;r++) for (ll g=log;g<=hig;g++) for (ll b=lob;b<=hib;b++) {
						ans+=f[N][r][g][b];
					}
				}
				{
					ll d=d1;
					ll lor=max(0LL,r-d);
					ll hir=min(maxR-1,r+d);
					ll log=max(0LL,g-d);
					ll hig=min(maxG-1,g+d);
					ll lob=max(0LL,b-d);
					ll hib=min(maxB-1,b+d);
					for (ll r=lor;r<=hir;r++) for (ll g=log;g<=hig;g++) for (ll b=lob;b<=hib;b++) {
						ans-=f[N][r][g][b];
					}
				}
		}
		ans=1-ans;
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
		cout << "Testing RandomColoring (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1471446148;
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
		RandomColoring _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int maxR = 5;
				int maxG = 1;
				int maxB = 1;
				int startR = 2;
				int startG = 0;
				int startB = 0;
				int d1 = 0;
				int d2 = 1;
				_expected = 0.0;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 1:
			{
				int N = 3;
				int maxR = 5;
				int maxG = 1;
				int maxB = 1;
				int startR = 2;
				int startG = 0;
				int startB = 0;
				int d1 = 0;
				int d2 = 1;
				_expected = 0.22222222222222227;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 2:
			{
				int N = 7;
				int maxR = 4;
				int maxG = 2;
				int maxB = 2;
				int startR = 0;
				int startG = 0;
				int startB = 0;
				int d1 = 3;
				int d2 = 3;
				_expected = 1.0;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 3:
			{
				int N = 10;
				int maxR = 7;
				int maxG = 8;
				int maxB = 9;
				int startR = 1;
				int startG = 2;
				int startB = 3;
				int d1 = 0;
				int d2 = 10;
				_expected = 0.0;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 4:
			{
				int N = 10;
				int maxR = 7;
				int maxG = 8;
				int maxB = 9;
				int startR = 1;
				int startG = 2;
				int startB = 3;
				int d1 = 4;
				int d2 = 10;
				_expected = 0.37826245943967396;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 5:
			{
				int N = 3;
				int maxR = 3;
				int maxG = 2;
				int maxB = 2;
				int startR = 1;
				int startG = 0;
				int startB = 0;
				int d1 = 1;
				int d2 = 2;
				_expected = 0.09090909090909148;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			case 6:
			{
				int N = 2;
				int maxR = 5;
				int maxG = 1;
				int maxB = 1;
				int startR = 2;
				int startG = 0;
				int startB = 0;
				int d1 = 0;
				int d2 = 0;
				_expected = 0.0;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}
			/*case 7:
			{
				int N = ;
				int maxR = ;
				int maxG = ;
				int maxB = ;
				int startR = ;
				int startG = ;
				int startB = ;
				int d1 = ;
				int d2 = ;
				_expected = ;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}*/
			/*case 8:
			{
				int N = ;
				int maxR = ;
				int maxG = ;
				int maxB = ;
				int startR = ;
				int startG = ;
				int startB = ;
				int d1 = ;
				int d2 = ;
				_expected = ;
				_received = _obj.getProbability(N, maxR, maxG, maxB, startR, startG, startB, d1, d2); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
