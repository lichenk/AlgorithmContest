#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef int ST;
class SegmentTreeFast {
public:
	// Modify the following 5 methods to implement your custom operations on the tree.
	// This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
	ST modifyOperation(ST x, ST y) {
		return max(x,y);
	}

	// query (or combine) operation
	ST queryOperation(ST leftValue, ST rightValue) {
		return max(leftValue, rightValue);
	}

	ST deltaEffectOnSegment(ST delta, int segmentLength) {
		if (delta == getNeutralDelta()) return getNeutralDelta();
		// Here you must write a fast equivalent of following slow code:
		// int result = delta;
		// for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
		// return result;
		return delta;
	}

	ST getNeutralDelta() {
		return -1;
	}

	ST getInitValue() {
		return -1;
	}

	ST getNeutralValue() {
		return -1;
	}

	// generic code
	ST *value;
	ST *delta; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]
	int gn;

	ST joinValueWithDelta(ST value, ST delta) {
		if (delta == getNeutralDelta()) return value;
		return modifyOperation(value, delta);
	}

	ST joinDeltas(ST delta1, ST delta2) {
		if (delta1 == getNeutralDelta()) return delta2;
		if (delta2 == getNeutralDelta()) return delta1;
		return modifyOperation(delta1, delta2);
	}

	void pushDelta(int i) {
		int d = 0;
		for (; (i >> d) > 0; d++) {
		}
		for (d -= 2; d >= 0; d--) {
			int x = i >> d;
			value[x >> 1] = joinNodeValueWithDelta(x >> 1, 1 << (d + 1));
			delta[x] = joinDeltas(delta[x], delta[x >> 1]);
			delta[x ^ 1] = joinDeltas(delta[x ^ 1], delta[x >> 1]);
			delta[x >> 1] = getNeutralDelta();
		}
	}

	SegmentTreeFast(int n) {
		gn=n;
		value = new int[2 * n];
		for (int i = 0; i < n; i++) {
			value[i + n] = getInitValue();
		}
		for (int i = 2 * n - 1; i > 1; i -= 2) {
			value[i >> 1] = queryOperation(value[i], value[i ^ 1]);
		}
		delta = new int[2 * n];
		fill(delta, delta + (2*n), getNeutralDelta());
	}

	int joinNodeValueWithDelta(int i, int len) {
		return joinValueWithDelta(value[i], deltaEffectOnSegment(delta[i], len));
	}

	ST query(int from, int to) {
		from += gn;
		to += gn;
		pushDelta(from);
		pushDelta(to);
		ST res = getNeutralValue();
		bool found = false;
		for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
			if ((from & 1) != 0) {
				res = found ? queryOperation(res, joinNodeValueWithDelta(from, len)) : joinNodeValueWithDelta(from, len);
				found = true;
			}
			if ((to & 1) == 0) {
				res = found ? queryOperation(res, joinNodeValueWithDelta(to, len)) : joinNodeValueWithDelta(to, len);
				found = true;
			}
		}
		if (!found) assert(0);
		return res;
	}

	void modify(int from, int to, ST delta) {
		from += gn;
		to += gn;
		pushDelta(from);
		pushDelta(to);
		int a = from;
		int b = to;
		for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
			if ((from & 1) != 0) {
				this->delta[from] = joinDeltas(this->delta[from], delta);
			}
			if ((to & 1) == 0) {
				this->delta[to] = joinDeltas(this->delta[to], delta);
			}
		}
		for (int i = a, len = 1; i > 1; i >>= 1, len <<= 1) {
			value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
		}
		for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
			value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
		}
	}
};
int nextInt(int x) {
	return (rand()%x);
}
	// Random test
	int main() {
		for (int step = 0; step < 1000; step++) {
			int n = nextInt(50) + 1;
			int *x = new int[n];
			SegmentTreeFast t = SegmentTreeFast(n);
			fill(x, x+n, t.getInitValue());
			for (int i = 0; i < 1000; i++) {
				int b = nextInt(n);
				int a = nextInt(b + 1);
				int cmd = nextInt(3);
				if (cmd == 0) {
					int delta = nextInt(100) - 50;
					t.modify(a, b, delta);
					for (int j = a; j <= b; j++) {
						x[j] = t.joinValueWithDelta(x[j], delta);
					}
				} else if (cmd == 1) {
					int res1 = t.query(a, b);
					int res2 = x[a];
					for (int j = a + 1; j <= b; j++) {
						res2 = t.queryOperation(res2, x[j]);
					}
					if (res1 != res2) {
						assert(0);
					}

				} else {
					for (int j = 0; j < n; j++) {
						if (t.query(j, j) != x[j]) {
							assert(0);
						}
					}
				}
			}
		}
		printf("Test passed\n");
	}