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

// Utility function to do modular exponentiation.
// It returns (x^y) % p
ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
                // equal to p
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
 
// This function is called for all k trials. It returns
// false if n is composite and returns false if n is
// probably prime.
// d is an odd number such that  d*2<sup>r</sup> = n-1
// for some r >= 1
bool miillerTest(ll d, ll n)
{
    // Pick a random number in [2..n-2]
    // Corner cases make sure that n > 4
    ll a = 2 + rand() % (n - 4);
 
    // Compute a^d % n
    ll x = power(a, d, n);
 
    if (x == 1  || x == n-1)
       return true;
 
    // Keep squaring x while one of the following doesn't
    // happen
    // (i)   d does not reach n-1
    // (ii)  (x^2) % n is not 1
    // (iii) (x^2) % n is not n-1
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
 
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
 
    // Return composite
    return false;
}
 
// It returns false if n is composite and returns true if n
// is probably prime.  k is an input parameter that determines
// accuracy level. Higher value of k indicates more accuracy.
bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
 
    // Find r such that n = 2^d * r + 1 for some r >= 1
    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;
 
    // Iterate given nber of 'k' times
    for (ll i = 0; i < 7; i++)
         if (miillerTest(d, n) == false)
              return false;
 
    return true;
}



const ll MAXN=pow(1e10,1.0/3.0)+4;
const ll MAXP=MAXN;
bool sieve_array[MAXP+1];
ll sp[MAXP+1];
vector<ll> gpv;
void sieve() {
	for (ll i = 0; i <= MAXP; i++) {
		sieve_array[i] = true;
		sp[i]=INF;
	}
	sieve_array[0] = false; sieve_array[1] = false;
	ll lim = sqrt(MAXP)+1;
	for (ll i = 2; i <= lim; i++) {
		if(sieve_array[i]) {
			for (ll j = i*i; j <= MAXP; j+=i) {
				sieve_array[j] = false;
				chkmin(sp[j],i);
			}
		}
	}
	for (ll i = 2; i <= MAXP; i++) {
		if(sieve_array[i]) {
			gpv.PB(i);
			chkmin(sp[i],i);
		}
	}
}
map<ll,ll> factorize(ll x) {
	// WARNING: This factorization is WRONG!!!!!!!!!!
	// It only works with this problem since we ignore all primes > x^(1/3)
	map<ll,ll> h;
	for (auto &p:gpv) {
		ll k=0;
		while(x%p==0) {
			x/=p;k++;
		}
		if (k>0) h[p]=k;
	}
	if (x>1) {
		ll r=round(sqrt((long double)x));
		if (r*r==x) {
			h[r]=2;
		}
		else h[x]=1;
	}
	/*printf("Factorize %lld. Got ",x);
	for (auto &w:h) printf("(%lld: %lld), ",w.first,w.second);
	printf("\n");*/
	return h;
}
const ll xlim=1e10+1;
int main() {
	sieve();
	vector<ll> cpv;
	for (auto &w:gpv) {
		ll cw=w*w*w;
		if (cw>xlim) break;
		cpv.PB(cw);
	}
  ll n; scanf("%lld",&n);
	map<ll,ll> h;
	for (ll i=0;i<n;i++) {
		ll x; scanf("%lld",&x);
		for (auto &w:cpv) {
			if (x<w) break;
			while (x%w==0) x/=w;
		}
		h[x]++;
	}
	ll ans=0;
	if (h[1]>0) {
		ans++;
		h.erase(1);
	}
	for (auto &w:h) {
		map<ll,ll> factors=factorize(w.first);
		ll key=1;
		for (auto &w:factors) {
			ll ex=3-w.second;
			for (ll i=0;i<ex;i++) key*=w.first;
		}
		auto it=h.find(key);
		ll other;
		if (it==h.end()) {
			other=0;
		}
		else {
			other=it->second;
			h.erase(it);
		}
		ans+=max(w.second,other);
	}
	printf("%lld\n",ans);
}