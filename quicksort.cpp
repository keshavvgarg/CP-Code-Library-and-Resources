#include<iostream>
using namespace std;

int partition(int arr[], int beg, int end){
    int pivot_element = arr[end];
    int pivot_index = beg;
    
    for(int i=beg;i<=end;i++){
        if(arr[i] <= pivot_element){
            swap(arr[i],arr[pivot_index]);
            pivot_index++;
        }   
    }
    
    pivot_index--;
    return pivot_index;
}


void quickSort(int arr[], int beg, int end){
    if(beg >= end){
        return;
    }
    
    int pivot_index = partition(arr,beg,end);
    quickSort(arr,beg,pivot_index-1);
    quickSort(arr,pivot_index+1,end);
}

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    quickSort(arr,0,n-1);
    
    // In-place sorting algorithm
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}












-----------------------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int>& arr, int st, int ed){
    if(st > ed){
        return;
    }
    
    int p = 0;
    int pivotelement = arr[ed];
    int i = 0;
    
    while(i <= ed){
        if(arr[i] <= pivotelement){
            swap(arr[i],arr[p]);
            p++;
        }
        i++;
    }
    
    int pivot_index = p-1;
    
    quickSort(arr,st,pivot_index-1);
    quickSort(arr,pivot_index+1,ed);
}

int main(){
    vector<int> arr = {5,4,3,2};
    quickSort(arr,0,arr.size()-1);
    for(int ele: arr){
        cout<<ele<<" ";
    }
    cout<<"\n";
    return 0;
}
