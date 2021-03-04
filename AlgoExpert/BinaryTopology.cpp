#include<bits/stdc++.h>
using namespace std;

// O(n) time and space
int BinTopNum(int n){
    // 1 2 5 14 36 92
    vector<int> dp = {0,1,2,5};
    if(n < 4) return dp[n];
    for(int i = 4; i <= n; i++){
        dp.push_back(dp[i-1]*2+4*dp[i-3]);
    }
    return dp[n];
}

int main(){
    for(int i=0; i < 10; i++){
        cout << "number of binary topologies: " << BinTopNum(i) << "\n";
    }
    return 0;
}