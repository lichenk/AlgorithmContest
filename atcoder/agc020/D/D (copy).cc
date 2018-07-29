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

void go(int A,int B,int C,int D) {
	--C; --D;
	int imin=0,imax=A+B+1;
	int r=max(
		(A+B)/(B+1),
		(B+A)/(A+1)
		);
	printf("r:%d\n",r);
	while(imin<imax) {
		int imid=(imin+imax)>>1;
		int blocks=imid/(r+1);
		bool ok=1;
		int sa=imid-blocks*(r+1);
		int ta=r*blocks+sa;
		int tb=blocks;
		int la=A-ta,lb=B-tb;
		if (sa<1&&tb>0) ok=0;
		if (sa>r) ok=0;
		if (la<0||lb<0) ok=0;
		if (r*(la+1) < lb) ok=0;

		int leftsz=imid;
		int rightsz=A+B-leftsz;
		int rightblocks=la;
		int qb=rightsz-rightblocks*(r+1);
		if (qb==0) ok=0;
		if (qb>r) ok=0;
		if (imid==2) printf("ta:%d tb:%d la:%d lb:%d qb:%d\n",ta,tb,la,lb,qb);

		if (ok) imin=imid+1;
		else imax=imid;
	}
	printf("leftsz:%d\n",imin-1);
	{
		int leftsz=imin-1;
		int leftblocks=leftsz/(r+1);
		int sa=leftsz-leftblocks*(r+1); assert(sa>=0);

		int rightsz=A+B-leftsz;
		int rightblocks=rightsz/(r+1);
		int qb=rightsz-rightblocks*(r+1);
		for (int _pos=C;_pos<=D;_pos++) {
			int pos=_pos;
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

