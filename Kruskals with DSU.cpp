/*
Connected components in a graph
This is one of the obvious applications of DSU.

Formally the problem is defined in the following way: Initially we have an empty graph. 
We have to add vertices and undirected edges, and answer queries of the form (a,b) - "are the vertices a and b in the same connected component of the graph?"

Here we can directly apply the data structure, and get a solution that handles an addition of a vertex or an edge and a query in nearly constant time on average.

This application is quite important, because nearly the same problem appears in Kruskal's algorithm for finding a minimum spanning tree. 
Using DSU we can improve the O(mlogn+n^2) complexity to O(mlogn).
*/


/*
Ref1: https://cp-algorithms.com/graph/mst_kruskal.html
Ref2: https://cp-algorithms.com/graph/mst_kruskal_with_dsu.html

It has the proof and the properties of MST

*/

vector<int> parent, rank;

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;

int cost = 0;
vector<Edge> result;
parent.resize(n);
rank.resize(n);
for (int i = 0; i < n; i++)
    make_set(i);

sort(edges.begin(), edges.end());

for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
        cost += e.weight;
        result.push_back(e);
        union_sets(e.u, e.v);
    }
}

// Notice: since the MST will contain exactly N−1 edges, we can stop the for loop once we found that many.
