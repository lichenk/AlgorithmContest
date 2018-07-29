#include <bits/stdc++.h>
 
using namespace std;
 
const int NMAX = 200000 + 5;
 
int N;
int A[NMAX];
 
int l[NMAX];
 
int ans;
int cnt[NMAX];
 
void addNr(int nr, int val) {
    if (val == 1) {
        l[nr] --;
        if (l[nr] > 0) {
            cnt[l[nr]] ++;
            if (cnt[l[nr]] == 1)
                ans --;
        }
    }
    else {
        if (l[nr] > 0) {
            cnt[l[nr]] --;
            if (cnt[l[nr]] == 0)
                ans ++;
        }
        l[nr] ++;
    }
}
 
int main() {
    int M = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; ++ i)
        l[i] = i + 1;
    ans = N;
    for (int i = 1; i <= N; ++ i) {
        cin >> A[i];
        addNr(A[i], 1);
    }
 
    while (M --) {
        int X, Y;
        cin >> X >> Y;
        addNr(A[X], -1);
        A[X] = Y;
        addNr(A[X], 1);
        cout << ans << '\n';
    }
 
    return 0;    
}