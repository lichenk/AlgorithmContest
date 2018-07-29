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

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
ll a[1004];
ll f[104][104];
bool vowel(char x) {
	return (x=='a')||(x=='e')||(x=='i')||(x=='o')||(x=='u');
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll nn; cin>>nn;
	for (ll i=0;i<nn;i++) cin>>a[i];
	{
		string s;getline(cin,s);
	}
	bool ans=true;
	for (ll i=0;i<nn;i++) {
		string s;
		getline(cin,s);
		//cout<<s<<endl;
		ll n=s.length();
		//printf("n:%lld\n",n);
		for (ll x=0;x<=n;x++) for (ll y=0;y<=n;y++) f[x][y]=0;
		f[0][0]=1;
		for (ll x=0;x<n;x++) {
			if (s[x]==' ') {
				for (ll w=0;w<=n;w++) {
					f[x+1][w]=f[x][w];
				}
			}
			for (ll w=0;w<=n;w++) {
				if (f[x][w]) {
					ll add=0;
					for (ll y=x;y<n;y++) {
						if (s[y]==' ') break;
						if (vowel(s[y])) {
							if (add==1) break;
							else add=1;
						}
						//printf("%lld %lld->%lld %lld %c\n",x,y,y+1,w+add,s[y]);
						f[y+1][w+add]=1;
					}
				}
			}
		}
		if (!f[n][a[i]]) {
			//printf("i:%lld\n",i);
			ans=false;
		}
	}
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

