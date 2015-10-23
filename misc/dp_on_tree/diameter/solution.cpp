#include<bits/stdc++.h>
using namespace std;

#define VI vector < int >
#define VVI vector < VI >

// Finds diameter of a given graph
int solve(int &N, VVI &adj_list, int root) {
  static VI visited(N);
  static VI fn(N), gn(N);
  static int diameter;
  visited[root] = 1;
  // base case - leaf
  if (adj_list[root].size() == 0) {
    fn[root] = 1;
    gn[root] = 1;
    return 1;
  }
  VI f_values;
  for (int i = 0 ; i < adj_list[root].size(); i++) {
    if (!visited[adj_list[root][i]]) {
      solve(N, adj_list, adj_list[root][i]);
      f_values.push_back(fn[adj_list[root][i]]);
    }
  }
  sort(f_values.begin(), f_values.end());
  reverse(f_values.begin(), f_values.end());
  if (f_values.size() >= 1)
    fn[root] = f_values[0] + 1;
  if (f_values.size() >= 2) {
    gn[root] = 1 + f_values[0] + f_values[1];
  }
  int max_path_through_root = max(fn[root], gn[root]);
  diameter = max(diameter, max_path_through_root);
  return diameter;
}

int main () {
  int N;
  cin >> N;
  VVI adj_list(N);
  for (int i = 0; i < N - 1; i++) {
    int from, to;
    cin >> from >> to;
    from--; to--;
    adj_list[from].push_back(to);
  }
  cout << solve(N, adj_list, 0) - 1 << endl;
}
