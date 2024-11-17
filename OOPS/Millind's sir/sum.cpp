#include <iostream>
using namespace std;
class Sum {
  public:
    int add(int num1, int num2){
      return num1 + num2;
    }
    int sub(int num1, int num2){
      return num1 - num2;
    }
   
    int mul(int num1, int num2);
       
    int div(int num1, int num2);
    
};

int Sum::mul(int num1, int num2)
    {
      return num1 * num2;
    }

int Sum::div(int num1, int num2){
      return num1 / num2;
    }
int main(void) {
   //Object of class Sum
   Sum obj; 

   //This will call the add function
   cout<<"The addition is" << obj.add(50, 60) << endl;

   //This will call the sub function
   cout<<" The substraction is"<<obj.sub(10, 20) <<endl;
   
   //This will call the mul function
   cout<<" The multiplication is  "<<obj.mul(50, 20) <<endl; 
   
   //This will call the div function
   cout<<" The division is  "<<obj.div(100, 10) <<endl; 
   
   return 0;
}
