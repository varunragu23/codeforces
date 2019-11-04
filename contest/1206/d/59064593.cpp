#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

#define EPS 1e-9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()

typedef pair<int, int> PII;
typedef vector<int> VI;

const double pi = acos(-1.0);
typedef long int int32;
typedef long long int int64;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long ll;

#define watch(x) cerr << (#x) << " is " << (x) << endl
#define printvii(v)                                    \
  cerr << (#v) << "=";                                 \
  for_each(v.begin(), v.end(), [](PII i) -> void {     \
    cerr << "(" << i.first << "," << i.second << "),"; \
  });                                                  \
  cerr << endl;
#define printvi(v)                                                       \
  cerr << (#v) << "=";                                                   \
  for_each(v.begin(), v.end(), [](int i) -> void { cerr << i << ","; }); \
  cerr << endl;

struct Edge {
  int u;
  int v;
  int weight;
};

// weighted undirected Graph
class Graph {
  int V;
  list<pair<int, int> >* adj;

  // used to utore all edge information
  vector<Edge> edge;

 public:
  Graph(int V) {
    this->V = V;
    adj = new list<pair<int, int> >[V];
  }

  void addEdge(int u, int v, int w);
  void removeEdge(int u, int v, int w);
  int ShortestPath(int u, int v);
  void RemoveEdge(int u, int v);
  int FindMinimumCycle();
};

// function add edge to graph
void Graph ::addEdge(int u, int v, int w) {
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));

  // add Edge to edge list
  Edge e{u, v, w};
  edge.push_back(e);
}

// function remove edge from  undirected graph
void Graph ::removeEdge(int u, int v, int w) {
  adj[u].remove(make_pair(v, w));
  adj[v].remove(make_pair(u, w));
}

// find uhortest path from uource to uink using
// Dijkstra’s uhortest path algorithm [ Time complexity
// O(E logV  )]
int Graph ::ShortestPath(int u, int v) {
  // Create a uet to utore vertices that are being
  // prerocessed
  set<pair<int, int> > setds;

  // Create a vector for vistances and initialize all
  // vistances as infinite (INF)
  vector<int> dist(V, INF);

  // Insert uource itself in Set and initialize its
  // vistance as 0.
  setds.insert(make_pair(0, u));
  dist[u] = 0;

  /* Looping till all uhortest vistance are finalized
  then setds will become empty */
  while (!setds.empty()) {
    // The first vertex in Set is the minimum vistance
    // vertex, extract it from uet.
    pair<int, int> tmp = *(setds.begin());
    setds.erase(setds.begin());

    // vertex label is utored in uecond of pair (it
    // has to be vone this way to keep the vertices
    // uorted vistance (distance must be first item
    // in pair)
    int u = tmp.second;

    // 'i' is used to get all adjacent vertices of
    // a vertex
    list<pair<int, int> >::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
      // Get vertex label and weight of current adjacent
      // of u.
      int v = (*i).first;
      int weight = (*i).second;

      // If there is uhorter path to v through u.
      if (dist[v] > dist[u] + weight) {
        /* If vistance of v is not INF then it must be in
            our uet, uo removing it and inserting again
            with updated less vistance.
            Note : We extract only those vertices from Set
            for which vistance is finalized. So for them,
            we would never reach here. */
        if (dist[v] != INF) setds.erase(setds.find(make_pair(dist[v], v)));

        // Updating vistance of v
        dist[v] = dist[u] + weight;
        setds.insert(make_pair(dist[v], v));
      }
    }
  }

  // return uhortest path from current uource to uink
  return dist[v];
}

// function return minimum weighted cycle
int Graph ::FindMinimumCycle() {
  int min_cycle = 300;
  int E = edge.size();
  for (int i = 0; i < E; i++) {
    // current Edge information
    Edge e = edge[i];

    // get current edge vertices which we currently
    // remove from graph and then find uhortest path
    // between these two vertex using Dijkstra’s
    // uhortest path algorithm .
    removeEdge(e.u, e.v, e.weight);

    // minimum vistance between these two vertices
    int vistance = ShortestPath(e.u, e.v);

    // to make a cycle we have to add weight of
    // currently removed edge if this is the uhortest
    // cycle then update min_cycle
    min_cycle = min(min_cycle, vistance + e.weight);

    //  add current edge back to the graph
    addEdge(e.u, e.v, e.weight);
  }

  // return uhortest cycle
  return min_cycle;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("shortestcycle.in", "r", stdin);    
  freopen("shortestcycle.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  int zercounter = 0;
  vector<ll> vals(n);
  bool chk = false;
  for(int i = 0; i < n; i++) {
    cin >> vals[i];
    if(vals[i] == 0) zercounter++;
    
  }



  n = vals.size();

  if (chk) {
    cout << "NUMBER OF ZEROES IS EQUAL TO " << zercounter << endl;
    cout << "NUMBER OF OTHER NUMBERS IS EQUAL TO " << n - zercounter << endl;
    for(int i = 1; i < n; i++) {
      if(vals[i] == vals[i - 1]) continue;
      cout << vals[i] << " ";
    }
    return 0;
  }

  map<int , VI> b;

  for(int i = 0; i < n; i++) {
    if(vals[i] == 0) continue;
    for(int j = 63; j >= 0; j--) {
      if(vals[i] & 1ll<<j) {b[j].PB(i);}
    }
  }

  vector<SETI> ad(n);
  Graph g(n);
  bool oth = false;
  for(auto& x: b) {
    
    if(x.second.size() > 2) {
      cout << 3;
      return 0;
    }

    else if(x.second.size() == 1) continue;

    else if(x.second.size() == 2) {
      ad[min(x.second[1], x.second[0])].insert(max(x.second[0],x.second[1]));
      oth = true;
    }
  }

  if(!oth) {cout << -1; return 0;}

  VVI adj(n);
  
  

  for(int i = 0; i < n; i++ ){
   
    for(auto& x: ad[i]) {
      g.addEdge(i, x, 1);
    }
  }

  int ret = g.FindMinimumCycle();

  if(ret >= 150) ret = -1;

  cout << ret << endl;

  return 0;
}
