#include <iostream>
using namespace std;

double square(double y) {
	cout<<"double square"<<endl;
return y *y;
} 

int square (int y) { 
cout<<"int square"<<endl;
return y *y; 
}

int main( ) {
	int x;
	double y;
	cout<<"Enter the values"<<endl;
	cin>>x;
	cin>>y;
	cout<<"x before square is"<<x<<endl;
	cout<<"y before square is"<<y<<endl;
   x= square(x);
   cout<<"x after square is"<<x<<endl;
   y= square(y);
   cout<<"y after square is"<<y<<endl;
//cout << square(10) << endl;
//cout << square(10.25) << endl;
}


