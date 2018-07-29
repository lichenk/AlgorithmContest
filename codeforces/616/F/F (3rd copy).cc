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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"


/* Suffix array bookcode */
// lexicographic order for pairs
inline bool leq(int a1, int a2, int b1, int b2) {
    return(a1 < b1 || a1 == b1 && a2 <= b2);
}
 
// and triples
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
    return(a1 < b1 || a1 == b1 && leq(a2,a3, b2,b3));
} // and triples
 
// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
static void radixPass(int* a, int* b, int* r, int n, int K) {// count occurrences
    int* c = new int[K + 1]; // counter array
    for (int i = 0; i <= K; i++) c[i] = 0; // reset counters
    for (int i = 0; i < n; i++) c[r[a[i]]]++; // count occurrences
    for (int i = 0, sum = 0; i <= K; i++) // exclusive prefix sums
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (int i = 0;  i < n; i++) b[c[r[a[i]]]++] = a[i]; // sort
    delete [] c;
}
 
// find the suffix array SA of s[0..n-1] in {1..K}ˆn
// require s[n]=s[n+1]=s[n+2]=0, n>=2
void suffixArray(int* s, int* SA, int n, int K) {
    if (n == 1) {
        SA[0] = 0;
        return;
    }
    int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2;
    int* s12 = new int[n02+3]; s12[n02] = s12[n02+1] = s12[n02+2] = 0;
    int* SA12 = new int[n02+3]; SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
    int* s0 = new int[n0];
    int* SA0 = new int[n0];
    // generate positions of mod 1 and mod 2 suffixes
    // the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
    for (int i=0, j=0; i < n + (n0-n1); i++)
        if (i%3 != 0) s12[j++] = i;
    // lsb radix sort the mod 1 and mod 2 triples
    radixPass(s12 , SA12, s+2, n02, K);
    radixPass(SA12, s12 , s+1, n02, K);
    radixPass(s12 , SA12, s  , n02, K);
    // find lexicographic names of triples
    int name = 0, c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n02; i++) {
        if (s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
            name++;
            c0 = s[SA12[i]];
            c1 = s[SA12[i]+1];
            c2 = s[SA12[i]+2];
        }
        if (SA12[i]%3 == 1) s12[SA12[i]/3] = name; // left half
        else s12[SA12[i]/3 + n0] = name; // right half
    }
    // recurse if names are not yet unique
    if (name < n02) {
        suffixArray(s12, SA12, n02, name);
        // store unique names in s12 using the suffix array
        for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
    } else // generate the suffix array of s12 directly
        for (int i = 0;  i < n02; i++) SA12[s12[i] - 1] = i;
    // stably sort the mod 0 suffixes from SA12 by their first character
    for (int i = 0, j = 0; i < n02; i++)
        if (SA12[i] < n0) s0[j++] = 3*SA12[i];
    radixPass(s0, SA0, s, n0, K);
    // merge sorted SA0 suffixes and sorted SA12 suffixes
    for (int p = 0, t = n0-n1, k = 0; k < n; k++) {
        #define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)
        int i = GetI(); // pos of current offset 12 suffix
        int j = SA0[p]; // pos of current offset 0 suffix
        if (SA12[t] < n0 ? // different compares for mod 1 and mod 2 suffixes
            leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) :
            leq(s[i],s[i+1],s12[SA12[t]-n0+1], s[j],s[j+1],s12[j/3+n0]))
        {// suffix from SA12 is smaller
            SA[k] = i; t++;
            if (t == n02) // done --- only SA0 suffixes left
            for (k++; p < n0; p++, k++) SA[k] = SA0[p];
        } else {// suffix from SA0 is smaller
            SA[k] = j; p++;
            if (p == n0) // done --- only SA12 suffixes left
            for (k++; t < n02; t++, k++) SA[k] = GetI();
        }
    }
    delete [] s12; delete [] SA12; delete [] SA0; delete [] s0;
}

