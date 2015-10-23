#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
vector<ll> factors;

int dp[10000000];

int isPrime(int x) {
    if (x==1) return 1;
    for (ll i=2; i*i<=x; i++) {
        if (x%i==0)return 0;
    }
    return 1;
}

ll sum(ll x) {
    ll ret = 0;
    while (x) {
        ret = ret + x%10;
        x = x/10;
    }
    return ret;
}

int solve(int done, ll num) {
    if ( isPrime(sum(num)) ) {
        return 0;
    }
    if (dp[done]!=-1) {
        return dp[done];
    }
    int allWin = 1;
    for (int i=0; i<factors.size(); i++) {
        if (done & (1<<i))continue;
        ll temp = num;
        while (temp % factors[i]==0) {
            temp = temp/factors[i];
        }
        int ret = solve(done|(1<<i), temp);
        if (ret == 0)allWin = 0;
    }
    dp[done] = 1-allWin;
    return 1-allWin;
}

int main() {
    int t;
    cin>>t;
    int cs = 1;
    while(t--) {
        factors.clear();
        cout<<"Case #"<<cs++<<": ";
        ll num = 0;
        cin>>num;
        ll temp = num;
        for (ll i=2; i*i<=num; i++) {
            if (temp%i==0) {
                while(temp%i==0) {
                    temp = temp/i;
                }
                factors.push_back(i);
                if (temp==1)break;
            }
        }
        memset(dp, -1, sizeof(dp));
        if (temp!=1) {
            factors.push_back(temp);
        }
        if (solve(0, num)) {
            cout<<"Laurence"<<endl;
        } else {
            cout<<"Seymour"<<endl;
        }
    }
}
