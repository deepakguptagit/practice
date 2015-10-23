#include<bits/stdc++.h>
using namespace std;


int main() {
  int T;
  cin >> T;
  vector<int> points;
  for (int c = 0; c < T; c++) {
    cout << "Case #" << c+1 << ": " << endl;
    map<string, vector<int> > player_point_map;
    multimap<int, string> point_player_map;
    int P;
    cin >> P;
    points.resize(P);
    for (int i = 0; i < P; i++) cin >> points[i];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      int W; cin >> W;
      for (int j = 0; j < P; j++) {
        string player;
        cin >> player;
        if (player_point_map.find(player) != player_point_map.end()) {
          player_point_map[player].push_back(W*points[j]);
        } else {
          vector<int> v;
          v.push_back(W*points[j]);
          player_point_map[player] = v;
        }
      }
    }
    int M, rank = 0, prev = INT_MAX;
    cin >> M;
    for (auto entry : player_point_map) {
      int total_points  = 0;
      for (int i = 0; entry.second.size() > i && i < M; i++) {
        total_points += entry.second[i];
      }
      point_player_map.insert(make_pair(INT_MAX - total_points, entry.first));
    }
    int count = 1;
    for (auto entry : point_player_map) {
      if (prev != entry.first) { rank += count; count = 1; }
      else count++;
      cout << rank << ": " << entry.second << endl;
      prev = entry.first;
    }
  }
}
