#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int NN = 100100, L = 500100;

int k;
char buf[L];
string a[NN];
int c[NN];

inline bool read() {
	if (!(cin >> k)) return false;
	forn(i, k) {
		assert(scanf("%s", buf) == 1);
		a[i] = string(buf);
	}
	forn(i, k) assert(scanf("%d", &c[i]) == 1);
	return true;
}

struct node {
	int l, r;
	int parent, link;
	map<int, int> next;
	node(int l = 0, int r = 0, int parent = 0): l(l), r(r), parent(parent) {
		link = -1;
		next.clear();
	}
};
struct state {
	int v, pos;
	state(int v = 0, int pos = 0): v(v), pos(pos) { }
};
const int N = 1000 * 1000 + 3;
int n;
int s[N];
int tsz = 1;
node t[2 * N];
state ptr;
inline int len(int v) { return t[v].r - t[v].l; }
inline int split(state st) {
	if (st.pos == 0) return t[st.v].parent;
	if (st.pos == len(st.v)) return st.v;
	int cur = tsz++;
	t[cur] = node(t[st.v].l, t[st.v].l + st.pos, t[st.v].parent);
	t[cur].next[s[t[st.v].l + st.pos]] = st.v;
	t[t[st.v].parent].next[s[t[st.v].l]] = cur;
	t[st.v].parent = cur;
	t[st.v].l += st.pos;
	return cur;
}
state go(state st, int l, int r) {
	while (l < r) {
		if (st.pos == len(st.v)) {
			if (!t[st.v].next.count(s[l])) return state(-1, -1);
			st = state(t[st.v].next[s[l]], 0);
		}
		else {
			if (s[t[st.v].l + st.pos] != s[l]) return state(-1, -1);
			int d = min(len(st.v) - st.pos, r - l);
			l += d;
			st.pos += d;
		}
	}
	return st;
}
int link(int v) {
	int& ans = t[v].link;
	if (ans != -1) return ans;
	if (v == 0) return ans = 0;
	int p = t[v].parent;
	return ans = split(go(state(link(p), len(link(p))), t[v].l + (p == 0), t[v].r));
}
inline void treeExtand(int i) {
	while (true) {
		state next = go(ptr, i, i + 1);
		if (next.v != -1) {
			ptr = next;
			break;
		}
		int mid = split(ptr), cur = tsz++;
		t[cur] = node(i, n, mid);
		t[mid].next[s[i]] = cur;
		if (mid == 0) break;
		ptr = state(link(mid), len(link(mid)));
	}
}

li ans;
set<pt> pos;

li dfs(int v, int len) {
	//if (v) assert(t[v].l < t[v].r);
	li sum = 0;
	auto it = pos.lower_bound(mp(t[v].l, -INF));
	if (it != pos.end() && it->x < t[v].r) {
		//cerr << "len=" << len << " l=" << t[v].l << " r=" << t[v].r << endl;
		sum += it->y;
		if (it->x > t[v].l) {
			len += it->x - t[v].l;
			ans = max(ans, len * sum);
		}
		return sum;
	}

	len += t[v].r - t[v].l;
	for (auto nt : t[v].next)
		sum += dfs(nt.y, len);
	ans = max(ans, len * sum);
	return sum;
}

inline ostream& operator<< (ostream& out, const pt& p) { return out << "(" << p.x << ", " << p.y << ")"; }

inline void solve() {
	n = 0;
	pos.clear();
	forn(i, k) {
		forn(j, sz(a[i])) s[n++] = int(a[i][j]);
		pos.insert(mp(n, c[i]));
		s[n++] = 300 + i;
	}

	//for (auto it : pos) cerr << it << ' '; cerr << endl;

	//cerr << n << endl;
	//forn(i, n) cerr << s[i] << ' '; cerr << endl;
	
	forn(i, tsz) t[i] = node();
	ptr = state();
	tsz = 1;
	forn(i, n) treeExtand(i);

	ans = 0;
	dfs(0, 0);
	cout << ans << endl;

	/*li s = 0;
	forn(i, k) s += c[i];
	cerr << s << endl;*/
}

int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    while (read()) {
		solve();
		//break;
	}
	
    return 0;
}