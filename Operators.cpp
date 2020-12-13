#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define p(a) cout<<sizeof(a)<<"\n";

int main(){
    // Operators in c++
    
    //   1: sizeof()
    
    // sizeof: return the size of variable
    int a = 0;
    cout<<sizeof(a)<<"\n";
    
    char c = 'z';
    cout<<sizeof(c)<<"\n";
    
    char char_arr[10];
    cout<<sizeof(char_arr)<<"\n";
    // prints 10
    
    // bool: 1 byte
    
    // char: 1 byte
    
    // short: 2 bytes
    // int: 4 bytes
    // long: 8 bytes
    // long long: 8 bytes
    
    // float: 4 bytes
    // double: 8 bytes
    
    int arr[5];
    cout<<sizeof(arr)<<"\n";
    // outputs 20: size of int(4)*(5)Number of elements

    string s = "monkey";
    cout<<sizeof(s)<<"\n";
    // When applied to a class type, the result is the size of 
    // an object of that class plus any additional padding required 
    // to place such object in an array.
    // prints 32 (structural size of the class string)(which is generally a pointer)
    // This system has 32 byte pointer some system might have 8 or 4 byte pointer
    
    string str[10];
    cout<<sizeof(str)<<"\n";
    // prints 320
    
    // std::string expands dynamically to meet any required size
    cout<<s.max_size()<<"\n"; // true maximum size
    cout<<s.capacity()<<"\n"; // max_capacity before resizing
    cout<<s.size()<<"\n"; // how many elements it currently holds
    cout<<s.length()<<"\n"; // same
    
    // Pointer can be 64 bit, 32 bit or something else depending
    // on the system architecture.
    
    // 1 byte != 8 bit for all system architectures. (It can be more than that)
    
    // Ref: https://en.cppreference.com/w/cpp/language/sizeof
    
    // Pro tip: Sort your data members in descending order of there sizes 
    // to avoid padding costs (in structure or classes)
    
    // Ref: https://www.geeksforgeeks.org/is-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member/
    
    // Pro tip: always include <string> header if you want to work with strings
    // in some implementations it's included in the <iostream> header but in others it
    // does not.
    
    // Ref: https://stackoverflow.com/questions/9539650/why-does-omission-of-include-string-only-sometimes-cause-compilation-failur
    // Ref: https://stackoverflow.com/questions/3629301/c-sizeof-string
    
    // 2: Condition? X: Y
    // if condition true implement X else implement Y
    
    1>2?cout<<1<<"\n": cout<<2<<"\n";
    // prints 2
    
    int i = 1, j = 2;
    cout << ( i > j ? i : j ) << " is greater." << endl;


    // 3: .(dot) and ->(arrow) operator
    // used to reference individual members of classes, structs and unions.
    
    // The dot operator is applied to the actual object.
    // The arrow operator is used with a pointer to an object. 
    // To access members of a structure, use the dot operator. 
    // To access members of a structure through a pointer, use the arrow operator.
    
    // 4: Pointer Operator(&): will give actual address of the variable
    
    // 5: Pointer Operator(*): is a pointer to a variable
    
    int* p; // p is a pointer to an integer variable
    int x = 20;
    p = &x; // address of x is in p
    cout<<p<<"\n";
    
    // 6: Comma operator(,): Evaluates all the expressions and then set the value equal to 
    // rightmost expression
    // Ref: https://www.tutorialspoint.com/cplusplus/cpp_comma_operator.htm
    
    
    // 7: Casting operators: forcefully converting one data type to another
    double db = 10.23;
    int y = (int)db;
    cout<<y<<"\n";
    // y stores 10
    
    // have to learn precedence and their associativity also
    // ref: https://www.tutorialspoint.com/cplusplus/cpp_operators.htm
    
    return 0;
}
