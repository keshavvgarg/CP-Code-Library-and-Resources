#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> g;
vector<bool> vis;

void dfs(int u){
    vis[u] = true;
    for(int ele: g[u]){
        if(!vis[ele]){
            dfs(ele);
        }
    }
}

void bfs(int u){
    queue<int> q;
    vis[u] = true;
    q.push(u);
    
    while(!q.empty()){
     int x = q.front();
     q.pop();
     cout<<x<<"\n";
     
    for(int ele: g[x]){
         if(!vis[ele]){
            vis[ele] = true;
            q.push(ele);
         }
     }
    }
}

int main(){ // 
}
