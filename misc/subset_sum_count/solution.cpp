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
  return dp[k];
}

int main () {
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  int k;
  cin >> k;
  cout << subset_sum_count(arr, k) << endl;
}
