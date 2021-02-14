#include<bits/stdc++.h>
using namespace std;

void maxProfit(vector<int> arr, int k){
    vector<vector<int>> dp(k+1, vector<int>(arr.size(), 0));
    
    for(int i = 1; i <= k; i++){
        for(int j = 1; j < arr.size(); j++){
            int prok = INT_MIN;
            for(int k = 0; k < j; k++) prok = max(prok, -arr[k]+dp[i-1][k]);
            dp[i][j] = max(dp[i][j-1], prok + arr[j]);
        }
    }
    
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < arr.size(); j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    cout << "max profit will be: " << dp[k][arr.size()-1];
}

int main(){
    int k = 2;
    vector<int> price = {5,11,3,50,60,90};
    maxProfit(price, k);
    return 0;
}