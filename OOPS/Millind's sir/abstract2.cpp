#include <iostream> // io related functions
#include <string>  // strings manipulations
using namespace std; // to avoid conflicts with the names or identifiers - C++ 11 onwards
class employee {
   int EId;
   string Ename;
   double salary, basic, allowances;
   double computeSalary(int EId){
   salary = basic + allowances;
   return salary;
}
public:
void setSalary(int Id, string name,double b, double a)
{
EId =Id;  
//strcpy(Ename, name);
Ename=name;
basic =b;
allowances=a;
computeSalary(EId);
}  
void getsalary(){
  cout<<"EmpId = "<<EId<<"\tName = "<<Ename<<endl;

   cout<<"Employee Salary = "<<salary <<endl;
  }
  

};
int main()
{
   employee E1,E2; // two objects of class Employee 
   E1.setSalary(1, "Mahesh", 10000, 5000);
   E1.getsalary();    
   E2.setSalary(2, "Ram", 20000, 5000);
   E2.getsalary();    
}
