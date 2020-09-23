#include<iostream>
using namespace std;

int main(){

int x = 127;

for(int i=31;i>=0;i--){
  if((x&(1<<i))!=0) { // If ith bit is 1
   cout<<"1";
  }
  else{ // If ith bit is zero
  cout<<"0";
  }
}

return 0;
}
