#include<iostream>
using namespace std;
class faculty
{
    protected:
    string department;
    public:
    faculty(string n):department(n){
        cout<<"Base class 1 faculty is constructed"<<endl;
    }
    ~faculty()
    {
        cout<<"Base class 1 faculty is destructed"<<endl;
    }
};
class staff
{
    protected:
    int experience;
    public:
    staff(int e):experience(e){
        cout<<"Base class 2 staff is constructed"<<endl;
    }
    ~staff()
    {
        cout<<"Base class 2 staff is destructed"<<endl;
    }
};
class employee:public faculty,public staff{
    protected:
    string name;
    int age;
    int salary;
    int empId;
    public:
    employee(string n,int a,string d,int e,int s,int id):faculty(d),staff(e){
        name=n;
        age=a;
        salary=s;
        empId=id;
        cout<<"Derived class employee is constructed"<<endl;
    }
    ~employee()
    {
        cout<<"Derived class employee is destructed"<<endl;
    }
    void display()
    {
        cout<<"Name is "<<name<<endl;
        cout<<"Age is "<<age<<endl;
        cout<<"Salary is "<<salary<<endl;
        cout<<"Empid is "<<empId<<endl;
        cout<<"Department is "<<department<<endl;
        cout<<"Experience is "<<experience<<endl;
    }
};
int main()
{
    employee e("akfeu",25,"CSE",5,50000,1);
    e.display();
}
/*
MULTILEVEL


#include<iostream>
using namespace std;
class person
{
    protected:
    string name;
    int age;
    public:
       person(string n,int a){
        cout<<"Person (base) class is constructed"<<endl;
        name=n;
        age=a;
       };
       ~person()
       {
        cout<<"Person (base) class is destructed"<<endl;
       }
};
class employee:public person
{
    protected:
    int empId;
    public:

       employee(string n,int a,int e):person(n,a){
        cout<<"Employee (derived) class is constructed"<<endl;
        empId=e;
       };
       ~employee()
       {
        cout<<"Employee (derived) class is destructed"<<endl;
       }
       void details()
       {
        cout<<"Name of Employee :- "<<name<<endl;
        cout<<"Age of Employee :- "<<age<<endl;
        cout<<"Emp. Id of employee :- "<<empId<<endl;
       }
};
class Regemp:public employee
{
    protected:
    string type;
    string dep;
    int salary;
    public:

       Regemp(string n,int a,int e,string d,int sal):employee(n,a,e){
        cout<<"Regemp (derived) class is constructed"<<endl;
        type="Regular";
        salary=sal;
        dep=d;
       };
       ~Regemp()
       {
        cout<<"Regemp (derived) class is destructed"<<endl;
       }
       void details()
       {
        cout<<"Name of Employee :- "<<name<<endl;
        cout<<"Age of Employee :- "<<age<<endl;
        cout<<"Emp. Id of employee :- "<<empId<<endl;
        cout<<"Employee is a "<<type<<" employee"<<endl;
        cout<<"Department is "<<dep<<" department"<<endl;
       }
};
class Adhemp:public employee
{
    protected:
    string type;
    string dep;
    int salary;
    public:

       Adhemp(string n,int a,int e,string d,int sal):employee(n,a,e){
        cout<<"Adhemp (derived) class is constructed"<<endl;
        type="Adhoc";
        salary=sal;
        dep=d;
       };
       ~Adhemp()
       {
        cout<<"Adhemp (derived) class is destructed"<<endl;
       }
       void details()
       {
        cout<<"Name of Employee :- "<<name<<endl;
        cout<<"Age of Employee :- "<<age<<endl;
        cout<<"Emp. Id of employee :- "<<empId<<endl;
        cout<<"Employee is a "<<type<<" employee"<<endl;
        cout<<"Department is "<<dep<<" department"<<endl;
       }
};
int main()
{
    {
    Regemp E1("awaeva",23,1265,"CSE",10000);
    cout<<endl;
    E1.details();
    cout<<endl;
    }
    cout<<endl;
    {
    Adhemp E2("afdawd",34,1783,"ECE",15000);
    cout<<endl;
    E2.details();
    cout<<endl;
    }
    
}
*//*
FRIEND


#include<iostream>
using namespace std;
class F;
class M
{
    float m,cm;
    public:
      M(float m,float cm):m(m),cm(cm){};
      friend F conversion(M&m1);
      friend void display(M&m1)
      {
        float x=m1.m;
        float y=m1.cm;
        if(y>=100)
        {
            float y1=y/100;
            x+=y1;
            y=(y-y1)*100;
        }
        cout<<"distance is "<<x<<" meters and "<<y<<" centimeters";
        cout<<endl;
      };
};
class F
{
    float f,i;
    public:
      F(float f,float i):f(f),i(i){};
      friend M conversion(F&f1);
      friend void display(F&f1)
      {
        float x=f1.f;
        float y=f1.i;
        if(y>=12)
        {
            float y1=y/12;
            x+=y1;
            y=(y-y1)*12;
        }
        cout<<"distance is "<<x<<" feet and "<<y<<" inches";
        cout<<endl;
      };
};
F conversion(M&m1)
{
    cout<<"distance before conversion is :-"<<m1.m<<" meters and "<<m1.cm<<" cm "<<endl;
    float f=m1.m*(3.280);
    float i=m1.cm/(2.54)/12;
    return F(f,i);
}
M conversion(F&f1)
{
    cout<<"distance before conversion is :-"<<f1.f<<" feet and "<<f1.i<<" inches "<<endl;
    float m=f1.f/(3.280);
    float cm=f1.i*(2.54)*(12);
    return M(m,cm);
}
int main()
{
    M m1(10,10);
    F f2=conversion(m1);
    display(f2);
    M m3 = conversion(f2);
    display(m3);
    F f1(10,10);
    M m2=conversion(f1);
    display(m2);
}*/