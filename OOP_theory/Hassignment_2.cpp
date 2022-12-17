/*#include <bits/stdc++.h> 
using namespace std; 
class City{ 
protected: string name; 
public:
void setName(){ 
cout<<"Enter name: "<<endl; 
cin>>this->name; } 
};
class mumbai: public City{ 
private:
string feature; 
public:
void setFeature(){ 
cout<<"Enter feature: "<<endl; 
cin>>this->feature; } 
void details(){
cout<<"Name: "<<name<<endl; cout<<"Feature: "<<feature; 
} 
};
int main(){ 
mumbai d1; d1.setName(); d1.setFeature(); d1.details(); return 0; 
} */


/*#include <bits/stdc++.h> 
using namespace std; 
class Person{ 
protected: string name; 
public:
void getName(){ 
cout<<"Enter name: "<<endl; 
cin>>name; } 
};
class Age: virtual public Person{ 
protected: int age; 
public:
void getAge(){ 
cout<<"Enter the age: "<<endl; 
cin>>age; } 
}; 
class Salary: virtual public Person{ protected:
int salary;
public: 
void getsalary(){
cout<<"Enter salary: "<<endl; 
cin>>salary; } 
};
class Profile: public Age, public Salary{ 
public:
void display(){ 
cout<<"Name: "<<name<<endl; cout<<"Age: "<<age<<endl; cout<<"Salary: "<<salary<<endl; 
} }; 
int main()
{
     Profile p1; p1.getName(); p1.getAge(); p1.getsalary(); p1.display(); 
     return 0; 
} */

/*#include <bits/stdc++.h> 
using namespace std; 
class A1 { 
int num = 10; 
public:
void display() { 
cout << "Value of num is " << num<< endl; } 
};
class B1: public A1 {
};
class C1 : public A1 {
};
int main()
{ 
C1 c;
 c.display(); 
return 0; 
} */

#include <bits/stdc++.h> 
using namespace std; 
class ABC
{ 
protected: int x, y; 
public:
void getData() { 
cout << "Enter values of x and y" << endl; 
cin >> x >> y; } 
};
class PQR : public ABC{
public: 
void product() { 
cout << "x times y is: " << x * y << endl; } 
};
class JKL : public ABC{ 
public:
void addVar(){ 
cout<<"Addition is: "<<x+y<<endl; } 
}; 
int main() { 
PQR b1;
JKL c1; b1.getData(); b1.product(); c1.getData(); c1.addVar(); 
return 0; } 



















































