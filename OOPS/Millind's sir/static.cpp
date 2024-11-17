#include <iostream>
using namespace std;
class shared {
public:
static int a; // declare a
int b;

void set(int i, int j) 
{
a=i; b=j;
//cout << "Address of this pointer is" <<&this;
}
void show();
} ;
int shared::a; // define a
void shared::show() {
cout << "This is static a: " <<this->a<<endl;
cout << &a;
cout << "\nThis is non-static b: " <<this->b<<endl;
cout << &b;
cout << "\n";
}

int main() {
shared x, y;
x.set(1, 1); // set a to 1
x.show();

y.set(2, 2); // change a to 2
y.show();
x.show(); /* Here, a has been changed for both x and y because a is shared by both objects. */
//this->a =12;
//cout<<this->a;
return 0; 
} 

