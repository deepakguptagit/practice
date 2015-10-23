#include<bits/stdc++.h>
using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int N; cin >> N;
    vector<int> A(N);
    string ans = "YES\n";
    bool is_swap = false;
    for (int i = 0; i < N; i++){
      scanf("%d", &A[i]);
      if (i == 0 || ans == "NO\n") continue;
      if (!is_swap && A[i] < A[i-1]) {
        is_swap = true;
        swap(A[i], A[i-1]);
      } else if (is_swap && A[i] < A[i-1]) {
        ans = "NO\n";
      } else if (is_swap) is_swap = false;
    }
    cout << ans << endl;
  }
}
