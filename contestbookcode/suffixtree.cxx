#include <bits/stdc++.h>
#include <assert.h>
#define PB push_back
#define MP make_pair
#define UNDEF -1LL
using namespace std;
typedef long long ll;

string ALPHABET = "abcdefghijklmnopqrstuvwxyz$#";
int ALPHABETLEN = ALPHABET.length();

typedef struct Node {
    int begin;
    int end;
    int depth; // distance in characters from root to this node
    Node *parent;
    Node **children;
    Node *suffixLink;	
} Node;

Node *init(int begin, int end, int depth, Node *parent) {
	Node *x = new Node;
    x->begin = begin;
    x->end = end;
    x->parent = parent;
    x->depth = depth;
    x->children = new Node*[ALPHABETLEN];
    for (ll i = 0; i < ALPHABETLEN; i++) {
    	x->children[i] = NULL;
    }
    x->suffixLink = NULL;
    return x;
}

Node *buildSuffixTree(string s) {
	int n = s.length();
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = ALPHABET.find(s[i]);
	}
	Node *root = init(0,0,0,NULL);
	Node *node = root;
	for (int i = 0, tail = 0; i < n; i++,tail++) {
		Node *last = NULL;
		while (tail >= 0) {
			Node *ch = node->children[a[i-tail]];
			while (ch != NULL && tail >= ch->end - ch->begin) {
				tail -= ch->end - ch->begin;
				node = ch;
				ch = ch->children[a[i-tail]];
			}
			if (ch == NULL) {
				node->children[a[i]] = init(i,n,node->depth + node->end - node->begin, node);
				if (last != NULL) last->suffixLink = node;
				last = NULL;
			}
			else {
				int t = a[ch->begin + tail];
				if (t == a[i]) {
					if (last != NULL) last->suffixLink = node;
					break;
				}
				else {
					Node *splitNode = init(ch->begin, ch->begin + tail, node->depth + node->end - node->begin, node);
					splitNode->children[a[i]] = init(i, n, ch->depth + tail, splitNode);
					splitNode->children[t] = ch;
					ch->begin += tail;
					ch->depth += tail;
					ch->parent = splitNode;
					node->children[a[i - tail]] = splitNode;
					if (last != NULL) last->suffixLink = splitNode;
					last = splitNode;
				}
			}
			if (node == root) {
				--tail;
			}
			else {
				node = node->suffixLink;
			}
		}
	}
	return root;
}

void dfs(Node *x,string s) {
	vector<Node*> v;
    for (ll i = 0; i < ALPHABETLEN; i++) {
    	Node *y = x->children[i];
    	if (y != NULL) {
    		v.PB(y);
    		dfs(y,s);
    	}
    }
    for (int i = x->begin; i < x->end; i++) {
    	printf("%c", s[i]);
    }
    printf(" has children: ");
    for (auto& y: v) {
    	for (int i = y->begin; i < y->end; i++) {
    		printf("%c", s[i]);
    	}
    	printf(" ");
    }
    printf("\n");
}

int main() {
	string s = "banana$";
	Node *tree = buildSuffixTree(s);
	dfs(tree,s);
}
