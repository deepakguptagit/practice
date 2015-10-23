#include<bits/stdc++.h>
using namespace std;

long long solve(int c) {
  cout << "Case #" << c+1 << ": ";
  int N;
  cin >> N;
  long long ans = -1;
  vector<pair<long long, long long> > values(N);
  for (int i = 0; i < N; i++) {
    cin >> values[i].first >> values[i].second;
    values[i].second *= 100;
    if (values[i].first == 100) ans = values[i].second/100;
  }
  if (ans != -1) {
    for (int i = 0 ; i < N; i++) {
      if (values[i].second / ans != values[i].first) return -1;
    }
    return ans;
  }
  long long low = 0;
  long long high = LLONG_MAX;
  long long mid;
  bool found = false;
  while (low <= high) {
    mid = (low + high)/2;
    long long count = 0;
    bool wantlow = false;
    bool wanthigh = false;
    for (int i = 0; i < values.size(); i++) {
      if (values[i].second / mid == values[i].first) {
        count++;
      }
      else if (values[i].second / mid > values[i].first) {
        wanthigh = true;
      } else {
        wantlow = true;
      }
    }
    if (ans == -1 && count == values.size()) {
      ans = mid;
    }
    else if (ans != mid && count == values.size()) {
      return -1;
    }
    if (low == high) return ans;
    if (wanthigh) {
      low = mid;
    } else if (wantlow) {
      high = mid;
    } else {
      low++;
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int c = 0; c < T; c++) {
    cout << solve(c) << endl;
  }
}
