#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

// O(log(n)) time
// O(1) space
int findClosestInBST(Node* node, int target){
    if(!node) return INT_MAX;
    if(node->data == target) return target;
    Node* next = NULL;

    if(node->left && node->data > target) next = node->left;
    else if(node->right && node->data < target) next = node->right;
    else return node->data;
    
    int fut = findClosestInBST(next, target);
    return (abs(node->data - target) < abs(fut - target))?node->data:fut;
}

int main(){
    return 0;
}