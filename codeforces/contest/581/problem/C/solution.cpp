#include<bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> skill(N);
  multimap<int, int> scaled_skill;
  for (int i = 0; i < N; i++) {
    cin >> skill[i];
    scaled_skill.insert(make_pair(min(skill[i] - ((skill[i]/10)*10), 100), i));
  }
  auto it = scaled_skill.rbegin();
  for (; K >= 0 && it != scaled_skill.rend(); it++) {
    int ind = it -> second;
    int new_val = ((skill[ind]/10)*10) + 10;
    if (K >= new_val - skill[ind]) {
      K -= new_val - skill[ind];
      skill[ind] = new_val;
    }
  }
//  cout << "Increased\n"   << K << endl;
//  for (int i = 0; i < N; i++ ) {
//    cout << skill[i] << " ";
//  }
//  cout << endl;
  for (int i = 0; K >= 0 && i < N; i++) {
    if (K >= (100 - skill[i])) {
      K -= (100 - skill[i]);
      skill[i] = 100;
    }
    else {
      skill[i] += K;
      K = 0;
    }
  }
//  cout << "Skillful\n" << K << endl;
//  for (int i = 0; i < N; i++ ) {
//    cout << skill[i] << " ";
//  }
//  cout << endl;
  int total_rating = 0;
  for (int i = 0; i < N; i++) {
    total_rating += (skill[i]/10);
  }
  cout << total_rating << endl;

}
