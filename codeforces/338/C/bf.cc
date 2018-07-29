#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int primeDivisors[8];
int primeCount;
int rec(int cur, vector<long long> &a, vector<long long> &tree, int rootChildrenNum, int rootChildrenSum)
{
	if (cur == a.size())
		return rootChildrenSum + (rootChildrenNum > 1) + (int)a.size() - primeCount;

	int best = (int)1e9;
	for(int i = 0; i < tree.size(); i++)
		if (tree[i] % a[cur] == 0)
		{
			tree[i] /= a[cur];
			tree.push_back(a[cur]);
			best = min(best, rec(cur + 1, a, tree, rootChildrenNum + (i == 0), 
				rootChildrenSum + (i == 0 ? primeDivisors[cur] : 0)));
			tree[i] *= a[cur];
			tree.pop_back();
		}
	return best;
}

int main()
{
	int n, i, j;
	cin >> n;
	vector<long long> a(n);
	for(i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end(), greater<long long>());

	for(i = 0; i < n; i++)
	{
		long long x = a[i];
		for(j = 2; 1LL * j * j <= x; j++)
			while(x % j == 0)
			{
				++primeDivisors[i];
				x /= j;
			}
		if (x > 1)
			++primeDivisors[i];
		if (primeDivisors[i] == 1)
			primeCount++;
	}

	vector<long long> tree;
	tree.push_back(0);
	cout << rec(0, a, tree, 0, 0) << endl;

	return 0;
}