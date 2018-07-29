#include <bits/stdc++.h>
#include <assert.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>
extern char **environ;
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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
typedef vector<int> vi;
struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int add_var() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void add_clause(int aind, bool aval, int bind, bool bval) {
		int a = 2*aind + aval, b = 2*bind + bval;
		gr[a^1].push_back(b);
		gr[b^1].push_back(a);
	}

	void add_impl(int aind, bool aval, int bind, bool bval) {
		int a = 2*aind + aval, b = 2*bind + bval;
		gr[a].push_back(b);
		gr[b^1].push_back(a^1);
	}

	void set_value(int index, bool value) { // (optional)
		add_clause(index, value, index, value);
	}

	void at_most_one(const vi& li, bool val=1) { // (optional)
		if ((int)li.size() <= 1) return;
		int cur = li[0];
		rep(i,2,(int)li.size()) {
			int next = add_var();
			add_clause(cur, !val, li[i], !val);
			add_clause(cur, !val, next, val);
			add_clause(li[i], !val, next, val);
			cur = next;
		}
		add_clause(cur, !val, li[1], !val);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		trav(e, gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		++time;
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = time;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		// Answer is in values vector
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};


const ll mn=202;
const ll maxid=mn*mn;
const ll MAXN=maxid;

string s[mn];
bool sn[mn][mn][4];
bool beamfail[maxid][2];
ll rlim,clim;
ll e2b[maxid][2];
ll e2bv[maxid][2];
ll dc[4]={1,0,-1,0};
ll dr[4]={0,1,0,-1};
ll getid(ll r, ll c) {
	ll ans=r*100+c;
	assert(ans<maxid);
	return ans;
}
void dfs(ll r, ll c, ll dir, ll id, ll isvert) {
	if (sn[r][c][dir]) return;
	sn[r][c][dir]=true;
	char a=s[r][c];
	//printf("id:%lld r:%lld c:%lld a:%c isvert:%lld\n",id,r,c,a,isvert);
	if (a=='#'||r<1||r>rlim||c<1||c>clim) return;
	else if (a=='-'||a=='|') {
		//printf("BF%lld %lld %lld %lld %lld\n",r,c,dir,id,isvert);
		beamfail[id][isvert]=true;
		//add_impl(id,isvert,id,isvert^1);
		//dfs(r+dr[dir],c+dc[dir],dir,id,isvert);
	}
	else if (a=='\\') {
		dir^=1;
		dfs(r+dr[dir],c+dc[dir],dir,id,isvert);
	}
	else if (a=='/') {
		dir^=3;
		dfs(r+dr[dir],c+dc[dir],dir,id,isvert);
	}
	else if (a=='.') {
		e2b[getid(r,c)][dir&1]=id;
		e2bv[getid(r,c)][dir&1]=isvert;
		//printf("r:%lld c:%lld dir:%lld id:%lld isvert:%lld\n",r,c,dir,id,isvert);
		dfs(r+dr[dir],c+dc[dir],dir,id,isvert);
	}
	else {
		//printf("Un:(%lld %lld) (%lld %lld) :%c\n",r,c,rlim,clim,a);
		assert(0);
	}
}
int mainsolve(string testcasein, string testcaseout, int testnum)
{
	// Solve a test case from the file named testcasein, and writes answer to the file named testcaseout
	std::ifstream ifs(testcasein.c_str(),std::ifstream::in);
	FILE *fout=fopen(testcaseout.c_str(),"wb"); assert(fout!=NULL);
		ifs>>rlim>>clim;
		for (ll r=1;r<=rlim;r++) {
			string tmp; ifs>>tmp;
			s[r]="#"+tmp+"#";
		}
		memset(e2b,-1,sizeof e2b);
		memset(e2bv,-1,sizeof e2bv);
		memset(beamfail,0,sizeof beamfail);
		//for (ll j=0;j<2;j++) beamfail[j].reset();
		vector<ll> bids,cids;
		for (ll r=1;r<=rlim;r++) {
			for (ll c=1;c<=clim;c++) {
				if (s[r][c]=='.') {
					cids.PB(getid(r,c));
				}
				if (s[r][c]=='-'||s[r][c]=='|') {
					ll id=getid(r,c);
					bids.PB(id);
					for (ll k=0;k<4;k+=2) {
						//for (ll i=0;i<mn;i++) sn[i].reset();
						memset(sn,0,sizeof sn);
						dfs(r+dr[k],c+dc[k],k,id,k&1);
					}
					for (ll k=1;k<4;k+=2) {
						//for (ll i=0;i<mn;i++) sn[i].reset();
						memset(sn,0,sizeof sn);
						dfs(r+dr[k],c+dc[k],k,id,k&1);
					}
				}
			}
		}
		TwoSat ts(maxid);
		for (ll isvert=0;isvert<2;isvert++) {
			for (auto &id:bids) {
				if (beamfail[id][isvert]) {
					//printf("bf id:%lld isvert:%lld\n",id,isvert);
					ts.add_impl(id,isvert,id,isvert^1);
				}
			}
		}
		for (auto &cid:cids) {
			for (ll cvert=0;cvert<2;cvert++) {
				ll bid=e2b[cid][cvert];
				ll bvert=e2bv[cid][cvert];
				if (bid==-1) {
					ts.add_impl(cid,cvert,cid,cvert^1);
					//printf("cid:%lld cvert:%lld\n",cid,cvert);
				}
				else {
					ts.add_impl(cid,cvert,bid,bvert);
					//printf("cid:%lld cvert:%lld bid:%lld bvert:%lld\n",cid,cvert,bid,bvert);
				}
			}
		}
		bool final=ts.solve();
		//printf("res:%d\n",res[102]);
		if (final) {
			fprintf(fout, "Case #%d: POSSIBLE\n",testnum);
			for (ll r=1;r<=rlim;r++) {
				for (ll c=1;c<=clim;c++) {
					if (s[r][c]=='-'||s[r][c]=='|') {
						bool bvert=ts.values[getid(r,c)];
						if (bvert) s[r][c]='|';
						else s[r][c]='-';
					}
				}
			}
			for (ll r=1;r<=rlim;r++) {
				string tmp=s[r].substr(1,clim);
				fprintf(fout, "%s\n",tmp.c_str());
			}
		}
		else {
			fprintf(fout, "Case #%d: IMPOSSIBLE\n",testnum);
		}
}


const int MAX_NUM_PROCESSES = 4;

string getinputfilename(int testnum) {
	ostringstream testcasein; testcasein<<"testcasein"<<testnum;
	return testcasein.str();
}
string getoutputfilename(int testnum) {
	ostringstream testcaseout; testcaseout<<"testcaseout"<<testnum;
	return testcaseout.str();
}

void wait_for_running_children_to_be_under_limit(set<pid_t> &running_child_pids, int limit) {
	while(running_child_pids.size() > limit) {
		for (auto &ChildPID:running_child_pids) {
			int status;
			pid_t result = waitpid(ChildPID, &status, WNOHANG);
			if (result == 0) {
			  // Child still alive
			} else if (result == -1) {
			  // Error 
			  cerr<<"waitpid error"<<endl; assert(0);
			} else {
			  // Child exited
			  if (status!=0) {
			  	cerr<<"Child returned nonzero status."<<endl; assert(0);
			  }
			  running_child_pids.erase(ChildPID);
			}
		}
	}	
}

int main(int argc, char* argv[])
{
	/*
	If no arguments are passed, then please pass full data set into stdin
	If one argument is passed, that argument should be the test case number. It will read from getinputfilename(testnum)
	and write to getoutputfilename(testnum). Usually, you first run this with no arguments to populate all the input files,
	then you pass in the test case number as the argument to debug this particular test case.
	*/
	ios_base::sync_with_stdio(false); cin.tie(0);
	set<pid_t> running_child_pids;
	if (argc == 1)
	{
		int number_of_test_cases; cin>>number_of_test_cases;
		for (int testnum=1;testnum<=number_of_test_cases;testnum++) {
			/* Custom code starts here! Read one test case, and output to a file named getinputfilename(testnum)*/
			int rlim,clim;
			cin>>rlim>>clim;
			vector<string> tmp(rlim);
			for (ll r=0;r<rlim;r++) {
				cin>>tmp[r];
			}
			
			FILE *fp = fopen(getinputfilename(testnum).c_str(),"wb");
			fprintf(fp, "%d %d\n",rlim,clim);
			for (auto &w:tmp) {
				fprintf(fp, "%s\n",w.c_str());
			}
			fclose(fp);
			/* End custom code! */

			// Execute child process with test case number as its only argument
			ostringstream childCommandLine; childCommandLine << argv[0] << " " << testnum;
			pid_t pid=fork();
			running_child_pids.insert(pid);
			int exitCode,status;
			switch(pid) {
				case -1:
					cerr<<"Fork failed"<<endl; assert(0);
					break;
				case 0:
					/*
					Start a new process by running this executable with the test case number as its only argument.
					*/
					exitCode = system(childCommandLine.str().c_str());
					if (exitCode!=0) {cerr<<"Runtime error"<<endl; assert(0);}
					assert(exitCode==0);
					return 0;
					break;
				default:
					// Parent process
					break;
			}
			wait_for_running_children_to_be_under_limit(running_child_pids, MAX_NUM_PROCESSES);
		}
		// Wait for processes to finish executing
		wait_for_running_children_to_be_under_limit(running_child_pids, 0);

		for (int testnum=1;testnum<=number_of_test_cases;testnum++) {
			/* Custom code here! Read one test case, and output to testcasein* file */
			std::ifstream ifs(getoutputfilename(testnum).c_str(),std::ifstream::in);
			string str;
			while(getline(ifs,str)) {
				if (ifs.bad()) {cerr<<"ifs bad"<<endl; assert(0);}
				cout<<str<<endl;
				if (ifs.eof()) break;
			}
		}
	}
	else {
		int testnum; istringstream(argv[1]) >> testnum;
		ostringstream testcasein; testcasein<<"testcasein"<<testnum;
		ostringstream testcaseout; testcaseout<<"testcaseout"<<testnum;
		mainsolve(getinputfilename(testnum),getoutputfilename(testnum), testnum);
	}
}
