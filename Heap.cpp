#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void swap(int& a, int& b){
    a = a^b; b = a^b; a = a^b;
}

class MinHeap{
    int* arr;
    int size;
    int capacity;
    
    public:
    
    // Constructor
    MinHeap(int cap);
    
    // to heapify a subtree with the root at given index
    void MinHeapify(int i);
    
    // to get index of parent
    int parent(int i) { return (i - 1)/2; }
    
    // to get index of left child
    int left(int i) { return 2*i + 1; }
    
    // to get index of right child
    int right(int i) { return 2*i + 2; }
    
    // to remove and return the root value
    int extractMin();
    
    // Decrease key value of key stored at index i to new_val
    void decreaseKey(int i, int new_val);
    
    // Return min value stored in heap
    int getMin() { return arr[0]; }
    
    // Delete a key stored at index i
    void deleteKey(int i);
    
    // Insert a new key k
    void insertKey(int k);
};

MinHeap::MinHeap(int cap){
    size = 0;
    capacity = cap;
    arr = new int[cap];
}

void MinHeap::insertKey(int k){ // O(logn)
    if(size >= capacity) return;
    
    arr[++size - 1] = k;
    
    int i = size - 1;
    while(i!=0 && arr[i] < arr[parent(i)]){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int val){ // O(logn)
    arr[i] = val;
    while(i!=0 && arr[parent(i)] > arr[i]){
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

int MinHeap::extractMin(){ // O(logn)
    if(size <= 0){
        cout << "Heap is empty\n";
        return -1;
    }
    
    if(size == 1){
        size--;
        return arr[0];
    }
    
    int root = arr[0];
    arr[0] = arr[size - 1];
    size--;
    MinHeapify(0);
    
    return root;
}

void MinHeap::deleteKey(int i){
     // When deleting a node from a binary heap
     // we sometimes have to filter the replacement node
     // up the binary tree and sometimes down
     // example: http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/9-BinTree/heap-delete.html
     
     decreaseKey(i, INT_MIN);
     // so that it will go to top
     extractMin();
     // now we just have top heapify it i.e. settle it down
}

void MinHeap::MinHeapify(int i){
    // we have to swap with the smallest one
    // if it's already smaller than both then ok

    int l = left(i), r = right(i);
    int smallest_index = i;
    
    if(l < size && arr[l] < arr[smallest_index]){
        smallest_index = l;
    }
    if(r < size && arr[r] < arr[smallest_index]){
        smallest_index = r;
    }
    
    if(smallest_index != i){
       swap(arr[i], arr[smallest_index]);
       MinHeapify(smallest_index);
    } 
}

int main(){
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;  
}
