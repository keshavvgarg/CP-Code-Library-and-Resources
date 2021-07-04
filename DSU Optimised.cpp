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

/*
As mentioned before, if we combine both optimizations - path compression with union by rank - we will reach nearly constant time queries. 
It turns out, that the final amortized time complexity is O(α(n)), where α(n) is the inverse Ackermann function, which grows very slowly. 
In fact it grows so slowly, that it doesn't exceed 4 for all reasonable n (approximately n<10^600).

Amortized complexity is the total time per operation, evaluated over a sequence of multiple operations.
The idea is to guarantee the total time of the entire sequence, while allowing single operations to be much slower then the amortized time.
E.g. in our case a single call might take O(logn) in the worst case, but if we do m such calls back to back we will end up with an average time of O(α(n)).

We will also not present a proof for this time complexity, since it is quite long and complicated.

Also, it's worth mentioning that DSU with union by size / rank, but without path compression works in O(logn) time per query.
*/
