#include <iostream>
using namespace std; 

void show (double i)
{
	cout << "I am interger" << i << endl;	
}

void show (char c)
{ 
	cout << "I am character " <<c<< endl;	
}


int main() 
{
 
  show(97); // Ambiguous call
 
} 
