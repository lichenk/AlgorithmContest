#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}


template<typename T>
struct MaxFlowMinCost {
    struct Edge {
        T cap, flow, cost;
        int to;
    };
    vector<Edge> Edges;
    vector<vector<int>> G;
    int src, dest;

    vector<int> Parent, ParentEdge, InQ;
    vector<T> Dist;


    MaxFlowMinCost& Initialize(int n, int m = 0) {
        G.clear();
        G.resize(n);
        Edges.clear();
        Edges.reserve(m);
        Parent.resize(n);
        ParentEdge.resize(n);
        Dist.resize(n);
        InQ.resize(n);

        return *this;
    }

    void _addEdge(int from, int to, T cap, T cost) {
        int ei = Edges.size();
        Edges.push_back(Edge {cap, 0, cost, to});
        G[from].push_back(ei);
    }
    MaxFlowMinCost& AddEdge(int from, int to, T cap, T cost) {
        _addEdge(from, to, cap, cost);
        _addEdge(to, from, 0, -cost);
        return *this;
    }

    MaxFlowMinCost& SetSourceSink(int src, int dest) {
        this->src = src; this->dest = dest;
        return *this;
    }

    bool Bellman() {
        static queue<int> Q;

        fill(Dist.begin(), Dist.end(), numeric_limits<T>::max());
        fill(Parent.begin(), Parent.end(), -1);
        fill(InQ.begin(), InQ.end(), 0);

        Dist[src] = 0;
        Q.push(src);

        while(!Q.empty()) {
            int node = Q.front();
            Q.pop();
            InQ[node] = 0;

            if(Parent[node] != -1 && InQ[Parent[node]])
                continue;

            for(auto ei : G[node]) {
                auto &e = Edges[ei];
                if(e.flow < e.cap && Dist[e.to] > Dist[node] + e.cost) {
                    Dist[e.to] = Dist[node] + e.cost;
                    Parent[e.to] = node;
                    ParentEdge[e.to] = ei;
                    if(!InQ[e.to]) {
                        Q.push(e.to);
                        InQ[e.to] = 1;
                    }
                }
            }
        }

        return Parent[dest] != -1;
    }
    pair<T, T> Compute() {
        T flow = 0, cost = 0;

        while(Bellman()) {
            T m = numeric_limits<T>::max();
            for(int node = dest; node != src; node = Parent[node]) {
                int ei = ParentEdge[node];
                m = min(m, Edges[ei].cap - Edges[ei].flow);
            }
            for(int node = dest; node != src; node = Parent[node]) {
                int ei = ParentEdge[node];
                Edges[ei].flow += m;
                Edges[ei ^ 1].flow -= m;
                
                cost += Edges[ei].cost * m;
            }
            flow += m;
        }

        return {flow, cost};
    }
};

MaxFlowMinCost<long long> mc;
const int mn=404;
int px[mn],py[mn];
const ll C=1000LL*1000LL*1000LL*1000LL;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    px[i]=rint(),py[i]=rint();
  }
  int src=2*n+1,dest=2*n+2;
  mc.Initialize(dest+1);
  mc.SetSourceSink(src,dest);
  for (int x=0;x<n;x++) {
    mc.AddEdge(src,x,1,0);
    mc.AddEdge(x+n,dest,2,0);
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (py[i]<py[j]) {
        int dx=px[i]-px[j];
        int dy=py[i]-py[j];
        int dist2=dx*dx+dy*dy;
        ld dist=sqrt((ld)dist2);
        ll cost=round(dist*C);
        mc.AddEdge(i,j+n,1,cost);
      }
    }
  }
  int needflow=n-1;
  pll got=mc.Compute();
  if (got.fst<needflow) {
    printf("-1\n"); return 0;
  }
  else {
    assert(got.fst==needflow);
    ll gotcost=got.snd;
    ld final=((ld)gotcost)/C;
    printf("%.10f\n",(double)final);
  }
}