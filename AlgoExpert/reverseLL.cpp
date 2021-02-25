#include<bits/stdc++.h>
using namespace std;

void reverseLL(Node* root){
    root = reverseHelper(root, NULL);
}

// O(n) time and space
Node* reverseHelper(Node* cur, Node* prev){
    if(cur->next){
        Node* temp = cur->next;
        cur->next = prev;
        return reverseHelper(temp, cur);
    }
    cur->next = prev;
    return cur;
}

// O(1) space
// O(n) time
Node* reverseHelperIter(Node* cur){
    Node* prev = NULL;
    Node* next = cur->next;
    while(next){
        cur->next = prev;
        prev = cur;
        cur = next;
        next = cur->next;
    }
    return cur;
}