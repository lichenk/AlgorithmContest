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
const int mn=2001;
char s[602];
int a[602];
void decimalStringToBigRadixArray(char *s, int *a) {
  // Radix is 1e8
  int len=strlen(s);
  int numdig=0;
  for (int d=0;d<len;) {
    int take=min(8,len-d);
    int sum=0;
    for (int j=0;j<take;j++) {
      sum+=(s[len-1-d]-'0');
      d++;
    }
  }
}

void bigRadixArrayToBinaryArray(int *radix, int *binary) {
  int base=100000000;
  for 
}

int main()
{
	int n; scanf("%d\n",&n);
  for (int i=0;i<n;i++) {
    scanf("%s\n",&s);
  }
	
}
