#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
// C implementation of search and insert operations
// on Trie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
 
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
ll gans;
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
    gans++;
 
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
 
    if (pNode)
    {
        int i;
 
        pNode->isLeaf = false;
 
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
 
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
 
    struct TrieNode *pCrawl = root;
 
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isLeaf = true;
}
vector<pair<ll,char> > g[5555];
vector<string> glob;
void dfs(ll x, string s) {
	//cout<<x<<":"<<s<<endl;
	bool has=false;
	for (auto &yy:g[x]) {
		ll y=yy.first;
		char c=yy.second;
		dfs(y,s+c);
		has=true;
	}
	if (!has) glob.PB(s);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d\n",&n);
	for (ll i=0;i<n-1;i++) {
		ll s,t; char x; scanf("%d %d %c\n",&s,&t,&x);
		g[s].PB(MP(t,x));
	}
	dfs(1,"");
	pll final=MP(INF,INF);
	for (ll p=1;;p++) {
		//printf("p:%d\n",p);
  	struct TrieNode *root = getNode();
  	gans=1;
  	bool has=false;
  	for (auto &w:glob) {
  		ll wlen=w.length();
  		string s;
  		if (wlen>=p) {
  			has=true;
  			s=w.substr(0,p-1)+w.substr(p,wlen-p);
  			//printf("orig:%s. %s+%s=%s\n",w.c_str(),w.substr(0,p-1).c_str(),w.substr(p,wlen-p).c_str(),s.c_str());
  		}
  		else s=w;
  	  insert(root, s.c_str());
  	}
  	if (!has) break;
  	//printf("p:%d gans:%d\n",p,gans);
  	chkmin(final,MP(gans,p));
  }
  printf("%d\n%d\n",final.first,final.second);
}

