#include <iostream>
#include <utility>
using namespace std;

int main() {
    // pair - simple container defined in <utility> header 
    
    // pair - container consisting of two data elements
    // first element is referenced as first and second 
    // element as second
    
    // pairs is used to combined together two values
    // different in types pairs can be assigned, 
    // copied and compared.
    
    // The array of objects allocated in a map or 
    // hash_map are of type ‘pair’ by default in 
    // which all the ‘first’ elements are unique keys 
    // associated with their ‘second’ value objects.
    
    // To access the elements, we use variable name
    // followed by dot operator followed by the
    // keyword first or second.
    
    pair<int,char> p1;
    
    p1.first = 10;
    p1.second = 'K';
    
    cout<<p1.first<<"\n";
    cout<<p1.second<<"\n";
    
    // Output:
    // 10
    // K
    
    
    // Initialising a Pair
    
    // Method 1:
    // pair (data_type1, data_type2) Pair_name (value1, value2) ;
    
    pair<int,char> p2(10,'K');
    
    cout<<p2.first<<"\n";
    cout<<p2.second<<"\n";
    
    // Output:
    // 10
    // K
    
    // You can also use same data type
    
    pair<int,char> p3; // default pair
    cout<<p3.first<<"\n";
    cout<<p3.second<<"\n";
    
    // Output:
    // 0
    // 
    
    // Method 2:
    pair<int,char> p4;
    p4 = make_pair(10,'K');
    cout<<p4.first<<"\n";
    cout<<p4.second<<"\n";
    
    // Output:
    // 10
    // K
    
    // Random complex example
    
    pair<string,double> p5("KESHAV",21.01);
    cout<<p5.first<<"\n";
    cout<<p5.second<<"\n";
    
    // Output:
    // KESHAV
    // 21.01
    
    pair<string, char> PAIR2;
    cout << PAIR2.first<<"\n"; 
    cout << PAIR2.second<<"\n"; 
    
    // Output:
    // 
    // 
    
    cout<<"-------";
    
    // ***MEMBER FUNCTIONS***
    // 1. make_pair()
    
    // Pending:
    // https://www.geeksforgeeks.org/pair-in-cpp-stl/
    
    return 0;
}
