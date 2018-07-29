#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define INF 9223372036854775807LL
ll s[20],a[20];
ll f[20][2];
ll ten[20];

void g(ll need, ll x, ll i,ll current,ll next,bool any,ll k) {
    if (need == k || any) {
        ll cand = x+(k+current)*ten[i];
        f[i+1][next] = min(cand, f[i+1][next]);
    }
}

class LuckySum {
    public:
    long long construct(string note) {
        ll n = note.length();
        for (ll i = 0; i < n; i++) {
            ll x = note[n-1-i] - '0';
            if (note[n-1-i] == '?') x = -1;
            s[i] = x;
        }
        ten[0] = 1;
        for (ll i = 1; i < 20; i++) ten[i] = 10*ten[i-1];
ll ans = INF;
for (ll p = 1; p <= n; p++) {
    for (ll q = 1; q <= n; q++) {

    for (ll i = 0; i <= n; i++) {
        for (ll c = 0; c < 2; c++) {
            f[i][c] = INF;
        }
    }
    f[0][0] = 0;

    for (ll i = 0; i < n; i++) {
        for (ll next = 0; next < 2; next++) {
            for (ll current = 0; current < 2; current++) {
                bool any = (s[i] == -1);
                ll need = s[i] - current;
                ll x = f[i][current];
                if (x == INF) continue;
                ll nums = ((i<p)?1:0) + ((i<q)?1:0);
                if (nums==2) {
                    if (next == 0) {
                        g(need,x,i,current,next,any,8);
                    }
                    if (next == 1) {
                        g(need,x,i,current,next,any,1);
                        g(need,x,i,current,next,any,4);
                    }
                }
                else if (nums==1) {
                    if (next == 0) {
                        g(need,x,i,current,next,any,4);
                        g(need,x,i,current,next,any,7);
                    }
                }
                else if (nums == 0) {
                    if (i == n-1 && current == 0) continue;
                    if (next == 0) {
                        g(need,x,i,current,next,any,0);
                    }
                }
            }
        }
    }
    ll cand = f[n][0];
    ans = min(ans, cand);

    }
}
if (ans == INF) return -1;
else return ans;
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
        cout << "Testing LuckySum (300.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++)
        {
            ostringstream s; s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1450902517;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    }
    else
    {
        int _tc; istringstream(argv[1]) >> _tc;
        LuckySum _obj;
        long long _expected, _received;
        time_t _start = clock();
        switch (_tc)
        {
            case 0:
            {
                string note = "?";
                _expected = 8LL;
                _received = _obj.construct(note); break;
            }
            case 1:
            {
                string note = "?1";
                _expected = 11LL;
                _received = _obj.construct(note); break;
            }
            case 2:
            {
                string note = "4?8";
                _expected = 448LL;
                _received = _obj.construct(note); break;
            }
            case 3:
            {
                string note = "2??";
                _expected = -1LL;
                _received = _obj.construct(note); break;
            }
            case 4:
            {
                string note = "??????????????";
                _expected = 11888888888888LL;
                _received = _obj.construct(note); break;
            }
            /*case 5:
            {
                string note = ;
                _expected = LL;
                _received = _obj.construct(note); break;
            }*/
            /*case 6:
            {
                string note = ;
                _expected = LL;
                _received = _obj.construct(note); break;
            }*/
            /*case 7:
            {
                string note = ;
                _expected = LL;
                _received = _obj.construct(note); break;
            }*/
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
