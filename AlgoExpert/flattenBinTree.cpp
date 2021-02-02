#include<bits/stdc++.h>
using namespace std;

void FTHelper(Node* cur, Node* prev){
    if(cur->left) FTHelper(cur->left, prev);
    cur->left = prev;
    if(prev) prev->right = cur;
    prev = cur;
    if(cur->right) FTHelper(cur->right, prev);
}

void flattenTree(Node* node){
    Node* prev = NULL;
    FTHelper(root, prev);
}

// O(n) time
// O(1) space