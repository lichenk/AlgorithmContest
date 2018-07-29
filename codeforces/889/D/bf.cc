#include<bits/stdc++.h>
using namespace std;
const int N=2010;
int n,id[N],x;
struct point{
	double x,y;
	point operator + (point a){return (point){x+a.x,y+a.y};}
	point operator - (point a){return (point){x-a.x,y-a.y};}
	point operator / (double a){return (point){x/a,y/a};}
	bool operator == (point a){
		return abs(x-a.x)<1e-9&&abs(y-a.y)<1e-9;
	}
	double operator * (point a){return x*a.x+y*a.y;}
}p[N],root,mid,vec;
pair<double,int> P[N];
bool check(int pos){
	mid=(p[x]+p[pos])/2;
	vec=root-mid;
	vec=(point){vec.y,-vec.x};
	for (int i=1;i<=n;i++) P[i]=make_pair(vec*p[i],i);
	sort(P+1,P+n+1);
	for (int i=1;i<=n;i++) id[P[i].second]=i;
	if (id[x]+id[pos]!=n+1) return 0;
	double flag=P[1].first+P[n].first;
	for (int i=1;i<=n;i++)
	if (abs(P[i].first+P[n-i+1].first-flag)>1e-9) return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lf%lf",&p[i].x,&p[i].y);
		root=root+p[i];
	}
	root=root/n;
	bool inf=1;
	for (int i=1;i<=n;i++){
		bool is=0;
		for (int j=1;j<=n;j++)
		if (p[i]+p[j]==root+root) is=1;
		if (!is) inf=0,x=i;
	}
	if (inf) return puts("-1"),0;
	int ans=0;
	for (int i=1;i<=n;i++)
		if (check(i)) ans++;
	cout<<ans<<endl; 
	return 0;
}