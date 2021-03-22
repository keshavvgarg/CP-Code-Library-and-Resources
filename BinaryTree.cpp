#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left; // can contain address to a Node data structure
    Node* right;
    
    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool lookup(Node* root, int val){ 
    if(root == nullptr){ // if node is last
        return false;
    }
    else if(root->data == val){ // if node has data
        return true;
    }
    else{ // if node is not last and doesn't have data then check in its left and right subtrees if they have it.
      if(lookup(root->left, val)){
          return true;
      }
      else if(lookup(root->right, val)){
          return true;
      }
      else{
          return false;
      }
    
    // return max(lookup(root->right, val), lookup(root->left, val));
    // Why not this code think about it?
    }
}

// http://cslibrary.stanford.edu/110/BinaryTrees.html

bool lookup_bst(Node* root, int target){
    if(root == nullptr){
        return false;
    }
    else if(root->data == target){
        return true;
    }
    else if(root->data >= target){
        return lookup_bst(root->left, target);
    }
    else{
        return lookup_bst(root->right, target);
    }
}


int main(){
    // Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    
    // cout<<lookup(root, 1)<<"\n";
    // cout<<lookup(root, 2)<<"\n";
    // cout<<lookup(root, 3)<<'\n';
    // cout<<lookup(root, 4)<<"\n";
    // cout<<lookup(root, 5)<<"\n";
    // cout<<lookup_bst(root,1)<<"\n";
    // cout<<lookup_bst(root,4)<<"\n";
    
    Node* root = new Node(3);
    insert_bst(*root, 2);
    insert_bst(*root, 3);
    insert_bst(*root, 4);
    
    cout<<root->data<<"\n";
    // cout<<root->left->data<<"\n";
    // cout<<root->left->right->data<<"\n";
    // cout<<root->right->data<<"\n";
    return 0;
}
