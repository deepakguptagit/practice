#include<bits/stdc++.h>
using namespace std;

#define VI vector < int >
#define VB vector < bool >

#define VVI vector < VI >

#define MAX 40000
#define LOG true

int N;
VB visited(MAX), fs(MAX), fe(MAX), cs(MAX), ce(MAX);
VI start_time(MAX), end_time(MAX);
int current_time = 0;

void dfs(VVI &G, VI &parent, VB &is_possible, int root) {
  visited[root] = true;
  start_time[root] = current_time++;
  if (LOG) cout << "start time of " << root << " is " << start_time[root] << endl;
  for (int child_ind = 0; child_ind < G[root].size(); child_ind++) {
    int child = G[root][child_ind];
    if (!visited[child]) {
      parent[child] = root;
      dfs(G, parent, is_possible, child);
    } else if (end_time[child] == -1) {
      // noop
        if (LOG) cout << "backedge edge from " << root << " to " << child << endl;
    } else if (start_time[child] > start_time[root] &&
               end_time[root] == -1){
        if (LOG) cout << "forward edge from " << root << " to " << child << endl;
        fs[root] = true;
        fe[child] = true;
    } else {
        if (LOG) cout << "cross edge from " << root << " to " << child << endl;
        ce[child] = true;
        int x = root;
        while (x != -1) {
          cs[x] = true;
          if (LOG) cout << "cs[" << x << "] : " << "true" << endl;
          x = parent[x];
        }
    }
  }
  end_time[root] = current_time++;
  if (LOG) cout << "end time of " << root << " is " << end_time[root] << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    fill(visited.begin(), visited.end(), false);
    fill(start_time.begin(), start_time.end(), -1);
    fill(end_time.begin(), end_time.end(), -1);
    fill(fe.begin(), fe.end(), 0);
    fill(fs.begin(), fs.end(), 0);
    fill(cs.begin(), cs.end(), 0);
    fill(ce.begin(), ce.end(), 0);
    current_time = 0;
    int N, M;
    cin >> N >> M;
    VVI G(N);
    for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      G[a].push_back(b);
    }
    VI parent(N, -1);
    VB is_possible(N, true);
    dfs(G, parent, is_possible, 0);
    int iter = N - 1, closest = N - 1, fcount = 0, ccount = 0;
    while (true) {
      if (parent[iter] == 0) {
        break;
      }
      if (fe[iter]) fcount++;
      if (ce[iter]) ccount++;
      if (cs[iter]) ccount--;
      if (fs[iter]) fcount--;
      if (!fcount && !ccount) closest = iter;
      iter = parent[iter];
      if (LOG) cout << "iter : " << iter << "  closest: " << closest << endl;
    }
    cout << closest + 1 << endl;
  }

}
