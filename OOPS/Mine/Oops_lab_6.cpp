#include<iostream>
using namespace std;
class person{
    public:
    string name;
    int age;
    person(string n,int age){
        this->name=n;
        this->age = age;
        cout<<"we are in person's constructor"<<endl;
    }
    ~person(){
        cout<<"we are in person's destructor"<<endl;
    }
    void display(){
        cout<<"name is "<<name<<endl;
        cout<<"age is "<<age<<endl;
    }
};
class employee : public person{
    public:
    string id;
    string dept;
    string phone;
    int leave;
    employee(string n,int age,string id,string dept,string phone,int leave): person(n,age){
        this->id=id;
        this->dept = dept;
        this->phone=phone;
        this->leave= leave;
        cout<<"We are in employee constructor"<<endl;
    }
    ~employee(){
        cout<<"We are in emp;loyee destructor"<<endl;
    }
    void display(){
        person::display();
        cout<<"Id is : "<<'id'<<endl;
        cout<<"department is : "<<'dept'<<endl;
        cout<<"phone no. is : "<<'phone'<<endl;
        cout<<"total leave is : "<< leave <<endl;
    }
};
class adhoc : public employee{
    public:
    int salary;
    int tenure;
    int leave_taken;
    adhoc(string n,int age,string id,string dept,string phone,int leave,int sal,int tenure,int taken) : employee(n,age,id,dept,phone,leave){
        salary=sal;
        this->tenure = tenure;
        leave_taken= taken;
        cout<<"We are in adhoc constructor"<<endl;
    }
    ~adhoc(){
        cout<<"We are in adhoc destructor"<<endl;
    }
    float compute_salary(int sal,int taken,int leave){
        float total = 0;
        if(taken>leave){
        total = (float)(sal-(float)((sal/260)*(taken-leave)));}
        else {
        total = sal;}
        cout<<"Adhoc compute-salary. "<<endl;
        return total;
    }
    void display(){
        employee::display();
        cout<<"tenure is : "<<tenure<<"year"<<endl;
        cout<<"leave taken is : "<<leave_taken<<endl;
        float sal = this->compute_salary(salary,leave_taken,leave);
        cout<<"Adhoc employee salary after all leaves taken is : "<<sal<<endl;
    }
};
class regular : public employee{
    public:
    int salary;
    int leave_taken;
    regular(string n,int age,string id,string dept,string phone,int leave,int sal,int taken) : employee(n,age,id,dept,phone,leave){
        salary=sal;
        leave_taken= taken;
        cout<<"We are in regular constructor"<<endl;
    }
    ~regular(){
        cout<<"We are in regular destructor"<<endl;
    }
    float compute_salary(int sal,int taken , int leave){
        float total = 0;
        if(taken>leave){
        total = (float)((sal-(float)((sal/260)*(taken-leave))*1.21));}
        else{
        total=sal*1.11;}
        cout<<"Adhoc compute-salary. "<<endl;
        return total;
    }
    void display(){
        employee::display();
        cout<<"leave taken is ;l "<<leave_taken<<endl;
        float sal = this->compute_salary(salary,leave_taken,leave);
        cout<<"salary of regular employee after all leaves is"<<sal<<endl;
    }
};
int main(){
    //(name,age,id,dept,phone,leave,salary,(tenure),leave_taken)
    adhoc a1("Aditya",19,"854796512","Front_end_developer","958547269",48,448,3,45);
    adhoc a2("Tarun",18,"9456687259","Senior_developer","8456975266",48,538,1,50);
    regular r1("Druvil",19,"4589612576","Resource_Management","965236874",55,650,30);
    regular r2("Prince",20,"123647965","Human_Resources","9637412580",35,569,45);
    a1.display();
    a2.display();
    r1.display();
    r2.display();
    return 0;
}