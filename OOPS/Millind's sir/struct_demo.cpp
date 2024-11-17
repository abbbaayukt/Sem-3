#include <iostream>
using namespace std;
struct X {
 int a;
 int b;
 void display();
};
//class X obj_X;

struct X obj_X;

void X :: display()
{
	
	cout << "Here are a and b: " << obj_X.a << " " << obj_X.b << endl;
}

int main() {
 
  
  obj_X.a = 0;
  obj_X.b = 1;
  
  obj_X.display();
  
  
  //cout << "Here are a and b: " << obj_X.a << " " << obj_X.b << endl;
}
