#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MAXN 200010
#define MOD 1000000007

using namespace std;

int n,p[MAXN];
vector<int> ch[MAXN];
long long dp[MAXN],prod[MAXN];
int z[MAXN];
long long ans[MAXN];

long long modpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void dfs1(int u) {
    dp[u] = 1;
    prod[u] = 1;
    for (auto v : ch[u]) {
        dfs1(v);
        dp[u] *= dp[v] + 2;
        dp[u] %= MOD;
        if (!z[u] && dp[v] + 2 == MOD) {
            z[u] = v;
        }
        else {
            prod[u] *= dp[v] + 2;
            prod[u] %= MOD;
        }
    }
    dp[u]--;
    if (dp[u] < 0) dp[u] += MOD;
    //printf("u:%d dp:%d\n",u,dp[u]);
}

void dfs2(int u, long long x) {
    //cerr << u << ": " << dp[u] << ' ' << x << endl;
    ans[u] = dp[u] + 1;
    if (u != 1) ans[u] *= x + 2;
    ans[u] %= MOD;
    for (auto v : ch[u]) {
        long long xx;
        if (v == z[u]) xx = prod[u];
        else {
            xx = (dp[u] + 1) % MOD;
            xx *= modpow((dp[v] + 2) % MOD, MOD-2);
            xx %= MOD;
        }
        if (u != 1) {
            xx *= x + 2;
            xx %= MOD;
        }
        xx--;
        if (xx < 0) xx += MOD;
        dfs2(v,xx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        ch[p[i]].push_back(i);
    }
    dfs1(1);
    dfs2(1,0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout<<endl;
}