#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct s {
  int x, y;
  char c;
  s(){};
  bool operator<(const s& obj) const { return this->c < obj.c; }
};

int main() {
  vector<s> v;
  v.resize(3);
  for (int i = 0; i < 3; i++) {
    cin >> v[i].x >> v[i].y;
    v[i].c = 'A' + i;
  }
  for (int i = 0; i < (1 << 3); i++) {
    vector<s> tmp = v;
    for (int j = 0; j < 3; j++)
      if (i & (1 << j)) swap(tmp[j].x, tmp[j].y);
    sort(tmp.begin(), tmp.end());

    do {
      if ((tmp[0].x == tmp[1].x && tmp[1].x == tmp[2].x) &&
          (tmp[0].x == tmp[0].y + tmp[1].y + tmp[2].y)) {
        cout << tmp[0].x << endl;
        for (int j = 0; j < 3; j++) {
          for (int k = 0; k < tmp[j].y; k++) {
            for (int l = 0; l < tmp[0].x; l++) cout << tmp[j].c;
            cout << endl;
          }
        }

        return 0;
      } else if ((tmp[0].x == tmp[1].x + tmp[2].x) && (tmp[1].y == tmp[2].y) &&
                 (tmp[0].x == tmp[0].y + tmp[1].y)) {
        cout << tmp[0].x << endl;
        for (int j = 0; j < tmp[0].y; j++) {
          for (int k = 0; k < tmp[0].x; k++) cout << tmp[0].c;
          cout << endl;
        }
        for (int j = 0; j < tmp[1].y; j++) {
          for (int k = 0; k < tmp[0].x; k++) {
            if (k < tmp[1].x)
              cout << tmp[1].c;
            else
              cout << tmp[2].c;
          }
          cout << endl;
        }
        return 0;
      }
    } while (next_permutation(tmp.begin(), tmp.end()));
  }
  cout << -1 << endl;
}
