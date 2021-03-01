#include<bits/stdc++.h>
using namespace std;

// hashset with a doubly linked list

struct Node{
    Node* next;
    Node* prev;
    int value;
    char key;
};

class DLL{
    Node* head,tail;
public:
    void shiftToEnd(){}
    void remove_front(){}
    void append(){}
    void get_head(){}
};

// O(1) space
// O(1) time

class LRU_Cache{
    DLL<char> cache;
    unordered_map<char, Node*> hash;
public:
    void insert(char key, int value){
        if(hash.size() >= 3){
            if(hash.find(key) != hash.end()){
                cache.shiftToEnd(key);
            }
            else{
                char key = cache.remove_front();
                hash.erase(key);
            }
        }
        hash[key] = cache.append(key, value);
    }

    unordered_map<char, int> get_LRUData(){
        unordered_map<char, int> res;
        if(cache.size() > 0){
            Node* front = cache.get_head();
            res[front->key] = front->value;
        }
        return res;
    }

    int get_value(char key){
        Node* target;
        if(cache.size() > 0){
            if(hash.find(key) != hash.end()) target = hash[key];
            else return INT_MIN;
            cache.shiftToEnd(target);
        }
        else{
            return INT_MIN;
        }
        return target->value;
    }
};