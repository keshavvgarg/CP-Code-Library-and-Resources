/*
Connected components in a graph
This is one of the obvious applications of DSU.

Formally the problem is defined in the following way: Initially we have an empty graph. 
We have to add vertices and undirected edges, and answer queries of the form (a,b) - "are the vertices a and b in the same connected component of the graph?"

Here we can directly apply the data structure, and get a solution that handles an addition of a vertex or an edge and a query in nearly constant time on average.

This application is quite important, because nearly the same problem appears in Kruskal's algorithm for finding a minimum spanning tree. 
Using DSU we can improve the O(mlogn+n^2) complexity to O(mlogn).
*/
