//In The Name Of God
//Let Our Voices Echo
#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+9;
int n,q,a[MAX],ll[MAX*4],lz[MAX*4];
vector<int> seg[MAX*4];
void add(vector<int> &a,int x)
{
	for (auto &s:a) if ((s&(-s))&x) x^=s;
	if (!x) return ;
	for (auto &s:a) if ((x&(-x))&s) s^=x;
	a.push_back(x);
}
vector<int> merge(vector<int> a,vector<int> b)
{
	if (a.size()<b.size()) a.swap(b);
	for (auto i:b) add(a,i);
	return a;
}
void shift(int id)
{
	lz[id*2+1]^=lz[id];
	lz[id*2+2]^=lz[id];
	ll[id*2+1]^=lz[id];
	ll[id*2+2]^=lz[id];
	lz[id]=0;
}
void upd(int l,int r,int k,int s=0,int e=n,int id=0)
{
	if (!k || r<=s || e<=l) return ;		
	if (l<=s && e<=r) 
	{
		ll[id]^=k;
		lz[id]^=k;
		return ;
	}
	int mid=s+e>>1;
	shift(id);
	upd(l,r,k,s,mid,id*2+1),upd(l,r,k,mid,e,id*2+2);
	seg[id]=merge(seg[id*2+1],seg[id*2+2]);	
	add(seg[id],ll[id*2+1]^ll[id*2+2]);
	ll[id]=ll[id*2+1];
}
vector<int> get(int l,int r,int s=0,int e=n,int id=0)
{
	vector<int> ret;
	if (r<=s || e<=l) return ret;
	if (l<=s && e<=r) 
	{
		ret=seg[id];
		add(ret,ll[id]);
		return ret;
	}
	int mid=s+e>>1;
	shift(id);
	return merge(get(l,r,s,mid,id*2+1),get(l,r,mid,e,id*2+2));
}
int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=0;i<n;i++) cin>>a[i],upd(i,i+1,a[i]);
	while (q--)
	{
		int t,l,r,k;
		cin>>t>>l>>r,l--;
		if (t==1) cin>>k,upd(l,r,k);
		else 
		{
			cout<<(1<<(get(l,r).size()))<<'\n';
		}
	}
	return 0;
}
