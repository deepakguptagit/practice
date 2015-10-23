#include<bits/stdc++.h>
using namespace std;

#define MAX 300001

int main () {
  int N, K;
  cin >> N >> D;
  int gems_on_island[MAX];
  for (int i = 0; i < N; i++) {
    int location;
    cin >> location;
    gems_on_island[location]++;
  }
  map<int, int> jump_value_map[MAX];
  for (int i = 0; i < MAX; i++) {
    jump_value_map[0][i] = 0;
  }
  jump_value_map[d][d] = gems_on_island[d];
  int answer = 0;
  for (int i = d+1; i < MAX; i++) {
  
  }
}
