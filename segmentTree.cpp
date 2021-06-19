#include<iostream>
#include<vector>
using namespace std;

#define MAXN 100000

vector<int> segtree(4*MAXN);

void buildtree(vector<int>& vect, int st, int ed, int v){
    // base case :: if we have to find sum of index range [i,i]
    if(st==ed){
        segtree[v] = vect[st];
        return;
    }
    
    // else first build tree for left and right subtree then sum their values
    int mid = st+ (ed - st)/2;
    buildtree(vect, st, mid, 2*v);
    buildtree(vect, mid+1, ed, 2*v+1);
    
    segtree[v] = segtree[2*v] + segtree[2*v+1];
}

void update(int v, int st, int ed, int pos, int new_val){
    
        if(st==ed){ // It'll only be st==ed when we reach to be updated index
            segtree[v] = new_val;
            return;
        }
        
        int mid = st+ (ed - st)/2;
        if(pos<=mid){
            update(2*v,st,mid,pos,new_val);
        }
        else{
            update(2*v+1,mid+1,ed,pos,new_val);
        }
        
        segtree[v] = segtree[2*v] + segtree[2*v+1];
}

int sum(int u, int v, int st, int ed, int vertex){
    // u,v: range under consideration
    // st,ed: query range
    
    // Case1: If both range are same
    if(u==st && v==ed){
        return segtree[vertex];
    }
    
    int mid = u + (v - u)/2;
    
    // Case2: If range completely lies inside any one of the two ranges
    if(u<=st && ed<=mid){
        return sum(u,mid,st,ed,2*vertex);
    }
    if(mid+1 <= st && ed <= v){
        return sum(mid+1,v,st,ed,2*vertex+1);
    }
    
    // Case3: If it lies inside both
    int a = sum(u,mid,st,mid,2*vertex);
    int b = sum(mid+1,v,mid+1,ed,2*vertex+1);
    return a+b;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1); // 1 based indexing
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    buildtree(arr,1,n,1);

    // start_vertex, complete range, index_to_be_updated, value
    update(1,1,n,6,0);
    
    // Outputs segment tree
    // cout<<"\n";
    // for(int i=0;i<4*n;i++){
    //     cout<<segtree[i]<<" ";
    // }    
    cout<<"\n";
    
    // full range, start and end index of query, first index
    cout<<sum(1,n,2,5,1);
}
