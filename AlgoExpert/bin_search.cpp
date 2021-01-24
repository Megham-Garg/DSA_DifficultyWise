bool binary_search(vector<int>* arr, int target){
    int start = 0;
    int end = arr.size();
    int mid = (end - start)/2 + start;
    while(mid >= 0 and mid <= end){
        if(arr[mid] == target) return true;
        else if(arr[mid] > target) end = mid - 1;
        else start = mid + 1;
        mid = (start+mid)/2;
    }
    return false;
}
// o(log(n)) time
// o(1) space

// In recursive soln
// space O(log(n)) due to recursion stack