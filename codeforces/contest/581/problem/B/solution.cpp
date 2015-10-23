#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> street(N);
  for (int i = 0; i < N; i++) {
    cin >> street[i];
  }
  int max_floors = -1;
  for (int i = N-1; i >= 0; i--) {
    int temp = max(0, max_floors - street[i] + 1);
    max_floors = max(max_floors, street[i]);
    street[i] = temp;
  }
  for (int i = 0; i < street.size(); i++) {
    cout << street[i] << " ";
  }
  cout << endl;
}
