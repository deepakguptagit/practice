#include<bits/stdc++.h>
using namespace std;

int main () {
  string s;
  cin >> s;
  int N = s.size();
  for (char c = 'a'; c <= 'z'; c++) {
    for (int i = 0; i <= N; i++) {
      string temp = s.substr(0, i) + c + s.substr(i);
      string temp_rev = temp;
      reverse(temp_rev.begin(), temp_rev.end());
      if (temp == temp_rev) {
        cout << temp << endl;
        return 0;
      }
    }
  }
  cout << "NA\n";
  return 0;
}
