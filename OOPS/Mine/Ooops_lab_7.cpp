#include<iostream>
using namespace std;
class complex{
    int real;
    int imag;
    public:
    complex(){
        int real = 0;
        int imag = 0;
    }
    complex(int r, int i){
        real = r;
        imag = i;
    }
    ~complex(){
        cout<<"Destructor called"<<endl;
        }
    complex operator+(complex &c){
        this->real = this->real + c.real;
        this->imag = this->imag + c.imag; 
        return *this;
    }
    complex operator++(){
        this->real = this->real + 1;
        return *this;
    }
    complex operator++(int n){
        this->real = this->real + 1;
        return *this;
    }
    complex operator--(){
        this->real = this->real - 1;
        return *this;
    }
    complex operator+(int a){
        this->real = this->real + a;
        return *this;
    }
     complex operator-(int a){
        this->real = this->real - a;
        return *this;
    }
    complex operator--(int n){
        this->real = this->real - 1;
        return *this;
    }
        friend  complex operator - (complex a, complex b);
        friend ostream & operator<<(ostream &out,complex &c);
        friend istream & operator>>(istream &in, complex &c);    
};

    complex operator - (complex a, complex b)
    {
        complex temp;
        temp.real = a.real - b.real;
        temp.imag = a.imag - b.imag;
        return temp;
    }
    ostream & operator<<(ostream &out,complex &c){
        out<<c.real<<"+"<<c.imag<<"i"<<endl;
        return out;
    }
    istream & operator>>(istream &in, complex &c){
        in>>c.real>>c.imag;
        return in;
    }

int main(){
    complex c1;
    complex c2(34,54);
    complex c3(5,9);
    complex c4;

    c1 = c2+ c3;
    cin>>c4;
    c4 = c4- c3;
    cout<<"initially complex c1 is : "<<c1<<endl;
    cout<<"initially complex c2 is : "<<c2<<endl;
    cout<<"initially complex c3 is : "<<c3<<endl;
    cout<<"initially complex c4 is : "<<c4<<endl;
    c1++;
    cout<<"c1++ is : "<<c1<<endl;
    ++c2;
    cout<<"++c2 is : "<<c2<<endl;
    c3--;
    cout<<"c3-- is : "<<c3<<endl;
    --c4;
    cout<<"--c4 is : "<<c4<<endl;
    c1 = c1+9;
    cout<<"c1+9 is : "<<c1<<endl;
    return 0;
}
