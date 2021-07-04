// This implementation is not efficient. It might take O(n) to look for parent
// So we'll optimise this using two optimisations
// 1. Path Compression optimization: can make union operations O(logn) on avg
// 2. Union by Rank: can make union operations O(logn) on avg
// Together they make union operations constant time O(1) amortized meaning it can perform O(logn) in
// worst case but on avg it will perform O(1)

void make_set(int v){
    // usko khudka parent bna do
    parent[v] = v;
}

int find_set(int v){ // representative dhundho

    // agr uska koi parent nhi hai toh ok
    if(v == parent[v]) return v;
    
    // otherwise uske parent ka parent dhundho
    return find_set(parent[v]);
}


void union_set(int a, int b){ // do set ko sath me jodna
    // agr same set me nhi hai
    // toh ek ke parent ko dusre ka parent bna do
    
    a = find_set(a);
    b = find_set(b);
    
    if(a != b) parent[b] = a;
}

