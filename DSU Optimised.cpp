// Ref: https://cp-algorithms.com/data_structures/disjoint_set_union.html

int find_set(int v){ // with Path compression optimization
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

/*
The simple implementation does what was intended: first find the representative of the set (root vertex), and then in the process of stack
unwinding the visited nodes are attached directly to the representative.

This simple modification of the operation already achieves the time complexity O(logn) per call on average. 
There is a second modification, that will make it even faster.
*/

void make_set(int v){ // with union by rank optimization
    parent[v] = v;
    rank[v] = 0;
}

void union_sets(int a, int b){ // with union by rank optimization
    a = find_set(a);
    b = find_set(b);
    
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a; // b me vo node hai jiski rank kam hai, a ko parent bna diya
  
        if (rank[a] == rank[b]) rank[a]++;
    }
}