void buildlcp(int *lcp, int *s, int *SA, int *SAshifted, int *SAshiftedinverse, int n) {
    SAshifted[0] = n;
    for (ll i = 1; i <= n; i++) {
        SAshifted[i] = SA[i-1];
    }
    for (ll i = 0; i <= n; i++) {
        SAshiftedinverse[SAshifted[i]] = i;
    }
    // Output goes into LCP[1...n]. So LCP table must be length n+1
    int l = 0;
    for (int i=0; i<n; i++) {
        int k = SAshiftedinverse[i];
        int j = SAshifted[k-1];
        while (s[i+l] == s[j+l]) l++;
        lcp[k] = l;
        if (l > 0) l--;
    }
}


const ll mn=6e5+4;
vector<ll> vlcp[mn];
ll vc[mn];
const ll ms=mn;
string t[ms];
ll c[ms];
ll invSA[mn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll sn; cin>>sn;
	for (ll i=0;i<sn;i++) cin>>t[i];
	for (ll i=0;i<sn;i++) cin>>c[i];
	string str;
	ll slen=0;
	for (ll i=0;i<sn;i++) slen+=t[i].length()+1;
	str.resize(slen);
	slen=0;
	for (ll i=0;i<sn;i++) {
		for (ll j=0;j<t[i].length();j++) {
			str[slen]=t[i][j];
			slen++;
		}
		str[slen]='a'+26;
		slen++;
	}
  int n = str.length();
  int *s = new int[n+3];
  int *SA = new int[n+3];
  //int *pattern = new int[n+3];
  for (ll i = 0; i < n; i++) {
      s[i] = str[i] - 'a' + 1;
      //pattern[i] = pat[i]-'a'+1;
  }
  // Require s[n]=s[n+1]=s[n+2]=0;
  for (ll i=n;i<=n+2;i++) s[i] = 0;
  suffixArray(s, SA, n, 27);
  int *sa = new int[n+1];
  int *invSA = new int[n+1];
  int *lcp = new int[n+2];
  buildlcp(lcp, s, SA, sa, invSA, n);
  for (ll i=0;i<n;i++) lcp[i]=lcp[i+1];

	/*for (int i = 0; i < n; i++) {
		cout << str.substr(sa[i + 1]);
		if (i < n - 1)
			cout << " " << lcp[i + 1];
		cout << endl;
	}
	*/
	memset(vc,0,sizeof vc);
	slen=0;
	for (ll i=0;i<sn;i++) {
		ll tlen=t[i].length();
		for (ll j=0;j<tlen;j++) {
			ll sai=invSA[slen];
			vc[sai]+=c[i];
			int rem=tlen-j;
			chkmin(lcp[sai],rem);
			chkmin(lcp[sai+1],rem);
			////printf("Add to idx:%lld cost %lld\n",sai,c[i]);
			slen++;
		}
		{
			ll sai=invSA[slen];
			chkmin(lcp[sai],0);
			chkmin(lcp[sai+1],0);
		}
		slen++;
	}
	for (ll i=1;i<n;i++) {
		vc[i]+=vc[i-1];
	}
	set<ll> st; // Contains last point in segment
	for (ll i=1;i<=n;i++) {
		st.insert(i);
	}
	for (ll i=1;i<n;i++) {
		vlcp[lcp[i]].PB(i);
	}
	ll best=0;
	for (ll k=mn-1;k>=0;k--) {
		vector<ll> cand;
		for (auto &w:vlcp[k]) {
			auto it=st.find(w);
			auto jt=it; ++jt;
			cand.PB(*jt);
			st.erase(it);
		}
		for (auto &w:cand) {
			auto it=st.find(w);
			if (it==st.end()) continue;
			ll prevpt=1;
			if (it!=st.begin()) {
				--it;
				prevpt=1+(*it);
			}
			ll cost=vc[w]-vc[prevpt-1];
			//printf("k:%lld prevpt:%lld w:%lld cost:%lld\n",k,prevpt,w,cost);
			ll cand=k*cost;
			chkmax(best,cand);
		}
	}
	for (ll i=0;i<sn;i++) {
		ll cand=t[i].length()*c[i];
		chkmax(best,cand);
	}
	printf("%lld\n",best);
}