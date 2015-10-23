#include<bits/stdc++.h>
using namespace std;

#define MAX 101
set<int> graph[MAX][MAX];
int visited[MAX];

bool is_edge(int u,int v,int c) {
  return (graph[u][v].find(c) != graph[u][v].end());
}

bool is_connected(int u, int v, int c) {
  visited[u] = true;
  for (int i = 0; i < MAX; i++) {
    if (is_edge(u, i, c) && !visited[i]) {
      is_connected(i, v, c);
    }
  }
  return (visited[v] == true);
}

int main () {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a][b].insert(c);
    graph[b][a].insert(c);
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int u, v, count = 0;
    cin >> u >> v;
    for (int c = 0; c < 100; c++) {
      memset(visited, 0, sizeof(visited));
      if (is_connected(u, v, c)) {
        count++;
      }
    }
    cout << count << endl;
  }
}
