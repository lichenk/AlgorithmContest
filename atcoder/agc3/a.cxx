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
int main() {
	ios_base::sync_with_stdio(false);
	string t; cin>>t;
	ll n=0,s=0,w=0,e=0;
	for (auto &c:t) {
		if (c=='N') n=1;
		if (c=='S') s=1;
		if (c=='E') e=1;
		if (c=='W') w=1;
	}
	//printf("%d %d %d %d. %lld %lld\n",n,s,e,w,n^s,e^w);
	if ((n^s)||(e^w)) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}