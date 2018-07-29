#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const int UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
#define MAXN 210004
int t1[MAXN],t2[MAXN]; // MAXN = maxindex + 1
int v[MAXN];
// T[i] += value
void add(int *t, int i, int value) {
  for (; i < MAXN; i |= i + 1)
    t[i] += value;
}

  // sum[0..i]
int sum(int *t, int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res += t[i];
  return res;
}

void sset(int *t, int i, int value) {
  int orig = sum(t,i)-sum(t,i-1);
  add(t,i,value-orig);
}


int main() {
	ios_base::sync_with_stdio(false);
	int n, k, a, b, q;
	scanf("%I64d %I64d %I64d %I64d %I64d",&n,&k,&a,&b,&q);
	for (int i=0;i<MAXN;i++) {
		t1[i]=0;
		t2[i]=0;
		v[i]=0;
	}
	for (int zz=0;zz<q;zz++) {
		int tp; scanf("%I64d",&tp);
		if (tp==1) {
			int di,ai; scanf("%I64d %I64d",&di,&ai);
			v[di]+=ai;
			sset(t1,di,min(v[di],b));
			sset(t2,di,min(v[di],a));
			//printf("Set: %I64d: %I64d %I64d\n",di,min(v[di],b),min(v[di],a));
		}
		else {
			int qi;scanf("%I64d",&qi);
			int ans1 = sum(t2,n)-sum(t2,min(qi+k-1,n));
			//printf("Q:%I64d-%I64d:%I64d. %I64d %I64d\n",min(qi+k-1,n),n,ans1,sum(t2,min(qi+k-1,n)),sum(t2,n));
			int ans2 = sum(t1,qi-1);
			//printf("Q:%I64d:%I64d\n",qi-1,ans2);
			int final=ans1+ans2;
			printf("%I64d\n",final);
		}
	}
}



/*
typedef int FT2;
FT2 t2[MAXN];
FT2 NEUTRAL2=0;
FT2 comb2(FT2 x, FT2 y) { // ONLY COMMUTATIVE OPERATIONS ALLOWED
	return x+y;
}
// T[i] += value. Only modifictions allowed, no setting.
void fenwick_modify2(int i, FT2 value) {
  for (; i < MAXN; i |= i + 1)
    t2[i]=comb2(t2[i],value);
}

  // sum[0..i]
FT2 fenwick_query2(int i) {
  FT2 res = NEUTRAL2;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res = comb2(res,t2[i]);
  return res;
}
*/