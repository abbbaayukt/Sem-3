#include <iostream>
using namespace std; 

//void show (int i)
//{
//	cout << "I am interger" << i << endl;	
//}

void show (char c)
{ 
	cout << "I am character " <<c<< endl;	
}

//void show(float f)
//{
//cout << "I am float " << f << endl;	
//}

int main() 
{
 //case 3 - treated as char .. a match through standard C++ mechanism
  //show(97); // int to char
  show(97); // float to int
 
} 
