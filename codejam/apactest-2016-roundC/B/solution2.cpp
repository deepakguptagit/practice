#include <bits/stdc++.h>
using namespace std;

long long int merge(vector<pair<unsigned long long int, unsigned long long int> > possible){
  unsigned long long int start = 0, end = 99999999999999999LL;
  for(int i=0;i<possible.size();i++){
    start = max(start,possible[i].first);
    end = min(end,possible[i].second);
  }
  if(end == start)
    return end;
  else
    return -1;
}

int main(){
  int T;
  int cno = 0;
  cin >> T;
  while(cno++ < T){
    int N;
    cin >> N;
    vector<pair<unsigned long long int, unsigned long long int> > possible;
    bool flag = false;
    for(int i=0;i<N;i++){
      unsigned long long int P, K;
      cin >> P >> K;
      if(P==100 && !flag){
        cout << "Case #" << cno << ": " << K << "\n";
        flag = true;
      }
      unsigned long long int frst = 100*K;
      possible.push_back(make_pair((100*K)/(P+1)+1,P!=0?(100*K)/P:1000000000000005LL));
    }
    if(flag)
      continue;
    long long int soln = merge(possible);
    cout << "Case #" << cno << ": " << soln << "\n";
  }
  return 0;
}
