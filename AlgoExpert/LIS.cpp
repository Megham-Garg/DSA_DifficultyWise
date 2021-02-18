#include<bits/stdc++.h>
using namespace std;

void LIS(vector<int>, int);

int main(){
    vector<int> arr = {5,7,-24,12,10,2,3,12,5,6,35};
    LIS(arr, arr.size());
    return 0;
}

// O(n) space
// O(n^2) time
void LIS(vector<int> arr, int n){
    if(!n) return;
    if(n == 1) {cout << "longest increasing subsequence : " << arr[0]; return;}
    vector<int> length(n,1);
    vector<int> prev(n,-1);
    int ind = 0;
    for(int i = 1; i < n; i++){
        for(int j = i-1; j > -1; j--){
            if(arr[i] > arr[j] && length[i] < length[j] + 1) {
                length[i] = 1 + length[j];
                prev[i] = j;
            }
        }
        if(length[ind] < length[i]) ind = i;
    }
    
    for(auto len : length) cout << len << " ";
    cout << endl;
    
    cout << "length of max inc subseq is: " << length[ind] << "\n";
    
    while(ind!=-1){
        cout << arr[ind] << " ";
        ind = prev[ind];
    }return;
}