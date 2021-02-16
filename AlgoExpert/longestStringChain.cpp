#include <bits/stdc++.h>
using namespace std;

// O(n) space
// O(n*max(stringLength^2)) time
int longestChain(string ele, unordered_map<string, int>& memo){
    string temp;
    for(int i =0; i < ele.size(); i++){
        temp = ele;
        temp.erase(i+temp.begin());
        if(memo.find(temp) != memo.end() && memo[temp]==1) {
            memo[temp] = longestChain(temp, memo);
        }
        if(memo.find(temp) != memo.end()) memo[ele] = max(memo[ele], memo[temp]+1);
    }
    return memo[ele];
}

int main()
{
    vector<string> strSet = {"abde", "abc", "abd", "abcde", "ade", "ae", "labde", "abcdef"};
    
    unordered_map<string, int> memo; 
    for(auto ele : strSet) memo[ele] = 1;
    
    int maxLengthChain = 1;
    for(auto ele : strSet) if(memo[ele]==1) maxLengthChain = max(longestChain(ele, memo), maxLengthChain);
    
    for(auto ele : strSet) cout << ele << " : " << memo[ele] << "\n";
    
    cout << "\nmax chain length = " << maxLengthChain << "\n";
    return 0;
}
