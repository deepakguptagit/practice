#include<bits/stdc++.h>
using namespace std;

#define MAX 25
#define TOKEN 1e7

int SP[MAX][MAX][MAX];
int N, M, K;

void findSP(int hour) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        SP[i][j][hour] = min(SP[i][j][hour], SP[i][k][hour] +  SP[k][j][hour]);
      }
    }
  }
}

void resetSP() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      for (int k = 0; k < MAX; k++) {
        SP[i][j][k] = TOKEN;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    resetSP();
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
      int X, Y;
      cin >> X >> Y;
      for (int i = 0; i < 24; i++) {
        int cost;
        cin >> cost;
        SP[X-1][Y-1][i] = cost;
      }
    }

    for (int i = 0; i < 24; i++) {
      findSP(i);
    }

    for (int i = 0; i < K; i++) {
      int D, S;
      cin >> D >> S;
      if (SP[0][D-1][S] != TOKEN)
        cout << SP[0][D-1][S] << " ";
      else cout << -1 << " ";
    }
    cout << endl;
  }
}
