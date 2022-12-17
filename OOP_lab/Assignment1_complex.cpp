/*Problem Statement:

Implement a class complex which represent the complex number data type.
1. Constructor(which include 0 + 0i)
2. Overloaded + operator, which adds two complex number.
3. Overloaded * operator, which multiplies two complex number.
4. Overloaded << and >> to print and read complex.*/


#include <iostream>
#include <ostream>
#include <limits>
using namespace std;


//Declaring the class:
class complx{
public:
    float real,img;



//creating default Constructor:
complx(float r = 0, float i = 0){
    real = r;
    img = i;
}



// Addition of complex number
// overloading + operator
complx operator + (complx ob1){
    complx sum;
    sum.real = real + ob1.real;
    sum.img = img + ob1.img;
    return sum;
}



//Multiplication of complex number
// overloading * operator
complx operator*(complx obj)
  {
   complx temp;
   temp.real = (real*obj.real) - (img*obj.img);
   temp.img = (real*obj.img)+ (img*obj.real);
   return temp;
  }




//Accepting a complex number
// overloading >> operator
friend istream& operator>>(istream &in, complx &c1)
  {
     string choice ;
cout<<"Do you want default values? " ;
cin>> choice ;
if (choice == "yes")
return in;

else

{
   cout<<"Enter the real part of the number- ";
   in>>c1.real;
     while(true)                                      //***Exception Handling***
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"You have entered wrong input. Enter again: ";
				cin>>c1.real;
			}
			if(!cin.fail())
			break;
		}
   cout<<"Enter the imaginary part of the number- ";
   in>>c1.img;
     while(true)                                      //***Exception Handling***
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"You have entered wrong input. Enter again: ";
				cin>>c1.img;
			}
			if(!cin.fail())
			break;
		}
   return in;
  }
  }

void printout(){
if(img < 0){
    cout << real << img << "i" << endl;
}
else{
    cout << real << "+" << img << "i" << endl;
}
}

};

// MAIN FUNCTON:

int main()
{


 complx c1,c2;
 int option;
 string input;
 cout<<"MENU!!!!!!!"<< endl;
 cout<<"1.Press {1} to perform addition.\n2.Press {2} to perform multiplication." << endl;

 while(true)
 {
  cout<<"\nEnter the number corresponding to your operation- ";
  cin>>option;
   while(true)                                      //***Exception Handling***
		{
			if(cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"You have entered wrong input. Enter again: ";
				cin>>option;
			}
			if(!cin.fail())
			break;
		}

  switch(option)
  {
  case 1:
  {
   cout<<"\nEnter the first number- "<<endl;
   cin>>c1;
   cout<<"\nEnter the second number- "<<endl;
   cin>>c2;
   (c1+c2).printout();
   break;
  }

  case 2:
  {
   cout<<"\n\nEnter the first number- "<<endl;
   cin>>c1;
   cout<<"\nEnter the second number- "<<endl;
   cin>>c2;
   (c1*c2).printout();
   break;
  }
    default:{
    cout << "Enter the correct value!!!" << endl;
    }


  }

 cout<<"Do you want to continue? Type yes/no-  ";
 cin>>input;
 if(input == "no" || input == "n" || input == "N")
 {
  cout<<"THANK YOU!!!!!!!! ";
  break;
 }

}
 return 0;
}




