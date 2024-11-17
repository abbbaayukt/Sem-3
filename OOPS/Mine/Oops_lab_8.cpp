#include<iostream>
using namespace std;
# define Max 120

template<class T> class stack{
    public:
    int size = 10;
    T arr[size];
    int top =-1;
    stack(){
        int k = 0;
    }
    void push(T a){
        if(top == Max)
        cout<<"Stack is full."<<endl;
        else{
            top++;
            arr[top]=a;
        }
    }
    void pop(){
        if(top==-1)
        cout<<"Stack is empty>"<<endl;
        else{
            cout<<"pop number is : "<<arr[top]<<endl;
            top--;
        }
    }
    void view(){
        cout<<"Stack is : "<<endl;
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
};
   

class employee{
    public:
    string name;
    int age;
    employee(){
        cout<<"construtor"<<endl;
    }
    employee(string n,int a){
        this->name=n;
        this->age=a;
        cout<<"We are in employee constructor"<<endl;
    }
    friend ostream & operator<<(ostream &out,employee &c){
        out<<"Name is :"<<c.name<<endl;
        out<<"Age is :"<<c.age<<endl;
        return out;
    }
     friend istream & operator>>(istream &in, employee &c){
        in>>c.name>>c.age;
        return in;
    }
    ~employee(){
        cout<<"We are in emp;loyee destructor"<<endl;
    }
};

int main(){
    employee e1("Rahul",25);
    employee e2("ashish",19);
    employee e3("aditya",18);
    employee e4("prince",21);
    stack<employee> e;
    e.push(e1);
    e.push(e2);
    e.push(e4);
    e.push(e3);
    e.view();
    e.pop();
    e.pop();
    e.view();

    stack<int> i;
    i.push(10);
    i.push(85);
    i.push(145);
    i.push(88);
    i.push(165);
    i.push(258);
    i.view();
    i.pop();
    i.pop();
    i.push(1478);
    i.view();

    stack<char> c;
    c.push('a');
    c.push('b');
    c.push('d');
    c.push('e');
    c.push('c');
    c.push('h');
    c.view();
    c.pop();
    c.pop();
    c.pop();
    c.view();
    return 0;
}