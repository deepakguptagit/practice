#include<bits/stdc++.h>
using namespace std;

vector<int> random_order;
map<int, string> team;

void map_team() {
  team.insert(make_pair(1, "deepakgupta"));
  team.insert(make_pair(2, "gunjanp"));
  team.insert(make_pair(3, "charvibhasin"));
  team.insert(make_pair(4, "gsubraman"));
  team.insert(make_pair(5, "rravindran"));
  team.insert(make_pair(6, "nsananth"));
  team.insert(make_pair(7, "nikhildev"));
  team.insert(make_pair(8, "sidhantc"));
  team.insert(make_pair(9, "lchhakchhuak"));
  team.insert(make_pair(10, "gollamudi"));
  team.insert(make_pair(11, "khalid"));
  team.insert(make_pair(12, "sbilora"));
  team.insert(make_pair(13, "avasanth"));
}

int main () {
  std::srand ( unsigned ( std::time(0) ) );
  map_team();
  int N = 13; // TDT
  for (int i = 0; i < N; i++) random_order.push_back(i+1);
  std::random_shuffle(random_order.begin(), random_order.end());
  for (int i = 0; i < random_order.size(); i++) {
    cout << "Desk no : " << i + 1 << " -> "   <<  team.find(random_order[i]) -> second << endl;
  }
}
