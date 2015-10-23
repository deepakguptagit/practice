#include<bits/stdc++.h>
using namespace std;

#define VI vector < int >
#define VB vector < bool >

#define VVI vector < VI >

int solve_impl(VVI &adj_list, int node) {
  int N = adj_list.size();
  static VB visited(N);
  static VI fn(N), gn(N);

  // fn[i] contains no of subtrees rooted at i
  // gn[i] contains no of subtrees not rooted at i

  visited[node] = true;
  VI f_values, g_values;
  for (int i = 0; i < adj_list[node].size(); i++) {
    int child = adj_list[node][i];
    if (! visited[child]) {
      solve_impl(adj_list, child);
      f_values.push_back(fn[child]);
      g_values.push_back(gn[child]);
    }
  }
  fn[node] = 1;
  for (int i = 0; i < f_values.size(); i++) {
    fn[node] *= (1 + f_values[i]);
  }
  gn[node] = 0;
  for (int i = 0; i < f_values.size(); i++) {
    gn[node] += f_values[i] + g_values[i];
  }
  return fn[node] + gn[node];
}

int solve(VVI &adj_list) {
  return solve_impl(adj_list, 0);
}

int main () {
  int N;
  cin >> N;
  VVI adj_list(N);
  for (int i = 0; i < N; i++) {
    int from, to;
    cin >> from >> to;
    adj_list[from].push_back(to);
  }
  cout << solve(adj_list) << endl;

}
