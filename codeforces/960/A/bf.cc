#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
char s[50100];
int n,cnt[10];
int main() {
  scanf("%s",s);
  n=strlen(s);
  rep(i,0,n-1) {
    if (s[i]>s[i+1]) {
      puts("NO");
      return 0;
    }
  }
  rep(i,0,n) cnt[s[i]-'a']++;
  if (cnt[0]>=1&&cnt[1]>=1&&(cnt[2]==cnt[0]||cnt[2]==cnt[1])) {
    puts("YES");
  } else puts("NO");
}