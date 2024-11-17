#include <iostream>
using namespace std;
class Abstract_Demo{
private:
 /*The  data members are made private means they are hidden from 
  the outside world. 
 These data members are not accessible outside  the class */ 
  int  first;
  char second;
 
 public:
   void set_data (int n, char c) { // interface1
      first= n; second = c;
   } 
void get_data( ) {  // interface2
      cout<<"First is: " << first << endl;
      cout<<"Second is : " << second <<endl;
   	}
}; 

int main(){
   Abstract_Demo d;
   d.set_data(500, 'M');
   d.get_data();
   return 0;
}
