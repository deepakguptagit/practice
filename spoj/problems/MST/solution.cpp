#include<bits/stdc++.h>
using namespace std;

#define MAX 10000

struct compare {
  bool operator()(const pair<int, int>& l, const pair<int, int>& r) {
    return l > r;
  }
};

pair<int, int> swap_pair(pair<int, int> p) {
  return make_pair(p.second, p.first);
}

long long find_mstws(vector<pair<int, int> > G[], int N, int M) {
  set<pair<pair<int, int>,int> > used_edges;
  priority_queue<pair<int, int>, vector<pair<int, int> >, compare> min_pq;
  long long mstws = 0;
  for (int i = 0; i < G[0].size(); i++) {
    min_pq.push(swap_pair(G[0][i]));
    int node = G[0][i].first;
    int weight = G[0][i].second;
    used_edges.insert(make_pair(make_pair(min(0, node), max(0, node)), weight));
  }
  for (int i = 0; i < N - 1; i++) {
    pair<int, int> top = min_pq.top();
    min_pq.pop();
    int node = top.second;
    int weight = top.first;
    mstws += weight;
    for (int j = 0; j < G[node].size(); j++) {
      int node2 = G[node][j].first;
      int weight2 = G[node][j].second;
      if (used_edges.find(make_pair(make_pair(min(node2, node), max(node2, node)), weight2)) == used_edges.end()) {
        min_pq.push(swap_pair(G[node][j]));
        used_edges.insert(make_pair(make_pair(min(node2, node), max(node2, node)), weight2));
      }
    }
  }
  return mstws;
}

int main() {
  int N, M;
  vector<pair<int, int> > G[MAX];
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    G[a].push_back(make_pair(b, w));
    G[b].push_back(make_pair(a, w));
  }
  long long mstws = find_mstws(G, N, M);
  cout << mstws << endl;
}
