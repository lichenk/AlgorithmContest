#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

void go(ll A,ll B,ll C,ll D) {
	--C; --D;
	ll maxleftsz;
		ll r=max(
			(A+B)/(B+1),
			(B+A)/(A+1)
			);
	{
		ll imin=0,imax=A+B+1;
		while(imin<imax) {
			ll imid=(imin+imax)>>1;
			ll blocks=(imid-1)/(r+1);
			bool ok=1;
			ll sa=imid-blocks*(r+1);
			ll ta=r*blocks+sa;
			ll tb=blocks;
			ll la=A-ta,lb=B-tb;
			if (r*(la+1) < lb) ok=0;
			if (ok) imin=imid+1;
			else imax=imid;
		}
		maxleftsz=imin-1;
	}
	ll gleftsz=maxleftsz;
	//printf("leftsz:%d\n",gleftsz);
	{
		ll leftsz=gleftsz;
		ll leftblocks=(leftsz-1)/(r+1);
		ll sa=leftsz-leftblocks*(r+1);
		ll rightsz=A+B-leftsz;
		ll rightblocks=rightsz/(r+1);
		ll qb=rightsz-rightblocks*(r+1);
		for (ll _pos=C;_pos<=D;_pos++) {
			ll pos=_pos;
			char c;
			if (pos<leftblocks*(r+1)) {
				pos%=(r+1);
				if (pos==r) c='B'; else c='A';
			}
			else if (pos<leftsz) {
				c='A';
			}
			else if (pos<leftsz+qb) {
				c='B';
			}
			else {
				pos-=leftsz+qb;
				pos%=(r+1);
				if (pos==0) c='A'; else c='B';
			}
			printf("%c",c);
		}
	}
	printf("\n");
}


void solve(long long Q, vector<long long> A, vector<long long> B, vector<long long> C, vector<long long> D){
	for (ll i=0;i<Q;i++) {
		go(A[i],B[i],C[i],D[i]);
	}
}

int main(){	
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long Q;
	scanf("%lld",&Q);
	vector<long long> D(Q-1+1);
	vector<long long> C(Q-1+1);
	vector<long long> A(Q-1+1);
	vector<long long> B(Q-1+1);
	for(int i = 0 ; i <= Q-1 ; i++){
		scanf("%lld",&A[i]);
		scanf("%lld",&B[i]);
		scanf("%lld",&C[i]);
		scanf("%lld",&D[i]);
	}
	solve(Q, A, B, C, D);
	return 0;
}

