#include<bits/stdc++.h>
using namespace std;

#define MAX 500

int store[MAX][MAX][MAX][2];

void prefix_albocedes(string s, char a, char b, int pos) {
  store[0][0][0][pos]++;
  if (s[0] == a) {
    store[1][0][0][pos]++;
  }
  int len = s.size();
  for (int x = 1; x < len; x++) {
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        store[i][j][x][pos] = store[i][j][x-1][pos];
      }
    }
    if (s[x] == a) {
      for (int i = 1; i < len; i++) {
        store[i][0][x][pos] += store[i-1][0][x-1][pos];
      }
    }
    else if (s[x] == b) {
      for (int i = 0; i < len; i++) {
        for (int j = 1; j < len; j++) {
          store[i][j][x][pos] += store[i][j-1][x-1][pos];
        }
      }
    }
  }
}

int albocede_sub(int len) {
  int count = 0;
  for (int k = 1; k < len - 2; k++) {
    for (int i = 1; i < len; i++) {
      for (int j = 1; j < len; j++) {
        count += store[i][j][k][0] * store[i][j][len-k-1][1];
      }
    }
  }
  return count;
}

int print(int len) {
  for (int p = 0; p < 2; p++) {
    cout << "p = " << p << endl;
    for (int k = 0; k < len; k++) {
      cout << "k = " << k << endl;
      for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
         cout << store[i][j][k][p] << " ";
        }
        cout << endl;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    memset(store, 0, sizeof(store));
    string s;
    cin >> s;
    prefix_albocedes(s, 'a', 'b', 0);
    reverse(s.begin(), s.end());
    prefix_albocedes(s, 'c', 'd', 1);
    print(s.size());
    cout << albocede_sub(s.size()) << endl;
  }
}
