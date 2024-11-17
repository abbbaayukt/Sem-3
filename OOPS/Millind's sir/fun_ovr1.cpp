#include <iostream>
using namespace std;
int square (int y)  // signature - function prototype without return type 
{
return y *y;
}

double square (double y) 
{
return y *y;}

int main() 
{
//cout << square(10) << endl;
cout << square(10.5F) << endl; // float is promoted here to double
cout << square(12) << endl;
}
