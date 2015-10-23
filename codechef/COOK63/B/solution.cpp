#include <bits/stdc++.h>
using namespace std;

string LCSubStr(string X, string Y) {
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string ans = "";
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++) {
      cin >> words[i];
    }
    for (int i = 0; i < words[0].size(); i++) {
      for (int j = 1; j <= words[0].size() - i; j++) {
        string sub = words[0].substr(i, j);
        bool found = true;
        for (int k = 1; k < words.size(); k++) {
          if (words[k].find(sub) == string::npos) {
            found = false;
          }
        }
        if (found && (ans.size() < sub.size() ||
            (ans.size() == sub.size() && ans > sub))) {
          ans = sub;
        }
      }
    }
    cout << ans << endl;
  }
}
