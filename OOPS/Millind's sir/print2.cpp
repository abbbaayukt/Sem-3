#include <iostream>
using namespace std; 

//void show (int i){
//cout << "I am interger" << i << endl;	
//}
//void show (char c)
//{ 
//cout << "I am character " <<c<< endl;	
//}

void show(float f)
{
 cout << "I am float " << f << endl;	
}

//void show(double f)
//{
	//cout << "I am double " <<f<< endl;	
//}

int main() 
{
 //case 2 - treated as int .. a match through promotion
  show('c'); // converted to int and displayed
  //show(97); 
 //show(14.5F);
 //show(12.5); // 12.5 double 64-bit format 
 
} 
