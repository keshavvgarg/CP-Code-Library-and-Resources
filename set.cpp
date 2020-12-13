#include<iostream>
#include<set>
#include<iterator>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(19);
    s.insert(32);
    
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();){
        cout<<*it<<" "; 
        advance(it,1); // can make it advance as you want
    }
    
    cout<<*next(s.begin(),2);
    // prints 32
    
    cout<<*prev(s.end(),1);
    // prints 32
    
    // same as
    for(it = s.begin();it!=s.end();it++){
        cout<<*it<<" ";
    }
    
    // s.size() 
    // s.max_size()
    // s.empty()
    // s.insert()
    
    // set in decreasing order
    set<int, greater<int>> s1;
    // iterator for this
    set<int,greater<int>>::iterator it
    
    
    // assigning elements from set s1 to s2
    set<int> s2(s1.begin(),s1.end())
    
    // remove all elements less than 20 from s2
    s2.erase(s2.begin(),s2.find(20))
    
    // remove element with value 1020
    s2.erase(1020); // returns 1 if removed
    
    // upperbound and lowerbound
    // equal_range returns both above pointers
    
    // lb >= x
    // up > x
    
    // lowerbound: returns a pointer to first array
    // element whose value is at least x
    
    // upperbound: returns a pointer to the first array
    // element whose value is larger than x.
    
    // The functions assume that the array is sorted. If there is no such element,
    // the pointer points to the element after the last array element.
    
    int k = lower_bound(array,array+n,x)-array;
    if (k < n && array[k] == x) {
        // x found at index k
    }
    
    // the following code counts the number of elements whose value is x:
    
    auto a = lower_bound(array, array+n, x); // O(n)
    auto b = upper_bound(array, array+n, x); // O(n)
    cout << b-a << "\n";
    
    // for set don't use lower_bound(st.begin(),st.end(),x) // works in O(n)
    // use st.lower_bound(x); // works in O(logn)
    
    // Using equal_range, the code becomes shorter:
    auto r = equal_range(array, array+n, x);
    cout << r.second-r.first << "\n";
    

    return 0;
}
