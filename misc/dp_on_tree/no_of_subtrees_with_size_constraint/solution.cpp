#include <bits/stdc++.h>
using namespace std;

#define VI vector<int>
#define VB vector<bool>

#define VVI vector<VI>

int subset_sum_count(VI arr, int k) {
  if (arr.size() == 0) return 0;
  VI dp(k + 1);
  dp[0] = 1;
  for (int i = 0; i < arr.size(); i++) {
    vector<int> temp(k+1);
    for (int j = 0; j <= k; j++) {
      if (j - arr[i] >= 0) {
        temp[j] += dp[j - arr[i]];
      }
    }
    for (int j =0; j <= k; j++) {
      dp[j] += temp[j];
    }
  }
  int cnt = 0;
  for (int i = 0; i <= k; i++) cnt += dp[i];
  return cnt;
}

int solve_impl(VVI &adj_list, int node, int k) {
  int N = adj_list.size();
  static VB visited(N);
  static VI fn(N), gn(N);

  // fn[i] contains no of subtrees rooted at i
  // gn[i] contains no of subtrees not rooted at i

  visited[node] = true;
  VI f_values, g_values;
  for (int i = 0; i < adj_list[node].size(); i++) {
    int child = adj_list[node][i];
    if (!visited[child]) {
      solve_impl(adj_list, child, k);
      f_values.push_back(fn[child]);
      g_values.push_back(gn[child]);
    }
  }
  fn[node] = max(subset_sum_count(f_values, k - 1) + 1, 1);
  gn[node] = 0;
  for (int i = 0; i < f_values.size(); i++) {
    gn[node] += f_values[i] + g_values[i];
  }
  cout << "fn and gn for " << node << " are " << fn[node] << " " << gn[node]
       << endl;
  return fn[node] + gn[node];
}

int solve(VVI &adj_list, int k) { return solve_impl(adj_list, 0, k); }

int main() {
  int N;
  cin >> N;
  VVI adj_list(N);
  for (int i = 0; i < N - 1; i++) {
    int from, to;
    cin >> from >> to;
    adj_list[from].push_back(to);
  }
  int k;
  cin >> k;
  cout << solve(adj_list, k) << endl;
}
