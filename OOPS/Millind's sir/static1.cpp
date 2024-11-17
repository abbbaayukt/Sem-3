#include <iostream>
using namespace std;
class shared {
//public:
static int a;
} ;
int shared::a; // define a
int main( ) {
// initialize ‘a’ before creating any objects
shared::a = 99;
cout << "This is initial value of a: " << shared::a <<endl;
cout << "\n";
shared x;
cout << "This is x.a: " << x.a <<endl;
shared y;
x.a++;
cout << "This is y.a: " << y.a;
return 0;
}


