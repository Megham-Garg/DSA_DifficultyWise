#include<bits/stdc++.h>
using namespace std;

void moveElementToEnd(vector<int> &arr, int target){
    int left = 0;
    int right = arr.size()-1;
    while(left < right){
        if(arr[right] == target) right--;
        else if(arr[left] != target) left++;
        else{
            swap(arr[left++], arr[right--]);
        }
    }
}

int main(){
    vector<int> arr;
    arr.assign({2,1,2,2,2,3,4,1,2});
    moveElementToEnd(arr, 2);
    for(auto num : arr) cout << num << " ";
    cout << endl;
    return 0;
}