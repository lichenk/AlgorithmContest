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
const ll maxn=105;
void solve(ll testnum) {
	ll Hd,Ad,Hk,Ak,B,D; cin>>Hd>>Ad>>Hk>>Ak>>B>>D;
	ll finalans=INF;
	for (ll debuffs=0;debuffs<=maxn;debuffs++) {
		for (ll buffs=0;buffs<=maxn;buffs++) {
			ll dh=Hd;
			ll kh=Hk;
			ll da=Ad;
			ll ka=Ak;
			ll b=buffs,db=debuffs;
			for (ll c=0;c<1000;c++) {
				bool ok=false;
				for (ll t=0;t<4;t++) {
					ll old_dh=dh;
					ll old_kh=kh;
					ll old_da=da;
					ll old_ka=ka;
					bool commit=false;
					if (t==0&&db>0) {
						ka=max(0ll,ka-D);
						{
							dh-=ka;
							if (dh>0) {
								commit=true;
								db--;
							}
						}
					}
					if (t==1&&b>0) {
						da+=B;
						{
							dh-=ka;
							if (dh>0) {
								commit=true;
								b--;
							}
						}
					}
					if (t==2) {
						kh-=da;
						{
							dh-=ka;
							if (dh>0||kh<=0) {
								if (kh<=0) {
									chkmin(finalans,c+1);
									//if (c+1==1) {
									//	if(buffs==1) printf("%d %d\n",debuffs,buffs);
									//}
								}
								commit=true;
							}
						}
					}
					if (t==3) {
						dh=Hd;
						{
							dh-=ka;
							if (dh>0) {
								commit=true;
							}
						}
					}
					if (commit) {
						ok=true;
						break;
					}
					else {
						dh=old_dh;
						kh=old_kh;
						da=old_da;
						ka=old_ka;
					}
				}
				if (!ok) break;
			}
		}
	}
	if (finalans>=INF) {
		cout<<"Case #"<<testnum<<": "<<"IMPOSSIBLE"<<endl;
	}
	else cout<<"Case #"<<testnum<<": "<<finalans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll numtests; cin>>numtests;
	for (ll testnum=1;testnum<=numtests;testnum++) {
		solve(testnum);
	}
}

