char youngAncestorCommon(Node* x, Node* y){
    map<Node*, bool> visited;
    while(x->ancestor){
        visited[x]=1;
        x = x->ancestor;
    }
    while(!visited[y]) y = y->ancestor;
    return y->data;
}  
// O(max (depth(x), depth(y))) space and time