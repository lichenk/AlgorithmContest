#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll NEUTRAL_VALUE = -(1<<30);
const ll NEUTRAL_DELTA=0;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
struct node {
	int sum;
	int value;
	int delta;
	node *left,*right;
	node(int sum, int value, int delta, node *left, node *right):
		sum(sum),value(value),delta(delta),left(left),right(right) {}
};
node *makenode(node *left, node *right, int value, int delta, int size) {
	int sum=0;
	if (left!=NULL) sum+=left->sum;
	if (right!=NULL) sum+=right->sum;
	if (value!=NEUTRAL_VALUE) sum=size*value;
	sum+=delta*size;
	//printf("Making: %d %d %d: %d\n",value,delta,size,sum);
	return new node(sum,value,delta,left,right);
}
node *build(int left, int right) {
	if (left==right) return new node(0,NEUTRAL_VALUE,NEUTRAL_DELTA,NULL,NULL);
	return makenode(build(left, (left + right) / 2), build((left + right) / 2 + 1, right),NEUTRAL_VALUE,NEUTRAL_DELTA,right-left+1);
}
node *push(node *root, int left, int right) {
	int size=right-left+1;
	node *newleft=NULL; node* newright=NULL;
	//printf("Pushing %d %d with original sum %d\n",left,right,root->sum);
	if (size==1) return makenode(NULL,NULL,root->value,root->delta,size);
	int mid=(left+right)/2;
	if (root->left!=NULL) {
		node *orig = root->left;
		newleft = makenode(
			orig->left,
			orig->right,
			(root->value!=NEUTRAL_VALUE)?root->value:orig->value,
			(root->value!=NEUTRAL_VALUE)?root->delta:root->delta+orig->delta,
			mid-left+1
			);
	}
	if (root->right!=NULL) {
		node *orig=root->right;
		newright = makenode(
			orig->left,
			orig->right,
			(root->value!=NEUTRAL_VALUE)?root->value:orig->value,
			(root->value!=NEUTRAL_VALUE)?root->delta:root->delta+orig->delta,
			right-(mid+1)+1
			);
	}
	return makenode(newleft,newright,NEUTRAL_VALUE,NEUTRAL_DELTA,size);
}
int sum(int a, int b, node *root, int left, int right) {
	root=push(root, left,right);
	if (a>right||b<left) return 0;
	if (a<=left&&right<=b) {
		//printf("sum: %d %d %d %d: %d\n",a,b,left,right,root->sum);
		return root->sum;
	}
	return sum(a,b,root->left,left,(left+right)/2) + sum(a,b,root->right,(left+right)/2+1,right);
}
node *sset(int a, int b, int value, node *root, int left, int right) {
	//printf("sset call %d %d %d %d %d\n",a,b,value,left,right);
	if (a>right||b<left) return root;
	int size=right-left+1;
	root = push(root, left,right);
	if (a<=left&&right<=b) {
		//printf("sseting: %d %d %d\n",left,right,value);
		return makenode(root->left,root->right,value,NEUTRAL_DELTA,size);
	}
	int mid=(left+right)/2;
	node *newleft=sset(a,b,value,root->left,left,mid);
	node *newright=sset(a,b,value,root->right,mid+1,right);
	return makenode(newleft,newright,NEUTRAL_VALUE,NEUTRAL_DELTA,size);
}
node *sadd(int a, int b, int delta, node *root, int left, int right) {
	//printf("sadd call %d %d %d %d %d\n",a,b,delta,left,right);
	if (a>right||b<left) return root;
	int size=right-left+1;
	root = push(root, left,right);
	if (a<=left&&right<=b) {
		//printf("sadding: %d %d %d\n",left,right,delta);
		return makenode(root->left,root->right,root->value,root->delta+delta,size);
	}
	int mid=(left+right)/2;
	node *newleft=sadd(a,b,delta,root->left,left,mid);
	node *newright=sadd(a,b,delta,root->right,mid+1,right);
	return makenode(newleft,newright,NEUTRAL_VALUE,NEUTRAL_DELTA,size);
}

int main() {
	//ios_base::sync_with_stdio(false);
	ll n,m; cin>>n>>m;
	node *root[100000+1];
	root[0]=build(0,n-1);
	for (ll q=1;q<=m;q++) {
		ll t; cin>>t;
		if (t==1) {
			ll a,b,v; cin>>a>>b>>v;
			root[q]=sset(a,b,v,root[q-1],0,n-1);
			//printf("New sum:%d\n",root[q]->sum);
		}
		else if (t==2) {
			ll a,b,past;cin>>a>>b>>past;
			root[q]=root[q-1];
			printf("%d\n",sum(a,b,root[past],0,n-1));
		}
		else if (t==3) {
			ll a,b,v; cin>>a>>b>>v;
			root[q]=sadd(a,b,v,root[q-1],0,n-1);
			//printf("New sum:%d\n",root[q]->sum);
		}
	}
}