#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000009LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
// Max number of states in the matching machine.
// Should be equal to the sum of the length of all keywords.
const int MAXS = 304;
 
// Maximum number of characters in input alphabet
const int MAXC = 26;
 
// OUTPUT FUNCTION IS IMPLEMENTED USING out[]
// Bit i in this mask is one if the word with index i
// appears when the machine enters this state.
int out[MAXS];
 
// FAILURE FUNCTION IS IMPLEMENTED USING f[]
int f[MAXS];
 
// GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING g[][]
int g[MAXS][MAXC];
 
// Builds the string matching machine.
// arr -   array of words. The index of each keyword is important:
//         "out[state] & (1 << i)" is > 0 if we just found word[i]
//         in the text.
// Returns the number of states that the built machine has.
// States are numbered 0 up to the return value - 1, inclusive.
int buildMatchingMachine(string arr[], int k)
{
    // Initialize all values in output function as 0.
    memset(out, 0, sizeof out);
 
    // Initialize all values in goto function as -1.
    memset(g, -1, sizeof g);
 
    // Initially, we just have the 0 state
    int states = 1;
 
    // Construct values for goto function, i.e., fill g[][]
    // This is same as building a Trie for arr[]
    for (int i = 0; i < k; ++i)
    {
        const string &word = arr[i];
        int currentState = 0;
 
        // Insert all characters of current word in arr[]
        for (int j = 0; j < word.size(); ++j)
        {
            int ch = word[j] - 'a';
 
            // Allocate a new node (create a new state) if a
            // node for ch doesn't exist.
            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;
 
            currentState = g[currentState][ch];
        }
 
        // Add current word in output function
        out[currentState] |= (1 << i);
    }
 
    // For all characters which don't have an edge from
    // root (or state 0) in Trie, add a goto edge to state
    // 0 itself
    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;
 
    // Now, let's build the failure function
 
    // Initialize values in fail function
    memset(f, -1, sizeof f);
 
    // Failure function is computed in breadth first order
    // using a queue
    queue<int> q;
 
     // Iterate over every possible input
    for (int ch = 0; ch < MAXC; ++ch)
    {
        // All nodes of depth 1 have failure function value
        // as 0. For example, in above diagram we move to 0
        // from states 1 and 3.
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }
 
    // Now queue has states 1 and 3
    while (q.size())
    {
        // Remove the front state from queue
        int state = q.front();
        q.pop();
 
        // For the removed state, find failure function for
        // all those characters for which goto function is
        // not defined.
        for (int ch = 0; ch < MAXC; ++ch)
        {
            // If goto function is defined for character 'ch'
            // and 'state'
            if (g[state][ch] != -1)
            {
                // Find failure state of removed state
                int failure = f[state];
 
                // Find the deepest node labeled by proper
                // suffix of string from root to current
                // state.
                while (g[failure][ch] == -1)
                      failure = f[failure];
 
                failure = g[failure][ch];
                f[g[state][ch]] = failure;
 
                // Merge output values
                out[g[state][ch]] |= out[failure];
 
                // Insert the next level node (of Trie) in Queue
                q.push(g[state][ch]);
            }
        }
    }
 
    return states;
}
 
// Returns the next state the machine will transition to using goto
// and failure functions.
// currentState - The current state of the machine. Must be between
//                0 and the number of states - 1, inclusive.
// nextInput - The next character that enters into the machine.
int findNextState(int currentState, char nextInput)
{
    int answer = currentState;
    int ch = nextInput - 'a';
 
    // If goto is not defined, use failure function
    while (g[answer][ch] == -1)
        answer = f[answer];
 
    return g[answer][ch];
}
int dp[51][MAXS][1<<6];
class RequiredSubstrings {
	public:
	int solve(vector <string> words, int C, int L) {
		string arr[6];
		ll k=words.size();
		for (ll i=0;i<k;i++) arr[i]=words[i];
    // Preprocess patterns.
    // Build machine with goto, failure and output functions
    buildMatchingMachine(arr, k);
  	for (ll x=0;x<=L;x++) for (ll s=0;s<MAXS;s++) for (ll z=0;z<(1ll<<k);z++) dp[x][s][z]=0;
  	dp[0][0][0]=1;
  	for (ll x=0;x<L;x++) {
  		for (ll s=0;s<MAXS;s++) {
  			for (ll z=0;z<(1ll<<k);z++) {
  				ll v=dp[x][s][z];
  				if (v==0) continue;
  				for (ll cc=0;cc<26;cc++) {
  					char c='a'+cc;
  					ll ns=findNextState(s,c);
  					ll nz=z|out[ns];
  					dp[x+1][ns][nz]=(dp[x+1][ns][nz]+(long long)v)%MOD;
  				}
  			}
  		}
  	}
  	ll ans=0;
  	for (ll z=0;z<(1ll<<k);z++) {
  		if (__builtin_popcountll(z)==C) {
  			for (ll s=0;s<MAXS;s++) ans=(ans+dp[L][s][z])%MOD;
  		}
  	}
  	return ans;
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing RequiredSubstrings (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1475039062;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RequiredSubstrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"a","aa","aaa","aaaa"};
				int C = 2;
				int L = 3;
				_expected = 50;
				_received = _obj.solve(vector <string>(words, words+sizeof(words)/sizeof(string)), C, L); break;
			}
			case 1:
			{
				string words[] = {"abcdefgh"};
				int C = 0;
				int L = 7;
				_expected = 31810104;
				_received = _obj.solve(vector <string>(words, words+sizeof(words)/sizeof(string)), C, L); break;
			}
			case 2:
			{
				string words[] = {"abcdefgh"};
				int C = 1;
				int L = 7;
				_expected = 0;
				_received = _obj.solve(vector <string>(words, words+sizeof(words)/sizeof(string)), C, L); break;
			}
			case 3:
			{
				string words[] = {"a","b","c","d"};
				int C = 3;
				int L = 3;
				_expected = 24;
				_received = _obj.solve(vector <string>(words, words+sizeof(words)/sizeof(string)), C, L); break;
			}
			case 4:
			{
				string words[] = {"ab","bc","xy","yz"};
				int C = 2;
				int L = 3;
				_expected = 2;
				_received = _obj.solve(vector <string>(words, words+sizeof(words)/sizeof(string)), C, L); break;
			}
			/*case 5:
			{
				string words[] = ;
				int C = ;
				int L = ;
				_expected = ;
				_received = _obj.solve(vector <string>(words, words+sizeof(words)/sizeof(string)), C, L); break;
			}*/
			/*case 6:
			{
				string words[] = ;
				int C = ;
				int L = ;
				_expected = ;
				_received = _obj.solve(vector <string>(words, words+sizeof(words)/sizeof(string)), C, L); break;
			}*/
			/*case 7:
			{
				string words[] = ;
				int C = ;
				int L = ;
				_expected = ;
				_received = _obj.solve(vector <string>(words, words+sizeof(words)/sizeof(string)), C, L); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
