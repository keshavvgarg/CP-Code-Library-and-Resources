#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define print(a) for(auto ele: a){cout<<ele<<" ";} cout<<"\n";

int main(){
    // Sorting 
    
    // Sorting: Vectors
    
    vector<int> v = {4,2,5,3,5,8,3};
    vector<int> a(v.begin(), v.end());
    // to allot in reverse order
    vector<int> b(v.rbegin(), v.rend());
    
    print(a);
    // to sort in increasing order:
    sort(a.begin(),a.end());
    print(a);
    
    print(b);
    // to sort in decreasing order:
    // M1: 
    sort(b.begin(),b.end(), greater<int>());
    // M2:
    sort(b.rbegin(),b.rend());
    print(b);
    
    // Sorting: array
    int n = 7;
    int arr[] = {4,2,5,3,5,8,3};
    
    // Sort from index 1 (2nd element) (leave one element)
    sort(arr+1,arr+n);
    print(arr); // {2,3,3,5,5,8}
    
    // sort [1,3] (2nd, 3rd and 4th element) 
    sort(arr+1,arr+4);
    print(arr); // {2,3,5}
    
    // Sort in ascending order
    sort(arr,arr+n);
    print(arr);
    
    // sort in descending order
    sort(arr,arr+n,greater<int>());
    print(arr);
    
    // Sorting: Strings
    
    string s = "monkey";
    // sort string in alphabetical order
    sort(s.begin(),s.end());
    print(s);
    
    // M1: sort in reverse order
    sort(s.begin(),s.end(),greater<int>());
    print(s);
    
    // M2: Sort in reverse order 
    sort(s.rbegin(),s.rend());
    print(s);
    
}
