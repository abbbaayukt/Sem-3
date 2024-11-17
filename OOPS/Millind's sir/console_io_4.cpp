#include <iostream>
#include <string>

using namespace std;
int main() {
//auto x=1; 
float f;
double d; 
//char str [80];
string str = " "; 
//cout << "Enter two floating point numbers: ";
cout << "Enter a string" << endl;
//cin >> str; 
getline(cin, str);
cout << "enter the float and double: ";
cin >> f >> d;
//cin >> f ;
cout << x << f << " " << d << " " << str;
return 0;
} 

