#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl "\n"
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define MAXN 300004
#define MAXSEG (4*MAXN)
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

typedef vector<ld> vi;
typedef vector<vi> vvi;

vvi segtree[MAXSEG];
ll ang[MAXN], trans[MAXN];
ld tcos[360],tsin[360];

vvi mul(const vvi &a, const vvi &b) {
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    vvi res(n, vi(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int p = 0; p < m; p++)
            	res[i][j] += a[i][p] * b[p][j];
    return res;
}

vvi translate_matrix(ld translate) {
	vvi res = {
		{1,0,translate},
		{0,1,0},
		{0,0,1},
	};
	return res;
}

vvi rotate_matrix(ll deg) {
	deg %= 360;
	while (deg < 0) deg += 360;
	ll angle=deg;
	vvi res = {
		{tcos[angle],tsin[angle],0},
		{-tsin[angle],tcos[angle],0},
		{0,0,1},
	};
	return res;
}


void ins(ll bot, ll top, ll x, ll idx) {
	if (bot == top) {
		assert(bot == x);
		segtree[idx] = mul(rotate_matrix(ang[x]), translate_matrix(trans[x]));
		return;
	}
	ll mid = (bot+top)/2;
	if (x <= mid) {
		ins(bot, mid, x, idx*2+1);
	}
	else {
		ins(mid+1, top, x, idx*2+2);
	}
	segtree[idx] = mul(segtree[idx*2+1], segtree[idx*2+2]);
}

void init(ll bot, ll top, ll idx) {
	if (bot == top) {
		segtree[idx] = mul(translate_matrix(trans[bot]), rotate_matrix(ang[bot]));
		return;
	}
	ll mid = (bot+top)/2;
	init(bot, mid, idx*2+1);
	init(mid+1, top, idx*2+2);
	segtree[idx] = mul(segtree[idx*2+1], segtree[idx*2+2]);
}
int main() {
	ll n,m;
	for (ll i=0;i<360;i++) {
		ld angle = i;
		angle = angle*PI/180.0;
		tcos[i]=cos(angle);
		tsin[i]=sin(angle);
	}
	scanf("%lld %lld",&n,&m);
	for (ll i = 1; i <= n; i++) {
		ang[i] = 0; trans[i] = 1;
	}
	init(1,n,0);
	for (ll i = 0; i < m; i++) {
		ll type,seg,val;
		scanf("%lld %lld %lld",&type,&seg,&val);
		if (type == 1) {
			trans[seg] += val;
		}
		else {
			ang[seg] += val;
		}
		ins(1, n, seg, 0);
		vvi res = segtree[0];
		printf("%.8f %.8f\n",(double)res[0][2], (double)res[1][2]);
	}

}