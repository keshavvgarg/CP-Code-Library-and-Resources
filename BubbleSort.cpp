#include<bits/stdc++.h>
using namespace std;

// Revise Bubble Sort:
// https://www.youtube.com/watch?v=Jdtq5uKz-w4

int main(){
    // Bubble sort - Non decreasing order 
   
    int arr[] = {2,3,4,5,2,3,7,9}; // declaration and initialization
    
    int n = sizeof(arr)/sizeof(arr[0]); // size of whole array in bytes / size of one array element in bytes = number of elements in array
    
    for(int i=1;i<=n-1;i++){ // To run this loop n-1 times (In each iteration largest element bubbles up), so we need only n-1 items to bubble up
    int flag = 0;
    // compare for n-2 index at max i.e (n-1)th element (0 based indexing) because we can't compare last element with anything, in fact we can go
    // one index lesser for every next iteration because one outer loop iteration bubbles up the largest element from the unsorted part of the array
        for(int j=0;j<n-i;j++){ 
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]); // swap can take any variables (int, string etc). In fact, it operates on addresses i.e. no problem for vectors
                flag = 1;
            }
        }
        if(flag==0){ // if there's no swap in one complete loop iteration of the unsorted array that means the array is sorted and we can break out
            break;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
