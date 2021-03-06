#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define pb push_back

// O(1) space
// O( nlogn + mlogm )
int smallestDifference(vector<int> arr1, vector<int> arr2){
    sort(arr1.begin(), arr1.end());
    sort(arr1.begin(), arr1.end());
    int ind1 = 0, ind2 = 0;
    int smallestDiff = INT_MAX;
    int ans1 = arr1[0],ans2 = arr2[0];
    while(ind1 < arr1.size() && ind2 < arr2.size()){
        int n1 = arr1[ind1];
        int n2 = arr2[ind2];
        int curDiff = abs(n1-n2);
        if(n1 > n2) ind2++;
        else if(n1 < n2) ind1++;
        else {
            cout << n1 << " " << n2 << "\n";
            return 0;
        }
        if(curDiff < smallestDiff) {
            smallestDiff = curDiff;
            ans1 = n1;
            ans2 = n2;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    return smallestDiff;
}

int main(){
    vector<int> arr1,arr2;
    arr1.pb(-1);
    arr1.pb(5);
    arr1.pb(10);
    arr1.pb(20);
    arr1.pb(28);
    arr1.pb(3);
    arr2.pb(26);
    arr2.pb(134);
    arr2.pb(135);
    arr2.pb(15);
    arr2.pb(17);
    cout << smallestDifference(arr1,arr2);
    return 0;
}