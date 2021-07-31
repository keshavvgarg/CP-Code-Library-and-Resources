#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

int const inf = 1e9;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int starting_node){
    vector<int> dis(adj.size() + 1, inf);
    dis[starting_node] = 0; // distance to the node itself is 0
    
    set<pair<int,int>> st;
    st.insert(mp(0, starting_node)); // store distance and node name
    
    // Note: visited array nhi bnana pd rha kyuki jab node set me sbse uper hota hai
    // tb uska distance sbse kam hota hai bche hue nodes me aur hm use visit krte hai
    // uske baad uska distance us se kam nhi ho skta to wo dubara nhi aata set me
    
    while(!st.empty()){
        pair<int,int> current_node = *(st.begin());
        st.erase(current_node);
        
        // from current node visit all the adjacent nodes and update the distance
        // then go to the next closest node and update distances from that node
        for(pair<int,int> edge: adj[current_node.second]){
            int node = edge.first;
            int weight = edge.second;
        
            // current node whose adjacent nodes we are exploring
            // is the node with minimum cost
        
            // determining weight to node from starting node
            
            // agr koi visited node hai toh vo dubara visit nhi hoga
            // kyuki uska distance toh least possible tha
            if(current_node.first + weight < dis[node]){
                st.erase(mp(dis[node], node)); // we have to update distance for node
                // agr nya node hua jo set me nhi hai tb bhi theek hai
                dis[node] = current_node.first + weight;
                st.insert(mp(dis[node], node));
            }
        }  
    }
    
    return dis;
}


int main(){
    int n, e, u, v, w, s;
    // Enter number of nodes
    // Enter number of edges
    
    cout << "Enter number of nodes: \n";
    cin >> n;
    
    cout << "Enter number of edges: \n";
    cin >> e;
    
    cout << "Enter the edges (u, v, w): \n";
    
    vector<vector<pair<int,int>>> adj(n + 1);
    
    // Enter the edges with their weights
    for(int i = 0; i < e; i++){
        cin >> u >> v >> w;
        adj[u].pb(mp(v,w));
        adj[v].pb(mp(u,w));
    }
    
    cout << "Enter the source node: \n";
    cin >> s;
    
    // adj: Edge information
    // s: kaunsa node source node hai
    vector<int> dis = dijkstra(adj, s);
    
    for(int i = 1; i <= n; i++){
        cout << i << ": " << dis[i] << "\n";
    }
    
    return 0;
}

/* TIME COMPLEXITY
overall time complexity is O(E+V)*O(LogV) which is O((E+V)*LogV) = O(ELogV) 
Log(V) for the set operations
*/


/*                      TEST CASE                  */
9
14
1 2 4
1 8 8
2 8 11
2 3 8
8 9 7
8 7 1
3 9 2
9 7 6
7 6 2
3 6 4
3 4 7
4 6 14
4 5 9
6 5 10
1
*/
    
    
    
    
    
 /* CSES Dijkstra code, directed graph, multiple edges */
    
#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
void dijkstra(vector<vector<pair<int,int>>>& adj, vector<int>& dis){
    set<pair<int,int>> st;
    dis[1] = 0;
    st.insert(make_pair(0, 1));
    
    while(!st.empty()){
        int closest_node = (*st.begin()).second;
        int dist = (*st.begin()).first;
        
        st.erase(st.begin());
        dis[closest_node] = dist;
        
        for(pair<int,int> ele: adj[closest_node]){
            if(dis[closest_node] + ele.second < dis[ele.first]){ // multiple edges handled
                st.erase(make_pair(dis[ele.first], ele.first)); // if not present no problem
                st.insert(make_pair(dis[closest_node] + ele.second, ele.first));
                dis[ele.first] = dis[closest_node] + ele.second;
            }
        }
    }
}
 
int32_t main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,int>>> adj(n + 1);
    vector<int> dis(n + 1, LONG_MAX);
    
    int u, v, x;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> x;
        adj[u].push_back(make_pair(v, x));
    }
    
    dijkstra(adj, dis);
    
    for(int i = 1; i <= n; i++){
        cout << dis[i] << " ";
    }
 
    cout << "\n";
    
    return 0;
}
