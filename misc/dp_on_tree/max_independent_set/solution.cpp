#include <bits/stdc++.h>
using namespace std;

#define VI vector<int>
#define VVI vector<VI>

// contains node, cost pair if node is selected for subset
map<int, int> max_if_chosen;
map<int, int> max_if_not_chosen;

// Finds the subset of node s.t. the cost of maximimed and
// no two adjacent nodes are chosen.
int solve(int N, VVI adjacency_list, VI cost, int root) {
  static VI visited(N);

  visited[root] = 1;

  // Base case, when root is the leaf
  if (adjacency_list[root].size() == 0) {
    max_if_chosen[root] = cost[root];
    max_if_not_chosen[root] = 0;
  }

  for (int i = 0; i < adjacency_list[root].size(); i++) {
    int child_node = adjacency_list[root][i];
    if (!visited[child_node]) {
      solve(N, adjacency_list, cost, child_node);
    }
  }

  int x = 0;
  int y = 0;
  for (int i = 0; i < adjacency_list[root].size(); i++) {
    int child = adjacency_list[root][i];
    x += max_if_not_chosen[child];
    y += max(max_if_chosen[child], max_if_not_chosen[child]);
  }
  max_if_chosen[root] = cost[root] + x;
  max_if_not_chosen[root] = y;
  return max(max_if_chosen[root], max_if_not_chosen[root]);
}

int main() {
  // No of nodes in tree
  int N;
  cin >> N;

  VVI adjacency_list(N);
  VI cost(N);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    adjacency_list[a].push_back(b);
  }

  for (int i = 0; i < N; i++) {
    cin >> cost[i];
  }

  cout << solve(N, adjacency_list, cost, 0) << endl;
}
